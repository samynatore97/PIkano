#include "graph_iden.h"
void propagation(struct s_matrix *partition,size_t i , size_t j)
{
	if (partition->data[i*partition->cols+j] == 0 )
	{
		partition->data[i*partition->cols+j] = 3 ;
		if(i + 1 < partition->lines)
		propagation(partition,i+1,j);
		if(i > 0)
		propagation(partition,i-1,j);
		if(j + 1 < partition->cols)
		propagation(partition,i,j+1);
		if(j > 0)
		propagation(partition,i,j-1);
	}
	return ;
}

struct s_matrix* color_graph(SDL_Surface * partition)
{
  struct s_matrix * real_partition = genMatFromImg(partition);
  struct s_matrix * histo = histo_hori(real_partition);
  struct list *num_lines ;
  num_lines = ligne_port(histo);
  struct s_matrix *color ;
  color = color_line(real_partition, num_lines);
	for (size_t i = 0 ; i<color->lines ;i++)
	{
		for (size_t j = 0 ; j<color->cols;j++)
		{
			if( color->data[i*color->cols +j ] == 2)
			{
		//		if(color->data[i+1*color->cols +j] ==0 )
					propagation(color,i+1,j);
		//		if( color->data[i-1 *color->cols+j] == 0)
					propagation(color,i-1,j);
			}
		}
	}
	struct s_matrix * res ;
	res = delete_line(color, num_lines);

	return res ;
}
//struct s_matrix * color_note_graph(struct s_matrix * ma)
struct s_matrix * delete_line(struct s_matrix * mat, struct list * list)
{
	struct list * ptr = list->next; 
	while (ptr != NULL)
	{
		for (size_t j = 0 ; j < mat->cols; j++)
		{
			if (mat->data[((*(size_t *)(ptr->data)) + 1) *mat->cols+j] == 3  || mat->data[((*(size_t *)(ptr->data)) -1) * mat->cols + j ] == 3)
					  mat->data[(*(size_t * )ptr->data)*mat->cols +j ] = 3 ;
			else
			{
			  mat->data[(*(size_t *)ptr->data) * mat->cols + j ] = 1 ;
			}
		}
		ptr = ptr->next ;
	}
	return mat ;
}
/*
struct s_matrix * __delete_line(struct s_matrix * mat, struct list * list)
{
	while (list != NULL)
	{
		for (size_t j = 0 ; j < mat->cols; j++)
		{
			if (mat->data[(list->data + 1) *mat->cols+j] == 0  || mat->data[(list->data -1) * mat->cols + j ] == 0)
					  mat->data[list->data*mat->cols +j ] = 0 ;
			else
			{
			  mat->data[list->data * mat->cols + j ] = 1 ;
			}
		}
		list = list->next ;
	}
	return mat ;
}
*/
//supprime les barres verticales des notes 
struct s_matrix * delete_vert_graph(struct s_matrix * mat, struct list * list)
	{
		size_t cpt ;
		struct list * ptr = list->next;
		while(ptr!=NULL)
		{
			struct coord * coord = (struct coord * ) (ptr->data);
			for (size_t j = coord->maxleft; j < coord->maxright ; j++)
			{
				cpt = 0 ;
				for (size_t i = coord->maxup ; i < coord->maxdown ; i++)
				{
					if (mat->data[i* mat->cols + j] == 4)
					{
						cpt ++;
					}
					if (mat->data[i*mat->cols + j]!=4)
					{
						if (cpt > 0)
						{
							break;
						}
					}
				}
				if(cpt > ((coord->maxdown - coord->maxup)/2))
				{
					coord->isVert = 1;
					for (size_t k = coord->maxup ; k < coord->maxdown ; k++)
					{
							  if (mat->data[k* mat->cols + j ] == 4)
							  {
									 mat->data[k*mat->cols + j ] = 3 ;
							  }
					}
				}
			}
			ptr = ptr->next;
		}
		return mat;
	}
