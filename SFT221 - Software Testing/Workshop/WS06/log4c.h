#pragma once

#ifndef LOG4C_H
#define LOG4C_H

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Log message severity codes*/
#define L4C_ERROR	1
#define L4C_WARNING	2
#define L4C_INFO	3


/* This is the size to use for the error messages returned from l4cCheck() */
#define L4C_ERROR_MSG_MAX 50

/* 
* You should store the log file in a structure of this type.
* Eg. struct Log4CStruct logFile = l4cOpen("log.txt", 0);
*/
struct Log4cStruct
{
	FILE*	logFile;
	char	fileStatus;
	char	enabled;
	char	autoFlush;
	char	filter;
};

/**
* Open a log file and return a structure containing information about the log file.
* You must open a log file before it can be used.
* You should call l4cCheck() after opening the file to make sure that the file opened correctly.
* @param fileName - the name of the file to open as a null terminated string.
* @param append - a Boolean value which if false, will overwrite the file if it exists. If true, it will append 
* to the existing file.
* @returns A struct identifying the log file.
*/
struct Log4cStruct l4cOpen(char fileName[], const int append);

/**
* This will close an open log file. Once the file is closed, it cannot be used again unless re-opened.
* @param log - the struct representing the log file to close.
*/
void l4cClose(struct Log4cStruct* log);

/**
* Write an error message to the log file.
* @param log -  the struct representing the log file to write to.
* @param msg - the text string to write to the log file.
*/
void l4cError( struct Log4cStruct* log, const char msg[]);

/**
* Write a warning message to the log file.
* @param log -  the struct representing the log file to write to.
* @param msg - the text string to write to the log file.
*/
void l4cWarning( struct Log4cStruct* log, const char msg[]);

/**
* Write an information message to the log file.
* @param log -  the struct representing the log file to write to.
* @param msg - the text string to write to the log file.
*/
void l4cInfo( struct Log4cStruct* log, const char msg[]);

/**
* Write a formatted message to the log file. 
* @param log -  the struct representing the log file to write to.
* @param severity - The severity of the message using L4C_ERROR, L4C_WARNING or L4C_INFO.
* @param format - a format string, just like you would use for printf.
* @param ... - a varying number of arguments that will provide values to be used in the format string. 
* This works just like printf(format, ...).
*/
void l4cPrintf( struct Log4cStruct* log, const int severity, const char format[], ...);

/**
* This checks the status of the log file and returns 0 if it is function normally. 
* @param log -  the struct representing the log file to check.
* @param errMsg - a string into which an error message will be placed. This string must be at least
* L4C_ERROR_MSG_MAX + 1 characters in length. If there is no error, it will contain an empty string.
* @returns 0 if the file is functioning normally and non-zero if there is an error. If there is an
* error, stop using the log file and print out the error message.
*/
int l4cCheck(const struct Log4cStruct* log, char errMsg[]);

/**
* Temporarily disable the log file without closing it. While disabled, writes will have no effect.
* @param log -  the struct representing the log file to disable. If a NULL parameter is passed, the
* function will have no effect.
*/
void l4cDisable(struct Log4cStruct* log);

/**
* Enable the log file without closing it. This will resume writing to the file if it was disabled.
* @param log -  the struct representing the log file to ensable. If a NULL parameter is passed, the
* function will have no effect.
*/
void l4cEnable(struct Log4cStruct* log);

/**
* Determine if the log file is enabled and the messages will be written to the file.
* @param log -  the struct representing the log file to query.
* @returns true if the file is enabled. If a NULL log file is passed, a negative value is returned.
*/
int l4cIsEnabled(struct Log4cStruct* log);

/**
* This will filter the log file so that only messages of the indicated severity or higher will
* be written to the log file. If you set it to L4C_ERROR, you will only see errors messages in
* the log file. Setting it to L4C_INFO will send all messages to the log file. L4C_INFO is the
* default setting when a log file is opened.
* @param log -  the struct representing the log file to query. If NULL, the function has no effect.
* @param severity - the lowest severity to be sent to the log file.
* @returns the previous setting of the filter. If log was NULL, returns a negative value.
*/
int l4cFilter(struct Log4cStruct* log, const int severity);

/**
* This will return the current setting of the log filter.
* @param log -  the struct representing the log file to query.
* @returns the current setting on the log severity filter.
* Returns filter setting or negative value if log was NULL.
*/
int l4cGetFilter(const struct Log4cStruct* log);

/**
* Auto flush will flush a message to disk right after it has been written to the log file.
* This virtually guarantees all your messages will appear in the log file, even if your
* program crashes. The downside is that this has a major impact on performance if you are
* writing many log messages. The default is to have auto flush on. This function will disable
* auto flush if it is on. If the log is NULL, it has no effect.
* @param log -  the struct representing the log file to query.
*/
void l4cDisableAutoFlush(struct Log4cStruct* log);

/**
* Auto flush will flush a message to disk right after it has been written to the log file.
* This virtually guarantees all your messages will appear in the log file, even if your
* program crashes. The downside is that this has a major impact on performance if you are
* writing many log messages. The default is to have auto flush on. This function will enable
* auto flush if it is off. If the log is NULL, it has no effect.
* @param log -  the struct representing the log file to query.
*/
void l4cEnableAutoFlush(struct Log4cStruct* log);

/**
* Determine if auto flush is enabled for the log file.
* @param log -  the struct representing the log file to query.
* @returns true if auto flush is enabled (default) or false if not enabled. 
* Returns negative value if log is NULL.
*/
int l4cIsAutoFlush(const struct Log4cStruct* log);

#endif