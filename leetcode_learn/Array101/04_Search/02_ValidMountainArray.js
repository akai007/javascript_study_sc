/**
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 * Recall that arr is a mountain array if and only if:
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 */

const input = [0,3,2,1]

var validMountainArray = function(arr) {
  if (arr.length < 3){
    return false
  }
  let lM = undefined;
  for (let i = 0; i < arr.length; i++) { // l -> r
    console.log(i, arr[i]);
    let cI = arr[i+1] - arr[i]
    if (cI < 0) {
      lM = i
      break
    } else if (cI === 0) {
      return false
    }
  }
  let rM = undefined;
  for (let j = arr.length-1; j >= 0; j--) { // r -> l
    let cJ = arr[j] - arr[j+1]
    if (cJ < 0) {
      rM = j+1
      break
    } else if (cJ === 0) {
      return false
    }
  }
  // console.log(`leftMax: ${lM}:${arr[lM]},rightMax: ${rM}:${arr[rM]}`);

  return (lM == rM && arr[lM] === arr[rM])
};

console.log(validMountainArray(input));
