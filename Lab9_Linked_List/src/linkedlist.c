#include "linkedlist.h"

int linked_list_init(linked_list_t **ll)
{
	if (ll == NULL)
	{
		printf("linked list pointer error \n");
		return -1;
	}

	/* do program */
	/* allocate linked list */
	/* initialize list head */
	/* initialize mutex lock for BLINKED_LIST version */

	(*ll) = (linked_list_t *)malloc(sizeof(linked_list_t));
	(*ll)->list_head = (node_t *)malloc(sizeof(node_t));
	(*ll)->list_head->key = NULL;
	(*ll)->list_head->value = NULL;
	(*ll)->list_head->level = NULL;
	(*ll)->list_head->next = NULL;

#ifdef BLINKED_LIST
	int rc = pthread_mutex_init(&((*ll)->list_lock), NULL);
	assert(rc == 0);
#endif
	srand((unsigned)time(NULL));

	return 0;
}

void linked_list_destroy(linked_list_t *ll)
{
	/* do program */
	/* free all nodes in the linked list */
	/* free the linked list */
/*
	node_t **ptr;
	node_t **tmp;
	node_t *_tmp;

	ptr = &(ll->list_head);
	while ((*ptr) != NULL)
	{
		tmp = ptr;
		_tmp = *tmp;
		ptr = (*ptr)->next;

		free(_tmp);
		free(tmp);
	}

	free(ll);
	return;*/
}

long linked_list_get(long key, linked_list_t *ll)
{
	/* do program */
	/* if key is found, return value */
	/* if key is not found, return -1 */

	node_t **ptr;

	ptr = &(ll->list_head);
	while ((*ptr) != NULL)
	{
		if ((*ptr)->key != key)
		{
			ptr = (*ptr)->next;
			continue;
		}

		return (*ptr)->value;
	}

	return -1;
}

long linked_list_put(long key, long value, linked_list_t *ll)
{
	/* do program */
	/* if succeeds, return 0 */
	/* if fails, return -1 */

	int i = 0;
	while (i < 1000)
	{
#ifdef BLINKED_LIST
		// lock
		pthread_mutex_lock(&(ll->list_lock));

		node_t **ptr;
		node_t **tmp;

		ptr = &(ll->list_head);
		while ((*ptr)->next != NULL)
		{
			ptr = (*ptr)->next;
		}

		tmp = (node_t **)malloc(sizeof(node_t *));
		*tmp = (node_t *)malloc(sizeof(node_t));

		(*tmp)->key = i;
		(*tmp)->value = i;
		(*tmp)->level = i;
		(*tmp)->next = NULL;

		(*ptr)->next = tmp;
		i++;

		// unlock
		pthread_mutex_unlock(&(ll->list_lock));

#else

		node_t **ptr;
		node_t **tmp;

		ptr = &(ll->list_head);
		while ((*ptr)->next != NULL)
		{
			ptr = (*ptr)->next;
		}

		tmp = (node_t **)malloc(sizeof(node_t *));
		*tmp = (node_t *)malloc(sizeof(node_t));

		(*tmp)->key = i;
		(*tmp)->value = i;
		(*tmp)->level = i;
		(*tmp)->next = NULL;

		if (CAS(&((*ptr)->next), NULL, tmp) == NULL)
			continue;

		FAI(&i);
#endif
	}

	return 0;
}
