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
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         while(headB!=nullptr){
//         ListNode *temp = headA;
//         while(temp!=nullptr){
//             if(temp == headB) return headB;
//             temp = temp->next;
//         }
//         headB = headB->next;
//         }
//         return nullptr;
//     }
// };

// // 3.Optimal-I
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *a = headA, *b = headB;
//         int lenA=0, lenB=0, Diff=0;
//         while(a!=nullptr){
//             lenA++;
//             a=a->next;
//         }
//         while(b!=nullptr){
//             lenB++;
//             b=b->next;
//         }
//         Diff = abs(lenA-lenB);
//         a = headA, b = headB;
//         if(lenA>=lenB){
//             while(Diff>0){
//                 a = a->next;
//                 Diff--;
//             }
//         }
//         else{
//             while(Diff>0){
//                 b = b->next;
//                 Diff--;
//             }
//         }

//         while(a!=b){
//             a=a->next;
//             b=b->next;
//         }
//         return a;
//     }
// };

// 4.Optimal-II
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a!=b){
         a=(a==nullptr)?headB:a->next;
         b=(b==nullptr)?headA:b->next;

        }
        return a;
    }
};