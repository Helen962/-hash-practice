





#ifndef INPUTPARSE_HPP
#define INPUTPARSE_HPP

#include <string>
#include <iostream>
#include "HashMap.hpp"

class InputParse
{

//the public part of the class. 

public:
    InputParse();
    void setInput();
    std::string parseInput();
    std::string inputAStr();
	std::string login();
	std::string create();
	std::string remove();
	std::string clear();
	std::string debug();
	std::string buckCounts();
	std::string loadFact();
	std::string maxBSize();
 	~InputParse();


private:   
	//all the private functions
std::string lineInput,inputA,user,pass,debugState;
HashMap hm1;
};

  

#endif //inputParse.hpp
