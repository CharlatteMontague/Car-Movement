#include "Input.h"

Input::Input(): MathVector(2){
}

Input::Input(double v, double deltaDot): MathVector(2){
    this->elements.at(0) = v;
    this->elements.at(1) = deltaDot;
}


double Input::getDeltaDot() { return elements.at(1); }

double Input::getV() { return elements.at(0); }
