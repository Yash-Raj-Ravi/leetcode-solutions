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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL || k==0) return head;

        ListNode* temp = head, *trail = NULL;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        if(k%len==0) return head;

        temp = head;
        int shift=-1;
        if(k>len) {
            int modk = k%len;
            shift = abs(len-modk);
        }
        else{
            shift = len-k;
        }

        if(shift==0){
            return head;
        }

        while(shift!=0){
            trail = head;
            head = head->next;
            shift--;
        }
        trail->next = NULL;
        ListNode* temp2 = head;

        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next = temp;
    return head;
    }
};


// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
        
//     }
// };