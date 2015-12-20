/*
 * mtestcsv header.
 * Contains struct scores definition.
 */

#ifndef _MTESTCSV_H_
#define _MTESTCSV_H_
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))

#define F 6
#define L 21

#define MNAME 20

/* The scores struct. */
struct scores {
	char name[MNAME];
	int scores[3];
	float av;
	int top;
};


int writeScores(char *fname, struct scores **class, int n);
void getFname(char *fname);
void display(struct scores *st);
void ex_err(char *s);
struct scores *getclass(int *n, char *fname);


#endif
