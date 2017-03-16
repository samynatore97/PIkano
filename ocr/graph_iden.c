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
  struct s_matrix *color;
  color = color_line(real_partition,num_lines); 
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
	return color ;
}

