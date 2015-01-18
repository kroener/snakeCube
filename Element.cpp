//#include <ctime>
//#include <cstdlib>
#include "Element.hpp"

using namespace std;


Element::Element()
{
      fixed=0;
      invector=-1;
      outvector=-1;
      elementType=0;
      //srand(time(0));
}

Element::~Element()
{
if(elementType==1 || elementType==2)
delete[] vectorlist;
}

int Element::setType(int t)
{
  elementType=t;
  if(elementType==1)
  {
    vectorlist=new int[4];
    vectorlistpointer=0;
  }
  else if(elementType==2)
  {
    vectorlist=new int[5];
    vectorlistpointer=0;
  }
  return 0;
}

int Element::setInVector(int v)
{
  invector=v;
  if(!fixed)
   updateOutVectorList();
  return 0;
}

int Element::updateOutVectorList()
{
 int n=0;
  if(elementType==1)
  {
    for(int i=0; i<6; i++)
    {
      int temp=i-invector;
      if(temp<0)temp+=6;
      if(temp%3!=0)
      {
        vectorlist[n]=i;
        n++;
      }
    }
    outvector=vectorlist[0];
    vectorlistpointer=0;
  }
  else{
    if(elementType==0)
    {
     outvector=invector;
    }
    else{
      if(elementType==2)
      {
      vectorlist[0]=invector;
      n++;
      for(int i=0; i<6; i++)
      {
        int temp=i-invector;
        if(temp<0)temp+=6;
        if(temp%3!=0)
      {
        vectorlist[n]=i;
        n++;
      }
    }
    outvector=vectorlist[0];
    vectorlistpointer=0;
    }
  }
  } 
 return 0;
}

int Element::next()
{
  if(fixed)
  {
   return 1;
  }
  
  if(elementType==0)
  {
    return 1;
  }
  else
  {
    if(elementType==1)
    {
     vectorlistpointer++;
     if(vectorlistpointer<4)
     {
      outvector=vectorlist[vectorlistpointer];
     }
     else{
       return 1;
     }
    }
    else
    {
      if(elementType==2)
      {
        vectorlistpointer++;
        if(vectorlistpointer<5)
        {
         outvector=vectorlist[vectorlistpointer];
        }
        else{
          return 1;
        }
      }
      else
      {
        return 1;
      }
    }
  }
  return 0;
}

int Element::getOutVector(){
 return outvector;
}

int Element::fixElement(int v)
{
  fixed=1;
  outvector=v;
  return 0;
}