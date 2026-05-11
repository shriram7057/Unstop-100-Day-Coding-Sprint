function processData(input) {
  input = input.trim().split(/\s+/).map(Number);

  let n = input[0];
  let arr = input.slice(1, n + 1);
  let k = input[n + 1];

  arr.sort((a, b) => a - b);

  let indices = [];
  for (let i = 0; i < n; i++) {
    if (arr[i] === k) {
      indices.push(i);
    }
  }

  console.log(indices.length);
  if (indices.length > 0) {
    console.log(indices.join(" "));
  }
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
