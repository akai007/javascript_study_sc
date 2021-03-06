const array = [1,2,3];
 
function getMaxNumber(arr) {
  // in the case, the 'this' keyword doesn't matter!
  // return Math.max.apply(this, arr) 
  return Math.max.apply(null, arr)
}
 
console.log(getMaxNumber(array)) // should return 3
