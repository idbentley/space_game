#include "Vec2.h"

/*
 * Constructors.
 */
Vec2::Vec2(){
	vector[0] = 0.0f;
	vector[1] = 0.0f;
}

Vec2::Vec2(float x, float y){
	vector[0] = x;
	vector[1] = y;
}

Vec2::Vec2(const Vec2& copy){
	vector[0] = copy.vector[0];
	vector[1] = copy.vector[1];
}

//Destructors
Vec2::~Vec2(){}

Vec2 Vec2::operator+ (const Vec2& second) const{
	Vec2 temp = Vec2(second.vector[0]+vector[0], second.vector[1]+vector[1]);
	return temp;
}

Vec2 Vec2::operator- (const Vec2& second) const{
	Vec2 temp = Vec2(second.vector[0]-vector[0], second.vector[1]-vector[1]);
	return temp;
}

Vec2 Vec2::operator* (float m) const{
	Vec2 temp = Vec2(vector[0]*m, vector[1]*m);
	return temp;
}

Vec2& Vec2::operator=(const Vec2& v){
	vector[0] = v.vector[0];
	vector[1] = v.vector[1];
	return *this;
}

float& Vec2::operator[](const int i){
	return vector[i];
}

float Vec2::operator[](const int i) const{
	return vector[i];
}

bool Vec2::operator<(const Vec2& v) const{
	return this->mag() < v.mag();
}

bool Vec2::operator>(const Vec2& v) const{
	return this->mag() > v.mag();
}

float Vec2::dot(const Vec2& v) const{
	return vector[0]*v.vector[0] + vector[1]*v.vector[1];
}
//returns the distance from this vector to v.
float Vec2::dist(const Vec2& v) const{
	return sqrt(pow((vector[0]-v.vector[0]), 2) + pow((vector[1]-v.vector[1]), 2));
}
//returns a version of this vector rotated theta radians
Vec2 Vec2::rotate(float theta) const{
	Vec2 temp = Vec2((*this)[0]*cos(theta)+(*this)[1]*sin(theta), -(*this)[0]*sin(theta)+(*this)[1]*cos(theta));
	return temp;

}
//returns a version of the vector translated by x and y
Vec2 Vec2::translate(float x, float y) const{
	Vec2 temp = Vec2(x+(*this)[0], y+(*this)[1]);
	return temp;
}
//Returns a normalized version of this vector.
Vec2 Vec2::normalize() const{
	float f = this->mag();
	Vec2 ret = (*this)*(1/f);
	ret[2] = 1.0f;
	return ret;
}
//Magnitude
float Vec2::mag() const{
	return this->dist(Vec2(0, 0));
}

/*
 * Static Functions
 */

//Compares two vectors and returns the smaller of the two.
Vec2 Vec2::min(Vec2 v1, Vec2 v2){
	if(v1 > v2)
		return v2;
	else
		return v1;
}
//Compares two vectors and returns the larger of the two.
Vec2 Vec2::max(Vec2 v1, Vec2 v2){
	if(v1 < v2)
		return v2;
	else
		return v1;
}

ostream& operator<<(ostream& o, const Vec2 v){ 
	o << "[ " << v[0] << ", " << v[1] <<  "]"; 
	return o;
}
