/*
 ============================================================================
 Name        : Eratosthenes.c
 Author      : Yukihiro Saito
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000
#define TRUE 1
#define FALSE 0

void eratosthenes();
char judge_eratosthenes(unsigned int judge_num);
unsigned int rsa_eratosthenes(unsigned int rsa_num);

int main(int argc, char *argv[]) {
	if (argc == 1)
		eratosthenes();
	else if (judge_eratosthenes(atoi(argv[1])))
		printf("true");

	return EXIT_SUCCESS;
}

void eratosthenes(void) {
	unsigned int i, j;
	char num[MAX] = { };
	unsigned int sqrt_num = (int) ceil(sqrt((double) MAX));
	num[1] = 1;
	for (i = 2; i < sqrt_num; i++) {
		if (!num[i]) {
			for (j = 2; i * j < MAX; j++)
				num[i * j] = 1;
		}
	}
	for (i = 1; i < MAX; i++) {
		if (!num[i])
			printf("%d \n", i);
	}

	return;
}

char judge_eratosthenes(unsigned int judge_num) {
	unsigned int i, j;
	char num[MAX] = { };
	unsigned int sqrt_num = (int) ceil(sqrt((double) judge_num));

	for (i = 2; i <= sqrt_num; i++) {
		if (!num[i]) {
			for (j = 2; i * j <= judge_num; j++)
				num[i * j] = 1;
		}
	}

	if (!num[judge_num]) {
		if (judge_num == 1)
			return FALSE;
		return TRUE;
	} else {
		return FALSE;
	}
}

