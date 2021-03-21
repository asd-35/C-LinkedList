#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList
{
    struct LinkedList *child;
    char *dir;

};struct LinkedList head;

void add(struct LinkedList *head,char str[]);

void removes(struct LinkedList *head,char *str[]);

void makeDiretory();

void removeDirectory();

struct StorageUnit
{
    char *root;
    char *path;
};struct StorageUnit store;

int main()
{
    add(&head,"hello");
    printf("%s\n",head.dir);
    add(&head,"yoo");
    printf("%s\n",head.child->dir);
    add(&head,"hel");
    printf("%s\n",head.child->child->dir);
    removes(&head,"yoo");

    return 0;
}

void add(struct LinkedList *head,char str[]){
    if(head->dir == '\0')
    {
        head->dir = str;
    }

    struct LinkedList node;
    node.dir = str;

    struct LinkedList *last;
    last = head;

    while (last->child != NULL){last = last->child;}

    last->child = &node;

};

void removes(struct LinkedList *head,char *str[]){

    if(strcmp(head->child->dir,str)){
        head->child = NULL;
    }else{
        removes(head->child,str);
    }
}


