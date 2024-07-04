#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rowCount(char *filename){
    FILE *file = fopen(filename,"r");

    char *lineptr = NULL;
    size_t n;

    int lines = 0;

    while (getline(&lineptr,&n,file) != -1) //sszie_t return functions like get always return -1 on failiure or some other negative values
    {
        lines++;
    }

    free(lineptr);
    fclose(file);
    
    return lines;
}

int fieldCount(char *filename){
    FILE *file = fopen(filename,"r");
    char *lineptr = NULL;
    size_t n;

    getline(&lineptr,&n,file);
    fclose(file);
    
    char *field = strtok(lineptr,",");
    int fieldCount = 1;

    while (field != NULL)
    {
        field = strtok(NULL,",");

        if (field == NULL) break;
        fieldCount++;
    }
    
    free(lineptr);
    return fieldCount;
}

int main(int argc,char *argv[]){
    //printf("%s",argv[1]);
    int rcount = rowCount(argv[1]);
    int fcount = fieldCount(argv[1]);
    printf("rows:%i fields:%i\n",rcount,fcount);
    return 0;
}