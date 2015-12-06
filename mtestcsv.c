#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include "mathstest.h"

/* Read data in from a .csv file. */

int getfields(FILE *ptr, char fields[F][L])
{
    char *p, *q, *buf; 
    buf = p = q = NULL;
    int k, i;
    size_t m = 0;
  
    /* Make sure fields are empty. */ 
    for(k = 0; k < F; k++)
        fields[k][0] = '\0';

    /* Make sure i is zero in case getline fails. */
    i = 0;
    /* Get a line and split it on commas. */
    if ((k = getline(&buf, &m, ptr)) != -1){
        for (q = buf; i < F && (p = strtok(q, ",\n\r")); q = NULL)
            strcat(fields[i++], p);
    }  
    free(buf);
    return i;
}

struct scores *getclass(int *n, char *fname)
{
    char fields[F][L];
    int i = 0, j;
    size_t size = 1;
    struct scores *class = malloc(sizeof(struct scores));
    FILE *f;
    

    f = fopen(fname, "r");
    if (f == NULL)
        ex_err("Could not open file.\n");
            
    /* Read each line of the file and populate struct array. */
    while(getfields(f, fields)){      
        /* Resize array if full. */
        if (size == i){
            size *= 2;
            class = realloc(class, sizeof(class[0]) * size);
            assert(class != NULL);
        }
        strcpy(class[i].name, fields[0]);
        
        for (j = 0; j < 3; j++)
            class[i].scores[j] = atoi(fields[j+1]); 
        class[i].av = atof(fields[4]);
        class[i++].top = atoi(fields[5]);
    } 
    *n = i;
    fclose(f);
    return class;
}


void display(struct scores *st)
{
	printf("%-20s ", st->name);
	printf("%3d %3d %3d ", st->scores[0], st->scores[1],
	       st->scores[2]);
	printf("%3d", st->top);
	printf("%6.2f.\n", st->av);
}

void ex_err(char *s)
{
    printf("%s", s);
    exit (1);
}

/* Takes file name, pointer to struct array, and number of entries. */
int writeScores(char *fname, struct scores **class, int n)
{
    FILE *f;
    int i, w = 0;

    f = fopen(fname, "w");
    for (i = 0; i < n; i++){
        w += fprintf(f, "%s,%d,%d,%d,%.2f,%d\n",
                (*class)[i].name,
                (*class)[i].scores[0],
                (*class)[i].scores[1],
                (*class)[i].scores[2],
                (*class)[i].av,
                (*class)[i].top);
                   
    }
    fclose(f);
    return w;
} 


void getFname(char *fname)
{
   char *base = "class%c.txt", c, d;
   
   while(1){
       printf("Class (1-3): ");
       if ((c = getchar()) > '0' && c < '4' && (d = getchar()) == '\n')
           break;
       while((d = getchar() != '\n'))
           ;
       printf("Please try again.\n");
   }
   sprintf(fname, base, c);
}
