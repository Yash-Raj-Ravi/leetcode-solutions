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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode *temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        temp = head;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
        
//     }
// };