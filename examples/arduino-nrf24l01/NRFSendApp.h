//
// Created by wangyang on 17/3/8.
//

#ifndef NRF_NRFSENDAPP_H
#define NRF_NRFSENDAPP_H

#include "AppBase.h"

class NRFSendApp  : public AppBase {
public:
    virtual void setup();
    virtual void loop();

private:
    void sendBytes(uint8_t *data, uint8_t count);
};


#endif //NRF_NRFSENDAPP_H
