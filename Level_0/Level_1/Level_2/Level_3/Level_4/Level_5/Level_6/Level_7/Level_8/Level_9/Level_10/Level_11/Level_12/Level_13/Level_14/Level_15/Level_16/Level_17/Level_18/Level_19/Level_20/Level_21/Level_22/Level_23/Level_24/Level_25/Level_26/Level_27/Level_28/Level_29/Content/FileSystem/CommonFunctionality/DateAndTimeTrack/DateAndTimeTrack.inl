// //	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



// inline DateAndTimeTrack::DateAndTimeTrack() :
// 	member_creationDateAndTimeStamp(),
// 	member_lastViewDateAndTimeStamp( member_creationDateAndTimeStamp ),
// 	member_lastEditDateAndTimeStamp( member_creationDateAndTimeStamp )
// {}


// inline DateAndTimeTrack::DateAndTimeTrack( const SelfType& other ) :
// 	member_creationDateAndTimeStamp( other.member_creationDateAndTimeStamp ),
// 	member_lastViewDateAndTimeStamp( other.member_lastViewDateAndTimeStamp ),
// 	member_lastEditDateAndTimeStamp( other.member_lastEditDateAndTimeStamp )
// {}


// inline void DateAndTimeTrack::UpdateViewDateAndTimeStamp()
// {
// 	// Update the view date and time stamp
// 	member_lastViewDateAndTimeStamp.Update();
// }


// inline void DateAndTimeTrack::UpdateEditDateAndTimeStamp()
// {
// 	// Update the edit date and time stamp
// 	member_lastEditDateAndTimeStamp.Update();
// }



// //  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



// inline Boolean DateAndTimeTrack::operator==( const SelfType& other ) const
// {
// 	// Compare all the dates and time stamps, and return the result
// 	return ( member_creationDateAndTimeStamp == other.member_creationDateAndTimeStamp && member_lastViewDateAndTimeStamp == other.member_creationDateAndTimeStamp && member_lastEditDateAndTimeStamp == other.member_lastEditDateAndTimeStamp );
// }


// inline Boolean DateAndTimeTrack::operator!=( const SelfType& other ) const
// {
// 	// Return the negotiated value from the equal operator
// 	return ( !( *this == other ) );
// }



// }  //  Namespace FileSystem


// }  //  Namespace Universe