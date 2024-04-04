cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Acm_III) 

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executables

# testovani
# add_executable(test test.cpp)

# # minisoutez I
# add_executable(odd_sum 1_4_odd_sum.cpp)
# add_executable(aggrcow 1_6_aggrcow.cpp)

# minisoutez II

# minisoutez III
add_executable(maze 5_1_RRmaze.cpp)
add_executable(route 5_3_RouteChange.cpp)
add_executable(cars 5_4_FunnyCarRacing.cpp)

# minisoutez IV
add_executable(fact 7_2_FactorialFactors.cpp)
add_executable(sum 7_9_Summation.cpp)





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


