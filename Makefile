CC = g++

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

VERSIONS = v1.0 v1.1 v1.2

all: $(VERSIONS)

$(VERSIONS):
	$(MAKE) -C $@

clean:
	@for dir in $(VERSIONS); do \
		$(MAKE) -C $$dir clean; \
	done

v1.0:
	$(MAKE) -C $@

v1.1:
	$(MAKE) -C $@

v1.2:
	$(MAKE) -C $@


.PHONY: all clean $(VERSIONS)
