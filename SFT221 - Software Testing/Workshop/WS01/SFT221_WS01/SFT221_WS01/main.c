#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns true if the strings begins with the prefix.
*/
int startsWith(const char s[], const char prefix[])
{
    char buf[25]; 
    int i;
    int sz = strlen(prefix);
    for (i = 0; i < sz; i++)
    {
        buf[i] = s[i];
        printf("%c\n", buf[i]);
    }
    buf[sz] = '\0';
    printf("Test: %s \n", buf);
    return 0 == strcmp(buf, prefix);
}
/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns true if the strings ends with the suffix.
*/
int endsWith(const char s[], const char suffix[])
{
    int sz = strlen(suffix);
    int slen = strlen(s);
    return 0 == strcmp(s + slen - sz, suffix);
}

int main(void)
{
    char s1[] = { "upended" };
    char prefix[] = { "upended123" };
    char suffix[] = { "ed123456789" };
    printf("%s does %s start with %s\n",
           s1, startsWith(s1, prefix) ? "" : " not", prefix);
    printf("%s does %s end with %s\n",
           s1, endsWith(s1, suffix) ? "" : " not", suffix);
    return 0;
}
