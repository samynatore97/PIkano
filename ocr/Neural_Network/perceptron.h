# ifndef PERCEPTRON_H_
# define PERCEPTRON_H_
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../list.h"
# include "../coord.h"
# define TAILLE 8
struct perceptron
{
	double * entrees;
	double * poids;
	size_t dim;
//	double (*fn)(struct  perceptron*);
	double sortie;
	double seuil;
};
struct perceptron * initialisation(size_t dimension);
void sortie_fn_losig(struct perceptron * percep);
void ajustement_poids(struct perceptron * percep,int souhait,double epsilon);
struct perceptron ** init_reseau(size_t dimension);
void maj_entrees_reseau(struct perceptron ** tab_percep, double * entrees);
void  apprentissage(struct perceptron ** tab_percep, int souhait);
# endif
