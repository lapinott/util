add_library(util STATIC
	"include/util/filesystem_path_t.h"
	"include/util/split.h"
	"include/util/utf8_utf16_conv.h"
	"source/filesystem_path_t.cpp"
	"source/split.cpp"
	"source/utf8_utf16_conv.cpp")
	
target_include_directories(util PUBLIC "include")
target_include_directories(util PUBLIC "${BOOST_DIR}")