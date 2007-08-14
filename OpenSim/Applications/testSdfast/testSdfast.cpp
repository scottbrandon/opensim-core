// testSdfast.cpp
// Author: Peter Loan
/* Copyright (c) 2006, Stanford University and Peter Loan.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

// INCLUDES
#include <string>
#include <OpenSim/Common/Storage.h>
#include <OpenSim/Common/IO.h>
#include <OpenSim/Common/VisibleProperties.h>
#include <OpenSim/Common/ScaleSet.h>
#include <OpenSim/Simulation/Model/Model.h>
#include <OpenSim/Actuators/LinearSetPoint.h>
#include <OpenSim/DynamicsEngines/SdfastEngine/SdfastEngine.h>
#include <OpenSim/DynamicsEngines/SimmKinematicsEngine/SimmKinematicsEngine.h>
#include <OpenSim/Actuators/Schutte1993Muscle.h>

using namespace std;
using namespace OpenSim;


//______________________________________________________________________________
/**
 * Program to read an xml file for an openSim Model and generate
 * SDFast corresponding code.
 *
 * @param argc Number of command line arguments
 * @param argv Command line arguments: testSdfast 
 */
int main(int argc, char **argv)
{
	Object::RegisterType(SdfastEngine());
	SdfastEngine::registerTypes();

	Object::RegisterType(SimmKinematicsEngine());
	SimmKinematicsEngine::registerTypes();

	Object::RegisterType(Schutte1993Muscle());
	//Schutte1993Muscle::registerTypes();

	try {
			// Construct the model with the SimmKinematicsEngine
			Model *model1 = new Model("C:/SimTK/OpenSim/Utilities/simmToOpenSim/test/meTest2.osim");
			model1->setup();
			model1->kinTest();

			// Construct the model with the SdfastEngine
			Model *model2 = new Model("ellWrapSdfast.xml");
			model2->setup();
			model2->kinTest();

			// Cleanup
			delete model1;
			delete model2;
	}
	catch(Exception &x) {
		x.print(cout);
	}

}
