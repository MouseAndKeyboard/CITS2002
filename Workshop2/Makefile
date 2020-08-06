##
# myCal
#
# @file
# @version 0.1

./bin/myCal: runner.c ./bin/myCal.o
	cc runner.c ./bin/myCal.o -o ./bin/myCal

./bin/myCal.o: myCal.c myCal.h
	cc -g -O -c myCal.c -o ./bin/myCal.o

# end
