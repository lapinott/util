set(UTIL_PUBLIC_HEADERS
	"include/util/filesystem_path_t.h"
	"include/util/split.h"
	"include/util/utf8_utf16_conv.h")
	
set(UTIL_SOURCE_FILES
	"source/filesystem_path_t.cpp"
	"source/split.cpp"
	"source/utf8_utf16_conv.cpp")

add_library(util STATIC ${UTIL_PUBLIC_HEADERS} ${UTIL_SOURCE_FILES})
	
target_include_directories(util PUBLIC "include")
target_include_directories(util PUBLIC "${BOOST_DIR}")

install(TARGETS util LIBRARY DESTINATION lib)
install(FILES ${UTIL_PUBLIC_HEADERS} DESTINATION "include/util")