AUTOMAKE_OPTIONS = subdir-objects
SUBDIRS = $(LIBMASA_PATH)

CXX=$(mcxx)

bin_PROGRAMS = masa-starpu
masa_starpu_CXXFLAGS = -malign-double -fno-strict-aliasing  -I$(TAREDOR_HOOKS_HOME)
masa_starpu_LDADD  = $(LIBMASA_PATH)/libmasa.a -lpthread $(pkg-config --libs starpu-1.2) $(TAREADOR_LDFLAGS) 
masa_starpu_SOURCES = \
./src/main.cpp \
./src/StarPuAligner.cpp \
./src/StarPuAlignerParameters.cpp 
dist_doc_DATA = README
EXTRA_DIST = masa-starpu.script

noinst_HEADERS = \
./src/StarPuAligner.hpp \
./src/StarPuAlignerParameters.hpp 

dist-clone-link:
	@if test -L $(LIBMASA_PATH); then \
		mv $(LIBMASA_PATH) $(LIBMASA_PATH).link && \
		cp -r -L $(LIBMASA_PATH).link $(LIBMASA_PATH); \
	fi
 
dist-unclone-link:
	@if test -L $(LIBMASA_PATH).link; then \
		rm -rf $(LIBMASA_PATH) && \
		mv $(LIBMASA_PATH).link $(LIBMASA_PATH); \
	fi
 
dist-link: dist-clone-link dist dist-unclone-link
