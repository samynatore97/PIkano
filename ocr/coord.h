# ifndef COORD_H_
# define COORD_H_
# include "matrix.h"
# include "list.h"
struct coord{
		  size_t maxup;
		  size_t maxdown;
		  size_t maxleft;
		  size_t maxright;
		  size_t numnote;
};
struct s_matrix* drawrect(struct s_matrix *mat,struct coord * coord);
struct coord * propa_coord(struct s_matrix * mat,size_t i ,size_t j);
struct list * fill_list_coord(struct s_matrix * mat);
# endif
