# include "stat.h"

double moyenne(struct list * list_entrees)
{
	size_t len = list_len(list_entrees);
	struct list * ptr = list_entrees->next;
	double cpt = 0;
	while (ptr!= NULL)
	{
		cpt += *(double *) ptr->data;
		ptr = ptr->next;
	}
	return ((1.0/len)*cpt);
}

double ecart_type(struct list * list_entrees)
{
	size_t len = list_len(list_entrees);
	double cpt = 0;
	struct list * ptr = list_entrees->next;
	while(ptr!= NULL)
	{
		cpt+= paw((*(double *)ptr->data - moyenne(list_entrees)),2);
		ptr = ptr->next;
	}
	return sqrt((1.0/(double) len - 1)*cpt);
}
struct list * normaliser(struct list * list_entrees)
{
	double ecart = ecart_type(list_entrees);
	double moyenne = moyenne(list_entrees);
	struct list * res = malloc(sizeof(struct list));
	list_init(res);
	struct list * ptr = list_entrees->next;
	while (ptr != NULL)
	{
		struct list * elm = malloc(sizeof(struct list));
		double tmp = (*(double *)ptr->data - moyenne)/ecart;
		*elm->data = tmp;
		list_push_front(res,elm);
		ptr= ptr->next;
	}
	return res;
}
