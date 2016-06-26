/*
 * mycout.h
 *
 *  Created on: Jun 26, 2016
 *      Author: Administrator PC
 */

#ifndef MYCOUT_H_
#define MYCOUT_H_

template<class T> inline Print &operator <<(Print &obj, T arg) {
	obj.print(arg);
	return obj;
}

#endif /* MYCOUT_H_ */
