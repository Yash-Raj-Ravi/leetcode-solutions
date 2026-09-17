/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1.Brute
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        unordered_map<ListNode*,int> mp;

        while(temp!=nullptr){
            if(mp.find(temp)!=mp.end()) return true;

            mp[temp] = 1;
            temp = temp->next;

        }
        return false;
    }
};

// // 2.Optimal (Slow,Fast)
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* slow = head, *fast = head;
//         while(fast!=nullptr && fast->next!=nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow==fast) return true;
//        }
//        return false;
//     }
// };