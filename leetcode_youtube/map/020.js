
var isValid = function(s) {
  const map = new Map([['(',')'], ['[',']'], ['{','}']])
  let stack = []
  let sList = s.split('')
  let c
  for (let i = 0 ; i < s.length; i++ ) {
    c = sList[i]
    if (map.has(c)) stack.push(c)
    else
      if (map.get(stack[stack.length-1]) == c) stack.pop()
      else return false
  }

  return !stack.length
}

console.log(isValid('(]'))
