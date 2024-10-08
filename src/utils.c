# include "include/utils.h"
# include <stdlib.h>
# include <stdio.h>

// Specialish
char* readFile(char* path)
{
	FILE* file;
	unsigned int fileSize;

	file = fopen(path, "r");
	if (!file)
	{
		printf("Failed to open %s\n", path);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	fileSize = ftell(file);
	rewind(file);

	char* out = calloc(fileSize + 1, sizeof(char));
	if (out == NULL)
	{
		printf("Failed to allocate for the readFile(%s)\n", path);
		fclose(file);
		return NULL;
	}

	if (fread(out, fileSize, 1, file) != 1)
	{
		printf("Failed to read %s\n", path);
		free(out);
		fclose(file);
		return NULL;
	}

	fclose(file);
	return out;
}

// Base
char* strCat(char* str1, char* str2)
{
	int lenStr1 = strLen(str1);
	int lenStr2 = strLen(str2);

	char* out = calloc(lenStr1 + lenStr2 + 1, sizeof(char));
	if (!out)
	{
		printf("Failed to allocate: strCat for %s and %s\n", str1, str2);
		return NULL;
	}

	int i = 0;
	int j = 0;
	while (i < lenStr1)
	{
		out[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < lenStr2)
	{
		out[j] = str2[i];
		i++;
		j++;
	}
	out[j] = '\0';

	return out;
}

int strLen(char* str)
{
	int out = 0;
	while (str[out])
		out++;

	return out;
}

int strCmp(char* str1, char* str2)
{
	int i = -1;
	
	while (++i, str1[i] || str2[i])
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (str1[i] - str2[i]);
}