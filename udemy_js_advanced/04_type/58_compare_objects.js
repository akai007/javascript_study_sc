/**
 * How would you compare two objects if they are pointing to a different location in memory but still have the same properties?
 */

var user1 = {name : 'nerd', org: 'dev'}
var user2 = {name : 'nerd', org: 'dev'}
var eq_ref = user1 == user2
var eq_value = JSON.stringify(user1) == JSON.stringify(user2)

console.log(eq_ref)
console.log(eq_value)