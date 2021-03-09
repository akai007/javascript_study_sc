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


const lazyIntro = function(str) {
    return function(firstName) {
        return function(lastName) {
            return `${str} ${firstName} ${lastName}`
        }
    }
}

const startIntro = lazyIntro('Hi My Name is')
// long time after
console.log( startIntro('Liao')('Kai') )

const lazyIntroSimple = (str) => (firstName) => (lastName) => {
    return `${str} ${firstName} ${lastName}`
}
const startIntroSimple = lazyIntroSimple('Hi My Name is')
// long time after
console.log( startIntroSimple('Zhang')('Xumeng') )
