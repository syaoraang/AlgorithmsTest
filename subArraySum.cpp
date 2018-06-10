#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int array[] = {1, 1, 1, 1, -4, 6, -2, 7, 1, -6, 5, 2, 1, -10, -10};
	const int len = sizeof(array)/sizeof(int);
	unsigned int start = 0, end = 0; //Start and end indexes
	int m = 0, M = 0; //local and global maximum
	for (int i = 0; i < len; ++i)
	{
		m = m+array[i];
		if(array[i] >= m){
			m = array[i];
			start = i;
		}
		if(m >= M){
			M = m;
			end = i;
		}
	}

	printf("Start: %d, End: %d, Total: %d\n", start, end, M);

	return 0;
}