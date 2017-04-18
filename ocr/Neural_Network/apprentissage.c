# include "apprentissage.h"

void apprentissage()
{
	struct perceptron * tab_percep[TAILLE];
	for(size_t i = 0 ; i < TAILLE; i++)
	{
		struct list * ptr_poids = tab_percep[i]->poids->next;
		while(ptr_poids != NULL)
		{
			*ptr_poids->data =(double) rand()/(double)RAND_MAX;
			ptr_poids = ptr_poids->next;
		}
	}

}
