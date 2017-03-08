/*
 * AppBase.h
 *
 *  Created on: 2017年2月10日
 *      Author: ocean
 */

#ifndef APPBASE_H_
#define APPBASE_H_

#include "Arduino.h"

class AppBase {
public:
	AppBase();
	virtual ~AppBase();

	virtual void setup() = 0;
	virtual void loop() = 0;
};

#endif /* APPBASE_H_ */


#define StartApp(AppClass) \
AppClass *mainApp = new AppClass(); \
void setup() { \
	mainApp->setup(); \
}\
void loop() { \
	mainApp->loop(); \
}
