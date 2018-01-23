#include "geometry.h" 
#include <iostream>
#include <cmath>

/***********************
* Equals: test equality of vectors
* @author: Daniel Opoka
* @parameter: TVector3& _krA, TVector3& _krB
* @return: Boolean
********************/

bool Equals(const TVector3& _krA,
	const TVector3& _krB) {
	if ((_krA.m_fX == _krB.m_fX) &&
		(_krA.m_fY == _krB.m_fY) &&
		(_krA.m_fZ == _krB.m_fZ)) {
		return true;
	}
	else {
		return false;
	}
}

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
* @author: Jason Kristanto
* @parameter: two vectors to subtract and a resultant vector
* @return: the resultant vector of the subtraction
********************/

TVector3& Subtract(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}


/***********************
* ScaleVector: Scales a vector
* @author: Daniel Opoka
* @parameter: const TVector3& _krA, const float _kfScalar, TVector3& _rResultant
* @return: ScaleVector.m_fX, ScaleVector.m_fY, ScaleVector.m_fZ,
********************/

TVector3& ScaleVector(const TVector3& _krA,
	const float _kfScalar,
	TVector3& _rResultant) {
	_rResultant.m_fX = (_kfScalar * _krA.m_fX);
	_rResultant.m_fY = (_kfScalar * _krA.m_fY);
	_rResultant.m_fZ = (_kfScalar * _krA.m_fZ);

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
* DotProduct: Calculates dot product 
* @author: Jason Kristanto
* @parameter: const TVector3& _krA, const TVector3& _krB
* @return: the dot product of the two vectors
********************/

float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	return ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ));
}


/***********************
* Cross Product: Calculates cross product between given vectors
* @author: Daniel Opoka
* @parameter: const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant
* @return: CrossProduct.m_fX, CrossProduct.m_fY, CrossProduct.m_fZ
********************/

TVector3& CrossProduct(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {
	_rResultant.m_fX = ((_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY));
	_rResultant.m_fY = ((_krA.m_fZ * _krB.m_fX) - (_krA.m_fX * _krB.m_fZ));
	_rResultant.m_fZ = ((_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX));

	return _rResultant;
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
* Projection: Calculates projection of vectors
* @author: Jason Kristanto
* @parameter: Two vectors and a resultant vector
* @return: resultant vector
********************/
TVector3& Projection(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{

	float dotproductAB = ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ));
	float Magnitude = (_krB.m_fX * _krB.m_fX) + (_krB.m_fY * _krB.m_fY) + (_krB.m_fZ * _krB.m_fZ);
	float multiplyer = dotproductAB / Magnitude;

	_rResultant.m_fX = _krA.m_fX * multiplyer;
	_rResultant.m_fY = _krA.m_fY * multiplyer;
	_rResultant.m_fZ = _krA.m_fZ * multiplyer;

	return _rResultant;
}

/***********************
* ComputeAngleBetween: Compute angle between 2d vectors
* @author: Daniel Opoka
* @parameter: const TVector2& _krA, const TVector2& _krB
* @return: Float, the answer is in radians
********************/

float ComputeAngleBetween(const TVector2& _krA,
	const TVector2& _krB) {
	float AB = ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY));
	float NormA = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2));
	float NormB = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2));
	float NormAB = (NormA * NormB);
	float AngleBetween = acos(AB / NormAB);

	return AngleBetween;
}


/***********************
* ComputeAngleBetween: Compute angle between two 3d vectors
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
	float final_angle = acos(dot_product / (magnitude_A * magnitude_B)) * (180 / 3.14); //Gets angle and converts to degrees
	return final_angle;


}


/***********************
* Compute Distance Point To Line: Computes distance between a point and a line
* @author: Jason Kristanto
* @parameter: const T3DLine& _krLine, const TVector3& _krPoint
* @return: Float
********************/
float ComputeDistancePointToLine(const T3DLine& _krLine, const TVector3& _krPoint)
{

	float DirectVec1 = _krPoint.m_fX - _krLine.m_v3q.m_fX;
	float DirectVec2 = _krPoint.m_fY - _krLine.m_v3q.m_fY;
	float DirectVec3 = _krPoint.m_fZ - _krLine.m_v3q.m_fZ;

	// Multiply with Line Direction Vector
	float MultipliedDirectVec1 = DirectVec1 * _krLine.m_v3v.m_fX;
	float MultipliedDirectVec2 = DirectVec2 * _krLine.m_v3v.m_fY;
	float MultipliedDirectVec3 = DirectVec3 * _krLine.m_v3v.m_fZ;

	// Calculate Magnitude for Numerator
	float MagnitudeVec = pow(MultipliedDirectVec1, 2) + pow(MultipliedDirectVec2, 2) + pow(MultipliedDirectVec3, 2);

	float MagnitudeVecSqrt = sqrt(MagnitudeVec);

	// Calculate Magnitude for Denominator
	float MagnitudeVec2 = pow(_krLine.m_v3v.m_fX, 2) + pow(_krLine.m_v3v.m_fY, 2) + pow(_krLine.m_v3v.m_fZ, 2);

	float MagnitudeVec2Sqrt = sqrt(MagnitudeVec2);

	// Calculate Distance
	return MagnitudeVecSqrt / MagnitudeVec2Sqrt;
}


