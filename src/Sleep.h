/*
 * Sleep.h
 *
 *  Created on: 21/01/2013
 *      Author: Marcel
 */

#ifndef SLEEP_H_
#define SLEEP_H_

#ifdef WIN32
#include <windows.h>
#define vi_sleep(x) Sleep((x)*1000)
#else
#include <unistd.h>
#define vi_sleep(x) sleep(x)
#endif

#endif /* SLEEP_H_ */
