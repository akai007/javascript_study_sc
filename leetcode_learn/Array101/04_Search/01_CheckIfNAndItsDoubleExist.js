/**
 * Given an array arr of integers, check if there exists two integers N and M 
 * such that N is the double of M ( i.e. N = 2 * M).
 * 
 */

let input = [-2,0,10,-19,4,6,-8]

var checkIfExist = function(arr) {
  for (let i = 0; i < arr.length; i++) {
    const iN = arr[i];
    for (let j = 0; j < arr.length; j++) {
      if(j === i) {
        continue
      }
      const jN = arr[j];
      if (iN * 2 === jN) {
        return true
      }
      
    }
    
  }

  return false
};

console.log(checkIfExist(input));