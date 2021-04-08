const fs = require("fs");

const inputAll = fs
  .readFileSync("/dev/stdin")
  .toString()
  .replace(/\r/g, "")
  .split("\n");

// const inputAll = fs
//   .readFileSync("./input.txt")
//   .toString()
//   .replace(/\r/g, "")
//   .split("\n");

const n = parseInt(inputAll.shift());

function solve() {
  let answer = "";
  const jsize = inputAll[0].length;
  for (let j = 0; j < jsize; j++) {
    let check = true;
    const first = inputAll[0][j];
    for (let i = 0; i < n; i++) {
      if (first !== inputAll[i][j]) {
        check = false;
        break;
      }
    }
    if (check) answer += first;
    else answer += "?";
  }
  console.log(answer);
}

solve();
