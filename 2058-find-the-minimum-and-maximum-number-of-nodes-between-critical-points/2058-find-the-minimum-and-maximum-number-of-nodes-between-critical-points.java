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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return new int[]{-1, -1};
        }

        int firstCriticalPos = -1;
        int lastCriticalPos = -1;
        int minDistance = Integer.MAX_VALUE;
        int pos = 1;  // Start position for the second node (since we need at least three nodes to have a critical point)
        
        ListNode prev = head;
        ListNode curr = head.next;

        while (curr.next != null) {
            ListNode next = curr.next;

            if ((curr.val > prev.val && curr.val > next.val) || (curr.val < prev.val && curr.val < next.val)) {
                if (firstCriticalPos == -1) {
                    firstCriticalPos = pos;
                } else {
                    minDistance = Math.min(minDistance, pos - lastCriticalPos);
                }
                lastCriticalPos = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (firstCriticalPos == lastCriticalPos) {
            return new int[]{-1, -1};
        }

        int maxDistance = lastCriticalPos - firstCriticalPos;

        return new int[]{minDistance, maxDistance};
    }
}
