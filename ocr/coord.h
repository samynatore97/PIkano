# ifndef COORD_H_
# define COORD_H_
# include "matrix.h"
struct coord{
		  int maxup;
		  int maxdown;
		  int maxleft;
		  int maxright;
		  int numnote;
};
struct s_matrix* drawrect(struct s_matrix *mat,struct coord * coord);

# endif
