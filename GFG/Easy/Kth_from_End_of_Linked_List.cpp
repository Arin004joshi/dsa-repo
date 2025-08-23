class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* first = head;
        Node* second = head;

        // Move first k steps ahead
        for (int i = 0; i < k; i++) {
            if (first == NULL) return -1; // k > length
            first = first->next;
        }

        // Move both until first reaches end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        return second ? second->data : -1;
    }
};
