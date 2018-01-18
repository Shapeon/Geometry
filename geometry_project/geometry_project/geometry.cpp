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
* Magnitude: calculate magnitude of vector
* @author: Lewis MacJack
* @parameter: A vector
* @return: result of magnitude calculation
********************/
float Magnitude(const TVector3& _krA) {
	float magnitude_result = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2)); // Calculating magnitude
	return magnitude_result;
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
* @parameter: Sphere structure and a 3d vector
* @return: float value representing distance
********************/
float ComputeDistancePointToSphere(const TSphere & _krSphere, const TVector3 & _krPoint)
{
	float ptoc_distance = sqrt(pow(_krPoint.m_fX - _krSphere.m_v3center.m_fX, 2) + pow(_krPoint.m_fY - _krSphere.m_v3center.m_fY, 2) + pow(_krPoint.m_fZ - _krSphere.m_v3center.m_fZ, 2));
	return ptoc_distance;
}

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

TVector3 & ComputeIntersectionBetweenLines(const T3DLine & _krLine1, const T3DLine & _krLine2, TVector3 & _rIntersectionPoint)
{
	
}



