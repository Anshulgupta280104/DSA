class Solution {
public:
    Node* addTwoLists(Node* num1, Node* num2) {
        stack<int> s1, s2;

        while (num1) {
            s1.push(num1->data);
            num1 = num1->next;
        }

        while (num2) {
            s2.push(num2->data);
            num2 = num2->next;
        }

        int carry = 0;
        Node* head = NULL;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            Node* temp = new Node(sum % 10);
            temp->next = head;
            head = temp;
        }

        while (head && head->data == 0 && head->next)
            head = head->next;

        return head;
    }
};