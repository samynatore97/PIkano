# include "output.h"

void create_file_note(struct list * list_coord,char * name)
{	
	FILE * fichier = NULL;
	char * res ;
	asprintf(&res,"%s.txt",name);
	fichier = fopen(res, "w+");
	struct list * ptr = list_coord->next;
	while(ptr != NULL)
	{
	struct coord * coord = (struct coord *)ptr->data;
	fprintf(fichier,"%f %f %zu %d \n"
	,coord->nbPas,coord->nbPixelNoir,coord->nbCol,coord->typeNote); 
	ptr = ptr->next;
	}
	fclose(fichier);
} 
void save_img(SDL_Surface * img,char * name)
{
  FILE * fichier = fopen(name, "w+");
  SDL_SaveBMP(img, name);
}
struct list * genListFromFile(char * path)
{
	 char * realpath ;
	 asprintf(&realpath,"%s.txt",path);
	FILE * fichier = NULL;
	fichier = fopen(realpath,"r");
	struct list * res = malloc(sizeof(struct list));
	list_init(res);
	char line[128];
	while (fgets(line, sizeof line, fichier)!= NULL)
	{
		struct list *elm = malloc(sizeof(struct list));
		struct coord * tmp = malloc(sizeof(struct coord));
		tmp = coord_init(tmp);
		float nbPas;
		float nbPixelNoir;
		size_t nbCol;
		int typeNote;
		int r ;
		r = sscanf(line,"%f %f %zu %d", &nbPas,&nbPixelNoir,&nbCol,&typeNote);
		if (r != 4)
			err(3,"error while writing");
		tmp->nbPas = nbPas;
		tmp->nbPixelNoir = nbPixelNoir;
		tmp->nbCol = nbCol;
		tmp->typeNote = typeNote ;
		elm->data = tmp;
		list_push_front(res,elm);
	}
	fclose(fichier);
	return res ; 
}



