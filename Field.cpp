#include "Field.hpp"

using namespace std;

Field::Field(int l,int t, int h)
{
      wx=l;
      wy=t;
      wz=h;
      fixedDomain=0;
      lowestx=-wx/2;
      lowesty=-wy/2;
      lowestz=-wz/2;
      minx=0;maxx=0;
      miny=0;maxy=0;
      minz=0;maxz=0;
      field=new int[wx*wy*wz]; 
      for(int i=0; i<wx*wy*wz;i++)field[i]=0;
}

Field::~Field()
{
      delete[] field; 
}

int Field::setElement(int i, int j, int k)
{
  if(i-minx<4 && maxx-i<4 && j-miny<4 && maxy-j<4 && k-minz<4 && maxz-k<4 &&
     i>=lowestx && j>=lowesty && k>=lowestz)
  {
    if(i<minx)minx=i;
    if(j<miny)miny=j;
    if(k<minz)minz=k;
    if(i>maxx)maxx=i;
    if(j>maxy)maxy=j;
    if(k>maxz)maxz=k;
    if(i<0){i+=4;}
    if(j<0){j+=4;}
    if(k<0){k+=4;} 
    int nx=i%4;
    int ny=j%4;
    int nz=k%4;
    if(field[nx+wx*ny+wx*wy*nz]==0)
      field[nx+wx*ny+wx*wy*nz]=1;
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
  return 1;
}

int Field::removeElement(int i,int j, int k)
{
    int check=0;
    if(i==maxx)check+=1;
    if(i==minx)check+=1<<1;
    if(j==maxy)check+=1<<2;
    if(j==miny)check+=1<<3;
    if(k==maxz)check+=1<<4;
    if(k==minz)check+=1<<5; 
    if(i<0){i+=4;}
    if(j<0){j+=4;}
    if(k<0){k+=4;} 
    int nx=i%4;
    int ny=j%4;
    int nz=k%4;
    field[nx+wx*ny+wx*wy*nz]=0;
    if(check!=0 && !fixedDomain)
    {
     if(1 & check)
     {
       int x=maxx;
       if(x<0)x+=4;
       int frei=0;
       for(int y=0; y<4; y++)
        for(int z=0; z<4; z++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       maxx--;
     }
     if((1<<1) & check)
     {
       int x=minx;
       if(x<0)x+=4;
       int frei=0;
       for(int y=0; y<4; y++)
        for(int z=0; z<4; z++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       minx++;
     }
     if((1<<2) & check)
     {
       int y=maxy;
       if(y<0)y+=4;
       int frei=0;
       for(int x=0; x<4; x++)
        for(int z=0; z<4; z++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       maxy--;
     }       
     if((1<<3) & check)
     {
       int y=miny;
       if(y<0)y+=4;
       int frei=0;
       for(int x=0; x<4; x++)
        for(int z=0; z<4; z++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       miny++;
     }       
     if((1<<4) & check)
     {
       int z=maxz;
       if(z<0)z+=4;
       int frei=0;
       for(int x=0; x<4; x++)
        for(int y=0; y<4; y++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       maxz--;
     }       
     if((1<<5) & check)
     {
       int z=minz;
       if(z<0)z+=4;
       int frei=0;
       for(int x=0; x<4; x++)
        for(int y=0; y<4; y++)
         if(field[x+wx*y+wx*wy*z]!=0)
          {frei=1;break;}
       if(frei==0)
       minz++;
     }
    }
 return 0;
}

int Field::getmaxx()
{
 return maxx;
}

int Field::getmaxy()
{
 return maxy;
}

int Field::getmaxz()
{
 return maxz;
}

int Field::getminx()
{
 return minx;
}

int Field::getminy()
{
 return miny;
}

int Field::getminz()
{
 return minz;
}

int Field::fixDomain(int xmin, int xmax,int ymin, int ymax, int zmin, int zmax)
{
 fixedDomain=1;
 minx=xmin;
 miny=ymin;
 minz=zmin;
 maxx=xmax;
 maxy=ymax;
 maxz=zmax;
 return 0; 
}