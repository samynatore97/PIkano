# ifndef LIST_H_
# define LIST_H_
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include "coord.h"
struct list {
struct list *next;
int  data;
};
struct list_coord{
struct list_coord *next;
struct coord *coord;
};
void list_init(struct list * list);
int list_is_empty(struct list * list);
size_t list_len(struct list * list);
void list_push_front (struct list *list , struct list *elm);
struct list* list_pop_front(struct list *list);
struct list * list_find(struct list *list, int value);
int list_is_sorted(struct list *list);
void list_insert(struct list * list, struct list *elm);

#endif
