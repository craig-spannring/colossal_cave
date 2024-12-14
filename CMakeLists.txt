cmake_minimum_required(VERSION 3.20)
project(advent)

set(CMAKE_C_STANDARD 99)



# Set the dependencies for the custom command
set(TEXT_FILES
  ${CMAKE_CURRENT_LIST_DIR}/advent1.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent2.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent3.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent4.txt)

file(COPY ${TEXT_FILES} DESTINATION /tmp/.)

# Add a custom command to generate advtext.h
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/advtext.h
    COMMAND echo advent0 ${TEXT_FILES} ${CMAKE_CURRENT_BINARY_DIR}/advtext.h 
    COMMAND advent0 ${TEXT_FILES} ${CMAKE_CURRENT_BINARY_DIR}/advtext.h 
    DEPENDS advent0 ${TEXT_FILES}
    COMMENT "Generating advtext.h"
)
add_custom_target(generate_advtext ALL DEPENDS advtext.h)

set(ADV_SRC
  advent.c
  database.c
  english.c             
  itverb.c              
  turn.c                
  verb.c
)
set(ADV_HDR
  advcave.h
  advdec.h
  advdef.h
  advent.h
  advword.h
  proto.h
  
  ${CMAKE_CURRENT_BINARY_DIR}/advtext.h
)

add_executable(advent) #  advent.c)
target_include_directories(advent PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(advent generate_advtext)
target_sources(advent PRIVATE ${ADV_SRC} ${ADV_HDR})

add_executable(advent0 advent0.c)
