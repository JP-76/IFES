#pragma once
#pragma comment(lib,"pthreadVC2.lib")

#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define HAVE_STRUCT_TIMESPEC

#define MATRIX_WIDTH 15000
#define MATRIX_HEIGHT 15000
#define NUM_THREADS 8
#define BLOCK_WIDTH 15000
#define BLOCK_HEIGHT 15000

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

pthread_mutex_t mutex;
pthread_mutex_t primesBufferMutex;

int primesBuffer = 0;
int** matrix;
int nextBlock = 0;
int maxBlocksPerRow = MATRIX_WIDTH / BLOCK_WIDTH;
int maxBlocksPerColumn = MATRIX_HEIGHT / BLOCK_HEIGHT;

int** createMatrix(int width, int height) {
	int** matrix = (int**)malloc(height * sizeof(int*));
	if (matrix == NULL) return NULL;
	int i;
	for (i = 0; i < height; i++) {
		matrix[i] = (int*)malloc(width * sizeof(int));
		if (matrix[i] == NULL) return NULL;
	}
	for (i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = rand() % 32000;
		}
	}
	return matrix;
}

void freeMatrix() {
	for (int i = 0; i < MATRIX_HEIGHT; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int ehPrimo(int n) {
	if (n <= 1 || (n % 2 == 0 && n > 2)) return 0;
	double nRoot = sqrt(n);
	for (int i = 3; i <= nRoot; i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int matrixPrimeCounter(int height, int width, int vStart, int hStart) {
	int buffer = 0;
	for (int k = 0; k < height; k++) {
		for (int l = 0; l < width; l++) {
			buffer += ehPrimo(matrix[k + hStart][l + vStart]);
		}
	}
	return buffer;
}

void serialPrimeCounter() {
	primesBuffer = matrixPrimeCounter(MATRIX_HEIGHT, MATRIX_WIDTH, 0, 0);
}

void threadMatrixPrimeCounter(int currentBlock) {
	int vStart = BLOCK_WIDTH * (currentBlock % maxBlocksPerRow); // Wrap row
	int hStart = BLOCK_HEIGHT * (currentBlock / maxBlocksPerRow); // Wrap column
	int primes = matrixPrimeCounter(BLOCK_HEIGHT, BLOCK_WIDTH, vStart, hStart);

	pthread_mutex_lock(&primesBufferMutex);
	primesBuffer += primes;
	pthread_mutex_unlock(&primesBufferMutex);
}

void threadFunc(int num) {
	while (1) {
		int currentBlock;
		pthread_mutex_lock(&mutex);
		currentBlock = nextBlock++;
		pthread_mutex_unlock(&mutex);
		if (currentBlock >= maxBlocksPerRow * maxBlocksPerColumn) {
			break;
		};
		threadMatrixPrimeCounter(currentBlock);
	}
	pthread_exit(0);
}

void parallelPrimeCounter() {
	pthread_t workers[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&workers[i], NULL, threadFunc, i);
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(workers[i], NULL);
	}
}

int main(int argc, char* argv[]) {
	double serialTime;
	double parallelTime;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&primesBufferMutex, NULL);
	pthread_t thread;
	printf("============================= TRABALHO DE SISTEMAS OPERACIONAIS =============================\n");
	printf("\t\t> Comparacao entre um programa serial e um programa paralelo.\n");

	matrix = createMatrix(MATRIX_WIDTH, MATRIX_HEIGHT);

	clock_t begin = clock();
	serialPrimeCounter();
	clock_t end = clock();
	serialTime = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\t\t> Serial:\t%d prime numbers, took %lf seconds\n", primesBuffer, serialTime);

	primesBuffer = 0;

	begin = clock();
	parallelPrimeCounter();
	end = clock();

	pthread_mutex_destroy(&mutex);
	pthread_mutex_destroy(&primesBufferMutex);

	parallelTime = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\t\t> Parallel:\t%d prime numbers, took %lf seconds\n", primesBuffer, parallelTime);

	freeMatrix();

	printf("\t\t> Speedup: \t%lf\n", serialTime / parallelTime);
	printf("\t\tv Trabalho feito por:\n");
	printf("\t\t   > Jhonata Polito Demuner\n");
	printf("\t\t   > Joao Pedro Spinasse Viana\n");
	printf("=============================================================================================\n");

	printf("\n");
	return 0;
}