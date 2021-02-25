/** part 1 */
console.log('teddy:', teddy)
console.log('let teddy:', teddyLet)
console.log('const teddy:', teddyConst)
console.log('call function howl() => ', howl())

// console.log('call function howlInner() => ', howlInner())
// console.log('expression function expressionFunction => ', expressionFunction)
// console.log('call function expressionFunction() => ', expressionFunction())

var teddy = 'deg'
let teddyLet = 'dog'
const teddyConst = 'dog'

function howl() {
    console.log('one one one!!!');
}
(function howlInner() {
    console.log('one one one!!!');
})
var expressionFunction = function howlExpression() {
    console.log('one one one!!!');
}