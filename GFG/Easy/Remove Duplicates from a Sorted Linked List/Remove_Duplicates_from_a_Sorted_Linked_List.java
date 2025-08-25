class Solution {
    // Function to remove duplicates from sorted linked list.
    Node removeDuplicates(Node head) {
        if (head == null) return null;

        Node current = head;

        // Traverse the list
        while (current != null && current.next != null) {
            if (current.data == current.next.data) {
                // Skip the duplicate node
                current.next = current.next.next;
            } else {
                current = current.next; // move forward
            }
        }

        return head;
    }
}
