import fetch from 'node-fetch';

async function openEpitechDoor(doorName) {
  try {
    const url = `https://tekme.eu/api/doors_open?token=${process.env.EPITECH_DOORS_API_KEY}&door_name=${doorName}`;
    await fetch(url, {
      method: 'GET',
      headers: {
        'Content-Type': 'application/json',
      },
    });
    return true
  } catch (error) {
    console.error('Error processing epitech doors API:', error);
    return false;
  }
}

export { openEpitechDoor };