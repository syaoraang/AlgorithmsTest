#include <fstream> 		//For ifstream
#include <sstream> 		//string lies here
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAILURE 1

int main(int argc, char const *argv[])
{
	//In this case we're considering, there's not another way to do it, that the .cpp and the executable have the same
	//and that they're in the same folder
	std::string fileName = argv[0], line;
	fileName+=".cpp";
	std::ifstream file(fileName.c_str());
	if(!file.is_open())
		exit(EXIT_FAILURE);
	//While there's something to read we will keep reading and showing it
	while(std::getline(file, line)){
		std::cout<<line<<"\n";
	}
	if (system(NULL))
		puts ("Ok");
	else
		exit (EXIT_FAILURE);
	//When we're sure that the system is ready to help us out to compile the game, we build the command string to excecute
	std::stringstream command;
	command<<"g++ -g "<<fileName<<" -o sample";
	//And we run it
	system(command.str().c_str());
	return 0;
}