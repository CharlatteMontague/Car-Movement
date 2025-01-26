#include "MathVector.h"
#include "Input.h"
#include "State.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
//add more libraries and header files that you use


// 1) uncomment this part since zyBooks use it.
int main(int argc, const char* argv[]) {
    if (argc != 3)
    {
        std::cout << "./project3 inputFile outputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    ///////////////////// uncomment above before submitting on zyBooks /////////////////
//2) Comment the next 3 lines below

/*int main(void) {
    string inputFileName = "inputFile1.txt";
    string outputFileName = "outFile1.txt";*/
    
    ifstream inputFile;
    inputFile.open(inputFileName);
    
    ofstream outputFile;
    outputFile.open(outputFileName);
    
    double velocity;
    double dotDelta;
    char comma; //for comma in files
    double timeValue = 0.0;
    
    State data;
    Input inputs;
    
    double newX;
    double newY;
    double newDelta;
    double newTheta;
    
    if(!inputFile.is_open()){
        cout << "Error opening input file" << endl;
    }
    if(!outputFile.is_open()){
        cout << "Error opening output file" << endl;
    }
    
   /*README
   For inputFile 1, set the initial state (values of x, y, delta, theta) to (0,0,0.125,0)
   For inputFile 2, set the initial state (values of x, y, delta, theta) to (0,0,0.076,0)
   For inputFile 3 and 4, set the initial state (values of x, y, delta, theta) to (0,0,0,0)*/
   
   //initialize state depending on file number//
   if(inputFileName == "inputFile1.txt"){
       data = State(0.0, 0.0, 0.125, 0.0);
   }
   else if(inputFileName == "inputFile2.txt"){
       data = State(0, 0, 0.076, 0);
   }
   else{
       data = State(0, 0, 0, 0);
   }
   
   //scans velocity and delta dot from file//
   while(inputFile >> velocity >> comma >> dotDelta){
       inputs = Input(velocity, dotDelta);
      
       //print values in output file//
       outputFile << fixed << setprecision(4);
       outputFile << timeValue << "," << data.getX() << "," << data.getY() << "," << data.getDelta() << "," << data.getTheta() << "," << inputs.getV()  << "," << inputs.getDeltaDot() << endl;
       
       //calculates new values//
       newX = (data.getX()) + 0.1 * inputs.getV() * cos(data.getDelta()) * cos(data.getTheta()); 
       newY = (data.getY()) + 0.1 * inputs.getV() * cos(data.getDelta()) * sin(data.getTheta());
       newDelta = (data.getDelta()) + 0.1 * inputs.getDeltaDot();
       newTheta = (data.getTheta()) + 0.025 * inputs.getV() * sin(data.getDelta());
       
       //sets new variables//
       data.setX(newX);
       data.setY(newY);
       data.setDelta(newDelta);
       data.setTheta(newTheta);
       timeValue += 0.1;
   }
   
   //last line
   outputFile << timeValue << "," << data.getX() << "," << data.getY() << "," << data.getDelta() << "," << data.getTheta();

    return 0;   
}
