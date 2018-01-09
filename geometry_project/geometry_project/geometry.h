enum EIntersections { INTERSECTION_NONE, INTERSECTION_ONE, INTERSECTION_TWO };

struct TVector2 { float m_fX;      float m_fY; };

struct TTriangle2 { TVector2 m_v2p1;     TVector2 m_v2p2;     TVector2 m_v2p3; };

struct TRectangle { TVector2 m_v2p1;     TVector2 m_v2p2; };

struct TVector3 { float m_fX;      float m_fY;      float m_fZ; };

struct TTriangle3 { TVector3 m_v3p1;     TVector3 m_v3p2;     TVector3 m_v3p3; };

struct T3DLine {
	TVector3 m_v3q; //point on the line     TVector3 m_v3v; //direction vector along the line }; 

struct TCircle { TVector2 m_v2center;     float m_fRadius; };







