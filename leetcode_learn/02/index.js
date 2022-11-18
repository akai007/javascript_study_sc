/**
 * Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
 */

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let [p1, p2, l3, val, carry] = [l1, l2, new ListNode(), 0, 0]
    let p3 = l3

    while (p1 || p2) {
        val = (p1 ? p1.val : 0) + (p2 ? p2.val : 0) + carry
        carry = Math.floor(val / 10)
        p3.next = new ListNode(val % 10)

        if (p1) p1 = p1.next
        if (p2) p2 = p2.next
        p3 = p3.next
    }
    if (carry) p3.next = new ListNode(1)

    return l3.next;
};