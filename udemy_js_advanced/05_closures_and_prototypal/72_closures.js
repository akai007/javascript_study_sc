/**
 * Closures 
 * Note: Is Important
 */

function a() {
    let grandma = 'grandma'
    return function b() {
        let mother = 'mother'
        return function c() {
            let daughter = 'daughter'
            return `${grandma} > ${mother} > ${daughter}`
        }
    }
}

console.log( a() )
console.log( a()() )
console.log( a()()() )


const intro = function(str) {
    return function(firstName) {
        return function(lastName) {
            return `${str} ${firstName} ${lastName}`
        }
    }
}

const startIntro = intro('Hi My Name is ')
// long time after
console.log( startIntro('Liao')('Kai') )