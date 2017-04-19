#include "coord.h"
#include <unistd.h>
void print_coord(struct coord * coord)
{
//	printf("coordonnees de la note numero : %zu \n",coord->numnote);
//	printf("coordonnees du coin gauche : %zu, %zu \n", coord->maxup, coord->maxleft);
//	printf("coordonnees du coin droit : %zu , %zu \n", coord->maxdown,coord->maxright);
	printf("Nombre de pas : %f \n", coord->nbPas);
	printf("Ratio PixelNoir/Pixelblanc: %f \n",coord->nbPixelNoir);
	printf("Nombre de barres verticales : %zu \n",coord->nbCol);
	printf("Type de note : %d \n \n",coord->typeNote); 
}
void print_list_coord(struct list * list_coord)
{
	struct list * ptr = list_coord->next;
	while(ptr!=NULL)
	{
		struct coord * coord = (struct coord *)ptr->data;
		print_coord(coord);
		printf("\n");
		ptr = ptr->next;
	}
}
struct coord * coord_init(struct coord * coord)
{
	coord->isVert = 0;
	coord->nbPas = 0;
	coord->nbPixelNoir = 0;
	coord->nbCol = 0;
	coord->typeNote = -1;
	return coord;
}
void  draw_rect(struct s_matrix *mat,struct coord * coord )
{
	for (size_t i = coord->maxup ; i <coord->maxdown ;i++)
  {
		mat->data[i*mat->cols + coord->maxleft] = 5 ;
		mat->data[i*mat->cols + coord->maxright+17] = 5 ;
  }
	for (size_t j = coord->maxleft;j<coord->maxright + 17 ;j++)
	{
		mat->data[coord->maxup*mat->cols + j] = 5;
		mat->data[coord->maxdown *mat->cols + j] = 5 ;
	}
	return ;
}
struct s_matrix * draw_all_rect(struct s_matrix *mat,struct list * list)
{
	struct list* ptr = list->next;
	while(ptr != NULL)
	{
		struct s_matrix * cpy = matrix_copy(mat);
		struct coord * coord = (struct coord *)(ptr->data);
		draw_rect(cpy,coord);
		SDL_Surface * update = genImgFromMat(cpy);
		display_image(update);

		ptr = ptr->next ;
	}
	return mat ;
}
struct s_matrix * get_mat_rect(struct s_matrix * mat, struct coord * coord)
{
	struct s_matrix * res = malloc(sizeof(struct s_matrix));
	 matrix_init(res, (coord->maxdown - coord->maxup), (coord->maxright - coord->maxleft));
	for(size_t i = 0 ; i < res->lines;i++)
	{
		for (size_t j = 0 ; j < res->cols; j++)
		{
			res->data[i*res->cols + j] = mat->data[(i + coord->maxup)*mat->cols + (j + coord->maxleft)];
		}
	}
	return res ; 
}
void display_all_rect(struct s_matrix * mat,struct list * list_coord)
{
	struct list * ptr = list_coord->next;
	while(ptr != NULL)
	{
		struct coord * coord = (struct coord *) ptr->data;
		struct s_matrix *rect = get_mat_rect(mat, coord);
		SDL_Surface * update = genImgFromMat(rect);
		display_image(update);
		int note = 0;
		scanf("%d",&note);
		coord->typeNote = note;
		ptr = ptr->next;
	}
}
struct list * fill_list_coord(struct s_matrix * mat)
{
	struct list *res  = malloc (sizeof(struct list));
	list_init(res);
	size_t cpt = 0;
	for (size_t i = 0 ; i<mat->lines ;i++)
	{
		for(size_t j = 0 ; j < mat->cols ;j++)
		{
			if (mat->data[i*mat->cols + j] == 3)
			{
				struct list *elm = malloc(sizeof(struct list));
				struct coord * tmp = malloc(sizeof(struct coord ));
				tmp = coord_init(tmp);
				tmp->maxup = i;
				tmp->maxdown = i;
				tmp->maxleft = j;
				tmp->maxright = j;
				tmp->numnote = cpt +1;
				tmp = propa_coord(mat,i,j,tmp);
				elm->data = tmp;
				list_push_front(res,elm);
				cpt++;
			}
		}
	}
	return res ;
}
//struct list* delete_sub_coord(struct list *)
//{
//}
struct coord * propa_coord(struct s_matrix * mat,size_t i ,size_t j,struct coord * coord )
{
  if (mat->data[i*mat->cols+j] == 3)
  {
		mat->data[i*mat->cols+j] = 4;
		coord->maxup = min(i,coord->maxup);
		coord->maxdown = max(i,coord->maxdown);
		coord->maxleft = min(j,coord->maxleft);
		coord->maxright = max(j,coord->maxright);
		if(i+1 <mat->lines)
			propa_coord(mat,i+1,j, coord);
		if(i > 0)
			propa_coord(mat,i-1,j, coord);
		if (j+1<mat->cols)
			propa_coord(mat,i,j+1, coord);
		if(j > 0)
			propa_coord(mat,i,j-1, coord);

  }
  return coord;
}
struct list * create_list_barre_mesure(struct s_matrix * mat,struct list * list)
{
	struct list * res = malloc(sizeof(struct list));
	list_init(res);
	struct list * ptr = list->next;
	int test = 1;
	while(ptr != NULL)
	{
		struct coord * coord = (struct coord * ) (ptr->data);
		test = 1;
		for(size_t i = coord->maxup; i < coord->maxdown; i++)
		{				
			for(size_t j = coord->maxleft; j < coord->maxright ; j++)
			{
				if(mat->data[i*mat->cols + j] !=3)
					test = 0;
			}
		}
		if(test)
		{
			list_pop_front(ptr);
			struct list * elm = malloc(sizeof(struct list));
			elm->next = NULL;
			elm->data = coord;
			list_push_front(res,elm);
		}

		ptr = ptr->next;
	}
	return res;
}

