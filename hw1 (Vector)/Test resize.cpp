#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
   vector< int > v;
   for( unsigned int length = 0; length < 16; ++length )
   {
      v.resize( length );
      cout << setw( 4 ) << length << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
   }
   cout << endl;

   {
       vector< int > v(0);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//0,0 1,1

   {
       vector< int > v(0);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(2);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//0,0 2,2
 
   {
       vector< int > v(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//1,1 1,1

   {
       vector< int > v(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(2);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//1,1 2,2

   {
       vector< int > v(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(3);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//1,1 3,3
  
   {
       vector< int > v(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//1,1 4,4

   {
       vector< int > v(2);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//2,2 1,2

   {
       vector< int > v(2);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(3);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//2,2 3,3

   {
       vector< int > v(2);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//2,2 4,4

   {
       vector< int > v(3);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(1);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;//3,3 1,3

   {
       vector< int > v(3);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//3,3 4,4
   cout << endl;

   {
       vector< int > v(3);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(5);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//3,3 5,5
   cout << endl;

   {
       vector< int > v(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(5);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//4,4 5,6
   cout << endl;

   {
       vector< int > v(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//4,4 6,6
   cout << endl;

   {
       vector< int > v(4);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(9);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//4,4 9,9
   cout << endl;

   {
      vector< int > v( 5 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 4 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//5,5 4,5

   {
      vector< int > v( 5 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 6 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//5,5 6,7

   {
       vector< int > v(5);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(7);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//5,5 7,7
   
   {
      vector< int > v( 5 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 8 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//5,5 8,8

   {
       vector< int > v(5);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(13);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(5);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 5,6

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(7);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6-9

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(8);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 8,9
   cout << endl;

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(9);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 9,9
   cout << endl;

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(10);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 10,10
   cout << endl;

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(11);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 11,11
   cout << endl;

   {
       vector< int > v(6);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(15);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//6,6 15,15
   cout << endl;

   {
       vector< int > v(7);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(8);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//7,7 8,10
   cout << endl;

   {
       vector< int > v(7);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(11);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//7,7 11,11
   cout << endl;

   {
       vector< int > v(7);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(12);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//7,7 12,12
   cout << endl;

   {
       vector< int > v(8);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(9);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//8,8 9,12
   cout << endl;

   {
       vector< int > v(8);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(13);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;

   {
       vector< int > v(8);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(14);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }
   cout << endl;


   {
      vector< int > v( 9 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 8 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }

   {
       vector< int > v(9);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(10);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//9,9 10,13
   cout << endl;

   {
      vector< int > v( 9 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 12 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//9,9 12,13
  
   {
       vector< int > v(9);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(14);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//9,9 14,14
   cout << endl;
   {
      vector< int > v( 9 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 16 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//9,9 16,16

   {
      vector< int > v( 10 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 8 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//10,10 8,10

   {
       vector< int > v(10);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;
       v.resize(11);
       cout << setw(4) << v.size() << setw(4) << v.capacity() << endl << endl;
   }//10,10 11,15
   cout << endl;

   {
      vector< int > v( 10 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 12 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//10,10 12,15

   {
      vector< int > v( 10 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;
      v.resize( 16 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;
   }//10,10,16,16

   {
      vector< int > v( 10 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;//10,10
      v.resize(11);
      cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;//11,15
      v.resize( 12 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;//12,15
      v.resize( 14 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl;//14,15
      v.resize(15);
      cout << setw(4) << v.size() << setw(4) << v.capacity() << endl;//15,15
      v.resize( 16 );
      cout << setw( 4 ) << v.size() << setw( 4 ) << v.capacity() << endl << endl;//16,22
   }

   {
      vector< int > v1( 10, 3 );
      vector< int > v2( 8, 5 );
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl;
      cout << setw( 4 ) << v2.size() << setw( 4 ) << v2.capacity() << endl;
      v1 = v2;
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl << endl;
   }//shrink

   {
      vector< int > v1( 10, 3 );
      vector< int > v2( 12, 5 );
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl;
      cout << setw( 4 ) << v2.size() << setw( 4 ) << v2.capacity() << endl;
      v1 = v2;
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl << endl;//12,15
   }

   {
      vector< int > v1( 10, 3 );
      vector< int > v2( 16, 5 );
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl;
      cout << setw( 4 ) << v2.size() << setw( 4 ) << v2.capacity() << endl;
      v1 = v2;
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl << endl;
   }

   {
      vector< int > v1( 6, 3 );
      vector< int > v2( 5, 5 );
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl;
      cout << setw( 4 ) << v2.size() << setw( 4 ) << v2.capacity() << endl;
      v1 = v2;
      cout << setw( 4 ) << v1.size() << setw( 4 ) << v1.capacity() << endl << endl;
   }

   system( "pause" );
}