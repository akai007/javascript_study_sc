/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  const map = new Map()
  nums1.forEach(item => map.set(item, true))
  const list = []
  nums2.forEach(item => {
    if (map.get(item)) {
      list.push(item)
      map.delete(item)
    }
  })
  return list
};

console.log(intersection([4,9,5], [9,4,9,8,4]))