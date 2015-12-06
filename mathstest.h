/*Maths test header. */
#ifndef _MATHSTEST_H_
#define _MATHSTEST_H_
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


/* Defined in mtestcsv.c. */
int writeScores(char *fname, struct scores **class, int n);
void getFname(char *fname);
void display(struct scores *st);
void ex_err(char *s);
struct scores *getclass(int *n, char *fname);
int getfields(FILE *ptr, char fields[F][L]);

/* Struct comparison functions from mtestsort.c. */
int stringcmp(const void *s, const void *t);
int intcmp(const void *a, const void *b);
int floatcmp(const void *a, const void *b);

/* Functions from mathstest.c */
struct scores *findName(struct scores *class, int n, char *name);
int test(void);
void update(struct scores *student, int score);
void toTitle(char *name, int n);

#endif
