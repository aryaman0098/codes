var fs = require('fs');

let input = fs.readFileSync('./testCase', { encoding: 'utf8'})
input = input.split('\n')
let row1 = [], row2 = []
for(let i of input) {
  let x = i.split('  ')
  row1.push(+x[0])
  row2.push(+x[1])
}


/**
 *  Part 1.
 */
// row1.sort()
// row2.sort()

// let sum = 0

// for(let i = 0; i < row1.length; i++) sum += Math.abs(row1[i] - row2[i])

// console.log(sum)

let row2Map = {}
for(let i of row2) {
  if(!row2Map.hasOwnProperty(i)) row2Map[i] = 1
  else row2Map[i] += 1
}

let sum = 0
for(let i of row1) {
  if(row2Map[i]) {
    sum += i * row2Map[i]
  }
}

console.log(sum)