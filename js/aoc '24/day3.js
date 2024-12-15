var fs = require('fs');

let input = fs.readFileSync('./testCase', { encoding: 'utf8'})

/**
 *  Part 1
 */

// const matches = input.match(/mul\(\d{1,3},\d{1,3}\)/g)

// let sum = 0

// for(let i of matches) {
//   const numbers = i.slice(4, i.length - 1).split(',')
//   sum += +numbers[0] * +numbers[1]
// }

// console.log(sum)

let updatedString = ''
let enabled = true
for(let i = 0; i < input.length; i++) {
  if(i + 7 < input.length && input.slice(i, i + 7) == "don\'t()") enabled = false
  if(i + 4 < input.length && input.slice(i, i + 4) == "do()") enabled = true
  if(enabled) updatedString += input[i]
}

const matches = updatedString.match(/mul\(\d{1,3},\d{1,3}\)/g)

let sum = 0

for(let i of matches) {
  const numbers = i.slice(4, i.length - 1).split(',')
  sum += +numbers[0] * +numbers[1]
}

console.log(sum)