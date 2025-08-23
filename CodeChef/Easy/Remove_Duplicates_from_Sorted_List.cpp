class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if (!head) return head;
        
        Node* curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                // skip the duplicate node
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // free memory
            } else {
                curr = curr->next; // move forward only if no duplicate
            }
        }
        
        return head;
    }
};
