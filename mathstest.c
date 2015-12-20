#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <ctype.h>
#include "mtestcsv.h"

/*Maths test program similar to A453 GCSE assessment. */

struct scores *findName(struct scores *class, int n, char *name);
int test(void);
void update(struct scores *student, int score);
void toTitle(char *name, int n);

int main(void)
{
	char name[20], c, fname[12];
        int s, n = 0, i;
        struct scores *mySet, *student;  
        mySet = student = NULL;

	/* Seed the rn. */
	srand(time(NULL));

	printf("*** Maths test ***\n\n");
       
        /* Get the class number. */ 
        getFname(fname);

        /* Import data from file. */
        mySet = getclass(&n, fname);

	printf("Please enter your name: ");
	if (scanf("%19s", name) != 1) {
		printf("Unexpected input. Aborting.\n");
		while ((c = getchar()) != '\n' && c != EOF) {
		}
		exit(1);
	}

        i = strlen(name);
        toTitle(name, i);
        student = findName(mySet, n, name); 
        if (student == NULL){
            ex_err("Name not found.\n");
        }

	printf("Hello %s!\n", name);

	s = test();
	printf("Well done, you scored: %d.\n", s);
	update(student, s);
	display(student);
        writeScores(fname, &mySet, n);
        free(mySet);
	return 0;
}

void update(struct scores *student, int score)
{
	student->scores[0] = student->scores[1];
	student->scores[1] = student->scores[2];
	student->scores[2] = score;
	student->top =
	    MAX(MAX(student->scores[0], student->scores[1]),
		student->scores[2]);
	student->av =
	    (student->scores[0] + student->scores[1] +
	     student->scores[2]) / 3.0;
}


int test(void)
{
	char *ops = "+-x/";
	int sc = 0, op, c, i, x, y, ans, t1, t2, user;

	for (i = 0; i < 5; i++) {

		/* Get a random operator */
		op = rand() % 4;

		/* Use numbers between 2 and 10. */
		x = rand() % 8 + 2;
		y = rand() % 8 + 2;

		/* Set up x, y and ans ready to test user. */
		switch (op) {
		case 0:
			ans = x + y;
			break;
		case 1:
			/* Put largest value first for subtraction. */
			t1 = MAX(x, y);
			t2 = MIN(x, y);
			x = t1;
			y = t2;
			ans = x - y;
			break;
		case 2:
			ans = x * y;
			break;
		case 3:
			/* Only ask integer division questions. */
			t1 = x * y;
			ans = x;
			x = t1;
			break;
		}

		printf("What is %d %c %d ? ", x, *(ops + op), y);

		if (scanf("%d", &user) != 1) {
			while ((c = getchar()) != '\n' && c != EOF) {
			}
			printf("Please enter an integer.\n");
			continue;
		}
		if (user == ans) {
			printf("Correct.\n");
			sc += 1;
		} else {
			printf("Sorry, correct answer is %d.\n", ans);
		}
	}

	return sc;
}

void toTitle(char *name, int n)
{
	int i;
	name[0] = toupper(name[0]);
	for (i = 1; i < n; i++)
		name[i] = tolower(name[i]);
}

struct scores *findName(struct scores *class, int n, char *name)
{
    int i;
    for (i = 0; i<n; i++){
        if (!strcmp(class[i].name, name)){
            return &class[i];
        }
    }
    return NULL;
}
