#include <stdio.h>

int main() {
	FILE *src, *dest;
	char ch;
	
	src = fopen("w.txt", "r");
	dest = fopen("ww.txt", "w");

	if (src == NULL || dest == NULL) {
		printf("Error");
		return 1;
	}
	
	while ((ch = fgetc(src)) != EOF) {
		printf("%c", ch);
	}
	
	fclose(src);
	fclose(dest);

	return 0;
}
