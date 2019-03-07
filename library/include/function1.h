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

#ifndef LIBRARY_INCLUDE_FUNCTION1_H_
#define LIBRARY_INCLUDE_FUNCTION1_H_

// global includes

// library includes

// local includes
#include "modelcomponent.h"

namespace mexComponent
{
  class Function1 : public ModelComponent
  {
    public:
      static Function1 *getInstance();


      /**
       * Delete the (static) instance of this component,
       * and set the instance pointer to 0.
       */
      static void deleteInstance();

      virtual bool allocateReturnSpace(int nlhs, mxArray **plhs);
      virtual bool compute(int nrhs, const mxArray **prhs);
      virtual bool computeFast(int nrhs, const mxArray **prhs);

      virtual ~Function1();

    private:
      Function1();
      bool processArguments(int nrhs, const mxArray **prhs);

      static Function1 * func1;

      // inputs:
      static std::string name;
      // output:
      static double *vector_output; // vector-quaternion transformation (from ref. link to world frame)
  };

}



#endif /* LIBRARY_INCLUDE_FUNCTION1_H_ */








