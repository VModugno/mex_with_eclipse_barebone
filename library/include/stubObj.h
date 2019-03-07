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
