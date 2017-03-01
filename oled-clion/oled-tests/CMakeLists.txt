CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
SET(CMAKE_SYSTEM_NAME Generic)
PROJECT(oled-clion-tests)

file(GLOB TARGET_SRC
        "../oled/Classes/LinkedArray.h"
        "../oled/Classes/LinkedArray.cpp"
        "../oled/Classes/Graphics.h"
        "../oled/Classes/Graphics.cpp"
        "main.cpp"
)

include_directories(/usr/local/include)
include_directories(/usr/include)

SET(SOURCE_FILES
        ${TARGET_SRC}
)

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

include_directories("../oled/Classes")