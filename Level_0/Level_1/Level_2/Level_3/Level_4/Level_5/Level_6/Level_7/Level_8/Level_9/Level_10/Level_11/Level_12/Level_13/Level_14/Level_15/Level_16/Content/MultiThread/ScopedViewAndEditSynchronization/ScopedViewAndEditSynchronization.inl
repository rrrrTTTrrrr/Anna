//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ScopedViewAndEditSynchronization::ScopedViewAndEditSynchronization( ViewAndEditSynchronization* const viewAndEditSynchronizationTool, const AccessType accessType ) :
	member_viewAndEditSynchronizationTool( viewAndEditSynchronizationTool ),
	member_accessType( accessType ),
	member_wasDoneEditingCalled( false )
{
	// Switch case structure to select the required access type
	switch ( accessType )
	{
		// Access required - View
		case ( AccessType::View ) :
		{
			// The current thread of execution requires to view the resource
			member_viewAndEditSynchronizationTool->View();

			// Nothing else needs to be done
			break;
		}

		// Access required - Edit
		case ( AccessType::Edit ) :
		{
			// The current thread of execution requires to edit the resource
			member_viewAndEditSynchronizationTool->Edit();

			// Nothing else needs to be done
			break;
		}

		// Access required - EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween
		case ( AccessType::EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween ) :
		{
			// The current thread of execution requires the ability to edit and then view the resource, without other threads of execution
			// editing the resource between
			member_viewAndEditSynchronizationTool->EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween();

			// Nothing else needs to be done
			break;
		}

		default:
		{
			ThrowException( "Unknown access type" );
		}
	}
}


inline ScopedViewAndEditSynchronization::~ScopedViewAndEditSynchronization()
{
	// Check if the current thread of execution required to view the resource
	if ( member_accessType == AccessType::View )
	{
		// The current thread of execution required to view the resource

		// Notify that the current thread of execution has finished viewing the resource
		member_viewAndEditSynchronizationTool->DoneViewing();

		// Nothing else needs to be done
		return;
	}

	// Check if the current thread of execution required to edit the resource
	if ( member_accessType == AccessType::Edit )
	{
		// The current thread of execution required to edit the resource

		// Notify that the current thread of execution has finished editing the resource
		member_viewAndEditSynchronizationTool->DoneEditing();

		// Nothing else needs to be done
		return;
	}

	// The current thread of execution required the ability to edit and then view the resource, without other threads of execution
	// editing the resource between

	// Check if the the method to notify that the current thread of execution has finished editing was already called
	if ( member_wasDoneEditingCalled == false )
	{
		// The the method to notify that the current thread of execution has finished editing was not called

		// Notify that the current thread of execution has finished editing
		DoneEditing();
	}

	// Notify that the current thread of execution has finished viewing the resource
	member_viewAndEditSynchronizationTool->DoneViewing();
}


inline void ScopedViewAndEditSynchronization::DoneEditing()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( member_accessType == AccessType::EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween ), "Only for access type \"EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween\" this method should be used" );

	// Notify that the current thread of execution has finished editing the resource
	member_viewAndEditSynchronizationTool->DoneEditing();

	// Set the boolean that stores if this method was called to true, so it won't be called again on destruction
	member_wasDoneEditingCalled = true;
}



}  //  Namespace MultiThread


}  //  Namespace Universe