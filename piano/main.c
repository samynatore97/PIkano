#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "pixel_operations.h"
#include "time.h"

#include <time.h>
 
void my_delay(int i){
 clock_t start,end;
 start=clock();
 while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000));
}

SDL_Surface* line()
{
  SDL_Surface *screen = NULL, *rectangle = NULL, *text=NULL;
  SDL_Rect position;
  SDL_Color black={20,20,20,0};
  /* screen set */
  screen = SDL_SetVideoMode(1265, 550, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Pikano", NULL);

  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 52, 73, 94));

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1265 ,430,32,0,0,0,0);
  position.y = 215;
  position.x=0;
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format,8,8,8));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1265 ,215,32,0,0,0,0);
  position.y = 0;
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format,22,22,22));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1265 ,2,32,0,0,0,0);
  position.y = 214;
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format,192,57,43));
  SDL_BlitSurface(rectangle, NULL, screen, &position);


  TTF_Font *police = NULL;
  police = TTF_OpenFont("Ubuntu-B.ttf", 17);
  text = TTF_RenderText_Blended(police, "Done", black);

  /* button */
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,101 , 31, 32, 0, 0, 0, 0);
  position.x = 630;
  position.y=5;
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 189, 195, 199));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  /* path box */
  position.x=10;
  position.y=5;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,610 , 25, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 44, 62, 80));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
 
  /* mic */

  SDL_Surface *mic=IMG_Load("images/mic.png");
  position.x = 900;
  position.y = 5;
  SDL_BlitSurface(mic, NULL, screen, &position);

  /* touches */
  SDL_Surface *touche=IMG_Load("images/do.png");
  position.x=5;
  position.y=250;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=320;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=635;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=950;
  SDL_BlitSurface(touche, NULL, screen, &position);

  
  touche=IMG_Load("images/re.png");
  position.x=50;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=365;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=680;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=995;
  SDL_BlitSurface(touche, NULL, screen, &position);


  touche=IMG_Load("images/mi.png");
  position.x=95;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=410;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=725;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1040;
  SDL_BlitSurface(touche, NULL, screen, &position);


  touche=IMG_Load("images/do.png");//fa
  position.x=140;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=455;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=770;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1085;
  SDL_BlitSurface(touche, NULL, screen, &position);

  touche=IMG_Load("images/sol.png");
  position.x=185;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=500;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=815;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1130;
  SDL_BlitSurface(touche, NULL, screen, &position);

  touche=IMG_Load("images/la.png");
  position.x=230;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=545;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=860;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1175;
  SDL_BlitSurface(touche, NULL, screen, &position);

  touche=IMG_Load("images/mi.png"); //si
  position.x=275;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=590;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=905;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1220;
  SDL_BlitSurface(touche, NULL, screen, &position);
  

  touche=IMG_Load("images/bemol.png");
  position.x=29;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=84;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=164;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=214;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=265;
  SDL_BlitSurface(touche, NULL, screen, &position);
  
  position.x=344;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=399;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=479;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=530;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=580;
  SDL_BlitSurface(touche, NULL, screen, &position);
  
  position.x=659;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=715;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=794;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=845;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=895;
  SDL_BlitSurface(touche, NULL, screen, &position);
 
  position.x=974;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1029;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1109;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1159;
  SDL_BlitSurface(touche, NULL, screen, &position);
  position.x=1209;
  SDL_BlitSurface(touche, NULL, screen, &position);
 
  /* "done" */
  position.x=656;
  position.y=10;
  SDL_BlitSurface(text, NULL, screen, &position);

 /* design path box */
  position.y=5;
  position.x=11;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,609 , 1, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
  
  position.x=10;
  position.y=6;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1 , 24, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  position.x = 620;
  position.y = 6;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1 , 24, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
   
  position.y=30;
  position.x=11;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,609 , 1, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
  /* end */
  return screen;
}

