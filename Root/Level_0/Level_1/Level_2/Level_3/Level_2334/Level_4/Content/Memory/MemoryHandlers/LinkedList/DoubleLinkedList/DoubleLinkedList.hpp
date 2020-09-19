#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP


#include "../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  MACRO MOVE
#include "./DoubleLinkedListNode/DoubleLinkedListNode.hpp"  //  Class DoubleLinkedListNode
#include "../../../../../../../Content/Interfaces/AccessDataUsingIndices_Interface/AccessDataUsingIndices_Interface.hpp"  //  Class AccessDataUsingIndices_Interface
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Memory
    {


		// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
		// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
		// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
		// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
		//
		// Forward declarations :
		//
		//  NONE
		//



        // In C the purpose of the keyword "typedef" with structures, was to reduce to need to add the keyword "struct" with every decleration of new
        // instance of the structure. In C++ this is not needed anymore



        // Array VS Linked List :
        //
        //	Array and linked list both are used to work with multiple elements of the same kind mostly. The difference starts first of all by the 
        //	fact that an array will always be a contigous segment in memory, which means all the entires are located at the same memory location 
        //	one after the other. This has the advantage that accessing every entry is immediate ( O( 1 ) ), because every entry location is known,
        //	the third entry is 2 jumps of the pointer from the beginning of the array. The disadvantage is that there must be a long enough contigous
        //	segment in memory. Linked list as it's name implies, is a set of interconnected entries. Each entry has a pointer to the next entry 
        //	( double linked list ) and possibly to the previous one ( double linked list ). The advantage then is that each entry can be anywhere 
        //	in memory, and when the next entry is required the pointer to the next entry is used. The disadvantage is that accessing the entries 
        //	is more complicated. In the most simple linked lists, all there is to store is the address of the first entry ( the same as in the array 
        //	case ), and then all the route to the entry needs to be done ( use the pointer in the first entry to the next entry, and so on until the
        //	required entry is reached ). In very long linked lists this can take much time.
        //
        //	Beside this, the next consideration is derived from the usage. If the number of entries is known in advance then array is usually the 
        //	better choice, because the access is faster. In cases where there should be many adding and deleting of entries, then linked list is 
        //	better. This is because when an entry needs to be added, a bigger memory space is needed, and all the array should be copied to, while 
        //	in linked list all there is to do is to change the pointer to the new entry and set the new entry to point to the rest of the linked list



        // In C the purpose of the keyword "typedef" with structures, was to reduce to need to add the key word "struct" with every decleration of new instance of the
        // structure. In C++ this is not needed anymore



        // In order to parse a C++ program, the compiler needs to know whether certain names are types or not. The following example demonstrates that :
        //
        //      t * f;
        //
        // How should this be parsed? For many languages a compiler doesn't need to know the meaning of a name in order to parse and basically know what action a line of 
        // code does. In C++, the above however can yield vastly different interpretations depending on what t means. If it's a type, then it will be a declaration of a 
        // pointer f. However if it's not a type, it will be a multiplication. So the C++ Standard says at paragraph ( 3/7 ) :
        //
        // Some names denote types or templates. In general, whenever a name is encountered it is necessary to determine whether that name denotes one of these entities 
        // before continuing to parse the program that contains it. The process that determines this is called name lookup
        //
        // How will the compiler find out what a name t::x refers to, if t refers to a template type parameter? 
        //
        // x could be a static int data member that could be multiplied or could equally well be a nested class or typedef that could yield to a declaration. If a name 
        // has this property - that it can't be looked up until the actual template arguments are known - then it's called a dependent name ( it "depends" on the template 
        // parameters )
        //
        // You might recommend to just wait till the user instantiates the template:
        //
        // Let's wait until the user instantiates the template, and then later find out the real meaning of t::x * f;.
        //
        // This will work and actually is allowed by the Standard as a possible implementation approach. These compilers basically copy the template's text into an internal 
        // buffer, and only when an instantiation is needed, they parse the template and possibly detect errors in the definition. But instead of bothering the template's 
        // users (poor colleagues!) with errors made by a template's author, other implementations choose to check templates early on and give errors in the definition as 
        // soon as possible, before an instantiation even takes place
        //
        // So there has to be a way to tell the compiler that certain names are types and that certain names aren't
        //
        // The "typename" keyword :
        //
        // The answer is: We decide how the compiler should parse this. If t::x is a dependent name, then we need to prefix it by typename to tell the compiler to parse it 
        // in a certain way. The Standard says at ( 14.6/2 ) :
        //
        // A name used in a template declaration or definition and that is dependent on a template-parameter is assumed not to name a type unless the applicable name lookup 
        // finds a type name or the name is qualified by the keyword typename
        //
        // There are many names for which typename is not necessary, because the compiler can, with the applicable name lookup in the template definition, figure out how to 
        // parse a construct itself - for example with T *f;, when T is a type template parameter. But for t::x * f; to be a declaration, it must be written as typename 
        // t::x *f;. If you omit the keyword and the name is taken to be a non-type, but when instantiation finds it denotes a type, the usual error messages are emitted by 
        // the compiler. Sometimes, the error consequently is given at definition time:
        //
        // t::x is taken as non-type, but as an expression the following misses an operator between the two names or a semicolon separating them
        //
        //      t::x f;
        //
        // The syntax allows typename only before qualified names - it is therefor taken as granted that unqualified names are always known to refer to types if they do so
        //
        // A similar gotcha exists for names that denote templates, as hinted at by the introductory text.
        //
        // The "template" keyword :
        //
        // Remember the initial quote above and how the Standard requires special handling for templates as well? Let's take the following innocent-looking example :
        //
        //      boost::function< int() > f;
        //
        // It might look obvious to a human reader. Not so for the compiler. Imagine the following arbitrary definition of 
        // boost::function and f :
        //
        //      namespace boost { int function = 0; }
        //      int main() 
        //      { 
        //          int f = 0;
        //          boost::function< int() > f; 
        //      }
        //
        // That's actually a valid expression! It uses the less-than operator to compare boost::function against zero ( int() ), and then uses the greater-than operator to 
        // compare the resulting bool against f. However as you might well know, boost::function in real life is a template, so the compiler knows ( 14.2/3 ) :
        //
        // After name lookup ( 3.4 ) finds that a name is a template-name, if this name is followed by a <, the < is always taken as the beginning of a template-argument-list 
        // and never as a name followed by the less-than operator
        //
        // Now we are back to the same problem as with typename. What if we can't know yet whether the name is a template when parsing the code? We will need to insert 
        // template immediately before the template name, as specified by 14.2/4. This looks like :
        //
        //      t::template f<int>(); // call a function template
        //
        // Template names can not only occur after a :: but also after a -> or . in a class member access. You need to insert the keyword there too :
        //
        //      this->template f<int>(); // call a function template
        //
        // 
        // Dependencies :
        //
        // In template declarations some constructs have different meanings depending on what template arguments you use to instantiate the template : Expressions may have 
        // different types or values, variables may have different types or function calls might end up calling different functions. Such constructs are generally said to 
        // depend on template parameters
        //
        // The Standard defines precisely the rules by whether a construct is dependent or not. It separates them into logically different groups: One catches types, another 
        // catches expressions. Expressions may depend by their value and/or their type. So we have, with typical examples appended :
        //
        // Dependent types ( e.g: a type template parameter T )
        // Value-dependent expressions ( e.g: a non-type template parameter N )
        // Type-dependent expressions ( e.g: a cast to a type template parameter (T)0 )
        //
        // Most of the rules are intuitive and are built up recursively: For example, a type constructed as T[N] is a dependent type if N is a value-dependent expression or 
        // T is a dependent type. The details of this can be read in section ( 14.6.2/1 ) for dependent types, ( 14.6.2.2 ) for type-dependent expressions and ( 14.6.2.3 ) 
        // for value-dependent expressions.
        //
        // Dependent names
        //
        // The Standard is a bit unclear about what exactly is a dependent name. On a simple read, all it defines as a dependent name is the special case for function names 
        // below. But since clearly T::x also needs to be looked up in the instantiation context, it also needs to be a dependent name ( fortunately, as of mid C++14 the 
        // committee has started to look into how to fix this confusing definition )
        //
        // Of all the constructs that denote dependent types or expressions, a subset of them represent names. Those names are therefore "dependent names". A name can take 
        // different forms - the Standard says :
        //
        // A name is a use of an identifier ( 2.11 ), operator-function-id ( 13.5 ), conversion-function-id ( 12.3.2 ), or template-id ( 14.2 ) that denotes an entity or label 
        // ( 6.6.4, 6.1 )
        //
        // An identifier is just a plain sequence of characters / digits, while the next two are the operator + and operator type form. The last form is template-name 
        // < argument list >. All these are names, and by conventional use in the Standard, a name can also include qualifiers that say what namespace or class a name should be 
        // looked up in
        //
        // A value dependent expression 1 + N is not a name, but N is. The subset of all dependent constructs that are names is called dependent name. Function names, however, 
        // may have different meaning in different instantiations of a template, but unfortunately are not caught by this general rule 
        //
        // Dependent function names
        //
        // Not primarily a concern of this article, but still worth mentioning: Function names are an exception that are handled separately. An identifier function name is 
        // dependent not by itself, but by the type dependent argument expressions used in a call. In the example f( (T)0 ), f is a dependent name. In the Standard, this is 
        // specified at ( 14.6.2/1 ) :
        //
        // Additional notes and examples
        //
        // In enough cases we need both of typename and template. Your code should look like the following
        //
        //      template <typename T, typename Tail>
        //      struct UnionNode : public Tail {
        //      // ...
        //      template<typename U> struct inUnion {
        //      typedef typename Tail::template inUnion<U> dummy;
        //      };
        //      // ...
        //      };
        //
        // The keyword template doesn't always have to appear in the last part of a name. It can appear in the middle before a class name that's used as a scope, like in the 
        // following example
        //
        //      typename t::template iterator<int>::value_type v;
        //
        // In some cases, the keywords are forbidden, as detailed below
        //
        // On the name of a dependent base class you are not allowed to write typename. It's assumed that the name given is a class type name. This is true for both names 
        // in the base-class list and the constructor initializer list :
        //
        //      template <typename T>
        //      struct derive_from_Has_type : /* typename */ SomeBase<T>::type 
        //      { };
        //
        // In using-declarations it's not possible to use template after the last ::, and the C++ committee said not to work on a solution.
        //
        //      template <typename T>
        //      struct derive_from_Has_type : SomeBase<T> {
        //      using SomeBase<T>::template type; // error
        //      using typename SomeBase<T>::type; // typename *is* allowed
        //      };



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple instances of the same type. The instances will not be stored in contigous memory space, but rather
		//		as seperated nodes connected through pointers. Each node will have a pointer to the next node in the list. This allows making changes
		//		without the needs to copy large amout of contigous memory spaces, in other words changes in this platform cost very little in terms
		//		of performance. This is a double linked list which means the current node knows about the next node and previous node, and therefore 
		//		passes on this platform are only in any direction
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//		3. Template arguments :
		//
		//			1. Type - any type
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename AnyType >
		class DoubleLinkedList : public AccessDataUsingIndices_Interface< AnyType >
		{
		public:


            // Create a type definition for this object
            using SelfType = DoubleLinkedList< AnyType >;

            // Create a type definition for the nodes of this object
            using NodeType = DoubleLinkedListNode< AnyType >;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
		    //
		    //  Description :
			//
			//		Default Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
 			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
 			//
 			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline DoubleLinkedList();


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a reference to the data that will stored in the first node of the double linked list
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline DoubleLinkedList( const AnyType& data );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          data - a constant reference to a sequential platform instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The given sequential platform instance is ready 
            //      2. The given sequential platform instance size should be larger then 0
            //      3. 
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            explicit inline DoubleLinkedList( const AccessDataUsingIndices_Interface< AnyType >& data );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
            //      wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
            //      to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
            //
            //              1. data - a reference to the data that will stored in the first node of the double linked list
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            explicit inline DoubleLinkedList( const Tuple< const AnyType& >& arguments );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, to allow creating a random generated instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
            //          2. rangeForSize - this will be used to limit the possible size of the random instance
            //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
            explicit inline DoubleLinkedList( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
			//
			//  Required arguments :
			//
		    //		User information needed :
			//
			//			other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2
			//
			inline DoubleLinkedList( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Reset
			//		5. State
			//
			ObjectInfrastructure_MACRO( DoubleLinkedList< AnyType > )


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			other - a reference to the instance that should be swaped
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline void Swap( SelfType& other );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a reference to the data that will stored in the first node of the double linked list
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const AnyType& data );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          data - a constant reference to a sequential platform instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The given sequential platform instance is ready 
            //      2. The given sequential platform instance size should be larger then 0
            //      3. 
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            inline void Initiate( const AccessDataUsingIndices_Interface< AnyType >& data );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
            //      This version is to allow initiating an instance with the same arguments as the parameterized constructor, just that the arguments
            //      will be wrapped in a tuple, to allow more automatic initialization of instances
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          arguments - the arguments needed to initiate an instance, only wrapped in a tuple. The arguments are :
            //
            //              1. data - a reference to the data that will stored in the first node of the double linked list
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            inline void Initiate( const Tuple< const AnyType& >& arguments );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
            //      This version is to allow initiating random instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
            //          2. rangeForSize - this will be used to limit the possible size of the random instance
            //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
            inline void Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ~DoubleLinkedList();


			// The following methods give access and manipulate the data inside this object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get the size of the double linked list
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The size of the double linked list
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            UnsignedInteger64bits Size() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add a node at the given index. This means that if a node needs to be added at index 2 then :
            //
            //          Currently the double linked list looks :
            //
            //              --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
            //              --------------  --------------  --------------  --------------  
            //
            //          After the addition :
            //
            //                                                  Added     Moved up by 1 index
            //                                                    |                |
            //              --------------  --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | New Node 2 |  | Old Node 3 |  | Old Node 4 |  ...
            //              --------------  --------------  --------------  --------------  -------------- 
            //
            //      As can be seen all the nodes that exist in the double linked list before the addition, starting from the node with the required index,
            //      will be moved one index up.
            //
            //      Note - if the node should be added to the end of the double linked list, provide as index the current size of the double linked list
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. data - a reference to the data that a copy of it should be stored in the new node
            //          2. index - the index to insert the new node
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index should be smaller or equal to the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            void AddData( UnsignedInteger64bits index, const AnyType& data );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add a number of nodes at the given index. This means that if the nodes needs to be added starting at index 2 then :
            //
            //          Currently the double linked list looks :
            //
            //              --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
            //              --------------  --------------  --------------  --------------  
            //
            //          After the addition :
            //
            //                                                  Added     Moved up by 1 index
            //                                                    |                |
            //              --------------  --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | New Node 2 |  | Old Node 3 |  | Old Node 4 |  ...
            //              --------------  --------------  --------------  --------------  -------------- 
            //
            //      As can be seen all the nodes that exist in the double linked list before the addition, starting from the node with the required index,
            //      will be moved one index up.
            //
            //      Note - if the nodes should be added to the end of the double linked list, provide as index the current size of the double linked list
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. data - a reference to a sequential platform interafce that contains the data to add
            //          2. index - the index to insert the new nodes
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index should be smaller or equal to the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
            //      2. 
            //
            void AddData( UnsignedInteger64bits index, const AccessDataUsingIndices_Interface< AnyType >& data );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to remove a node at the given index. This means that if a node needs to be removed at index 2 then :
            //
            //          Currently the double linked list looks :
            //
            //              --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
            //              --------------  --------------  --------------  --------------  
            //
            //          After the remove :
            //
            //                                           Moved down by 1 index
            //                                                     |
            //              --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  ...
            //              --------------  --------------  -------------- 
            //
            //      As can be seen all the nodes that exist in the double linked list before the removal, starting from the node with the required index,
            //      will be moved one index down.
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index to remove from it the node
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A copy of the data removed
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index is smaller then the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            AnyType RemoveData( UnsignedInteger64bits index );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to remove number of nodes starting at the given index. This means that if the nodes needs to be removed starting at index 2 then :
            //
            //          Currently the double linked list looks :
            //
            //              --------------  --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
            //              --------------  --------------  --------------  --------------  
            //
            //          After the remove :
            //
            //                                           Moved down by 1 index
            //                                                     |
            //              --------------  --------------  --------------    
            //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  ...
            //              --------------  --------------  -------------- 
            //
            //      As can be seen all the nodes that exist in the double linked list before the removal, starting from the last node to be removed index, will be 
            //      moved one index down.
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          indexOfFirstDataToRemove - the index of the first data to remove
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index is smaller then the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            void RemoveData( UnsignedInteger64bits indexOfFirstDataToRemove, UnsignedInteger64bits sizeToRemove );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get an instance with only part of the current instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. partStartingIndex - the starting index from which the part instance will start
            //          2. partSize - the size of the part instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      An instance with only the required part from this instance
            //
            //  Expectations :
            //
            //      1. The given part starting index is smaller then the instance size
            //      2. The given part starting index and size is smaller or equal to the size of the instance
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline SelfType Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare only the required part of the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. startingIndexInThisInstance - the index from to start the comparison on this instance
            //          2. other - a constant reference to an other sequential platform instance
            //          3. startingIndexInOtherInstance - the index from to start the comparison on the other instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      True if the parts are equal, and false otherwise
            //
            //  Expectations :
            //
            //      1. The given starting index in this instance should be smaller then the size of the instance
            //      2. The size of the given other instance should not be 0
            //      3. The given starting index in this instance should be smaller then the size of the instance
            //      4. The given starting index in this instance plus the size to compare must be smaller or equal to the size of the instance
            //      5. The given starting index in the other instance plus the size to compare must be smaller or equal to the size of the other instance
            //      6. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Boolean ComparePart( UnsignedInteger64bits startingIndexInThisInstance, const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits startingIndexInOtherInstance, UnsignedInteger64bits sizeToCompare ) const;


			// The following methods declare the overloaded operators for the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get a reference to the required node
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the required node
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to the required node
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index is smaller then the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual AnyType& operator[]( UnsignedInteger64bits index ) override;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get a copy of the value inside the required node
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the required node
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A constant reference to the required node
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given index is smaller then the double linked list size
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual const AnyType& operator[]( UnsignedInteger64bits index ) const override;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the this instance match the other
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a constnt reference to a sequential platform
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the 2 instances are the same
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Boolean operator==( const AccessDataUsingIndices_Interface< AnyType >& other ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the this instance does not match the other
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be compared with this object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the 2 instances are not the same
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Boolean operator!=( const AccessDataUsingIndices_Interface< AnyType >& other ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to add the content of another instance to the end of this instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          data - a reference to a sequential platform to concatenate to the end of this instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The sequential platform should be ready
            //      3. The sequential platform size should be larger then 0
            //      4. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - Class std::bad_alloc is thrown
            //      2. 
            //
            virtual AccessDataUsingIndices_Interface< AnyType >& operator+=( const AccessDataUsingIndices_Interface< AnyType >& data ) override;


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
				//
				//  Required arguments :
				//
				//		User information needed :
				//
				//			NONE
				//
				//		Information returned to the user :
				//
				//			NONE
				//
				//  Return value :
				//
				//			NONE
				//
				//  Expectations :
				//
				//		Please let the test pass lord!!
				//
				//  Possible errors :
				//
				//		It says there are no problems, which is even scarier, did I just wrote a working code??
				//
				static inline void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


 			// This object will store the memory address of the first node in the double linked list
 			NodeType* member_doubleLinkedListRoot;

 			// This object will store the number of nodes in the double linked list
 			UnsignedInteger64bits member_size;

 			// The following data members are added to make specific optimizations. The first one is to store the memory address of the last node, to allow 
 			// adding a node to the end of the double linked list without passing on all the nodes for it. The second and third are used to store the memory
 			// address and index of the last used node. This will allow first of all another starting point beside the beginning of the double linked list
 			// to find specific nodes, furthermore, it will allow passing on all the nodes, without starting each time from the root :

 			// This object will store the memory address of the last node in the double linked list
 			NodeType* member_doubleLinkedListLastNode;

 			// This object will store the last node used in the double linked list
 			mutable NodeType* member_lastUsedNode;

 			// This object will store the index of the last used node
 			mutable UnsignedInteger64bits member_lastUsedNodeIndex;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add all the sequential platform entries to this instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. node - a pointer to the node that the adding of data needs to start from
            //          2. data - a constant reference to a sequential platform
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The memory address of the last node added to double linked list
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - Class std::bad_alloc is thrown
            //      2. 
            //
            inline NodeType* AddAllTheDataStartingFromTheGivenNode__Private( NodeType* startAddingFromThisNode, const AccessDataUsingIndices_Interface< AnyType >& data );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to delete all the node from the double linked list
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void DeleteAllNodes__Private();


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
			//		the beginning or from the last used node, and take that path
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required node
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
	        //      The memory address of the required node
			//
			//  Expectations :
			//
			//		1. The given index is smaller then the double linked list size
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			NodeType* TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( UnsignedInteger64bits index ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
			//		required amount of nodes to the required node
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - the memory address of the node to start from
			//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The memory address of the required node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline NodeType* AdvanceForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
			//		required amount of nodes backward to the required node
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - the memory address of the node to start from
			//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The memory address of the required node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline NodeType* AdvanceBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const;


		};  //  Class DoubleLinkedList




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































		// Method Information :
		//
		//  Description :
		//
		//		Default Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline DoubleLinkedList< AnyType >::DoubleLinkedList() :
        AccessDataUsingIndices_Interface< AnyType >(),
		member_state( InstanceState::Ready ),
		member_doubleLinkedListRoot( 0UL ),
		member_size( 0UL ),
		member_doubleLinkedListLastNode( 0UL ),
		member_lastUsedNode( 0UL ),
		member_lastUsedNodeIndex( 0UL )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a reference to the data that will stored in the first node of the double linked list
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline DoubleLinkedList< AnyType >::DoubleLinkedList( const AnyType& data ) :
        AccessDataUsingIndices_Interface< AnyType >(),
        member_state( InstanceState::Ready ),
		member_doubleLinkedListRoot( new NodeType( data, 0UL, 0UL ) ),
		member_size( 1UL ),
		member_doubleLinkedListLastNode( member_doubleLinkedListRoot ),
		member_lastUsedNode( member_doubleLinkedListRoot ),
		member_lastUsedNodeIndex( 0UL )
		{}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a constant reference to a sequential platform instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The given sequential platform instance is ready 
        //      2. The given sequential platform instance size should be larger then 0
        //      3. 
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        inline DoubleLinkedList< AnyType >::DoubleLinkedList( const AccessDataUsingIndices_Interface< AnyType >& data ) :
        AccessDataUsingIndices_Interface< AnyType >(),
        member_state( InstanceState::Ready ),
        member_doubleLinkedListRoot( 0UL ),
        member_size( data.Size() ),
        member_doubleLinkedListLastNode( 0UL ),
        member_lastUsedNode( 0UL ),
        member_lastUsedNodeIndex( 0UL )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertInstanceIsReady_MACRO( data );
            AssertInstanceSizeIsLargerThenZero_MACRO( data );

            // Allocate a new node for the double linked list root
            member_doubleLinkedListRoot = new NodeType();

            // Add all the data to this instance starting from the root node. The method will return the memory address of the last node added to the 
            // double linked list, set that as the last node in the double linked list
            member_doubleLinkedListLastNode = AddAllTheDataStartingFromTheGivenNode__Private( member_doubleLinkedListRoot, data );

            // Set the last used node to the root of the double linked list
            member_lastUsedNode = member_doubleLinkedListRoot;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
        //      wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
        //      to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
        //
        //              1. data - a reference to the data that will stored in the first node of the double linked list
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        inline DoubleLinkedList< AnyType >::DoubleLinkedList( const Tuple< const AnyType& >& arguments ) :
        SelfType( arguments.template Entry< 0 >() )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, to allow creating a random generated instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline DoubleLinkedList< AnyType >::DoubleLinkedList( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType ) :
        SelfType()
        {
            // Pick a number for the size
            UnsignedInteger64bits randomInstanceSize = Random::Generator::Get< UnsignedInteger64bits >( rangeForSize );

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits arrayIndex = 0UL ; arrayIndex < randomInstanceSize ; ++arrayIndex )
            {
                // Add another random generated node
                AddData( 0UL, Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... ) );
            }

        }


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline DoubleLinkedList< AnyType >::DoubleLinkedList( const SelfType& other ) :
        AccessDataUsingIndices_Interface< AnyType >(),
        member_state( other.member_state ),
		member_doubleLinkedListRoot( 0UL ),
		member_size( other.member_size ),
		member_doubleLinkedListLastNode( 0UL ),
		member_lastUsedNode( 0UL ),
		member_lastUsedNodeIndex( 0UL )
		{

            // Check if the other instance is empty
            if ( other.member_size > 0UL )
            {
                // The other instance is not empry

                // Allocate a new node for the double linked list root
                member_doubleLinkedListRoot = new NodeType();

                // Add all the data to this instance starting from the root node. The method will return the memory address of the last node added to the 
                // double linked list, set that as the last node in the double linked list
                member_doubleLinkedListLastNode = AddAllTheDataStartingFromTheGivenNode__Private( member_doubleLinkedListRoot, other );

                // Set the last used node to the double linked list root
                member_lastUsedNode = member_doubleLinkedListRoot;
            }

		}


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void DoubleLinkedList< AnyType >::Swap( SelfType& other )
		{
		    // Swap between the double linked list root pointers
		    Memory::Operations::Swap< NodeType* >( member_doubleLinkedListRoot, other.member_doubleLinkedListRoot );

		    // Swap between the sizes
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );

		    // Swap between the double linked list last node pointers
		    Memory::Operations::Swap< NodeType* >( member_doubleLinkedListLastNode, other.member_doubleLinkedListLastNode );

		    // Swap between the double linked list last used node pointers
		    Memory::Operations::Swap< NodeType* >( member_lastUsedNode, other.member_lastUsedNode );

		    // Swap between the double linked list last used node index
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_lastUsedNodeIndex, other.member_lastUsedNodeIndex );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a reference to the data that will stored in the first node of the double linked list
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void DoubleLinkedList< AnyType >::Initiate( const AnyType& data )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( data );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a constant reference to a sequential platform instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The given sequential platform instance is ready 
        //      2. The given sequential platform instance size should be larger then 0
        //      3. 
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        inline void DoubleLinkedList< AnyType >::Initiate( const AccessDataUsingIndices_Interface< AnyType >& data )
        {
            // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
            // leave this scope it will delete the old data
            SelfType temporary( data );

            // Swap between this instance and the temporary instance
            Swap( temporary );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
        //      This version is to allow initiating an instance with the same arguments as the parameterized constructor, just that the arguments
        //      will be wrapped in a tuple, to allow more automatic initialization of instances
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          arguments - the arguments needed to initiate an instance, only wrapped in a tuple. The arguments are :
        //
        //              1. data - a reference to the data that will stored in the first node of the double linked list
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        inline void DoubleLinkedList< AnyType >::Initiate( const Tuple< const AnyType& >& arguments )
        {
            // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
            // leave this scope it delete the old data if exist
            SelfType instanceCreatedUsingTheRequiredConstructor( arguments );

            // Swap between this instance and the temporary instance
            Swap( instanceCreatedUsingTheRequiredConstructor );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
        //      This version is to allow initiating random instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline void DoubleLinkedList< AnyType >::Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
            // leave this scope it delete the old data if exist
            SelfType randomGeneratedInstance( GenerateRandomInstance, rangeForSize, argumentsNeededToGenerateRandomInstanceOfDataType... );

            // Swap between this instance and the temporary instance
            Swap( randomGeneratedInstance );
        }


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		DoubleLinkedList< AnyType >::~DoubleLinkedList()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue_MACRO( member_size == 0UL );

		    // Delete all the nodes
		    DeleteAllNodes__Private();
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the size of the double linked list
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The size of the double linked list
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		UnsignedInteger64bits DoubleLinkedList< AnyType >::Size() const
		{			
			// Return the size of the double linked list
			return ( member_size );
		}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add a node at the given index. This means that if a node needs to be added at index 2 then :
        //
        //          Currently the double linked list looks :
        //
        //              --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
        //              --------------  --------------  --------------  --------------  
        //
        //          After the addition :
        //
        //                                                  Added     Moved up by 1 index
        //                                                    |                |
        //              --------------  --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | New Node 2 |  | Old Node 3 |  | Old Node 4 |  ...
        //              --------------  --------------  --------------  --------------  -------------- 
        //
        //      As can be seen all the nodes that exist in the double linked list before the addition, starting from the node with the required index,
        //      will be moved one index up.
        //
        //      Note - if the node should be added to the end of the double linked list, provide as index the current size of the double linked list
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. data - a reference to the data that a copy of it should be stored in the new node
        //          2. index - the index to insert the new node
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index should be smaller or equal to the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        void DoubleLinkedList< AnyType >::AddData( UnsignedInteger64bits index, const AnyType& data )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( index <= member_size ), "The given index should by smaller then the double linked list size" );


            // The logic of the method is as follows :
            //
            // The current node with the required index first of all will be found. Now the new node should be added at this index, therefore, a new node 
            // will be allocated, but instead of putting the new data in it, all the members of the current node, which are the data itself and the memory
            // address of the next node will be stored in the new node. The memory address of the next node of the current node, will be set to the new 
            // node, and finally the new data will be set in the current node as well. Visually it will look :
            //
            //      Before :
            //
            //                  --------------      --------------
            //          ...     |   data 30  |  ->  |   data 31  |      ...
            //                  |  index 30  |  <-  |  index 31  |
            //                  --------------      --------------
            //
            //      Allocating new node and putting all the data of the current node in the required index to it :
            //
            //                                            New
            //                                             |
            //                  --------------      --------------      --------------
            //          ...     |   data 30  |  ->  |   data 30  |  ->  |   data 31  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |
            //                  --------------      --------------      --------------
            //
            //      And finally setting the new data :      
            //
            //                                            New
            //                                             |
            //                  --------------      --------------      --------------
            //          ...     |  data New  |  ->  |   data 30  |  ->  |   data 31  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |
            //                  --------------      --------------      --------------
            //
            // There is one exception to this, to allow adding a node to the end of the double linked list!


            // Check if the instance is empty
            if ( member_size == 0UL )
            {
                // The instance is empty

                // Initialize the instance
                Initiate( data );

                // Nothing else needs to be done
                return;                
            }
            // Check if the new node should be added to the beginning of the double linked list
            else if ( index == 0UL )
            {
                // The new node should be added to the beginning

                // Allocate a new node, set the requied data and point it to the old first node, and store the memory address in this object
                NodeType* newFirstNode = new NodeType( data, member_doubleLinkedListRoot, 0UL );

                // Set the previous node of the current first node to the new first node
                member_doubleLinkedListRoot->SetPreviousNode( newFirstNode );

                // Set the new root of the double linked list
                member_doubleLinkedListRoot = newFirstNode;

                // Increase the index of the last used node by 1
                member_lastUsedNodeIndex += 1UL;
            }
            // Check if the new node should be added to the end of the double linked list
            else if ( index == member_size )
            {
                // The new node should be added to the end

                // Allocate new node, and store the new data in it, and point the current last node pointer to the next node to the new allocated node
                member_doubleLinkedListLastNode->SetNextNode( new NodeType( data, 0UL, member_doubleLinkedListLastNode ) );

                // Set the pointer to the last node in the double linked list to the new node
                member_doubleLinkedListLastNode = member_doubleLinkedListLastNode->NextNode();
            }
            // Check if the new node should be added one before the last node
            else if ( index == ( member_size - 1UL ) )
            {
                // The new node should be added one before the last node

                // Check if the last used node is the last of in the double linked list
                if ( member_doubleLinkedListLastNode == member_lastUsedNode )
                {
                    // The last used node is the last one

                    // Increase the index of the last used node by 1
                    member_lastUsedNodeIndex += 1UL;
                }

                // Allocate new node, and store the new data in it, and point the current last node pointer to the next node to the new allocated node
                member_doubleLinkedListLastNode->SetPreviousNode( new NodeType( data, member_doubleLinkedListLastNode, member_doubleLinkedListLastNode->PreviousNode() ) );

                // Set the next pointer of the old one before last node to the new node
                member_doubleLinkedListLastNode->PreviousNode()->PreviousNode()->SetNextNode( member_doubleLinkedListLastNode->PreviousNode() );
            }
            else
            {
                // The node should be added to the middle of the double linked list

                // This object will store the memory address of the node with the required index
                member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

                // Allocate new node, and store the data of the current node with the required index in it. Finally set the pointer to the next node to it
                member_lastUsedNode->SetNextNode( new NodeType( member_lastUsedNode->Data(), member_lastUsedNode->NextNode(), member_lastUsedNode ) );

                // Set the previous node of the old next node, to the new node allocated
                member_lastUsedNode->NextNode()->NextNode()->SetPreviousNode( member_lastUsedNode->NextNode() );

                // Store the new data in the current node
                member_lastUsedNode->Data() = data;

                // Store the index in the last used index member
                member_lastUsedNodeIndex = index;
            }

            // Increase the size of the double linked list by 1
            member_size += 1UL;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add a number of nodes at the given index. This means that if the nodes needs to be added starting at index 2 then :
        //
        //          Currently the double linked list looks :
        //
        //              --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
        //              --------------  --------------  --------------  --------------  
        //
        //          After the addition :
        //
        //                                                  Added     Moved up by 1 index
        //                                                    |                |
        //              --------------  --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | New Node 2 |  | Old Node 3 |  | Old Node 4 |  ...
        //              --------------  --------------  --------------  --------------  -------------- 
        //
        //      As can be seen all the nodes that exist in the double linked list before the addition, starting from the node with the required index,
        //      will be moved one index up.
        //
        //      Note - if the nodes should be added to the end of the double linked list, provide as index the current size of the double linked list
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. data - a reference to a sequential platform interafce that contains the data to add
        //          2. index - the index to insert the new nodes
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index should be smaller or equal to the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        void DoubleLinkedList< AnyType >::AddData( UnsignedInteger64bits index, const AccessDataUsingIndices_Interface< AnyType >& data )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( index <= member_size ), "The given index should by smaller then the double linked list size" );
            AssertInstanceIsReady_MACRO( data );
            AssertInstanceSizeIsLargerThenZero_MACRO( data );

            // Check if the instance is empty
            if ( member_size == 0UL )
            {
                // The instance is empty

                // Initiate the instance
                Initiate( data );

                // Nothing else needs to be done
                return;
            }
            // Check if the data needs to be added to the end of the double linked list instance
            else if ( index == member_size )
            {
                // The first entry of the data needs to be added after the current last node

                // Allocate a new node at the end of the double linked list
                member_doubleLinkedListLastNode->SetNextNode( new NodeType( MOVE( AnyType() ), 0UL, member_doubleLinkedListLastNode ) );

                // Add all the new data to the double linked list, and set the memory address of the last added node returned from the method
                member_doubleLinkedListLastNode = AddAllTheDataStartingFromTheGivenNode__Private( member_doubleLinkedListLastNode->NextNode(), data );
            }
            // Check if the new node should be added one before the last node
            else if ( index == ( member_size - 1UL ) )
            {
                // The first entry of the data should be set in the current last node

                // Store the data in the node represented by the index, to allow storing it later in the node after the last added node
                AnyType dataInTheNodeRepresentedByTheIndex = MOVE( member_lastUsedNode->Data() );

                // Add all the new data to the double linked list, and set the memory address of the last added node returned from the method
                member_doubleLinkedListLastNode = AddAllTheDataStartingFromTheGivenNode__Private( member_doubleLinkedListLastNode, data );

                // Allocate a new node at the end of the double linked list
                member_doubleLinkedListLastNode->SetNextNode( new NodeType( MOVE( dataInTheNodeRepresentedByTheIndex ), 0UL, member_doubleLinkedListLastNode ) );

                // Advance the pointer of the last node to the next node which is the new last node
                member_doubleLinkedListLastNode = member_doubleLinkedListLastNode->NextNode();
            }
            else
            {
                // The first entry of the data needs to be set in the middle

                // This object will store the memory address of the node with the required index
                member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

                // Set the last used index to the index
                member_lastUsedNodeIndex = index;

                // Store the data in the node represented by the index, to allow storing it later in the node after the last added node
                AnyType dataInTheNodeRepresentedByTheIndex = MOVE( member_lastUsedNode->Data() );

                // Add all the new data to the double linked list, and set the memory address of the last added node returned from the method
                NodeType* memoryAddressOfLastAddedNode = AddAllTheDataStartingFromTheGivenNode__Private( member_lastUsedNode, data );

                // Allocate a new node for the data the node represented by the index stored before
                memoryAddressOfLastAddedNode->SetNextNode( new NodeType( MOVE( dataInTheNodeRepresentedByTheIndex ), memoryAddressOfLastAddedNode->NextNode(), memoryAddressOfLastAddedNode ) );

                // Set the previous node pointer of the node after the last new node added to point to the last new node added
                memoryAddressOfLastAddedNode->NextNode()->NextNode()->SetPreviousNode( memoryAddressOfLastAddedNode->NextNode() );

                // Check if the index is 0, which means that the data was added to the beginning of the double linked list
                if ( index == 0UL )
                {
                    // The data was added to the beginning of the double linked list

                    // Set the last used node to the last added node
                    member_lastUsedNode = memoryAddressOfLastAddedNode;

                    // Set the last used index to one minus the size of the added data
                    member_lastUsedNodeIndex = ( data.Size() - 1UL );
                }

            }

            // Increment the size of the instance by the size of the sequential platfrom
            member_size += data.Size();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to remove a node at the given index. This means that if a node needs to be removed at index 2 then :
        //
        //          Currently the double linked list looks :
        //
        //              --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
        //              --------------  --------------  --------------  --------------  
        //
        //          After the remove :
        //
        //                                           Moved down by 1 index
        //                                                     |
        //              --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  ...
        //              --------------  --------------  -------------- 
        //
        //      As can be seen all the nodes that exist in the double linked list before the removal, starting from the node with the required index,
        //      will be moved one index down.
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index to remove from it the node
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A copy of the data removed
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index is smaller then the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        AnyType DoubleLinkedList< AnyType >::RemoveData( UnsignedInteger64bits index )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( index < member_size ), "The given index should by smaller then the double linked list size" );


            // The logic of the method is as follows :
            //
            // The first step is to find the memory address of the node before the node that should be removed. Now, the memory address of the node to
            // remove will be stored in a temporary, to be able to delete it later. The next step is to set the pointer to the next node of the node
            // before the node that should be removed to the node after the node that should be removed. Now set the pointer to the previous node of the
            // node after the node that should be removed to the node before the node that should be removed. Finally delete the required node.  Visually 
            // it will look :
            //
            //      Before :
            //
            //                  --------------      --------------      --------------      --------------
            //          ...     |   data 30  |  ->  |   data 31  |  ->  |   data 32  |  ->  |   data 33  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |  <-  |  index 33  |
            //                  --------------      --------------      --------------      --------------
            //
            //      Storing the pointer to the node that should be removed :
            //
            //                                      Node to remove
            //                                            |
            //                  --------------      --------------      --------------      --------------
            //          ...     |   data 30  |  ->  |   data 31  |  ->  |   data 32  |  ->  |   data 33  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |  <-  |  index 33  |
            //                  --------------      --------------      --------------      --------------
            //
            //      Set the next pointer of the node before the node to remove to the node after the node to remove :
            //
            //                  --------------      --------------      --------------      --------------
            //          ...     |   data 30  |  ->  |   data 31  |      |   data 32  |  ->  |   data 33  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |  <-  |  index 33  |
            //                  --------------      --------------      --------------      --------------
            //                                            |                                        |
            //                                            ----------------------------------------->
            //
            //      Set the previous pointer of the node after the node to remove to the node before the node to remove :
            //
            //                                            <-----------------------------------------
            //                                            |                                        |
            //                  --------------      --------------      --------------      --------------
            //          ...     |   data 30  |  ->  |   data 31  |      |   data 32  |  ->  |   data 33  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <-  |  index 32  |      |  index 33  |
            //                  --------------      --------------      --------------      --------------
            //                                            |                                        |
            //                                            ----------------------------------------->
            //
            //      Finally delete the required node :
            //
            //                  --------------      --------------                          --------------
            //          ...     |   data 30  |  ->  |   data 31  |  --------------------->  |   data 33  |      ...
            //                  |  index 30  |  <-  |  index 31  |  <---------------------  |  index 32  |
            //                  --------------      --------------                          --------------


            // Store the data currently located at the index location
            AnyType dataToRemove;

            // Check if the current size of the double linked list is 1, and the given index is 0
            if ( member_size == 1UL )
            {
                // The current size of the double linked list is 1, and the given index is 0

                // Store the data in the only node  
                dataToRemove = MOVE( member_doubleLinkedListRoot->Data() );

                // Reset the instance
                Reset();

                // Nothing else needs to be done
                return ( MOVE( dataToRemove ) );
            }
            // Check if the first node needs to be removed
            else if ( index == 0UL )
            {
                // The first node needs to be removed

                // Store the data in the first node  
                dataToRemove = MOVE( member_doubleLinkedListRoot->Data() );

                // Store the address of the second node in the double linked list
                NodeType* secondNode = member_doubleLinkedListRoot->NextNode();

                // Check if the last used node pointer was to the first node
                if ( member_lastUsedNode == member_doubleLinkedListRoot )
                {
                    // The last used node was the first node

                    // Set the last used node to the second node
                    member_lastUsedNode = secondNode;
                }

                // Delete the first node
                delete member_doubleLinkedListRoot;

                // Set the root to the new first node
                member_doubleLinkedListRoot = secondNode;

                // Set the previous node of the new first node to NULL
                member_doubleLinkedListRoot->SetPreviousNode( 0UL );
            }
            // Check if the last node needs to be removed
            else if ( index == ( member_size - 1 ) )
            {
                // The last node needs to be removed

                // Store the data in the last node  
                dataToRemove = MOVE( member_doubleLinkedListLastNode->Data() );

                // Set the last node in the double linked list to one before the last node that needs to be removed
                member_doubleLinkedListLastNode = member_doubleLinkedListLastNode->PreviousNode();

                // Check if the last used node pointer was to the last node
                if ( member_lastUsedNode == member_doubleLinkedListLastNode->NextNode() )
                {
                    // The last used node was the last in the double linked list

                    // Set the last used node to the new last node
                    member_lastUsedNode = member_doubleLinkedListLastNode;

                    // Set the index of the last used node
                    member_lastUsedNodeIndex -= 1UL;
                }

                // Delete the last node
                delete member_doubleLinkedListLastNode->NextNode();

                // Set the pointer to the next node of the new last node to NULL
                member_doubleLinkedListLastNode->SetNextNode( 0UL );
            }
            else
            {
                // The node should be removed from the middle of the double linked list

                // This object will store the memory address of the node with the required index
                NodeType* nodeToRemove = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

                // Store the data in the node to remove  
                dataToRemove = MOVE( nodeToRemove->Data() );

                // Set the pointer to the next node of the node before the node that should be removed, to the node after the node that should be removed
                nodeToRemove->PreviousNode()->SetNextNode( nodeToRemove->NextNode() );

                // Set the pointer to the previous node of the node after the node that should be removed, to the node before the node that should be removed
                nodeToRemove->NextNode()->SetPreviousNode( nodeToRemove->PreviousNode() );

                // Set the last used node to the node before the node that was removed
                member_lastUsedNode = nodeToRemove->PreviousNode();

                // Store the index in the last used index member
                member_lastUsedNodeIndex = ( index - 1UL );

                // Delete the next node
                delete nodeToRemove;
            }

            // Decrease the size of the double linked list by 1
            member_size -= 1UL;

            // Return a copy of the removed data
            return ( MOVE( dataToRemove ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to remove number of nodes starting at the given index. This means that if the nodes needs to be removed starting at index 2 then :
        //
        //          Currently the double linked list looks :
        //
        //              --------------  --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  | Old Node 3 |  ...
        //              --------------  --------------  --------------  --------------  
        //
        //          After the remove :
        //
        //                                           Moved down by 1 index
        //                                                     |
        //              --------------  --------------  --------------    
        //              | Old Node 0 |  | Old Node 1 |  | Old Node 2 |  ...
        //              --------------  --------------  -------------- 
        //
        //      As can be seen all the nodes that exist in the double linked list before the removal, starting from the last node to be removed index, will be 
        //      moved one index down.
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          indexOfFirstDataToRemove - the index of the first data to remove
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index is smaller then the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        void DoubleLinkedList< AnyType >::RemoveData( UnsignedInteger64bits indexOfFirstDataToRemove, UnsignedInteger64bits sizeToRemove )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( ( indexOfFirstDataToRemove + sizeToRemove ) <= member_size ), "The given index should by smaller then the double linked list size" );

            // This pointer will store the memory address of the first node to delete
            NodeType* memoryAddressOfCurrentNodeToDelete = 0UL;

            // Check if all the nodes needs to be removed
            if ( member_size == sizeToRemove )
            {
                // All the nodes needs to be removed

                // Reset the instance
                Reset();

                // Nothing else needs to be done
                return;
            }
            // Check if the nodes to be removed needs to start from the first node
            else if ( indexOfFirstDataToRemove == 0UL )
            {
                // The nodes to remove start from the first node

                // Store the memory address of the second node, to allow deleting all the required nodes
                memoryAddressOfCurrentNodeToDelete = member_doubleLinkedListRoot;

                // Set the last used node to the node after the last node that needs to be removed
                member_doubleLinkedListRoot = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( sizeToRemove );

                // Check if the last used node pointer points to one of the nodes that about to be deleted
                if ( member_lastUsedNodeIndex < sizeToRemove )
                {
                    // The last used node points to one of the nodes that are about to be deleted

                    // Set the last used node to the new last node
                    member_lastUsedNode = member_doubleLinkedListRoot;

                    // Set the index of the last used node
                    member_lastUsedNodeIndex = 0UL;
                }

            }
            // Check if the last node that needs to be removed is the last node of the double linked list
            else if ( ( indexOfFirstDataToRemove + sizeToRemove ) == member_size )
            {
                // The last node needs to be removed as well

                // Set the last node member to the node one before the last one
                member_doubleLinkedListLastNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove - 1UL );

                // Store the memory address of the first node that needs to be deleted, to allow deleting all the required nodes
                memoryAddressOfCurrentNodeToDelete = member_doubleLinkedListLastNode->NextNode();

                // Set the pointer to the next node of the new last node to NULL
                member_doubleLinkedListLastNode->SetNextNode( 0UL );

                // Check if the last used node pointer points to one of the nodes that about to be deleted
                if ( member_lastUsedNodeIndex > ( indexOfFirstDataToRemove - 1UL ) )
                {
                    // The last used node points to one of the nodes that are about to be deleted

                    // Set the last used node to the new last node
                    member_lastUsedNode = member_doubleLinkedListLastNode;

                    // Set the index of the last used node
                    member_lastUsedNodeIndex = ( indexOfFirstDataToRemove - 1UL );
                }

            }
            else
            {
                // The nodes should be removed from the middle of the double linked list

                // Store the memory address of the node befroe the first node that needs to be removed
                member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove - 1UL );

                // Store the index in the last used index member
                member_lastUsedNodeIndex = ( indexOfFirstDataToRemove - 1UL );

                // Store the memory address of the first node that needs to be deleted, to allow deleting all the required nodes
                memoryAddressOfCurrentNodeToDelete = member_lastUsedNode->NextNode();

                // Store the memory address of the node after the last node that needs to be removed, in the node before the first node that needs to be removed
                member_lastUsedNode->SetNextNode( TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove + sizeToRemove ) );

                // Set the previous node of the currently set next node to point to the node before the nodes that about to be removed
                member_lastUsedNode->NextNode()->SetPreviousNode( member_lastUsedNode );
            }

            // This pointer will store the memory address of the next pointer that needs to be deleted
            NodeType* memoryAddressOfNextNodeToDelete = 0UL;

            // Loop on all the nodes that needs to be removed and delete them
            for ( UnsignedInteger64bits numberOfNodesRemoved = 0UL ; numberOfNodesRemoved < sizeToRemove ; ++numberOfNodesRemoved )
            {
                // Set the next memory address that needs to be deleted
                memoryAddressOfNextNodeToDelete = memoryAddressOfCurrentNodeToDelete->NextNode();

                // Delete the current node
                delete memoryAddressOfCurrentNodeToDelete;

                // Advance the pointer to the next node to delete
                memoryAddressOfCurrentNodeToDelete = memoryAddressOfNextNodeToDelete;
            }

            // Decrease the size of the double linked list by 1
            member_size -= sizeToRemove;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get an instance with only part of the current instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. partStartingIndex - the starting index from which the part instance will start
        //          2. partSize - the size of the part instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      An instance with only the required part from this instance
        //
        //  Expectations :
        //
        //      1. The given part starting index is smaller then the instance size
        //      2. The given part starting index and size is smaller or equal to the size of the instance
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline DoubleLinkedList< AnyType > DoubleLinkedList< AnyType >::Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( partSize > 0UL ), "The given part size is 0" );
            Assert_MACRO( ( ( partStartingIndex + partSize ) <= member_size ), "The sum of the given starting index and part size should be smaller or equal to the double linked list size" );

            // Create an instance to store only the required part from the current instance
            SelfType part;

            // This object will store the index after the last index that needs to be added
            UnsignedInteger64bits stopAtThisIndex = ( partStartingIndex + partSize );

            // This object will store the index on the part instance at which the current entry needs to be added
            UnsignedInteger64bits addEntryAtThisIndex = 0UL;            
            
            // Loop to add all the entries of the required part of this instance
            for ( UnsignedInteger64bits partIndex = partStartingIndex ; partIndex < stopAtThisIndex ; ++partIndex )
            {
                // Add the current entry to the new part instance
                part.AddData( addEntryAtThisIndex, operator[]( partIndex ) );

                // Increment the index on the part instance
                addEntryAtThisIndex += 1UL;
            }

            // Return a copy of the instance with only the required part of this instance
            return ( MOVE( part ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to compare only the required part of the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. startingIndexInThisInstance - the index from to start the comparison on this instance
        //          2. other - a constant reference to an other sequential platform instance
        //          3. startingIndexInOtherInstance - the index from to start the comparison on the other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      True if the parts are equal, and false otherwise
        //
        //  Expectations :
        //
        //      1. The given starting index in this instance should be smaller then the size of the instance
        //      2. The size of the given other instance should not be 0
        //      3. The given starting index in this instance should be smaller then the size of the instance
        //      4. The given starting index in this instance plus the size to compare must be smaller or equal to the size of the instance
        //      5. The given starting index in the other instance plus the size to compare must be smaller or equal to the size of the other instance
        //      6. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline Boolean DoubleLinkedList< AnyType >::ComparePart( UnsignedInteger64bits startingIndexInThisInstance, const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits startingIndexInOtherInstance, UnsignedInteger64bits sizeToCompare ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( ( startingIndexInThisInstance + sizeToCompare ) <= member_size ), "The given starting index in this instance plus the size to compare must be smaller or equal to the size of the instance" );
            Assert_MACRO( ( other.Size() > 0UL ), "The size of the given other instance should not be 0" );
            Assert_MACRO( ( ( startingIndexInOtherInstance + sizeToCompare ) <= other.Size() ), "The given starting index in the other instance plus the size to compare must be smaller or equal to the size of the other instance" );
            
            // This object will store the index on the other instance
            UnsignedInteger64bits indexOnOtherInstance = startingIndexInOtherInstance;

            // This object will store the index after the last index that needs to be compared
            UnsignedInteger64bits stopAtThisIndex = ( startingIndexInOtherInstance + sizeToCompare );

            // Loop on all the required entries and compare their content
            for ( UnsignedInteger64bits indexOnThisInstance = startingIndexInThisInstance ; indexOnThisInstance < stopAtThisIndex ; ++indexOnThisInstance, ++indexOnOtherInstance )
            {
                // Compare the current entries in both instances
                ReturnValueIfExpressionIsTrue_MACRO( ( operator[]( indexOnThisInstance ) != other[ indexOnOtherInstance ] ), false );
            }

            // If the control of the method reached this far, then the cmpared parts match, return true
            return ( true );
        }































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a reference to the required node
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required node
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the required node
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index is smaller then the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        AnyType& DoubleLinkedList< AnyType >::operator[]( UnsignedInteger64bits index )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( index < member_size ), "The given index should by smaller then the double linked list size" );

            // Store the required node memory address in the last used node member
            member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

            // Store the index in the last used index member
            member_lastUsedNodeIndex = index;
            
            // Find the required node, and return a reference to it
            return ( member_lastUsedNode->Data() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a copy of the value inside the required node
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required node
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A constant reference to the required node
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given index is smaller then the double linked list size
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        const AnyType& DoubleLinkedList< AnyType >::operator[]( UnsignedInteger64bits index ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            Assert_MACRO( ( index < member_size ), "The given index should by smaller then the double linked list size" );
            
            // Store the required node memory address in the last used node member
            member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

            // Store the index in the last used index member
            member_lastUsedNodeIndex = index;
            
            // Find the required node, and return a constant reference to it
            return ( member_lastUsedNode->Data() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the this instance match the other
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a constnt reference to a sequential platform
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the 2 instances are the same
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline Boolean DoubleLinkedList< AnyType >::operator==( const AccessDataUsingIndices_Interface< AnyType >& other ) const
        {
            // Check if the size of both instances match, if it doesn't return false
            ReturnValueIfExpressionIsTrue_MACRO( ( member_size != other.Size() ), false );

            // This pointer will be used to pass on the nodes of this instance
            const NodeType* currentNodeInThisInstance = member_doubleLinkedListRoot;

            // Loop on all the entries and compare the data inside
            for ( UnsignedInteger64bits nodeIndex = 0UL ; nodeIndex < member_size ; ++nodeIndex )
            {
                // Check if the data in both nodes match, if it doesn't the instances does not match then return false
                ReturnValueIfExpressionIsTrue_MACRO( ( currentNodeInThisInstance->Data() != other[ nodeIndex ] ), false );
                
                // Advance the pointer on this instance to the next node
                currentNodeInThisInstance = currentNodeInThisInstance->NextNode();
            }

            // If control reached here, then the 2 double linked lists match
            return ( true );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the this instance does not match the other
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be compared with this object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the 2 instances are not the same
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline Boolean DoubleLinkedList< AnyType >::operator!=( const AccessDataUsingIndices_Interface< AnyType >& other ) const
        {
            // Return the negotiated value from the equal operator
            return ( !( *this == other ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the content of another instance to the end of this instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a reference to a sequential platform to concatenate to the end of this instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The sequential platform should be ready
        //      3. The sequential platform size should be larger then 0
        //      4. 
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        AccessDataUsingIndices_Interface< AnyType >& DoubleLinkedList< AnyType >::operator+=( const AccessDataUsingIndices_Interface< AnyType >& data )
        {
            // Add the data to the end of this double linked list instance
            AddData( member_size, data );

            // Return a reference to this instance
            return ( *this );
        }




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************


































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add all the sequential platform entries to this instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. node - a pointer to the node that the adding of data needs to start from
        //          2. data - a constant reference to a sequential platform
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The memory address of the last node added to double linked list
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - Class std::bad_alloc is thrown
        //      2. 
        //
        template< typename AnyType >
        inline DoubleLinkedListNode< AnyType >* DoubleLinkedList< AnyType >::AddAllTheDataStartingFromTheGivenNode__Private( NodeType* startAddingFromThisNode, const AccessDataUsingIndices_Interface< AnyType >& data )
        {

            // Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
            try
            {

                // Add the data of the first entry to the reference to node to start adding from
                startAddingFromThisNode->Data() = data[0];

                // This node will store the next node of the node that the adding needs to start from
                NodeType* nextNodeOfNodeThatTheAddingNeedsToStartFrom = startAddingFromThisNode->NextNode();

                // Loop until the required amount of nodes to pass has reached
                for ( UnsignedInteger64bits dataIndex = 1UL ; dataIndex < data.Size() ; ++dataIndex )
                {
                    // Add the current data to the double linked list

                    // Allocate a new node, set the requied data and point it to next node of the node the adding needed to start after
                    startAddingFromThisNode->SetNextNode( new NodeType( data[ dataIndex ], nextNodeOfNodeThatTheAddingNeedsToStartFrom, startAddingFromThisNode ) );

                    // Advance to the node just added
                    startAddingFromThisNode = startAddingFromThisNode->NextNode();
                }

            }
            catch ( const std::bad_alloc& exception )
            {
                // Delete all the nodes allocated so far
                DeleteAllNodes__Private();

                // Rethrow the exception to notify the caller that the operation failed
                throw;
            }

            // Return the memory address of the last node added the double linked list
            return ( startAddingFromThisNode );
        }


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to delete all the node from the double linked list
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void DoubleLinkedList< AnyType >::DeleteAllNodes__Private()
		{
			// This pointer will store the pointer of the node that needs to be deleted
			NodeType* currentNodeToDelete = member_doubleLinkedListRoot;

			// Loop on all the entries allocated so far and delete them
			for ( NodeType* nextNodeToDelete = member_doubleLinkedListRoot->NextNode() ; nextNodeToDelete != 0UL ; nextNodeToDelete = nextNodeToDelete->NextNode() )
			{
				// Delete the node
				delete currentNodeToDelete;

				// Set the next node to delete
				currentNodeToDelete = nextNodeToDelete;
			}

			// Delete the last node
			delete currentNodeToDelete;
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
		//		the beginning, end or from the last used node, and take that path
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - the index of the required node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
        //      The memory address of the required node
		//
		//  Expectations :
		//
		//		1. The given index is smaller then the double linked list size
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		DoubleLinkedListNode< AnyType >* DoubleLinkedList< AnyType >::TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( UnsignedInteger64bits index ) const
		{
            // Check if the index is 0, which means the first node in the double linked list is required
            ReturnValueIfExpressionIsTrue_MACRO( ( index == 0UL ), member_doubleLinkedListRoot );

            // Check if the index is smaller by 1 then the current size, which means the last node in the double linked list is required
            ReturnValueIfExpressionIsTrue_MACRO( ( index == ( member_size - 1UL ) ), member_doubleLinkedListLastNode );

            // Check if the index is the same as the index of the last used node
            ReturnValueIfExpressionIsTrue_MACRO( ( index == member_lastUsedNodeIndex ), member_lastUsedNode );

			// Check if the last used node also points to the beginning, to the end, or really close them
			if ( ( member_doubleLinkedListRoot == member_lastUsedNode ) || ( member_lastUsedNodeIndex < 10UL ) || ( member_doubleLinkedListLastNode == member_lastUsedNode ) || ( member_lastUsedNodeIndex > ( member_size - 10UL ) ) )
			{
				// The last used node either points exactly or really close to the beginning or end, and therefore will not be used

				// Check if the end or the beginning are closer
				if ( index <= ( member_size / 2 ) )
				{
					// The search for the required node will start from the beginning

					// Advance to the required node and return the memory address
					return ( AdvanceForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_doubleLinkedListRoot, index ) );
				}
				else
				{
					// The search for the required node will start from the end

					// Advance to the required node and return the memory address
					return ( AdvanceBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_doubleLinkedListLastNode, ( ( member_size - 1UL ) - index ) ) );
				}

			}

			// Now, there are 3 options, the required node could be closest to the beginning, the end or the last used node!

			// Check if the required node is closer to the beginning then the end or the last used node
			if ( index <= ( member_lastUsedNodeIndex / 2UL ) )
			{
				// The search for the required node will start from the beginning

				// Advance to the required node and return the memory address
				return ( AdvanceForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_doubleLinkedListRoot, index ) );
			}
			// Check if the required node is closer to the end then the beginning or the last used node
			else if ( index >= ( member_lastUsedNodeIndex + ( ( member_size - 1UL - member_lastUsedNodeIndex ) / 2UL ) ) )
			{
				// The search for the required node will start from the end

				// Advance to the required node and return the memory address
				return ( AdvanceBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_doubleLinkedListLastNode, ( ( member_size - 1UL ) - index ) ) );
			}
			else
			{
				// The search for the required node will start from the last used node

				// Check if the index is before or after the last used node
				if ( member_lastUsedNodeIndex >= index )
				{
					// The required node is before the last used node
			
					// Advance to the required node and return the memory address
					return ( AdvanceBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_lastUsedNode, ( member_lastUsedNodeIndex - index ) ) );
				}
				else
				{
					// The required node is after the last used node
					
					// Advance to the required node and return the memory address
					return ( AdvanceForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_lastUsedNode, ( index - member_lastUsedNodeIndex ) ) );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
		//		required amount of nodes forward to the required node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - the memory address of the node to start from
		//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The memory address of the required node
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline DoubleLinkedListNode< AnyType >* DoubleLinkedList< AnyType >::AdvanceForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const
		{

			// Loop until the required amount of nodes to pass has reached
			for ( UnsignedInteger64bits numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
			{
				// Advance to the next node
				node = node->NextNode();
			}

			// Return the memory address of the required node 
			return ( node );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
		//		required amount of nodes backward to the required node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - the memory address of the node to start from
		//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The memory address of the required node
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline DoubleLinkedListNode< AnyType >* DoubleLinkedList< AnyType >::AdvanceBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const
		{

			// Loop until the required amount of nodes to pass has reached
			for ( UnsignedInteger64bits numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
			{
				// Advance to the next node
				node = node->PreviousNode();
			}

        }

































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      1. true - if the object passed the test
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< typename AnyType >
			inline void DoubleLinkedList< AnyType >::Test()
			{
                // Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
                // destructor, swap and more, seem to work correctly
                Testing::SanityCheck::Full< DoubleLinkedList< AnyType > COMMA const Type& >();

                // Create a double linked list instance
                DoubleLinkedList< UnsignedInteger64bits > testSingleLinkedList_1;

                // Initiate the instance
                testSingleLinkedList_1.Initiate( 89UL );
            
                // Check that the instance was initialized
                Assert_Test_MACRO( testSingleLinkedList_1.State().Get() == InstanceState::Ready );

                // Check that the node was added correctly
                Assert_Test_MACRO( testSingleLinkedList_1[0] == 89UL );

                // Add 100 nodes
                for ( UnsignedInteger64bits index = 0UL ; index < 100UL ; ++index )
                {
                    // Add as node
                    testSingleLinkedList_1.AddData( index, index );
                }

                const DoubleLinkedList< UnsignedInteger64bits >& testSingleLinkedList_49 = testSingleLinkedList_1.Part( 9UL, 43UL );

                // Check that all the nodes were added correctly
                for ( UnsignedInteger64bits index = 0UL ; index < 100UL ; ++index )
                {
                    // Add as node
                    Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
                }

                // Check that the node was added correctly
                Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

                // Add 100000 nodes
                for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
                {
                    // Add as node
                    testSingleLinkedList_1.AddData( index, index );
                }

                // Check that all the nodes were added correctly
                for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
                {
                    // Add as node
                    Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
                }

                // Check that the node was added correctly
                Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

                // Add 100000 nodes
                for ( UnsignedInteger64bits index = 45UL ; index < 100000UL ; ++index )
                {
                    // Add as node
                    testSingleLinkedList_1.AddData( index, index );
                }

                // Check that all the nodes were added correctly
                for ( UnsignedInteger64bits index = 45UL ; index < 100000UL ; ++index )
                {
                    // Add as node
                    Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
                }

                // Check that the node was added correctly
                Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

                // Store the current size of the double linked list
                UnsignedInteger64bits currentSingleLinkedListSize = testSingleLinkedList_1.Size();

                // Add 100000 nodes
                for ( UnsignedInteger64bits index = currentSingleLinkedListSize ; index < ( currentSingleLinkedListSize + 100000UL ) ; ++index )
                {
                    // Add as node
                    testSingleLinkedList_1.AddData( index, index );
                }

                // Check that all the nodes were added correctly
                for ( UnsignedInteger64bits index = currentSingleLinkedListSize ; index < ( currentSingleLinkedListSize + 100000UL ) ; ++index )
                {
                    // Add as node
                    Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
                }

                // Check that the node was added correctly
                Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == ( currentSingleLinkedListSize + 100000UL - 1UL ) );

                // Store the current size
                currentSingleLinkedListSize = testSingleLinkedList_1.Size();

                // Remove 100000 nodes
                for ( UnsignedInteger64bits index = 56 ; index < 100001UL ; index += 3 )
                {
                    // Add as node
                    testSingleLinkedList_1.RemoveData( index );
                }

                // Check that the size is correct
                Assert_Test_MACRO( testSingleLinkedList_1.Size() == ( currentSingleLinkedListSize - ( ( 100001UL - 56UL ) / 3UL ) ) );               

                // Create a new instance using the copy constructor
                DoubleLinkedList< UnsignedInteger64bits > testSingleLinkedList_2( testSingleLinkedList_1 );

                // Check that the instances match
                Assert_Test_MACRO( testSingleLinkedList_1 == testSingleLinkedList_2 );                               

                // Check that the instances match
                Assert_Test_MACRO( ( testSingleLinkedList_1 != testSingleLinkedList_2 ) == false );

                // Reset the second instance
                testSingleLinkedList_2.Reset();

                // Check that the instances don't match
                Assert_Test_MACRO( ( testSingleLinkedList_1 == testSingleLinkedList_2 ) == false );                              

                // Check that the instances don't match
                Assert_Test_MACRO( testSingleLinkedList_1 != testSingleLinkedList_2 );

                // Check the assignment operator
                testSingleLinkedList_2 = testSingleLinkedList_1;

                // Check that the instances match
                Assert_Test_MACRO( testSingleLinkedList_1 == testSingleLinkedList_2 );                               

                // Check that the instances match
                Assert_Test_MACRO( ( testSingleLinkedList_1 != testSingleLinkedList_2 ) == false );

                // Remove all nodes
                while ( testSingleLinkedList_2.Size() > 0UL )
                {
                    // Remove node
                    testSingleLinkedList_2.RemoveData( 0UL );
                }

                // Check the assignment operator
                testSingleLinkedList_2 = testSingleLinkedList_1;

                // Remove all nodes
                while ( testSingleLinkedList_2.Size() > 6UL )
                {
                    // Remove node
                    testSingleLinkedList_2.RemoveData( 5UL );
                }

                // Check that the instance is really in default state
                Assert_Test_MACRO( testSingleLinkedList_2.Size() == 6UL );

                // Create a double linked list instance
                DoubleLinkedList< UnsignedInteger64bits > testSingleLinkedList_3;

                // Add some nodes
                testSingleLinkedList_3.Initiate( 8UL );
                testSingleLinkedList_3.AddData( 0UL, 8UL );
                testSingleLinkedList_3.AddData( 0UL, 8UL );
                testSingleLinkedList_3.AddData( 0UL, 8UL );
                testSingleLinkedList_3.AddData( 0UL, 8UL );
                testSingleLinkedList_3.AddData( 0UL, 8UL );
                testSingleLinkedList_3.AddData( 1UL, 8UL );
                testSingleLinkedList_3.AddData( 1UL, 8UL );
                testSingleLinkedList_3.AddData( 1UL, 8UL );
                testSingleLinkedList_3.AddData( 1UL, 8UL );
                testSingleLinkedList_3.AddData( 1UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 2UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( 7UL, 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 0UL , 8UL);
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 21UL, 8UL );
                testSingleLinkedList_3.AddData( 22UL, 8UL );
                testSingleLinkedList_3.AddData( 23UL, 8UL );
                testSingleLinkedList_3.AddData( 24UL, 8UL );
                testSingleLinkedList_3.AddData( 25UL, 8UL );
                testSingleLinkedList_3.AddData( 26UL, 8UL );
                testSingleLinkedList_3.AddData( 27UL, 8UL );
                testSingleLinkedList_3.AddData( 28UL, 8UL );
                testSingleLinkedList_3.AddData( 29UL, 8UL );
                testSingleLinkedList_3.AddData( 30UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );
                testSingleLinkedList_3.AddData( 20UL, 8UL );

                // Remove all nodes
                while ( testSingleLinkedList_3.Size() > 0UL )
                {
                    // Remove node
                    testSingleLinkedList_3.RemoveData( testSingleLinkedList_3.Size() - 1UL );
                }

                // Check the assignment operator
                testSingleLinkedList_2 = testSingleLinkedList_1;

                // Remove all nodes
                while ( testSingleLinkedList_2.Size() > 0UL )
                {
                    // Remove node
                    testSingleLinkedList_2.RemoveData( testSingleLinkedList_2.Size() - 1UL );
                }

                // Check the assignment operator
                testSingleLinkedList_2 = testSingleLinkedList_1;

                // Remove a segment of nodes
                testSingleLinkedList_2.RemoveData( 1UL, ( testSingleLinkedList_2.Size() - 7UL ) );

                // Check that the size is correct
                Assert_Test_MACRO( testSingleLinkedList_2.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 7UL ) ) );

                // Check the assignment operator
                testSingleLinkedList_3 = testSingleLinkedList_1;

                // Remove a segment of nodes
                testSingleLinkedList_3.RemoveData( 0UL, ( testSingleLinkedList_3.Size() - 45UL ) );

                // Check that the size is correct
                Assert_Test_MACRO( testSingleLinkedList_3.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 45UL ) ) );

                // Check the assignment operator
                testSingleLinkedList_3 = testSingleLinkedList_1;

                // Remove a segment of nodes
                testSingleLinkedList_3.RemoveData( 564UL, ( testSingleLinkedList_3.Size() - 1UL - 564UL ) );

                // Check that the size is correct
                Assert_Test_MACRO( testSingleLinkedList_3.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 565UL ) ) );

                // Check the assignment operator
                testSingleLinkedList_3 = testSingleLinkedList_1;

                // Remove a segment of nodes
                testSingleLinkedList_3.RemoveData( 0UL, testSingleLinkedList_3.Size() );

                // Check that the size is correct
                Assert_Test_MACRO( testSingleLinkedList_3.Size() == 0UL );

                // Create a random instance
                DoubleLinkedList< UnsignedInteger64bits > testRandomInstance_1 = MOVE( DoubleLinkedList< UnsignedInteger64bits >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 40000UL, 60000UL ) ) );

                // Add segment of nodes at the beginning 
                testSingleLinkedList_3.AddData( 0UL, testRandomInstance_1 );

                // Add segment of nodes at the end
                testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), testRandomInstance_1 );

                // Add segment of nodes at one before the end
                testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1UL ), testRandomInstance_1 );

                // Add segment of nodes at the middle
                testSingleLinkedList_3.AddData( 300UL, testRandomInstance_1 );
                testSingleLinkedList_3.AddData( 4008UL, testRandomInstance_1 );
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // DOUBLELINKEDLIST_HPP