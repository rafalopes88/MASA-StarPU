AUTOMAKE_OPTIONS = subdir-objects
SUBDIRS = $(LIBMASA_PATH)

CXX=$(mcxx)

bin_PROGRAMS = masa-ompss
masa_ompss_CXXFLAGS = -malign-double -fno-strict-aliasing  -I$(TAREDOR_HOOKS_HOME)
masa_ompss_LDADD  = $(LIBMASA_PATH)/libmasa.a -lpthread $(TAREADOR_LDFLAGS)
masa_ompss_SOURCES = \
./src/main.cpp \
./src/OmpSsAligner.cpp \
./src/OmpSsAlignerParameters.cpp 
dist_doc_DATA = README
EXTRA_DIST = masa-ompss.script

noinst_HEADERS = \
./src/OmpSsAligner.hpp \
./src/OmpSsAlignerParameters.hpp 

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
