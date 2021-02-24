/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

let input = [0,1,2,2,3,0,4,2]
// let input = [3,2,2,3]

function removeElement(nums, val) {
    let count = 0
    let rNums = []

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            rNums.push(nums[i])
            ++count
        }
    }

    nums.length = 0
    for (let j = 0; j < rNums.length; j++) {
        nums.push(rNums[j])
    }

    return count
}

console.log(removeElement(input, 2), input)