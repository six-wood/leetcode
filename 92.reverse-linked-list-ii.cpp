// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=21913
 *
 * [92] 反转链表 II
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *flipPre = nullptr;
        ListNode *back = nullptr;
        ListNode *flip = nullptr;
        int cnt = 1;
        while (dummy != nullptr)
        {
            dummy = dummy->next;
            if (cnt == left - 1)
            {
                flipPre = dummy;
            }
            else if (cnt == right + 1)
            {
                back->next = dummy;
            }
            else if (cnt == left)
            {
                flip = new ListNode(dummy->val);
                back = flip;
            }
            else if (cnt <= right && cnt > left)
            {
                ListNode *tmp2 = new ListNode(dummy->val);
                tmp2->next = flip;
                flip = tmp2;
            }

            cnt++;
        }
        if (flipPre != nullptr)
        {
            flipPre->next = flip;
            return head;
        }
        else
        {
            return flip;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
