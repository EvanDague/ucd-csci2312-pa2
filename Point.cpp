Point::Point(int dim){
  __dim = dim;
  __values = 0;
}

Point::Point(int dim, double *value){
  __dim = dim;
  __values = value;
}

// Big three: cpy ctor, overloaded operator=, dtor
Point::Point(const Point & copy){
  __id = copy.getID();
  __dims = copy.getDims();
  __values = copy.getValue();
}

Point::Point &operator=(const Point &);

Point::~Point(){
}

// Accessors & mutators
int Point::getId() const{
  return __id;
}

int Point::getDims() const{
  return __dim;
}

void Point::setValue(int id, double values){
  __values = values
  __id = id;
}

double Point::getValue(int) const{
  return __values;
}

// Functions
double Point::distanceTo(const Point &) const;

// Overloaded operators

// Members
Point Point::&operator*=(double num){ // p *= 6; p.operator*=(6)
  num = num * getValue();
  setValue(num);
}

Point Point::&operator/=(double num){
  num = getValue() / num;
  setValue(num);
}

const Point::Point operator*(double num) const{ // prevent (p1 * 2) = p2;
  
}

const Point::Point operator/(double) const; // p3 = p2 / 2;

double Point::&operator[](int index);

// Friends
friend Point::Point &operator+=(Point & a, const Point & b){
  a.setValue(a.getValue() + b.getValue());
}

friend Point::Point &operator-=(Point & a, const Point & b){
  a.setValue(a.getValue() - b.getValue());
}

friend const Point::Point operator+(const Point & a, const Point & b){
  a.setValue(a.getValue() + b.getValue());
}

friend const Point::Point operator-(const Point & a, const Point & b){
    a.setValue(a.getValue() - b.getValue());
}

friend bool Point::operator==(const Point & a, const Point & b){
  if(a.getValue() == b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend bool Point::operator!=(const Point &, const Point &){
  if(a.getValue() != b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend bool Point::operator<(const Point &, const Point &){
  if(a.getValue() < b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend bool Point::operator>(const Point &, const Point &){
  if(a.getValue() > b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend bool Point::operator<=(const Point &, const Point &){
  if(a.getValue() <= b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend bool Point::operator>=(const Point &, const Point &){
  if(a.getValue() >= b.getValue()){
    return true;
  }
  else{
    return false;
  }
}

friend Point::std::ostream &operator<<(std::ostream & outData, const Point & a){
  outData << a.getValue();
}

friend Point::std::istream &operator>>(std::istream & inData, Point & a){
  double value = 0;
  inData >> value;
  a.setValue(value);
}
