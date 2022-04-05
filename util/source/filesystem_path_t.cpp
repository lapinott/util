#include <util/filesystem_path_t.h>
#include <util/utf8_utf16_conv.h>
#include <filesystem>
#include <fstream>
#include <boost/filesystem/operations.hpp>

namespace util {

	static_assert(std::is_same<filesystem_path_t::std_filesystem_path_string_type, std::filesystem::path::string_type>::value, "std::filesystem::path::string_type mismatch.");

	filesystem_path_t::filesystem_path_t(const char* u8path) {
		m_u8path = u8path;
		m_u16path = util::Utf8ToUtf16(u8path);
	}

	filesystem_path_t::filesystem_path_t(const std::string& u8path) : filesystem_path_t(u8path.c_str()) {}

	std::string filesystem_path_t::u8path() const {
		return m_u8path;
	}

	filesystem_path_t::filesystem_path_t(const wchar_t* u16path) {
		m_u8path = util::Utf16ToUtf8(u16path);
		m_u16path = u16path;
	}

	filesystem_path_t::filesystem_path_t(const std::wstring& u16path) : filesystem_path_t(u16path.c_str()) {}

	std::wstring filesystem_path_t::u16path() const {
		return m_u16path;
	}

	std::filesystem::path::string_type filesystem_path_t::platform_path() const {
#ifdef _MSC_VER
		return m_u16path;
#endif
#ifdef __linux__
		return m_u8path;
#endif
#ifdef __APPLE__
		return m_u8path;
#endif
	}

	filesystem_path_t filesystem_path_t::parent_path() const {
		return std::filesystem::path(platform_path()).parent_path().c_str();
	}

	bool filesystem_path_t::exists() const {
		return std::filesystem::exists(platform_path());
	}

	bool filesystem_path_t::is_directory() const {
		return std::filesystem::is_directory(platform_path());
	}

	bool filesystem_path_t::is_regular_file() const {
		return std::filesystem::is_regular_file(platform_path());
	}

	time_t filesystem_path_t::last_write_time() const {
		return boost::filesystem::last_write_time(platform_path());
		//return std::filesystem::last_write_time(platform_path()).time_since_epoch().count();
	}

	bool filesystem_path_t::last_write_time(time_t last_write_time) const {
		boost::system::error_code ec;
		boost::filesystem::last_write_time(platform_path(), last_write_time, ec);//boost dependency here
		return !ec.failed();
	}

	size_t filesystem_path_t::file_size() const {
		return std::filesystem::file_size(platform_path());
	}

	std::vector<char> filesystem_path_t::cat() const {
		size_t sz = file_size();
		std::vector<char> buf(sz);
		std::ifstream ifs{ platform_path(), std::ios::binary };
		ifs.read(buf.data(), sz);
		ifs.close();
		if (!ifs.bad())
			return buf;
		else
			return {};
	}

	bool filesystem_path_t::cat(const std::vector<char>& buf, std::ios::openmode open_mode) const {
		std::ofstream ofs{ platform_path(), open_mode };
		ofs.write(buf.data(), buf.size());
		ofs.close();
		return !ofs.bad();
	}
}