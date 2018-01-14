#include <iostream>
#include "test.h"
#include "geometry.h"

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

	if ((testResultant.m_fX == desiredResultant.m_fX) && (testResultant.m_fY == desiredResultant.m_fY) && (testResultant.m_fZ == desiredResultant.m_fZ)) {
		std::cout << "SUCCESS" << std::endl;
	}
	else {
		std::cout << "FAILURE" << std::endl;
	}

	
}
