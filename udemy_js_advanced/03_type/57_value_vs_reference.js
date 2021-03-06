/**
 * Pass by value vs pass by reference
 */

var a = 1
var b = a

b++
console.log(a)
console.log(b)

let obj1 = {a: 1, b: 2}
let obj2 = obj1

obj1.a = 9
console.log(obj1);
console.log(obj2);