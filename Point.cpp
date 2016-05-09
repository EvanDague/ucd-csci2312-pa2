#include "Point.h"

#include <iostream>
#include <sstream>
using namespace std;

namespace Clustering{
  
  unsigned int Point::__idGen;
  
  Point::Point(int dim):
    __dim(dim)
  {
    __values = new double[__dim];
    __id = ++__idGen;
    for(int i = 0; i < dim; i++){
      __values[i] = 0;
    }
  }
  
  Point::Point(int dim, double *value):
    __dim(dim)
  {
    __values[dim];
    __values = new double[__dim];
    __id = ++__idGen;
    for(int i = 0; i < dim; i++){
      __values[i] = 0;
    }
  }
  
  // Big three: cpy ctor, overloaded operator=, dtor
  Point::Point(const Point & copy){
    double value;
        
    __id = copy.getId();
    __dim = copy.getDims();
    __values = new double[__dim];
    for(int i = 0; i < __dim; i++){
      __values[i] = copy.__values[i];
    }
  }
  
  Point& Point::operator=(const Point & a){
    for(int i = 0; i < a.getDims(); i++){
      __values[i] = a.getValue(i);
    }
    
    return *this;
  }
  
  Point::~Point(){
    delete[] __values;
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
  double Point::distanceTo(const Point &a) const{
      double dist = 0;
      
      for(int i = 0; i < a.getDims(); i++){
          dist += (pow(__values[i] - a.__values[i],2));
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
      __values[i] = value;
    }
  }
  
  Point& Point::operator/=(double num){
    int dim = getDims();
    double value;
    
    for(int i = 0; i < dim; i++){
      value = getValue(i) / num;
      __values[i] = value;
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
      return __values[index];
  }
  
  // Friends
  Point& operator+=(Point & a, const Point & b){
    if(a.getDims() == b.getDims()){
          for(int i = 0; i < a.getDims(); i++){
              a[i] += b.getValue(i);
          }
      }
    return a;
  }
  
  Point& operator-=(Point & a, const Point & b){
    if(a.getDims() == b.getDims()){
          for(int i = 0; i < a.getDims(); i++){
              a[i] -= b.getValue(i);
          }
    }
    return a;
  }
  
  const Point operator+(const Point & a, const Point & b){
    Point holder(a.getDims());
    
    if(a.getDims() == b.getDims()){
          for(int i = 0; i < a.getDims(); i++){
              holder[i] = a.getValue(i) + b.getValue(i);
          }
     }
    return holder;
  }
  
  const Point operator-(const Point & a, const Point & b){
    Point holder(a.getDims());
    
    if(a.getDims() == b.getDims()){
          for(int i = 0; i < a.getDims(); i++){
              holder[i] = a.getValue(i) - b.getValue(i);
          }
      }
    return holder;
  }
  
  bool operator==(const Point & a, const Point & b){
    if(a.getDims() != b.getDims()){
      return false;
    }
    
    for(int i = 0; i < a.__dim; i++){
      if(a.__values[i] != b.__values[i]){
        return false;
      }
    }
    
    return true;
  }
  
  bool operator!=(const Point & a, const Point & b){
    if(a.getDims() != b.getDims()){
      return true;
    }
    
    for(int i = 0; i < a.__dim; i++){
      if(a.__values[i] != b.__values[i]){
        return true;
      }
    }
    
    return false;
  }
  
  bool operator<(const Point & a, const Point & b){
    double adist, bdist;
    for(int i = 0; i < a.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    for(int i = 0; i < b.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    
    return bdist < adist;
  }
  
  bool operator>(const Point &a , const Point & b){
    double adist, bdist;
    for(int i = 0; i < a.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    for(int i = 0; i < b.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    
    return bdist > adist;
    }
  
  bool operator<=(const Point &a , const Point & b){
    double adist, bdist;
    
    for(int i = 0; i < a.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    for(int i = 0; i < b.getDims(); i++){
      bdist += b.getValue(i) * b.getValue(i);
    }
    
    return bdist >= adist;
  }
  
  bool operator>=(const Point & a, const Point & b){
    double adist, bdist;
    for(int i = 0; i < a.getDims(); i++){
      adist += a.getValue(i) * a.getValue(i);
    }
    for(int i = 0; i < b.getDims(); i++){
      bdist += b.getValue(i) * b.getValue(i);
    }
    
    return bdist <= adist;
    }

  std::ostream &operator<<(std::ostream & outData, const Point & a){
      for(int i = 0; i < a.getDims(); i++){
          outData << a.__values[i] << ", ";
      }
      return outData;
  }
  
  std::istream &operator>>(std::istream & inData, Point & a){
    string holder;
    double d;
    
    for(int i = 0; i < a.__dim; i++)
    {
        getline(inData, holder, ',');
        std::stringstream input(holder);
        input>>d;
        a.__values[i] = d;
    }
    return inData;
  }
}
