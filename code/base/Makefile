CXX := g++
CXXFLAGS := -std=c++20 -fsanitize=address,undefined -g3 -Wall -Wextra -Wshadow -Wpedantic -Wconversion -Wformat=2

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
