/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *l4 = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *l3;
    l4->val = 0;
    l4->next = NULL;
    int buff = 0;
    l3 = l4;
    while(l1 != NULL || l2 != NULL || buff != 0)
    {
        if (l1 == NULL && l2 == NULL && buff == 1)
        {
            l3->val = 1;
            buff = 0;
            printf("NULL NULL %d\n",l3->val);
            break;
        }
        if (l1 != NULL && l2 == NULL)
        {
            if (l1->val + buff> 9)
            {
                l3->val = (int)((l1->val + buff) % 10);
                buff = 1;
            }
            else 
            {
                l3->val = l1->val + buff;
                buff = 0;
            }
            printf("%d NULL %d\n", l1->val, l3->val);
            l1 = l1->next;
            if(l1 == NULL && buff == 0)
                break;
        }
        if (l1 == NULL && l2 != NULL)
        {
            if (l2->val + buff> 9)
            {
                l3->val = (int)((l2->val + buff) % 10);
                buff = 1;
            }
            else 
            {
                l3->val = l2->val + buff;
                buff = 0;
            }
            printf("NULL %d %d\n", l2->val, l3->val);
            l2 = l2->next;
            if(l2 == NULL && buff == 0)
                break;  
        }
        if (l1 != NULL && l2 != NULL)
        {
            if (l1->val + l2->val + buff> 9)
            {
                l3->val = (int)((l1->val + l2->val + buff) % 10);
                buff = 1;
            }
            else 
            {
                l3->val = l1->val + l2->val + buff;
                buff = 0;
            }
            if (l1->next == NULL && l2->next == NULL && buff == 0)
                break;
            printf("%d %d %d\n", l1->val, l2->val, l3->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        struct ListNode *result = (struct ListNode*) malloc(sizeof(struct ListNode));
            result->val = 0;
            result->next = NULL;
            l3->next = result;
            l3 = result;
    }
    return l4;
}