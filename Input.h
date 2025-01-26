//
//  Input.h
//

#ifndef Input_h
#define Input_h

#include <stdio.h>
#include "MathVector.h"

class Input : public MathVector {
public:
    Input( );
    Input( double v, double delta );
    double getV( );
    double getDeltaDot( );
};

#endif /* Input_h */
