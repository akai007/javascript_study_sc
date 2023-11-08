/**
 * 函数柯里化
 */

function log(type, datetime, message) {
  console.log(`${type}: ${datetime}, ${message}`)
}


let curriedLog = type => datetime => message => console.log(`${type}: ${datetime}, ${message}`)

// let logSuccessAndDate = curriedLog('Success')
// let logWarnAndDate  = curriedLog('Warn')
// let logSuccess = curriedLog('Success')(new Date())
// let logWarn = curriedLog('Warn')(new Date())

// logSuccessAndDate(new Date())('登录成功')
// logWarn('未授权')


function currying(fn) {
  return function curry(...args) {
    if (args.length >= fn.length) {
      return fn.apply(this, args)
    } else {
      return function (...args2) {
        return curry.apply(this, args.concat(args2))
      }
    }
  }
}

let curryLog = currying(log)

let logSuccessX = curryLog('Success')(new Date())
let logWarnX  = curryLog('Warn')(new Date())
logSuccessX('asdf')
