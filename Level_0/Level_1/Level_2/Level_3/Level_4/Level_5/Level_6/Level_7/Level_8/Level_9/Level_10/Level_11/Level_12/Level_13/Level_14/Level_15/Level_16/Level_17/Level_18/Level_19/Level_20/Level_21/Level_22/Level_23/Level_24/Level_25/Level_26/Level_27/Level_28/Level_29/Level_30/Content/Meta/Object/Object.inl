//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Object::Object() :
		member_methods(),
		member_members(),
        m_doesDefaultConstructorExist( false ),
        m_doesParameterizedConstructorExist( false ),
        m_doesDestructorExist( false ),
        m_doesCopyConstructorExist( false ),
        m_doesAssignmentOperatorExist( false ),
        m_doesMoveConstructorExist( false ),
        m_doesMoveAssignmentOperatorExist( false ),
        m_isTemplated( false ),
        m_doesInherit( false )
	{}


	inline Object::Object( Boolean doesDefaultConstructorExist, Boolean doesParameterizedConstructorExist, Boolean doesDestructorExist, Boolean doesCopyConstructorExist, Boolean doesAssignmentOperatorExist, Boolean doesMoveConstructorExist, Boolean doesMoveAssignmentOperatorExist, Boolean isTemplated, Boolean doesInherit ) :
		member_methods(),
		member_members(),
        m_doesDefaultConstructorExist( doesDefaultConstructorExist ),
        m_doesParameterizedConstructorExist( doesParameterizedConstructorExist ),
        m_doesDestructorExist( doesDestructorExist ),
        m_doesCopyConstructorExist( doesCopyConstructorExist ),
        m_doesAssignmentOperatorExist( doesAssignmentOperatorExist ),
        m_doesMoveConstructorExist( doesMoveConstructorExist ),
        m_doesMoveAssignmentOperatorExist( doesMoveAssignmentOperatorExist ),
        m_isTemplated( isTemplated ),
        m_doesInherit( doesInherit )
	{}


	inline Object::AddMethod( const Language::String& name, const Language::String& encapsulationClassification, Boolean isInline, Boolean isConstantExpression, Boolean canThrowException, Boolean isConstant, Boolean isStatic, Boolean isVirtual, Boolean doesOverride, Boolean isPureVirtual )
	{
		// Create a method instance using the given information and add it to the methods container
		member_methods.Insert( 0UL, name, encapsulationClassification, isInline, isConstantExpression, canThrowException, isConstant, isStatic, isVirtual, doesOverride, isPureVirtual );
	}


	inline Object::AddMember( const Language::String& name, const Language::String& encapsulationClassification, Boolean isConstantExpression, Boolean isConstant, Boolean isVolatile, Boolean isStatic )
	{
		// Create a method instance using the given information and add it to the methods container
		member_members.Insert( 0UL, name, encapsulationClassification, isConstantExpression, isConstant, isVolatile, isStatic );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void Object::UnitTest()
		{}

	)  //  End of debug tool



	}  //  Namespace Meta

}  //  Namespace Universe



#endif  // OBJECT