//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file   cfunctions.h
	\author Raul Villanueva
	\date   05.25.2013
	\brief	Contains declarations for common or standard c libraries
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#ifndef	__CFUNCTIONS_H__
#define	__CFUNCTIONS_H__
    //--------------------------------------------------------------------------
    // Includes
    //--------------------------------------------------------------------------
#include <stdint.h>

    //--------------------------------------------------------------------------
    // Defines
    //--------------------------------------------------------------------------
#define NULL	0
#define FALSE	0
#define TRUE	(!)
	/*
		\def	NULL
		\brief
	*/
    //--------------------------------------------------------------------------
    // Enums
    //--------------------------------------------------------------------------
	/*
		\enum
		\brief
	*/
    //--------------------------------------------------------------------------
    // Variables
    //--------------------------------------------------------------------------


    //--------------------------------------------------------------------------
    // Functions
    //--------------------------------------------------------------------------

void vfnMemCpy(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize);
void vfnMemSet(unsigned char* bpDest, unsigned char bByteToFill, unsigned short wSize);
unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize);
unsigned char bfnFindMin(unsigned char* bpDest, unsigned short wSize);
unsigned char bfnStrCmp(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize);
unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize);
unsigned short wfnStrLen (unsigned char* bpString);
//------------------------------------------------------------------------------
#endif
