MAKEFILES := $(shell find . -name Makefile -exec dirname {} \; | grep -v ^\.$$ | grep -v "_template" | grep -v "_test")

.PHONY: all

all: 
	@for i in $$MAKEFILES; \
	do \
		( \
			echo -------------------------------------------; \
			echo $$(basename $$i): $(if $(MAKECMDGOALS),$(MAKECMDGOALS),all) start; \
			echo -------------------------------------------; \
			cd $$i; \
			make $(MAKECMDGOALS); \
			echo -------------------------------------------; \
			echo $$(basename $$i): $(if $(MAKECMDGOALS),$(MAKECMDGOALS),all) end; \
			echo -------------------------------------------; \
		); \
	done

$(MAKECMDGOALS): all