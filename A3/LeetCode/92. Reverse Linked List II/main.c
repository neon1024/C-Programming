/*
    Scumpu Ioan Robert 916 (neon1024)
*/

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

    if (head == NULL)
        return NULL;

    if (head->next == NULL || left == right)
        return head;

    struct ListNode *left_previous = NULL;
    struct ListNode *right_next = NULL;
    struct ListNode *current = head;

    int pos = 1;

    while (current != NULL)
    {
        if (pos == left-1)
            left_previous = current;

        if (pos == right+1)
        {
            right_next = current;
            break;
        }

        pos++;
        current = current->next;
    }

    struct ListNode *left_node = left_previous ? left_previous->next : head;
    struct ListNode *current_node = left_node->next;
    struct ListNode *previous_node = left_node;

    while (current_node != right_next)
    {
        struct ListNode *next_node = current_node->next;

        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }

    left_node->next = right_next;

    if (left_previous)
    {
        left_previous->next = previous_node;
        return head;

    }
    else
        return previous_node;
}
