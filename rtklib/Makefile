all: rtklib

TARBALL = build/rtklib_2.4.1.zip
TARBALL_URL = http://www.rtklib.com/prog/rtklib_2.4.1.zip
SOURCE_DIR = build/rtklib_2.4.1
MD5SUM_FILE = rtklib_2.4.1.zip.md5sum
UNPACK_CMD = unzip
include $(shell rospack find mk)/download_unpack_build.mk
include $(shell rospack find mk)/cmake.mk

rtklib: $(SOURCE_DIR)/unpacked
	-mkdir include
	cp $(SOURCE_DIR)/src/rtklib.h include
	-mkdir src
	cp -r $(SOURCE_DIR)/src/* src

wipe: clean
	-rm -rf src include lib
