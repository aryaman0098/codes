var fs = require('fs');

const input = fs.readFileSync('./testCase', { encoding: 'utf8'})
const grid = input.split('\n').map(e => e.split(''))

let n = grid.length, m = grid[0].length
let count = 0

/**
 *  Part 1.
 */

// for(let i = 0; i < n; i++) {
//   for(let j = 0; j < m; j++) {
//     if(grid[i][j] == 'X') {
//       let candidate
//       if(j + 3 < m) {
//         candidate = grid[i].slice(j, j + 4).join('')
//         if(candidate == 'XMAS') count += 1 
//       }
//       if(j - 3 >= 0) {
//         candidate = grid[i].slice(j - 3, j + 1).reverse().join('')
//         if(candidate == 'XMAS') count += 1
//       } 
//       if(i - 3 >= 0) {
//         candidate = grid[i][j] + grid[i - 1][j] + grid[i - 2][j] + grid[i - 3][j]
//         if(candidate == 'XMAS') count += 1 
//       } 
//       if(i + 3 < n) {
//         candidate = grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 3][j]
//         if(candidate == 'XMAS') count += 1
//       }
//       if(i - 3 >=0 && j - 3 >= 0) {
//         candidate = grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2] + grid[i - 3][j - 3]
//         if(candidate == 'XMAS') count += 1
//       }
//       if(i + 3 < n && j - 3 >= 0) {
//         candidate = grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2] + grid[i + 3][j - 3]
//         if(candidate == 'XMAS') count += 1
//       }
//       if(i - 3 >=0 && j + 3 < m) {
//         candidate = grid[i][j] + grid[i - 1][j + 1] + grid[i - 2][j + 2] + grid[i - 3][j + 3]
//         if(candidate == 'XMAS') count += 1
//       }
//       if(i + 3 < n && j + 3 < m) {
//         candidate = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] + grid[i + 3][j + 3]
//         if(candidate == 'XMAS') count += 1
//       }
//     }
//   }
// }

// console.log(count)


for(let i = 0; i < n; i++) {
  for(let j = 0; j < m; j++) {
    if(grid[i][j] == 'A') {
      if(i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < m) {
        if(
          grid[i - 1][j - 1] == 'M' && 
          grid[i - 1][j + 1] == 'M' && 
          grid[i + 1][j - 1] == 'S' &&
          grid[i + 1][j + 1] == 'S'
        ) count += 1
        if(
          grid[i - 1][j - 1] == 'M' &&
          grid[i - 1][j + 1] == 'S' &&
          grid[i + 1][j - 1] == 'M' &&
          grid[i + 1][j + 1] == 'S'
        ) count += 1
        if(
          grid[i - 1][j - 1] == 'S' &&
          grid[i - 1][j + 1] == 'S' &&
          grid[i + 1][j - 1] == 'M' &&
          grid[i + 1][j + 1] == 'M'
        ) count += 1
        if(
          grid[i - 1][j - 1] == 'S' &&
          grid[i - 1][j + 1] == 'M' &&
          grid[i + 1][j - 1] == 'S' &&
          grid[i + 1][j + 1] == 'M'
        ) count += 1
      }
    }
  }
}
console.log(count)