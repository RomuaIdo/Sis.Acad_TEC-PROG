CC = g++

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 

VERSIONS = v1.0 v2.0 v3.0 v4.0

all: $(VERSIONS)

$(VERSIONS):
	$(MAKE) -C $@ TARGET_NAME=$@

run-%:
	@if [ -f "$*/bin/programa_$*" ]; then \
		echo "Executando $*..."; \
		cd $* && ./bin/$*_programa; \
	else \
		$(MAKE) -C $* TARGET_NAME=$* && \
		echo "Executando..." && \
		cd $* && ./bin/$*_programa; \
	fi


clean:
	@for dir in $(VERSIONS); do \
		$(MAKE) -C $$dir clean; \
	done


.PHONY: all run-% clean $(VERSIONS)
