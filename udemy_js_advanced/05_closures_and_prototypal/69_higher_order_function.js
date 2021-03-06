/**
 * Higher Order Functions
 */

const multiple = function(num1) {
    return function(num2) {
        return num1 * num2
    }
}

function multipleByTwo(num) {
    return multiple(2)(num)
}

multipleByFive = multiple(5)

console.log(multipleByTwo(4));
console.log(multipleByFive(4));