/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL)
        {
            return false;
        }
        ListNode * p0 = head;
        ListNode * p1 = head;
          if(p0 != NULL)
            {
                p0 = p0->next;
            }
    		if (p0 != NULL)
    		{
    			p0 = p0->next;
    		}
            if(p1 != NULL)
            {
                p1 = p1->next;
            }
        while(true)
        {
            if(p0 == p1 )
            {
                if(p0 == NULL)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            if(p0 != NULL)
            {
                p0 = p0->next;
            }
    		if (p0 != NULL)
    		{
    			p0 = p0->next;
    		}
            if(p1 != NULL)
            {
                p1 = p1->next;
            }
        }
    }
};