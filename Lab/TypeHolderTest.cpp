// To compile with dumping record layout:
// $ clang++ -o variadic-tuple -Xclang -fdump-record-layouts variadic-tuple.cpp
//           -Wall -g -std=c++11
#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

template <class... Ts> struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
  tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {}

  T tail;
};

template <size_t, class> struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
  typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
  typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};

template <size_t k, class... Ts>
typename std::enable_if<
    k == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
get(tuple<Ts...>& t) {
  return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
    k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
get(tuple<T, Ts...>& t) {
  tuple<Ts...>& base = t;
  return get<k - 1>(base);
}

template< typename T >
class Zero
{
public:
	typedef T type;
};


// template< int, typename... Arguments >
// class TypeHolder;

// template< typename ExposedType, typename... Arguments >
// class TypeHolder< 0, ExposedType, Arguments... >
// {
// public:
//     typedef ExposedType m_type;
// };

// template< int NumberOfArguments, typename ExposedType, typename... Arguments >
// class TypeHolder
// {
// public:

// 	TypeHolder() { std::cout << "Bozo" << std::endl; }

//     // Create a typedef of the current exposed type
//     typedef typename TypeHolder< NumberOfArguments - 1, Arguments... >::m_type m_type;
// };

template <class... Ts> struct tuple1 {
	typedef void type;
};

template <class T, class... Ts>
struct tuple1<T, Ts...> : tuple1<Ts...> {
  tuple1() : tuple1<Ts...>() { T temp = 76.7273; std::cout << temp << std::endl; }

  typedef T type;
};

template <size_t k, class... Ts>
typename tuple1<Ts...>::type get1( tuple1<Ts...> m ) {
  typename m.type m;
  return ( m );
}


// template <size_t k, class... Ts>
// typename std::enable_if<
//     k == 0, typename tuple1<Ts...>::type>::type
// get1() {
//   typename tuple1<Ts...>::type m;
//   return ( m );
// }

// template <size_t k, class T, class... Ts>
// typename std::enable_if<
//     k != 0, typename tuple1<T, Ts...>::type>::type
// get1() {
//   return get1<k - 1, Ts...>();
// }

int main() {
  tuple<double, uint64_t, const char*> t1(12.2, 42, "big");

  std::cout << "0th elem is " << get<0>(t1) << "\n";
  std::cout << "1th elem is " << get<1>(t1) << "\n";
  std::cout << "2th elem is " << get<2>(t1) << "\n";

  get<1>(t1) = 103;

  std::cout << "1th elem is " << get<1>(t1) << "\n";

  typename elem_type_holder<1, tuple<double, int, const char*>>::type foo;
  std::cout << typeid(foo).name() << "\n";


  typename Zero< const char* >::type lol = "Lol";
  std::cout << lol << std::endl;

  tuple1< int, double > m;

  std::cout << get1< 1 >() << std::endl;

  return 0;
}

