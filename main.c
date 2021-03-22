#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList //struct
{
    struct LinkedList *child;
    char *dir;

};struct LinkedList head;//creating the base linkedlist object

//decleration of functions
void add(struct LinkedList *head,char str[]);

void removes(struct LinkedList *head,char *str[]);

void makeDiretory(char str[]);

void removeDirectory(char str[]);

void swapDirectory(struct LinkedList *swap,char *str1[],char *str2[]);
//decleration of storageUnit
struct StorageUnit
{

    char *root;
    char *path;
};struct StorageUnit store; //creating the main storage called store

int main() //main function that includes some cases
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
    printf("child of desktop: %p\n",head.child);
    printf("child of desktop: %s\n",head.child->dir);
    printf("child of bin: %p\n",head.child->child->dir);
    printf("child of bin: %s\n",head.child->child->dir);
    printf("lets swap desktop and bin \n");
    swapDirectory(&head,"desktop","bin");
    printf("child of bin: %p\n",head.child);
    printf("child of bin: %s\n",head.child->dir);
    printf("store : %s%s\n",store.root,store.path);
    printf("lets remove desktop\n");
    removeDirectory("desktop");
    printf("store : %s%s\n",store.root,store.path);
    printf("child of bin: %p\n",head.child);


    return 0;
}

void add(struct LinkedList *head,char str[]){
    if(head->dir == '\0') //if the first element is null
    {
        head->dir = str;

    }else{
    //creating the node that will be created
    struct LinkedList *node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->dir = str;
    node->child =NULL;

    struct LinkedList *last; //creating a pointer to manuplate the first element of linked list
    last = head;

    while (last->child != NULL) //until the child is null it keeps going
    {

    last = last->child;

    }

    last->child = node; // adds the node to the end of the list

    }
};

void removes(struct LinkedList *head,char *str[]){
    if(strcmp(head->dir,str) == 0) head = NULL; //if we want to delete the first and only element

    if(strcmp(head->child->dir,str) == 0){
        //where deletion of the object happens
        head->child = NULL;
    }else{
        removes(head->child,str); //if node does not contain what we are looking for it calls the func for child of the node given
    }
}

void makeDiretory(char str[]){
    if(head.dir == NULL){ //for assigning the first node
    store.path = str; // store it on the path

    add(&head,str); //where it gets added to the list this func acts everywhere the same
    }else{ //this is for other elements on the lists
        char *temp = malloc(sizeof(char) * sizeof(store.path));
        char *slash = '/';

        strcpy(temp, store.path);
        strncat(temp, &slash, 1);
        strcat(temp,str);
        //added slash for better visual
        store.path = temp; //added to the path
        add(&head,str);
    }

};

void removeDirectory(char str[]){ //removes a dir from list and path
    if(store.path == '\0') printf("nothing to  remove"); // if the given var is null

    removes(&head,str); // removes from the list

    //finding the position of the substring
    char *temp = strstr(store.path,str);

    int pos = temp - store.path - 1;
    //filling it with empty chars
    for(int i = pos; i < strlen(store.path); i++){
        if(store.path[i] != '\0') store.path[i] = '\0';
    }
}

void swapDirectory(struct LinkedList *swap,char *str1[],char *str2[])
{
    struct LinkedList *temp = swap;//this for traversing and manuplating data
    char *tempPath; //we will rewrite the swapped path here
    tempPath = malloc(sizeof(store.path));
    store.path = NULL;
    while(temp != NULL) //until every dir is traversed
    {

        if(strcmp(temp->dir,str1) == 0){ //if we found one of the given string we replaced it other string given

            temp->dir = NULL;
            temp->dir = malloc(sizeof(str2));
            strcpy(temp->dir,str2); // this is where we change the value of the node

            char *str = malloc(sizeof(str2));
            char *slash = '/';

            strcpy(str, temp->dir);
            strncat(str, &slash, 1);
            strcat(tempPath,str); // this is where it is written to the temporary path
            str = NULL;

            temp = temp->child; //for traversing

        }else if(strcmp(temp->dir,str2) == 0){ //same with the last if block

            temp->dir = NULL;
            temp->dir = malloc(sizeof(str1));
            strcpy(temp->dir,str1);

            char *str = malloc(sizeof(str1));
            char *slash = '/';

            strcpy(str, temp->dir);
            strncat(str, &slash, 1);
            strcat(tempPath,str);
            str = NULL;

            temp = temp->child;

        }else{//if the node contains none of the strings given

        char *str = malloc(sizeof(temp->dir));
        char *slash = '/';

        strcpy(str, temp->dir);
        strncat(str, &slash, 1);
        strcat(tempPath,str); //added to the temprorary path
        str = NULL;

        temp = temp->child;

        }
    }
    store.path = malloc(sizeof(tempPath)); //we reallocate the size of the original path with the temporary one
    store.path = tempPath; //we assing swapped temprorary one with the original one

}


