#pragma once
#ifndef STRINGHELP_H
#define STRINGHELP_H
#define MAX_STRING_SIZE 511
#define MAX_INDEX_SIZE 100
#define MAX_WORD_SIZE 23
struct StringIndex
{
	char str[MAX_STRING_SIZE + 1];
	int wordStarts[MAX_INDEX_SIZE];
	int lineStarts[MAX_INDEX_SIZE];
	int numberStarts[MAX_INDEX_SIZE];
	int numWords, numLines, numNumbers;
};
/**
* * Return the index of the next whitespace.
* @param str - the string to search
* @returns the index of the next white space or the position of the string terminator.
*/
int nextWhite(const char* str);
/**
* Return true if the string contains only digits.
* @param str - the string to check
* @param len - the number of characters to check
* @returns true if the string is only digits.
*/
int isNumber(const char* str, const int len);
/**
* Build an index for a string showing the start of the lines,
* words, and numbers in the string.
* @param str - the string to search
* @returns the index of the next white space or -1 if there is none.
*/
struct StringIndex indexString(const char* str);
/**
* Return the number of lines in the index.
* @param idx - the index to get the number of lines in it
* @returns the number of lines in the index
*/
int getNumberLines(const struct StringIndex* idx);
/**
* Return the number of words in the index.
* @param idx - the index to get the number of words in it
* @returns the number of words in the index
*/
int getNumberWords(const struct StringIndex* idx);
/**
* Return the number of numbers in the index.
* @param idx - the index to get the number of numbers in it
* @returns the number of numbers in the index
*/
int getNumberNumbers(const struct StringIndex* idx);
/**
* Return the nth word from the index
* @param word - where the result will be placed
* @param idx - the index to use
* @param wordNum - the index of the word to retrieve
* @returns the word or an empty string if index is invalid
*/
void getWord(char word[], const struct StringIndex* idx, int wordNum);
/**
* Return the nth number from the index
* @param word - where the result will be placed
* @param idx - the index to use
* @param wordNum - the index of the number to retrieve
* @returns the number or an empty string if index is invalid
*/
void getNumber(char word[], const struct StringIndex* idx, int numberNum);
/**
* Return a pointer to the start of a line
* @param idx - the index to use
* @param lineNum - the index of the line to retrieve
* @returns a pointer to the start of the line
*/
char* getLine(struct StringIndex* idx, int lineNum);
/**
* Prints characters until the terminator is found.
* @param s - the string to print
* @param start - the index to start printing
* @param terminator - the character to stop printing at when encountered.
*/
void printUntil(const char* s, const int start, const char terminator);
/**
* Prints characters until a space is found.
* @param s - the string to print
* @param start - the index to start printing
*/
void printUntilSpace(const char* s, const int start);

#endif