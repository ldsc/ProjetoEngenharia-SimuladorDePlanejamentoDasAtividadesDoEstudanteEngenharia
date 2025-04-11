# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PetroPlanner_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PetroPlanner_autogen.dir\\ParseCache.txt"
  "PetroPlanner_autogen"
  )
endif()
