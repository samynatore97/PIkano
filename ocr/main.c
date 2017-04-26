# include "main.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
		 err(1,"must provide an img");
	else if(argc == 2)
	{
	char* path = argv[1];
/*	SDL_Surface* img = load_image(path);
	struct s_matrix* real_partition = genMatFromImg(img);
//	print_matrix(real_partition);
	struct s_matrix *histo = histo_hori(real_partition);
	SDL_Surface * img2;
	img2 = genImgFromMat(histo);
	display_image(img2);

	struct list *num_lines ;
	 num_lines = ligne_port(histo);
	 struct s_matrix *res;
	 res = color_line(real_partition,num_lines);
	 SDL_Surface * img3;
	 img3 = genImgFromMat(res);
	 display_image(img3);
*/
	SDL_Surface *partition1 = load_image(path);
	display_image(partition1);
	SDL_Surface * partitionGS = generateGrayScaleImage(partition1);
	SDL_Surface *partition = generateBlackAndWhiteFromGS(partitionGS);
	display_image(partition);
	struct s_matrix * histo = build_histo_hori(partition);
	struct s_matrix * cpy = matrix_copy(histo);
	SDL_Surface *histo_hori = build_img_histo_hori(histo);
	display_image(histo_hori);
	struct s_matrix *color =  build_color_line(partition);
	SDL_Surface * partition_color = build_img_color_line(color);
	display_image(partition_color);
	
	struct s_matrix *prey = color_graph(partition);
	SDL_Surface *graph = genImgFromMat(prey);
	display_image(graph);

	struct list * num_lines = ligne_port(cpy);
   	size_t pas = calcul_pas(num_lines);	

	struct s_matrix *sans_ligne = delete_line(prey,num_lines);
	SDL_Surface *sans = genImgFromMat(sans_ligne);
	display_image(sans);

	struct list *l2 = fill_list_coord(prey);
//	struct s_matrix * rect = draw_all_rect(prey,l2);
//	SDL_Surface *rec = genImgFromMat(rect);
//	display_image(rec);

	struct s_matrix *bar = delete_vert_graph(prey, l2); 
	SDL_Surface * barr = genImgFromMat(prey);
	display_image(barr);
//refais ta liste de ligne de portée fdp
//	printf("Pas : %zu",pas);
	completeInfoCoord(bar,l2,pas);
//	print_list_coord(l2);

/*
	printf("avant : %zu \n",list_len(l2));
	struct list * l3 = create_list_barre_mesure(bar,l2);
	printf("len de la liste apres détection des barres de mesures : %zu \n ",list_len(l2));
	struct s_matrix * sol = detect_cle_sol(bar,l2,13);
	SDL_Surface * Sol = genImgFromMat(sol);
	display_image(Sol);
	
*/
	display_all_rect(bar,l2);
	create_file_note(l2,path);
	print_list_coord(l2);
	//struct list * l3 = genListFromFile(path);
//	print_list_coord(l3);
//	struct s_matrix * rect = draw_all_rect(bar,l2);
//	SDL_Surface * rec = genImgFromMat(rect);
//	display_image(rec);
	}
	else
	{
		char * path = argv[1];
		struct list * list_coord = genListFromFile(path);
		struct perceptron ** tab_percep = init_reseau(3);
		int i = 0;
		double * entree = malloc(3 * sizeof(double));
		while (i < 500000)
		{
			struct list * ptr = list_coord->next;
			while (ptr != NULL)
			{
				struct coord * coord = (struct coord *)ptr->data;
				if (coord->typeNote != -1)
				{
			  		entree[0] = coord-> nbPas;
			 		entree[1] = coord->nbPixelNoir;
			  		entree[2] = coord->nbCol;
					maj_entrees_reseau(tab_percep, entree);
			  		apprentissage(tab_percep, coord->typeNote);
				}
				ptr = ptr->next;
			}
			i++;
		}
		struct list * ptr_entrees = list_coord->next;
		while(ptr_entrees != NULL)
		{
			struct coord * coord = (struct coord *) ptr_entrees->data;
			if (coord->typeNote != -1)
			{
			  	entree[0] = coord-> nbPas;
			 	entree[1] = coord->nbPixelNoir;
			  	entree[2] = coord->nbCol;
				maj_entrees_reseau(tab_percep, entree);

				printf("Type de note : %d \n",coord->typeNote);
				for (int i = 0 ; i < TAILLE; i++)
				{
					sortie_fn_losig(tab_percep[i]);
					printf(" sortie %lf  \n",tab_percep[i]->sortie);
				}
				printf("\n");
			}
			ptr_entrees = ptr_entrees->next;
		}	
	}
	return 0; 
}
