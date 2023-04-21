const bTree = require('./_b-tree')

!(function preorder(root) {
  if (!root) return
  console.log(root.val)
  preorder(root.left)
  preorder(root.right)
})(bTree)

console.log()

!(function preorder(root) {
  if (!root) return
  const stack = [root]
  while (stack.length) {
    const n = stack.pop()
    console.log(n.val)
    if(n.right) stack.push(n.right)
    if(n.left) stack.push(n.left)
  }
})(bTree)

console.log()

!(function preorderLevel(root) {
  let deepLen = 0
  const preorder = (root, l) => {
    if (!root) return
    if (!root.left && !root.right) deepLen = Math.max(deepLen, l)
    preorder(root.left, l+1)
    preorder(root.right, l+1)
  }
  preorder(root, 1)
  console.log('the tree level is:', deepLen)
})(bTree)
