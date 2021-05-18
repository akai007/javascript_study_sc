/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */

let input = [1,1,2]

/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  let cNums = Object.assign([], nums)
  let rLen = 0
  
  for (let i = 0; i < cNums.length; i++) {
    if ( i === 0 || cNums[i] !== cNums[i-1]) {
      nums[rLen] = cNums[i]
      rLen++
    }
  }
  nums.length = rLen

  return rLen
}

var removeDuplicates2 = function(nums) {
  let rLen = 0
  
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== nums[i+1]) {
      nums[rLen] = nums[i]
      rLen++
    }
  }
  nums.length = rLen

  return rLen
}



console.log(removeDuplicates2(input), input)