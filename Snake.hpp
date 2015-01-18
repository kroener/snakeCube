#ifndef Snake_hpp
#define Snake_hpp
#include "Element.hpp"
#include "Field.hpp"

using namespace std;


class Snake
{
  public:
      Snake(int n);
      ~Snake();
      int solve();
      int setDomain(int xmin,int xmax,int ymin,int ymax,int zmin,int zmax);
 
  private:
      int printSolution();
      int printSnake();
      int printProgress();
      Field* Cube;
      Element* Elements;
      int numberofelements;
      int wx;
      int wy;
      int wz;
      int* elementsType;
      int* iv;
      int ce;
      int* ax;
      int* ay;
      int* az;
      unsigned long long iteration;
      int output;
      int numofsol;
      int minElement;
      int maxElement;
      int minElement2;
      int maxElement2;
      int lastMinx;
      int lastMiny;
      int lastMinz;
      int lastMaxx;
      int lastMaxy;
      int lastMaxz;
      int findSnake;
};

#endif