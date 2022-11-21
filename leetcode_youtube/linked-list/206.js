
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 var reverseList = function(head) {
    let list = [];
    let p = head;
    while (p != null) {
        list.push(p.val)
        p = p.next
    }
    p = head;
    while (list.length > 0) {
        p.val = list.pop()
        p = p.next
    }
    
    return head
};
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 var reverseListB = function(head) {
    const p1 = head
    const p2 = null
    while (p1 != null) [p1.next, p1, p2] = [p2, p1.next, p1]
    return p2
};
// p2:null p1:1 2 3
//

var createLinkedList = function(len) {
    let head = new ListNode(0, null)
    let p = head
    for (let i = 1; i < len; i++) {
        let node = new ListNode(i, null)
        p.next = node
        p = node
    }
    return head
}

var displayLinkedList = function(p) {
    while (p != null) { 
        console.log(p.val)
        p = p.next
    }
}

h = createLinkedList(5)

displayLinkedList(h)
h = reverseListB(h)
displayLinkedList(h)