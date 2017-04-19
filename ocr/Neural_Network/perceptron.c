# include "perceptron.h"

struct perceptron * initialisation(size_t dimension)
{
	struct perceptron * percep = malloc(sizeof(struct perceptron));
	percep->dim = dimension;
	percep->poids = malloc(dimension * sizeof(double));
	for (size_t i = 0; i < dimension; i++)
	{
		percep->poids[i] = (double) rand()/(double) RAND_MAX;
	}
	return percep;
}
void sortie_fn_losig(struct perceptron *percep, struct coord * coord)
{
	
	double somme = coord->typeNote * percep->poids[0] + 
			  coord->nbPas * percep->poids[1] +
			  coord->nbPixelNoir * percep->poids[2] +
			  coord->nbCol * percep->poids[3] ;
	percep->sortie =  (1.0/(1.0+ exp(-somme)));
}

void ajustement_poids(struct perceptron * percep, struct coord * coord, int souhait, double epsilon)
{
	percep->poids[0] = percep->poids[0] + epsilon * (souhait - percep->sortie) *
			   coord->typeNote * percep->sortie * (1 - percep->sortie);
	percep->poids[1] = percep->poids[1] + epsilon * (souhait - percep->sortie) *
			   coord->nbPas * percep->sortie * (1 - percep->sortie);
	percep->poids[2] = percep->poids[2] + epsilon * (souhait - percep->sortie) *
			   coord->nbPixelNoir * percep->sortie * (1 - percep->sortie);
	percep->poids[3] = percep->poids[3] + epsilon * (souhait - percep->sortie) *
			   coord->nbCol * percep->sortie * (1 - percep->sortie);
}

struct perceptron ** apprentissage(struct list * entrees)
{
	struct perceptron **  tab_percep = malloc(sizeof(struct perceptron *) * TAILLE) ;
	for(size_t i = 0 ; i < TAILLE; i++)
	{
		tab_percep[i] = initialisation(4);

	}
   struct list * ptr_entrees = entrees->next;
	while(ptr_entrees != NULL)
	{
		struct coord * coord = (struct coord *) ptr_entrees->data;
		for (int i = 0; i < TAILLE; i++)
		{
			sortie_fn_losig(tab_percep[i],coord);
			ajustement_poids(tab_percep[i], coord , (i == (coord->typeNote - 1)) ? coord->typeNote : 0, 0.1);
		}
		ptr_entrees = ptr_entrees->next;
	}
	return tab_percep;
	
}
