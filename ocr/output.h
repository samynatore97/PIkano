# ifndef OUTPUT_H_
# define OUTPUT_H_
# include <stdlib.h> 
# include <stdio.h>
# include "coord.h"
# include "list.h"
# include <string.h>
# include <err.h>
void create_file_note(struct list * list_coord,char * name);
struct list * genListFromFile(char * path);

#endif
