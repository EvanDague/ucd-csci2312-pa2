#include "Cluster.h"

#include <iostream>
using namespace std;

namespace Clustering{
    
    LNode::LNode(const Point &p, LNodePtr n) :
    point(p), next(n)
    {
    }
    
    Cluster::Cluster():
    __size(0)
    {        
        __points=nullptr;
    }
    
    // The big three: cpy ctor, overloaded operator=, dtor
    Cluster::Cluster(const Cluster & copy){
        for(int i = 0; i < copy.__size; i++){
            add(copy[i]);
        }
    }
    
    Cluster &Cluster::operator=(const Cluster & copy){
        Cluster *holder;
        
        for(int i = 0; i < copy.__size; i++){
            holder->add(copy[i]);
        }
        
        return *holder;
    }
    
    Cluster::~Cluster(){
        LNodePtr next=__points;
        LNodePtr curr = nullptr;
        while (next != nullptr){
            curr = next->next;
            delete next;
            next = curr;
        }
    }
    
    // Getters/setters
    int Cluster::getSize() const{ // TODO add to the requirements
        return __size;
    }
    
    // Set functions: They allow calling c1.add(c2.remove(p));
    void Cluster::add(const Point & a){ // TODO add asc order to the requirements
        LNodePtr prev = this->__points, curr = this->__points;
        LNodePtr newNode = new LNode(a, nullptr);

        if(curr == nullptr){
            this->__points = newNode;
            __size++;
            return;
        }
        
        while(curr != nullptr){
            if(curr->point < newNode->point){
                prev = curr;
                curr = curr->next;
            }
            else if(prev == curr){
                this->__points = newNode;
                newNode->next = curr;
                __size++;
                return;
            }
            else{
                prev->next = newNode;
                newNode->next = curr;
                __size++;
                return;
            }
        }
    }
    
    const Point &Cluster::remove(const Point & a){
        LNodePtr prev, curr = this->__points, next = this->__points->next;
        
        while(this->__points->next != nullptr){
            if(curr->point == a){
                delete curr;
                __size--;
                return a;
            }
            else{
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
        return a;
    }
    
    bool Cluster::contains(const Point & a){
        LNodePtr check;
        bool test = false;
        
        while(test != true && check->next != nullptr){
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
        LNodePtr holder = __points;
        
        for(int i = 0; i < index; i++){
            holder = holder->next;
        }
        
        return holder->point;
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
        LNodePtr holder1, holder2;
        
        if(a.__size != b.__size){
            return false;
        }
        else{
            holder1 =  b.__points;
            holder2 = a.__points;
            for(int i = 0; i < b.__size; i++){
                if(holder1 != holder2){
                    return false;
                }
                else{
                    holder1 = holder1->next;
                    holder2 = holder2->next;
                }
            }
        }
        return true;
    }
    
    bool operator!=(const Cluster & a, const Cluster & b){
        LNodePtr holder1, holder2;
        
        if(a.__size != b.__size){
            return true;
        }
        else{
            holder1 =  b.__points;
            holder2 = a.__points;
            for(int i = 0; i < b.__size; i++){
                if(holder1 != holder2){
                    return true;
                }
                else{
                    holder1 = holder1->next;
                    holder2 = holder2->next;
                }
            }
        }
        return false;
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
