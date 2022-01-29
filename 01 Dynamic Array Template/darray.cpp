#include<iostream>
using namespace std;
template <class T>
class Darray
{
    T *data;
    int NextIndex;
    int capacity; //Total size of the array

    public:
        Darray() /// Contructor
        {
            data = new T[5];
            NextIndex = 0;
            capacity = 5;
        }

        /// Parametrize Constructor initialize array with zeros
        Darray(int c)
        {
            data = new T[c];
            for(int i = 0; i < c; i++){
                data[i] = 0;
            }
            NextIndex = 0;
            capacity = c;
        }

        //Deep copy Constructor
        Darray(Darray const &d)
        {
            this->NextIndex = d.NextIndex;
            this->capacity = d.capacity;
            // this->data = d.data; ///This is Shallow copy
            //Deep copy
            this->data = new T[d.capacity];
            for(int i = 0; i < d.NextIndex; i++)
            {
                this->data[i] = d.data[i];
            }
        }

        //Destructor
        ~Darray()
        {
            delete [] data;
        }


        ///Overloading []
        T& operator [](int index)
        {
            T *newdata;                           ///  Pointer to the new array
            if(index >= capacity)                   ///Is element in the array?
            {
                newdata = new T[index + 10];     ///Allocate bigger array
                for(int i = 0; i < NextIndex; i++)
                    {
                        newdata[i] = data[i];       ///Copy old values
                    }
                ///Initializing remainder

                capacity = index + 10;              ///Set length
                delete [] data;                   ///delete old array
                data = newdata;                 ///reassign new array
            }
            if(index > NextIndex)               /// Set nextIndex past Index
            {
                NextIndex = index + 1;

            }
            return *(data + index);             ///A reference to the element
        }


         /// Overloading assignment operator
         void operator=(Darray const &d)
         {
            this->NextIndex = d.NextIndex;
            this->capacity = d.capacity;
            // this->data = d.data; ///This will create a  Shallow copy

            //Deep copy
            this->data = new T[d.capacity];
            for(int i = 0; i < d.NextIndex; i++)
            {
                this->data[i] = d.data[i];
            }
         }


        void add(int element)
        {
            if(NextIndex == capacity)
            {
                int *newData = new T[2*capacity];
                for(int i = 0; i < capacity; i++)
                {
                    newData[i] = data[i];
                }

                delete []data;
                data = newData;
                capacity = (capacity  * 2);
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

        void add(T element, int i)
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
        T sum()
        {
            int s = 0;
            for(int i = 0; i < NextIndex; i++)
            {
                s += data[i];
            }
            return s;
        }

        /// Getting sum of Specific number of arrays
        T sum(int start, int stop)//Starting and stopping Index
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
