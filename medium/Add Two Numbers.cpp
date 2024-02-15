#include <cmath>
#include <string>
using namespace std;

struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* answer = new ListNode(0);
            ListNode* current = answer;
            int carry = 0;
            while (l1 != nullptr || l2 != nullptr || carry != 0) {
                int sum = (l1 != nullptr ? l1->val : 0) +
                          (l2 != nullptr ? l2->val : 0) + carry;
                carry = sum / 10;
                current->next = new ListNode(sum % 10);
                current = current->next;
                l1 = (l1 == nullptr) ? nullptr : l1->next;
                l2 = (l2 == nullptr) ? nullptr : l2->next;
            }
            ListNode* temp = answer->next;
            delete (answer);
            return temp;
        }
};

int main() {}
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.



Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/