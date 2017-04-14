# include "main.h"

int main(int argc, char *argv[])
{
	if(argc <1)
		 err(1,"must provide an img");
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
	SDL_Surface *histo_hori = build_img_histo_hori(histo);
	display_image(histo_hori);
	struct s_matrix *color =  build_color_line(partition);
	SDL_Surface * partition_color = build_img_color_line(color);
	display_image(partition_color);
	
	struct s_matrix *prey = color_graph(partition);
	SDL_Surface *graph = genImgFromMat(prey);
	display_image(graph);

	struct list *l2 = fill_list_coord(prey);
//	struct s_matrix * rect = draw_all_rect(prey,l2);
//	SDL_Surface *rec = genImgFromMat(rect);
//	display_image(rec);

	struct s_matrix *bar = delete_vert_graph(prey, l2);
	SDL_Surface * barr = genImgFromMat(prey);
	display_image(barr);

	printf("avant : %zu \n",list_len(l2));
	struct list * l3 = create_list_barre_mesure(bar,l2);
	printf("len de la liste apres détection des barres de mesures : %zu \n ",list_len(l2));
	struct s_matrix * sol = detect_cle_sol(bar,l2,13);
	SDL_Surface * Sol = genImgFromMat(sol);
	display_image(Sol);
	struct s_matrix * rect = draw_all_rect(bar,l2);
	SDL_Surface * rec = genImgFromMat(rect);
	display_image(rec);
	return 0; 
}
