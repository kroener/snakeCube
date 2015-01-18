#include <iostream>
#include <stdlib.h> 
#include "Snake.hpp"
#include "Element.hpp"
#include "Field.hpp"

using namespace std;

int main(int argc , char* argv[])
{
 if(argc==2){ 
    cerr<<"Initialize snake..."<<endl;
    //two possible king_snake cubes:
    //2: 4x4x4 search for king snake
    //   use setDomain() to choose starting point
    //   no error checking, please check values...
    //3: 3x3x3 king snake
    //4: 4x4x4 king snake
    int num=atoi(argv[1]);
    Snake king_snake(num);
    if(num==3)
      king_snake.setDomain(0,3,0,3,0,3);
    cerr<<"Solve..."<<endl;
    king_snake.solve();
    cerr<<"Finished!"<<endl;
 }
 else{cerr<<"Usage:"<<argv[0]<<" case\n2=find snake for 4x4x4\n3=solve 3x3x3 snake\n=4 solve 4x4x4 snake\n";}
 return 0;
}
