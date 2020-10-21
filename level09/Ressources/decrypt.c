#include <stdio.h>

int main(int argc, char **argv) {
	if (argv[1]) {
		int i = 0;
		while (argv[1][i]) {
			printf("%c", argv[1][i] - i);
			i++;
		}
	} else {
		printf("No text provided");
	}
	return (0);
}
