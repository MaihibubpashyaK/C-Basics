#include <iostream>

using namespace std;

class stud{
public:
   int roll;
   void print()
   {

       cout<<"roll no is "<<roll;
   }


};

int main()
{
   class stud s;
  s.roll=12;
  s.print();
    return 0;
}