/***********************
* Compute Distance Point To Plane: Compute distance between a point and a plane
* @author: Daniel Opoka
* @parameter: const TPlane& _krPlane, const TVector3& _krPoint
* @return: Float
********************/

float ComputeDistancePointToPlane(const TPlane& _krPlane, const TVector3& _krPoint) {
	float VWX = (_krPlane.m_v3normal.m_fX * (_krPoint.m_fX - _krPlane.m_v3point.m_fX));
	float VWY = (_krPlane.m_v3normal.m_fY * (_krPoint.m_fY - _krPlane.m_v3point.m_fY));
	float VWZ = (_krPlane.m_v3normal.m_fZ * (_krPoint.m_fZ - _krPlane.m_v3point.m_fZ));
	float VW = (VWX + VWY + VWZ);
	float V = (sqrt(pow(_krPlane.m_v3normal.m_fX, 2) + pow(_krPlane.m_v3normal.m_fY, 2) + pow(_krPlane.m_v3normal.m_fZ, 2)));
	float Distance = (VW / V);

	return Distance;
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
* ComputeDistanceCircleToCircle: Compute distance between a two circles
* @author: Jason Kristanto
* @parameter: Two circle structures
* @return: float value representing distance
********************/
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1, const TCircle& _krCircle2)
{

	float xResult = _krCircle1.m_v2center.m_fX - _krCircle2.m_v2center.m_fX;
	float yResult = _krCircle1.m_v2center.m_fY - _krCircle2.m_v2center.m_fY;

	return sqrt(pow(xResult, 2) + pow(yResult, 2));
}



/***********************
* ComputeDistanceCircleToTriangle: Calculates distance between a circle and a triangle
* @author: Daniel Opoka
* @parameter: const TCircle& _krCircle, const TTriangle2& _krTriangle
* @return: Float
********************/

float ComputeDistanceCircleToTriangle(const TCircle& _krCircle,
	const TTriangle2& _krTriangle) {
	float TCX = (_krTriangle.m_v2p1.m_fX + _krTriangle.m_v2p2.m_fX + _krTriangle.m_v2p3.m_fX) / 3;
	float TCY = (_krTriangle.m_v2p1.m_fY + _krTriangle.m_v2p2.m_fY + _krTriangle.m_v2p3.m_fY) / 3;
	float CCMinusTCX = (_krCircle.m_v2center.m_fX - TCX);
	float CCMinusTCY = (_krCircle.m_v2center.m_fY - TCY);
	float Distance = (sqrt(pow(CCMinusTCX, 2) + pow(CCMinusTCY, 2)));
	Distance = floor(Distance * 100.00) / 100.00;

	return Distance;
}

