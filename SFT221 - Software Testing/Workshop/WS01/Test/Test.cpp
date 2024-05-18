#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns true if the strings begins with the prefix.
*/
int flag;
int startsWith(const char s[], char prefix[])
{
	char buf[25];
	int i,j;

	int start = 0, end;

	while (prefix[start] == ' ')
	{
		start++;
	}

	end = strlen(prefix) - 1;
	while (end > start && (prefix[end] == ' '))
	{
		end--;
	}

	for (i = 0, j = start; j <= end; ++i, ++j)
	{
		prefix[i] = prefix[j];
	}

	prefix[end - start + 1] = '\0';

	int sz = strlen(prefix); 
	if (sz == 0)
	{
		printf("Please input a valid prefix!!!\n");
		flag = 1;
		return 0;
	}

	if (sz > strlen(s))
	{
		printf("Please input a prefix which is shorter than the string!!!\n");
		flag = 1;
		return 0;
	}

	if (sz > 24)
	{
		printf("Please input a prefix whose length is shorter than 25!!!\n");
		flag = 1;
		return 0;
	}
	
	for (i = 0; i < sz; i++)
	{
		buf[i] = s[i];
	}
	buf[sz] = '\0';
	return 0 == strcmp(buf, prefix);
}
/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns true if the strings ends with the suffix.
*/
int endsWith(const char s[], char suffix[])
{
	int i, j;

	int start = 0, end;

	while (suffix[start] == ' ')
	{
		start++;
	}

	end = strlen(suffix) - 1;
	while (end > start && (suffix[end] == ' '))
	{
		end--;
	}

	for (i = 0, j = start; j <= end; ++i, ++j)
	{
		suffix[i] = suffix[j];
	}

	suffix[end - start + 1] = '\0';
		
	int sz = strlen(suffix);
	if (sz == 0)
	{
		printf("Please input a valid suffix!!!\n");
		flag = 1;
		return 0;
	}
	if (sz > strlen(s))
	{
		printf("Please input a suffix which is shorter than the string!!!\n");
		flag = 1;
		return 0;
	}


	int slen = strlen(s);
	return 0 == strcmp(s + slen - sz, suffix);
}
int main(void)
{
	char s1[] = { "upended" };
	char prefix[] = { "up" };
	char suffix[] = { "ed" };

	flag = 0;
	startsWith(s1, prefix);

	if (!flag)
	{
		printf("%s does %s start with %s\n", s1, startsWith(s1, prefix) ? "" : " not", prefix);
	}
	flag = 0;
	endsWith(s1, suffix);

	if (!flag)
	{
		printf("%s does %s end with %s\n", s1, endsWith(s1, suffix) ? "" : " not", suffix);
	}
	
	
	
	return 0;
}