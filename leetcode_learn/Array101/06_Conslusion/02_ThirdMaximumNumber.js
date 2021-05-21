/**
 * Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.
 */
const input = [1,2];

/**
 * @param {number[]} nums
 * @return {number}
 */
let thirdMax = function(nums) {
  nums = Array.from(new Set(nums))
  nums.sort((a, b) => b-a );
  if (nums.length >= 3) return nums[2];
  else return nums[0];
};

console.log( thirdMax(input) );