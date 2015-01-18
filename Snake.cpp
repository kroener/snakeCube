#include <iostream>
#include "Element.hpp"
#include "Field.hpp"
#include "Snake.hpp"

using namespace std;


Snake::Snake(int n)
{
  findSnake=0;
  iteration=0;output=1000000;
  numofsol=0;
  minElement=0;maxElement=0;
  minElement2=0;maxElement2=0; 
  lastMinx=0;lastMiny=0;lastMinz=0;
  lastMaxx=0;lastMaxy=0;lastMaxz=0;
  if(n==4){
  wx=4;wy=4;wz=4;
  numberofelements=wx*wy*wz;
  elementsType=new int[numberofelements];
  elementsType[ 0]=0; elementsType[ 1]=1; elementsType[ 2]=0; elementsType[ 3]=0;
  elementsType[ 4]=1; elementsType[ 5]=1; elementsType[ 6]=1; elementsType[ 7]=1;
  elementsType[ 8]=1; elementsType[ 9]=1; elementsType[10]=1; elementsType[11]=1;
  elementsType[12]=1; elementsType[13]=1; elementsType[14]=0; elementsType[15]=1;
  elementsType[16]=1; elementsType[17]=0; elementsType[18]=0; elementsType[19]=1;
  elementsType[20]=1; elementsType[21]=1; elementsType[22]=1; elementsType[23]=0;
  elementsType[24]=0; elementsType[25]=1; elementsType[26]=0; elementsType[27]=1;
  elementsType[28]=1; elementsType[29]=1; elementsType[30]=1; elementsType[31]=1;
  elementsType[32]=1; elementsType[33]=0; elementsType[34]=1; elementsType[35]=0;
  elementsType[36]=1; elementsType[37]=1; elementsType[38]=1; elementsType[39]=1;
  elementsType[40]=1; elementsType[41]=1; elementsType[42]=1; elementsType[43]=1;
  elementsType[44]=1; elementsType[45]=0; elementsType[46]=1; elementsType[47]=1;
  elementsType[48]=0; elementsType[49]=1; elementsType[50]=1; elementsType[51]=0;
  elementsType[52]=1; elementsType[53]=1; elementsType[54]=0; elementsType[55]=0;
  elementsType[56]=1; elementsType[57]=1; elementsType[58]=1; elementsType[59]=0;
  elementsType[60]=1; elementsType[61]=1; elementsType[62]=0; elementsType[63]=0;
  }
  else if(n==3){
  wx=3;wy=3;wz=3;
  numberofelements=wx*wy*wz;
  elementsType=new int[numberofelements];
  elementsType[ 0]=0; elementsType[ 1]=0; elementsType[ 2]=1; 
  elementsType[ 3]=1; elementsType[ 4]=1; elementsType[ 5]=0; 
  elementsType[ 6]=1; elementsType[ 7]=1; elementsType[ 8]=0; 
  elementsType[ 9]=1; elementsType[10]=1; elementsType[11]=1;
  elementsType[12]=0; elementsType[13]=1; elementsType[14]=0;
  elementsType[15]=1; elementsType[16]=1; elementsType[17]=1; 
  elementsType[18]=1; elementsType[19]=0; elementsType[20]=1; 
  elementsType[21]=0; elementsType[22]=1; elementsType[23]=0;
  elementsType[24]=1; elementsType[25]=0; elementsType[26]=0;
  }
  else if(n==2){
  findSnake=1;
  wx=4;wy=4;wz=4;
  numberofelements=wx*wy*wz;
  elementsType=new int[numberofelements];
  for(int i=0; i<numberofelements; i++)
    elementsType[i]=2;
  }  
  Cube=new Field(wx,wy,wz);
  Elements=new Element[numberofelements];
  for(int i=0; i<numberofelements; i++)
   Elements[i].setType(elementsType[i]);

  iv=new int[numberofelements];
  ce=0;
  ax=new int[numberofelements];
  ay=new int[numberofelements];
  az=new int[numberofelements];
  for(int i=0; i<numberofelements; i++) {iv[i]=0;ax[i]=0;ay[i]=0;az[i]=0;}  
}

Snake::~Snake()
{
  delete[] iv;
  delete[] ax;
  delete[] ay;
  delete[] az;
  delete[] elementsType;
}

