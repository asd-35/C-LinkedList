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

void makeDiretory(char str[]);

void removeDirectory(char str[]);

void swapDirectory(struct LinkedList swap,char *str1[],char *str2[]);

struct StorageUnit
{

    char *root;
    char *path;
};struct StorageUnit store;

int main()
{
    store.root = "./";
    makeDiretory("desk");
    printf("store : %s\n",store.path);
    makeDiretory("dir");
    printf("store : %s\n",store.path);
    makeDiretory("usr");
    printf("store : %s\n",store.path);
    printf("child desktop: %p\n",head.child);
    printf("child  desktop: %s\n",head.child->dir);
    printf("child dir: %p\n",head.child->child->dir);
    printf("child  dir: %s\n",head.child->child->dir);

    //printf("%s\n",store.path);
    removeDirectory("dir");
    printf("store : %s\n",store.path);
    printf("child desktop: %p\n",head.child);

    //swapDirectory(head,"desk","dir");

    return 0;
}

void add(struct LinkedList *head,char str[]){
    if(head->dir == '\0')
    {
        head->dir = str;

    }else{

    struct LinkedList *node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->dir = str;
    node->child =NULL;

    struct LinkedList *last;
    last = head;

    while (last->child != NULL)
    {

    last = last->child;

    }

    last->child = node;

    }
};

void removes(struct LinkedList *head,char *str[]){

    if(strcmp(head->child->dir,str) == 0){

        head->child = NULL;
    }else{
        removes(head->child,str);
    }
}

void makeDiretory(char str[]){
    if(head.dir == NULL){
    store.path = str;

    add(&head,str);
    }else{
        char *temp = malloc(sizeof(char) * sizeof(store.path));
        char *slash = '/';

        strcpy(temp, store.path);
        strncat(temp, &slash, 1);
        strcat(temp,str);

        store.path = temp;
        add(&head,str);
    }

};

void removeDirectory(char str[]){
    if(store.path == '\0') printf("nothing to  remove");

    removes(&head,str);


    char *temp = strstr(store.path,str);

    int pos = temp - store.path - 1;

    for(int i = pos; i < strlen(store.path); i++){
        if(store.path[i] != '\0') store.path[i] = '\0';
    }
}

void swapDirectory(struct LinkedList swap,char *str1[],char *str2[])
{
    if(swap.child == NULL)
    {
        printf("ends here\n");

    }else
    {
        printf("%s\n",swap.dir);
        swapDirectory(*swap.child,str1,str2);
    }


}

