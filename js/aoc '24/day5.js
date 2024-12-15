var fs = require('fs');

let input = fs.readFileSync('./testCase', { encoding: 'utf8'})
input = input.split('\n')
let ordering = [], updates = []
temp = true
for(let i of input) {
  if(i == '') {
    temp = false
    continue
  } 
  if(temp) ordering.push(i.split('|'))
  else updates.push(i.split(','))
}

const validUpdates = []
for(let i of updates) {
  let isValid = true
  const updated = {}
  for(let j of i) {
    for(let k of ordering) {
      if(j == k[0]) continue
      else if (j == k[1]) {
        let f = i.find(e => e == k[0])
        if(f && !updated[f]) {
          isValid = false
          break
        }
      }
    }
    if(isValid) {
      updated[j] = true
    } else {
      break
    }
  }
  if(!isValid) validUpdates.push(i) // remove ! for part 1.
} 

