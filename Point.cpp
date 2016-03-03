#include "Point.h"

namespace Clustering{
  
Point::Point(int dim){
  __dim = dim;
  for(int i = 0; i < dim; i++){
    setValue(i, 0); 
  }
}

Point::Point(int dim, double *value){
  __dim = dim;
  for(int i = 0; i < dim; i++){
    setValue(i, *value);
  }
}

// Big three: cpy ctor, overloaded operator=, dtor
Point::Point(const Point & copy){
    double value;
    
  __id = copy.getId();
  __dim = copy.getDims();
  for(int i = 0; i < __dim; i++){
    setValue(i,copy.getValue(i));
  }
}

Point& Point::operator=(const Point & a){
  for(int i = 0; i < getDims(); i++){
    setValue(i, a.getValue(i));
  }
}

Point::~Point(){
}

// Accessors & mutators
int Point::getId() const{
  return __id;
}

int Point::getDims() const{
  return __dim;
}

void Point::setValue(int num, double values){
  __values[num] = values;
}

double Point::getValue(int num) const{
  return __values[num];
}

// Functions
double Point::distanceTo(const Point & a) const{
    double dist;
    
    for(int i = 0; i < a.getDims(); i++){
        dist += (pow(a.getValue(i),2));
    }
    
    return sqrt(dist);
}

// Overloaded operators

// Members
Point& Point::operator*=(double num){ // p *= 6; p.operator*=(6)
  int dim = getDims();
  double value;
  
  for(int i = 0; i < dim; i++){
    value = getValue(i) * num;
    setValue(i, value);
  }
}

Point& Point::operator/=(double num){
  int dim = getDims();
  double value;
  
  for(int i = 0; i < dim; i++){
    value = getValue(i) / num;
    setValue(i, value);
  }
}

const Point Point::operator*(double num) const{ // prevent (p1 * 2) = p2;
  int dim = getDims();
  double value;
  
  Point newVal(dim);
  
  for(int i = 0; i < dim; i++){
    value = getValue(i) * num;
    newVal.setValue(i, value);
  }
  
  return newVal;
}

const Point Point::operator/(double num) const{ // p3 = p2 / 2;
  int dim = getDims();
  double value;
  
  Point newVal(dim);
  
  for(int i = 0; i < dim; i++){
    value = getValue(i) / num;
    newVal.setValue(i, value);
  }
  
  return newVal;
}

double& Point::operator[](int index){
    __values[index];
}

// Friends
Point& operator+=(Point & a, const Point & b){
  if(a.getDims() == b.getDims()){
        for(int i = 0; i < a.getDims(); i++){
            a.setValue(i, a.getValue(i) + b.getValue(i));
        }
    }
}

Point& operator-=(Point & a, const Point & b){
  if(a.getDims() == b.getDims()){
        for(int i = 0; i < a.getDims(); i++){
            a.setValue(i, a.getValue(i) - b.getValue(i));
        }
    }
}

const Point operator+(const Point & a, const Point & b){
    if(a.getDims() == b.getDims()){
        for(int i = 0; i < a.getDims(); i++){
            return a.getValue(i)+b.getValue(i);
        }
    }
}

const Point operator-(const Point & a, const Point & b){
if(a.getDims() == b.getDims()){
        for(int i = 0; i < a.getDims(); i++){
            return a.getValue(i)-b.getValue(i);
        }
    }
}

bool operator==(const Point & a, const Point & b){
  if(a.distanceTo(a) == b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

bool operator!=(const Point & a, const Point & b){
  if(a.distanceTo(a) != b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

bool operator<(const Point & a, const Point & b){
  if(a.distanceTo(a) < b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

bool operator>(const Point &a , const Point & b){
  if(a.distanceTo(a) > b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

bool operator<=(const Point &a , const Point & b){
  if(a.distanceTo(a) <= b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

bool operator>=(const Point & a, const Point & b){
  if(a.distanceTo(a) >= b.distanceTo(b)){
    return true;
  }
  else{
    return false;
  }
}

std::ostream &operator<<(std::ostream & outData, const Point & a){
    for(int i = 0; i < a.getDims(); i++){
        outData << a.getValue(i);
    }
}

std::istream &operator>>(std::istream & inData, Point & a){
  double value = 0;
  int i = 0;
  
  while(inData){
    inData >> value;
    a.setValue(i, value);
    i++;
  }
}
}
