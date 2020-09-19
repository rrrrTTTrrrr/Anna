#ifndef  FORWRAPPINGTOALLOWSPECIALIZATIONBASEDONARBITRARYNUMBEROFTEMPLATEARGUMENTS_HPP
#define  FORWRAPPINGTOALLOWSPECIALIZATIONBASEDONARBITRARYNUMBEROFTEMPLATEARGUMENTS_HPP


#include "../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../AsDataMemberOnly/State/State.hpp"  //  Class State


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace Abilities
    {


    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


        // This macro should be used to create an object that wraps other templated objects, that allow arbitrary number of template arguments, and need to implement
        // template specializations based on that number of arbitrary template arguments. The macro will create a wrapper that will inherit from the required object,
        // and expose the objects interface. The name of the templated object should be of the form :
        //
        //      ObjectName_ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments
        //
        // The use of the macro as follows :
        //
        //      CreateObjectThatWrappsOtherObjectsToAllowTemplateSecializationBasedOnArbitraryNumberOfTemplateArguments( Anna )
        //
        // The preprocessor will create the following object :
        //
        //      template< typename... WrappedObjectTemplateArgumentsType >
        //      class Anna : public Anna_ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments< WrappedObjectTemplateArgumentsType... >
        //
        // It is basically used to create different objects, by switching the text in the required locations!
        //
        // The comments inside are C style. This is the only to create it in multi line macro
        //
        #define CreateObjectThatWrappsOtherObjectsToAllowTemplateSecializationBasedOnArbitraryNumberOfTemplateArguments( TemplatedObjectName ) \
\
\
    	/* Template Class Information :    \
\
    	  Purpose :    \
\
    			Use this object to wrap another object to allow the template specialization according to the arbitrary number of template arguments provieded    \
\
    	  Description :    \
\
    	 		Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :  \
\
    					1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools    \
    								presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is   \
    								lost, so it should be avoided in most cases     \
\
    					2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access  \
    								   all the data and methods inside this part. This part will usually containt some methods and few data members     \
\
    					3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the  \
    								 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the  \
    								 suffix __Private   \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			Too many to count    */  \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                                                 \
    	class TemplatedObjectName : public TemplatedObjectName ## _ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments< WrappedObjectTemplateArgumentsType... >              \
    	{                                                                                                                                                                                          \
    	public:                                                                                                                                                                                    \
\
\
             /* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler    \
             generates a basic behavior for them : */   \
\
\
            /* Method Information :   \
\
    	      Description :    \
\
    		   	Default Constructor,  \
\
    		  Required arguments :    \
\
    		   	User information needed :     \
\
        	          NONE     \
\
    		      Information returned to the user :  \
\
    		          NONE    \
\
        	  Return value :   \
\
    		   	NONE  \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		inline TemplatedObjectName();     \
\
\
             /* Method Information :    \
\
              Description :     \
\
                  Constructor,  \
\
              Required arguments :  \
\
                  User information needed :     \
\
                      wrappedObjectArguments - the required arguments to construct an instance of the wrapped object    \
\
                  Information returned to the user :    \
\
                      NONE  \
\
              Return value :    \
\
                  NONE  \
\
              Expectations :    \
\
                  1. The given arguments match the template arguments in type and number    \
                  2.    \
\
              Possible errors :     \
\
                  They will come */     \
\
            explicit inline TemplatedObjectName( WrappedObjectTemplateArgumentsType... wrappedObjectArguments );    \
\
\
    		 /* Method Information :  \
\
    		  Description : \
\
    		   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment    \
\
    		  Required arguments :    \
\
    	       	User information needed :  \
\
    		          other - a reference to the instance that should be copied   \
\
    				Information returned to the user :  \
\
    		          NONE    \
\
    		  Return value :  \
\
    		   	NONE  \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		inline TemplatedObjectName( const TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& other );  \
\
\
    		 /* Method Information :  \
\
    		  Description :   \
\
    		   	Assignment operator, can handle with self assignment and instances in default state   \
\
    		  Required arguments :    \
\
    				User information needed :   \
\
    					other - a reference to the instance that should be copied  \
\
    				Information returned to the user :  \
\
    		          NONE    \
\
    		  Return value :  \
\
    		   	A reference to this instance    \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& operator=( const TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& other );  \
\
\
    		 /* Method Information :  \
\
    		  Description :   \
\
    		   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state    \
\
    		  Required arguments :    \
\
    		   	User information needed :     \
\
    		          other - a reference to the instance that should be moved    \
\
    		      Information returned to the user :  \
\
    		          NONE    \
\
    		  Return value :      \
\
    		   	NONE  \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		inline TemplatedObjectName( TemplatedObjectName< WrappedObjectTemplateArgumentsType... >&& other );   \
\
\
    		 /* Method Information :  \
\
    		  Description :   \
\
    		   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state   \
\
    		  Required arguments :    \
\
    		   	User information needed :     \
\
    		          other - a reference to the instance that should be moved    \
\
    		      Information returned to the user :  \
\
    		          NONE    \
\
    		  Return value :  \
\
    		   	A reference to this instance    \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& operator=( TemplatedObjectName< WrappedObjectTemplateArgumentsType... >&& other );   \
\
\
    		 /* Method Information :  \
\
    		  Description :   \
\
    		   	Destructor, does not throw    \
\
    		  Required arguments :    \
\
    		   	User information needed :     \
\
    		          NONE    \
\
    		      Information returned to the user :  \
\
    		          NONE    \
\
    		  Return value : \
\
    		   	NONE  \
\
    		  Expectations :  \
\
    				NONE    \
\
    		  Possible errors :   \
\
    				They will come */   \
\
    		virtual ~TemplatedObjectName() = default;     \
\
\
    		DEBUG_TOOL(   \
\
    			/* This part of the object is dedicated for testing : */   \
\
\
    			/* Method Information :    \
\
    			  Description :   \
\
    			      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code   \
\
    			  Required arguments :   \
\
    			      User information needed :  \
\
    			          NONE   \
\
    			      Information returned to the user :     \
\
    			          NONE   \
\
    			  Return value :     \
\
    						NONE  \
\
    			  Expectations :     \
\
    					Please let the test pass lord!!    \
\
    			  Possible errors :  \
\
    					It says there are no problems, which is even scarier, did I just wrote a working code?? */     \
\
    			static void Test();  \
\
    		)    /* End of debug tool */  \
\
\
    	};    /* Class TemplatedObjectName */  \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ****************************************************/ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
    	/* Method Information :     \
\
    	  Description :    \
\
    	   	Default Constructor,   \
\
    	  Required arguments :     \
\
    	   	User information needed :  \
\
    	          NONE     \
\
    	      Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	NONE   \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                         \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::TemplatedObjectName() :                       \
    	TemplatedObjectName ## _ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments()                \
    	{}                                                                                                                 \
\
\
    	 /* Method Information :   \
\
    	  Description :    \
\
    	   	Constructor,   \
\
    	  Required arguments :     \
\
    			User information needed :    \
\
    	          wrappedObjectArguments - the required arguments to construct an instance of the wrapped object   \
\
    	      Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	NONE   \
\
    	  Expectations :   \
\
    		1. The given arguments match the template arguments in type and number   \
            2.  \ 
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                         \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::TemplatedObjectName( WrappedObjectTemplateArgumentsType... wrappedObjectArguments ) :         \
    	TemplatedObjectName ## _ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments( wrappedObjectArguments... )                                     \
    	{}                                                                                                                                                                 \
\
\
    	 /* Method Information :   \
\
    	  Description :    \
\
    	   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment     \
		
    	  Required arguments :     \
\
    	   	User information needed :  \
\
    	          other - a reference to the instance that should be copied    \
\
    			Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	NONE   \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                                         \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::TemplatedObjectName( const TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& other ) :            \
    	TemplatedObjectName ## _ForWrappingToAllowSpecializationBasedOnArbitraryNumberOfTemplateArguments( other )                                                                         \
    	{}                                                                                                                                                                                 \
\
\
    	 /* Method Information :   \
\
    	  Description :    \
\
    	   	Assignment operator, can handle with self assignment and instances in default state    \
\
    	  Required arguments :     \
\
    			User information needed :   \
\
    				other - a reference to the instance that should be copied   \
\
    			Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	A reference to this instance     \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                                                                                                \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::operator=( const TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& other )                 \
    	{                                                                                                                                                                                                                                         \
    		/* Create a copy of the other instance */                                                                                                                                                                                             \
    		TemplatedObjectName copyOfOther( other );                                                                                                                                                                                             \
\
    		/* Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted */                                                                                           \
    		Swap( copyOfOther );                                                                                                                                                                                                                  \
\
    		/* Return a reference to this instance */                                                                                                                                                                                             \
    		return ( *this );                                                                                                                                                                                                                     \
    	}                                                                                                                                                                                                                                         \
