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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//         if(head == nullptr) return head;

//         ListNode *temp = head;
//         int len = 0;
//         while(temp!=nullptr){
//             len++;
//             temp = temp->next;
//         }

//         if(n==len){
//             ListNode *p = head;
//             head = head->next;
//             delete p;
//             return head;
//         }
//       temp = head;
//       for(int i=1;i<len-n;i++){
//         temp = temp->next;
//       }
        
//         ListNode *p = temp->next;
//         temp->next = p->next;
//         delete p;
        
//      return head;
//     }
// };

// 2.Optimal
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode *slow = head, *fast = head;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        // Edge case: If n==len of LL, (Deletion of head)
        if(fast==nullptr){
            ListNode *p = head;
            head = head->next;
            delete p;
            return head;
        }

        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return head;

    }
};