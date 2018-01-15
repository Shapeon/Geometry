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

float ComputeAngleBetween(const TVector3 & _krA, const TVector3 & _krB)
{
	//Angle equals inverse cosine times ((vector 1 times vector 2) / (vector1 mag times vector2))
	
	float dot_product = (_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ);
	float magnitude_A = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
	float magnitude_B = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2) + pow(_krB.m_fZ, 2));
	float final_angle = acos(dot_product / (magnitude_A * magnitude_B));
	return final_angle;


}


