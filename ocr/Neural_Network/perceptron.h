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
	double * poids;
	size_t dim;
//	double (*fn)(struct  perceptron*);
	double sortie;
};
struct perceptron * initialisation(size_t dimension);
void sortie_fn_losig(struct perceptron * percep, struct coord * coord);
void ajustement_poids(struct perceptron * percep, struct coord * coord, int souhait,double epsilon);
struct perceptron **  apprentissage(struct list * entrees);
# endif
