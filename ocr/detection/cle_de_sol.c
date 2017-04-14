# include "cle_de_sol.h"

struct s_matrix* detect_cle_sol(struct s_matrix * mat,struct list * list_coord,size_t pas)
{
	struct list * ptr = list_coord->next;
	while (ptr!=NULL)
	{
		struct coord * coord = (struct coord *)ptr->data;
		if ((coord->maxdown - coord->maxup> 5 * pas) && (!coord->isVert))
		{
			for (size_t i = coord->maxup; i < coord->maxdown;i++)
				for(size_t j = coord->maxleft;j < coord->maxright;j++)
				{
					if (mat->data[i*mat->cols+j] == 4)
						mat->data[i*mat->cols+j] = 6;
				}

		}
		ptr = ptr->next;
	}
	return mat;
}

