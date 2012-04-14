#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using namespace std;
class Vec2{
	private:
		float vector[2];
	public:
		Vec2();
		Vec2(float , float );
		Vec2(const Vec2& );
		~Vec2();
		/* Procedure Prototypes */
		Vec2& operator=(const Vec2&);
		Vec2 operator-(const Vec2&) const;
		Vec2 operator+(const Vec2&) const;
		Vec2 operator*(float) const;
		float operator[](const int ) const;
		float& operator[](const int );
		bool operator<(const Vec2&) const;
		bool operator>(const Vec2&) const;
		float dot(const Vec2&) const;	
		float dist(const Vec2&) const;
		Vec2 rotate(float theta) const;
		Vec2 translate(float , float ) const;
		Vec2 normalize() const;
		float mag() const;
		static Vec2 max(Vec2 , Vec2 );
		static Vec2 min(Vec2 , Vec2 );
};

//cout vec2's
ostream& operator<<(ostream& o, const Vec2 v);

#endif
