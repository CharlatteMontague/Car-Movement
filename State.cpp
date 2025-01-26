#include "State.h"


//see input.cpp to implement this one BUT with number of elements = 4
//since a state is a 1-D array with 4 values: x, y, delta, theta
State::State(): MathVector(4){
}

State::State(double x, double y, double delta, double theta): MathVector(4){
   this->elements.at(0) = x;
   this->elements.at(1) = y;
   this->elements.at(2) = delta;
   this->elements.at(3) = theta;
}


//return a value at index 0 of elements
double State::getX(){
    return this->elements.at(0);
}

//return a value at index 1 of elements
double State::getY(){
    return this->elements.at(1);
}


//return a value at index 2 of elements
double State::getDelta(){
    return this->elements.at(2);
}


//return a value at index 3 of elements
double State::getTheta(){
    return this->elements.at(3);
}


//use newX to set index 0 of elements
void State::setX(double newX){
    this->elements.at(0) = newX; 
}


//use newY to set index 1 of elements
void State::setY(double newY){
    this->elements.at(1) = newY;
}


//if newDelta is between [-0.5236,0.5236], use newDelta to set index 2 of elements
//if newDelta < -0.5236,  set index 2 of elements to -0.5236
//if newDelta > 0.5236,  set index 2 of elements to 0.5236
void State::setDelta(double newDelta){
   if((newDelta <= DELTA_MAX) && (newDelta >= DELTA_MIN)){
       this->elements.at(2) = newDelta;
   }
   else if(newDelta > DELTA_MAX){
       this->elements.at(2) = DELTA_MAX;
   }
   else{
       this->elements.at(2) = DELTA_MIN;
   }
}


//First, make sure that newTheta is between [0, 2π)
//then use it to set index 3 of elements
void State::setTheta(double newTheta){
    while((newTheta < 0) || (newTheta >= HEADING_MAX)){
        if((newTheta < 0)){
            newTheta = newTheta + HEADING_MAX;
        }
        else if (newTheta >= HEADING_MAX){
            newTheta = newTheta - HEADING_MAX;
        }
    }
    this->elements.at(3) = newTheta;
}

