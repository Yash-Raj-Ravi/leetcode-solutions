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
//     ListNode* sortList(ListNode* head) {
//         vector<int> arr;
//         ListNode *temp = head;
//         while(temp!=nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         int n = arr.size();
//         temp = head;
//         sort(arr.begin(),arr.end());
//         for(int i=0;i<n;i++){
//             temp->val = arr[i];
//             temp = temp->next;
//         }
//         return head;
//     }
// };

// 2.Optimal
class Solution {
private:
ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head->next; // fast is taken 1 node ahead to get 1st middle in case of even number of total nodes.
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;

        if(temp1->val <= temp2->val) { 
            head = temp1;
            prev = head;
            temp1 = temp1->next;
            } 
        else {
            head = temp2;
            prev = head;
            temp2 = temp2->next;
            }

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val <= temp2->val){
               prev->next = temp1;
               prev = temp1;
               temp1 = temp1->next;
            }
            else{
               prev->next = temp2;
               prev = temp2;
               temp2 = temp2->next;
            }
        }

        if(temp1!=nullptr){
            while(temp1!=nullptr){
               prev->next = temp1;
               prev = temp1;
               temp1 = temp1->next;
            }
        }
        else{
               while(temp2!=nullptr){
               prev->next = temp2;
               prev = temp2;
               temp2 = temp2->next;
            }
        }
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *middle = middleNode(head);
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left,right);

    }
};