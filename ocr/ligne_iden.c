#include "ligne_iden.h"
struct s_matrix* histo_hori(struct s_matrix* mat)
{
	struct s_matrix* res;
	res = malloc(sizeof(struct s_matrix));
	matrix_init(res,mat->lines,mat->cols);
	for(size_t i = 0 ; i<mat->lines; i++)
	{
		size_t k = 0;
		for (size_t j = 0 ; j<mat->cols; j++)
		{
			if (mat->data[i*mat->cols + j] == 0)
			{
				res->data[i*res->cols + k] = 0 ;
				k++;
			}

		}	
	}
	return res;
}

struct list * ligne_port(struct s_matrix* mat)
{
	struct list  *res = malloc(sizeof(struct list));
	list_init(res);
	for (size_t i = 0 ; i<mat->lines; i++)
	{
		 size_t cpt = 0;
		 
		 for(size_t j = 0 ; j<mat->cols;j++)
		 {
			if(mat->data[i*mat->cols + j] == 0)
			   cpt++;
	    }
		 if (cpt>=( mat->cols/2))
		 {
			 struct list * elm = malloc(sizeof(struct list));
//			 elm->next =NULL;
			 size_t * tmp = malloc(sizeof(size_t));
			 *tmp = i;
			 elm->data = tmp;
			 list_push_front(res,elm);
			 
		 }
	}
	struct list* ptr = res->next;
	while (ptr != NULL)
	{
		printf("%zu \n ",*((size_t *)ptr->data));
		ptr = ptr->next ;
	}
	printf("fin lign_port");
  	return res;
}

struct s_matrix* color_line(struct s_matrix * partition, struct list* list)
{
//	struct s_matrix * partition;
//	partition = matrix_copy(mat);
   struct list* ptr  = list->next;
	while(ptr != NULL)
	{
		for(size_t j = 0 ; j <partition->cols;j++)
			{
				if(partition->data[*((size_t *)(ptr->data))*partition->cols+j] ==0)
				   partition->data[*((size_t *)(ptr->data))*partition->cols+j] = 2;
			}
		ptr= ptr->next;
	}
  return partition;
}

// renvoie la matrice  de l histogramme horizontale de la partition
struct s_matrix * build_histo_hori(SDL_Surface * partition)
{
  struct s_matrix * real_partition = genMatFromImg(partition);
  struct s_matrix * histo = histo_hori(real_partition);
  return histo;
}
//renvoie l'img de l'histo a partir de la matrice de l'histo
SDL_Surface * build_img_histo_hori(struct s_matrix * histo)
{
  SDL_Surface * img ;
  img = genImgFromMat(histo);
  return img; 
}
//renvoie la matrice modifie avec les lignes en couleur
struct s_matrix * build_color_line(SDL_Surface  * partition)
{
  struct s_matrix * real_partition = genMatFromImg(partition);
  struct s_matrix * histo = histo_hori(real_partition);
  struct list *num_lines ;
  num_lines = ligne_port(histo);
  struct s_matrix *res;
  res = color_line(real_partition,num_lines);
  return res;
}

SDL_Surface * build_img_color_line(struct s_matrix * mat_color_line)
{
  SDL_Surface * img ;
  img = genImgFromMat(mat_color_line);
  return img ; 
}

