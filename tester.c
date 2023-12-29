#include "unif01.h"
#include "bbattery.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int FileBitRandom() {
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;

	byte1 = getchar();
	byte2 = getchar();
	byte3 = getchar();
	byte4 = getchar();

	return (unsigned int) (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
}

void PrintUsage(char *argv) {
	printf("Usage: %s <test>\n                        <test>: SmallCrush, Crush, BigCrush", argv);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		PrintUsage(argv[0]);
		return 1;
	}

	unif01_Gen *gen;

	gen = unif01_CreateExternGenBits("FileBitRandom", FileBitRandom);

	if (strcmp(argv[1], "SmallCrush") == 0) {
		bbattery_SmallCrush(gen);
	} else if (strcmp(argv[1], "Crush") == 0) {
		bbattery_Crush(gen);
	} else if (strcmp(argv[1], "BigCrush") == 0) {
		bbattery_BigCrush(gen);
	} else {
		printf("Unknown test received: %s\n\n", argv[1]);
		PrintUsage(argv[0]);
		return 1;
	}

	unif01_DeleteExternGenBits(gen);

	return 0;
}
