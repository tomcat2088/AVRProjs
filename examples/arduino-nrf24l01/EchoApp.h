/*
 * EchoApp.h
 *
 *  Created on: 2017年2月10日
 *      Author: ocean
 */

#ifndef ECHOAPP_H_
#define ECHOAPP_H_

#include "AppBase.h"

class EchoApp : public AppBase {
public:
	EchoApp();
	virtual ~EchoApp();

	virtual void setup();
	virtual void loop();
};

#endif /* ECHOAPP_H_ */
