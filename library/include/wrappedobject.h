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

#ifndef MODELSTATE_H
#define MODELSTATE_H

// global includes
#include <mex.h>
#include <string>

// library includes
//#include <wbi/wbiUtil.h>
//#include <wbi/iWholeBodyModel.h>

// local includes
#include "stubObj.h"

std::string int_array_to_string(double int_array[], double size_of_array);

namespace mexComponent
{
  class WrappedObject
  {
    public:
	  static WrappedObject *getInstance();
      static WrappedObject *getInstance(const char* inputTowrappedObj);
      static void initModelState();

      /**
      * Delete the (static) instance of this component,
      * and set the instance pointer to 0.
      */
      static void deleteInstance();

      //bool setState(double *qj_t, double *qj_dot_t, double *vb_t);

      //void setGravity(double *pg);
      //void setBase2WorldTransformation(wbi::Frame frm3d_H);
      //wbi::Frame getBase2WorldTransformation();

      //wbi::iWholeBodyModel *robotModel();
      //char *robotName();

      /*double *qj();
      double *qj_dot();
      double *vb();
      double *g();
      size_t dof();

      void qj(double *qj_t);
      void qj_dot(double *qj_dot_t);
      void vb(double *vb_t);
      void g(double *g_t);*/

      double * getAllDataFromContent();

      ~WrappedObject();

    private:
      WrappedObject(const char * inputTowrappedObj);

      //static void initRobotModel(const wbi::IDList &jntIDList);
      //static void initState();

      /**
      * Load a robot model from a yarpWholeBodyInterface
      * configuration, specified by YARP_ROBOT_NAME
      */
      //static void robotModel(const char *pstrRobotName);

      /**
      * Load a robot model from a URDF file path.
      * Using this function, all the dofs of the URDF
      * are automatically added to the interface.
      */
      //static void robotModelFromURDF(const char *pstrURDFileName);

      static WrappedObject *obj;
      static stubObj       *content;
      static double        *contentData;
      //static wbi::iWholeBodyModel *robotWBIModel;

      //static size_t nDof;
      static char *pstrCurrRobotName;
      static const char *pcstrLocalName; // local name of the interface (used as stem of port names)

      // state variables:
      //static double *sqj, *sqj_dot, svb[6], sg[3];

      // frame transformation (from base to world frame):
      //static wbi::Frame wf_H_b;
  };

  /**
   * Helper function to delete instances
   *
   * @param pp pointer to the pointer to delete and set to 0
   */
  template <class T> void deleteObject(T **pp)
  {
    if (*pp != 0) {
      delete *pp;
      *pp = 0;

    #ifdef DEBUG
      mexPrintf("Object deleted.\n");
    #endif
    }
  };

}

#endif // MODELSTATE_H
