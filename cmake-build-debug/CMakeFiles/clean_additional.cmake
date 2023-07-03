# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TSP_GA_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TSP_GA_autogen.dir/ParseCache.txt"
  "TSP_GA_autogen"
  )
endif()
