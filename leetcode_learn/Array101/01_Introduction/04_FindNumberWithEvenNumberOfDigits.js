// Given an array nums of integers, return how many of them contain an even number of digits.
 
const input = [12,345,2,6,7896];

/**
 * @param {number[]} nums
 * @return {number} count
 */
var findNumbers = function(nums) {
  nums = nums.filter(num => {
    if ((num + '').length % 2 === 0) return true;
    return false;
  })
  return nums.length;
};

console.log(findNumbers(input));
