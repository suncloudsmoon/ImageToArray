#ifndef IMGTOARR_HPP
#define IMGTOARR_HPP

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>

namespace util {
	using ImageBin = std::vector<std::uint8_t>;
	
	ImageBin imgtoarr(std::FILE* img);
	std::string arrtosource(const ImageBin& b);
}

#endif /* IMGTOARR_HPP */