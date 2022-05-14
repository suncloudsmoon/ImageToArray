/*
 * Copyright (c) 2022, suncloudsmoon and the ImageToArray contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
		std::string out = "unsigned char img[" + std::to_string(b.size()) + "] = {";
		if (b.empty()) return (out += "\n};\n");
		
		std::size_t i;
		for (i = 0; i < b.size() - 1; i++) {
			if (i % 8 == 0) out += "\n\t";
			out += std::to_string(b.at(i)) + ",";
		}
		if (i != 0) out += std::to_string(b.at(i));
		
		return (out += "\n};\n");
	}
}