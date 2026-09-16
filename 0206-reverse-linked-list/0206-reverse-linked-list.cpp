/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// // 1.Brute
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<int> st;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             st.push(temp->val);
//             temp = temp->next;
//         }

//         temp = head;
//         while(!st.empty()){
//             temp->val = st.top();
//             st.pop();
//             temp = temp->next;
//         }
//         return head;
//     }
// };

// 2.Optimal
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) return head;

       ListNode* p = head;
       ListNode* q = nullptr;
       ListNode* r = nullptr;
       while(p!=nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
       }
     return q;
    }
};