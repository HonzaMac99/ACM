cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Acm_III) 

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(test test.cpp)
add_executable(odd_sum 1_04_odd_sum.cpp)
add_executable(aggrcow 1_6_aggrcow.cpp)
add_executable(maze 5_1_RRmaze.cpp)
add_executable(test.cpp)

# enable_testing()
# 
# function(do_test target arg result)
#   add_test(NAME Comp<${arg}> COMMAND ${target} ${arg})
#   set_tests_properties(Comp<${arg}>
#     PROPERTIES PASS_REGULAR_EXPRESSION ${result}
#     )
# endfunction()

# # check if the executable is able to run
# add_test(NAME Runs COMMAND task01 -f)

# # do a bunch of result based tests
# foreach(i RANGE 1 9) 
#   #message(STATUS "I=${i}")
#   file(READ "./datapub/pub0${i}.out" outStringRef)
#   do_test(task01 "../datapub/pub0${i}.in" ${outStringRef}) 
# endforeach()
# 
# file(READ "./datapub/pub10.out" outStringRef)
# do_test(task01 "../datapub/pub10.in" ${outStringRef}) 