int Snake::solve()
{
  int onlyOne=0;
  int m,n;
  int looping=1;
  int oldn=0;
  int step_back=0;
    
if(wx==4 && !findSnake)
{
  Cube->setElement(0, 0, 0);
  Cube->setElement(1, 0, 0);
  Cube->setElement(1, 1, 0);
  
  ax[0]=0;ay[0]=0;az[0]=0;iv[0]=0;
  ax[1]=1;ay[1]=0;az[1]=0;iv[1]=0;
  ax[2]=1;ay[2]=1;az[2]=0;iv[2]=1;
  n=3;
  m=2;
  ce=3;
}
else if(wx==3 && !findSnake)
{
  Cube->setElement(0, 0, 0);
  Cube->setElement(1, 0, 0);
  Cube->setElement(2, 0, 0);
  
  ax[0]=0;ay[0]=0;az[0]=0;iv[0]=0;
  ax[1]=1;ay[1]=0;az[1]=0;iv[1]=0;
  ax[2]=2;ay[2]=0;az[2]=0;iv[2]=0;
  Elements[2].fixElement(1);
  n=3;
  m=2;
  ce=3;
}
else if(wx==4 && findSnake)
{
  Cube->setElement(0, 0, 0);
  ax[0]=0;ay[0]=0;az[0]=0;iv[0]=0;
  n=1;
  m=0;
  ce=1;
  onlyOne=0;
  //Cube->fixDomain(0,3,0,3,0,3);  
}
//else if(wx==3 && findSnake)
//{
// 
//}
  
  while(looping)
  {
   if(oldn<n)
   {
     Elements[n-1].setInVector(iv[n-1]);
     oldn=n;
     ce=n;
     if(ce<minElement)minElement=ce;
     if(ce<minElement2)minElement2=ce;
     if(ce>maxElement)maxElement=ce;  
     if(ce>maxElement2)maxElement2=ce;
   }
   else
   {
     step_back=Elements[n-1].next();
     if(step_back)
     {
       Cube->removeElement(ax[n-1],ay[n-1],az[n-1]);
       ax[n-1]=0;
       ay[n-1]=0;
       az[n-1]=0;
       n--;
       oldn=n;
       ce=n;
       if(ce<minElement)minElement=ce;
       if(ce<minElement2)minElement2=ce;
       if(ce>maxElement)maxElement=ce;  
       if(ce>maxElement2)maxElement2=ce;
       if(n==m)looping=0;
     }
   }
   if(!step_back)
   {
    int nextout=Elements[n-1].getOutVector();
    int nx=ax[n-1];
    int ny=ay[n-1];
    int nz=az[n-1];
    if(nextout==0)nx++;
    if(nextout==1)ny++;
    if(nextout==2)nz++;
    if(nextout==3)nx--;
    if(nextout==4)ny--;
    if(nextout==5)nz--;
    int passt=Cube->setElement(nx,ny,nz);
    if(passt)
    { 
      iteration++;
      ax[n]=nx;
      ay[n]=ny;
      az[n]=nz;
      iv[n]=nextout;
      n++;
      ce=n;
      if(n==numberofelements)
      {
        if(!findSnake){printSolution();}
        else{printSnake();}
        if(onlyOne)looping=0;
        Cube->removeElement(ax[n-1],ay[n-1],az[n-1]);
        ax[n-1]=0;
        ay[n-1]=0;
        az[n-1]=0;
        n--;
        oldn=n;
        ce=n;
        if(ce<minElement)minElement=ce;
        if(ce<minElement2)minElement2=ce;
        if(ce>maxElement)maxElement=ce;  
        if(ce>maxElement2)maxElement2=ce;
      }
    }
   }
   else
   {
    step_back=0;
   } 
   printProgress();
  }
  cerr <<"\r" <<"Finished: Placed "<<iteration<<" cubes to find "<<numofsol<< " solutions\n";
  return 0;
}

int Snake::printSolution()
{
 cout <<"#"<<iteration<<" ["<<minElement<<"->"<<maxElement<<"]"<<endl;
 for(int i=0; i<numberofelements; i++)
  cout << ax[i]<<" "<<ay[i]<<" "<<az[i]<<endl;
 numofsol++;
 minElement=ce;
 maxElement=ce;  
 return 0;
}

int Snake::printSnake()
{
 cout <<numofsol<<" 0";
 for(int i=1;i<numberofelements-1;i++)
 {
  if(2*(ax[i]-ax[i-1])==ax[i+1]-ax[i-1] &&
     2*(ay[i]-ay[i-1])==ay[i+1]-ay[i-1] && 
     2*(az[i]-az[i-1])==az[i+1]-az[i-1])
  {
    cout<<"0";
  }
  else
  {
    cout <<"1";
  }
 }
 cout<<"0"<<endl;
 numofsol++;
 return 0;
}

int Snake::printProgress()
{
 if(iteration%output==0)
 {
  cerr << "\r" << iteration<<": "<<ce<<"("<<numofsol<<")["<<minElement2<<"->"<<maxElement2<<"] ("<<Cube->getminx()<<"->"<<Cube->getmaxx()<<","<<Cube->getminy()<<"->"<<Cube->getmaxy()<<","<<Cube->getminz()<<"->"<<Cube->getmaxz()<<")   "<< flush;
  minElement2=ce;
  maxElement2=ce;
 }     
 return 0;
}

int Snake::setDomain(int xmin,int xmax,int ymin,int ymax,int zmin,int zmax)
{
  Cube->fixDomain(xmin,xmax,ymin,ymax,zmin,zmax);
  return 0;
}
