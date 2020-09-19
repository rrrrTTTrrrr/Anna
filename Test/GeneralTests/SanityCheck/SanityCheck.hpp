#ifndef SANITYCHECK_HPP
#define SANITYCHECK_HPP


#include "../../../Root/Level_0/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../Root/Level_0/Level_1/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../Root/Level_0/Level_1/Level_2/Level_3/Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../Root/Level_0/Level_1/Level_2/Content/NumericRange/NumericRange.hpp"  //  Class NumericRange
#include "../../../Root/Level_0/Level_1/Level_2/Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../Root/Level_0/Content/Metaprogramming/CommonFunctionality/Sequences/IncrementingIntegerSequenceGenerator/IncrementingIntegerSequenceGenerator.hpp"  //  Class IncrementingIntegerSequenceGenerator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../TestingTools/Objects/TestObject_1/TestObject_1.hpp"  //  Class TestObject_1
#endif


namespace Universe
{

    namespace Testing
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



		// In order to take the address of an overloaded method, use static cast :
		//
		//		static_cast< void (ObjectType::*)( int ) >( &ObjectType::MethodName )
    	//
		//		static_cast< void (ObjectType::*)( int, long ) >( &ObjectType::MethodName )



		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to perform a sanity test on an object. It basically will check all the functionality each object in the system
		//		must have. It has also capability to check various types of objects, like an object without copy constructor and assignment
		//		operator and more
		//
   	    //  Description :
   	    //
		//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
		//		   an interface which conatins only static methods, and does not need to never be instantied
		//
		//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
		class SanityCheck
		{
		public:


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object needs to have. This check is
			//		for object that does not provide copy constructor and assignment operator. The methods that will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Copy constructor
			//			5. Assignment operator
			//			6. Move constructor
			//			7. Move assignment operator
			//			8. Destructor
			//			9. Reset
			//			10. Swap
			//			11. Equal operator
			//			12. Not equal operator
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void Full( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform = 1000UL );


 			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on an object that has state always ready. It will test all the basic functionality each 
			//		object needs to have. This check is for object that does not provide copy constructor and assignment operator. The methods that 
			//		will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Copy constructor
			//			5. Assignment operator
			//			6. Move constructor
			//			7. Move assignment operator
			//			8. Destructor
			//			9. Reset
			//			10. Swap
			//			11. Equal operator
			//			12. Not equal operator
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void Full_ForObjectWithStateAlwaysReady( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform = 1000UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object needs to have. This check is
			//		for object that does not provide copy constructor and assignment operator. The methods that will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Copy constructor
			//			5. Assignment operator
			//			6. Destructor
			//			7. Reset
			//			8. Swap
			//			9. Equal operator
			//			10. Not equal operator
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void NoMoveConstructorAndMoveAssignmentOperator( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform  = 1000UL);


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object needs to have. This check is
			//		for object that does not provide copy constructor, move constructor, assignment operator and move assignment operator. The methods that 
			//		will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Move constructor
			//			5. Move assignment operator
			//			6. Destructor
			//			7. Reset
			//			8. Swap
			//			9. Equal operator
			//			10. Not equal operator
			//
			//		This method should be used to check only objects that contains the above methods!
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void NoCopyConstructorAndAssignmentOperator( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform = 1000UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object needs to have. This check is
			//		for object that does not provide copy constructor, move constructor, assignment operator and move assignment operator. The methods that 
			//		will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Destructor
			//			5. Reset
			//			6. Swap
			//			7. Equal operator
			//			8. Not equal operator
			//
			//		This method should be used to check only objects that contains the above methods!
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static void NoCopyOrMove( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform = 1000UL );


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
				static void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


			// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SanityCheck )


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object needs to have. This check is
			//		for object that does not provide copy constructor and assignment operator. The methods that will be checked are :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Copy constructor
			//			5. Assignment operator
			//			6. Move constructor
			//			7. Move assignment operator
			//			8. Destructor
			//			9. Reset
			//			10. Swap
			//			11. Equal operator
			//			12. Not equal operator
			//
			//		This method is a wrapper to the private method that does the actual work, it is used to create an incrementing integer sequence and to
			//		pass it to the private method, so it could use the compiler to unpack the tuple members
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void Full__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test mainly the copy constructor and assignment operator, but in order
			//		to test it a few more methods are needed. The methods that will be checked are :
			//
			//			1. Default constructor
			//			2. Destructor
			//			3. Reset
			//			4. State
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          testInstance - an instance of the object ready to use
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. The instance should be ready to use
			//		3. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
		 	static inline void DefaultConstructor__Private();


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. It will test all the basic functionality each object must have. The
			//		test requires the following methods :
			//
			//			1. Default constructor
			//			2. Parameterized constructor
			//			3. Random constructor
			//			4. Destructor
			//			5. Reset
			//			6. Swap
			//			7. Equal operator
			//			8. Not equal operator
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
		    //          3. An incrementing integer sequence, it is part of the functionality required to invoke the parameterized constructor using the tuple
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< UnsignedInteger64bits... ArgumentIndices >
		 	static inline void TestFunctionalityThatEachObjectMustHave__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. The purpose is to test the copy constructor and assignment operator. The
			//		test requires the following methods :
			//
			//			1. Random constructor
			//			2. Copy constructor
			//			3. Assignment operator
			//			4. Destructor
			//			5. Reset
			//			6. Swap
			//			7. State
			//			8. Equal operator
			//			9. Not equal operator
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
		    //          3. An incrementing integer sequence, it is part of the functionality required to invoke the parameterized constructor using the tuple
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< UnsignedInteger64bits... ArgumentIndices >
		 	static inline void Test_CopyConstructor_AssignmentOperator__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perform a sanity check on the object. The purpose is to test the move constructor and move assignment operator. The
			//		requires the following methods :
			//
			//			1. Random constructor
			//			2. Move constructor
			//			3. Move assignment operator
			//			4. Destructor
			//			5. Reset
			//			6. Swap
			//			7. State
			//			8. Equal operator
			//			9. Not equal operator
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. constructorArgumentConstraintsTuple - a constant reference to a tuple instance with the constraints on the constructor arguments
			//          2. numberOfIterationsToPerform - the number of iterations to perform during the sanity check
		    //          3. An incrementing integer sequence, it is part of the functionality required to invoke the parameterized constructor using the tuple
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
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< UnsignedInteger64bits... ArgumentIndices >
		 	static inline void Test_MoveConstructor_MoveAssignmentOperator__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


		};  //  Class SanityCheck



#include "SanityCheck.inl"



    }  //  Namespace Testing

}  //  Namespace Universe


#endif  // SANITYCHECK_HPP