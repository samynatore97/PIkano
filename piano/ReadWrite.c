#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadWrite.h"
#include <unistd.h>
#include <err.h>
#include <fcntl.h>

char* readToStr(char* fname){
  int fd;
  if((fd=open(fname,O_RDONLY))==-1) {
	return NULL;
  }

  char buf[8];
  int r,cpt;
  char* res=malloc(sizeof(char));
  while((r=read(STDIN_FILENO,buf,8)) !=0) {
	res=realloc(res,8*sizeof(char));
	if(r == -1)
		return "\0";
	for(int i=cpt;i<cpt+strlen(buf);i++){
	  res[i]=buf[i-cpt];
	}
  }
  close(fd);
  return res;
}
