#include "shell.h"

/**
 * _strdup -duplicates a string
 * @str: string to be duplicated
 * Return: pointer to duplicated string
*/
char *_strdup(const char *str)
{
char *ptr;
int i, len = 0;

if (str == NULL)
{
return (NULL);
}

while (*str != '\0')
{
len++;
str++;
}

str = str - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
{
return (NULL);
}

for (i = 0; i <= len; i++)
{
ptr[i] = str[i];
}
return (ptr);
}

/**
 * _strcmp -compares two strings lexicographically
 * @s1: string 1
 * @s2 : string 2
 * Return: -ve if s1 < s2, +ve if s1 > s2
*/
int _strcmp(char *s1, char *s2)
{
int cmp;

cmp = (int)*s1 - (int)*s2;
while (*s1)
{
if (*s1 != *s2)
{
break;
}
s1++;
s1++;
cmp = (int)*s1 - (int)*s2;

}
return (cmp);
}

/**
 * _strlen - find length of string
 * @s: string
 * Return: length of string
*/
int _strlen(char *s)
{
int len = 0;
while (s[len])
{
len++;
}
return (len);
}

/**
 * *_strcpy -copy string
 * @dest: destination
 * @src: source
 * Return: pointer to copy of string
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i])
{
dest[i] = src[i];
}
return (dest);
}
