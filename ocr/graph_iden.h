# ifndef GRAPH_IDEN_H_
# define GRAPH_IDEN_H_

# include <stdlib.h>
# include "matrix.h"
# include "list.h"
# include "ligne_iden.h"
# include "coord.h"
# include "SDL_init.h"
# include "surface_operations.h"
void propagation(struct s_matrix *partition,size_t i , size_t j);
struct s_matrix * color_graph(SDL_Surface * partition);
struct s_matrix * delete_line(struct s_matrix * mat , struct list * list);
struct s_matrix * delete_vert_graph(struct s_matrix * mat, struct list * list);
#endif
