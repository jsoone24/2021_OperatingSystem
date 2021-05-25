#include "linkedlist.h"

int linked_list_init(linked_list_t** ll) 
{
	if(ll == NULL){
		printf("linked list pointer error \n");
		return -1;
	}

	/* do program */
	/* allocate linked list */
	/* initialize list head */
	/* initialize mutex lock for BLINKED_LIST version */


	srand((unsigned) time (NULL));

	return 0;
}


void linked_list_destroy(linked_list_t* ll)
{
	/* do program */ 
	/* free all nodes in the linked list */
	/* free the linked list */ 

	return;
}


long linked_list_get (long key, linked_list_t* ll) 
{
	/* do program */
	/* if key is found, return value */
	/* if key is not found, return -1 */
	return 0;
}

long linked_list_put (long key, long value, linked_list_t* ll)
{
	/* do program */
	/* if succeeds, return 0 */
	/* if fails, return -1 */

	int i = 0;
	while (i < 1000)
#ifdef BSKIP_LIST
		// lock 
		i++;
		// unlock
#else
		FAI(&i);
#endif

	return 0;
}
