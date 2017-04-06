#include "coord.h"

struct s_matrix * draw_rect(struct s_matrix *mat,struct coord * coord )
{
	for (size_t i = coord->maxdown ; i <coord->maxup ;i++)
  {
		mat->data[i*mat->cols+coord->maxleft] = 4 ;
		mat->data[i*mat->cols + coord->maxright] = 4 ;
  }
	for (size_t j = coord->maxleft;j<coord->maxright;j++)
	{
		mat->data[coord->maxup*mat->cols + j] = 4;
		mat->data[coord->maxdown *mat->cols +j] = 4 ;
	}
	return mat ;
}

struct list * fill_list_coord(struct s_matrix * mat)
{
	struct list *res  = malloc (sizeof(struct list));
	list_init(res);
	for (size_t i = 0 ; i<mat->cols ;i++)
	{
		for(size_t j = 0 ; j < mat->cols ;j++)
		{
			if (mat->data[i*mat->cols + j] == 3)
			{
				struct list *elm = malloc(sizeof(struct list));
				struct coord * tmp = malloc(sizeof(struct coord ));
				tmp = propa_coord(mat,i,j);
				elm->data = tmp;
				list_push_front(res,elm);
			}
		}
	}
	return res ;
}

struct coord * propa_coord(struct s_matrix * mat,size_t i ,size_t j )
{
  struct coord * res ;
  return res;
}

