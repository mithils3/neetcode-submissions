

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *newHead = nullptr;
        if (list1->val <= list2->val)
        {
            newHead = list1;
            list1 = list1->next;
        }
        else
        {
            newHead = list2;
            list2 = list2->next;
        }
        ListNode *iter = newHead;

        while (list1 || list2)
        {
            if (list1 == nullptr)
            {
                iter->next = list2;
                return newHead;
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                iter->next = list1;
                return newHead;

                list1 = list1->next;
            }
            else
            {
                if (list1->val <= list2->val)
                {
                    iter->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    iter->next = list2;
                    list2 = list2->next;
                }
            }
            iter = iter->next;
        }
        return newHead;
    }
};
