CXXFLAGS = -O2 -g -Wall -fmessage-length=0

OBJS_GRAPHGEN = graphgen.o
OBJS_READWRITE = readwritetest.o

LIBS = DegreeVectorAdjacencyList.o AdjacencyList.o GeraGrafo.o

TARGET-READWRITE = readwritetest

TARGET-GRAPHGEN = graphgen

TARGET-VECTOR = vector

TARGET-HEAP = heap

TARGET-LISTSET = listset

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.cpp: %.h

all: $(TARGET-GRAPHGEN) $(TARGET-VECTOR) $(TARGET-HEAP) $(TARGET-LISTSET)

$(TARGET-GRAPHGEN): $(OBJS_GRAPHGEN) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-GRAPHGEN) $(TARGET-GRAPHGEN).o $(LIBS)

$(TARGET-READWRITE): $(OBJS_READWRITE) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-READWRITE) $(TARGET-READWRITE).o $(LIBS)

clean:
	rm -f *.o $(TARGET-GRAPHGEN) $(TARGET-VECTOR) $(TARGET-HEAP) $(TARGET-LISTSET) $(TARGET-READWRITE)
