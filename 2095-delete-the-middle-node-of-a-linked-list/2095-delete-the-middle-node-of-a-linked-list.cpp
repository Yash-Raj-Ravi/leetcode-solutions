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
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head->next==nullptr) return nullptr;

//         ListNode *temp = head;
//         int len = 0;
//         while(temp!=nullptr){
//             len++;
//             temp = temp->next;
//         }
//         temp = head;
//         for(int i=1;i<len/2;i++){
//             temp = temp->next;
//         }
//         ListNode *p = temp->next;
//         temp->next = p->next;
//         delete p;
//         return head;

//     }
// };

// 2.Optimal
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;

        ListNode *slow = head, *fast = head , *prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        return head;

    }
};