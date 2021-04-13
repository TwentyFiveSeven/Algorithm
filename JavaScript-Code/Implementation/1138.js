const fs = require("fs");

const inputAll = fs
  .readFileSync("/dev/stdin")
  .toString()
  .replace(/\r/g, "")
  .split("\n");

const N = parseInt(inputAll.shift());
const list = inputAll.shift().split(" ");

function solve() {
  const answer = Array.from({ length: N + 1 }, () => 0);
  for (let i = 1; i <= N; i++) {
    let location = 1,
      count = 0;
    const number = parseInt(list[i - 1]);
    while (true) {
      if (answer[location]) {
        location++;
        continue;
      }
      if (count === number) {
        answer[location] = i;
        break;
      }
      location++, count++;
    }
  }
  let print = "";
  for (let i = 1; i <= N; i++) print += answer[i] + " ";
  console.log(print);
}

solve();
