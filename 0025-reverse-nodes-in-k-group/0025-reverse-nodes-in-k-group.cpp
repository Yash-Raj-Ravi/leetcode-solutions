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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || k<=1) return head;

        ListNode* temp = head;
        ListNode* Dummy = new ListNode(-1);
        ListNode* tail = Dummy;

        while(temp!=NULL){
        ListNode* start = temp;
        int x = k;
        stack<ListNode*> st;
        while(temp!=NULL && x!=0){ 
        st.push(temp);
        temp=temp->next;
        x--;
        }
       if(x==0){
        while(!st.empty()){
            tail->next = st.top();
            tail = tail->next;
            st.pop();
        }
        tail->next = NULL; // Imp line
       }
       else{
        tail->next = start;
        break;
       }
      }
      return Dummy->next;
    }
};

// class Solution {
// private:
//     ListNode* Rev(ListNode* H,int k){
//         ListNode* t = H,*p=NULL,*q=NULL;
//         int cnt=0;
//         while(t!=NULL && cnt<k){
//             q=p;
//             p=t;
//             t=t->next;

//             t->next = p;
//             cnt++;
//         }
//         return p;
//     }
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {

//     }
// };

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {

//     }
// };

// // Optimal
// class Solution {
// private:
//     ListNode* rev(ListNode* H) {

//         if (H == NULL || H->next == NULL)
//             return H;

//         ListNode* temp = H;
//         ListNode *p = NULL, *q = NULL;
//         while (temp != NULL) {
//             q = p;
//             p = temp;
//             temp = temp->next;
//             p->next = q;
//         }
//         return p;
//     }
//     ListNode* findKthNode(ListNode* h, int k) {
//         ListNode* find = h;
//         int cnt = 0;
//         while (find!= NULL && cnt < k - 1) {
//             find = find->next;
//             cnt++;
//         }

//         return find;
//     }

// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *temp = head, *prevNode = NULL, *NextNode = NULL;
//         while (temp != NULL) {
//             ListNode* KthNode = findKthNode(temp, k);
//             if (KthNode == NULL) {
//                 if (prevNode)
//                     prevNode->next = temp;
//                 break;
//             }

//             else {
//                 NextNode = KthNode->next;
//                 KthNode->next = NULL;
//                 rev(temp);

//                 if (temp == head) {
//                     head = KthNode;
//                 } 
//                 else {
//                     prevNode->next = KthNode;
//                 }
//             }
//             prevNode = temp;
//             temp = NextNode;
//         }
//         return head;
//     }
// };