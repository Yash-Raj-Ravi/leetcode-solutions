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
//     // array to Linked list conversion
// private:
//     ListNode *arrToLL(vector<int>& arr){
//         if(arr.empty()) return nullptr;

//         ListNode *head = new ListNode(arr[0]);
//         ListNode *temp = head;

//         for(int i=1;i<arr.size();i++){
//             temp->next = new ListNode(arr[i]);
//             temp = temp->next;
//         }
//         return head;
//     }
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int> arr;

//         ListNode *temp1 = list1;
//         ListNode *temp2 = list2;

//         while(temp1!=nullptr){
//             arr.push_back(temp1->val);
//             temp1 = temp1->next;
//         }
//         while(temp2!=nullptr){
//             arr.push_back(temp2->val);
//             temp2 = temp2->next;
//         }
//     sort(arr.begin(),arr.end());
//         return arrToLL(arr);
//     }
// };

// 2.Optimal
class Solution {
public:
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
};