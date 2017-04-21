# include "perceptron.h"

struct perceptron * initialisation(size_t dimension)
{
	struct perceptron * percep = malloc(sizeof(struct perceptron));
	percep->dim = dimension;
	percep->poids = malloc(dimension * sizeof(double));
	percep->entrees = malloc(dimension * sizeof(double));
	percep->seuil = 1;
	for (size_t i = 0; i < dimension; i++)
	{
		percep->poids[i] = (double) rand()/(double) RAND_MAX;
//		printf("Poids : %lf \n",percep->poids[i]); 
	}
	return percep;
}
void sortie_fn_losig(struct perceptron *percep)
{
	double somme = percep->seuil;	 
	for(size_t i = 0; i < percep->dim; i++)
		 somme +=  percep->entrees[i] * percep->poids[i];
	if (somme > 0)
	  percep->sortie = 1.0;
	else
	  percep->sortie = 0.0;
	printf("Somme :%lf \n", somme);
	//percep->sortie =  (1/(1.0+ exp(-coord->typeNote * somme)));
}

void ajustement_poids(struct perceptron * percep, int souhait, double epsilon)
{
	for (size_t i = 0; i < percep->dim; i++)
		percep->poids[i] = percep->poids[i] + epsilon * (souhait - percep->sortie) * percep->entrees[i];//- percep->sortie) *
			   //percep->seuil * percep->sortie * (1 - percep->sortie);
}
struct perceptron ** init_reseau(size_t dimension)
{
	struct perceptron ** tab_percep = malloc(sizeof(struct perceptron * ) * TAILLE);
	for (size_t i = 0 ; i < TAILLE; i++)
	{
		tab_percep[i] = initialisation(dimension);
	}
	return tab_percep;
}
void maj_entrees_reseau(struct perceptron ** tab_percep, double * entrees)
{
	for (size_t i = 0 ; i < TAILLE ; i++)
	{
		tab_percep[i]->entrees = entrees;
	}
}

void apprentissage(struct perceptron ** tab_percep, int souhait)
{
  	for (int i = 0; i < TAILLE; i++)
	{
		sortie_fn_losig(tab_percep[i]);
/*	   printf("Neurone : %d, Type note : %d Nb pas : %f NbPixel : % f NbCol : %zu, Sortie : %lf\n",
 *	   	i+1,coord->typeNote, coord->nbPas,coord->nbPixelNoir,coord->nbCol,tab_percep[i]->sortie);
*/			
		ajustement_poids(tab_percep[i], i == souhait - 1 ? 1 : 0, 0.01);
//		int a;
//		scanf("%d", &a);

	}
}
