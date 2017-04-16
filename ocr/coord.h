# ifndef COORD_H_
# define COORD_H_
# include "matrix.h"
# include <stdio.h>
# include "SDL_init.h"
# include "surface_operations.h"
# include "list.h"
struct coord{
		  int isVert;
		  size_t maxup;
		  size_t maxdown;
		  size_t maxleft;
		  size_t maxright;
		  size_t numnote;
		  float nbPas;
		  size_t nbPixelNoir;
		  size_t nbCol;
};
struct coord * coord_init(struct coord *coord );
void print_coord(struct coord * coord);
void print_list_coord(struct list * list_coord);
void draw_rect(struct s_matrix *mat, struct coord * coord);
struct s_matrix* draw_all_rect(struct s_matrix * mat, struct list * list);
struct coord * propa_coord(struct s_matrix * mat, size_t i , size_t j, struct coord * coord);
struct list * fill_list_coord(struct s_matrix * mat);
struct list * create_list_barre_mesure(struct s_matrix *mat,struct list * list);
void completeInfoCoord(struct s_matrix * mat,struct list * list_coord, size_t pas);
void fillNbPas(struct coord * coord, size_t pas);
void fillNbPixelNoir(struct s_matrix * mat,struct coord * coord);
void fillNbCol(struct s_matrix * mat, struct coord * coord);
# endif
