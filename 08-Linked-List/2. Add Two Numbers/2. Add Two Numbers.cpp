1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* dummyHead = new ListNode(0);
15        ListNode* tail = dummyHead;
16        int carry = 0;
17
18        while (l1 != nullptr || l2 != nullptr || carry != 0) {
19            int digit1 = (l1 != nullptr) ? l1->val : 0;
20            int digit2 = (l2 != nullptr) ? l2->val : 0;
21
22            int sum = digit1 + digit2 + carry;
23            int digit = sum % 10;
24            carry = sum / 10;
25
26            ListNode* newNode = new ListNode(digit);
27            tail->next = newNode;
28            tail = tail->next;
29
30            l1 = (l1 != nullptr) ? l1->next : nullptr;
31            l2 = (l2 != nullptr) ? l2->next : nullptr;
32        }
33
34        ListNode* result = dummyHead->next;
35        delete dummyHead;
36        return result;
37    }
38};