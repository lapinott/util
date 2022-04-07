#pragma once
/*
	filesystem path helper class.
	use case: feed utf8 paths and convert internally to utf16 on Windows,
	no conversion needed on *nix / macos
	platform_path() returns a path suited to the host platform filesystem in the
	correct encoding (utf16 on Windows, utf8 on *nix / macos).
	u8path() returns an utf8 encoded path for all other purposes.

	This implementation assumes that native filesystem names are:
		- wchar_t strings on Windows (->utf16 encoded)
		- char strings on Linux (->utf8 encoded)
		- char string on macOS (->utf8 encoded)

	DOC
		https://en.cppreference.com/w/cpp/language/string_literal
*/

#if 0
#define __linux__
#undef _MSC_VER
#endif

#if 0
#define __APPLE__
#undef _MSC_VER
#endif

#include <string>
#include <vector>
#include <iostream>

namespace util {

	class filesystem_path_t {
	private:

		std::string
			m_u8path;

		std::wstring
			m_u16path;

	public:

		filesystem_path_t() {}

#if defined(_MSC_VER)
		using std_filesystem_path_string_type = std::wstring;//static_assert in impl. file & avoiding #include <filesystem>
#elif defined(__linux__)
		using std_filesystem_path_string_type = std::string;//static_assert in impl. file & avoiding #include <filesystem>
#elif defined(__APPLE__)
		using std_filesystem_path_string_type = std::string;//static_assert in impl. file & avoiding #include <filesystem>
#else //NetBSD?
		using std_filesystem_path_string_type = std::string;//static_assert in impl. file & avoiding #include <filesystem>
#endif

		//assumes an ascii or utf8-encoded path; string litterals must be prefixed with u8"..." if they contain non-ascii characters
		filesystem_path_t(const char* u8path);
		filesystem_path_t(const std::string& u8path);

		std::string u8path() const;

		//assumes an utf16-encoded path; string litterals must be prefixed with L"..."
		filesystem_path_t(const wchar_t* u16path);
		filesystem_path_t(const std::wstring& u16path);

		std::wstring u16path() const;

		std_filesystem_path_string_type platform_path() const;

		filesystem_path_t parent_path() const;

		bool exists() const;

		bool is_directory() const;

		bool is_regular_file() const;

		time_t last_write_time() const;

		bool last_write_time(time_t last_write_time) const;

		size_t file_size() const;

		std::vector<char> cat(std::ios::openmode open_mode = std::ios::binary) const;

		bool cat(const std::vector<char>& buf, std::ios::openmode open_mode = std::ios::binary) const;
	};
}