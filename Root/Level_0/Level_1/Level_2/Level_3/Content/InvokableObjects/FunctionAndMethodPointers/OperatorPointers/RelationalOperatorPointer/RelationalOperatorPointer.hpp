#ifndef  RELATIONALOPERATORPOINTER_HPP
#define  RELATIONALOPERATORPOINTER_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace Memory
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


        // This macro should be used to create relational operators ( ==, !=, >, <, >=, <= ). This is a template object which has certain locations that need to be replaced
        // as text. One of them is the required relational operator. 
        //
        // For example if an comparison operator pointer ( == ), the syntax will look :
        //
        //      CreateRelationalOperatorPointer( Comparison, == )
        //
        // The preprocessor will create the following object :
        //
        //		template< typename LeftSideOperandType, typename RightSideOperandType >
        //		ComparisonOperatorPointer
        //
        // It is basically used to create different objects, by switching the text in the required locations!
        //
        // The comments inside are C style. This is the only to create it in multi line macro
        //
        #define CreateRelationalOperatorPointer( RelationalOperatorName, RelationalOperatorTextReprsentation ) \
\
\
        	/* Template Class Information :\
\
        	  Purpose :\
\
        	     Use this object to invoke the operator. The operator belongs to the left side operand object type\
\
        	  Description :\
\
        	     1. Template arguments :\
\
                      LeftSideOperandType - this will be used to determine the object the operator belongs to, and to know the type of the left side operand\
                      RightSideOperandType - this will be used to determine the type of the right side operand\
\
        	  Expectations :\
\
        		  1. The left side operand type has overloaded the operator\
                  2. The operator's right side operand type match the type given or an implicit conversion to the type exist\
                  3.\
\
        	  Possible errors :\
\
        	      They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	class RelationalOperatorName ## OperatorPointer\
        	{\
        	public:\
\
\
                /* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler\
                 generates a basic behavior for them : */\
\
\
                /* Method Information :\
\
        	      Description :\
\
        		   	Default Constructor, used to support move semantics\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
            	          NONE\
\
        		      Information returned to the user :\
\
        		          NONE\
	\
            	  Return value :\
\
        		   	NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline RelationalOperatorName ## OperatorPointer();\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Copy constructor, will operate correctly even if the other instance is in default state\
\
        		  Required arguments :\
\
        	       	User information needed :\
\
        		          other - a reference to the instance that should be copied\
\
        				Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline RelationalOperatorName ## OperatorPointer( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other );\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Assignment operator, can handle with self assignment and instances in default state\
\
        		  Required arguments :\
\
        				User information needed :\
\
        					other - a reference to the instance that should be copied\
\
        				Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	A reference to this object\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& operator=( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other );\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
        		          other - a reference to the instance that should be moved\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline RelationalOperatorName ## OperatorPointer( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >&& other );\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
        		          other - a reference to the instance that should be moved\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	A reference to this object\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& operator=( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >&& other );\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		      This method is used to swap the content between this instance and the other one\
\
        		  Required arguments :\
\
        		      User information needed :\
\
        		          other - a reference to the instance that should be swaped\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		      NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        		      They will come */\
\
        		inline void Swap( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other );\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Destructor, does not throw\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
        		          NONE\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline ~RelationalOperatorName ## OperatorPointer() = default;\
\
\
        		/* To support Move semantics, the following 2 methods are added to every object. One method to set the object into the default state, another to check if the\
        		 object is in the default state. This way the user can know if the instance should be used or should it be initialized first : */\
\
\
        		/* Method Information :\
\
        		  Description :\
\
            	      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and\
        				a memory leak will occuer\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
        		          NONE\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		   	NONE\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        			    They will come */\
\
        		inline void SetToDefaultState();\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		   	Use to check if the object is in default state\
\
        		  Required arguments :\
\
        		   	User information needed :\
\
        		          NONE\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		      1. true, if instance is at default state\
        		      2. false, if instance is not at default state\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline Boolean DefaultState() const;\
\
\
        		/* The following methods are the interface of the object. This methods implement the capabilities of the object : */\
