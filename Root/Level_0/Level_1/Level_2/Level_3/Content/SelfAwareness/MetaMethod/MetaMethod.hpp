#ifndef METAMETHOD_HPP
#define METAMETHOD_HPP


#include "../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../Abilities/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../FunctionAndMethodPointers/MethodPointer/MethodPointer.hpp"  //  Class MethodPointer
#include "../../Memory/Platforms/AsciiLiteral/AsciiLiteral.hpp"  //  AsciiLiteral


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace Meta
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



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						object using the tools presented here. This part will usually contain only methods and not data members. If a data
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
		//			1. Type -
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		class MetaMethod NotForInheritance : public MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >
		{
		public:


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
			inline MetaMethod();


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
			//			1. methodMemoryAddress - the memory address of the method this instance comes to describe
			//			2. objectName - the name of the object that conatins the method
			//			3. methodName - the name of the method
			//			4. fileName - the name of the file that contains the method
			//			5. namespaceName - the namespace that contains the method ( Universe is the main namespace, this should be the subnamespace, if there isn't provide 'NONE' )
			//			6. constantOrNot - a boolean to describe if the method is marked as constant or not
			//			7. staticOrNot - a boolean to describe if the method is markes as static or not
			//			8. operatorOrNot - a boolean to describe if this is an operator
			//			9. inlineOrNot - a boolean to describe if the method is inline ( true ) or not ( false )
			//			10. constantExpressionOrNot - a boolean to describe if the method is a constant expression ( true ) or not ( false )
			//			11. encapsulationClassification - the encapsulation classification of the method, public ( 0 ), protected ( 1 ) and private ( 2 )
			//			12. canThrowExceptionOrNot - a boolean to describe if the method can throw an exception or not
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
			inline MetaMethod( typename MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerType methodMemoryAddress, Memory::AsciiLiteral objectName, Memory::AsciiLiteral methodName, Memory::AsciiLiteral fileName, Memory::AsciiLiteral namespaceName, Boolean constantOrNot = false, Boolean staticOrNot = false, Boolean operatorOrNot = false, Boolean inlineOrNot = false, Boolean constantExpressionOrNot = false, UnsignedInteger8bits encapsulationClassification = 0U, Boolean canThrowExceptionOrNot = false );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Reset
			//		2. State
			//
			TemplateObjectForInheritanceInfrastructureOnlyResetAndState_MACRO( MetaMethod, ObjectType, ReturnValueType, MethodArgumentsTypes... )


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
			inline void Swap( MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other );


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
			//			1. methodMemoryAddress - the memory address of the method this instance comes to describe
			//			2. objectName - the name of the object that conatins the method
			//			3. methodName - the name of the method
			//			4. fileName - the name of the file that contains the method
			//			5. namespaceName - the namespace that contains the method ( Universe is the main namespace, this should be the subnamespace, if there isn't provide 'NONE' )
			//			6. constantOrNot - a boolean to describe if the method is marked as constant or not
			//			7. staticOrNot - a boolean to describe if the method is markes as static or not
			//			8. operatorOrNot - a boolean to describe if this is an operator
			//			9. inlineOrNot - a boolean to describe if the method is inline ( true ) or not ( false )
			//			10. constantExpressionOrNot - a boolean to describe if the method is a constant expression ( true ) or not ( false )
			//			11. encapsulationClassification - the encapsulation classification of the method, public ( 0 ), protected ( 1 ) and private ( 2 )
			//			12. canThrowExceptionOrNot - a boolean to describe if the method can throw an exception or not
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
			//		They will come
			//
			inline void Initiate( typename MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerType methodMemoryAddress, Memory::AsciiLiteral objectName, Memory::AsciiLiteral methodName, Memory::AsciiLiteral fileName, Memory::AsciiLiteral namespaceName, Boolean constantOrNot = false, Boolean staticOrNot = false, Boolean operatorOrNot = false, Boolean inlineOrNot = false, Boolean constantExpressionOrNot = false, UnsignedInteger8bits encapsulationClassification = 0U, Boolean canThrowExceptionOrNot = false );


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
			virtual ~MetaMethod() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the function pointer from which the function can be invoked
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
			//		The function pointer from which the function can be invoked
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... > GetMethodPointer() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the object name that contains the method
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
			//		The object name that contains the method
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Memory::AsciiLiteral ObjectName() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the method name
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
			//		An ascii literal containing the method name
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Memory::AsciiLiteral Name() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the file name containing the method
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
			//		An ascii literal containing the file name containing the method
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Memory::AsciiLiteral FileName() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the namespace surronding the method
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
			//		An ascii literal containing the namespace surronding the method
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Memory::AsciiLiteral Namespace() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the method is marked as constant
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
			//		A boolean with the value true if this method is marked as constant, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Constant() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if this method is marked as static
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
			//		A boolean with the value true if this method is marked as static, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Static() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if this is an operator
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
			//		A boolean with the value true if this is an operator, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Operator() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the method is marked as inline
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
			//		A boolean with the value true if the method is marked as inline, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Inline() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the method is marked as constant expression
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
			//		A boolean with the value true if the method is marked as constant expression, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean ConstantExpression() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the encapsulation classification of the method
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
			//		A boolean with the value true if the encapsulation classification of the method :
			//
			//			1. public - 0
			//			2. protected - 1
			//			3. private - 2
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean EncapsulationClassification() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the method can throw an exception
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
			//		A boolean with the value true if the method can throw an excpetion, and false otherwise
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean CanThrowException() const;


			// The following methods declare the overloaded operators for the object :


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
			//			other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator==( const MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are not the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator!=( const MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const;


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


        	// Disable all copy and move related methods
            DisableCopyAndMove_MACRO( MetaMethod )


 			// This object will be used to monitor the state of each instance
 			Abilities::State member_state;

 			// This object will store the name of the object containing the method
 			Memory::AsciiLiteral member_objectName;

 			// This object will store the method name
 			Memory::AsciiLiteral member_methodName;

 			// This object will store the file name of the method
 			Memory::AsciiLiteral member_fileName;

 			// This object will store the namespace of the method
 			Memory::AsciiLiteral member_namespace;

 			// This object will store if the method is marked is constant, which means it does not change the state of the instance
 			Boolean member_constantOrNot;

 			// This object will store if the method is marked as static, which means it does not belong to any specific instance
 			Boolean member_staticOrNot;

 			// This object will store if this is an operator or not
 			Boolean member_operatorOrNot;

 			// This object will store if the method is marked as inline
 			Boolean member_inlineOrNot;

 			// This object will store if the method is marked as constant expression
 			Boolean member_constantExpressionOrNot;

 			// This object will store if the method is public ( 0 ), protected ( 1 ) or private ( 2 )
 			UnsignedInteger8bits member_encapsulationClassification;

 			// This object will store if the method throws an exception
 			Boolean member_canThrowExceptionOrNot;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
			//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
			//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
			//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
			//		run time
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
			//      NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const;


		};  //  Class MetaMethod




































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
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MetaMethod() :
		MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >(),
		member_state(),
		member_objectName(),
		member_methodName(),
		member_fileName(),
		member_namespace(),
		member_constantOrNot( false ),
		member_staticOrNot( false ),
		member_operatorOrNot( false ),
		member_inlineOrNot( false ),
		member_constantExpressionOrNot( false ),
		member_encapsulationClassification( 0U ),
		member_canThrowExceptionOrNot( false )
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
		//			1. methodMemoryAddress - the memory address of the method this instance comes to describe
		//			2. objectName - the name of the object that conatins the method
		//			3. methodName - the name of the method
		//			4. fileName - the name of the file that contains the method
		//			5. namespaceName - the namespace that contains the method ( Universe is the main namespace, this should be the subnamespace, if there isn't provide 'NONE' )
		//			6. constantOrNot - a boolean to describe if the method is marked as constant or not
		//			7. staticOrNot - a boolean to describe if the method is markes as static or not
		//			8. operatorOrNot - a boolean to describe if this is an operator
		//			9. inlineOrNot - a boolean to describe if the method is inline ( true ) or not ( false )
		//			10. constantExpressionOrNot - a boolean to describe if the method is a constant expression ( true ) or not ( false )
		//			11. encapsulationClassification - the encapsulation classification of the method, public ( 0 ), protected ( 1 ) and private ( 2 )
		//			12. canThrowExceptionOrNot - a boolean to describe if the method can throw an exception or not
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
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MetaMethod( typename MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerType methodMemoryAddress, Memory::AsciiLiteral objectName, Memory::AsciiLiteral methodName, Memory::AsciiLiteral fileName, Memory::AsciiLiteral namespaceName, Boolean constantOrNot, Boolean staticOrNot, Boolean operatorOrNot, Boolean inlineOrNot, Boolean constantExpressionOrNot, UnsignedInteger8bits encapsulationClassification, Boolean canThrowExceptionOrNot ) :
		MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >( methodMemoryAddress ),
		member_state(),
		member_objectName( objectName ),
		member_methodName( methodName ),
		member_fileName( fileName ),
		member_namespace( namespaceName ),
		member_constantOrNot( constantOrNot ),
		member_staticOrNot( staticOrNot ),
		member_operatorOrNot( operatorOrNot ),
		member_inlineOrNot( inlineOrNot ),
		member_constantExpressionOrNot( constantExpressionOrNot ),
		member_encapsulationClassification( encapsulationClassification ),
		member_canThrowExceptionOrNot( canThrowExceptionOrNot )
		{}


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
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline void MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Swap( MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other )
		{
			// Swap between the method pointers
			MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Swap( other );

		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the file name
		    member_objectName.Swap( other.member_objectName );

		    // Swap between the method name
		    member_methodName.Swap( other.member_methodName );

		    // Swap between the file name
		    member_fileName.Swap( other.member_fileName );

		    // Swap between the namespace name
		    member_namespace.Swap( other.member_namespace );

			// Swap between the booleans that describe if this is a constant method or not
		    Memory::Operations::Swap< Boolean >( member_constantOrNot, other.member_constantOrNot );	

			// Swap between the booleans that describe if this is a static method or not
		    Memory::Operations::Swap< Boolean >( member_staticOrNot, other.member_staticOrNot );	

			// Swap between the booleans that describe if this is an operator or not
		    Memory::Operations::Swap< Boolean >( member_operatorOrNot, other.member_operatorOrNot );		    

		    // Swap between the booleans that describe if the the method is inline or not
		    Memory::Operations::Swap< Boolean >( member_inlineOrNot, other.member_inlineOrNot );

		    // Swap between the booleans that describe if the method is constant expression or not
		    Memory::Operations::Swap< Boolean >( member_constantExpressionOrNot, other.member_constantExpressionOrNot );

		    // Swap between the integers that describe if the method encapsulation classification
		    Memory::Operations::Swap< UnsignedInteger8bits >( member_encapsulationClassification, other.member_encapsulationClassification );

		    // Swap between the booleans that describe if the method can throw an exception
		    Memory::Operations::Swap< Boolean >( member_canThrowExceptionOrNot, other.member_canThrowExceptionOrNot );
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
		//			1. methodMemoryAddress - the memory address of the method this instance comes to describe
		//			2. objectName - the name of the object that conatins the method
		//			3. methodName - the name of the method
		//			4. fileName - the name of the file that contains the method
		//			5. namespaceName - the namespace that contains the method ( Universe is the main namespace, this should be the subnamespace, if there isn't provide 'NONE' )
		//			6. constantOrNot - a boolean to describe if the method is marked as constant or not
		//			7. staticOrNot - a boolean to describe if the method is markes as static or not
		//			8. operatorOrNot - a boolean to describe if this is an operator
		//			9. inlineOrNot - a boolean to describe if the method is inline ( true ) or not ( false )
		//			10. constantExpressionOrNot - a boolean to describe if the method is a constant expression ( true ) or not ( false )
		//			11. encapsulationClassification - the encapsulation classification of the method, public ( 0 ), protected ( 1 ) and private ( 2 )
		//			12. canThrowExceptionOrNot - a boolean to describe if the method can throw an exception or not
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
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline void MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Initiate( typename MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerType methodMemoryAddress, Memory::AsciiLiteral objectName, Memory::AsciiLiteral methodName, Memory::AsciiLiteral fileName, Memory::AsciiLiteral namespaceName, Boolean constantOrNot, Boolean staticOrNot, Boolean operatorOrNot, Boolean inlineOrNot, Boolean constantExpressionOrNot, UnsignedInteger8bits encapsulationClassification, Boolean canThrowExceptionOrNot )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... > temporary( methodMemoryAddress, objectName, methodName, fileName, namespaceName, constantOrNot, staticOrNot, operatorOrNot, inlineOrNot, constantExpressionOrNot, encapsulationClassification, canThrowExceptionOrNot );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the function pointer from which the function can be invoked
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
		//		The function pointer from which the function can be invoked
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... > MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::GetMethodPointer() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::GetMethodPointer failed - the instance is not ready" )

			// Return the method pointer
			return ( *this );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the object name that contains the method
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
		//		The object name that contains the method
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Memory::AsciiLiteral MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::ObjectName() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Name failed - the instance is not ready" )

			// Return the method name
			return ( member_methodName );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the method name
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
		//		An ascii literal containing the method name
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Memory::AsciiLiteral MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Name() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Name failed - the instance is not ready" )

			// Return the method name
			return ( member_methodName );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the file name containing the method
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
		//		An ascii literal containing the file name containing the method
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Memory::AsciiLiteral MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::FileName() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::FileName failed - the instance is not ready" )

			// Return the file name containing the method
			return ( member_fileName );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the namespace surronding the method
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
		//		An ascii literal containing the namespace surronding the method
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Memory::AsciiLiteral MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Namespace() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Namespace failed - the instance is not ready" )

			// Return the namespace surronding the method
			return ( member_namespace );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the method is marked as constant
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
		//		A boolean with the value true if this method is marked as constant, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Constant() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Constant failed - the instance is not ready" )

			// Return if this method is marked as constant
			return ( member_constantOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if this method is marked as static
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
		//		A boolean with the value true if this method is marked as static, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Static() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Static failed - the instance is not ready" )

			// Return if this method is marked as static
			return ( member_staticOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if this is an operator
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
		//		A boolean with the value true if this is an operator, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Operator() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Operator failed - the instance is not ready" )

			// Return if this is an operator
			return ( member_operatorOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the method is marked as inline
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
		//		A boolean with the value true if the method is marked as inline, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Inline() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::Inline failed - the instance is not ready" )

			// Return if the method is marked as inline or not
			return ( member_inlineOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the method is marked as constant expression
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
		//		A boolean with the value true if the method is marked as constant expression, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::ConstantExpression() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::ConstantExpression failed - the instance is not ready" )

			// Return if the method is marked as constant expression or not
			return ( member_constantExpressionOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the encapsulation classification of the method
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
		//		A boolean with the value true if the encapsulation classification of the method :
		//
		//			1. public - 0
		//			2. protected - 1
		//			3. private - 2
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::EncapsulationClassification() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::EncapsulationClassification failed - the instance is not ready" )

			// Return the encapsulation classification of the method
			return ( member_encapsulationClassification );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the method can throw an exception
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
		//		A boolean with the value true if the method can throw an excpetion, and false otherwise
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::CanThrowException() const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.GetState() == Abilities::State::Ready ), "Meta::MetaMethod::CanThrowException failed - the instance is not ready" )

			// Return if the method can throw an exception
			return ( member_canThrowExceptionOrNot );
		}




































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































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
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator==( const MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const
		{
			// Check if both instances point to the same function, and return the result
			return ( MethodPointer< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator==( other ) );
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
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are not the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline Boolean MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator!=( const MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}






































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
		//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
		//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
		//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
		//		run time
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
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
		inline void MetaMethod< ObjectType, ReturnValueType, MethodArgumentsTypes... >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
		{
			// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
			//CompileTimeAssert();
		}





































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			class Test_1
			{
			public:

				Test_1() : member_state( Abilities::State::Ready ) {}

				UnsignedInteger64bits Voyge( UnsignedInteger64bits, void*, UnsignedInteger64bits, Boolean )
				{
					return 998;
				}

				Abilities::State State() const
				{
					return ( member_state );
				}

				Abilities::State member_state;

			};

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
			template< typename ObjectType COMMA typename ReturnValueType COMMA typename... MethodArgumentsTypes >
			void MetaMethod< ObjectType COMMA ReturnValueType COMMA MethodArgumentsTypes... >::Test()
			{
				// Create an instance
				MetaMethod< Test_1 COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA void* COMMA UnsignedInteger64bits COMMA Boolean > testMetaMethod_1;

				// Initiate the instance
				testMetaMethod_1.Initiate( &Test_1::Voyge, "Test_1", "Voyge", __FILE__, "Meta" );

				// Create an instance
				Test_1 testObject_1;

				// Invoke the function
				testMetaMethod_1.Invoke( testObject_1, 889, 0, 445, true );
			}

		)  //  End of debug tool











    }  //  Namespace Meta

}  //  Namespace Universe



#endif  // METAMETHOD_HPP