/** */

function exponent(power, num) {
  let count = 0;
  for (let i = 1; i < power; i++) {
    count += num * num
  }
  console.log(count);
}

const square = exponent.bind(this, 2)
const cube = exponent.bind(this, 3)

exponent(2, 4)
square(5)
cube(5)