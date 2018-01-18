
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

/***********************
* testNormalise : Test the normalise function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
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

/***********************
* testComputeAngleBetween : Test the ComputeAngleBetween function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
void testComputeAngleBetween() //Answer in degrees
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
	float epsilon = 0.001;
	std::cout << "Computing angles between 3D lines" << std::endl;
	if (abs(test_angle - correct_angle)/test_angle <= epsilon) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	
	std::cout << test_angle << std::endl;
}
/***********************
* testComputeDistancePointToSphere : Test the ComputeDistancePointToSphere function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
void testComputeDistancePointToSphere()
{
	TVector3 centre{
		0.0,
		0.0,
		0.0,
	};

	TVector3 point{
		5.0,
		8.0,
		3.0,
	};
	TSphere ball{
		centre,
		5.0,
	};
	float correct_distance = sqrt(98);
	float test_distance = ComputeDistancePointToSphere(ball, point);
	std::cout << "Computing distance between a point and the centre of a sphere" << std::endl;
	if (correct_distance == test_distance) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
}

void testComputeLineSphereIntersection()
{
	TVector3 line_point{
		4.0,
		4.0,
		4.0,
	};
	TVector3 line_dir{
		1.0,
		1.0,
		1.0,
	};
	T3DLine test_line{
		line_point,
		line_dir,
	};
	TVector3 circle_centre{
		0.0,
		0.0,
		0.0,
	};
	TSphere test_sphere{
		circle_centre,
		1.0,
	};

	TVector3 test_inter1{
		0.0,
		0.0,
		0.0,
	};
	TVector3 test_inter2{
		0.0,
		0.0,
		0.0,
	};
	std::cout << "Testing the Intersection of a Line and a Sphere" << std::endl;
	if (ComputeLineSphereIntersection(test_line, test_sphere, test_inter1, test_inter2) == 2) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
}

void testComputeIntersectionBetweenLines()
{
}

void testIsSurfaceLit()
{
	TVector3 test_surfacept{
		2.0,
		2.0,
		2.0,
	};
	TVector3 test_lightpt{
		1.0,
		5.0,
		5.0,
	};
	TVector3 triangle_pt1{
		0.0,
		0.0,
		0.0,
	};
	TVector3 triangle_pt2{
		0.0,
		0.0,
		0.0,
	};
	TVector3 triangle_pt3{
		0.0,
		0.0,
		0.0,
	};
	TTriangle3 test_triangle{
		triangle_pt1,
		triangle_pt2,
		triangle_pt3,
	};
	std::cout << "Testing if a surface is lit by a light source" << std::endl;
	if (IsSurfaceLit(test_surfacept, test_lightpt, test_triangle)== true) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	
}




