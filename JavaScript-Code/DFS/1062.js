const fs = require("fs");

const inputAll = fs.readFileSync("/dev/stdin").toString().split("\n");
const inputNM = inputAll.shift().split(" ");
const N = inputNM[0],
  K = inputNM[1];
const maskList = [0, 2, 8, 13, 19];

function solve() {
  let answer = 0;
  if (K < 5) {
    console.log(0);
    return;
  }
  let mask = maskList.reduce((prev, cur) => (prev = prev | (1 << cur)), 0);
  const bitmastList = Array.from({ length: N }, () => mask);
  for (let i = 0; i < N; i++) {
    const otherWords = inputAll[i].replace(/(tica|anta|\r)/g, "");
    for (let j = 0; j < otherWords.length; j++) {
      bitmastList[i] |= 1 << (otherWords.charCodeAt(j) - 97);
    }
  }

  function check(mask) {
    let count = 0;
    for (bitmastValue of bitmastList) {
      if (!(bitmastValue & ~mask)) {
        count++;
      }
    }
    return count;
  }

  function dfs(index, k, mask) {
    if (k < 0) return 0;
    if (index === 26 || !k) {
      return check(mask);
    }
    let retValue = 0;
    if (maskList.includes(index)) {
      retValue = dfs(index + 1, k, mask);
    } else {
      retValue = Math.max(
        dfs(index + 1, k - 1, mask | (1 << index)),
        dfs(index + 1, k, mask)
      );
    }
    return (answer = Math.max(answer, retValue));
  }

  answer = dfs(0, K - 5, mask);
  console.log(answer);
}

solve();
