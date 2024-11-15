# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Q1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Q1_autogen.dir\\ParseCache.txt"
  "Q1_autogen"
  )
endif()
