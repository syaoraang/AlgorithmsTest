#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fn(const char* prev, const char* str){
	const int n = strlen(str);
	if(n==1){
		printf("%s%c\n", prev, str[0]);
		return;
	}
	const int pl = strlen(prev);
	//Reserve pl characters + 2, 1 for \0 and the other for the new character to be stored
	char *prev_ = (char*)malloc(pl+2);
	//Reserving one extra character to include the '\0'
	char *str_ = (char*)malloc(n);
	for (int i = 0; i < n; ++i)
	{
		//Cleaning up all the array for the next one
		memset(prev_, 0, pl+2);
		memset(str_, 0, n);
		//Copying existing prev array
		strcpy(prev_, prev);
		//Adding the new one
		prev_[pl]=str[i];
		//Copying the characters before the i-th character
		strncpy(str_, str, i);
		//Copying the characters after the i-th character
		strncpy(str_+i, str+i+1, n-i+1);
		fn(prev_, str_);
	}
	free(str_);
	free(prev_);
}

int main(int argc, char const *argv[])
{
	if (argc!=2)
	{
		printf("Usage: %s string\n", argv[0]);
		return 0;
	}
	const char* input = argv[1];
	fn("", input);
	return 0;
}