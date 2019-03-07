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

#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

// global includes

// library includes

// local includes
#include "wrappedobject.h"

namespace mexComponent
{
  class ModelComponent {
    public:
      static ModelComponent *getInstance();

      virtual bool allocateReturnSpace(int nlhs, mxArray **plhs) = 0;
      virtual bool compute(int nrhs, const mxArray **prhs) = 0;
      virtual bool computeFast(int nrhs, const mxArray **prhs) = 0;

      const unsigned int numReturns();
      const unsigned int numArguments();
      const unsigned int numAltArguments();

      virtual ~ModelComponent();

    protected:
      ModelComponent(const unsigned int nArgs, const unsigned int nAltArgs, const unsigned int nRets);

      /* Internal function used to reorder double* matrix
       * elements (since MATLAB is column-major ordered
       * wbi::Rotation is instead row-major)
       */
      bool reorderMatrixInRowMajor(const double *srcMat, double *destMat, int nRows = 3, int nCols = 3);
      bool reorderMatrixInColMajor(const double *srcMat, double *destMat, int nRows = 3, int nCols = 3);

      static WrappedObject *obj;
      //static wbi::iWholeBodyModel *robotModel;

      // frame transformation (from base to world frame):
      //static wbi::Frame wf_H_b;

      const unsigned int numArgs;
      const unsigned int numRets;
      const unsigned int numAltArgs;
  };

}

#endif // MODELCOMPONENT_H

