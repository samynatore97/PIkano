# ifndef MATRIX_H_
# define MATRIX_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <stdlib.h>
# include <err.h>
// Structure definition
struct s_matrix
{
    size_t lines;
    size_t cols;
    int *data;
};
int max(int a, int b);
int min(int a , int b);
struct s_matrix *genMatFromImg(SDL_Surface *img);
void print_matrix(struct s_matrix *mat);

/*
** matrix_init(mat)
** struct s_matrix* -> |
** Initialize matrix with 0 in every cell
*/
void matrix_init(struct s_matrix *mat, size_t lines, size_t cols);
/*
** matrix_copy(mat)
** struct s_matrix* -> struct s_matrix*
** Returns a copy of the given matrix
*/
struct s_matrix* matrix_copy(struct s_matrix *mat);
SDL_Surface * generateEmptySurface(size_t width, size_t height);
SDL_Surface * genImgFromMat(struct s_matrix * mat);
// Memory Free
void matrix_free();

# endif
