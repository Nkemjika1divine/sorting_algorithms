#include "sort.h"

/**
 * insertion_sort_list - sorts a list using the insertion sort algorithm
 * @list: theblist to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *hole, *head, *sorted, *before, *after;

	if (list != NULL && (*list) != NULL && (*list)->next != NULL)
	{
		sorted = *list;
		hole = (*list)->next;
		head = *list;
		while (hole)
		{
			after = hole;
			before = sorted;
			while (before && before->n > after->n)
			{
				if (before->prev == NULL)
					head = after;
				if (after == hole)
					hole = before;
				if (after->next != NULL)
					after->next->prev = before;
				if (before->prev != NULL)
					before->prev->next = after;
				after->prev = before->prev;
				before->next = after->next;
				after->next = before;
				before->prev = after;
				before = after->prev;
				print_list(head);
			}
			sorted = hole;
			hole = hole->next;
		}
		*list = head;
	}
}
