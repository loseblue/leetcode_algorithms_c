/**
* Definition for singly-linked list.
* struct ListNode {
 *     int val;
 *     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry_flag = 0;
    int t_val = 0;
    int t_l1 = 0;
    int t_l2 = 0;

    struct ListNode* p_rec = NULL;
    struct ListNode* p_tmp = NULL;
    struct ListNode* p_lst = NULL;

    while (NULL != l1 || NULL !=l2 || 1==carry_flag)
    {
        t_l1 = (NULL != l1)? l1->val:0;
        t_l2 = (NULL != l2)? l2->val:0;

        t_val = t_l1 + t_l2 + carry_flag;
        if (t_val >9)
        {
            t_val -= 10;
            carry_flag = 1;
        }
        else
        {
            carry_flag = 0;
        }
        p_tmp = malloc(sizeof(struct ListNode));
        memset(p_tmp, 0, sizeof(struct ListNode));

        p_tmp->val = t_val;


        if(NULL == p_rec)
        {
            p_rec = p_lst = p_tmp;
        }
        else
        {
            p_lst->next = p_tmp;
            p_lst = p_lst->next;

        }

        l1 = (NULL != l1)? l1->next:NULL;
        l2 = (NULL != l2)? l2->next:NULL;

    }

    return p_rec;

}
