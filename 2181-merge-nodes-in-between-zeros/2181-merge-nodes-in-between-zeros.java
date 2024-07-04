/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode sum = head.next; 
        ListNode nextsum = head.next.next;

        while (nextsum != null) {
            if (nextsum.val == 0) {

                sum = sum.next = nextsum.next;
                nextsum = nextsum.next != null ? nextsum.next.next : null;
            } else {
                sum.val += nextsum.val;
                nextsum = nextsum.next;
            }
        }
        return head.next;  
    }
}