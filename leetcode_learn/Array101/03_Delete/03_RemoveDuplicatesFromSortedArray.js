/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */

 let input = [1,1,2]


var removeDuplicates = function(nums) {
    let countIndex = 0

    for (let i = 0; i < nums.length; i++) {

        if (nums[i] !== nums[i+1]) {
            nums[countIndex] = nums[i]
            countIndex++
        }
        
    }
    nums.length = countIndex;

    return countIndex
};


console.log(removeDuplicates(input), input);