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

// global includes

// library includes

// local includes
#include "function1.h"

using namespace mexComponent;

Function1 *Function1::func1       = 0;
std::string Function1::name       = "";
double * Function1::vector_output = 0;
//double *ModelForwardKinematics::qj      = 0;
//char   *ModelForwardKinematics::refLnk  = 0;
//double *ModelForwardKinematics::vqT_lnk = 0;

Function1::Function1() : ModelComponent(1, 1, 1)
{
}

Function1::~Function1()
{
#ifdef DEBUG
  mexPrintf("Function1 destructed.\n");
#endif
}

Function1 *Function1::getInstance()
{
  if (func1 == 0) {
	  func1 = new Function1();
  }
  return func1;
}

void Function1::deleteInstance()
{
  deleteObject(&func1);
}
// in this function we need to connect the output with the variable that will store the result of the computation in processArguments;
bool Function1::allocateReturnSpace(int nlhs, mxArray **plhs)
{
#ifdef DEBUG
  mexPrintf("Trying to allocateReturnSpace in function1.\n");
#endif
  plhs[0] = mxCreateDoubleMatrix(3, 1, mxREAL);
  vector_output = mxGetPr(plhs[0]);

  return true;
}
bool Function1::compute(int nrhs, const mxArray **prhs)
{
#ifdef DEBUG
  mexPrintf("function1 performing compute.\n");
#endif
  return processArguments(nrhs, prhs);
}

bool Function1::processArguments(int nrhs, const mxArray **prhs)
{
#ifdef DEBUG
  if (vqT_lnk == 0) {
    return false;
  }
#endif


  double* cur_values = this->obj->getAllDataFromContent();

  for (int i=0; i < 3; i++) {
      *(vector_output + i) = *(cur_values + i); // copy position vector
  }



  /*size_t nDof = modelState->dof();

  if ( mxGetM(prhs[1]) != 9 || mxGetN(prhs[1]) != 1 || mxGetM(prhs[2]) != 3 || mxGetN(prhs[2]) != 1 ||
       mxGetM(prhs[3]) != nDof || mxGetN(prhs[3]) != 1 || !mxIsChar(prhs[4]) )
  {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidNumInputs", "Malformed state dimensions/components.");
  }
  robotModel = modelState->robotModel();

  double *pR, *ppos;
  pR     = mxGetPr(prhs[1]);
  ppos   = mxGetPr(prhs[2]);
  qj     = mxGetPr(prhs[3]);
  refLnk = mxArrayToString(prhs[4]);

  std::string strCom("com");
  int refLnkID = -1; // if refLnk = "com"

  if (strCom.compare(refLnk) != 0) {
    if ( !robotModel->getFrameList().idToIndex(refLnk, refLnkID) ) {
      mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidInputs", "forwardKinematics call: Link ID does not exist.");
    }
  }

#ifdef DEBUG
  mexPrintf("qj received.\n");

  for (size_t i=0; i < nDof; i++) {
    mexPrintf(" %f", *(qj + i));
  }
#endif

  double R_rmo[9];
  reorderMatrixInRowMajor(pR, R_rmo); // matrix in "row major order"
  wbi::Rotation rot3d(R_rmo);

  wf_H_b = wbi::Frame(rot3d, ppos);

  double vxT_lnk[7]; // vector axis-angle transformation (from ref. link to world frame)
  if ( !(robotModel->forwardKinematics(qj, wf_H_b, refLnkID, vxT_lnk)) ) {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidInputs", "Something failed in the WBI forwardKinematics call.");
  }

  int i;
  for (i=0; i < 3; i++) {
    *(vqT_lnk + i) = *(vxT_lnk + i); // copy position vector
  }

  double axang[4] = {vxT_lnk[3], vxT_lnk[4], vxT_lnk[5], vxT_lnk[6]}; // axis-angle vector
  rot3d = wbi::Rotation::axisAngle(axang);

#ifdef DEBUG
  std::stringstream ssR;
  ssR << "axis-angle: [" << vxT_lnk[3] << "," << vxT_lnk[4] << "," << vxT_lnk[5] << "," << vxT_lnk[6] << "]\n";
  std::string sR = ssR.str();
  mexPrintf(sR.c_str());
  mexPrintf("rotation:\n");
  mexPrintf((rot3d.toString()).c_str());
#endif

  double quat_lnk[4];
  rot3d.getQuaternion(quat_lnk[1], quat_lnk[2], quat_lnk[3], quat_lnk[0]);
  for (i=0; i < 4; i++) {
    *(vqT_lnk + (3+i)) = *(quat_lnk + i); // copy quaternion
  }*/
  return true;
}

bool Function1::computeFast(int nrhs, const mxArray **prhs)
{
#ifdef DEBUG
  mexPrintf("fucntion1 performing computeFast.\n");
#endif
#ifdef DEBUG
  if (vqT_lnk == 0) {
    return false;
  }
#endif
  /*if ( !mxIsChar(prhs[1]) ) {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidNumInputs", "Malformed state dimensions/components.");
  }
  robotModel = modelState->robotModel();

  wf_H_b = modelState->getBase2WorldTransformation();
  qj     = modelState->qj();
  refLnk = mxArrayToString(prhs[1]);

  std::string strCom("com");
  int refLnkID = -1; // if refLnk = "com"

  if (strCom.compare(refLnk) != 0) {
    if ( !robotModel->getFrameList().idToIndex(refLnk, refLnkID) ) {
      mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidInputs", "forwardKinematics call: Link ID does not exist.");
    }
  }

  double vxT_lnk[7]; // vector axis-angle transformation (from ref. link to world frame)
  if ( !(robotModel->forwardKinematics(qj, wf_H_b, refLnkID, vxT_lnk)) ) {
    mexErrMsgIdAndTxt("MATLAB:mexatexit:invalidInputs", "Something failed in the WBI forwardKinematics call.");
  }

  int i;
  for (i=0; i < 3; i++) {
    *(vqT_lnk + i) = *(vxT_lnk + i); // copy position vector
  }

  double axang[4] = {vxT_lnk[3], vxT_lnk[4], vxT_lnk[5], vxT_lnk[6]}; // axis-angle vector
  wbi::Rotation rot3d = wbi::Rotation::axisAngle(axang);

#ifdef DEBUG
  std::stringstream ssR;
  ssR << "axis-angle: [" << vxT_lnk[3] << "," << vxT_lnk[4] << "," << vxT_lnk[5] << "," << vxT_lnk[6] << "]\n";
  std::string sR = ssR.str();
  mexPrintf(sR.c_str());
  mexPrintf("rotation:\n");
  mexPrintf((rot3d.toString()).c_str());
#endif

  double quat_lnk[4];
  rot3d.getQuaternion(quat_lnk[1], quat_lnk[2], quat_lnk[3], quat_lnk[0]);
  for (i=0; i < 4; i++) {
    *(vqT_lnk + (3+i)) = *(quat_lnk + i); // copy quaternion
  }*/

#ifdef DEBUG
  mexPrintf("Function1 fast computed.\n");
#endif
  return true;
}


