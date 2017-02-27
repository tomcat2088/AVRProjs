CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
SET(CMAKE_SYSTEM_NAME Generic)

#============================================================================================
PROJECT(oled-clion)

SET(DEVICE "atmega16")
SET(FREQ "1000000")

#============================================================================================

SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER /usr/local/CrossPack-AVR/bin/avr-g++)

SET(CMAKE_C_FLAGS "-Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=${DEVICE} -DF_CPU=${FREQ}UL -std=gnu99 -Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS  "-Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=${DEVICE} -DF_CPU=${FREQ}UL -Wl,--gc-sections")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(Classes)
include_directories(/usr/local/CrossPack-AVR-20131216/avr/include)
include_directories(/usr/local/CrossPack-AVR-20131216/lib/gcc/avr/4.8.1/include)
include_directories(/usr/local/CrossPack-AVR-20131216/lib/gcc/avr/4.8.1/include-fixed)

#============================================================================================

file(GLOB TARGET_SRC
        "main.cpp"
        "Classes/*.h"
        "Classes/*.cpp"
        "Classes/**/*.h"
        "Classes/**/*.cpp"
)

SET(SOURCE_FILES
        ${TARGET_SRC}
)

#============================================================================================

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -R.eeprom -R .fuse -R .lock -R .signature ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-size ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} --mcu=${DEVICE} --format=avr)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avrdude -pm16 -carduino -P/dev/cu.usbmodem1461 -b115200 -Uflash:w:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex:a )