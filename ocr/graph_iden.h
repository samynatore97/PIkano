# ifndef GRAPH_IDEN_H_
# define GRAPH_IDEN_H_

# include <stdlib.h>
# include "matrix.h"
# include "list.h"
# include "ligne_iden.h"
# include "coord.h"
void propagation(struct s_matrix *partition,size_t i , size_t j);
struct s_matrix* color_graph(SDL_Surface * partition);


#endif
