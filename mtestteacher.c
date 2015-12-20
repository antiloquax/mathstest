#include <stdlib.h>
#include <stdio.h>
#include "mtestcsv.h"
#include "mtestsort.h"

/* This will be the teacher's interface. */

int main(void)
{
    char fname[12], c, d;
    int i, n = 0;
    struct scores *mySet;

    printf("\n*** Maths Test - Teacher's Version ***\n\n");

    /* Get the class name. */
    getFname(fname);

    /* Read in the data. */
    mySet = getclass(&n, fname);

    /* Make array of struct scores pointers. */
    struct scores **parray = (struct scores **)malloc(sizeof(struct scores*) * (size_t)n);
    for(i = 0; i < n; i++)
        parray[i] = &mySet[i];

    while(1)
    {
        while (1)
        {
            printf("\nChoose which sort:\n1: Name\n2: Average\n3: Highest\n");
            printf("Or q to quit.\n:");
            while (1){
                if ((c = getchar()) == 'q'){
                    free(mySet);
                    free(parray);
                    return 0;
                }
                if (c > '0' && c < '4' && (d = getchar()) == '\n')
                    break;
                while((d = getchar() != '\n'))
                    ;
                printf("Please try again.\n");
            }

            switch (c)
            {
                case '1':
                    qsort(parray, (size_t)n, sizeof(struct scores*), stringcmp);
                    break;
                case '2':
                    qsort(parray, (size_t)n, sizeof(struct scores*), floatcmp);
                    break;
                case '3':
                    qsort(parray, (size_t)n, sizeof(struct scores*), intcmp);
                    break;
                default:
                    ex_err("Oops.\n");
            }
            printf("\n");
            for(i = 0; i < n; i++)
                display(parray[i]);
        }
    }
}
