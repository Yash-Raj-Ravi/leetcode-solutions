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

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         int len = 0;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             len++;
//             temp = temp->next;
//         }
//         temp = head;
//         int x = len/k;
//         stack<int> st;
//         while(x!=0){
//             int cnt=0;
//             while(cnt<k){
//             st.push(temp->val);
//             temp=temp->next;
//             cnt++;
//             }
//             while(!st.empty()){
//                 ListNode *newNode = new ListNode(st.top());

//                 st.pop();
//             }
//             x--;
//         }
//     }
// };

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

// Optimal
class Solution {
private:
    ListNode* rev(ListNode* H) {

        if (H == NULL || H->next == NULL)
            return H;

        ListNode* temp = H;
        ListNode *p = NULL, *q = NULL;
        while (temp != NULL) {
            q = p;
            p = temp;
            temp = temp->next;
            p->next = q;
        }
        return p;
    }
    ListNode* findKthNode(ListNode* h, int k) {
        ListNode* find = h;
        int cnt = 0;
        while (find!= NULL && cnt < k - 1) {
            find = find->next;
            cnt++;
        }

        return find;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *prevNode = NULL, *NextNode = NULL;
        while (temp != NULL) {
            ListNode* KthNode = findKthNode(temp, k);
            if (KthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            else {
                NextNode = KthNode->next;
                KthNode->next = NULL;
                rev(temp);

                if (temp == head) {
                    head = KthNode;
                } 
                else {
                    prevNode->next = KthNode;
                }
            }
            prevNode = temp;
            temp = NextNode;
        }
        return head;
    }
};