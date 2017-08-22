DEBUG := 1

# ***************************************************

ifdef DEBUG
	CXXFLAGS := -g
	LDFLAGS  :=
else
	CXXFLAGS := -O2
	LDFLAGS  := -Wl,-s
endif

TARGET ?= genproc

# include path
INCLUDE	:= -I../manual -I../auto

# compiler settings
CXXFLAGS += $(INCLUDE) -Wall
LDFLAGS  += -lpthread

TRACE_LIST :=$(addsuffix .o,$(TRACECLASSES))

# find sources and headers
SOURCES	:= $(wildcard ../auto/*.cpp ../manual/*.cpp)
HEADERS	:= $(wildcard ../auto/*.h ../manual/*.h)

# objects go into current directory
OBJS	:= $(notdir $(SOURCES:.cpp=.o))

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

build:	$(TARGET)

install:	build
	install -s $(TARGET) ~/genproc/
	cp ../../../../../resources/style.css ~/genproc/html/
	cp ../../../../../resources/md/example_* ~/genproc
	cp ./*.png ~/genproc/

clean:
	rm -f $(TARGET) *.o .depend

run:	$(TARGET)
	./$(TARGET) -i resources/main.txt -o ~/html

rebuild:	clean build

$(TARGET):	.depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend:	Makefile $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
