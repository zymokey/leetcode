/*
Sort a linked list using insertion sort.
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, 
finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };

        ListNode* insertionSortList(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *pre = head, 
                     *cur = head->next, 
                     *h = head, 
                     *next;
            while(cur) {
                if(cur->val < pre->val) {
                    next = cur->next;
                    pre->next = next;
                    ListNode *p = nullptr;
                    while(cur->val > h->val) {
                        p = h;
                        h = h->next;
                    }
                    if(p) {
                        p->next = cur;
                    } else {
                        dummy->next = cur;
                    }
                    cur->next = h;
                    h = dummy->next;
                    cur = next;
                } else {
                    pre = cur;
                    cur = cur->next;
                }
            }
            return dummy->next;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/