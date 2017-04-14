# include "portee.h"

size_t calcul_pas(struct list * list)
{
	struct list * ptr = list->next;
	while(ptr->next!= NULL)
	{
		size_t data = *(size_t*)ptr->data;
		if (data - 1 != *((size_t *)(ptr->next->data)))
		{
				  return data -(*(size_t * ) (ptr->next->data)) ;
		}
		ptr = ptr->next;
	}
	return 0;
}