\
\
    	/* Method Information :    \
\
    	  Description :    \
\
    	   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state     \
\
    	  Required arguments :     \
\
    	   	User information needed :  \
\
    	          other - a reference to the instance that should be moved     \
\
    	      Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	NONE   \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                                     \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::TemplatedObjectName( TemplatedObjectName< WrappedObjectTemplateArgumentsType... >&& other ) :             \
    	TemplatedObjectName< WrappedObjectTemplateArgumentsType... >()                                                                                                                 \
    	{                                                                                                                                                                              \
    		/* Swap between this instance, which is in default state, and the other one */                                                                                             \
    		Swap( other );                                                                                                                                                             \
    	}                                                                                                                                                                              \
\
\
    	/* Method Information :    \
\
    	  Description :    \
\
    	   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state    \
\
    	  Required arguments :     \
\
    	   	User information needed :  \
\
    	          other - a reference to the instance that should be moved     \
\
    	      Information returned to the user :   \
\
    	          NONE     \
\
    	  Return value :   \
\
    	   	A reference to this instance     \
\
    	  Expectations :   \
\
    			NONE     \
\
    	  Possible errors :    \
\
    			They will come */    \
\
    	template< typename... WrappedObjectTemplateArgumentsType >                                                                                                                                                                             \
    	inline TemplatedObjectName< WrappedObjectTemplateArgumentsType... >& TemplatedObjectName< WrappedObjectTemplateArgumentsType... >::operator=( TemplatedObjectName< WrappedObjectTemplateArgumentsType... >&& other )                   \
    	{                                                                                                                                                                                                                                      \
    	    /* Create a default constructed instance */                                                                                                                                                                                        \
    	    TemplatedObjectName< WrappedObjectTemplateArgumentsType... > defaultConstructedInstance;                                                                                                                                           \
\
    	    /* Swap between the temporary instance, which is in default state, and the other instance */                                                                                                                                       \
    	    defaultConstructedInstance.Swap( other );                                                                                                                                                                                          \
\
    	    /* Swap between this instance and the temporary one */                                                                                                                                                                             \
    	    Swap( defaultConstructedInstance );                                                                                                                                                                                                \
\
    	    /* Return a reference to this instance */                                                                                                                                                                                          \
    	    return ( *this );                                                                                                                                                                                                                  \
    	}                                                                                                                                                                                                                                      \
\
\
\
\
        //  End of Macro CreateObjectThatWrappsOtherObjectsToAllowTemplateSecializationBasedOnArbitraryNumberOfTemplateArguments






    }  //  Namespace Abilities

}  //  Namespace Universe



#endif  //  FORWRAPPINGTOALLOWSPECIALIZATIONBASEDONARBITRARYNUMBEROFTEMPLATEARGUMENTS_HPP