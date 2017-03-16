# ifndef LIGNE_IDEN_H_
# define LIGNE_IDEN_H_
#include <stdlib.h>
#include "matrix.h"
# include "list.h"
# include "SDL_init.h"
struct s_matrix* histo_hori(struct s_matrix* mat);
struct list* ligne_port(struct s_matrix* mat);
struct s_matrix * color_line(struct s_matrix *mat , struct list* list);
struct s_matrix * build_histo_hori(SDL_Surface * partition);
SDL_Surface * build_img_histo_hori(struct s_matrix * histo);
struct s_matrix * build_color_line(SDL_Surface  * partition);
SDL_Surface * build_img_color_line(struct s_matrix * mat_color_line);



#endif
