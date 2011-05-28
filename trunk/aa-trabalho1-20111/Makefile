CXXFLAGS = -O2 -g -Wall -fmessage-length=0

OBJS = graphgen.o

LIBS = AdjacencyList.o GeraGrafo.o

TARGET-GRAPHGEN = graphgen

TARGET-VECTOR = vector

TARGET-HEAP = heap

TARGET-LISTSET = listset

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.cpp: %.h

all: $(TARGET-GRAPHGEN) $(TARGET-VECTOR) $(TARGET-HEAP) $(TARGET-LISTSET)

$(TARGET-GRAPHGEN): $(OBJS) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-GRAPHGEN) $(TARGET-GRAPHGEN).o $(LIBS)

clean:
	rm -f *.o $(TARGET-GRAPHGEN) $(TARGET-VECTOR) $(TARGET-HEAP) $(TARGET-LISTSET)
