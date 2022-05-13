#include "imgtoarr.hpp"

namespace util {
	ImageBin imgtoarr(std::FILE* img) {
		if (!img) return {};
		ImageBin b;
		while (!std::feof(img)) {
			std::uint8_t byte;
			if (std::fread(&byte, sizeof(byte), 1, img) < 1) break;
			b.push_back(byte);
		};
		return b;
	}

	std::string arrtosource(const ImageBin& b) {
		std::string out = "char img[" + std::to_string(b.size()) + "] = {";
		if (b.empty()) return (out += "\n};\n");
		
		std::size_t i;
		for (i = 0; i < b.size() - 1; i++) {
			if (i % 8 == 0) out += "\n\t";
			out += std::to_string(b.at(i)) + ",";
		}
		if (i != 0) out += std::to_string(b.at(i));
		out += "\n};\n";
		
		return out;
	}
}