/** part1 */
function plus(a, b) {
  return a + b
}
console.log(plus(1, 2))

/** part2 */
function plus2(a, b) {
  let args = Array.from(arguments)
  return args[0] + args[1]
}
console.log(plus2(1, 2))

/** part3 */
function plus3(...args) {
  return args[0] + args[1]
}
console.log(plus3(1, 2))

/** part4 */
function plus3({a, b}) {
  console.log(arguments[0])
  return a + b
}
console.log(plus3({a: 1, b: 2}))

/** notice1 */
function notice() {
  console.log(arguments)
}
notice()