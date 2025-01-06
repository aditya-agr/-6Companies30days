class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node *curr = head;
        while(curr){
            for (int i = 1; i < m && curr; i++) 
                curr = curr->next;
            if (!curr) break;
            Node *temp = curr->next;
            for (int i = 0; i < n && temp; i++) {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete; 
            }
            curr->next = temp;
            curr = temp;
        }
        return head;
    }
};