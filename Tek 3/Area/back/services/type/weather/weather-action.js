import fetch from 'node-fetch';
import dotenv from 'dotenv';

// Import utilisé pour avoir les données du .env
dotenv.config();

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

export { getWeatherData, getWeatherString };