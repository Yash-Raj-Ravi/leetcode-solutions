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
//     ListNode* middleNode(ListNode* head) {
//         int cnt=0;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             cnt++;
//             temp = temp->next;
//         }
//         int k = (cnt/2) + 1;
//         int search = 0;
//         temp = head;
//         while(temp!=nullptr)
//         {
//             search++;
//             if(search==k){
//                 return temp;
//             }
//             temp = temp->next;
//         }
//         return nullptr;
//     }
// };

// 2.Optimal
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};