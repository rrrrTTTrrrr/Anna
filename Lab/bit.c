    AsciiString SetTheValueOfTheCharacterIntoTheEncoding( unsigned int m_charcterValue, char m_octetsNumberRequiredToEncodeCharacter, AsciiString m_stringToContainUTF_8encoding ) throw()
    {
    	// Create a character pointer to the addres of m_charcterValue
    	char* beginingOfCharacterValue = (char*)&m_charcterValue;

    	// Check if the encoding is little or big endian
    	if ( true == LittleOrBigEndian() )
    	{
    		// Little endian encoding

    		// Reverse the bits of m_charcterValue to create the operation for setting
    		// the bits of m_charcterValue into the UTF-8 template
    		ReverseBitsOrder< unsigned int >( &m_charcterValue );
    	}

		// Switch case structure to pick the number of octets to encode
		switch ( m_octetsNumberRequiredToEncodeCharacter )
		{	

			// One octet
			case 1 :
			{
				// The character value is stored on one octet and only using 7 bits
				// just store in the template
				m_stringToContainUTF_8encoding[0] |= *beginingOfCharacterValue;

				break;
			}
			// Two octets
			case 2 :
			{
				// Point to the second octet of m_stringToContainUTF_8encoding and set it,
				// in this octet, 6 bits can be stored, so to remove the extra two, shift accordingly
				m_stringToContainUTF_8encoding[1] |= ( *beginingOfCharacterValue << 2 ) >> 2;

				cout << endl <<  "1       ";

				DisplayObjectBitMap< char >( ( *beginingOfCharacterValue << 2 ) );

				// Point to the first octet of m_stringToContainUTF_8encoding and start setting it,
				// in this octet, 5 bits can be stored. 2 bits were left set them first, shift accordingly
				m_stringToContainUTF_8encoding[0] |= *beginingOfCharacterValue >> 6;

				cout << endl << "2       ";

				DisplayObjectBitMap< char >( *beginingOfCharacterValue >> 6 );

				// Point to the first octet of m_stringToContainUTF_8encoding and end setting it,
				// 3 bits were left. Take those bits from the next octet, shift accordingly
				m_stringToContainUTF_8encoding[0] |= ( *( beginingOfCharacterValue + 1 ) << 5 ) >> 3;

				cout << endl << "3       ";

				DisplayObjectBitMap< char >( ( *( beginingOfCharacterValue + 1 ) << 5 ) >> 3 );

				cout << endl;

				break;
			}
			// Three octets
			case 3 :
			{
				// Point to the third octet of m_stringToContainUTF_8encoding and set it,
				// in this octet, 6 bits can be stored, so to remove the extra two, shift accordingly
				m_stringToContainUTF_8encoding[2] |= ( *beginingOfCharacterValue << 2 ) >> 2;

				// Point to the second octet of m_stringToContainUTF_8encoding and start setting it,
				// in this octet, 6 bits can be stored. 2 bits were left set them first, shift accordingly
				m_stringToContainUTF_8encoding[1] |= *beginingOfCharacterValue >> 6;

				// Point to the second octet of m_stringToContainUTF_8encoding and end setting it,
				// 4 bits were left, take those bits from the next octet, shift slowly
				m_stringToContainUTF_8encoding[1] |= ( *( beginingOfCharacterValue + 1 ) >> 4 ) << 2;

				// Point to the first octet of m_stringToContainUTF_8encoding and set it,
				// in this octet, 4 bits can be stored. Take those and shift home
				m_stringToContainUTF_8encoding[0] |= *( beginingOfCharacterValue + 1 ) >> 4;

				break;
			}
			// Four octets
			default :
			{
				// Point to the fourth octet of m_stringToContainUTF_8encoding and set it,
				// in this octet, 6 bits can be stored, so to remove the extra two, shift accordingly
				m_stringToContainUTF_8encoding[3] |= ( *beginingOfCharacterValue << 2 ) >> 2;

				// Point to the third octet of m_stringToContainUTF_8encoding and start setting it,
				// in this octet, 6 bits can be stored. Two bits were left from before
				// so first set those, shift wisely
				m_stringToContainUTF_8encoding[2] |= *beginingOfCharacterValue >> 6;

				// Point to the third octet of m_stringToContainUTF_8encoding and end setting it,
				// 4 bits were left, take those bits from the next octet, shift slowly
				m_stringToContainUTF_8encoding[2] |= ( *( beginingOfCharacterValue + 1 ) << 4 ) >> 2;

				// Point to the second octet of m_stringToContainUTF_8encoding and start setting it,
				// in this octet, 6 bits can be stored. 4 bits were left, take those and
				// set the fourth first bits, shift regularly
				m_stringToContainUTF_8encoding[1] |= *( beginingOfCharacterValue + 1 ) >> 4;

				// Point to the second octet of m_stringToContainUTF_8encoding and end setting it,
				// 2 bits were left, take those bits from the next octet, shift carefully
				m_stringToContainUTF_8encoding[1] |= ( *( beginingOfCharacterValue + 2 ) << 6 ) >> 2;

				// Point to the first octet of m_stringToContainUTF_8encoding and set it,
				// in this octet, 3 bits can be stored. Take those and shift home
				m_stringToContainUTF_8encoding[0] |= ( *( beginingOfCharacterValue + 2 ) << 3 ) >> 5;
			}

		}

    	return ( m_stringToContainUTF_8encoding );
	}