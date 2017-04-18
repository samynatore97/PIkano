# include "perceptron.h"

void sortie_fn_losig(struct perceptron *percep)
{
	struct list * ptr_entrees = percep->entrees->next;
	int seuil = *(int *)ptr_entrees->data ;
	struct list * ptr_poids = percep->poids->next;
	double somme = 0;
	while(ptr_entrees != NULL || ptr_poids != NULL)
	{
		int  entree = * (int *)ptr_entrees->data;
		double poids = * (double *) ptr_poids->data;
		somme += entree*poids;
		ptr_entrees = ptr_entrees->next;
		ptr_poids = ptr_poids->next;
	}
	percep->sortie =  (seuil/(1+ exp(-somme)));
}

void ajustement_poids(struct perceptron * percep, int souhait)
{
	struct list * ptr_poids = percep->poids->next;
	struct list * ptr_entrees = percep->entrees->next;
	while(ptr_poids != NULL || ptr_entrees != NULL)
	{
		double poids = *(double *) ptr_poids->data;
		int entree = * (int *) ptr_entrees->data;
		poids = poids + percep->epsilon * (souhait - percep->sortie) * entree * percep->sortie * (1 - percep->sortie) ;
		*ptr_poids->data = poids;
		ptr_entrees = ptr_entrees->next;
		ptr_poids = ptr_poids->next;
	}
}
