const tree = require('./_tree')

!(function dfs (root) {
  console.log(root.val)
  root.children.forEach(dfs)
})(tree)