void completeInfoCoord(struct s_matrix * mat, struct list * list_coord,size_t pas)
{
	struct list * ptr = list_coord->next;
	while(ptr != NULL)
	{
		struct coord * coord = (struct coord *) ptr->data;
		fillNbPas(coord, pas);
		fillNbPixelNoir(mat, coord);
		fillNbCol(mat, coord);
		ptr = ptr->next;
	}
}

void fillNbPas(struct coord * coord, size_t pas)
{
	coord->nbPas = ((float)(coord->maxdown - coord->maxup)) / (float) pas ;
}

void fillNbPixelNoir(struct s_matrix * mat, struct coord * coord)
{
	int cpt = 0;
	coord->nbPixelNoir = 0 ;
	for (size_t i = coord->maxup ; i < coord->maxdown ; i++)
	{
		for (size_t j = coord->maxleft ; j < coord->maxright ; j++)
		{
			if (mat->data[i * mat->cols + j] != 1)
			{
				coord->nbPixelNoir++;
			}
			else
			{
				cpt ++;
			}
		}
	}
	if (cpt)
	coord->nbPixelNoir /= cpt; 
}

void fillNbCol(struct s_matrix * mat, struct coord * coord)
{
	if(coord->isVert)
	{
		coord->nbCol = 0;
		int test = 0;
		for(size_t j = coord->maxleft ; j < coord->maxright ; j++)
		{
			size_t cpt = 0;
			for (size_t i = coord->maxup ; i < coord->maxdown ; i++)
			{
				if(mat->data[i * mat->cols + j] == 3 && !test)
				{
					test = 1;
					coord->nbCol++;
				}

				if(mat->data[i * mat->cols + j]!=3)
				{
					cpt++;
				}


			}
			if (cpt == coord->maxdown - coord->maxup)
			{
				test = 0;
			}
		}
	}
	else
	{
		coord->nbCol = 0;
	}
}
