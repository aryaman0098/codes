var fs = require('fs');

let input = fs.readFileSync('./testCase', { encoding: 'utf8'})
input = input.split('\n').map(e => e.split(' ')).map(e => e.map(x => +x))

/**
 *  Part 1
 */

// let saveReport = 0

// for(let i of input) {
//   let isIncreasing = (i[1] - i[0]) > 0
//   let isSafe = true
//   for(let j = 0; j < i.length - 1; j++) {
//     if(isIncreasing) {
//       if(i[j + 1] - i[j] < 1 || i[j + 1] - i[j] > 3) {
//         isSafe = false
//         break
//       }
//     } else {
//       if(i[j] - i[j + 1] < 1 || i[j] - i[j + 1] > 3) {
//         isSafe = false
//         break
//       }
//     }
//   }
//   if(isSafe) saveReport += 1
// }

// console.log(saveReport)

let saveReport = 0

for(let i of input) {
  let isIncreasing = (i[1] - i[0] && i[2] - i[0]) > 0
  let isSafe = true
  let dampenerCount = 0
  for(let j = 0; j < i.length - 1; j++) {
    if(isIncreasing) {
      if(i[j + 1] - i[j] < 1 || i[j + 1] - i[j] > 3) {
        i.splice(j, 1)
        dampenerCount++
        j-= 1
      }
    } else {
      if(i[j] - i[j + 1] < 1 || i[j] - i[j + 1] > 3) {
        i.splice(j, 1)
        dampenerCount++
        j-= 1
      }
    }
    if(dampenerCount > 1) {
      isSafe = false
      break
    }
  }
  if(isSafe) {
    saveReport += 1
  }  
}

console.log(saveReport)
