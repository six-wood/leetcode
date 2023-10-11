// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=21913
 *
 * [25] K 个一组翻转链表
 */

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next; // 记录，方便递推
            cur->next = pre;  // 反转
            pre = cur;        // 后移一位
            cur = next;       // 后移一位
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *localReverseBegin = dummy->next;
        ListNode *pre = dummy;
        ListNode *next = dummy;
        int count = 0;
        while (head != nullptr)
        {
            count++;
            if (count % k == 0)
            {

                next = head->next;        // 记录
                head->next = nullptr;     // 断开前边的链表，以便局部反转
                head = localReverseBegin; // 递推，head=反转后的链表的尾部(现在链表的头部)

                localReverseBegin = reverseList(localReverseBegin); // 局部反转，更新头部

                head->next = next;               // 重新连接后面
                dummy->next = localReverseBegin; // 更新前面的连接
                dummy = head;                    // 递推
                localReverseBegin = next;        // 递推
            }
            head = head->next;
        }
        return pre->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
