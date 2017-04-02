# include "list.h"
# include <stdio.h>
# include<stdlib.h>
# include <stddef.h>
void list_init(struct list *list)
{
   list->next = NULL;
   list->data = -1;
}

int list_is_empty(struct list *list)
{
  return list->next == NULL;
}

size_t list_len(struct list *list)
{
  size_t len = 0;
  while(list) {
    list = list->next;
    len+=1;

    }
  return len>0? len-1 : 0;
}

void list_push_front(struct list *list, struct list *elm){
elm->next = list->next;
list->next = elm;
}

struct list* list_pop_front(struct list  *list){
  if (list_is_empty(list))
     return NULL;
  struct list *res = list->next;
  list->next = list->next->next;
  return res;
}

struct list* list_find(struct list *list,void * value){
  while(list){
  if (list->data == value){
     return list;
    }
  list = list->next;
  }
  return list;
}

int list_is_sorted(struct list *list){
int test = 1;
 while(list->next && test) {
    if (list->data  >  list->next->data){
        test = 0;
        }
    list= list->next;
    }
  return test;
}

void list_insert(struct list *list, struct list *elm){
int test = 1;
  while(list->next && test){
    if(list->next->data > elm->data){
       list_push_front(list,elm);
       test=0;
       }
    else{
     list = list->next;
     }
     }
     if (test){
     elm-> next =NULL;
     list->next = elm;
     
    }
}
