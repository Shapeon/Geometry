#include "geometry.h" 


TVector3& Add(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;

	return _rResultant;
}
 