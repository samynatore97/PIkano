# include <err.h>
# include <stdio.h>

# include "pixel_operations.h"
# include "matrix.h"

struct s_matrix *genMatFromImg(SDL_Surface *img)
{
		size_t lines;
		size_t columns;
		struct s_matrix *result;
		Uint32 pix;
		Uint8 r;
		Uint8 g;
		Uint8 b;

		lines = img->h;
		columns = img->w;
		result = malloc(sizeof(struct s_matrix));
		result->lines = lines;
		result->cols =  columns;
		result->data = malloc(( lines * columns) * sizeof(int));

		for (size_t x = 0 ; x < lines ; x++)
		{
						for (size_t y = 0 ; y < columns; y++)
						{
										r = 0;
										g = 0;
										b = 0;
										pix = getpixel(img, y, x);
										SDL_GetRGB(pix, img->format, &r,&g,&b);
										result->data[x * columns +y] = (int) (r/255);
						}
		}
		return result;
}
int max(int a, int b){
	if (a>b)
		return a ;
	else 
		return b ;
}
int min (int a, int b){
	if (a<b)
		return a;
	else
		return b;
}
SDL_Surface * genImgFromMat(struct s_matrix *mat)
{
	SDL_Surface *result;
	size_t width;
	size_t height;
	Uint32 pix = 0 ;
	width = mat->cols;
	height = mat->lines;
	result = generateEmptySurface(width, height);
	for (size_t x = 0 ; x < height; x++)
	{
		for (size_t y = 0 ; y < width;y++)
		{
			switch (mat->data[x*mat->cols + y])
			{
				case 0 :
					pix = SDL_MapRGB(result->format,0,0,0);
					break;
				case 1 :
					pix = SDL_MapRGB(result->format,255,255,255);
					break;
				case 2 :
					pix = SDL_MapRGB(result->format, 0, 0, 255); 
					break;
				case 3 :
					pix = SDL_MapRGB(result->format,255,0,0);
			}
			putpixel(result, y,x ,pix);
		}
	}
	return result;
}

SDL_Surface* generateEmptySurface(size_t width,size_t height)
{
   SDL_Surface *result ;
   int isBOIsBigEndian;
   isBOIsBigEndian = (SDL_BYTEORDER == SDL_BIG_ENDIAN);
   result = SDL_CreateRGBSurface(SDL_SWSURFACE,width,height,32,
   (isBOIsBigEndian ? 0xff000000 : 0x000000ff),
	(isBOIsBigEndian ? 0x00ff0000 : 0x0000ff00),
	(isBOIsBigEndian ? 0x0000ff00 : 0x00ff0000),
	(isBOIsBigEndian ? 0x000000ff : 0xff000000));
	return result;
}
void print_matrix(struct s_matrix *mat)
{
				for(size_t i = 0 ; i<mat->lines;i++)
				{
								size_t line_offset = i *mat->cols;
								for (size_t j = 0 ; j<mat->cols;j++)
								{
												printf("| %d ",mat->data[line_offset+j]);
								}
								printf("|\n");
				}
}
// Init Matrix
void matrix_init(struct s_matrix *mat, size_t lines, size_t columns)
{
				mat->lines = lines;
				mat->cols = columns;
				mat->data = malloc(lines * columns * sizeof(int));
				for (size_t i = 0 ; i < lines ; i++)
								for(size_t j = 0 ; j <columns ; j++)
												mat->data[i * columns + j]= 1;
}

// Copy Matrix
struct s_matrix *matrix_copy(struct s_matrix *src)
{
	struct s_matrix *cpy;
	if(NULL != src)
	{
		cpy = malloc(sizeof(struct s_matrix));
		matrix_init(cpy,src->lines, src->cols);
		for(size_t i = 0 ; i< cpy->lines; i++)
		{
			for(size_t j = 0 ; j<cpy->cols;j++)
			{
				cpy->data[i * cpy->cols +j] =src->data[i * src->cols + j];
			}
		}
	}
	else
		errx(1,"Could not copy matrix (NULL)");
	return cpy;
}

// Free Matrix 
void matrix_free(struct s_matrix *mat)
{
				if(NULL != mat)
				{
								if(NULL != mat->data)
								{
												free(mat->data);
												free(mat);
								}
				}
				else
								errx(1,"Could not free matrix (NULL)");
}
size_t Min(size_t a , size_t b)
{
  return a > b ? b : a ;
}
size_t Max(size_t a, size_t b)
{
  return a > b ? a : b ;
}
