
#include<iostream>
using namespace std;
#include "Dynamic.cpp"

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    /*


    DynamicArray d2(d1);//OUR copy constructor gets called

    DynamicArray d3;
    d3 = d1;

    d1.add(100,0);
    d1.print();
    d2.print();
    d3.print();

    DynamicArray d4(5); //Parametrize costructor gets called
    d4.getCapacity();

    */
    cout<<"Element at 0: " <<d1.getElement(0)<<endl;
    d1.print();
    cout<<"D1 size: " <<d1.getCapacity()<<endl;

    cout<<d1.sum()<<endl;
    cout<<d1.sum(2,4)<<endl;///You've to pass the **start index** and the **end/stop index**

return 0;
}
