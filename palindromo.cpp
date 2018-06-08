#include <string>
#include <stdio.h>


void fn(std::string prev, std::string str){
	const int n = str.size();
	if(n==1){
		printf("%s%s\n", prev.c_str(), str.c_str());
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		std::string prev1 = prev + str[i];
		std::string str_ = str;
		str_.erase(i, 1);
		fn(prev1, str_);
	}
}



int main(int argc, char const *argv[])
{
	if (argc!=2)
	{
		printf("Usage: %s string\n", argv[0]);
		return 0;
	}
	std::string input(argv[1]);
	fn("", input);
	return 0;
}