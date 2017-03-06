CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
SET(CMAKE_SYSTEM_NAME Generic)

PROJECT(oled-clion)

#============================================================================================

file(GLOB TARGET_SRC
        "main.cpp"
        "../../libs/*.h"
        "../../libs/*.cpp"
        "../../libs/**/*.h"
        "../../libs/**/*.cpp"
)

SET(SOURCE_FILES
        ${TARGET_SRC}
)

set(DEVICE "atmega16")
set(FREQ "1000000")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER /usr/local/CrossPack-AVR/bin/avr-g++)

set(CMAKE_C_FLAGS "-Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=${DEVICE} -DF_CPU=${FREQ}UL -std=gnu99 -Wl,--gc-sections")
set(CMAKE_CXX_FLAGS  "-Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=${DEVICE} -DF_CPU=${FREQ}UL -Wl,--gc-sections")


ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ../../libs)
target_include_directories(${PROJECT_NAME} PRIVATE ../../libs/oled)
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/CrossPack-AVR-20131216/avr/include)
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/CrossPack-AVR-20131216/lib/gcc/avr/4.8.1/include)
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/CrossPack-AVR-20131216/lib/gcc/avr/4.8.1/include-fixed)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -R.eeprom -R .fuse -R .lock -R .signature ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.eep)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND avr-size ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} --mcu=${DEVICE} --format=avr)

SET(AVRDUDE /usr/local/CrossPack-AVR-20131216/bin/avrdude)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${AVRDUDE} -pm16 -cusbasp -Uflash:w:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex:a )
