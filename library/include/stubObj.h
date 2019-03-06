/*
 * stubObj.h
 *
 *  Created on: Mar 6, 2019
 *      Author: vale
 */

#ifndef LIBRARY_INCLUDE_STUBOBJ_H_
#define LIBRARY_INCLUDE_STUBOBJ_H_


#include <string>

class stubObj{
	public:
		stubObj();
		stubObj(std::string name);

		void function1(std::string data);
		void function2(std::string data);
		void function3(std::string data);

		// set random variables
		void setVariables();
		// return each of them
		double getVariables(std::string name);

		double alpha;
		double beta;
		double gamma;


};




#endif /* LIBRARY_INCLUDE_STUBOBJ_H_ */
