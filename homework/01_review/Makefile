SRCS = Draw.cpp DrawMenu.cpp submitty_driver.cpp
EXE = a.out


ifneq ("$(wildcard DrawDriver.cpp)","")
	# Code.CS student settings
	SRCS = Draw.cpp DrawMenu.cpp DrawDriver.cpp
	EXE = Draw.out
else ifneq ("$(wildcard Draw.cpp)","")
	# Submitty submission
    # Do nothing. Leave defaults.
else
    # Code.CS TA settings
    SRCS = ../Draw.cpp DrawMenu.cpp submitty_driver.cpp
endif

# Everything below this should not have to change ever.

CXX=g++
LD=g++
CC=g++

TARGET = all 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -std=c++17 $(SUBMITTY_CXXFLAGS)

LDFLAGS = -g 
LIBS =

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(EXE)

clean:
	-rm -f $(OBJS)
	-rm -f $(EXE)
	-rm -f solutions.txt
