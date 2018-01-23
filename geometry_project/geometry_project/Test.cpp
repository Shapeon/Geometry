#include "test.h"
#include "geometry.h"



void testEquals() {

	TVector3 _krA{
		1.0f,
		2.0f,
		3.0f,
	};

	TVector3 _krB{
		1.0f,
		2.0f,
		3.0f,
	};

	std::cout << "Equals Function Test" << std::endl;
	std::cout << std::endl;
	if (Equals(_krA, _krB))
	{
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}

	std::cout << std::endl;
}

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
	std::cout << std::endl;
	if ((testResultant.m_fX == desiredResultant.m_fX) && (testResultant.m_fY == desiredResultant.m_fY) && (testResultant.m_fZ == desiredResultant.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}	
	std::cout << std::endl;
}

void testSubtract() {

}

void testScaleVector() {
	TVector3 _krA{
	1.0f,
	2.0f,
	3.0f,
	};
	
	const float _kfScalar = 5.0f;
	
	TVector3 _rResultant{
	0.0f,
	0.0f,
	0.0f,
	};

	ScaleVector(_krA, _kfScalar, _rResultant);

	std::cout << "Scale Vector Function Test" << std::endl;
	std::cout << std::endl;

	if ((_rResultant.m_fX == 5) && (_rResultant.m_fY == 10) && (_rResultant.m_fZ == 15)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}\
		std::cout << std::endl;
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
	std::cout << std::endl;

	if (calculated_mag == wanted_mag) {
		std::cout << "SUCCESS" << std::endl;
	}

	else{
		std::cout << "FAILURE" << std::endl;
		}
	std::cout << std::endl;
}


void testDotProduct() {

}


