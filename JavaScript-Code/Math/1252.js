const fs = require("fs");

const inputAll = fs
  .readFileSync("../input.txt")
  .toString()
  .split(" ")
  .map((value) => {
    const newValue = value.replace(/^0*/g, "");
    return newValue ? newValue : "0";
  });

function solve() {
  let answer = "";
  const sizeFirst = inputAll[0].length,
    sizeSecond = inputAll[1].length;
  const size = sizeFirst >= sizeSecond ? sizeFirst : sizeSecond;
  let value = 0,
    first = 0,
    second = 0;
  for (let i = 0; i < size; i++) {
    first = i < sizeFirst ? parseInt(inputAll[0][sizeFirst - 1 - i]) : 0;
    second = i < sizeSecond ? parseInt(inputAll[1][sizeSecond - 1 - i]) : 0;
    value = first + second + value;
    answer = (value % 2).toString() + answer;
    value = Math.floor(value / 2);
  }
  if (value) answer = value.toString() + answer;
  // if (answer.length > 80)
  //   answer = answer
  //     .slice(answer.length - 80, answer.length)
  //     .replace(/^0*/g, "");
  console.log(answer);
}

solve();
