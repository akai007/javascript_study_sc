#include <iostream>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

struct Ractangle
{
  int length;
  int breadth;
};

int main()
{

  cout<<"static object refence"<<endl;
  Ractangle r = {10, 5};
  cout<<r.length<<"\t"<<r.breadth<<endl;

  Ractangle *refR = &r;
  cout<<(*refR).length<<"\t"<<refR->breadth<<endl;

  cout<<endl<<"dynamic object refence"<<endl;
  Ractangle *refRD = (Ractangle *)malloc(sizeof(Ractangle));
  Ractangle *refRDPP;
  refRDPP = new Ractangle;
  // Ractangle *rdPP = new Ractangle({20, 4});
  refRD->length = 3;
  (*refRD).breadth = 20;
  refRDPP->length = 30;
  (*refRDPP).breadth = 3;

  cout<<(*refRD).length<<"\t"<<refRD->breadth<<endl;
  cout<<(*refRDPP).length<<"\t"<<refRDPP->breadth<<endl;
  
  
  return 0;
}
