/**
 * 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 示例 2：
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 示例 3:
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 */


/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function (s, t) {
  let l=0, r=0
  let map = new Map()
  for (let i = 0; i< t.length; i++) {
    const c = t[i]
    map.set(c, (map.get(c)||0) + 1)
  }

  let need = map.size
  let str = ''
  while(r < s.length) {
    const c = s[r]
    if (map.has(c)) {
      map.set(c, map.get(c)-1)
      if (map.get(c) === 0) need--
    }

    while(need == 0) {
      let newStr = s.substring(l, r+1)
      if(!str || newStr.length < str.length) str = newStr
      const cl = s[l]
      if (map.has(cl)) {
        map.set(cl, map.get(cl)+1)
        if (map.get(cl)===1) need++
      }
      l++
    }
    r++
  }

  return str
};

console.log(minWindow('a', 'aa'))
// console.log(minWindow('aa', 'aa'))