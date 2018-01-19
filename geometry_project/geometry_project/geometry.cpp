#include "geometry.h" 
#include <iostream>
#include <cmath>

/***********************  
* Add: Adds two vectors 
* @author: Lewis MacJack 
* @parameter: two vectors to add and a resultant vector 
* @return: the resultant vector of the addition  
********************/

TVector3& Add(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {
	// adding points
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
}
/***********************
* Subtract: Subtracts two vectors
* @author: Lewis MacJack
* @parameter: two vectors to subtract and a resultant vector
* @return: the resultant vector of the subtraction
********************/

TVector3& Subtract(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {
	// subtracting points
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}
 
TVector3& ScaleVector(const TVector3& _krA, const float _kfScalar, TVector3& _rResultant) {
	// scale points
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
}
/***********************
* Magnitude: calculate magnitude of vector

* @author: Lewis MacJack
* @parameter: A vector
* @return: result of magnitude calculation
********************/
float Magnitude(const TVector3& _krA) {
	float magnitude_result = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2)); // Calculating magnitude
	return magnitude_result;
	 }


TVector3 & CrossProduct(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {

	_rResultant.m_fX = ((_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY));
	_rResultant.m_fY = ((_krA.m_fZ * _krB.m_fX) - (_krA.m_fX * _krB.m_fZ));
	_rResultant.m_fZ = ((_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fZ));

	return (_rResultant);

}


/***********************
* Normalise: Normalise a vector
* @author: Lewis MacJack
* @parameter: A vector, resultant vector
* @return: resultant vector
********************/
TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant) {
	float magnitude_result = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2)); // Calculating magnitude
	_rResultant.m_fX = _krA.m_fX / magnitude_result;
	_rResultant.m_fY = _krA.m_fY / magnitude_result;
	_rResultant.m_fZ = _krA.m_fZ / magnitude_result;
	return _rResultant;
}
/***********************
* ComputeAngleBetween: Compute angle between two vectors
* @author: Lewis MacJack
* @parameter: Two vectors
* @return: angle in degrees
********************/
float ComputeAngleBetween(const TVector3 & _krA, const TVector3 & _krB)
{
	//Angle equals inverse cosine times ((vector 1 times vector 2) / (vector1 mag times vector2))
	
	float dot_product = (_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ);
	float magnitude_A = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
	float magnitude_B = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2) + pow(_krB.m_fZ, 2));
	float final_angle = acos(dot_product / (magnitude_A * magnitude_B)) * (180/3.14); //Gets angle and converts to degrees
	return final_angle;


}
/***********************
* ComputeDistancePointToSphere: Compute distance between a point and a spheres centre
* @author: Lewis MacJack
* @parameter: Sphere structure and a 3d vector
* @return: float value representing distance
********************/
float ComputeDistancePointToSphere(const TSphere & _krSphere, const TVector3 & _krPoint)
{
	float ptoc_distance = sqrt(pow(_krPoint.m_fX - _krSphere.m_v3center.m_fX, 2) + pow(_krPoint.m_fY - _krSphere.m_v3center.m_fY, 2) + pow(_krPoint.m_fZ - _krSphere.m_v3center.m_fZ, 2));
	return ptoc_distance;
}
/***********************
* ComputeLineSphereIntersection: Compute Intersection between a line and a sphere
* @author: Lewis MacJack
* @parameter: line, sphere, two intersection points
* @return: enumerated constant
********************/
EIntersections ComputeLineSphereIntersection(const T3DLine & _krLine, const TSphere & _krSphere, TVector3 & _rv3IntersectionPoint1, TVector3 & _rv3IntersectionPoint2)
{
	float a = (pow(_krLine.m_v3v.m_fX -_krLine.m_v3q.m_fX, 2) + pow(_krLine.m_v3v.m_fY - _krLine.m_v3q.m_fY, 2) + pow(_krLine.m_v3v.m_fZ - _krLine.m_v3q.m_fZ, 2));
	float b = 2 * (((_krLine.m_v3v.m_fX - _krLine.m_v3q.m_fX) * (_krLine.m_v3q.m_fX - _krSphere.m_v3center.m_fX)) + ((_krLine.m_v3v.m_fY - _krLine.m_v3q.m_fY) * (_krLine.m_v3q.m_fY - _krSphere.m_v3center.m_fY)) + ((_krLine.m_v3v.m_fZ - _krLine.m_v3q.m_fZ) * (_krLine.m_v3q.m_fZ - _krSphere.m_v3center.m_fZ)));
	float c = (pow(_krSphere.m_v3center.m_fX, 2) + pow(_krSphere.m_v3center.m_fY, 2) + pow(_krSphere.m_v3center.m_fZ, 2) + pow(_krLine.m_v3q.m_fX, 2) + pow(_krLine.m_v3q.m_fY, 2) + pow(_krLine.m_v3q.m_fZ, 2)) - 2 * ((_krSphere.m_v3center.m_fX * _krLine.m_v3q.m_fX) + (_krSphere.m_v3center.m_fY * _krLine.m_v3q.m_fY) + (_krSphere.m_v3center.m_fZ * _krLine.m_v3q.m_fZ)) - pow(_krSphere.m_fRadius, 2);
	float discriminant = pow(b, 2) - 4 * (a*c);
	if (discriminant > 0) {
		return EIntersections(2);
	}
	if (discriminant = 0) {
		return EIntersections(1);
	}
	else {
		return EIntersections(0);
	}
}


