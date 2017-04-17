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
	fprintf(fichier,"Nombre de pas : %f \n"
	"Ratio PixelNoir/Pixelblanc: %f \n"
	"Nombre de barres verticales : %zu \n"
	"Type de note : %d \n \n"
	,coord->nbPas,coord->nbPixelNoir,coord->nbCol,coord->typeNote); 
	ptr = ptr->next;
	}
	fclose(fichier);
} 



