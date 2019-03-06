/*
 * stubObj.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: vale
 */


#include "stubObj.h";
#include <iostream>

stubObj::stubObj(){
	std::cout << "constructor no input"<<std::endl;
};
stubObj::stubObj(std::string name){
	std::cout << "constructor with input "<<name<<std::endl;
}

void stubObj::function1(std::string data){
	std::cout << "function1 = "<<data<<std::endl;

}
void stubObj::function2(std::string data){
	std::cout << "function2 = "<<data<<std::endl;
}
void stubObj::function3(std::string data){
	std::cout << "function3 = "<<data<<std::endl;
}

