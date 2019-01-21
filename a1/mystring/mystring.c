#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *   Implement the following functions: 
 * 
 *   You are NOT allowed to use any standard string functions such as 
 *   strlen, strcpy or strcmp or any other string function.
 */

/*
 *  mystrlen() calculates the length of the string s, 
 *  not including the terminating character '\0'.
 *  Returns: length of s.
 */
int mystrlen (const char *s) 
{
	/* Complete the body of the function */
	unsigned int len = 0;
	//char* next = s;
	while(*s != '\0') {
	    s++;
	    len++;
	}
	return len;
}

/*
 *  mystrcpy()  copies the string pointed to by src (including the terminating 
 *  character '\0') to the array pointed to by dst.
 *  Returns: a  pointer to the destination string dst.
 */
char  *mystrcpy (char *dst, const char *src)
{
	/* Complete the body of the function */
	char * head = dst;
	while(*src != '\0') {
	    *dst = *src;
	    src++;
	    dst++;
	}
	*dst = *src;

	return head;
}

/*
 * mystrcmp() compares two strings alphabetically
 * Returns: 
 * 	-1 if s1  < s2
 *  	0 if s1 == s2
 *  	1 if s1 > s2
 */
char lower(char c){
    if(c >=65 && c<=90) {
        c += 32;
    }
    return c;
}
int mystrcmp(const char *s1, const char *s2)
{
	/* Complete the body of the function */
	while(1) {
	    char a = lower(*s1);
	    char b = lower(*s2);

	    if(a < b){
            return -1;
	    }
	    else if (a > b) {
            return 1;
	    }
	    else if (a == '\0' && b == '\0') {
            return 0;
	    }
	    s1++;
	    s2++;

	}
	return 0;
}

/*
 * mystrdup() creates a duplicate of the string pointed to by s. 
 * The space for the new string is obtained using malloc.  
 * If the new string can not be created, a null pointer is returned.
 * Returns:  a pointer to a new string (the duplicate) 
 	     or null If the new string could not be created for 
	     any reason such as insufficient memory.
 */
char *mystrdup(const char *s1)
{
    char * s2 = malloc(sizeof(char) * (mystrlen(s1) + 1) ); //Malloc 4 * (srtlen+1) bytes
    if(!s2){
		return NULL;
    }
    char * dup = s2;
    while (*s1 != '\0') {
        *s2 = *s1;
        s2++;
        s1++;
    }
    *s2 = '\0'; //add EoS

	return dup;
}

