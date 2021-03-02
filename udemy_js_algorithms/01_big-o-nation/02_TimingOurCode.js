/**
 * add to n
 */
const {performance} = require('perf_hooks');

function addUpto(n) {
    let count = 0
    for (let i = 1; i <= n; i++) {
        count += i
    }
    return count
}
let t1 = performance.now()
addUpto(1000000000)
let t2 = performance.now()
console.log(`1 Time Elapsed: ${(t2-t1).toFixed(4)}ms.`);


function addUpto2(n) {
    let count =  n * ( n + 1 ) / 2
    return count
}
let t21 = performance.now()
addUpto2(1000000000)
let t22 = performance.now()
console.log(`2 Time Elapsed: ${(t22-t21).toFixed(4)}ms.`);