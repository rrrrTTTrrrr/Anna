#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP


#include "../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/ShallowCopy/TypeCheck_ShallowCopy/TypeCheck_ShallowCopy.hpp"  //  Class TypeCheck_ShallowCopy
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/BuiltIn/TypeCheck_BuiltInType/TypeCheck_BuiltInType.hpp"  //  Class TypeCheck_BuiltInType
#include "./Aid/Aid.hpp"  //  Class Aid


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



        // To create an rvalue in C++ a static cast must be used -> static_cast< TYPE&& >( object ) 
        //
        // The cast is needed because named rvalue reference is treated as lvalue, and implicit conversion from lvalue to rvalue reference is forbidden by standard



        // The association with a name gives an object scope which controls its lifetime. If it is given a name, then it is bound to the scope that the name is declared in. By 
        // not naming an object, it's lifetime is bound to the statement. The object is created and destroyed instantaneously because it is not associated with a name



        // By design, C++ only allows a temporary to be passed to a const reference, value, or rvalue reference. The idea is that a function taking a non-const reference 
        // parameter is stating that it wants to modify the parameter and allowing it to go back to the caller. Doing so with a temporary is meaningless and most likely 
        // an error



	    // In C89/90 an unsuffixed decimal constant must be interpreted as int, long or unsigned long ( whichever fits first ). In C99 it must be interpreted as int, long or 
        // long long ( whichever fits first ). The compiler can be given explicit information that it's an unsigned integer by suffixing it with "U", as:
        //
        //      2147483648U
        //
        // Note that you can also add a suffix of "L" to make it a "long", but on many systems that's still 32-bit and thus irrelevant



        // The name of an array usually evaluates to the address of the first element of the array, so array and &array have the same value ( but different types, so array + 1 
        // and &array + 1 will not be equal if the array is more than 1 element long )
        //
        // There are two exceptions to this, when the array name is an operand of sizeof or unary & ( address-of ), the name refers to the array object itself. Thus sizeof 
        // array gives you the size in bytes of the entire array, not the size of a pointer
        //
        // For an array defined as T array[size], it will have type T *. When/if you increment it, you get to the next element in the array
        //
        // &array evaluates to the same address, but given the same definition, it creates a pointer of the type T(*)[size] -- i.e., it's a pointer to an array, not to a single 
        // element. If you increment this pointer, it'll add the size of the entire array, not the size of a single element



		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
   	    //  Description :
   	    //
		//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
		//		   an interface which conatins only static methods, and does not need to never be instantied
		//
		//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
		//
		//		3. Most of the methods in this object are selected according to template type automatically without the user knowledge. This is needed
		//		   because shallow copy types can be just byte copied to the new location, while objects require constructors to be called to copy them. 
		//		   This is possible due to subtitution failure is not an error, which is implemented in code through the 'ProvideTypeOnlyIfAssertionIsTrue' 
		//		   object. It will be operated on the return value of the method, and to construct it the expression given to the 
		//		   'ProvideTypeOnlyIfAssertionIsTrue' constructor will be the question if the type is primitve. Then only when the type is primitve the 
		//		   'ProvideTypeOnlyIfAssertionIsTrue' will create a type definiton inside it of the type 'void', because the method return nothing. 
		//		   Lastly for the 'Bit' object type a template specialization will be created
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class Operations
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
	        //      Use this method to swap the content of the given two arrays. This method is one of two methods that perform the swapping of memory areas.
	        //		This method is for single instances, and the second one is for arrays
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. firstInstance - a reference to the first instance to swap
	        //          2. secondInstance - a reference to the second instance to swap
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      NONE
	        //
	        //  Exceptions :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename AnyType >
	        static inline void Swap( AnyType& firstInstance, AnyType& secondInstance );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to swap the content of the given two arrays. This method is one of two methods that perform the swapping of memory areas.
	        //		The first method is for single instances, and this one is for arrays 
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. firstMemoryAddress - a pointer to the first memory address with array to swap
	        //          2. secondMemoryAddress - a pointer to the second memory address with array to swap
	        //			3. size - the size in terms of the template type
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      NONE
	        //
	        //  Exceptions :
	        //
	        //      1. The pointer to the first memory address should not be NULL
	        //      2. The pointer to the second memory address should not be NULL
	        //      3. The pointers must point to different memory addresses 
	        //      4. The size must be larger then 0
	        //      5. The destination pointer contains an address with enough memory space allocated to copy the source ( there is no way at this level to
	        //         verify that enough memory space was allocated in the address the destination points too )
	        //      6. The given template type must be primitve
	        //      7. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename AnyType >
	        static inline void Swap( AnyType* firstMemoryAddress, AnyType* secondMemoryAddress, UnsignedInteger64bits size );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to copy content in memory to another location. The method takes into account if the source memory address is lower 
	        //      or higher then the destination memory address. If the source address is lower then the copy will begin from the end of the source
	        //      memory area to copy, and if it is higher the copy will start from the beginning of the memory area. This is needed to avoid writing
	        //      into locations that needs to be read afterwards for the copy, in other words, when the source and destination memory areas overlaps. 
	        //		Visually :
	        //
	        //
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 7 8 9
	        //
	        //
	        //      As can be seen if the copying will start from the beginning of the source memory address, the first writing to the destination memory
	        //		address will erase the data, then after it the situation will look :
	        //
	        //                  
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 4 8 9
	        //
	        //
	        //		Which is of course unwanted. Then the check is dont to avoid it. Now if the source and destination memory addresses are equal then 
	        //     	there is nothing to do, this situation will be asserted! 
	        //
	        //      This method is one of two methods that perform the copying of memory areas. This method is enabled only for objects that can be shallow
	        //		copied and have a size less then 8 bytes, and the second is for object that can not be shallow copied or has a size of 8 bytes. The 
	        //		difference is that shallow copy types can be just byte copied to the new location, while objects require constructors to be called to copy them
	        //
	        //  Required arguments :
	        //            
	        //      User information needed :
	        //
	        //          1. source - a pointer contains the memory address to copy from
	        //          2. size - the number of entries to copy, in terms of the template type
	        //          3. destination - a pointer contains the memory address to copy to
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      NONE
	        //
	        //  Exceptions :
	        //
	        //      1. The source pointer should not be NULL
	        //      2. The destination pointer should not be NULL
	        //      3. The source pointer and destination pointer must point to different memory addresses 
	        //      4. The source size must be larger then 0
	        //      5. The destination pointer contains an address with enough memory space allocated to copy the source ( there is no way at this level to
	        //         verify that enough memory space was allocated in the address the destination points too )
	        //      6. The given template type must be primitve
	        //      7. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename ShallowCopyType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< ShallowCopyType >::Result() == true && sizeof( ShallowCopyType ) != 8 >::Type Copy( const ShallowCopyType* source, ShallowCopyType* destination, UnsignedInteger64bits size );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to copy content in memory to another location. The method takes into account if the source memory address is lower 
	        //      or higher then the destination memory address. If the source address is lower then the copy will begin from the end of the source
	        //      memory area to copy, and if it is higher the copy will start from the beginning of the memory area. This is needed to avoid writing
	        //      into locations that needs to be read afterwards for the copy, in other words, when the source and destination memory areas overlaps. 
	        //		Visually :
	        //
	        //
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 7 8 9
	        //
	        //
	        //      As can be seen if the copying will start from the beginning of the source memory address, the first writing to the destination memory
	        //		address will erase the data, then after it the situation will look :
	        //
	        //                  
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 4 8 9
	        //
	        //
	        //		Which is of course unwanted. Then the check is dont to avoid it. Now if the source and destination memory addresses are equal then 
	        //     	there is nothing to do, this situation will be asserted! 
	        //
	        //      This method is one of two methods that perform the copying of memory areas. This method is enabled only for objects that require copy
	        //		constructor and types that can be shallow copied but their size is 8 bytesm, which is the register size, and therefore can not be copied
	        //		any faster, and the second is for object that can be shallow copied. The difference is that shallow copy types can be just byte copied 
	        //		to the new location, while objects require constructors to be called to copy them
	        //
	        //  Required arguments :
	        //            
	        //      User information needed :
	        //
	        //          1. source - a pointer contains the memory address to copy from
	        //          2. size - the number of entries to copy, in terms of the template type
	        //          3. destination - a pointer contains the memory address to copy to
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      NONE
	        //
	        //  Exceptions :
	        //
	        //      1. The source pointer should not be NULL
	        //      2. The destination pointer should not be NULL
	        //      3. The source pointer and destination pointer must point to different memory addresses 
	        //      4. The source size must be larger then 0
	        //      5. The destination pointer contains an address with enough memory space allocated to copy the source ( there is no way at this level to
	        //         verify that enough memory space was allocated in the address the destination points too )
	        //      6. The given template type must be primitve
	        //      7. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename NonShallowCopyType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< NonShallowCopyType >::Result() == false || sizeof( NonShallowCopyType ) == 8 >::Type Copy( const NonShallowCopyType* source, NonShallowCopyType* destination, UnsignedInteger64bits size );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to move content in memory to another location. The method takes into account if the source memory address is lower 
	        //      or higher then the destination memory address. If the source address is lower then the move will begin from the end of the source
	        //      memory area to move, and if it is higher the move will start from the beginning of the memory area. This is needed to avoid writing
	        //      into locations that needs to be read afterwards for the move, in other words, when the source and destination memory areas overlaps. 
	        //		Visually :
	        //
	        //
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 7 8 9
	        //
	        //
	        //      As can be seen if the moving will start from the beginning of the source memory address, the first writing to the destination memory
	        //		address will erase the data, then after it the situation will look :
	        //
	        //                  
	        //                                         Pointer = 0x07
	        //                                                |
	        //                  Source            ->          4 5 6 7 8 9
	        //
	        //                                               Pointer = 0x09
	        //                                                      |
	        //                  destination       ->          4 5 6 4 8 9
	        //
	        //
	        //		Which is of course unwanted. Then the check is dont to avoid it. Now if the source and destination memory addresses are equal then 
	        //     	there is nothing to do, this situation will be asserted! 
	        //
	        //  Required arguments :
	        //            
	        //      User information needed :
	        //
	        //          1. source - a pointer contains the memory address to copy from
	        //          2. size - the number of entries to copy, in terms of the template type
	        //          3. destination - a pointer contains the memory address to copy to
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      NONE
	        //
	        //  Exceptions :
	        //
	        //      1. The source pointer should not be NULL
	        //      2. The destination pointer should not be NULL
	        //      3. The source pointer and destination pointer must point to different memory addresses 
	        //      4. The source size must be larger then 0
	        //      5. The destination pointer contains an address with enough memory space allocated to move the source ( there is no way at this level to
	        //         verify that enough memory space was allocated in the address the destination points too )
	        //      6. The given template type must be primitve
	        //      7. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename AnyType >
	        static inline void Move( AnyType* source, AnyType* destination, UnsignedInteger64bits size );


            // Method Information :
            //
            //  Description :
            //
            //     Use this method to set all the entries of the array of shallow copy type to the given value. This method is one of two methods that perform 
            //     the setting of memory areas. The first is for arrays of shallow copy types and the second is for array of object types
            //
            //  Required arguments :
            //
            //     User information needed :
            //
            //         1. array - a pointer to the a memory address with array to set
            //         2. size - the size in terms of the template type
            //         3. valueToSet - this value will be used to set all the entries of the array
            //
            //     Information returned to the user :
            //
            //         NONE
            //
            //  Return value :
            //
            //     NONE
            //
            //  Exceptions :
            //
            //     1. The pointer to the first memory address should not be NULL
            //     2. The size must be larger then 0
            //     3. The given template type must be primitve
            //     4. 
            //
            //  Possible errors :
            //
            //     They will come
            //
            template< typename ShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< ShallowCopyType >::Result() == true && sizeof( ShallowCopyType ) != 8 >::Type Set( ShallowCopyType* memoryAddress, UnsignedInteger64bits size, ShallowCopyType valueToSet );


            // Method Information :
            //
            //  Description :
            //
            //     Use this method to set all the entries of the array of object type to the given value. This method is one of two methods that perform 
            //     the setting of memory areas. The first is for arrays of shallow copy types and the second is for array of object types
            //
            //  Required arguments :
            //
            //     User information needed :
            //
            //         1. array - a pointer to the a memory address with array to set
            //         2. size - the size in terms of the template type
            //         3. instanceToSet - this instance will be used to set all the entries of the array
            //
            //     Information returned to the user :
            //
            //         NONE
            //
            //  Return value :
            //
            //     NONE
            //
            //  Exceptions :
            //
            //     1. The pointer to the first memory address should not be NULL
            //     2. The size must be larger then 0
            //     3. The given template type must not be primitve
            //     4. 
            //
            //  Possible errors :
            //
            //     They will come
            //
            template< typename NonShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< NonShallowCopyType >::Result() == false || sizeof( NonShallowCopyType ) == 8 >::Type Set( NonShallowCopyType* memoryAddress, UnsignedInteger64bits size, const NonShallowCopyType& instanceToSet );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare between 2 arrays of shallow copy types
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. firstMemoryAddress - a pointer to the first array
            //          2. secondMemoryAddress - a pointer to the second array
            //          3. size - the number of entries to compare
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The first pointer should not be NULL
            //      1. The second pointer should not be NULL
            //      3. The first and second pointers must point to different memory addresses 
            //      4. The size must be larger then 0
            //      5. Both memory addresses actually conatin the number of entries that the size declare ( there is no way at this level to verify 
            //         that enough memory space was allocated in both addresses )
            //      6. The given template type must be primitve
            //      7.  
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename ShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< ShallowCopyType >::Result() == true && sizeof( ShallowCopyType ) != 8, Boolean >::Type Compare( const ShallowCopyType* firstMemoryAddress, const ShallowCopyType* secondMemoryAddress, UnsignedInteger64bits size );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare between 2 arrays of object types
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. firstMemoryAddress - a pointer to the first array
            //          2. secondMemoryAddress - a pointer to the second array
            //          3. size - the number of entries to compare
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The first pointer should not be NULL
            //      1. The second pointer should not be NULL
            //      3. The first and second pointers must point to different memory addresses 
            //      4. The size must be larger then 0
            //      5. Both memory addresses actually conatin the number of entries that the size declare ( there is no way at this level to verify 
            //         that enough memory space was allocated in both addresses )
            //      6. The given template type must not be primitve
            //      7.  
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename NonShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< NonShallowCopyType >::Result() == false || sizeof( NonShallowCopyType ) == 8, Boolean >::Type Compare( const NonShallowCopyType* firstMemoryAddress, const NonShallowCopyType* secondMemoryAddress, UnsignedInteger64bits size );


            // Method Information :
            //
            //  Description :
            //
            //      Reverses the array of primitve type with size of 1 byte
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          1. memoryAddress - a pointer to the array to reverse
            //          2. size - the number of entries to reverse
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The first pointer should not be NULL
            //      2. The size must be larger then 0
            //      3. The memory address actually conatin the number of entries that the size declare ( there is no way at this level to verify
            //         that enough memory space was allocated in both addresses )
            //      4. The given template type must be 8 bits
            //      5. The fiven template type must be shallow copy
            //      6. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename ShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< ShallowCopyType >::Result() == true && sizeof( ShallowCopyType ) == 1 >::Type Reverse( ShallowCopyType* memoryAddress, UnsignedInteger64bits size );


            // Method Information :
            //
            //  Description :
            //
            //      Reverses the array of object type
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          1. memoryAddress - a pointer to the array to reverse
            //          2. size - the number of entries to reverse
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The first pointer should not be NULL
            //      2. The size must be larger then 0
            //      3. The memory address actually conatin the number of entries that the size declare ( there is no way at this level to verify
            //         that enough memory space was allocated in both addresses )
            //      4. The fiven template type must be object
            //      5. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename NonShallowCopyType >
            static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_ShallowCopy< NonShallowCopyType >::Result() == true >::Type Reverse( NonShallowCopyType* memoryAddress, UnsignedInteger64bits size );


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
			NoInstances_MACRO( Operations )


		};  //  Class Operations



#include "Operations.inl"



    }  //  Namespace Memory

}  //  Namespace Universe


#endif  // OPERATIONS_HPP