//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file
	\author
	\date
	\brief

    History:
        20130207_1635   :

*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "cfunctions.h"
//#include <stdio.h>

//------------------------------------------------------------------------------
// Local Defines
//------------------------------------------------------------------------------
/*!
    \def
    \brief
*/
#define DEST_LEN			256
#define GET_STUCK_HERE()	for(;;){}

//------------------------------------------------------------------------------
// Enums
//------------------------------------------------------------------------------
/*!
    \enum
    \brief
*/

//------------------------------------------------------------------------------
// Local Functions prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------
/*!
    \var
    \brief
*/



#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void main( void )
{
	unsigned char result;
	unsigned char bSourceLen;
	unsigned char bSourceEmptyLen;
	char cpDest[DEST_LEN];
	char cpSource[] = "The quick brown fox jumps over the lazy dog";
	char cpSourceEmpty[] = "........................................";
	char cpNumArray[] = "holamundocruel";

	///////////////////////////////////////////////////////////////////////////
	//  Test wfnStrLen function
	///////////////////////////////////////////////////////////////////////////
	bSourceLen = wfnStrLen((unsigned char *) cpSource);
	if (bSourceLen != 43) {
		GET_STUCK_HERE();
	}

	bSourceEmptyLen = wfnStrLen((unsigned char *) cpSourceEmpty);
	if (bSourceEmptyLen != 40) {
		GET_STUCK_HERE();
	}


	///////////////////////////////////////////////////////////////////////////
	//  Test vfnMemCpy and bfnStrCmp functions
	///////////////////////////////////////////////////////////////////////////
	vfnMemCpy((unsigned char *) cpSource, (unsigned char *) cpDest, bSourceLen);
	result = bfnStrCmp((unsigned char *) cpSource, (unsigned char *) cpDest, bSourceLen);
	if (result == 1){
		GET_STUCK_HERE();
	}

	///////////////////////////////////////////////////////////////////////////
	//  Test vfnMemSet and bfnStrCmp functions
	///////////////////////////////////////////////////////////////////////////
	vfnMemSet((unsigned char *) cpDest, (unsigned char) '.', sizeof(cpSourceEmpty)-1);
	result = bfnStrCmp((unsigned char *) cpSourceEmpty, (unsigned char *) cpDest, sizeof(cpSourceEmpty)-1);
	if (result == 1){
		GET_STUCK_HERE();
	}

	///////////////////////////////////////////////////////////////////////////
	//  Test bfnFindMax and bfnFindMin functions
	///////////////////////////////////////////////////////////////////////////
	result = bfnFindMax((unsigned char *) cpNumArray, sizeof(cpNumArray)-1);
	if (result != 'u' ) {
		GET_STUCK_HERE();
	}

	result = bfnFindMin((unsigned char *) cpNumArray, sizeof(cpNumArray)-1);
	if (result != 'a') {
		GET_STUCK_HERE();
	}

    for(;;)
    {
    }



}
//------------------------------------------------------------------------------
/*!
    \fn
    \param
    \return
    \brief
*/
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
