#include <stdio.h>

int main(int argc, char const *argv[])
{
	char array[][100] = {
		"#include <stdio.h>",
		"",
		"int main(int argc, char const *argv[])",
		"{",
		"	char array[][100] = {",
		"	};",
		"int len = 6;",
		"for (int i = 0; i < 5; ++i)",
		"{",
		"	printf(\"%s\n\", array[i]);",
		"}",
		"for (int i = 0; i < len; ++i)",
		"{		",
		"	printf(\"\"%s\"\n\", array[i]);",
		"}",
		"for (int i = 5; i < len; ++i)",
		"{",
		"	printf(\"%s\n\", array[i]);",
		"}",
		"return 0;",
		"}",
	};
	int len = 21;
	for (int i = 0; i < 5; ++i)
	{
		printf("%s\n", array[i]);
	}
	for (int i = 0; i < len; ++i)
	{		
		printf("\t\"%s\"\n", array[i]);
	}
	for (int i = 5; i < len; ++i)
	{
		printf("%s\n", array[i]);
	}
	return 0;
}