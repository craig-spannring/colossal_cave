cmake_minimum_required(VERSION 3.20)
project(advent)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_C_STANDARD 99)


find_package(Doxygen)


set(TEXT_FILES # List of all text files that will be indexed by advent0
  ${CMAKE_CURRENT_LIST_DIR}/advent1.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent2.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent3.txt
  ${CMAKE_CURRENT_LIST_DIR}/advent4.txt)

# TODO- Figure out how we want to handle installing text files. 
file(COPY ${TEXT_FILES} DESTINATION /tmp/.)

# Add a custom command to generate advtext.hpp
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/advtext.hpp
    COMMAND advent0 ${TEXT_FILES} ${CMAKE_CURRENT_BINARY_DIR}/advtext.hpp 
    COMMENT "Generating advtext.hpp"
)
add_custom_target(generate_advtext ALL DEPENDS advtext.hpp)

add_executable(advent0 advent0.cpp)


set(ADV_SRC
  advent.cpp
  database.cpp
  english.cpp             
  itverb.cpp              
  turn.cpp                
  verb.cpp
)
set(ADV_HDR
  advcave.hpp
  advdec.hpp
  advdef.hpp
  advent.hpp
  advword.hpp
  proto.hpp
)
set(ADV_GENED_HDR 
  ${CMAKE_CURRENT_BINARY_DIR}/advtext.hpp
)
string(REPLACE ";" " " ADV_SRC_FILES "${ADV_SRC}")
string(REPLACE ";" " " ADV_HDR_FILES "${ADV_HDR}")
string(REPLACE ";" " " ADV_GENED_HDR_FILES "${ADV_GENED_HDR}")


add_executable(advent)
target_include_directories(advent PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(advent generate_advtext)
target_sources(advent PRIVATE ${ADV_SRC} ${ADV_HDR} ${ADV_GENED_HDR})


# Add commands to make doxydocs if we found doxygen
if(DOXYGEN_FOUND)
  #
  # Note- Don't get your hopes up.  The source code doesn't really
  # have any doxydocs comments.
  # 
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/Doxyfile.tmpl
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
  
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/DoxyDocs/html/index.html
    COMMAND Doxygen::doxygen ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    DEPENDS ${ADV_SRC} ${ADV_HDR} ${ADV_GENED_HDR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    COMMENT            "Building doxydocs."
    VERBATIM
    COMMAND_EXPAND_LISTS
  )
  add_custom_target(docs DEPENDS generate_advtext ${CMAKE_CURRENT_BINARY_DIR}/DoxyDocs/html/index.html)
else()
  message("Doxygen package not found!  Can not generate doxydocs")
endif() 
