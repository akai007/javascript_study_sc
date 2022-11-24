function ListNode(val, next) {
  this.val = val === undefined ? 0 : val
  this.next = next === undefined ? null : next
}

function createLinkedList(len) {
  let head = new ListNode(0, null)
  let p = head
  for (let i = 1; i < len; i++) {
    let node = new ListNode(i, null)
    p.next = node
    p = node
  }
  return head
}

function createLinkedListByArray(list) {
  let p = new ListNode(0, null)
  let h = p
  for (let i = 0; i < list.length; i++) {
    let q = new ListNode(list[i])
    p.next = q
    p = q
  }
  return h.next
}

function displayLinkedList(p) {
  let str = ''
  while (p != null) {
    str += p.val + " "
    p = p.next
  }
  console.log(str)
}

module.exports = {
  ListNode,
createLinkedList,
createLinkedListByArray,
displayLinkedList,
}