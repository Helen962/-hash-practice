//Mengchen Xu
//ID:61281584


#include <iostream>
#include "HashMap.hpp"

#include "InputParse.hpp"
int main()
{
	




	HashMap hm1;



	
	InputParse inp;
	while (true)
	{
		std::string inputA,user,parseIn;
		inp.setInput();
		if (inp.parseInput() == ""){} // devide input
		else
		{
			std::cout<<"INVALID"<<std::endl;
			continue;}
		inputA = inp.inputAStr();
		//all are actions regards to different input command
		if (inputA == "CREATE")
		{
			std::cout<<inp.create()<<std::endl;
		}
		else if (inputA == "LOGIN")
		{
			std::cout<<inp.login()<<std::endl;
		}
		else if (inputA == "REMOVE")
		{
			std::cout<<inp.remove()<<std::endl;
		}
		else if (inputA == "CLEAR")
		{
			std::cout<<inp.clear()<<std::endl;
		}
		else if (inputA == "QUIT")
		{
			std::cout<<"GOODBYE"<<std::endl;
			break;
		}
		else if (inputA == "DEBUG")
		{
			std::cout<<inp.debug()<<std::endl;
		}
		else if (inputA == "BUCKET")
		{
			std::cout<<inp.buckCounts()<<std::endl;
		}
		else if (inputA == "LOAD")
		{
			std::cout<<inp.loadFact()<<std::endl;
		}
		else if (inputA == "MAX")
		{
			std::cout<<inp.maxBSize()<<std::endl;
		}
		else
		{
			std::cout<<"INVALID"<<std::endl;
		}}
    return 0;
}

