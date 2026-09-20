/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// // 1.Brute (Better)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *a = headA, *b = headB;
//         unordered_map<ListNode *,int> mp;

//         while(a!=nullptr){
//             mp[a] = 1;
//             a = a->next;
//         }

//         while(b!=nullptr){
//             if(mp.find(b)!=mp.end()) return b;
//             mp[b] = 1;
//             b = b->next;
//         }
//         return nullptr;
//     }
// };

// 2.Brute-II 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB!=nullptr){
        ListNode *temp = headA;
        while(temp!=nullptr){
            if(temp == headB) return headB;
            temp = temp->next;
        }
        headB = headB->next;
        }
        return nullptr;
    }
};


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//     }
// };