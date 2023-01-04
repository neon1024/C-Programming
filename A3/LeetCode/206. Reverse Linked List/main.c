/*
    Scumpu Ioan Robert 916 (neon1024)
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{

    struct ListNode *current = head;
    struct ListNode *previous = NULL;
    struct ListNode *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;

    return head;
}