int charPos(char* s,char c){
  int l=strlen(s);
  int res=-1,test=1,i=l-1;
  while(i>=0 && test==1){
	if(s[i] == c){
	  test=0;
	  res=i;
	}
	i--;
  }
  return res;
}

int charComp(char* a, char* b){
  int la=strlen(a);
  int lb=strlen(b);
  if(la!=lb){
	return -1;
  }
  int test=1,i=0;
  while(i>la && test==1){
	if(a[i]!=b[i]) test=-1;
	i++;
  }
  return test;
}		

int StrToInt(char *s){
  int res=0;
  int len=strlen(s);
  for(int i=0;i<len;i++){
    res+=s[i]-48;
    if(i!=len-1)
      res*=10;
  }
  return res;
}


void path_write(SDL_Surface *screen){ //write the path
  SDL_Rect position;
  SDL_Surface *rectangle=NULL;

  position.x=10;
  position.y=5;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,610 , 25, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 44, 62, 80));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  position.y=5;
  position.x=11;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,609 , 1, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  position.x=10;
  position.y=6;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1 , 24, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  position.x = 620;
  position.y = 6;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,1 , 24, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  position.y=30;
  position.x=11;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,609 , 1, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);  
}

void click_button(SDL_Surface *screen,int x,int y) //animation button
{
  SDL_Rect position;
  SDL_Surface *rectangle=NULL, *text=NULL;
  SDL_Color black = {20, 20, 20,0};
 
  TTF_Font *police = NULL;
  police = TTF_OpenFont("Ubuntu-B.ttf", 17);
  text = TTF_RenderText_Blended(police, "Done", black);
 
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,101 , 31, 32, 0, 0, 0, 0);
  position.x = x;
  position.y = y;
  
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 189, 195, 199));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
 
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 100, 30, 32, 0, 0, 0, 0);

  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 189, 195, 199));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
 
  position.x=656;
  position.y=10;
  SDL_BlitSurface(text, NULL, screen, &position);
  
  position.x =x;
  position.y=y;
  SDL_Flip(screen);
  SDL_Delay(200);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE,101 , 31, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(rectangle, NULL, screen, &position);

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 100, 30, 32, 0, 0, 0, 0);

  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 189, 195, 199));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
  position.x=656;
  position.y=10;
  SDL_BlitSurface(text, NULL, screen, &position);

  SDL_Flip(screen);
}

char* readToStr(char* fname){
 int fd;
 if((fd=open(fname,O_RDONLY,0666))==-1) {
  return "000";
 }
 char buf[1];
 int r,cpt=0;
 char* res=malloc(sizeof(char));
 while((r=read(fd,buf,1)) !=0){
   res=realloc(res,(strlen(res)+1)*sizeof(char));
   if(r == -1) break; 
   for(int i=cpt;i<cpt+(int)strlen(buf);i++){
     res[i]=buf[i-cpt];
   }
   cpt++;
 }
 if(r==-1) return "000";
 int j=0,test=1;
 while(j<(int)strlen(res) && test==1){
   if(res[j] == 'E') //caractere de fin défini
	 test=0;
   else j++;
 }
 res=realloc(res,(strlen(res)-(strlen(res)-j))*sizeof(char)); 
 res[j]='\0';
 close(fd);
 return res;
}


void error_img(SDL_Surface *screen,int test_int) //if the path is wrong
{
 SDL_Rect position;
 position.x=760;
 position.y=10;
 if(test_int == 0)
 {
  SDL_Color black = {192, 57, 53,0};
  SDL_Surface *text=NULL;  

  TTF_Font *police = NULL;
  police = TTF_OpenFont("Ubuntu-B.ttf", 17);
  text = TTF_RenderText_Blended(police, "Wrong path!", black);
  SDL_BlitSurface(text, NULL, screen, &position);
 }
 else
 { 
  SDL_Surface *rectangle=NULL;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 100, 30, 32, 0, 0, 0, 0); 
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format,22, 22, 22));
  SDL_BlitSurface(rectangle, NULL, screen, &position);
 } 
 SDL_Flip(screen);
}

