#pragma once

#include <string>

namespace util {

	/*
		As of now, the empty string is returned on anything else than Windows
	*/

	//https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
	std::wstring Utf8ToUtf16(std::string str);

	//https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte
	std::string Utf16ToUtf8(std::wstring str);

	/*
		DOC
			https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
				Maps a character string to a UTF-16 (wide character) string. The character string is not necessarily from a multibyte character set.

			https://stackoverflow.com/questions/30829364/open-utf8-encoded-filename-in-c-windows

			portable way for this?
				https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
				[DEPRECATED]http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0618r0.html
	*/
}