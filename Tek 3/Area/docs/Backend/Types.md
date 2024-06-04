# Types

## Ajouter un nouveau service (type)

Pour ajouter un nouveau type de service à l'application IFTTT, suivez les étapes suivantes :

1. Créez un nouveau dossier avec le nom de votre service dans le dossier "types". Par exemple, si votre service s'appelle "MyService", créez un dossier nommé `my-service`.

2. Ajoutez les fichiers nécessaires pour votre type de service dans ce dossier. En fonction de votre service, cela peut être un ou deux fichiers :

    - Si votre service est composé uniquement d'actions, ajoutez un fichier JavaScript pour ces actions. Par exemple, `my-service-actions.js`.

    - Si votre service comprend à la fois des déclencheurs et des actions, ajoutez deux fichiers JavaScript distincts : un pour les déclencheurs (`my-service-triggers.js`) et un pour les actions (`my-service-actions.js`).

3. Développez vos déclencheurs et/ou actions dans les fichiers que vous avez créés. Ces fichiers doivent exposer des fonctions pour interagir avec votre service.<br><br>
Voici un exemple de fichier d'action :

```javascript
// Prends les informations de l'api OpeWweatherMap
function getWeatherData(lat, lon) {
  return new Promise((resolve, reject) => {
    const api_key = process.env.WEATHER_API_KEY;
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${api_key}`;
    fetch(apiUrl)
    .then(res => res.json())
    .then(data => {
      resolve(data);
    })
    .catch(err => {
      reject(err);
    });
  });
}

// Formate les données envoyés en paramètre
function getWeatherString(weatherData) {
  const mainWeather = weatherData.weather[0].main;
  const description = weatherData.weather[0].description;
  const temperatureKelvin = weatherData.main.temp;
  const temperatureCelsius = (temperatureKelvin - 273.15).toFixed(2);
  const temperatureFahrenheit = ((temperatureKelvin - 273.15) * 9 / 5 + 32).toFixed(2);
  const humidity = weatherData.main.humidity;
  const windSpeed = weatherData.wind.speed;
  const windSpeedKph = (windSpeed * 3.6).toFixed(2);
  const visibility = weatherData.visibility;
  
  const weatherString = `Weather: ${mainWeather} - ${description}\nTemperature: ${temperatureCelsius}°C (${temperatureFahrenheit}°F)\nHumidity: ${humidity}%\nWind Speed: ${windSpeed} m/s (${windSpeedKph} km/h)\nVisibility: ${visibility} meters`;
  
  return weatherString;
}
```

Voici un exemple de fichier de déclencheur :

```javascript
async function weatherTrigger(parameters) {
  if (blackList.includes("getWeather"))
    return false;
  var status = [];
  const data = await getWeatherData(parameters.location._lat, parameters.location._long);

  if (parameters.weatherCondition != "/") {
    const main = data.weather[0].main.toLowerCase();
    console.log("current weather:", main);
    status.push(main === parameters.weatherCondition);
  }

  if (parameters.temperature != "/") {
    const operators = {
      "<": (a, b) => a < b,
      ">": (a, b) => a > b,
      "=": (a, b) => a === b,
      "<=": (a, b) => a <= b,
      ">=": (a, b) => a >= b
    };

    const [operator, value] = parameters.temperature.match(/([^\d]+)(\d+)/).slice(1);
    const temp = (parseInt(data.main.temp)) - 273.15;

    status.push(operators[operator](temp, value));
  }
  return status.every((value) => value === true);
}
```

4. Pour ajouter votre nouveau type de service à la liste des types disponibles dans l'application, il vous faudra modifier le fichier `about.json`, celui ci permet de communiquer avec le front et liste la totalité des plateformes mais également des déclencheurs et actions ainsi que leurs parametre, pour notre cas il vous suffit d'ajouter le nouveau type comme ceci :

```javascript
"server": {
  "services": [
  {
    "name": "weather",
    "actions": [
      {
        "name": "weatherCondition",
        "description": "Detects whether the weather matches your request",
        "parameters": [
          {
            "type": "string",
            "value": "weather condition",
            "examples": "clear, clouds, rain, snow, thunderstorm, drizzle"
          }
        ]
      },
      {
        "name": "temperature",
        "description": "Detects whether the temperature matches your request",
        "parameters": [
          {
            "type": "number",
            "value": "temperature",
            "examples": ">20, <=25, =30, <35"
          }
        ]
      }
    ],
    "reactions": [
      {
        "name": "getWeather",
        "time_to_add": 180000,
        "description": "Gets weather information"
      }
    ]
  },
  [...]
  ]
}
