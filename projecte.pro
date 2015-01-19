
LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio
QMAKE_CXXFLAGS += -std=c++11 -fpermissive

SOURCES += main.cpp Ball.cpp utilities.cpp
HEADERS += Ball.hpp utilites.hpp
