#define MAX_LEN 256

#ifdef _TARGET_WINDOWS
	#include <windows.h>
#endif

#include "OS_spec.hpp"

sf::String getProgPath(std::wstring path) {
	#ifdef _TARGET_WINDOWS
		wchar_t outstr[256];
		GetModuleFileNameW(NULL, outstr, MAX_LEN);
		int lastPos;
		for (int i = 0; outstr[i]; i++) {
			if (outstr[i] == L'\\') {
				lastPos = i;
			}
		}
		outstr[lastPos] = L'\0';
		return std::wstring(outstr) + std::wstring(L"/") + path;
	#else
		return std::string("");
	#endif
}
