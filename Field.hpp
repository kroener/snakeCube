#ifndef Field_hpp
#define Field_hpp

using namespace std;


class Field
{
  public:
      Field(int l,int t, int h);
      ~Field();
      int setElement(int i, int j, int k);
      int removeElement(int i,int j, int k);
      int getmaxx();
      int getminx();
      int getmaxy();
      int getminy();
      int getmaxz();
      int getminz();
      int fixDomain(int xmin, int xmax,int ymin, int ymax, int zmin, int zmax);      
  private:
      int wx;
      int wy;
      int wz;
      int* field;
      int k;
      int l;
      int m;
      int maxx;
      int minx;
      int maxy;
      int miny;
      int maxz;
      int minz;
      int lowestx;
      int lowesty;
      int lowestz;
      int fixedDomain;
};

#endif