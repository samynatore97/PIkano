# ifndef PERCEPTRON_H_
# define PERCEPTRON_H_
# include "../list.h"
# include <math.h>
struct perceptron
{
	struct list * entrees;
	struct list * poids;
	double (*fn)(struct  perceptron*);
	double epsilon;
	double sortie;
};
void sortie_fn_losig(struct perceptron * percep);
void ajustement_poids(struct perceptron * percep, int souhait);
#endif
