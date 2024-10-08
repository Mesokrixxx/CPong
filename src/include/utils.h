# ifndef PONG_UTIL_H
# define PONG_UTIL_H

# define TRUE 1
# define FALSE 0

// Specialish
char* readFile(char* path);

// Base
char* strCat(char* str1, char* str2);
int strLen(char* str);
int strCmp(char* str1, char* str2);

# endif