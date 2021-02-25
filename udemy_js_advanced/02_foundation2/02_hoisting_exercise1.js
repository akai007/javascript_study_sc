/** part 1 */

console.log('one when hoisting:', one);
var one = 1
var one = 2
console.log(one);


/** part 2 */

a()
function a() {
    console.log('hi');
}
function a() {
    console.log('bye')
}
a()