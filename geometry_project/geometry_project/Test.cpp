
#include "test.h"
#include "geometry.h"

/***********************
* testAdd: tests add function
* @author: Lewis MacJack
* @parameter: ---
* @return: --- 
********************/
void testAdd()
{
	TVector3 lewis{
	1.0,
	1.0,
	1.0,
	};

	TVector3 barry{
	1.0,
	1.0,
	1.0,
	};

	TVector3 testResultant{
		0.0,
		0.0,
		0.0,
	};

	TVector3 desiredResultant{
		2.0,
		2.0,
		2.0,
	};

	Add(lewis, barry, testResultant);
	std::cout << "Addition Function Test" << std::endl;

	if ((testResultant.m_fX == desiredResultant.m_fX) && (testResultant.m_fY == desiredResultant.m_fY) && (testResultant.m_fZ == desiredResultant.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}	
}
/***********************
* testMagnitude : Test the magnitude function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
void testMagnitude() {

	TVector3 mag_vector{
		1.0,
		2.0,
		3.0,
	};

	float wanted_mag = sqrt(14.0);
	float calculated_mag = Magnitude(mag_vector);
	std::cout << "Magnitude Function Test" << std::endl;
	if (calculated_mag == wanted_mag) {
		std::cout << "SUCCESS" << std::endl;
	}

	else{
		std::cout << "FAILURE" << std::endl;
		}
	}
void testNormalise() {
	TVector3 prenorm_vector{
		2.0,
		2.0,
		2.0, };
	
	TVector3 postnorm_vector{
		2.0 / sqrt(12.0),
		2.0 / sqrt(12.0),
		2.0 / sqrt(12.0), 
	};
	TVector3 test_vector{
		0.0,
		0.0,
		0.0, };
	
	test_vector = Normalise(prenorm_vector, test_vector);
	std::cout << "Normalise Test" << std::endl;
	if ((test_vector.m_fX == postnorm_vector.m_fX) && (test_vector.m_fY == postnorm_vector.m_fY) && (test_vector.m_fZ == postnorm_vector.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
}

void testComputeAngleBetween()
{
	TVector3 peter{
		2.0,
		3.0,
		4.0,
	};

	TVector3 parker{
		4.0,
		1.0,
		6.0,
	};
	float correct_angle = 26.78;
	float test_angle = ComputeAngleBetween(peter, parker);
	std::cout << "Computing angles between 3D lines" << std::endl;
	if (correct_angle == test_angle) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	
}