/***********************
* ComputeIntersectionBetweenLines: Compute Intersection between two lines
* @author: Lewis MacJack
* @parameter: two lines and an intersection point vector
* @return: vector
********************/
TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1, const T3DLine& _krLine2, TVector3& _rIntersectionPoint)
{
	//Step 1: Calculate cross product of the direction vectors
	TVector3 CrossProductLine1and2_Direction = CrossProduct(_krLine1.m_v3v, _krLine2.m_v3v, CrossProductLine1and2_Direction);

	//Step 2: Calculate the Magnitude of CrossProductLine1and2_Direction
	float MagnitudeCrossProductL1andL2 = pow(Magnitude(CrossProductLine1and2_Direction), 2.0);

	if (MagnitudeCrossProductL1andL2 == 0) {
		std::cout << "No Intersection" << std::endl;
	}
	else {
		//Step 3: get the distance between the q points of Line 1 and Line 2
		TVector3 DistanceL1L2 = Subtract(_krLine1.m_v3q, _krLine2.m_v3q, DistanceL1L2);

		//Step 4: Crossproduct of distance and Line 1 direction
		TVector3 L1L2DistanceL1DirectionCross = CrossProduct(DistanceL1L2, _krLine1.m_v3v, L1L2DistanceL1DirectionCross);

		//Step 5: Crossproduct of distance and Line 2 direction
		TVector3 L1L2DistanceL2DirectionCross = CrossProduct(DistanceL1L2, _krLine2.m_v3v, L1L2DistanceL2DirectionCross);

		//Step 6: Dot products of distance and two Crossproducts
		float Dot_1 = (L1L2DistanceL1DirectionCross.m_fX * DistanceL1L2.m_fX) + (L1L2DistanceL1DirectionCross.m_fY * DistanceL1L2.m_fY) + (L1L2DistanceL1DirectionCross.m_fZ * DistanceL1L2.m_fZ);
		float Dot_2 = (L1L2DistanceL2DirectionCross.m_fX * DistanceL1L2.m_fX) + (L1L2DistanceL2DirectionCross.m_fY * DistanceL1L2.m_fY) + (L1L2DistanceL2DirectionCross.m_fZ * DistanceL1L2.m_fZ);

		//Step 7: Use Dotproducts for solution

		TVector3 IntersectionPoint1 = Add(_krLine1.m_v3q, ScaleVector(_krLine1.m_v3v, Dot_1, IntersectionPoint1), IntersectionPoint1);
		TVector3 IntersectionPoint2 = Add(_krLine2.m_v3q, ScaleVector(_krLine2.m_v3v, Dot_1, IntersectionPoint2), IntersectionPoint2);

		float epsilon = 1.0;

		if ((abs(IntersectionPoint1.m_fX - IntersectionPoint2.m_fX) <= epsilon) && (abs(IntersectionPoint1.m_fY - IntersectionPoint2.m_fY) <= epsilon) && (abs(IntersectionPoint1.m_fZ - IntersectionPoint2.m_fZ) <= epsilon)) {

			_rIntersectionPoint.m_fX = IntersectionPoint1.m_fX;
			_rIntersectionPoint.m_fY = IntersectionPoint1.m_fY;
			_rIntersectionPoint.m_fZ = IntersectionPoint1.m_fZ;

			return _rIntersectionPoint;
			}
		else {
			std::cout << "No Intersection" << std::endl;
			return _rIntersectionPoint;
		}
	}

}
	

/***********************
* IsSurfaceLit: Sees if a surface is lit by a light source
* @author: Lewis MacJack
* @parameter: two vectors and a triangle
* @return: boolean
********************/

bool IsSurfaceLit(const TVector3 & _krPointOnSurface, const TVector3 & _krLightSourcePosition, const TTriangle3 & _krSurface)
{
	float light_source_angle = ComputeAngleBetween(_krPointOnSurface, _krLightSourcePosition);
	TVector3 vector_add1 = Add(_krSurface.m_v3p1, _krSurface.m_v3p2, vector_add1);
	TVector3 vector_add2 = Add(vector_add1, _krSurface.m_v3p3, vector_add2);
	TVector3 vector_norm = Normalise(vector_add2, vector_norm);

	TVector3 vector_subtract1 = Subtract(_krLightSourcePosition, _krPointOnSurface, vector_subtract1);
	float final_angle = ComputeAngleBetween(vector_norm, vector_subtract1);
	std::cout << final_angle << std:: endl;
	if (light_source_angle > 0 && light_source_angle < 180) {
		return true;
	}
	else {
		return false;
	}
}





