const fs = require("fs");

// /dev/stdin
const inputAll = fs
  .readFileSync("/dev/stdin")
  .toString()
  .replace(/\r/g, "")
  .split("\n");

const NM = inputAll.shift().split(" ");
const N = NM[0];
const M = NM[1];
const column = Array.from({ length: M }, () => 0);
const row = Array.from({ length: N }, () => 0);

function solve() {
  for (let i = 0; i < N; i++) {
    const tempRow = inputAll.shift().split("");
    for (let j = 0; j < M; j++) {
      if (tempRow[j] === "X") {
        column[j] = 1;
        row[i] = 1;
      }
    }
  }
  let rowNum = 0,
    colNum = 0;
  column.forEach((value) => {
    if (value === 0) colNum++;
  });
  row.forEach((value) => {
    if (value === 0) rowNum++;
  });
  console.log(Math.max(rowNum, colNum));
}

solve();
