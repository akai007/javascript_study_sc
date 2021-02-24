let input = [1, 1, 1, 0, 1, 1, 0, 1, 1, 1];

/**
 * @param {number[]} nums
 * @return {number} maxCount
 */
var findMaxConsecutiveOnes = function(nums) {
  let maxCount = 0;
  let count = 0;
  let target = 1;
  for (let i = 0; i < nums.length; i++) {
    const curr = nums[i];
    if (curr === target) {
      count = count + 1;
    } else {
      count = 0;
    }
    if (count > maxCount) {
      maxCount = count;
    }
  }
  return maxCount;
};

console.log(findMaxConsecutiveOnes(input));