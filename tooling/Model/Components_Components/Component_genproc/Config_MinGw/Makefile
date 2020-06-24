CXX := i686-w64-mingw32-g++

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

HEADERS += ../auto/folder.png.h
HEADERS += ../auto/folder_selected.png.h
HEADERS += ../auto/repository.png.h
HEADERS += ../auto/repository_selected.png.h
HEADERS += ../auto/role.png.h
HEADERS += ../auto/tool.png.h

../auto/folder.png.h: ../../../../../resources/Folder_small.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../auto/folder_selected.png.h: ../../../../../resources/Folder_selected_small.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../auto/repository.png.h: ../../../../../resources/repository_small.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../auto/repository_selected.png.h: ../../../../../resources/repository_selected_small.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../auto/role.png.h: ../../../../../resources/actor_klein.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../auto/tool.png.h: ../../../../../resources/tools_small.png
	../../Component_bin2c/Config_Linux/bin2c $< $@ 

../../Component_bin2c/Config_Linux/bin2c:
	make -C ../../Component_bin2c/Config_Linux/ TARGET=bin2c

%.o:	../auto/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

%.o:	../manual/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(if $(findstring $(notdir $@),$(TRACE_LIST)),-D_TRACE_ -include Trace2UML.h,) -c -o $@ $<

build:	../../Component_bin2c/Config_Linux/bin2c  $(TARGET).exe

install:	build
	install -s $(TARGET) ~/genproc/
	cp ../../../../../resources/style.css ~/genproc/html/
	cp ../../../../../resources/md/example_* ~/genproc
	cp ./*.png ~/genproc/

clean:
	rm -f $(TARGET).exe *.o .depend

run:	$(TARGET).exe
	./$(TARGET).exe -i resources/main.txt -o ~/html

rebuild:	clean build

$(TARGET).exe: .depend $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

.depend: ../../Component_bin2c/Config_Linux/bin2c $(SOURCES) $(HEADERS)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) >$@

-include .depend
