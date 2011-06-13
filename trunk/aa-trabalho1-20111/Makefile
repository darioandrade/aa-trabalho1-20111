CXXFLAGS = -O2 -g -Wall -fmessage-length=0

OBJS_HEAP = heaptest.o
OBJS_GRAPHGEN = graphgen.o
OBJS_READWRITE = readwritetest.o
OBJS_COBERTURA = cobertura.o

LIBS = DegreeHeapAdjacencyList.o DegreeVectorAdjacencyList.o AdjacencyList.o GeraGrafo.o AlgoritmoCoberturaGulosa.o VertexVectorAdjacencyList.o Heap.o

TARGET-HEAP = heaptest
TARGET-READWRITE = readwritetest
TARGET-GRAPHGEN = graphgen

TARGET-COBERTURA = cobertura

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.cpp: %.h

all: $(TARGET-GRAPHGEN) $(TARGET-COBERTURA) $(TARGET-READWRITE) $(TARGET-HEAP) 

$(TARGET-GRAPHGEN): $(OBJS_GRAPHGEN) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-GRAPHGEN) $(TARGET-GRAPHGEN).o $(LIBS)

$(TARGET-READWRITE): $(OBJS_READWRITE) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-READWRITE) $(TARGET-READWRITE).o $(LIBS)

$(TARGET-COBERTURA): $(OBJS_COBERTURA) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-COBERTURA) $(TARGET-COBERTURA).o $(LIBS)

$(TARGET-HEAP): $(OBJS_HEAP) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET-HEAP) $(TARGET-HEAP).o $(LIBS)

clean:
	rm -f *.o $(TARGET-GRAPHGEN) $(TARGET-COBERTURA) $(TARGET-READWRITE) $(TARGET-HEAP)
