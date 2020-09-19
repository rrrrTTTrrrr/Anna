#include <iostream> 

using namespace std;


	// This macro will contain the assignment operator for non template objects. The required arguments are :
	//
	//		ObjectName - the name of the object that will contain the method
	//
	#define AssignmentOperatorForNonTemplateObjects_MACRO( ObjectName )																									\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Assignment operator, can handle with self assignment and instances in default state    																		\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					other - a reference to the instance that should be copied    																						\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\	
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline ObjectName& operator=( const ObjectName& other )    																										\
		{    																																							\
			/* Create a copy of the other instance */   																												\
			ObjectName copyOfOther( other );    																														\
																																										\
			/* Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted */   				\
			Swap( copyOfOther );    																																	\
																																										\
			/* Return a reference to this instance */   																												\
			return ( *this );    																																		\
		}




	// This macro will contain the assignment operator for template objects. The required arguments are :
	//
	//		TemplateObjectName - the name of the object that will contain the method
	//		... - all the template arguments of the object that will contain the method
	//  	
	#define AssignmentOperatorForTemplateObjects_MACRO( TemplateObjectName, ... )																						\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Assignment operator, can handle with self assignment and instances in default state    																		\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					other - a reference to the instance that should be copied    																						\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline TemplateObjectName< __VA_ARGS__ >& operator=( const TemplateObjectName< __VA_ARGS__ >& other )    														\
		{    																																							\
			/* Create a copy of the other instance */   																												\
			TemplateObjectName< __VA_ARGS__ > copyOfOther( other );    																									\
																																										\
			/* Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted */   				\
			Swap( copyOfOther );    																																	\
																																										\
			/* Return a reference to this instance */   																												\
			return ( *this );    																																		\
		}




	// This macro will contain the move constructor for non template objects. The required arguments are :
	//
	//		ObjectName - the name of the object that will contain the method
	// 												
	#define MoveConstructorForNonTemplateObjects_MACRO( ObjectName )																									\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances 					\
				in default state    																																	\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline ObjectName( ObjectName&& other ) :    																													\
		ObjectName()    																																				\
		{    																																							\
			/* Swap between this instance, which is in default state, and the other one */   																			\
			Swap( other );    																																			\
		}




	// This macro will contain the move constructor for template objects. The required arguments are :
	//
	//		TemplateObjectName - the name of the object that will contain the method
	//		... - all the template arguments of the object that will contain the method
	//  	 												
	#define MoveConstructorForTemplateObjects_MACRO( TemplateObjectName, ... )																							\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances 					\
				in default state    																																	\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline TemplateObjectName< __VA_ARGS__ >( TemplateObjectName< __VA_ARGS__ >&& other ) :    																		\
		TemplateObjectName< __VA_ARGS__ >()    																															\
		{    																																							\
			/* Swap between this instance, which is in default state, and the other one */   																			\
			Swap( other );    																																			\
		}




	// This macro will contain the move assignment operator for non template objects. The required arguments are :
	//
	//		ObjectName - the name of the object that will contain the method
	// 												
	#define MoveAssignmentOperatorForNonTemplateObjects_MACRO( ObjectName )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state    			\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline ObjectName& operator=( ObjectName&& other )    																											\
		{    																																							\
		    /* Create a default constructed instance */   																												\
		    ObjectName defaultConstructedInstance;    																													\
																																										\
		    /* Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state */  			\
		    defaultConstructedInstance.Swap( other );    																												\
																																										\
		    /* Swap between this instance and the temporary one */   																									\
		    Swap( defaultConstructedInstance );    																														\
																																										\
		    /* Return a reference to this instance */   																												\
		    return ( *this );    																																		\
		}




	// This macro will contain the move assignment operator for template objects. The required arguments are :
	//
	//		TemplateObjectName - the name of the object that will contain the method
	//		... - all the template arguments of the object that will contain the method
	//  												
	#define MoveAssignmentOperatorForTemplateObjects_MACRO( TemplateObjectName, ... )																					\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state    			\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline TemplateObjectName< __VA_ARGS__ >& operator=( TemplateObjectName< __VA_ARGS__ >&& other )    															\
		{    																																							\
		    /* Create a default constructed instance */   																												\
		    TemplateObjectName< __VA_ARGS__ > defaultConstructedInstance;    																							\
																																										\
		    /* Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state */  			\
		    defaultConstructedInstance.Swap( other );    																												\
																																										\
		    /* Swap between this instance and the temporary one */   																									\
		    Swap( defaultConstructedInstance );    																														\
																																										\
		    /* Return a reference to this instance */   																												\
		    return ( *this );    																																		\
		}




	// This macro will contain the reset method for non template objects. The required arguments are :
	//
	//		ObjectName - the name of the object that will contain the method
	//		MethodSpecifier - this is given to allow changing the method specifier between inline and virtual
	// 												
	#define ResetForNonTemplateObjects_MACRO( ObjectName, MethodSpecifier )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		      Use this method to take an instance already initialized, delete the current resources and set it to default state    										\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		      User information needed :    																																\
		    																																							\
					NONE    																																			\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		      NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		MethodSpecifier void Reset()    																																\
		{    																																							\
		    /* Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it 				\
			will delete the old resources */   																															\
		    ObjectName defaultConstructedInstance;    																													\
																																										\
		    /* Swap between this instance and the default constructed instance */   																					\
		    Swap( defaultConstructedInstance );    																														\
		}




	// This macro will contain the reset method for template objects. The required arguments are :
	//
	//		TemplateObjectName - the name of the object that will contain the method
	//		MethodSpecifier - this is given to allow changing the method specifier between inline and virtual
	//		... - all the template arguments of the object that will contain the method
	// 				 												
	#define ResetForTemplateObjects_MACRO( TemplateObjectName, MethodSpecifier, ... )																					\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		      Use this method to take an instance already initialized, delete the current resources and set it to default state    										\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		      User information needed :    																																\
		    																																							\
					NONE    																																			\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		      NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		MethodSpecifier void Reset()    																																\
		{    																																							\
		    /* Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it				\
			will delete the old resources */   																															\
		    TemplateObjectName< __VA_ARGS__ > defaultConstructedInstance;    																							\
																																										\
		    /* Swap between this instance and the default constructed instance */   																					\
		    Swap( defaultConstructedInstance );    																														\
		}




	// This macro will contain the state method for all objects. The required arguments are :
	//
	//		ObjectName - the name of the object that will contain the method
	//		MethodSpecifier - this is given to allow changing the method specifier between inline and virtual
	// 			 												
	#define StateForAllObjects_MACRO( ObjectName, MethodSpecifier )																										\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		      Use this method to get a handle that can be used to obtain information on the state of the instance    													\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		      User information needed :    																																\
		    																																							\
		          NONE    																																				\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		      NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
		      NONE    																																					\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
		      They will come */   																																		\
		    																																							\
		MethodSpecifier const Abilities::State& State() const    																										\
		{    																																							\
		    /* Return a reference to the state member */   																												\
		    return ( member_state );    																																\
		}









// ************************************************************************************************************************************************************************** //
// **														   				    NON TEMPLATE OBJECT    												   			  		   ** //
// ************************************************************************************************************************************************************************** //




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
	// This macro will be for non template objects. It requires only one argument the object name
	#define ObjectInfrastructure_MACRO( ObjectName ) 																													\
																																										\
		AssignmentOperatorForNonTemplateObjects_MACRO( ObjectName )																										\
																																										\
		MoveConstructorForNonTemplateObjects_MACRO( ObjectName )																										\
																																										\
		MoveAssignmentOperatorForNonTemplateObjects_MACRO( ObjectName ) 																								\
																																										\
		ResetForNonTemplateObjects_MACRO( ObjectName, inline ) 																											\
																																										\
		StateForAllObjects_MACRO( ObjectName, inline )																													\





#define Foo( ObjectName ) void ObjectName() { std::cout << #ObjectName << std::endl; } 

#define Lord( Devil ) Foo( Devil )



class Test
{
public:

	ObjectInfrastructure_MACRO( Test )

	Lord( Devil )

private:

};  //  class Test



int main()  
{

	try
    {

    	Test tt;

    	tt.Devil();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}