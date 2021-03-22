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

void swapDirectory(struct LinkedList *swap,char *str1[],char *str2[]);

struct StorageUnit
{

    char *root;
    char *path;
};struct StorageUnit store;

int main()
{
    printf("initializng our dirs\n");
    store.root = "./";
    makeDiretory("desktop");
    printf("store : %s%s\n",store.root,store.path);
    makeDiretory("bin");
    printf("store : %s%s\n",store.root,store.path);
    makeDiretory("usr");
    printf("store : %s%s\n",store.root,store.path);
    printf("every dir is also on the linkedlist\n");
    printf("child desktop: %p\n",head.child);
    printf("child  desktop: %s\n",head.child->dir);
    printf("child bin: %p\n",head.child->child->dir);
    printf("child  bin: %s\n",head.child->child->dir);
    printf("lets swap some of them\n");
    swapDirectory(&head,"desktop","bin");
    printf("child bin: %p\n",head.child);
    printf("child  bin: %s\n",head.child->dir);
    printf("store : %s%s\n",store.root,store.path);
    printf("lets remove desktop\n");
    removeDirectory("desktop");
    printf("store : %s%s\n",store.root,store.path);
    printf("child bin: %p\n",head.child);


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
    if(strcmp(head->dir,str) == 0) head = NULL;

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

void swapDirectory(struct LinkedList *swap,char *str1[],char *str2[])
{
    struct LinkedList *temp = swap;
    char *tempPath;
    tempPath = malloc(sizeof(store.path));
    store.path = NULL;
    while(temp->child != NULL)
    {

        if(strcmp(swap->dir,str1) == 0){

            temp->dir = NULL;
            temp->dir = malloc(sizeof(str2));
            strcpy(temp->dir,str2);
            printf("after copy bin: %s\n",temp->dir);
            char *str = malloc(sizeof(str2));
            char *slash = '/';

            strcpy(str, temp->dir);
            strncat(str, &slash, 1);
            strcat(tempPath,str);
            str = NULL;

            temp = temp->child;

        }else if(strcmp(swap->dir,str2) == 0){

            temp->dir = NULL;
            temp->dir = malloc(sizeof(str1));
            strcpy(temp->dir,str1);
            printf("after copy desk: %s\n",temp->dir);
            char *str = malloc(sizeof(str1));
            char *slash = '/';

            strcpy(str, temp->dir);
            strncat(str, &slash, 1);
            strcat(tempPath,str);
            str = NULL;

            temp = temp->child;

        }else{

        char *str = malloc(sizeof(*temp->dir));
        char *slash = '/';

        strcpy(str, temp->dir);
        strncat(str, &slash, 1);
        strcat(tempPath,str);
        str = NULL;

        temp = temp->child;
        }
    }
    store.path = malloc(sizeof(tempPath));
    store.path = tempPath;

}


