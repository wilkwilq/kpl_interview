# kpl_interview
Interview Task

Assumptions:\
-"start" and "end" need to be different. For example (1, 1) make no sense as 1 can not be inclusive and exclusive at the same time\
-"start" < "end"\
-kepler struct is always sorted, it is not possible to have state [(5,10),(1,3)] it will always be passed to Add() or Delete() as [(1,3), (5,10)] 


Unit Testing was done is Google Test. To be able to compile and run them please follow this setup instruction:\
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

then use gtest.sh script that is located in the project directory. 

To just see that it is working it is possible to run "runTests" program located in "unit_tests" directory
