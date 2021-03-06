/**
 * Pass by value vs pass by reference
 */

var a = 1
var b = a

b++
console.log('a', a)
console.log('b', b)

/** referance */
// object
let obj1 = {a: 1, b: 2, deep: {c: 3}}
let obj2 = obj1
let obj3 = Object.assign({}, obj1)
let obj4 = {...obj1}
let obj5 = JSON.parse(JSON.stringify(obj1))

obj1.a = 9
console.log('obj1', obj1)
console.log('obj2', obj2)
obj3.a = 6
console.log('copy object')
console.log('obj1', obj1)
console.log('obj3', obj3)
console.log('obj4', obj4)
console.log('copy object deep')
obj1.deep.c = 4
console.log('obj1', obj1)
console.log('obj4', obj4)
console.log('obj4', obj5)

// array
let arr1 = [1, 2, 3]
let arr2 = arr1
let arr3 = arr1.concat([888])
arr1.push(666)
console.log('arr1', arr1)
console.log('arr2', arr2)
console.log('copy arr')
console.log('arr1', arr1)
console.log('arr3', arr3)