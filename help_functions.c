#include "holberton.h"

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
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

/**
 * _strdup - Function that duplicates a string
 * @str: String to duplicate
 * @d: Struct. For holding address to buffer for freeing later
 * Return: The copied string, or NULL if fail
 */
char *_strdup(char *str, struct data *d)
{
	if (str == NULL)
		return (NULL);

	d->buffer = malloc(sizeof(char *) * (_strlen(str) + 1));
	if (d->buffer == NULL)
		return (NULL);

	_strcpy(d->buffer, str);
	return (d->buffer);
}
/**
 * _atoi - Function that converts a string to an integer
 * @s: string to convert
 * Return: The string as an integer, or 0 if none
 */
int _atoi(char *s)
{
	unsigned int value = 0;
	int sign = 1;

	do {
		if (*s == '-')
		{
			sign = -sign;
		}
		else if ((*s >= '0' && *s <= '9') && *s != 0)
		{
			value *= 10;
			value += (*s - '0');
		}
		else if (value > 0)
		{
			break;
		}
	} while (*s++);

	return (value * sign);
}
