#ifndef  ID_HPP
#define  ID_HPP


#include "../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits
#include "../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace Metadata
    {


    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


    	// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
    	// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
    	//
    	//    The closest bit to the    The farest bit from the
    	//     address of the byte        address of the byte
    	//                        |      |
    	//      Byte address ->   00000000
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then the value 1 will be stored this way :
    	//
    	//      Byte address ->   00000001
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
    	// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000000 00000001
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000001 00000000


    	// To support move semantics every object must provide a default state. There are  how ever few exceptions, as objects that their members stay exactly the same along
    	// the run of the program, objects that don't have members at all, and objects with undefined state. This default state will be used to notify that the object should
    	// not be used


    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
        //
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	class ID
    	{
    	public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
    	    //
    	    //  Description :
            //
    		//   	Default Constructor, used to support move semantics
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
            //  Exceptions :
            //
            //      NONE
            //
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ID() = default;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor, does not throw
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
            //  Exceptions :
            //
            //      NONE
            //
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ~ID() = default;


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get the ID of the template type object
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
            //      The ID of the template type object
            //
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //
            template< typename Type >
            inline UnsignedInteger64bits Get() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get the number of ID's currently existing 
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
            //      The number of ID's currently existing 
            //
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //
            inline UnsignedInteger64bits GetNumberIDs() const;


    		DEBUG_TOOL(

    			// This part of the class is dedicated for testing :


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
                //  Exceptions :
                //
                //      NONE
                //
    			//  Possible errors :
    			//
    			//      1. A method does not work correctly - class Exception is thrown
    			//		2. There is no more free memory space - class std::bad_alloc is thrown
    			//		3. 
    			//
    			static void Test();

    		)  //  End of debug tool


    	private:


        	// Static data members do not belong to any instance, it belongs to the object. Like every global variable it is created with the start of the program
    		// and only destroyed when the program ends. This means that each member method can use the static data members, but not functions outside the object's
    		// scope. It restricts the access to this object use only, but rather then that acts as global variable


            // This object will act as a counter. It will serve 2 purposes, the first as it's name imply it will count the total number of objects using this object
            // in the program, and secondly it will be used to give each template type a different ID
            static UnsignedInteger64bits m_numberOfTypes;


    	};  //  Class ID


        // Initialize the static counter
        UnsignedInteger64bits ID::m_numberOfTypes = 0;










































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************












































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the ID of the template type object
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
        //      The ID of the template type object
        //
        //  Exceptions :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //
        template< typename Type >
        inline UnsignedInteger64bits ID::Get() const
        {
            // This static object will store the ID of the type. For each type that will use this object a copy of this method will be created, with the specific type, now
            // to make sure each type has a different ID, the counter is used. In each get method that gets created the static variable will be initialized on first call
            // with the current value of the counter, and will increase by 1 after
            static UnsignedInteger64bits id = m_numberOfTypes++;

            // Return the ID
            return ( id );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the number of ID's currently existing 
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
        //      The number of ID's currently existing 
        //
        //  Exceptions :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //
        inline UnsignedInteger64bits ID::GetNumberIDs() const
        {
            // Return the counter
            return ( m_numberOfTypes );
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
    		//  Possible errors :
    		//
    		//      1. A method does not work correctly - class Exception is thrown
    		//		2. There is no more free memory space - class std::bad_alloc is thrown
    		//		3. 
    		//
    		void ID::Test()
    		{
                std::cout << ID().Get< int >() << std::endl;

                std::cout << ID().Get< char >() << std::endl;

                std::cout << ID().Get< int >() << std::endl;

                std::cout << ID().Get< long >() << std::endl;

                std::cout << ID().Get< double >() << std::endl;
            }

    	)  //  End of debug tool











    }  //  Namespace Metadata

}  //  Namespace Universe



#endif  // ID_HPP