/** */

function one() {
    console.log(1);
}

one()

var obj = {
    two: function () {
        console.log(2)
    }
}
obj.two()

const three = function() {
    console.log(3)
}
three.call()
console.log(three.name)

const four = new Function('num=1', 'console.log(arguments, num)')
four(4)

console.log(four.name)
console.log(four.length)