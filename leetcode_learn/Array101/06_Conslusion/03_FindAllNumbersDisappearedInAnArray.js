/**
 * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
 */
 const input = [1,1];
 
 /**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
  const setNums = new Set(nums);
  const disappeared = [];
  for (let i = 1; i <= nums.length; i++) {
    if (!setNums.has(i)) {
      disappeared.push(i)
    }
  }
  return disappeared;
};

console.log(findDisappearedNumbers(input));