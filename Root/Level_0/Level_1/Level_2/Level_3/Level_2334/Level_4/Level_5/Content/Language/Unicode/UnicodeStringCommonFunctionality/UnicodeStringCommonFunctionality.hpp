#ifndef UNICODESTRINGCOMMONFUNCTIONALITY_HPP
#define UNICODESTRINGCOMMONFUNCTIONALITY_HPP


#include "../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../FunctionalityBranch/Level_0/Level_1/Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../FunctionalityBranch/Level_0/Content/Random/Generator/Generator.hpp"  //  Class Generator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe
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


	namespace Language
    {


		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
   	    //  Description :
   	    //
		//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
		//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
		//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
		//		   Take a look at next example :
		//
		//				class Base
		//				{
		//				    void Display() { cout << "Lord" << endl; }
		//				};
		//
		//				class Derived : public Base
		//				{
		//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
		//				};
		//
		//         Now if a call is made :
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				base->Display( 5 );   -> Outputs "Lord"
		//				derived->Display();   -> Outputs "Help Me"
		//
		//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
		//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
		//		   to derived objects with base pointers and that the correct method will be called. But now :
		//
		//				void Do( Base* base ) { base->Display(); }
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				Do( base );        -> Outputs "Lord"
		//				Do( derived );     -> Outputs "Lord"
		//
		//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
		//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
		//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
		//		   be overloaded for each one
		//
		//		2. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		//		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		//		4. Template arguments :
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
		template< template< typename > class SequentialPlatformType >
        class UnicodeStringCommonFunctionality
        {
        public:


            // Create a type definition for this object
			using SelfType = UnicodeStringCommonFunctionality< SequentialPlatformType >;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//   	Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
			//
			//  Required arguments :
			//
			//   	User information needed :
			//
			//          NONE
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ~UnicodeStringCommonFunctionality() = default;


			// The following methods are the interface of the object :











			// The following methods declare the overloaded operators for the object :



			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members



			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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


		protected:


			// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
			// members or methods


			// Method Information :
			//
			//  Description :
			//
			//   	Constructor, it is decalred protected to ensure that only object that drive from it will be able to create instances of it
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//          unicodeString - a reference to a sequential platform that contains the unicode characters of the unicode string object
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
	        inline UnicodeStringCommonFunctionality( SequentialPlatformType< UnicodeCharacter >& unicodeString );


		private:


			// This object will store a reference to the sequential platform of the unicode string that will inherit from this object
			SequentialPlatformType< UnicodeCharacter >& member_unicodeString;


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


		};  //  Class UnicodeStringCommonFunctionality




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************
































		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-8    	
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-8
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
	    inline UnsignedInteger64bits GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8() const
	    {
	    	// This object will store the number of bytes needed to compress the unicode string into UTF-8
	    	UnsignedInteger64bits numberBytesNeededToCompressUnicodeStringAs_UTF8 = 0UL;

	    	// Loop on all the unicode characters
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
				// Get the number of bytes needed to compress the current unicode character as UTF-8, and add it to the total number
				numberBytesNeededToCompressUnicodeStringAs_UTF8 += member_unicodeString[ unicodeStringIndex ].GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8();
	    	}

	    	// Return the number of bytes needed to compress the unicode string into UTF-8
	    	return ( numberBytesNeededToCompressUnicodeStringAs_UTF8 );
	    }


		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-16
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-16
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
	    inline UnsignedInteger64bits GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF16() const
	    {
	    	// This object will store the number of bytes needed to compress the unicode string into UTF-16
	    	UnsignedInteger64bits numberBytesNeededToCompressUnicodeStringAs_UTF16 = 0UL;

	    	// Loop on all the unicode characters
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
				// Get the number of bytes needed to compress the current unicode character as UTF-16, and add it to the total number
				numberBytesNeededToCompressUnicodeStringAs_UTF16 += member_unicodeString[ unicodeStringIndex ].GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF16();
	    	}

	    	// Return the number of bytes needed to compress the unicode string into UTF-16
	    	return ( numberBytesNeededToCompressUnicodeStringAs_UTF16 );
	    }


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode string as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF8_compression - a pointer to the memory address where to store the unicode string compressed as UTF-8
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes needed to compress the unicode string as UTF-8
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-8 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		inline void UnicodeStringCommonFunctionality< SequentialPlatformType >::CompressAs_UTF8( UnsignedInteger8bits* destinationToStore_UTF8_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF8_compression )

			// This object will store the current number of bytes needed to compress as UTF-8
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
	    		// Compress the current unicode character and store at the destination
				numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter = member_unicodeString[ unicodeStringIndex ].CompressAs_UTF8( destinationToStore_UTF8_compression );

				// Advance the pointer to the location to store the next unicode character
				destinationToStore_UTF8_compression += numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode string as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF16_compression - a pointer to the memory address where to store the unicode string compressed as UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes needed to compress the unicode string as UTF-16
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-16 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		void UnicodeStringCommonFunctionality< SequentialPlatformType >::CompressAs_UTF16( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF16_compression )

			// This object will store the current number of bytes needed to compress as UTF-16
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF16_currentUnicdoeCharacter = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
	    		// Compress the current unicode character and store at the destination
				numberOfBytesNeededToCompressAs_UTF16_currentUnicdoeCharacter = member_unicodeString[ unicodeStringIndex ].CompressAs_UTF16( destinationToStore_UTF16_compression );

				// Advance the pointer to the location to store the next unicode character
				destinationToStore_UTF16_compression += numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode UTF-8 into a unicode scalar value and store inside this instance
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_compression - a pointer to the memory address where the unicode scalar value compressed as UTF-8 is stored
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes the compressed unicode scalar value as UTF-8 contains
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given UTF-8 is compressed correctly
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		UnsignedInteger64bits UnicodeCharacter::DecompressFrom_UTF8( const UnsignedInteger8bits* UTF8_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF8_compression )

			// This object will store the size needed to be allocated in order to store the decompressed UTF-8 unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8( UTF8_compression, sizeInBytes_UTF8_compression );

			
		}


































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************










































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************


























































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************



































		// Method Information :
		//
		//  Description :
		//
		//   	Constructor, it is decalred protected to ensure that only object that drive from it will be able to create instances of it
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//          unicodeString - a reference to a sequential platform that contains the unicode characters of the unicode string object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< template< typename > class SequentialPlatformType >
        inline UnicodeStringCommonFunctionality< SequentialPlatformType >::UnicodeStringCommonFunctionality( SequentialPlatformType< UnicodeCharacter >& unicodeString ) :
		member_unicodeString( unicodeString )
		{}


































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************


































		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-8
		//			2. sizeInBytes_UTF8_compression - the size in bytes of the UTF-8 compression
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-8 was compressd correctly
		//		3. The given size should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline UnsignedInteger64bits UnicodeCharacter::GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger64bits sizeInBytes_UTF8_compression )
		{
			// This object will store the size needed to be allocated in order to store the decompressed unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = 0UL;

			// This object will store the number of bytes needed to compress the current unicode scalar value
			UnsignedInteger64bits numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits UTF8_compressionIndex = 0UL ; UTF8_compressionIndex < sizeInBytes_UTF8_compression ; UTF8_compressionIndex += numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 )
	    	{
	    		// Get the number of bytes needed to compress the current unicode scalar value
	    		numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 = UnicodeCharacter::GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8( UTF8_compression );

	    		// Increment by 1 the number of decompressed unicode string size
	    		decompressedUnicodeStringSize += 1UL;
	    	}

	    	// Return the size that decompressed unicode string will hold
	    	return ( decompressedUnicodeStringSize );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF16_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-16
		//			2. sizeInPairBytes_UTF16_compression - the size in bytes of the UTF-16 compression
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-16 was compressd correctly
		//		3. The given size should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline UnsignedInteger64bits GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( const UnsignedInteger16bits* UTF16_compression, UnsignedInteger64bits sizeInPairBytes_UTF16_compression )
		{
			// This object will store the size needed to be allocated in order to store the decompressed unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = 0UL;

			// This object will store the number of bytes needed to compress the current unicode scalar value
			UnsignedInteger64bits numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits UTF16_compressionIndex = 0UL ; UTF16_compressionIndex < sizeInPairBytes_UTF8_compression ; UTF16_compressionIndex += numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 )
	    	{
	    		// Get the number of bytes needed to compress the current unicode scalar value
	    		numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 = UnicodeCharacter::GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( UTF16_compression );

	    		// Increment by 1 the number of decompressed unicode string size
	    		decompressedUnicodeStringSize += 1UL;
	    	}

	    	// Return the size that decompressed unicode string will hold
	    	return ( decompressedUnicodeStringSize );
		}





































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************




































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
			//          NONE
			//
			//      Information returned to the user :
			//
			//          NONE
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
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< template< typename > class SequentialPlatformType >
			void UnicodeStringCommonFunctionality< SequentialPlatformType >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< SelfType,  >();
			}

		)  //  End of debug tool











    }  //  Namespace Language

}  //  Namespace Universe


#endif  // UNICODESTRINGCOMMONFUNCTIONALITY_HPP