#ifndef  ARITHMETICOPERATORPOINTER_HPP
#define  ARITHMETICOPERATORPOINTER_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
	//
	//  NONE
	//



    // This macro should be used to create arithmetic operators ( +, -, *, /, % ). This is a template object which has certain locations that need to be replaced
    // as text. One of them is the required arithmetic operator. 
    //
    // For example if an addition operator pointer ( + ), the syntax will look :
    //
    //      CreateArithmeticOperatorPointer( Addition, + )
    //
    // The preprocessor will create the following object :
    //
    //		template< typename LeftSideOperandType, typename RightSideOperandType >
    //		AdditionOperatorPointer
    //
    // It is basically used to create different objects, by switching the text in the required locations!
    //
    // The comments inside are C style. This is the only way to create multi line macro
    //
    #define CreateArithmeticOperatorPointer( ArithmeticOperatorName, ArithmeticOperatorTextReprsentation )                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
        /* Template Class Information :                                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                                                \
    	  Purpose :                                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    	     Use this object to invoke the operator. The operator belongs to the left side operand object type                                                                                                                                                                  \
                                                                                                                                                                                                                                                                                \
    	  Description :                                                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                                                \
    	     1. Template arguments :                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
                  LeftSideOperandType - this will be used to determine the object the operator belongs to, and to know the type of the left side operand                                                                                                                        \
                  RightSideOperandType - this will be used to determine the type of the right side operand                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    	  Expectations :                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  1. The left side operand type has overloaded the operator                                                                                                                                                                                                         \
              2. The operator's right side operand type match the type given or an implicit conversion to the type exist                                                                                                                                                        \
              3.                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    	  Possible errors :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    	      They will come */                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    	template< typename LeftSideOperandType, typename RightSideOperandType >                                                                                                                                                                                                 \
    	class ArithmeticOperatorName ## OperatorPointer                                                                                                                                                                                                                         \
    	{                                                                                                                                                                                                                                                                       \
    	public:                                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
            /* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler                                                                                                         \
             generates a basic behavior for them : */                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
            /* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    	      Description :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		   	Default Constructor, used to support move semantics                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		   	User information needed :                                                                                                                                                                                                                                       \
                                                                                                                                                                                                                                                                                \
        	          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
        	  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		   	NONE                                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    				They will come */                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
    		inline ArithmeticOperatorName ## OperatorPointer();                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		   	Copy constructor, will operate correctly even if the other instance is in default state                                                                                                                                                                         \
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    	       	User information needed :                                                                                                                                                                                                                                       \
                                                                                                                                                                                                                                                                                \
    		          other - a reference to the instance that should be copied                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    				Information returned to the user :                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		   	NONE                                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    				They will come */                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
    		inline ArithmeticOperatorName ## OperatorPointer( const ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other );                                                                                                            \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
            /* This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow                                                                                                               \
               simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is                                                                                                                \
               any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only                                                                                                                \
               be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this                                                                                                                \
               macro will be used to add the following methods to each object :                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
                    1. Assigenment operator                                                                                                                                                                                                                                     \
                    2. Move constructor                                                                                                                                                                                                                                         \
                    3. Move assigenment operator                                                                                                                                                                                                                                \
                    4. Reset                                                                                                                                                                                                                                                    \
                    5. State */                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
            TemplateObjectInfrastructure_MACRO( ArithmeticOperatorName ## OperatorPointer, LeftSideOperandType, RightSideOperandType )                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		      This method is used to swap the content between this instance and the other one                                                                                                                                                                               \
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		      User information needed :                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		          other - a reference to the instance that should be swaped                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		      NONE                                                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    		      They will come */                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		inline void Swap( ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other );                                                                                                                                                  \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		   	Destructor, does not throw                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		   	User information needed :                                                                                                                                                                                                                                       \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		   	NONE                                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    				They will come */                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
    		inline ~ArithmeticOperatorName ## OperatorPointer() = default;                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* The following methods are the interface of the object. This methods implement the capabilities of the object : */                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
            /* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
              Description :                                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
                  Use to invoke the operator on the operands and return the result                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
              Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
                  User information needed :                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
                      1. leftSideOperand - the left side operand of the operator 																																																\
                      2. rightSideOperand - the right side operand of the operator 																																																\
                                                                                                                                                                                                                                                                                \
                  Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
                      NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
              Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
                  The result of the operator. The type of the return value will be the same as the left side operand type                                                                                                                                                       \
                                                                                                                                                                                                                                                                                \
              Expectations :                                                                                                                                                                                                                                              		\
                                                                                                                                                                                                                                                                                \
                  1. The left side operand type has overloaded the operator 																																																	\
                  2. The operator's right side operand type match the type given or an implicit conversion to the type exist 																																					\
                  3. 																																																															\
                                                                                                                                                                                                                                                                                \
              Possible errors :                                                                                                                                                                                                                                           		\
                                                                                                                                                                                                                                                                                \
                  They will come */                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
            inline LeftSideOperandType Invoke( LeftSideOperandType leftSideOperand, RightSideOperandType rightSideOperand );    																																				\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* The following methods declare the overloaded operators for the object : */  																																														\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                               		\
                                                                                                                                                                                                                                                                                \
    		      Use this operator to check if the this instance match the other 																																																\
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		      User information needed :                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		          other - a reference to the instance that should be compared with this object 																																												\
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		      1. true - if the 2 objects are the same                                                                                                                                                                                                                       \
    		      2. false - otherwise                                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                 		      		\
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    				They will come */                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
    		inline Boolean operator==( const ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const;                                                                                                                             \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                               		\
                                                                                                                                                                                                                                                                                \
    		      Use this operator to check if the this instance does not match the other 																																														\
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		      User information needed :                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		          other - a reference to the instance that should be compared with this object 																																												\
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		      1. true - if the 2 objects are not the same                                                                                                                                                                                                                   \
    		      2. false - otherwise                                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                            		\
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    				They will come */                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
    		inline Boolean operator!=( const ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) const;                                                                                                                             \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		DEBUG_TOOL( 																																																														\
                                                                                                                                                                                                                                                                                \
    			/* This part of the class is dedicated for testing : */  																																																		\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    			/* Method Information :                                                                                                                                                                                                                                         \
                                                                                                                                                                                                                                                                                \
    			  Description :                                                                                                                                                                                                                                              	\
                                                                                                                                                                                                                                                                                \
    			      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement 																											\
    					the functionality 																																																										\
                                                                                                                                                                                                                                                                                \
    			  Required arguments :                                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    			      User information needed :                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    			          NONE                                                                                                                                                                                                                                                  \
                                                                                                                                                                                                                                                                                \
    			      Information returned to the user :                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    			          NONE                                                                                                                                                                                                                                                  \
                                                                                                                                                                                                                                                                                \
    			  Return value :                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    			      1. true - if the object passed the test 																																																					\
    			      2. false - otherwise                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    			  Expectations :                                                                                                                                                                                                                                           		\
                                                                                                                                                                                                                                                                                \
    					NONE                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    			  Possible errors :                                                                                                                                                                                                                                            	\
                                                                                                                                                                                                                                                                                \
    			      1. A method does not work correctly - class Exception is thrown 																																															\
    					2. There is no more free memory space - class std::bad_alloc is thrown 																																													\
    					3. */ 																																																													\
                                                                                                                                                                                                                                                                                \
    			static void Test(); 																																																											\
                                                                                                                                                                                                                                                                                \
    		)   /* End of debug tool */   																																																										\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    	private:    																																																															\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* This object will be used to monitor the state of each instance */ 																																																\
			InstanceState member_state; 																																																										\
																																																																				\
                                                                                                                                                                                                                                                                                \
    	};  /*  Class ArithmeticOperatorPointer */  																																																							\
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
/*	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ****************************************************** */                                                                                            \
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
    	/* Method Information :                                                                                                                                                                                                                                                	\
                                                                                                                                                                                                                                                                                \
    	  Description :                                                                                                                                                                                                                                                			\
                                                                                                                                                                                                                                                                                \
    	   	Default Constructor, used to support move semantics                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    	  Required arguments :                                                                                                                                                                                                                                           		\
                                                                                                                                                                                                                                                                                \
    	   	User information needed :                                                                                                                                                                                                                                    		\
                                                                                                                                                                                                                                                                                \
    	          NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	      Information returned to the user :                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    	          NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Return value :                                                                                                                                                                                                                                                     	\
                                                                                                                                                                                                                                                                                \
    	   	NONE                                                                                                                                                                                                                                                       			\
                                                                                                                                                                                                                                                                                \
    	  Expectations :                                                                                                                                                                                                                                             			\
                                                                                                                                                                                                                                                                                \
    			NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Possible errors :                                                                                                                                                                                                                                              		\
                                                                                                                                                                                                                                                                                \
    			They will come */                                                                                                                                                                                                                                               \
                                                                                                                                                                                                                                                                                \
    	template< typename LeftSideOperandType, typename RightSideOperandType > 																																																\
    	inline ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::ArithmeticOperatorName ## OperatorPointer() : 																															\
        member_state( InstanceState::Ready ) 																																																								\
    	{} 																																																																		\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    	/* Method Information :                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    	  Description :                                                                                                                                                                                                                                                			\
                                                                                                                                                                                                                                                                                \
    	   	Copy constructor, will operate correctly even if the other instance is in default state                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    	  Required arguments :                                                                                                                                                                                                                                           		\
                                                                                                                                                                                                                                                                                \
    	   	User information needed :                                                                                                                                                                                                                                    		\
                                                                                                                                                                                                                                                                                \
    	          other - a reference to the instance that should be copied                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    			Information returned to the user :                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    	          NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Return value :                                                                                                                                                                                                                                                     	\
                                                                                                                                                                                                                                                                                \
    	   	NONE                                                                                                                                                                                                                                                       			\
                                                                                                                                                                                                                                                                                \
    	  Expectations :                                                                                                                                                                                                                                             			\
                                                                                                                                                                                                                                                                                \
    			NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Possible errors :                                                                                                                                                                                                                                              		\
                                                                                                                                                                                                                                                                                \
    			They will come */                                                                                                                                                                                                                                               \
                                                                                                                                                                                                                                                                                \
    	template< typename LeftSideOperandType, typename RightSideOperandType > 																																																\
    	inline ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::ArithmeticOperatorName ## OperatorPointer( const ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) : 						\
    	member_state( other.member_state )																																																										\
        {} 																																																																		\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    	/* Method Information :                                                                                                                                                                                                                                                	\
                                                                                                                                                                                                                                                                                \
    	  Description :                                                                                                                                                                                                                                                			\
                                                                                                                                                                                                                                                                                \
    	      This method is used to swap the content between this instance and the other one                                                                                                                                                                                   \
                                                                                                                                                                                                                                                                                \
    	  Required arguments :                                                                                                                                                                                                                                           		\
                                                                                                                                                                                                                                                                                \
    	      User information needed :                                                                                                                                                                                                                                      	\
                                                                                                                                                                                                                                                                                \
    	          other - a reference to the instance that should be swaped 																																																	\
                                                                                                                                                                                                                                                                                \
    	      Information returned to the user :                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    	          NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Return value :                                                                                                                                                                                                                                                     	\
                                                                                                                                                                                                                                                                                \
    	      NONE                                                                                                                                                                                                                                                         		\
                                                                                                                                                                                                                                                                                \
    	  Expectations :                                                                                                                                                                                                                                             			\
                                                                                                                                                                                                                                                                                \
    			NONE                                                                                                                                                                                                                                                         	\
                                                                                                                                                                                                                                                                                \
    	  Possible errors :                                                                                                                                                                                                                                              		\
                                                                                                                                                                                                                                                                                \
    	      They will come */                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
    	template< typename LeftSideOperandType, typename RightSideOperandType > 																																																\
    	inline void ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::Swap( ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >& other ) 																\
    	{                                                                                                                                                                                                                                                                       \
            /* Swap between the states */																																																										\
            member_state.Swap( other.member_state ); 																																																							\
        } 																																																																		\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
        /* Method Information :                                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
          Description :                                                                                                                                                                                                                                            				\
                                                                                                                                                                                                                                                                                \
              Use to invoke the operator on the operands and return the result 																																																	\
                                                                                                                                                                                                                                                                                \
          Required arguments :                                                                                                                                                                                                                                            		\
                                                                                                                                                                                                                                                                                \
              User information needed :                                                                                                                                                                                                                                   		\
                                                                                                                                                                                                                                                                                \
                  1. leftSideOperand - the left side operand of the operator 																																																	\
                  2. rightSideOperand - the right side operand of the operator 																																																	\
                                                                                                                                                                                                                                                                                \
              Information returned to the user :                                                                                                                                                                                                                              	\
                                                                                                                                                                                                                                                                                \
                  NONE                                                                                                                                                                                                                                                      	\
                                                                                                                                                                                                                                                                                \
          Return value :                                                                                                                                                                                                                                                      	\
                                                                                                                                                                                                                                                                                \
              The result of the operator. The type of the return value will be the same as the left side operand type                                                                                                                                                           \
                                                                                                                                                                                                                                                                                \
          Expectations :                                                                                                                                                                                                                                              			\
                                                                                                                                                                                                                                                                                \
              1. The left side operand type has overloaded the operator 																																																		\
              2. The operator's right side operand type match the type given or an implicit conversion to the type exist 																																						\
              3. 																																																																\
                                                                                                                                                                                                                                                                                \
          Possible errors :                                                                                                                                                                                                                                           			\
                                                                                                                                                                                                                                                                                \
              They will come */                                                                                                                                                                                                                                                 \
                                                                                                                                                                                                                                                                                \
        template< typename LeftSideOperandType, typename RightSideOperandType > 																																																\
        inline LeftSideOperandType ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType, RightSideOperandType >::Invoke( LeftSideOperandType leftSideOperand, RightSideOperandType rightSideOperand ) 																\
        { 																																																																		\
            /* Invoke the operator on the operands and return the result */                                                                                                                                                                                                     \
            return ( ( leftSideOperand ArithmeticOperatorTextReprsentation rightSideOperand ) ); 																																												\
        }    																																																																	\
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
/* *********************************************************************************   TESTING   ******************************************************************************* */                                                                                             \
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
    	DEBUG_TOOL( 																																																															\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
            class ArithmeticOperatorName ## TestObject 																																																							\
            { 																																																																	\
            public: 																																																															\
                                                                                                                                                                                                                                                                                \
                ArithmeticOperatorName ## TestObject() : m_i() {} 																																																				\
                                                                                                                                                                                                                                                                                \
                ArithmeticOperatorName ## TestObject( UnsignedInteger32bits i ) : m_i( i ) {} 																																													\
                                                                                                                                                                                                                                                                                \
                ArithmeticOperatorName ## TestObject operator ArithmeticOperatorTextReprsentation( const ArithmeticOperatorName ## TestObject& other ) const { return ( ArithmeticOperatorName ## TestObject( m_i ArithmeticOperatorTextReprsentation other.m_i ) ); } 			\
                                                                                                                                                                                                                                                                                \
                void Swap( ArithmeticOperatorName ## TestObject& other ) { UnsignedInteger32bits tmp = m_i; m_i = other.m_i; other.m_i = tmp; } 																																\
                                                                                                                                                                                                                                                                                \
                void Display() { std::cout << m_i << std::endl; } 																																																				\
                                                                                                                                                                                                                                                                                \
            private: 																																																															\
                                                                                                                                                                                                                                                                                \
                UnsignedInteger32bits m_i; 																																																										\
            }; 																																																																	\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    		/* Method Information :                                                                                                                                                                                                                                             \
                                                                                                                                                                                                                                                                                \
    		  Description :                                                                                                                                                                                                                                               		\
                                                                                                                                                                                                                                                                                \
    		      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement 																												\
    				the functionality 																																																											\
                                                                                                                                                                                                                                                                                \
    		  Required arguments :                                                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                                \
    		      User information needed :                                                                                                                                                                                                                                     \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		      Information returned to the user :                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                                                                \
    		          NONE                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                \
    		  Return value :                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                                                \
    		      1. true - if the object passed the test 																																																						\
    		      2. false - otherwise                                                                                                                                                                                                                                          \
                                                                                                                                                                                                                                                                                \
    		  Expectations :                                                                                                                                                                                                                                            		\
                                                                                                                                                                                                                                                                                \
    				NONE                                                                                                                                                                                                                                                        \
                                                                                                                                                                                                                                                                                \
    		  Possible errors :                                                                                                                                                                                                                                             	\
                                                                                                                                                                                                                                                                                \
    		      1. A method does not work correctly - class Exception is thrown 																																																\
    				2. There is no more free memory space - class std::bad_alloc is thrown 																																														\
    				3. */ 																																																														\
                                                                                                                                                                                                                                                                                \
    		template< typename LeftSideOperandType COMMA typename RightSideOperandType > 																																														\
    		void ArithmeticOperatorName ## OperatorPointer< LeftSideOperandType COMMA RightSideOperandType >::Test() 																																							\
    		{ 																																																																	\
                /* Create an instance of the test obejct */ 																																																					\
                ArithmeticOperatorName ## TestObject testObject_1( 10 ); 																																																		\
                                                                                                                                                                                                                                                                                \
                /* Create an instance of the test obejct */ 																																																					\
                ArithmeticOperatorName ## TestObject testObject_2( 1 ); 																																																		\
                																																																																\
                /* Create an instance of 32 bits integer */																																																						\
                UnsignedInteger32bits testVariable_1 = 88;																																																						\
                                                                                                                                                                                                                                                                                \
                /* Create an instance of the operator pointer */ 																																																				\
                ArithmeticOperatorName ## OperatorPointer< ArithmeticOperatorName ## TestObject COMMA ArithmeticOperatorName ## TestObject > ArithmeticOperatorName ## OperatorPointerTesting; 																					\
                                                                                                                                                                                                                                                                                \
                /* Invoker the additon operator pointer */ 																																																						\
                ArithmeticOperatorName ## OperatorPointerTesting.Invoke( testObject_1, testObject_2 ).Display(); 																																								\
                                                                                                                                                                                                                                                                                \
                /* Invoker the additon operator pointer */ 																																																						\
                ArithmeticOperatorName ## OperatorPointerTesting.Invoke( testObject_1, testVariable_1 ).Display(); 																																								\
            } 																																																																	\
                                                                                                                                                                                                                                                                                \
    	)   /* End of debug tool */ 																																																											\
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
                                                                                                                                                                                                                                                                                \
    //  End of Macro CreateArithmeticOperatorPointer




































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   CreateArithmeticOperatorPointer specific definitions   ******************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































	// Template Class Information :
	//
	//  Purpose :
	//
	//		This macro will be used to create the object that can invoke the addition operator on 2 operands. The object name is  ->  AdditionOperatorPointer
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
	CreateArithmeticOperatorPointer( Addition, + )


	// Template Class Information :
	//
	//  Purpose :
	//
	//		This macro will be used to create the object that can invoke the subtraction operator on 2 operands. The object name is  ->  SubtractionOperatorPointer
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
	CreateArithmeticOperatorPointer( Subtraction, - )


	// Template Class Information :
	//
	//  Purpose :
	//
	//		This macro will be used to create the object that can invoke the divide operator on 2 operands. The object name is  ->  DivideOperatorPointer
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
	CreateArithmeticOperatorPointer( Divide, / )


	// Template Class Information :
	//
	//  Purpose :
	//
	//		This macro will be used to create the object that can invoke the multiply operator on 2 operands. The object name is  ->  MultiplyOperatorPointer
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
	CreateArithmeticOperatorPointer( Multiply, * )


	// Template Class Information :
	//
	//  Purpose :
	//
	//		This macro will be used to create the object that can invoke the modulo operator on 2 operands. The object name is  ->  ModuloOperatorPointer
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
	CreateArithmeticOperatorPointer( Modulo, % )









}  //  Namespace Universe



#endif  //  ARITHMETICOPERATORPOINTER_HPP