\
\
                /* Method Information :\
\
                  Description :\
\
                      Use to invoke the operator on the operands and return the result\
\
                  Required arguments :\
\
                      User information needed :\
\
                          1. leftSideOperand - the left side operand of the operator\
                          2. rightSideOperand - the right side operand of the operator\
\
                      Information returned to the user :\
\
                          NONE\
\
                  Return value :\
\
                      The result of the operator. True if the expression is true, and false otherwise\
\
                  Expectations :\
\
                      1. The left side operand type has overloaded the operator\
                      2. The operator's right side operand type match the type given or an implicit conversion to the type exist\
                      3.\
\
                  Possible errors :\
\
                      They will come */\
\
                inline Boolean Invoke( LeftSideOperandType leftSideOperand, RightSideOperandType rightSideOperand );\
\
\
        		/* The following methods declare the overloaded operators for the object : */\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		      Use this operator to check if the this instance match the other\
\
        		  Required arguments :\
\
        		      User information needed :\
\
        		          other - a reference to the instance that should be compared with this object\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		      1. true - if the 2 objects are the same\
        		      2. false - otherwise\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline Boolean operator==( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const;\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		      Use this operator to check if the this instance does not match the other\
\
        		  Required arguments :\
\
        		      User information needed :\
\
        		          other - a reference to the instance that should be compared with this object\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		      1. true - if the 2 objects are not the same\
        		      2. false - otherwise\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        				They will come */\
\
        		inline Boolean operator!=( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const;\
\
\
        		DEBUG_TOOL(\
\
        			/* This part of the class is dedicated for testing : */\
\
\
        			/* Method Information :\
        			\
        			  Description :\
        			\
        			      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement\
        					the functionality\
        			\
        			  Required arguments :\
        			\
        			      User information needed :\
        			\
        			          NONE\
        			\
        			      Information returned to the user :\
        			\
        			          NONE\
        			\
        			  Return value :\
        			\
        			      1. true - if the object passed the test\
        			      2. false - otherwise\
        			\
        			  Expectations :\
        			\
        					NONE\
        			\
        			  Possible errors :\
        			\
        			      1. A method does not work correctly - class Exception is thrown\
        					2. There is no more free memory space - class std::bad_alloc is thrown\
        					3. */\
        			\
        			static void Test();\
\
        		)   /* End of debug tool */\
\
\
        	private:\
\
\
                /* This object will store the return value from invoking the relational operator */\
                Boolean m_returnValue;\
\
\
                /* This object will store the number of times the operator was invoked */\
                UnsignedInteger64bits m_numberOfInvokes;\
\
\
        	};  /*  Class RelationalOperatorPointer */\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ****************************************************** */\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	   	Default Constructor, used to support move semantics\
\
        	  Required arguments :\
\
        	   	User information needed :\
\
        	          NONE\
\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	   	NONE\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        			They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::RelationalOperatorName ## OperatorPointer() :\
            m_returnValue( false ),\
            m_numberOfInvokes( 0 )\
        	{}\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	   	Copy constructor, will operate correctly even if the other instance is in default state\
\
        	  Required arguments :\
\
        	   	User information needed :\
\
        	          other - a reference to the instance that should be copied\
\
        			Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	   	NONE\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        			They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::RelationalOperatorName ## OperatorPointer( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) :\
            m_returnValue( other.m_returnValue ),\
            m_numberOfInvokes( 0 )\
            {}\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	   	Assignment operator, can handle with self assignment and instances in default state\
\
        	  Required arguments :\
\
        			User information needed :\
\
        				other - a reference to the instance that should be copied\
\
        			Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	   	A reference to this object\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        			They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::operator=( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other )\
        	{\
        		/* Create a copy of the other instance */\
        		RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType > temporary( other );\
\
        		/* Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it */\
        		Swap( temporary );\
\
        		/* Return a reference to this object */\
        		return ( *this );\
        	}\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state\
\
        	  Required arguments :\
\
        	   	User information needed :\
\
        	          other - a reference to the instance that should be moved\
\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	   	NONE\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        			They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::RelationalOperatorName ## OperatorPointer( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >&& other ) :\
        	RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >()\
        	{\
        		/* Swap between this instance, which is in default state, and the other one */\
        		Swap( other );\
        	}\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state\
\
        	  Required arguments :\
\
        	   	User information needed :\
\
        	          other - a reference to the instance that should be moved\
\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	   	A reference to this object\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        			They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::operator=( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >&& other )\
        	{\
        	    /* Create a default constructed instance */\
        	    RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType > defaultConstructedInstance;\
\
        	    /* Swap between the temporary instance, which is in default state, and the other instance */\
        	    defaultConstructedInstance.Swap( other );\
\
        	    /* Swap between this instance and the temporary one */\
        	    Swap( defaultConstructedInstance );\
\
        	    /* Return a reference to this object */\
        	    return ( *this );\
        	}\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	      This method is used to swap the content between this instance and the other one\
\
        	  Required arguments :\
\
        	      User information needed :\
\
        	          other - a reference to the instance that should be swaped\
    		\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	      NONE\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        	      They will come */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline void RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::Swap( RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other )\
        	{\
                /* Swap between the return values */\
                Memory::Swap< Boolean >( m_returnValue, other.m_returnValue );\
            }\
\
\
            /* Method Information :\
\
              Description :\
\
                  Use to invoke the operator on the operands and return the result\
\
              Required arguments :\
\
                  User information needed :\
\
                      1. leftSideOperand - the left side operand of the operator\
                      2. rightSideOperand - the right side operand of the operator\
\
                  Information returned to the user :\
\
                      NONE\
\
              Return value :\
\
                  The result of the operator. True if the expression is true, and false otherwise\
\
              Expectations :\
\
                  1. The left side operand type has overloaded the operator\
                  2. The operator's right side operand type match the type given or an implicit conversion to the type exist\
                  3.\
\
              Possible errors :\
\
                  They will come */\
\
            template< typename LeftSideOperandType, typename RightSideOperandType >\
            inline Boolean RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::Invoke( LeftSideOperandType leftSideOperand, RightSideOperandType rightSideOperand )\
            {\
                /* Increment the number of invokes by 1 */\
                m_numberOfInvokes += 1;\
\
                /* Invoke the operator on the operands and store the result */\
                m_returnValue = ( leftSideOperand RelationalOperatorTextReprsentation rightSideOperand );\
\
                /* Return the result */\
                return ( m_returnValue );\
            }\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ************************************************************** */\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	      Use this operator to check if the this instance match the other\
\
        	  Required arguments :\
\
        	      User information needed :\
\
        	          other - a reference to the instance that should be compared with this object\
\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	      1. true - if the 2 objects are the same\
        	      2. false - otherwise\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        	      1. The template type object does not have the comparison operator ( == )\
        	      2. */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline Boolean RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::operator==( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const\
        	{\
                /* Check if the return values in both instances match, and return the result */\
                return ( m_returnValue == other.m_returnValue );\
            }\
\
\
        	/* Method Information :\
\
        	  Description :\
\
        	      Use this operator to check if the this instance does not match the other\
\
        	  Required arguments :\
\
        	      User information needed :\
\
        	          other - a reference to the instance that should be compared with this object\
\
        	      Information returned to the user :\
\
        	          NONE\
\
        	  Return value :\
\
        	      1. true - if the 2 objects are not the same\
        	      2. false - otherwise\
\
        	  Expectations :\
\
        			NONE\
\
        	  Possible errors :\
\
        	      1. The template type object does not have the comparison operator ( == )\
        	      2. */\
\
        	template< typename LeftSideOperandType, typename RightSideOperandType >\
        	inline Boolean RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::operator!=( const RelationalOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const\
        	{\
        		/* Return the negotiated value from the equal operator */\
        		return ( !( *this == other ) );\
        	}\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* *********************************************************************************   TESTING   ******************************************************************************* */\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
        	DEBUG_TOOL(\
\
\
                class RelationalOperatorName ## TestObject\
                {\
                public:\
\
                    RelationalOperatorName ## TestObject() : m_i() {}\
\
                    RelationalOperatorName ## TestObject( int i ) : m_i( i ) {}\
\
                    Boolean operator RelationalOperatorTextReprsentation( const RelationalOperatorName ## TestObject& other ) const { return ( m_i RelationalOperatorTextReprsentation other.m_i ); }\
\
                    void Swap( RelationalOperatorName ## TestObject& other ) { int tmp = m_i; m_i = other.m_i; other.m_i = tmp; }\
\
                    void Display() { std::cout << m_i << std::endl; }\
\
\
                private:\
\
                    int m_i;\
                };\
\
\
        		/* Method Information :\
\
        		  Description :\
\
        		      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement\
        				the functionality\
\
        		  Required arguments :\
\
        		      User information needed :\
\
        		          NONE\
\
        		      Information returned to the user :\
\
        		          NONE\
\
        		  Return value :\
\
        		      1. true - if the object passed the test\
        		      2. false - otherwise\
\
        		  Expectations :\
\
        				NONE\
\
        		  Possible errors :\
\
        		      1. A method does not work correctly - class Exception is thrown\
        				2. There is no more free memory space - class std::bad_alloc is thrown\
        				3. */\
\
        		template< typename LeftSideOperandType COMMA typename RightSideOperandType >\
        		void RelationalOperatorName ## OperatorPointer< LeftSideOperandType COMMA RightSideOperandType >::Test()\
        		{\
                    /* Create an instance of the test obejct */\
                    RelationalOperatorName ## TestObject testObject_1( 10 );\
\
                    /* Create an instance of the test obejct */\
                    RelationalOperatorName ## TestObject testObject_2( 1 );\
\
                    /* Create an instance of the operator pointer */\
                    RelationalOperatorName ## OperatorPointer< RelationalOperatorName ## TestObject COMMA RelationalOperatorName ## TestObject > RelationalOperatorName ## OperatorPointerTesting;\
\
                    /* Invoker the additon operator pointer */\
                    std::cout << RelationalOperatorName ## OperatorPointerTesting.Invoke( testObject_1, testObject_2 ) << std::endl;\
\
                    /* Check that the number of invokes is 1 */\
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( RelationalOperatorName ## OperatorPointerTesting.m_numberOfInvokes == 1 ), "RelationalOperatorName ## OperatorPointer::Test failed - the number of invokes is not correct" );\
\
                    /* Create an instance of the test obejct */\
                    RelationalOperatorName ## TestObject testObject_3( 1 );\
\
                    /* Invoker the additon operator pointer */\
                    std::cout << RelationalOperatorName ## OperatorPointerTesting.Invoke( testObject_3, testObject_2 ) << std::endl << std::endl;\
                }\
\
        	)   /* End of debug tool */\
\
\
\
        //  End of Macro CreateRelationalOperatorPointer





    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the object that can invoke the equal operator on 2 operands. The object name is  ->  EqualOperatorPointer
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateRelationalOperatorPointer( Equal, == )


    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the object that can invoke the non equal operator on 2 operands. The object name is  ->  NonEqualOperatorPointer
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateRelationalOperatorPointer( NonEqual, != )


    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the object that can invoke the larger operator on 2 operands. The object name is  ->  LargerOperatorPointer
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateRelationalOperatorPointer( Larger, > )


    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the object that can invoke the smaller operator on 2 operands. The object name is  ->  SmallerOperatorPointer
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateRelationalOperatorPointer( Smaller, < )
 

    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the object that can invoke the larger or equal operator on 2 operands. The object name is  ->  LargerOrEqualOperatorPointer
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateRelationalOperatorPointer( LargerOrEqual, >= )


        // Template Class Information :
        //
        //  Purpose :
        //
        //      This macro will be used to create the object that can invoke the smaller or equal operator on 2 operands. The object name is  ->  SmallerOrEqualOperatorPointer
        //
        //  Description :
        //
        //      NONE 
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        CreateRelationalOperatorPointer( SmallerOrEqual, <= )






    }  //  Namespace Memory

}  //  Namespace Universe



#endif  //  RELATIONALOPERATORPOINTER_HPP