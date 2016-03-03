#include "Cluster.h"

//using namespace Clustering;


namespace Clustering{
Cluster::Cluster(){
    __size = 0;
    __points->point = 0;
    __points->next = NULL;
}

// The big three: cpy ctor, overloaded operator=, dtor
Cluster::Cluster(const Cluster & copy){
    __size = copy.getSize();
}

Cluster &Cluster::operator=(const Cluster & copy){
    __size = copy.getSize();
}

Cluster::~Cluster(){
}

// Getters/setters
int Cluster::getSize() const{ // TODO add to the requirements
    return __size;
}

// Set functions: They allow calling c1.add(c2.remove(p));
void Cluster::add(const Point & a){ // TODO add asc order to the requirements
    
}

const Point &Cluster::remove(const Point & a){
    
}

bool Cluster::contains(const Point & a){
    LNodePtr check;
    bool test = false;
    
    while(test != true && check->next != NULL){
        for(int i = 0; i < getSize(); i++){
            if(check->point.getValue(i) == a.getValue(i)){
                test = true;
            }
            else{
                test = false;
                i = getSize();
            }
        }
        check = check->next;
    }
    
    return test;
}

// Overloaded operators

// Members: Subscript
const Point &Cluster::operator[](unsigned int index) const{ // notice: const
    
}

// Members: Compound assignment (Point argument)
Cluster &Cluster::operator+=(const Point & a){
    
}

Cluster &Cluster::operator-=(const Point & a){
    
}

// Members: Compound assignment (Cluster argument)
Cluster &Cluster::operator+=(const Cluster & a){ // union
    
}

Cluster &Cluster::operator-=(const Cluster & a){ // (asymmetric) difference
    
}

// Friends: IO
std::ostream &operator<<(std::ostream & outData, const Cluster & a){
    
}

std::istream &operator>>(std::istream & inData, Cluster & a){
    
}

// Friends: Comparison
bool operator==(const Cluster & a, const Cluster & b){
    
}

bool operator!=(const Cluster & a, const Cluster & b){
    
}

// Friends: Arithmetic (Cluster and Point)
const Cluster operator+(const Cluster & a, const Point & b){
    
}

const Cluster operator-(const Cluster & a, const Point & b){
    
}

// Friends: Arithmetic (two Clusters)
const Cluster operator+(const Cluster & a, const Cluster & b){ // union

}

const Cluster operator-(const Cluster & a, const Cluster & b){ // (asymmetric) difference

}
}
