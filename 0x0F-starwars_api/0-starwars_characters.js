#!/usr/bin/node
const request = require('request');

const arg = process.argv.slice(2);

if (!arg.length) { process.exit(1); }

request.get(`https://swapi-api.hbtn.io/api/films/${arg}/`, async function (error, response, body) {
  if (error) {
    console.log(error);
    return;
  }
  const chars = JSON.parse(body).characters;
  for (const char of chars) {
    const res = await new Promise((resolve, reject) => {
      request(char, (error, res, body2) => {
        if (error) {
          reject(error);
        } else {
          resolve(JSON.parse(body2).name);
        }
      });
    });
    console.log(res);
  }
});
