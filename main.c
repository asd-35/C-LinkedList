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

struct StorageUnit
{

    char *root;
    char *path;
};struct StorageUnit store;

int main()
{
    store.root = "./";
    makeDiretory("desk");
    printf("%s\n",store.path);
    makeDiretory("dir");
    makeDiretory("usr");
    printf("%s\n",store.path);
    removeDirectory("dir");
    printf("%s\n",store.path);
    return 0;
}

void add(struct LinkedList *head,char str[]){
    if(head->dir )
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

void makeDiretory(char str[]){
    if(store.path == '\0'){
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

