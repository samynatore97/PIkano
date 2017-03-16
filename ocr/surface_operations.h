# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# include "matrix.h"
# include "pixel_operations.h"
/*
** generateGrayScaleImage(img)
** SDL_Surface* -> SDL_Surface*
** Return GrayScaledImage from <img>
*/

SDL_Surface* generateGrayScaleImage(SDL_Surface *img);

/*
** generateBlackAndWhiteFromGS(img)
** SDL_Surface* -> SDL_Surface*
** Return Black And White Image from GrayScaled Image
*/

SDL_Surface* generateBlackAndWhiteFromGS(SDL_Surface *img);
/*
**
**
**
*/

SDL_Surface* copySurface(SDL_Surface *img);
/*
** genBWImgFromMat(mat)
** struct matrix* -> SDL_Surface*
** Return the BlackAndWhite image generated from a [[0;1]] matrix
*/

SDL_Surface* genBWImgFromMat(struct s_matrix *mat);