/***********************
* ComputeLineSphereIntersection: Compute Intersection between a line and a sphere
* @author: Lewis MacJack
* @parameter: line, sphere, two intersection points
* @return: enumerated constant
********************/
EIntersections ComputeLineSphereIntersection(const T3DLine & _krLine, const TSphere & _krSphere, TVector3 & _rv3IntersectionPoint1, TVector3 & _rv3IntersectionPoint2)
{
	float a = (pow(_krLine.m_v3v.m_fX - _krLine.m_v3q.m_fX, 2) + pow(_krLine.m_v3v.m_fY - _krLine.m_v3q.m_fY, 2) + pow(_krLine.m_v3v.m_fZ - _krLine.m_v3q.m_fZ, 2));
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
* IsLinePlaneIntersection: See if a line and a plane intersect
* @author: Jason Kristanto
* @parameter: const T3DLine& _krLine, const TPlane& _krPlane, TVector3& _rv3IntersectionPoint
* @return: Boolean
********************/
bool IsLinePlaneIntersection(const T3DLine& _krLine, const TPlane& _krPlane, TVector3& _rv3IntersectionPoint)
{
	float DotProd;
	DotProd = (_krPlane.m_v3normal.m_fX * _krLine.m_v3v.m_fX) + (_krPlane.m_v3normal.m_fY * _krLine.m_v3v.m_fY) + (_krPlane.m_v3normal.m_fZ * _krLine.m_v3v.m_fZ);
	if (DotProd == 0)
		return false;
	return true;
}


/***********************
* IsIntersection: Test if there is an intersection between two lines
* @author: Daniel Opoka
* @parameter: const T3DLine& _krLine1, const T3DLine& _krLine2
* @return: Boolean
********************/

bool IsIntersection(const T3DLine& _krLine1,
	const T3DLine& _krLine2) {
	

	float day = (_krLine1.m_v3v.m_fY - _krLine1.m_v3q.m_fY);
	float daz = (_krLine1.m_v3v.m_fZ - _krLine1.m_v3q.m_fZ);

	float dby = (_krLine2.m_v3v.m_fY - _krLine2.m_v3q.m_fY);
	float dbz = (_krLine2.m_v3v.m_fZ - _krLine2.m_v3q.m_fZ);

	float dcx = (_krLine2.m_v3q.m_fX - _krLine1.m_v3q.m_fX);

	float ex = (day * dbz) - (daz * dby);

	float Num = dcx * ex;

	if (Num == 0) {
		return true;
	}
	else {
		return false;
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
* IsInFieldOfView: Tests if an object is within a cameras field of view
* @author: Jason Kristanto
* @parameter: const TVector2& _krCameraPosition, const TVector2& _krCameraDirection, const float _kfFieldOfViewInRadians, const TVector2& _krObjectPosition
* @return: Boolean
********************/

bool IsInFieldOfView(const TVector2& _krCameraPosition, const TVector2& _krCameraDirection, const float _kfFieldOfViewInRadians, const TVector2& _krObjectPosition)
{
	const double PI = 3.14159265358979323846264338328;
	float DirVec1 = _krObjectPosition.m_fX - _krCameraPosition.m_fX;
	float DirVec2 = _krObjectPosition.m_fY - _krCameraPosition.m_fY;
	float DirMag = pow(_krCameraDirection.m_fX, 2) + pow(_krCameraDirection.m_fY, 2);

	float DirMagSqrt = sqrt(DirMag);

	float DirMag1 = _krCameraDirection.m_fX / DirMagSqrt;
	float DirMag2 = _krCameraDirection.m_fY / DirMagSqrt;

	float CamObjMag = pow(DirVec1, 2) + pow(DirVec2, 2);

	float CamObjMagSqrt = sqrt(CamObjMag);

	float CamObjMag1 = DirVec1 / CamObjMagSqrt;
	float CamObjMag2 = DirVec2 / CamObjMagSqrt;

	float ThetaDeg = ((acos((DirMag1 * CamObjMag1) + (DirMag2 * CamObjMag2))) * (180 / PI));

	float FieldOfViewInDegrees = ((_kfFieldOfViewInRadians) * (180 / PI));

	float HalfField = FieldOfViewInDegrees / 2;

	if (ThetaDeg <= HalfField)
		return true;
	return false;
}


/***********************
* FindTriangleNormal: Normalises a triangle
* @author: Daniel Opoka
* @parameter: const TTriangle3& _krTriangle, TVector3& _rNormal
* @return: FindTriangleNormal.m_fX, FindTriangleNormal.m_fY, FindTriangleNormal.m_fZ,
********************/

TVector3& FindTriangleNormal(const TTriangle3& _krTriangle,
	TVector3& _rNormal) {
	_rNormal.m_fX = (((_krTriangle.m_v3p2.m_fY - _krTriangle.m_v3p1.m_fY) *
		(_krTriangle.m_v3p3.m_fZ - _krTriangle.m_v3p1.m_fZ)) -
		((_krTriangle.m_v3p2.m_fZ - _krTriangle.m_v3p1.m_fZ) *
		(_krTriangle.m_v3p3.m_fY - _krTriangle.m_v3p1.m_fY)));

	_rNormal.m_fY = (((_krTriangle.m_v3p2.m_fZ - _krTriangle.m_v3p1.m_fZ) *
		(_krTriangle.m_v3p3.m_fX - _krTriangle.m_v3p1.m_fX)) -
		((_krTriangle.m_v3p2.m_fX - _krTriangle.m_v3p1.m_fX) *
		(_krTriangle.m_v3p3.m_fZ - _krTriangle.m_v3p1.m_fZ)));

	_rNormal.m_fZ = (((_krTriangle.m_v3p2.m_fX - _krTriangle.m_v3p1.m_fX) *
		(_krTriangle.m_v3p3.m_fY - _krTriangle.m_v3p1.m_fY)) -
		((_krTriangle.m_v3p2.m_fY - _krTriangle.m_v3p1.m_fY) *
		(_krTriangle.m_v3p3.m_fX - _krTriangle.m_v3p1.m_fX)));

	return _rNormal;
}


/***********************
* IsSurfaceLit: Sees if a surface is lit by a light source
* @author: Lewis MacJack
* @parameter: two vectors and a triangle
* @return: boolean
********************/

bool IsSurfaceLit(const TVector3 & _krPointOnSurface, const TVector3 & _krLightSourcePosition, const TTriangle3 & _krSurface)
{
	
	TVector3 vector_add1 = Add(_krSurface.m_v3p1, _krSurface.m_v3p2, vector_add1);
	TVector3 vector_add2 = Add(vector_add1, _krSurface.m_v3p3, vector_add2);
	TVector3 vector_norm = Normalise(vector_add2, vector_norm);

	TVector3 vector_subtract1 = Subtract(_krLightSourcePosition, _krPointOnSurface, vector_subtract1);
	float d = DotProduct(vector_norm, vector_subtract1);
	
	if ((d > 0) && (d < 180)) {
		return true;
	}
	else {
		return false;
	}
}

/***********************
* RotateTriangleAroundPoint: Rotates a triangle around a point
* @author: Jason Kristanto
* @parameter: const TTriangle2& _krTriangle, const float _kfRotAngleInRadians, const TVector2& _krRotAroundPoint, TTriangle2& _rRotatedTriangle
* @return: triangle object
********************/

TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle, const float _kfRotAngleInRadians, const TVector2& _krRotAroundPoint, TTriangle2& _rRotatedTriangle)
{

	float xPoint1b = ((_krTriangle.m_v2p1.m_fX - _krRotAroundPoint.m_fX)*cos(_kfRotAngleInRadians)) + ((_krTriangle.m_v2p1.m_fY - _krRotAroundPoint.m_fY)*sin(_kfRotAngleInRadians));

	float yPoint1b = ((_krTriangle.m_v2p1.m_fX - _krRotAroundPoint.m_fX)*sin(_kfRotAngleInRadians)) - ((_krTriangle.m_v2p1.m_fY - _krRotAroundPoint.m_fY)*cos(_kfRotAngleInRadians));

	float xPoint1Result = _krRotAroundPoint.m_fX + xPoint1b;

	float yPoint1Result = _krRotAroundPoint.m_fY - yPoint1b;

	float xPoint2b = ((_krTriangle.m_v2p2.m_fX - _krRotAroundPoint.m_fX)*cos(_kfRotAngleInRadians)) + ((_krTriangle.m_v2p2.m_fY - _krRotAroundPoint.m_fY)*sin(_kfRotAngleInRadians));

	float yPoint2b = ((_krTriangle.m_v2p2.m_fX - _krRotAroundPoint.m_fX)*sin(_kfRotAngleInRadians)) - ((_krTriangle.m_v2p2.m_fY - _krRotAroundPoint.m_fY)*cos(_kfRotAngleInRadians));

	float xPoint2Result = _krRotAroundPoint.m_fX + xPoint2b;

	float yPoint2Result = _krRotAroundPoint.m_fY - yPoint2b;

	float xPoint3b = ((_krTriangle.m_v2p3.m_fX - _krRotAroundPoint.m_fX)*cos(_kfRotAngleInRadians)) + ((_krTriangle.m_v2p3.m_fY - _krRotAroundPoint.m_fY)*sin(_kfRotAngleInRadians));

	float yPoint3b = ((_krTriangle.m_v2p3.m_fX - _krRotAroundPoint.m_fX)*sin(_kfRotAngleInRadians)) - ((_krTriangle.m_v2p3.m_fY - _krRotAroundPoint.m_fY)*cos(_kfRotAngleInRadians));

	float xPoint3Result = _krRotAroundPoint.m_fX + xPoint3b;

	float yPoint3Result = _krRotAroundPoint.m_fY - yPoint3b;

	_rRotatedTriangle.m_v2p1.m_fX = xPoint1Result;
	_rRotatedTriangle.m_v2p1.m_fY = yPoint1Result;

	_rRotatedTriangle.m_v2p2.m_fX = xPoint2Result;
	_rRotatedTriangle.m_v2p2.m_fY = yPoint2Result;

	_rRotatedTriangle.m_v2p3.m_fX = xPoint3Result;
	_rRotatedTriangle.m_v2p3.m_fY = yPoint3Result;

	return _rRotatedTriangle;
}





