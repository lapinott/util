#include <util/utf8_utf16_conv.h>

#ifdef _MSC_VER
#include <windows.h>
#endif

namespace util {

	std::wstring Utf8ToUtf16(std::string str) {
#ifdef _MSC_VER
		std::wstring ret;
		int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0);
		if (len > 0) {
			ret.resize(len);
			MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), &ret[0], len);
		}
		return ret;
#else
		//throw std::exception{ "not implemented." };
		return std::wstring{};
#endif
	}

	std::string Utf16ToUtf8(std::wstring str) {
#ifdef _MSC_VER
		std::string ret;
		int len = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0, NULL, NULL);
		if (len > 0) {
			ret.resize(len);
			WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), &ret[0], len, NULL, NULL);
		}
		return ret;
#else
		//throw std::exception{ "not implemented." };
		return std::string{};
#endif
	}
}