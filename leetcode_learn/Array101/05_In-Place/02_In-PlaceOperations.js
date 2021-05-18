/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
 */

const input = [0,1,0,3,12];
const input2 = [0,0,1];

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let count = 0;
  let i = 0;

  while(i < nums.length) {
    if(nums[i] == 0) {
      nums.splice(i, 1);
      count++;
    } else {
      i++;
    }
  }
  while (count > 0) {
    nums.push(0);
    count--;
  }

  return nums;
};

console.log( moveZeroes(input) );
console.log( moveZeroes(input2) );