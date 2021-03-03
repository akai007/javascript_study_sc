/**
 * js is weird
 */

// 'use strict'

function weird() {
  height = 50
  return height
}

weird()
console.log(height)

var hi = function hey() {
  return 'hello'
}

hi()
hey() // is in function hi scope
