//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/*!
	\file
	\author
	\date
	\brief
*/
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "cfunctions.h"

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------
/*!
    \def
    \brief
*/


//------------------------------------------------------------------------------
// Enums
//------------------------------------------------------------------------------
/*!
    \enum
    \brief
*/


//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------
/*!
    \var
    \brief
*/

//------------------------------------------------------------------------------
/*!
    \fn				void vfnMemCpy(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize)
    \param[in] 		bpSource bloque de memoria desde donde va a ser copiado
    \param[out] 	bpDest bloque de memoria hacia donde va a ser copiado
    \param[in]		wSize longitud del bloque de memoria a ser copiado
    \return 		nada
    \brief  		Copia los datos del bloque apuntado por bpSource al bloque
    				apuntado por bpDest.
*/
//------------------------------------------------------------------------------
void vfnMemCpy(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize) {

	/* evita una excepcion al momento del cpu intente desreferenciar un apuntador.
	 * Debido a que esta funcion no puede regresar una bandera indicando error,
	 * al menos intenta regresar en caso de error */
	if (bpSource == NULL || bpDest == NULL) return;

	while (wSize) {
		*bpDest= *bpSource;
		bpSource++;
		bpDest++;
		wSize--;
	}
}

//------------------------------------------------------------------------------
/*!
    \fn				void vfnMemSet(unsigned char* bpDest, unsigned char bByteToFill, unsigned short wSize)
    \param[out]		bpDest	bloque de memoria a ser modificado
    \param[in]		bByteToFill	valor que sera copiado en memoria
    \param[in]		wSize	candidad de veces a ser copiado
    \return			nothing
    \brief			Rellena el bloque apuntado por bpDest con el dato indicado por bByteToFill
*/
//------------------------------------------------------------------------------
void vfnMemSet(unsigned char* bpDest, unsigned char bByteToFill, unsigned short wSize) {

	/* evita una excepcion al momento del cpu intente desreferenciar un apuntador.
	 * Debido a que esta funcion no puede regresar una bandera indicando error,
	 * al menos intenta regresar en caso de error */
	if (bpDest == NULL) return;

	while (wSize) {
		*bpDest= bByteToFill;
		bpDest++;
		wSize--;
	}
}

//------------------------------------------------------------------------------
/*!
    \fn				unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize)
    \param[in]		bpDest bloque de memoria a ser escaneado.
    \param[in]		wSize longitud del bloque de memoria
    \return			numero maximo encontrado en bpDest
    \brief			Devuelve el número sin signo mayor encontrado en el bloque de memoria apuntado
     	 	 	 	por bpDest
*/
//------------------------------------------------------------------------------
unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize) {
	unsigned char bMax;

	/* evita una excepcion al momento del cpu intente desreferenciar un apuntador.
	 * Debido a que esta funcion no puede regresar una bandera indicando error,
	 * al menos intenta regresar en caso de error */
	if (bpDest == NULL) return 0;

	bMax = *bpDest;

	while (wSize) {
		if ( *bpDest > bMax ){
			bMax = *bpDest;
		}
		bpDest++;
		wSize--;
	}
	return bMax;
}

//------------------------------------------------------------------------------
/*!
    \fn				unsigned char bfnFindMin(unsigned char* bpDest, unsigned short wSize)
    \param[in]		bpDest bloque de memoria a ser escaneado.
    \param[in]		wSize longitud del bloque de memoria
    \return			numero minimo encontrado en bpDest
    \brief			Devuelve el número sin signo menor encontrado en el bloque de memoria apuntado
     	 	 	 	por bpDest
*/
//------------------------------------------------------------------------------
unsigned char bfnFindMin(unsigned char* bpDest, unsigned short wSize) {
	unsigned char bMin;

	/* evita una excepcion al momento del cpu intente desreferenciar un apuntador.
	 * Debido a que esta funcion no puede regresar una bandera indicando error,
	 * al menos intenta regresar en caso de error */
	if (bpDest == NULL) return 0;

	bMin = *bpDest;

	while (wSize) {
		if ( *bpDest < bMin ){
			bMin = *bpDest;
		}
		bpDest++;
		wSize--;
	}
	return bMin;
}

//------------------------------------------------------------------------------
/*!
    \fn				unsigned char bfnStrCmp(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize)
    \param[in]		bpSource cadena fuente
    \param[in]		bpDest	cadena destino a comparar
    \param[in]		wSize caracteres a comparar
    \return			1 si las cadenas son iguales y un 0 si son distintas
    \brief			Compara las cadenas apuntadas por bpSource y bpDest
*/
//------------------------------------------------------------------------------
unsigned char bfnStrCmp(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize) {
	/* el default es que las cadenas sean iguales, asi que ponlo a 1 */
	 unsigned char bMismaCadena = 1;

	/* evita una excepcion al momento del cpu intente desreferenciar un apuntador.
	 * Debido a que esta funcion no puede regresar una bandera indicando error,
	 * al menos intenta regresar en caso de error */
	if (bpSource == NULL || bpDest == NULL) return 0;

	while (wSize) {
		if ( *bpSource != *bpDest ){
			bMismaCadena = 0;
			break;
		}
		bpSource++;
		bpDest++;
		wSize--;
	}

	return bMismaCadena;
}

//------------------------------------------------------------------------------
/*!
    \fn				unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize)
    \param[in]		bpString	apuntador a bloque de memoria que contiene el string en donde buscar
    \param[in]		bCharToFind	caracter a ser buscado
    \param[in]		wSize		longitud de bpString
    \return			direccion donde se encuentra el valor bCharToFind en la cadena bpString. NULL si no es
    				encontrado.
    \brief			Entrega la dirección donde se encuentra el valor bCharToFind en la cadena bpString. En caso de no
encontrar datos, regresa un apuntador a NULL
*/
//------------------------------------------------------------------------------
unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize) {
	/* default bpFoundAddress a NULL. Esta variable sera cambiada solo si se encuentra bCharToFind */
	unsigned char* bpFoundAddress = NULL;

	while (wSize) {
		if (*bpString == bCharToFind) {
			bpFoundAddress = bpString;
			break;
		}
		bpString++;
		wSize--;
	}

	return bpFoundAddress;
}


//------------------------------------------------------------------------------
/*!
    \fn				unsigned short wfnStrLen (unsigned char* bpString)
    \param[in]		bpString string de entrada
    \return
    \brief			Devuelve el tamaño de la cadena terminada en 0 apuntada por bpString.
*/
//------------------------------------------------------------------------------
unsigned short wfnStrLen (unsigned char* bpString) {
	unsigned short wStrLen = 0;

	while(*bpString != '\0') {
		bpString++;
		wStrLen++;
	}

	return wStrLen;
}


//------------------------------------------------------------------------------

