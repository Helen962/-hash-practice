//Mengchen Xu
//ID:61281584
//InputParse.cpp

#include <iostream>
#include <string>
#include "InputParse.hpp"
#include "HashMap.hpp"

namespace
{
}

//constructor 
InputParse::InputParse()
    : lineInput{""},inputA{""},user{""},pass{""},debugState{"off"},hm1{HashMap()}
{
}


InputParse::~InputParse()
{
}


// set all the input to a none string
void InputParse::setInput()
{
    lineInput="";
    inputA="";
    user="";
    pass="";
}

// devide up line input, to action;username;password
std::string InputParse::parseInput()
{
    std::string later,later1,later2,goal,ans;
    ans = "";
    std::getline(std::cin,lineInput);
    goal = " ";
    std::size_t f1 = lineInput.find_first_of(goal);
    if (f1 > 100){
        if (lineInput== "CLEAR" or lineInput == "QUIT"){
                inputA = lineInput;}
        else {
                return "INVALID";}}
    else
    {
        inputA = lineInput.substr(0,f1);
        std::string later = lineInput.substr(f1+1);
        if (later == "" and (inputA != "CLEAR" or inputA != "QUIT")){
            return "INVALID";}
        std::size_t f2 = later.find_first_not_of(goal);
        if (f2 > 100 and (inputA != "CLEAR" or inputA != "QUIT")){
            return "INVALID";}
        else{
            later1 = later.substr(f2);}
            std::size_t f3 = later1.find_first_of(goal);
            if (f3 > 100){
                user = later1;}
            else{
                user = later1.substr(0,f3);
                later2 = later1.substr(f3);
                std::size_t f4 = later2.find_first_not_of(goal);
            if (f4<100){
                pass = later2.substr(f4);
                if (pass.find_first_of(goal)>100){}
                else{
                    return "INVALID";}}
            else if (f4 > 100 and not((inputA == "LOGIN" and user == "COUNT") or (inputA == "BUCKET" and user == "COUNT")or (inputA == "LOAD" and user == "FACTOR")
                or (inputA == "DEBUG" and user == "OFF")
                or (inputA == "DEBUG" and user == "ON")))
                {
                    return "INVALID";}
            else{
                pass = "";}}}
        return ans;
}

// function to deal with the "LOGIN" input
std::string InputParse::login()
{
    std::string ans = "INVALID";
    if (user != "COUNT")
    {
        if (pass != "" and hm1.contains(user) and pass == hm1.value(user))
        {
            return "SUCCEEDED";
        }
        else if (pass != "" and (hm1.contains(user)==false or pass != hm1.value(user)))
        {
            return "FAILED";
        }
        else
        {
            return "INVALID";
        }}
    else
    {
        if (debugState == "on")
        {
            return std::to_string(hm1.size());
        }
        else
        {
            return "INVALID";
        }}
return ans;
}

        
// the action did when input is "create"
std::string InputParse::create()
{
    std::string ans = "";
    if (hm1.contains(user))
    {
        return "EXISTS";
    }
    else if (hm1.contains(user) != true and pass != "")
    {
        hm1.add(user,pass);
        return "CREATED";
    }
    else
    {
        return "INVALID";
    }
    return ans;
}


// function, when the action is remove
std::string InputParse::remove()
{
    std::string ans = "INVALID";
   if (hm1.contains(user) == true)
    {
        hm1.remove(user);
        return "REMOVED";
    }
    else
    {
        return "NONEXISTENT";
    }
    return ans;
}




std::string InputParse::clear()
{
    hm1 = HashMap();
    return "CLEARED";
}





std::string InputParse::debug()
{
std::string ans = "INVALID";
   if (user == "ON")
    {
        if (debugState == "on")
        {
            return "ON ALREADY";
        }
        else
        {
            debugState = "on";
            return "ON NOW";
        }}
    else if (user == "OFF")
    {
        if (debugState == "off")
        {
            return "OFF ALREADY";
        }
        else
        {
            debugState = "off";
            return "OFF NOW";
        }}
        else
        {
            return "INVALID";}
    return ans;
}

std::string InputParse::buckCounts()
{
    if (user == "COUNT" and debugState == "on" and pass == "")
            {
                return std::to_string(hm1.bucketCount());
            }
            else
            {
                return "INVALID";  
            }
            return "INVALID";
}

// the function to find loadFact
std::string InputParse::loadFact()
{
    if (user == "FACTOR" and debugState == "on" and pass == "")
    {
        return std::to_string(hm1.loadFactor());
    }
    else
    {
        return "INVALID";
    }
            return "INVALID";
}



std::string InputParse::maxBSize()
{
    if (user == "BUCKET" and pass == "SIZE" and debugState == "on")
    {
        return std::to_string(hm1.maxBucketSize());
    }
    else
    {
        return "INVALID";
    }
    return "INVALID";
}


// function to return the command input
std::string InputParse::inputAStr()
{
    return inputA;
}
