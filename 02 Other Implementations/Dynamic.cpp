#include<iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int NextIndex;
    int capacity; //Total size of the array

    public:
        DynamicArray() /// Contructor
        {
            data = new int[1];
            NextIndex = 0;
            capacity = 1;
        }

        /// Parametrize Constructor
        DynamicArray(int c)
        {
            data = new int[c];
            NextIndex = 0;
            capacity = c;
        }

        //Deep copy Constructor
        DynamicArray(DynamicArray const &d)
        {
            this->NextIndex = d.NextIndex;
            this->capacity = d.capacity;
            // this->data = d.data; ///This is Shallow copy
            //Deep copy
            this->data = new int[d.capacity];
            for(int i = 0; i < d.NextIndex; i++)
            {
                this->data[i] = d.data[i];
            }
        }
         /// Overloading assignment operator
         void operator=(DynamicArray const &d)
         {
            this->NextIndex = d.NextIndex;
            this->capacity = d.capacity;
            // this->data = d.data; ///This will create a  Shallow copy

            //Deep copy
            this->data = new int[d.capacity];
            for(int i = 0; i < d.NextIndex; i++)
            {
                this->data[i] = d.data[i];
            }
         }




        void add(int element)
        {
            if(NextIndex == capacity)
            {
                int *newData = new int[capacity + 1];
                for(int i = 0; i < capacity; i++)
                {
                    newData[i] = data[i];
                }

                delete []data;
                data = newData;
                capacity = (capacity + 1);
            }

            data[NextIndex] = element;
            NextIndex++;
        }

        int getElement(int i) const
        {
            if(i >= 0 && i < NextIndex)
            {
                return data[i];
            }
            else
            {
                return -1;
            }
        }

        void add(int element, int i)
        {
            if(i < NextIndex)
            {
                data[i] = element;
            }
            else if(i == NextIndex)
            {
                add(element);
            }
            else
            {
                return;
            }
        }

        void print() const
        {
            for(int i = 0; i < NextIndex; i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }

        int getCapacity() const
        {
            return capacity;
        }

        ///Sum of Array
        int sum()
        {
            int s = 0;
            for(int i = 0; i < NextIndex; i++)
            {
                s += data[i];
            }
            return s;
        }

        /// Getting sum of Specific number of arrays
        int sum(int start, int stop)//Starting and stopping Index
        {
            if((start < stop) && (start < NextIndex) && (stop < NextIndex))
            {
                int s = 0;
                for(int i = start; i <= stop; i++)
                {
                    s += data[i];
                }
                return s;
            }
            else
            {
                return -1;
            }
        }
};

