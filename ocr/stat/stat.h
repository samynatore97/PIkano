# ifndef STAT_H_
# define STAT_H_

# include <stdio.h>
# include <math.h>
# include "../list.h"

double moyenne(struct list * list_entrees);
double ecart_type(struct list * list_entrees);
struct list * normaliser(struct list * list_entrees);

# endif
