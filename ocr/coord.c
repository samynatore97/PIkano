#include "coord.h"
void print_coord(struct coord * coord)
{
	printf("coordonnees de la note numero : %zu \n",coord->numnote);
	printf("coordonnees du coin gauche : %zu, %zu \n", coord->maxup, coord->maxleft);
	printf("coordonnees du coin droit : %zu , %zu \n", coord->maxdown,coord->maxright); 
}
struct coord * coord_init(struct coord * coord)
{
	coord->isVert = 0;
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
		struct coord * coord = (struct coord *)(ptr->data);
		draw_rect(mat,coord);
		ptr = ptr->next ;
	}
	return mat ;
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
