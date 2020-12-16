/* 
 * Programmer : Nathan A. Mourey II <nmoureyii@gmail.com>
 * Program    : Multiplication questions.
 * Date       : November 14th 2011-2020
 * Copyright  : GLPv3
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int high = 0;
	int correct = 0;
	int guess = 0;
	int i,j = 0;
	int passes = 0;
	int num_questions = 0;
	char data[8];

	printf("Enter highest number to multiply by : ");
	fgets(data, sizeof(data), stdin);
	high = atoi(data);

	if (high == 0) high = 1;

	printf("Enter number of questions : ");
	fgets(data, sizeof(data), stdin);
	passes = atoi(data);

	if (passes == 0) passes = 1;

	/* seed random number generator with the current time. */
	srand(time(NULL));

	printf("\nEnter '0' (Zero) to skip a problem and get the answer.\n\n");
	do {
		/* Never muliply by 0 -- too easy. */
		i = rand() % high + 1;
		j = rand() % high + 1;

		/* print question */
		printf("%i X %i = ", i, j);
		fgets(data, sizeof(data), stdin);
		guess = atoi(data);
		if (guess == 0) guess = 0;

		/* Get answer and check */
		if (guess != 0){
			if (guess == i*j){
				printf("Correct! Good Job!\n");
				correct++;
			} else {
				printf("Sorry Wrong!\n");
				printf("The Correct Answer is : %i X %i = %i\n", i, j, i*j);
			}
		} else {
			printf("Answer: %i X %i = %i\n", i, j, i*j);
		}
		num_questions++;
	} while (num_questions < passes);
	printf("\n\t%i out of %i quesetions answered correctly.\n\n", correct, passes);
	exit(0);
}
