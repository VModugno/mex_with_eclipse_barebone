/*
 * derived from the work of Naveen Kuppuswamy email: naveen.kuppuswamy@iit.it
 * Author Valerio Modugno email:valerio.modugno@gmail.com
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A P
 *
 * ARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

#include "stubObj.h"
#include <iostream>
#include <stdlib.h>

stubObj::stubObj(){
	alpha = 0;
	beta  = 0;
	gamma = 0;
	std::cout << "constructor no input"<<std::endl;
};
stubObj::stubObj(std::string name){
	alpha = 0;
	beta  = 0;
	gamma = 0;
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

void stubObj::setVariables(){
	alpha = rand() % 100;
	beta  = rand() % 100;
	gamma = rand() % 100;
	std::cout << "alpha = "<<alpha<<std::endl;
	std::cout << "beta = "<<beta<<std::endl;
	std::cout << "gamma = "<<gamma<<std::endl;
}

double  stubObj::getVariables(std::string name){
	if(name.compare("alpha")==0){
		return alpha;
	}
	else if(name.compare("beta")==0){
		return beta;
	}
	else if(name.compare("gamma")==0){
		return gamma;
	}
}
