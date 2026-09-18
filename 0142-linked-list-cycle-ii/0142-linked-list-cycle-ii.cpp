/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// // 1.Brute
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *temp = head;
//         unordered_map<ListNode*,int> mp;

//         while(temp!=nullptr){
//             if(mp.find(temp)!=mp.end()) return temp;
//             mp[temp] = 1;
//             temp = temp->next;
//         }
//         return nullptr;
//     }
// };

// // 2.Optimal
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                slow = head;
                while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
                }
                if(slow==fast) return fast;
            };
        }
        return nullptr;
    }
};