#ifndef Element_hpp
#define Element_hpp

using namespace std;


class Element
{
  public:
      Element();
      ~Element();
      int setType(int t);
      int setInVector(int v);
      int fixElement(int v);
      int next();
      int getOutVector();
  private:
      int updateOutVectorList();
      int invector;
      int outvector;
      int* vectorlist;
      int vectorlistpointer; 
      int elementType; //0 strait, 1 corner , 2 free-element
      int fixed;
};

#endif