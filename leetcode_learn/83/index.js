/**
 * Definition for singly-linked list.
 */

let Linked = require('../_list_node');
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function (head) {
  let list = []
  let p = new Linked.ListNode()
  p.next = head
  q = p.next

  while (q) {
    if (list.includes(q.val)) {
      p.next = q.next
      q = p.next
    } else {
      list.push(q.val)
      p = q
      q = q.next
    }
  }

  return head
};

let h = Linked.createLinkedListByArray([2, 2, 3, 4])

Linked.displayLinkedList(deleteDuplicates(h))

// Linked.displayLinkedList(h)
