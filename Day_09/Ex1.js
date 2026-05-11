function processData(input) {
  input = input.trim().split(/\s+/).map(Number);
  let n = input[0];
  let arr = input.slice(1);

  arr.sort((a, b) => b - a);

  let total = arr.reduce((a, b) => a + b, 0);
  let curr = 0;
  let result = [];

  for (let num of arr) {
    curr += num;
    result.push(num);
    if (curr > total - curr) break;
  }

  console.log(result.join(" "));
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
let _input = "";
process.stdin.on("data", function (input) {
  _input += input;
});
process.stdin.on("end", function () {
  processData(_input);
});
