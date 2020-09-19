#include <iostream> 

using namespace std;


 template<class T>
 class A
 {
   public:
     A(T a = 0): m_a(a) {}

     void Print() { cout << m_a << endl; }
 
     template<class U>
     friend A<U> foo(A<U>& a);
 
   private:
     T m_a;
 };
 
 template<class T>
 A<T> foo(A<T>& a)
 {
   return a;
 }

int main()  
{

	try
	{

		A<int> a( 8 );

		a.Print();

		foo< double >( (A<double>)a ).Print();





	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
