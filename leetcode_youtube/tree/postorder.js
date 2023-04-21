const bTree = require('./_b-tree')

!(function postorder(root) {
  if (!root) return
  postorder(root.left)
  postorder(root.right)
  console.log(root.val)
})(bTree)

console.log()


!(function postorder(root) {
  if (!root) return
  const stack = [root]
  const outStack = []
  while (stack.length) {
    const n = stack.pop()
    outStack.push(n)
    if(n.left) stack.push(n.left)
    if(n.right) stack.push(n.right)
  }
  while(outStack.length) {
    console.log(outStack.pop().val)
  }
})(bTree)