void reading(char* c){
 int l=strlen(c);
 int k=0;
 char son[12];
 son[0]='s';
 son[1]='o';
 son[2]='n';
 son[3]='s';
 son[4]='/';
 son[8]='.';
 son[9]='w';
 son[10]='a';
 son[11]='v';
 char temp[3];
 for(int i=0;i<3;i++){
   temp[i]=c[i];
 }
 for(int i=3;i<l;i+=3){
  if(c[i]!=' '){
    son[5]=c[i];
    son[6]=c[i+1];
    son[7]=c[i+2];
	if(son[5]=='c'){
	  son[5] = 'b';
	}
	Mix_Chunk *musique = Mix_LoadWAV(son);
    if(k == 48) k=0;
	Mix_PlayChannel(k,musique, 0);
	k++;
	if(c[i]!='c'&&c[i]!='b') my_delay(StrToInt(temp));
	else if(c[i]=='c') my_delay(StrToInt(temp)/2);
	else my_delay(StrToInt(temp)*2);
  }
  else my_delay(StrToInt(temp)/2);
 } 
}

int main(int argc, char* argv[]) //main function
{
 /* init */
 SDL_Surface  *screen=NULL, *text=NULL;
 int test_int=1,x,y; 
 
 size_t k=0;
 char *inputText=malloc(sizeof(char));
 SDL_Color white = {255,255,255,0};
 SDL_Event event;
 SDL_Rect position;
 if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)== -1)
   printf("%s", Mix_GetError());
   
 TTF_Init();
 TTF_Font *police = NULL;
 police = TTF_OpenFont("Ubuntu-B.ttf", 14);
 SDL_Init(SDL_INIT_VIDEO);
 screen=line();
 SDL_Flip(screen);

 SDL_EnableUNICODE(1);
 position.x=30;
 position.y=8;

 int micTest = 1;
 Mix_AllocateChannels(48);
 char *record=malloc(3*sizeof(char));
 record[0]='2';
 record[1]='5';
 record[2]='0';
 int rcpt=3; //cpt for the tab

 if(argc == 2){
   char *mus=malloc(1024*sizeof(char));
   mus = readToStr(argv[1]);
   if(charComp(mus,"000")!=-1) error_img(screen,0);
   else reading(mus);

 }

 /* SDL_event */
 while ( test_int ) {
     while ( SDL_PollEvent(&event) ) {
         switch (event.type) {     
             case SDL_MOUSEMOTION:
                 break;
             case SDL_MOUSEBUTTONDOWN:
                 x = event.button.x;
                 y = event.button.y;
				 
				 if((x>=900 && x<=940)&&(y>=5 && y<=45)) // mic
				 {
				    if(micTest == 1){
					  SDL_Surface *mic=IMG_Load("images/micOn.png");
					  micTest =0;
					  position.x = 900;
					  position.y = 5;
					  SDL_BlitSurface(mic, NULL, screen, &position);

					}
					else {
					  SDL_Surface *mic=IMG_Load("images/mic.png");
					  micTest=1;
					  position.x = 900;
					  position.y = 5;
					  SDL_BlitSurface(mic, NULL, screen, &position);
					  record=realloc(record,(strlen(record)+2)*sizeof(char));
					  record[rcpt]='E';
					  record[rcpt+1]='\0';
					  int fd;
					  if ((fd = open("record.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
						err(3, "error while opening %s", "record");
					  }

					  write(fd, record, strlen(record));

			          close(fd);
								   

					}
					SDL_Flip(screen);
				 }

                 if((x>=630 && x<=731)&&(y>=5 && y<=36)) //button done
                 {
                  click_button(screen,630,5);
				  char* format=malloc(4*sizeof(char));
				  int len = strlen(inputText);
				  int PointPos=charPos(inputText,'.');
				  if(len > 4 && PointPos!=-1){
					for(int i=PointPos;i<len;i++){ 
					  format[i-PointPos]=inputText[i];
					}
				  }
				  else error_img(screen,0);
				  int r=charComp(format,".txt");
				  if(r==-1) error_img(screen,0);
				  if(r!=-1){ // TEXT PART 
				    char* text=malloc(1024*sizeof(char));
					printf("input text = %s\n" , inputText);
					text=readToStr(inputText); 
					printf("text = %s\n",text);
					if(charComp(text,"000")!=-1){ 
					  error_img(screen,0);
					}
					else{
					  reading(text);
					}
				  } 
				  /*else{ // IMAGE PART
					if(load_image(inputText) != NULL)
					{
					  SDL_Surface  *img = load_image(inputText);
					  ////// voir avec Samuel /////// (traitement d'image etc) cf projet s3

				    }	  
                  }*/
				 }

		 //// 1st gamme ////
                 
		 else if((x>=29 && x<=55)&&(y>=250 && y<=430)) {
                  Mix_Chunk *son1 = Mix_LoadWAV("sons/db1.wav");
				  Mix_PlayChannel(1,son1,0);
				  if(micTest==0) { 	
		  			record=realloc(record,(strlen(record)+3)*sizeof(char));
					record[rcpt]='d';
					record[rcpt+1]='b';
					record[rcpt+2]='1';
					rcpt+=3;}
				  
                 }
		 
		 else if((x>=84 && x<=100)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son2 = Mix_LoadWAV("sons/rb1.wav");
				   Mix_PlayChannel(2,son2,0);
				  if(micTest==0) { 		
					record=realloc(record,(strlen(record)+3)*sizeof(char));
					record[rcpt]='r';
					record[rcpt+1]='b';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }
		
		 else if((x>=164 && x<=190)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son3 = Mix_LoadWAV("sons/fb1.wav");
				   Mix_PlayChannel(3,son3,0);
				  if(micTest==0) { 		
					record=realloc(record,(strlen(record)+3)*sizeof(char));			// record
					record[rcpt]='f';
					record[rcpt+1]='b';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }

                 else if((x>=214 && x<=240)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son4 = Mix_LoadWAV("sons/sb1.wav");
				   Mix_PlayChannel(4,son4,0);
				  if(micTest==0) { 		
					record=realloc(record,(strlen(record)+3)*sizeof(char));			// record
					record[rcpt]='s';
					record[rcpt+1]='b';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }
                 
		 else if((x>=265 && x<=290)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son5 = Mix_LoadWAV("sons/lb1.wav");
				   Mix_PlayChannel(5,son5,0);
				  if(micTest==0) { 		
					record=realloc(record,(strlen(record)+3)*sizeof(char));			// record
					record[rcpt]='l';
					record[rcpt+1]='b';
					record[rcpt+2]='1';
					rcpt+=3;}
                 }

		 else if((x>=5 && x<=45)&&(y>=250 && y<=550)) {
                  //musique = Mix_LoadMUS("sons/do1.wav");
                  //Mix_PlayMusic(musique, 1);
				  Mix_Chunk *son6 = Mix_LoadWAV("sons/do1.wav");
				  Mix_PlayChannel(6,son6,0);
				  if(micTest==0) { 			
					record=realloc(record,(strlen(record)+3)*sizeof(char));		// record
					record[rcpt]='d';
					record[rcpt+1]='o';
					record[rcpt+2]='1';
					rcpt+=3;}
                 }
				 
		 else if((x>=50 && x<=90)&&(y>=250 && y<=550)) {
		  //musique = Mix_LoadMUS("sons/re1.wav");
		  //Mix_PlayMusic(musique, 1);
		   Mix_Chunk *son7 = Mix_LoadWAV("sons/re1.wav");
		   Mix_PlayChannel(7,son7,0);
				  if(micTest==0) {
					record=realloc(record,(strlen(record)+3)*sizeof(char)); 					// record
					record[rcpt]='r';
					record[rcpt+1]='e';
					record[rcpt+2]='1';
					rcpt+=3;}
		 }

                 else if((x>=95 && x<=135)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son8 = Mix_LoadWAV("sons/mi1.wav");
				   Mix_PlayChannel(8,son8,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='m';
					record[rcpt+1]='i';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }

                 else if((x>=140 && x<=180)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son9 = Mix_LoadWAV("sons/fa1.wav");
				   Mix_PlayChannel(9,son9,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='a';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }
	
                 else if((x>=185 && x<=225)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son10 = Mix_LoadWAV("sons/so1.wav");
				   Mix_PlayChannel(10,son10,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='o';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }

                 else if((x>=230 && x<=270)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son11 = Mix_LoadWAV("sons/la1.wav");
				   Mix_PlayChannel(11,son11,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='a';
					record[rcpt+2]='1';
					rcpt+=3;}
                  }

                 else if((x>=275 && x<=315)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son12 = Mix_LoadWAV("sons/si1.wav");
				   Mix_PlayChannel(12,son12,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='i';
					record[rcpt+2]='1';
					rcpt+=3;}
                 }
 
		 //// 2nd gamme ////	
		 else if((x>=344 && x<=370)&&(y>=250 && y<=430)) {
                  Mix_Chunk *son13 = Mix_LoadWAV("sons/db2.wav");
				   Mix_PlayChannel(13,son13,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='b';
					record[rcpt+2]='2';
					rcpt+=3;}
                 }
		 
		 else if((x>=399 && x<=425)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son14 = Mix_LoadWAV("sons/rb2.wav");
				   Mix_PlayChannel(14,son14,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='r';
					record[rcpt+1]='b';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }
		
		 else if((x>=479 && x<=505)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son15 = Mix_LoadWAV("sons/fb2.wav");
				   Mix_PlayChannel(15,son15,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='b';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }

                 else if((x>=530 && x<=555)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son16 = Mix_LoadWAV("sons/sb2.wav");
				   Mix_PlayChannel(16,son16,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='b';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }
                 
		 else if((x>=580 && x<=605)&&(y>=250 && y<=430)) {
                  Mix_Chunk *son17 = Mix_LoadWAV("sons/lb2.wav");
				   Mix_PlayChannel(17,son17,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='b';
					record[rcpt+2]='2';
					rcpt+=3;}
                 }

		 else if((x>=320 && x<=360)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son18 = Mix_LoadWAV("sons/do2.wav");
				   Mix_PlayChannel(18,son18,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='o';
					record[rcpt+2]='2';
					rcpt+=3;}
                 }
				 
		 else if((x>=365 && x<=405)&&(y>=250 && y<=550)) {
		  Mix_Chunk *son19 = Mix_LoadWAV("sons/re2.wav");
				   Mix_PlayChannel(19,son19,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='r';
					record[rcpt+1]='e';
					record[rcpt+2]='2';
					rcpt+=3;}
		 }

                 else if((x>=410 && x<=450)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son20 = Mix_LoadWAV("sons/mi2.wav");
				   Mix_PlayChannel(20,son20,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='m';
					record[rcpt+1]='i';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }

                 else if((x>=455 && x<=495)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son21 = Mix_LoadWAV("sons/fa2.wav");
				   Mix_PlayChannel(21,son21,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='a';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }

                 else if((x>=500 && x<=540)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son22 = Mix_LoadWAV("sons/so2.wav");
				   Mix_PlayChannel(22,son22,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='o';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }

                 else if((x>=545 && x<=585)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son23 = Mix_LoadWAV("sons/la2.wav");
				   Mix_PlayChannel(23,son23,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='a';
					record[rcpt+2]='2';
					rcpt+=3;}
                  }

                 else if((x>=590 && x<=630)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son24 = Mix_LoadWAV("sons/si2.wav");
				   Mix_PlayChannel(24,son24,0);
				  if(micTest==0) {
					record=realloc(record,(strlen(record)+3)*sizeof(char)); 					// record
					record[rcpt]='s';
					record[rcpt+1]='i';
					record[rcpt+2]='2';
					rcpt+=3;}
                 }

		 //// 3rd gamme ////	
		 else if((x>=659 && x<=685)&&(y>=250 && y<=430)) {
                  Mix_Chunk *son25 = Mix_LoadWAV("sons/db3.wav");
				   Mix_PlayChannel(25,son25,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='b';
					record[rcpt+2]='3';
					rcpt+=3;}
                 }
		 
		 else if((x>=715 && x<=740)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son26 = Mix_LoadWAV("sons/rb3.wav");
				   Mix_PlayChannel(26,son26,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='r';
					record[rcpt+1]='b';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }
		
		 else if((x>=794 && x<=820)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son27 = Mix_LoadWAV("sons/fb3.wav");
				   Mix_PlayChannel(27,son27,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='b';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }

                 else if((x>=845 && x<=870)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son28 = Mix_LoadWAV("sons/sb3.wav");
				   Mix_PlayChannel(28,son28,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='b';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }
                 
		 else if((x>=895 && x<=920)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son29 = Mix_LoadWAV("sons/lb3.wav");
				   Mix_PlayChannel(29,son29,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='b';
					record[rcpt+2]='3';
					rcpt+=3;}
                 }

		 else if((x>=635 && x<=675)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son30 = Mix_LoadWAV("sons/do3.wav");
				   Mix_PlayChannel(30,son30,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='o';
					record[rcpt+2]='3';
					rcpt+=3;}
                 }
				 
		 else if((x>=680 && x<=720)&&(y>=250 && y<=550)) {
		  Mix_Chunk *son31 = Mix_LoadWAV("sons/re3.wav");
				   Mix_PlayChannel(31,son31,0);
				  if(micTest==0) {
					record=realloc(record,(strlen(record)+3)*sizeof(char)); 					// record
					record[rcpt]='r';
					record[rcpt+1]='e';
					record[rcpt+2]='3';
					rcpt+=3;}
		 }

                 else if((x>=725 && x<=765)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son32 = Mix_LoadWAV("sons/mi3.wav");
				   Mix_PlayChannel(32,son32,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='m';
					record[rcpt+1]='i';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }

                 else if((x>=770 && x<=810)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son33 = Mix_LoadWAV("sons/fa3.wav");
				   Mix_PlayChannel(33,son33,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='a';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }

                 else if((x>=815 && x<=855)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son34 = Mix_LoadWAV("sons/so3.wav");
				   Mix_PlayChannel(34,son34,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='o';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }

                 else if((x>=860 && x<=900)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son35 = Mix_LoadWAV("sons/la3.wav");
				   Mix_PlayChannel(35,son35,0);
				  if(micTest==0) {
					record=realloc(record,(strlen(record)+3)*sizeof(char)); 					// record
					record[rcpt]='l';
					record[rcpt+1]='a';
					record[rcpt+2]='3';
					rcpt+=3;}
                  }

                 else if((x>=905 && x<=945)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son36 = Mix_LoadWAV("sons/si3.wav");
				   Mix_PlayChannel(36,son36,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='i';
					record[rcpt+2]='3';
					rcpt+=3;}
                 }

		 //// 4th gamme ////
		 else if((x>=974 && x<=1000)&&(y>=250 && y<=430)) {
                  Mix_Chunk *son37 = Mix_LoadWAV("sons/db4.wav");
				   Mix_PlayChannel(37,son37,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='b';
					record[rcpt+2]='4';
					rcpt+=3;}
                 }
		 
		 else if((x>=1029 && x<=1055)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son38 = Mix_LoadWAV("sons/rb4.wav");
				   Mix_PlayChannel(38,son38,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='r';
					record[rcpt+1]='b';
					record[rcpt+2]='4';
					rcpt+=3;}
                  }
		
		 else if((x>=1109 && x<=1135)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son39 = Mix_LoadWAV("sons/fb4.wav");
				   Mix_PlayChannel(39,son39,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='b';
					record[rcpt+2]='4';
					rcpt+=3;}
                  }

                 else if((x>=1159 && x<=1185)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son40 = Mix_LoadWAV("sons/sb4.wav");
				   Mix_PlayChannel(40,son40,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='b';
					record[rcpt+2]='4';
					rcpt+=3;}
                  }
                 
		 else if((x>=1209 && x<=1235)&&(y>=250 && y<=430)) {
                   Mix_Chunk *son41 = Mix_LoadWAV("sons/lb4.wav");
				   Mix_PlayChannel(41,son41,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='b';
					record[rcpt+2]='4';
					rcpt+=3;}
                 }

		 else if((x>=950 && x<=990)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son42 = Mix_LoadWAV("sons/do4.wav");
				   Mix_PlayChannel(42,son42,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='d';
					record[rcpt+1]='o';
					record[rcpt+2]='4';
					rcpt+=3;}
                 }
				 
		 else if((x>=995 && x<=1035)&&(y>=250 && y<=550)) {
		  Mix_Chunk *son43 = Mix_LoadWAV("sons/re4.wav");
				   Mix_PlayChannel(43,son43,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='r';
					record[rcpt+1]='e';
					record[rcpt+2]='4';
					rcpt+=3;}
		 }

                 else if((x>=1040 && x<=1080)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son44 = Mix_LoadWAV("sons/mi4.wav");
				   Mix_PlayChannel(44,son44,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='m';
					record[rcpt+1]='i';
					record[rcpt+2]='4';
					rcpt+=3;}
                  }

                 else if((x>=1085 && x<=1125)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son45 = Mix_LoadWAV("sons/fa4.wav");
				   Mix_PlayChannel(45,son45,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='f';
					record[rcpt+1]='a';
					record[rcpt+2]='4';
					rcpt+=3;}
                  }

                 else if((x>=1130 && x<=1170)&&(y>=250 && y<=550)) {
                  Mix_Chunk *son46 = Mix_LoadWAV("sons/so4.wav");
				   Mix_PlayChannel(46,son46,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='s';
					record[rcpt+1]='o';
					record[rcpt+2]='4';
					rcpt+=3;}
				  
                  }

                 else if((x>=1175 && x<=1215)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son47 = Mix_LoadWAV("sons/la4.wav");
				   Mix_PlayChannel(47,son47,0);
				  if(micTest==0) { 
					record=realloc(record,(strlen(record)+3)*sizeof(char));					// record
					record[rcpt]='l';
					record[rcpt+1]='a';
					record[rcpt+2]='4';
					rcpt+=3;}
				  
                  }

                 else if((x>=1220 && x<=1260)&&(y>=250 && y<=550)) {
                   Mix_Chunk *son = Mix_LoadWAV("sons/si4.wav");
				   Mix_PlayChannel(0,son,0);
				  if(micTest==0) { 					// record
					record[rcpt]='s';
					record[rcpt+1]='i';
					record[rcpt+2]='4';
					rcpt+=3;}
				  
                 }


                 break;
             case SDL_KEYDOWN:
                error_img(screen,1);
              
                position.x=30;
                position.y=8;
		        int x,y=0;
                /* typing the path */
                int key=event.key.keysym.unicode; 
				SDL_GetMouseState(&x,&y);
			    if(x>=10 && x<=620 && y>=5 && y<=30){ 
				 if(( key >= (Uint16)'A' ) && ( key <= (Uint16)'Z' ))
                 {
                  inputText = realloc(inputText,2*k+1*sizeof(char));
                  inputText[k]=(char)event.key.keysym.unicode;
                  if(strlen(inputText) > k) inputText[k+1]='\0';
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
                  k++;
                 }
                 else if(( key >= (Uint16)'a' ) && ( key <= (Uint16)'z' ))
                 {
                  inputText = realloc(inputText,2*k+1*sizeof(char));
		  		  inputText[k]=(char)event.key.keysym.unicode;
                  if(strlen(inputText) > k) inputText[k+1]='\0';
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
                  k++;
                 }

                 else if((key==(Uint16)'/')||( key ==(Uint16)'.'))
                 {
                  inputText = realloc(inputText,2*k+1*sizeof(char));
                  inputText[k]=(char)event.key.keysym.unicode;
                  if(strlen(inputText) > k) inputText[k+1]='\0';
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
                  k++;
                 }
                  else if((key==(Uint16)'_')||(key==(Uint16)'-'))
                 {
                  inputText = realloc(inputText,2*k+1*sizeof(char));
                  inputText[k]=(char)event.key.keysym.unicode;
                  if(strlen(inputText) > k) inputText[k+1]='\0';
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
                  k++;
                 }
                 else if((key >= (Uint16)'0')&&(key <= (Uint16)'9'))
                 {
                  inputText = realloc(inputText,2*k+1*sizeof(char));
                  inputText[k]=(char)event.key.keysym.unicode;
                  if(strlen(inputText)>k) inputText[k+1]='\0';
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
                  k++;
                 }
                 else if(event.key.keysym.sym == SDLK_BACKSPACE && k!=0)
                 { 
                  k--;
                  if(k>0)
                  {
                   inputText[k]='\0';
                   inputText = realloc(inputText,k*sizeof(char));
                  }
                  else 
                  {
                   inputText[0]='\0';
                   inputText = realloc(inputText,sizeof(char));
                  } 
                  path_write(screen);
                  text = TTF_RenderText_Blended(police, inputText, white);
                  SDL_BlitSurface(text, NULL, screen, &position);
                  SDL_Flip(screen);
			    }
		 	   }
				else {
				  	  
				  const char *tab[]={"sons/do1.wav","sons/re1.wav","sons/mi1.wav","sons/fa1.wav","sons/so1.wav","sons/la1.wav",
						  "sons/si1.wav","sons/do2.wav","sons/re2.wav","sons/mi2.wav","sons/fa2.wav","sons/so2.wav","sons/la2.wav",
						  "sons/si2.wav","sons/do3.wav","sons/re3.wav","sons/mi3.wav","sons/fa3.wav","sons/so3.wav","sons/la3.wav",
						  "sons/si3.wav","sons/do4.wav","sons/re4.wav","sons/mi4.wav","sons/fa4.wav","sons/so4.wav","sons/la4.wav",
						  "sons/si4.wav","sons/db1.wav","sons/rb1.wav","sons/fb1.wav","sons/sb1.wav","sons/lb1.wav","sons/db2.wav",
						  "sons/rb2.wav","sons/fb2.wav","sons/sb2.wav","sons/lb2.wav","sons/db3.wav","sons/rb3.wav","sons/fb3.wav",
						  "sons/sb3.wav","sons/lb3.wav","sons/db4.wav","sons/rb4.wav","sons/fb4.wav","sons/sb4.wav","sons/lb4.wav"};
				  if(( key >= (Uint16)'a' ) && ( key <= (Uint16)'|' )){
					Mix_Chunk *son = Mix_LoadWAV(tab[key-97]);
					Mix_PlayChannel(key-97,son,0);
				  }
				  if(( key >= (Uint16)'A' ) && ( key <= (Uint16)'U' )){
					Mix_Chunk *son = Mix_LoadWAV(tab[key-37]);
					Mix_PlayChannel(key-37,son,0);
			      }
				  
				}
               break;
             case SDL_QUIT:
                 test_int = 0;
                 break;
             default:
                 break;
		 
     }
  }
}
 Mix_CloseAudio();
 SDL_FreeSurface(screen);
 SDL_Quit();
 TTF_CloseFont(police);
 TTF_Quit(); 
 free(inputText);
 return EXIT_SUCCESS;
}
