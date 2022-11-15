// vector test program.
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
#include "Vector.h"

void testFillConstructor();
void testCopyConstructor();
void testAssignment1();
void testAssignment2();
void testResize1();
void testResize2();

// Determines if two vectors are equal.
bool equal(vector& left, std::vector< int >& right);

const unsigned int number = 1000;

int main()
{
    for (unsigned int seed = 1; seed <= 5; seed++)
    {
        srand(seed);
        testFillConstructor();
    }

    for( unsigned int seed = 1; seed <= 5; seed++ )
    {
       srand( seed );
       testCopyConstructor();
    }

   for( unsigned int seed = 1; seed <= 5; seed++ )
   {
       srand( seed );
       testAssignment1();
   }

    for( unsigned int seed = 1; seed <= 5; seed++ )
    {
       srand( seed );
       testAssignment2();
    }

    for (unsigned int seed = 1; seed <= 5; seed++)
    {
        srand(seed);
        testResize1();
    }

    for (unsigned int seed = 1; seed <= 5; seed++)
    {
        srand(seed);
        testResize2();
    }

    system("pause");
}

void testFillConstructor()
{
    unsigned int numErrors = number;
    unsigned int length;
    for (unsigned int i = 0; i < number; i++)
    {
        length = rand() % 200;
        vector vector1(length);  
        std::vector< int > vector2(length);  //和STL裡面的vector類別比較，看兩個class寫得有沒有一樣

        if (equal(vector1, vector2))
            numErrors--;
    }//跑完這個迴圈一次，vector1就結束了，所以會呼叫destructor

    cout << "There are " << numErrors << " errors.\n";
}

void testCopyConstructor()
{
   unsigned int numErrors = number;
   unsigned int length;
   int value;
   for( unsigned int i = 0; i < number; i++ )
   {
      vector vector1;
      std::vector< int > vector2;
      length = rand() % 200;
      for( unsigned int j = 0; j < length; j++ )
      {
         value = 1 + rand() % 99;
         vector1.push_back( value );
         vector2.push_back( value );
      }

      vector vector3( vector1 );  //calls copy constructor

      std::vector< int > vector4( vector2 );  //calls copy constructor

      if( equal( vector3, vector4 ) )
         numErrors--;
   }  //解構掉vector 1和vector 3

   cout << "There are " << numErrors << " errors.\n";
}

void testAssignment1()
{
   vector vector3;
   std::vector< int > vector4;

   unsigned int numErrors = number;
   unsigned int length;
   int value;
   for( unsigned int i = 0; i < number; i++ )
   {
      vector vector1;
      std::vector< int > vector2;
      length = rand() % 200;
      for( unsigned int j = 0; j < length; j++ )
      {
         value = 1 + rand() % 99;
         vector1.push_back( value );
         /*cout << vector1.element(j) << ' ';*/
         vector2.push_back( value );

      }

      vector3.assign( vector1 ); // vector3 = vector1
      /*for (int i = 0; i < vector1.size(); i++)
      {
          if (vector3.element(i) != vector1.element(i))
          {
              cout << i << ' ';
              system("pause");
          }
      }*/
      vector4 = vector2;

      if (equal(vector3, vector4))
          numErrors--;      
   }

   cout << "There are " << numErrors << " errors.\n";
}

void testAssignment2()
{
   unsigned int numErrors = number;
   unsigned int length;
   for( unsigned int i = 0; i < number; i++ )
   {
      vector vector1;
      length = rand() % 200;
      for (unsigned int j = 0; j < length; j++)
          vector1.push_back(1 + rand() % 99);

      vector vector2;
      length = rand() % 200;
      for( unsigned int j = 0; j < length; j++ )
         vector2.push_back( 1 + rand() % 99 );

      size_t capacity1 = vector1.capacity();

      int *oldAddress = vector1.begin(); // oldAddress = vector1.myFirst

      vector1.assign( vector2 );

     /*檢查陣列是否傳對值:
     for (int i = 0; i < vector1.size(); i++)
      {
          if (vector1.begin()[i] != vector2.begin()[i])
          {
              cout << ' ' << i;
              system("pause");
          }  
          else
              cout << vector1.begin()[i];
      }
      然後在assign隨便更改一個元素的值*/

      if( vector2.size() > capacity1 )
         numErrors--;
      else
         if( vector1.begin() == oldAddress )
            numErrors--;
   }

   // vector2.size() == oldAddress if and only if
   // the array pointed by vector1.myFirst before
   // the excution of vector1.assign( vector2 ) is the same as
   // the array pointed by vector1.myFirst after
   // the excution of vector1.assign( vector2 )
   // i.e., there is no memory allocation during the excution of
   // vector1.assign( vector2 )

   cout << "There are " << numErrors << " errors.\n";
}

void testResize1()
{
    vector vector1;
    std::vector< int > vector2;

    unsigned int numErrors = number;
    unsigned int length;
    for (unsigned int i = 0; i < number; i++)
    {
        length = rand() % 200;
        vector1.resize(length);  //裡面的值都是0
        /*cout << vector1.size() << ' ' << vector1.capacity() << ' ' << vector1.begin()[i] << ' ';*/
        vector2.resize(length);
        /*cout << vector2.size()<<' ' << vector2.capacity()<< ' ' << vector2.begin()[i] << endl;*/

        if (equal(vector1, vector2))
            numErrors--;
    }

    cout << "There are " << numErrors << " errors.\n";
}

void testResize2()
{
    vector v;

    unsigned int numErrors = number;
    unsigned int length; int n = 0;
    for (unsigned int i = 0; i < number; i++)
    {
        size_t oldCapacity = v.capacity();

        int* oldAddress = v.begin(); // oldAddress = v.myFirst

        length = rand() % 200;
        v.resize(length);

        int* newAddress = v.begin(); // newAddress = v.myFirst

        if (length > oldCapacity)
        {
            if (newAddress != oldAddress) 
                numErrors--;
        }
        else 
            if (newAddress == oldAddress)
                numErrors--;
    }

    // newAddress == oldAddress if and only if
    // the array pointed by v.myFirst before
    // the excution of v.resize( length ) is the same as
    // the array pointed by v.myFirst after
    // the excution of v.resize( length )
    // i.e., there is no memory allocation during the excution of
    // v.resize( length )

    cout << "There are " << numErrors << " errors.\n";
}

// Determines if two vectors are equal.
bool equal(vector& left, std::vector< int >& right)
{
    if (left.capacity() != right.capacity())
        return false;

    if (left.size() != right.size())
        return false;

    for (size_t i = 0; i < right.size(); ++i)
        if (left.element(i) != right[i])
            return false;  

    return true;
}
