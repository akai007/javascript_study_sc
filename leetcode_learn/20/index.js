
var isValid = function(s) {
  let left = '({['
  let right = ')}]'

  let stack = []
  let sList = s.split('')
  let c, li, ri;
  for (let i = 0 ; i < s.length; i++ ) {
    c = sList[i]
    li = left.indexOf(c)
    if (li >= 0) {
      stack.push(c)
    } else {
      ri = right.indexOf(c)
      if (left.indexOf(stack[stack.length-1]) == ri) stack.pop()
      else return false
    }
  }

  return !stack.length
};

  console.log(isValid('(]'))