#include "shell.h"

/**
 * _strcmp - Function that compares two strings
 * and attempts to find a match
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: 0 if the two strings are exactly identical, or any value
 * otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i, m = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		{
			m = s1[i] - s2[i];
		}
		else
		{
			m = s1[i] - s2[i];
			break;
		}
	}
	return (m);
}

/**
 * _strlen - Function that return the length of a string
 * @s: String to be counted
 * Return: The length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcpy - Function that copies a string from src to dest
 * @dest: Destination string
 * @src: String to be copied
 * Return: Pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