void testCrossProduct() {
	TVector3 _krA{
		_krA.m_fX = 2.0f,
		_krA.m_fY = 4.0f,
		_krA.m_fZ = 6.0f,
	};
	TVector3 _krB{
		_krB.m_fX = 1.0f,
		_krB.m_fY = 3.0f,
		_krB.m_fZ = 5.0f,
	};
	TVector3 _rResultant{
		_rResultant.m_fX = 0.0f,
		_rResultant.m_fY = 0.0f,
		_rResultant.m_fZ = 0.0f,
	};

	CrossProduct(_krA, _krB, _rResultant);
	std::cout << "Cross Product Test" << std::endl;
	std::cout << std::endl;

	if ((_rResultant.m_fX == 2) && (_rResultant.m_fY == -4) && (_rResultant.m_fZ == 2)) {
		std::cout << "SUCCESS" << std::endl;
	}

	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;

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
	std::cout << std::endl;


	if ((test_vector.m_fX == postnorm_vector.m_fX) && (test_vector.m_fY == postnorm_vector.m_fY) && (test_vector.m_fZ == postnorm_vector.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;

}

void testProjection(){

}


 void testComputeAngleBetween() {
	TVector2 _krA{
		1.0f,
		3.0f,
	};

	TVector2 _krB{
		5.0f,
		7.0f,
	};

	float RoundUp = ceilf(ComputeAngleBetween(_krA, _krB) * 10000) / 10000;
	std::cout << "Compute angles between 2D Lines Test" << std::endl;
	std::cout << std::endl;

	if (RoundUp == 0.2985f) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;

}

/***********************
* testComputeAngleBetween : Test the ComputeAngleBetween function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
void testComputeAngleBetween3D() //Answer in degrees
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
	std::cout << std::endl;

	if (abs(test_angle - correct_angle)/test_angle <= epsilon) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}


void testComputeDistancePointToLine() {

}



void testComputeDistancePointToPlane() {
	TVector3 m_v3normal{
		1.0f,
		2.0f,
		3.0f,
	};

	TVector3 m_v3point{
		1.0f,
		2.0f,
		3.0f,
	};

	TPlane _krPlane{
		m_v3normal,
		m_v3point,
	};

	TVector3 _krPoint{
		2.0f,
		4.0f,
		6.0f,
	};

	float RoundUp = ceilf(ComputeDistancePointToPlane(_krPlane, _krPoint) * 10000) / 10000;
	std::cout << "Computing distance between a point and a plane" << std::endl;
	std::cout << std::endl;

	if (RoundUp == 3.7417f) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
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
	std::cout << std::endl;

	if (correct_distance == test_distance) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}

void testComputeDistanceCircleToCircle(){

}

void testComputeDistanceCircleToTriangle() {
	TVector2 m_v2center{
		-2,
		 2,
	};

	float m_fRadius = 2.0f;

	TCircle _krCircle{
		m_v2center,
		m_fRadius,
	};

	TVector2 m_v2p1{
		3.0f,
		1.0f,
	};

	TVector2 m_v2p2{
		7.0f,
		4.0f,
	};

	TVector2 m_v2p3{
		4.0f,
		4.0f,
	};

	TTriangle2 _krTriangle{
		m_v2p1,
		m_v2p2,
		m_v2p3,
	};

	float RoundUp = ceilf(ComputeDistanceCircleToTriangle(_krCircle, _krTriangle) * 100) / 100;
	std::cout << "Computing distance between a circle and a triangle" << std::endl;
	std::cout << std::endl;

	if (RoundUp == 6.74f) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}

/***********************
* testComputeLineSphereIntersection : Test the ComputeLineSphereIntersection function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
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
	std::cout << std::endl;

	if (ComputeLineSphereIntersection(test_line, test_sphere, test_inter1, test_inter2) == 2) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}


void testIsLinePlaneIntersection(){

}


void testIsIntersection() {

	TVector3 m_v3q1{
		1.0f,
		1.0f,
		1.0f,
	};

	TVector3 m_v3v1{
		3.0f,
		3.0f,
		3.0f,
	};

	T3DLine _krLine1{
		m_v3q1,
		m_v3v1,
	};

	TVector3 m_v3q2{
		3.0f,
		1.0f,
		1.0f,
	};

	TVector3 m_v3v2{
		3.0f,
		3.0f,
		3.0f,
	};

	T3DLine _krLine2{
		m_v3q2,
		m_v3v2,
	};

	
	std::cout << "Tests if there is an intersection between 3D lines" << std::endl;
	std::cout << std::endl;

	if (IsIntersection(_krLine1, _krLine2)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}


/***********************
* testComputeIntersectionBetweenLines : Test the testComputeIntersectionBetweenLines function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
void testComputeIntersectionBetweenLines(){
	TVector3 Line1Point{
		5,
		5,
		4
	};
	TVector3 Line1Direction{
		10,
		10,
		6
	};
	T3DLine testLine1{
		Line1Point,
		Line1Direction
	};
	TVector3 Line2Point{
		5,
		5,
		5,
	};
	TVector3 Line2Direction{
		10,
		10,
		3,
	};
	T3DLine testLine2{
		Line2Point,
		Line2Direction
	};

	TVector3 testIntersection{
		0.0,
		0.0,
		0.0
	};

	TVector3 DesiredResultant{
		5.0,
		5.0,
		4.0
	};

	std::cout << "Computing Intersection between Lines" << std::endl;
	std::cout << std::endl;

	ComputeIntersectionBetweenLines(testLine1, testLine2, testIntersection);
	
	if ((DesiredResultant.m_fX == testIntersection.m_fX) && (DesiredResultant.m_fY == testIntersection.m_fY) && (DesiredResultant.m_fZ == testIntersection.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}

void IsInFieldOfView() {

}

void testFindTriangleNormal() {

	TVector3 m_v3p1{
		m_v3p1.m_fX = 2.0f,
		m_v3p1.m_fY = 4.0f,
		m_v3p1.m_fZ = 6.0f,
	};

	TVector3 m_v3p2{
		m_v3p2.m_fX = 1.0f,
		m_v3p2.m_fY = 3.0f,
		m_v3p2.m_fZ = 5.0f,
	};
	TVector3 m_v3p3{
		m_v3p3.m_fX = 1.0f,
		m_v3p3.m_fY = 2.0f,
		m_v3p3.m_fZ = 3.0f,
	};

	TTriangle3 _krTriangle{
		m_v3p1,
		m_v3p2,
		m_v3p3,
	};

	TVector3 _rNormal{
		_rNormal.m_fX = 1.0f,
		_rNormal.m_fY = 2.0f,
		_rNormal.m_fZ = 3.0f
	};

	FindTriangleNormal(_krTriangle, _rNormal);
	std::cout << "Normalise a Triangle" << std::endl;
	std::cout << std::endl;
	
	if ((_rNormal.m_fX == 1) &&
		(_rNormal.m_fY == -2) &&
		(_rNormal.m_fZ == 1)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}

/***********************
* testIsSurfaceLit : Test the IsSurfaceLit function
* @author: Lewis MacJack
* @parameter: ---
* @return: ---
********************/
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
		2.0,
		2.0,
		2.0,
	};
	TVector3 triangle_pt2{
		2.0,
		2.0,
		3.0,
	};
	TVector3 triangle_pt3{
		2.0,
		3.0,
		2.0,
	};
	TTriangle3 test_triangle{
		triangle_pt1,
		triangle_pt2,
		triangle_pt3,
	};
	std::cout << "Testing if a surface is lit by a light source" << std::endl;
	std::cout << std::endl;

	if (IsSurfaceLit(test_surfacept, test_lightpt, test_triangle)== true) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}
	std::cout << std::endl;
}

void testRotateTriangleAroundPoint(){

}





