/*
 * BIT_MATH.h
 *
 *  Created on: Sep 20, 2021
 *      Author: dell
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define SetBit(VAR,BIT)	    ( VAR |=(1 << (BIT)))
#define ClearBit(VAR,BIT)	(VAR &=	~(1 << (BIT)))
#define GetBit(VAR,BIT)	  (((VAR	>>BIT)	&  1))
#define ToggleBit(VAR,BIT)	(VAR ^= (1 << (BIT)))


#endif /* BIT_MATH_H_ */
