// Vérifie la validité des paramètres des triggers de type: temps
export function getTimeCond(type, values) {
  var status = [];

  if (type == "date") {
    const today = new Date();
    const inputDate = new Date(values[0]);

    status.push(today.getFullYear() === inputDate.getFullYear() &&
      today.getMonth() === inputDate.getMonth() &&
      today.getDate() === inputDate.getDate()
    );
  }

  if (type == "hours") {
    const [inputHour, inputMinute, inputSecond] = values[0].split(':').map(Number);

    const inputDate = new Date();
    inputDate.setHours(inputHour - 2, inputMinute, inputSecond);

    const currentDate = new Date();

    status.push(inputDate.getTime() == currentDate.getTime());
  }

  return status.every((value) => value === true);
}