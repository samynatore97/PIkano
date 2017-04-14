# ifndef CLE_DE_SOL_H_
# define CLE_DE_SOL_H_
# include <stdio.h>
# include "../coord.h"
# include "../matrix.h"
# include "../list.h"
struct s_matrix * detect_cle_sol(struct s_matrix * mat, struct list* list_coord,size_t pas);
# endif
