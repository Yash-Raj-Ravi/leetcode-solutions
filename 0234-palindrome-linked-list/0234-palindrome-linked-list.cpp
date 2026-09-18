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
//     bool isPalindrome(ListNode* head) {
//         if(head == nullptr || head->next == nullptr) return true;

//         ListNode *back = head;
//         stack<int> st;
//         while(back!=nullptr){
//             st.push(back->val);
//             back = back->next;
//         }

//         int cnt = 0;
//         int sz = st.size()/2;

//         while(cnt<sz  && head->val == st.top()){
//             st.pop();
//             head = head->next;
//             cnt++;
//             }
//             if(cnt==sz) return true;
//             return false;
//     }
// };

// 2.Optimal
class Solution {
private:
    ListNode* reverseList(ListNode* newhead) {
      if(newhead == nullptr || newhead->next == nullptr) return newhead;

       ListNode* p = newhead;
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

public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode *slow = head, *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseList(slow->next);
        ListNode *move = newHead;
        while(move!=nullptr){
            if(head->val != move->val) {
                // Restore back the original Linked List before returning
                reverseList(newHead);
                return false;
                }
            head = head->next;
            move = move->next;
        }
        // Restore back the original Linked List before returning
        reverseList(newHead);
        return true;
    }
};