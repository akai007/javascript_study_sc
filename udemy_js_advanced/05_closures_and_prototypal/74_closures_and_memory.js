/**
 * Closures and Memory, Efficient
 */

const heavyDuty = function(index) {
    const bigArr = new Array(8888).fill('😀')
    console.log('created!')
    return bigArr[index]
}

// create big Array every time
console.log( heavyDuty(8) )
console.log( heavyDuty(88) )
console.log( heavyDuty(888) )

const heavyDutyOpt = function () {
    const bigArr = new Array(8888).fill('😀')
    console.log('efficient created!')
    return function(index) {
        return bigArr[index]
    }
}

const doHeavyDutyEfficient = heavyDutyOpt()
console.log( doHeavyDutyEfficient(8) )
console.log( doHeavyDutyEfficient(88) )
console.log( doHeavyDutyEfficient(888) )
