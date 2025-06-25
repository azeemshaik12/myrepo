# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appdraganddrop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appdraganddrop_autogen.dir\\ParseCache.txt"
  "appdraganddrop_autogen"
  )
endif()
