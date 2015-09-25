#include <stdio.h>
#include <stdlib.h>

void DbMockRead(float keyToRead, int post) {
	
	char* refnum;
	char* name;
	char* age;
	char* sex;
	int cstate;
	
	int key = (int) keyToRead;

	if (post == 1) {
		FILE * fp;
		fp = fopen ("file.txt", "r");
	

		int i;
		for (i = 0; i < key; ++i) {
			fscanf(fp, "%d %s %s %s %s %d\n",
			       refnum, name, age,
			       sex, cstate );
		}
		
		fscanf(fp, "%d %s %s %s %s %d\n",
			       refnum, name, age,
			       sex, &cstate);
	

		fclose (fp);
	}
}