// Lab 6_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define FILE(path, file, mode)\
FILE* file;\
file = fopen (path, mode);\
	if (!file) {\
		printf("Error");\
		return -1;\
	}

int main()
{
	char buffer[512];
	char txt[] = "D:\\source\\repos\\Lab6\\Lab 6_2\\lab6_2.txt";
	char new_txt[] = "D:\\source\\repos\\Lab6\\Lab 6_2\\new.txt";
	char *c;
	FILE(txt, fp, "r");
	FILE(new_txt, fp1, "w");
	while (!feof(fp)) {
		c = fgets(buffer, sizeof(buffer), fp);
		if (c == NULL){
			if (feof(fp) != 0){
				printf("Read ends\n");
				break;
			}
			else{
				printf("Error\n");
				break;
			}
		}
		for (int i = 0; i < strlen(buffer); i++) {
			if (islower(buffer[i]))
				buffer[i] = toupper(buffer[i]);
			else
				buffer[i] = tolower(buffer[i]);
		}
		fprintf(fp1, "%s", buffer);
	}
	fclose(fp);
	fclose(fp1);
	system("pause");
    return 0;
}