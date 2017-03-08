/*
 * EchoApp.cpp
 *
 *  Created on: 2017年2月10日
 *      Author: ocean
 */

#include "EchoApp.h"

EchoApp::EchoApp() {

}

EchoApp::~EchoApp() {

}


void EchoApp::setup() {
	Serial.begin(9600);
	Serial.println("Hello World");
	::pinMode(LED_BUILTIN, OUTPUT);
}

void EchoApp::loop() {
	String str = Serial.readString();
	if (str != "") {
		Serial.println("U said to me :" + str);
	}
}
