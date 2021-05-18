/**
 * Given an array nums of non-negative integers, return an array consisting of all the even elements of nums, followed by all the odd elements of nums.

You may return any answer array that satisfies this condition.

Note:
1 <= nums.length <= 5000
0 <= nums[i] <= 5000
 */
const input = [3,1,2,4];
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function(nums) {
  let odds = [];
  let evens = [];
  nums.forEach(num => {
    num % 2 === 0 ? evens.push(num) : odds.push(num);
  });
  return evens.concat(odds);
};

console.log( sortArrayByParity(input) );
