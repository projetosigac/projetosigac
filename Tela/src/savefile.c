#include <stdio.h>
#include <stdlib.h>

int save_file()
{

	char str1[10], str2[10], str3[10];
	int year;
	FILE * fp;

	fp = fopen ("test.txt", "w+");
	fputs("We are in 2015", fp);

	rewind(fp);
	fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

	fclose(fp);

	return year;
}



