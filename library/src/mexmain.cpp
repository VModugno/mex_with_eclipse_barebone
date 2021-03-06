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

/** this wrapper is made in way that at the beginning you need to initialize your objects and then you can recall them using the
 *  associate components through the component manager**/

// global includes
#include <iostream>

// library includes

// local includes
#include "modelcomponent.h"
#include "componentmanager.h"

// namespaces
using namespace mexComponent;

// global variables
/**
 * Just a local copy of the pointer that you get
 * by ComponentManager::getInstance()
 *
 * To properly destroy, call ComponentManager::deleteInstance()
 * and then set this pointer to 0.
 */
static ComponentManager *pCompManager = 0;

// Cleanup function to call when matlab exits or mex clears
void mexWbmExit(void)
{
#ifdef DEBUG
  mexPrintf("Try to delete ComponentManager...\n");
#endif
  ComponentManager::deleteInstance();
  pCompManager = 0;
}

//=========================================================================================================================
// Entry point function to library
                 // # output //output arg  // # input    //  input args
void mexFunction(int nlhs, mxArray **plhs, int nrhs, const mxArray **prhs)
{

  #ifdef DEBUG
		  mexPrintf("mex function entry point\n");
  #endif
  if (pCompManager == 0) {
    // initialization of the component, i.e first call after a 'close all' or matlab start
    if (nrhs < 1) {
      mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidNumInputs", "Initialization has not been performed correctly.");
    }
    // check to be sure input is of type char
    if ( !mxIsChar(prhs[0]) ) {
      mexErrMsgIdAndTxt("MATLAB:mexatexit:inputNotString", "Initialization must include component.");
    }

    if (nrhs == 2) {
      if ( !mxIsChar(prhs[1]) ) {
        mexErrMsgIdAndTxt("MATLAB:mexatexit:inputNotString", "Initialization must include component and a robot name.");
      }
      std::cout <<"2.0"<<std::endl;
      pCompManager = ComponentManager::getInstance(mxArrayToString(prhs[1]));
      std::cout <<"2"<<std::endl;
    }
    else {
      // initialize with default configuration ... (first time call)
      std::cout <<"2.0.1"<<std::endl;
      pCompManager = ComponentManager::getInstance();
      std::cout <<"2.0.2"<<std::endl;
    }
    // register function to call on Matlab close / mex clear
    // to proper deallocate all the memory
    std::cout <<"2.0.3"<<std::endl;
    mexAtExit(mexWbmExit);
    std::cout <<"2.0.4"<<std::endl;
    return;
  }
  // else, the ComponentManager is already initialized ...
  #ifdef DEBUG
    mexPrintf("Start to process function...\n");
  #endif

  if (nrhs < 1) {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidNumInputs", "Required component must be named.");
  }
  // check to be sure input is of type char
  if ( !mxIsChar(prhs[0]) ) {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:inputNotString", "Input must be of type string.");
  }
  pCompManager->processFunctionCall(nlhs, plhs, nrhs, prhs);
}
