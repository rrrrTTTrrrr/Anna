// #include <iostream> 
// #include <type_traits>

// using namespace std;


// class Test final
// {
// public:
// 	virtual ~Test();
// private:
// 	int y, u, s, o, l, p;
// 	double ss,sss,ssss,sssssss;
// };  //  class Test


// struct Foo : Test
// {
// 	Foo();

// 	//char padding[256];

// 	Test tt;
// };

// class Foo2
// {
// 	Foo2();
// 	virtual ~Foo2();

// 	//char padding[256];

// 	Test tt;

// 	class Unique
// 	{};

// 	virtual void uuuuu(Unique*);
// };

// int main()  
// {

// 	try
//     {

//     	std::cout << std::is_polymorphic<Test>::value << std::endl;
//     	std::cout << sizeof(Test) << std::endl;
//     	std::cout << sizeof(Foo) << std::endl;
//     	std::cout << sizeof(Foo2) << std::endl;

//     }
//     catch ( const exception& stdException )
//     {
//     	cout << stdException.what() << endl;
//     }

//     return ( 0 );
// }


#include <iostream>
#include <type_traits>

template<class T>
decltype(T* p;dynamic_cast<void*>(p), std::true_type{}) is_polymorphic2_test(T* p);

template<class T>
std::false_type is_polymorphic2_test(...);

template<class T>
using is_polymorphic2 = decltype(is_polymorphic2_test<T>(nullptr));

struct A {};
struct B { virtual ~B(); };

int main() {
    std::cout << is_polymorphic2<A>::value << '\n'; // Outputs 0.
    std::cout << is_polymorphic2<B>::value << '\n'; // Outputs 1.
}