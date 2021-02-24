/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
 * 
 * Example 1:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * 
 * Example 2:
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * 
 * Constraints:
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -109 <= nums1[i], nums2[i] <= 109
 */
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3

var merge = function(nums1, m, nums2, n) {
  for (let j = 0; j < n; j++) {
    const n2 = nums2[j];

    if (m === 0) {
      nums1[j] = n2
      continue;
    }

    if (n2 <= nums1[0]) {
      nums1.splice(0, 0, n2);
      nums1.length = nums1.length - 1;
    } else if (n2 >= nums1[m+j-1]) {
      nums1.splice(m+j, 0, n2);
      nums1.length = nums1.length - 1;
    } else {
      for (let i = 0; i < m + j; i++) {
        const nL = nums1[i];
        const nR = nums1[i+1];
        if (n2 >= nL && n2 <= nR) {
          nums1.splice(i+1, 0, n2);
          nums1.length = nums1.length - 1;
          break;
        }
      }
    }
  }
};

var margin2 = function(nums1, m, nums2, n) {
  nums1.splice(m, n, ...nums2)
  nums1.sort((a, b)=> { return a - b })
}

// merge([2,0], 1, [1], 1)
// merge([1,0] ,1 ,[2] ,1)
// merge([-1,0,0,3,3,3,0,0,0], 6, [1,2,2], 3)
// merge([], 0, [1], 1)
// merge([4,5,6,0,0,0], 3, [1,2,3], 3)
// merge([1,2,4,5,6,0], 5, [3], 1)
// merge(nums1, m, nums2, n);
// console.log('nums1 & nums2 sort', nums1);

margin2(nums1, m, nums2, n);
console.log('nums1 & nums2 sort', nums1);