namespace Universe
{



// There is contradiction or incompatibility, between object oriented programming and generic programming. It is easy to dismiss Alexander
// Stepanov's rejection of object oriented programming as extreme and unrealistic. It is much harder to make the object oriented and generic
// programming paradigms coexist and cooperate in real-life software engineering.
//
// An Example from the Real World :
//
// Suppose you have a class number_cruncher that calculates and stores a sequence of numbers. Further, suppose that number_cruncher wants to 
// expose to its clients a way to iterate over the stored numbers and retrieve them.
//
// In the old days, predating the STL, the interface of number_cruncher might have exposed a callback for retrieving the numbers, or perhaps
// some form of get_first()/get_next() idiom. In an evironment where the STL and generic programming are used, such an interface would raise
// more than a few eyebrows. Here, the interface of number_cruncher will expose a pair of iterators, like this:
//
// 	class number_cruncher
// 	{   
// 	public:
// 	  typedef std::vector<double>::const_iterator const_iterator;
//   	const_iterator begin() const;
//   	const_iterator end() const;
//   	[...]
// 	};
//
// Now suppose you change the type of the collection which internally holds the items from std::vector to some other kind of container. In the
// sense of object oriented programming, what have you just done? You have changed an implementation detail. And what happens? The world recompiles. By using
// a typedef for the iterator that you expose, you were able to ensure that your clients did not have to change their code. Nonetheless, their 
// code depends on the type of the iterator, and thus on the type of the collection that you use to store your numbers. In the pre-STL design
// mentioned earlier, this dependency can easily be eliminated, e.g., by using the pimpl idiom, or by exposing the number cruncher's interface
// via an abstract base class. This option is now gone. By using the typedef for the iterators, you have introduced a compile-time dependency that
// cannot be eliminated. Depending on the context in which your class is used, that may or may not be a serious issue.
//
// But it gets worse. Suppose that the implementation of number_cruncher changes in such a way that there are frequent insertions to the
// internal collection of numbers. Having anticipated a change of that kind, you have carefully specified number_cruncher's interface to state
// that it will expose a pair of input iterators, dereferencing to something that converts to a double, with incrementing and dereferencing both
// having O(1) complexity. Therefore, you are within your rights when you change the internal type of your collection from std::vector<double> to
// std::list<double>. Again, your clients will have to recompile. But it is also possible that before, when you were exposing vector iterators,
// some of your clients may have said, gee, I wonder how many elements there are in this number cruncher. Let me do:
//
// 	size_t numItems = my_number_cruncher.end() - my_number_cruncher.begin();
//
// You did not mean for them to do that, but you could not prevent it either. Now, after you changed an implementation detail of number_cruncher,
// not only will the world recompile, the world will find that it has a broken build. By exposing functionality that you neither needed nor wanted
// to expose, you have broken encapsulation.
//
// Well, that's not really an issue, you might say, because if your clients are STL savvy, as they should be, then they were probably using
// std::distance to get the number of elements in the number_cruncher :
//
// 	size_t numItems = std::distance(
//   	my_number_cruncher.begin(),
//   	my_number_cruncher.end()
// 	);
//
// If they were doing that, then your implementation change from vector to list causes the semantics of your number cruncher to change: the cost
// of getting the number of elements changes from constant to linear. This is probably even worse than the broken build, because it may not be
// noticed until way, way later, when something goes horribly awry in the field. You never meant for anybody to get the number of elements in 
// constant time, but you could not prevent it.
//
// In this case, my number cruncher class had to calculate several sequences of numbers, and there were certain fairly simple relationships between
// these sequences. For example, sequence D was a constant multiple of sequence A, sequence E was the pointwise difference between sequences B and C,
// sequence F was the quotient of sequences D and E, and so on and so forth. It would have been a silly time-space trade-off for me to store each
// one of these sequences in a collection. Instead, I stored only sequences A, B, and C. Sequences D, E, and F were exposed via suitable combinations
// of boost::transform_iterator and boost::zip_iterator. These iterators calculate the respective value on the fly during dereferencing. The interface
// of the number_cruncher class ended up looking like this :
//
// 	class number_cruncher
// 	{
// 	public:
//   	typedef std::vector<double>::const_iterator a_iterator;
//   	typedef a_iterator b_iterator;
//   	typedef a_iterator c_iterator;
//   	typedef boost::transform_iterator<
//     	boost::function<double (double)>,
//     	std::vector<double>::const_iterator
//   	> d_iterator;
//   	[...]
//
//   	boost::range<a_iterator> get_a_sequence();
//   	boost::range<b_iterator> get_b_sequence();
//   	boost::range<c_iterator> get_c_sequence();
//   	boost::range<d_iterator> get_d_sequence();
//   	[...]
// 	};
//
// This design obviously suffers from compile-time dependencies just as the simpler examples that we considered earlier. Whenever I see fit to rearrange
// my sequences internally, e.g., by storing sequences C and E and have my iterators calculate B as the sum of C and E, then my clients have to recompile.
//
// Now let us analyze what kind of an interface my clients can rightfully expect of me from an object-oriented point of view. I just want to analyze the
// situation from an object oriented perspective.
//
// An interface exposes what an object does for its clients, not what the object is, and not how it does what it does. What is my number cruncher supposed
// to do for its clients? They have an enum value, and they need the corresponding sequence of numbers in the form of a pair of input iterators that
// dereference to a double. There can be little doubt as to what kind of interface we should see on an object that provides this service :
//
// 	class number_cruncher
// 	{
// 	public:
//   	boost::range<number_iterator> 
//   	get_sequence(sequence_type type);
// 	};
//
// Intead, my interface is bloated and cluttered with information that has a lot to do with how my number cruncher does what it does, and nothing with what
// it does for its clients. Focusing on the various iterator types in my interface, we see that they expose to the client what they are, when all that 
// matters is what they do for the client. The standard solution in object oriented programming is to employ runtime polymorphism to treat these 
// different types uniformly at runtime.
//
// We see that from on object oriented perspective, my clients complaints are entirely justified. Failure to employ runtime polymorphism has led to a
// poorly designed interface and strong compile-time dependencies.
//
// There are, of course, many more examples for this kind of tension between object oriented programming and generic programming. The common deeper
// reason behind all those examples is the different role that type plays in object oriented programming and in generic programming. In object
// oriented programming, the judicious choice of user-defined types is a very important, if not the most important, design tool. Take one look
// at any high-level book on object oriented analysis and design, and you'll find that it's all about the proper choice of classes and the inheritance
// relationships between them. In generic programming, on the other hand, the type system has a tendency to get away from the software designer.
// Types often end up being unrelated despite the fact that the things they represent are very much related. In other words, the multitude of types is
// merely a side effect of some generic programming technique such as policy driven design or some such thing. Were it not for these techniques, one
// would have never designed the user-defined types in that way.
//
// Now What?
//
// It is true that whenever you expose a pair of STL iterators such as std::vector<double>::const_iterator through a class interface, you are introducing
// a compile-time dependency. Moreover, as we saw in the previous section, you are getting precariously close to violating basic principles of object
// oriented programming such as encapsulation and the proper design of interfaces. But you also have an advantage on your side: when the compiler is 
// through with its inlining, your vector iterators are quite likely to perform as efficiently as plain pointers. This performance gain may well justify
// the sacrifice of object oriented purity. The important thing to understand is that there is a trade-off to be made here.
//
// Type Erasure as the Glue between object oriented and Generic Programming In their book on C++ template metaprogramming[4], Dave Abrahams and Aleksey
// Gurtovoy define type erasure as "the process of turning a wide variety of types with a common interface into one type with that same interface."
//
// The most widely known and used examples of type erasure are boost::any and boost::function. boost::function is a class template that takes one 
// template argument, a function type. Choosing a function type amounts to choosing a return type and a list of argument types for a function. Suppose
// we instantiate boost::function as follows:
//
// 	boost::function<int (int)> foo;
//
// The variable foo can now hold anything that's callable with an int as its only argument, and whose return type is convertible to int. This could be
// a function pointer, a user-defined functor, the result of a boost::bind, or what have you. Clearly, this matches the above definition of type erasure.
//
// The relevance of this in the context of object-oriented programming is that an interface can now say to the client programmer: "I need you to give me
// something that's callable as specified by this here function type. What it really is, I don't care. You can give me different things at run time. Also,
// you can change your client code so it gives me something other than it did before, and you won't have to recompile me." Or, referring to a return 
// value rather than an argument, an interface could say: "I'll give you something that's callable as specified by this here function type. What it
// really is, you won't know. It could change at run time. I might also change it at compile time, but don't worry, you won't have to recompile because
// of that"



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific method, and allowing to invoke it during run time. The difference between a
//		function and method, is that method is a function that belongs to an object
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
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
//			1. ObjectType - the type of the object the method belongs to
//			2. ReturnType - the return value type of the required function
//			3. MethodArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename FunctionType >
class Callable NotForInheritance
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( Callable );


};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Invokable ojbect with arguments   *********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ReturnType, typename... ArgumentTypes >
class Callable< ReturnType ( ArgumentTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ( ArgumentTypes... );

	// Create a type definition for this object
	using SelfType = Callable< SelfFunctionType >;


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
	inline Callable();


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
	//			rawFunctionPointer - a pointer with the memory address of the required function
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
	//		1. The given function pointer is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline Callable( SelfFunctionType const* rawFunctionPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline Callable( const FunctionPointer< SelfFunctionType >& functionPointer );


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
	//			1. instance - a refernce to the instance that will execute the method
	//			2. methodRawPointer - the memory address of the method to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType, typename MethodType = ReturnType ( ObjectType::* )( ArgumentTypes... ) >
	explicit inline Callable( ObjectType& instance, MethodType&& methodRawPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType >
	explicit inline Callable( const MethodPointerBoundToInstance< ObjectType, SelfFunctionType >& methodPointerBoundToInstance );


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
	//			1. instance - a constant refernce to the instance that will execute the method
	//			2. methodRawPointer - the memory address of the constant method to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType, typename ConstantMethodType = ReturnType ( ObjectType::* )( ArgumentTypes... ) const >
	explicit inline Callable( const ObjectType& instance, ConstantMethodType&& constantMethodRawPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType >
	explicit inline Callable( const ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType >& constantMethodPointerBoundToInstance );


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
	//			functor - a reference to the functor instance
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename FunctorType > requires ( ( Concepts::Functor< FunctorType, ArgumentTypes... > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) )
	explicit inline Callable( FunctorType& functor );


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
	//			functor - a constant reference to the functor instance
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename FunctorType > requires ( ( Concepts::Functor< FunctorType, ArgumentTypes... > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) )
	explicit inline Callable( const FunctorType& functor );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( Callable )


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
	inline ~Callable();


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments. This operator will give instances of
	//		this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()( ArgumentTypes... arguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments. This operator will give instances of
	//		this object the ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()( ArgumentTypes... arguments ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments tuple. This operator will give instances of
	//		this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argumentsTuple - A tuple with the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()( const Memory::Tuple< ArgumentTypes... >& argumentsTuple );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments tuple. This operator will give instances of
	//		this object the ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argumentsTuple - A tuple with the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()( const Memory::Tuple< ArgumentTypes... >& argumentsTuple ) const;


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( Callable );


	// This base pointer will store the memory address of the invokable object, and be used to execute it
	InvokableObjectInterface< ReturnType, ArgumentTypes... >* member_callablePointer;


    // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    // rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the function, using a tuple of arguments. Now to invoke a function using a tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the function
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. arguments - a tuple containing the arguments required to invoke the function 
    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the function using the tuple
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invoking the function will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< UnsignedInteger64bits... ArgumentIndices >
    EnsureRetrunValueIsUsed inline ReturnType InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& argumentsTuple, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


};  //  Class Callable




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Invokable object with no arguments   *********************************************//
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ReturnType >
class Callable< ReturnType () > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ();

	// Create a type definition for this object
	using SelfType = Callable< SelfFunctionType >;


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
	inline Callable();


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
	//			rawFunctionPointer - a pointer with the memory address of the required function
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
	//		1. The given function pointer is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline Callable( SelfFunctionType* const rawFunctionPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline Callable( const FunctionPointer< SelfFunctionType >& functionPointer );


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
	//			1. instance - a refernce to the instance that will execute the method
	//			2. methodRawPointer - the memory address of the method to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType, typename MethodType = ReturnType ( ObjectType::* )() >
	explicit inline Callable( ObjectType& instance, const MethodType& methodRawPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType >
	explicit inline Callable( const MethodPointerBoundToInstance< ObjectType, SelfFunctionType >& methodPointerBoundToInstance );



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
	//			1. instance - a constant refernce to the instance that will execute the method
	//			2. methodRawPointer - the memory address of the constant method to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType, typename ConstantMethodType = ReturnType ( ObjectType::* )() const >
	explicit inline Callable( const ObjectType& instance, const ConstantMethodType& constantmethodRawPointer );


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
	//			callable - a universal reference to the callable object
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename ObjectType >
	explicit inline Callable( const ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType >& constantMethodPointerBoundToInstance );


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
	//			functor - a reference to the functor instance
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< Concepts::Functor FunctorType > requires ( ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, SelfFunctionType > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, SelfFunctionType > > ) )
	explicit inline Callable( FunctorType& functor );


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
	//			functor - a constant reference to the functor instance
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< Concepts::Functor FunctorType > requires ( ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, SelfFunctionType > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, SelfFunctionType > > ) )
	explicit inline Callable( const FunctorType& functor );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( Callable )


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
	inline ~Callable();


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance. This operator will give instances of this object the ability
	//		to be used as if they are functions
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
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()();


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance. This operator will give instances of this object the ability
	//		to be used as if they are functions. This version is for constant instances
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
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed inline ReturnType operator()() const;


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { Callable< UnsignedInteger64bits ( UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( Callable );


	// This base pointer will store the memory address of the invokable object, and be used to execute it
	InvokableObjectInterface< ReturnType >* member_callablePointer;


};  //  Class Callable