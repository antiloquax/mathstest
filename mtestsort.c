#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mtestcsv.h>



/* Little reminder how to call qsort.
size_t s;
s = (size_t) sizeof(arr) / sizeof(struct scores *);
qsort(arr, s, sizeof(struct scores *), stringcmp);
qsort(arr, s, sizeof(struct scores *), intcmp);
qsort(arr, s, sizeof(struct scores *), floatcmp);
*/

/* Strings. */    
int stringcmp(const void *s, const void *t)
{
    return strcmp((*(struct scores **)s)->name,
            (*(struct scores **)t)->name);
}


/* Ints, highest first. */
int intcmp(const void *a, const void *b)
{
    return (*(struct scores**)b)->top - 
        (*(struct scores **)a)->top; 
}


/* Floats, highest first. */
int floatcmp(const void *f, const void *g)
{
    float y = (*(struct scores **)f)->av;
    float x = (*(struct scores **)g)->av;

    if(x == y)
        return 0;
    return (x > y) ? 1 : -1;
}


