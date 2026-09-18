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

// 1.Brute
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode *back = head;
        stack<int> st;
        while(back!=nullptr){
            st.push(back->val);
            back = back->next;
        }

        int cnt = 0;
        int sz = st.size()/2;

        while(cnt<sz  && head->val == st.top()){
            st.pop();
            head = head->next;
            cnt++;
            }
            if(cnt==sz) return true;
            return false;
    }
};


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
        
//     }
// };