#include <cstdio>
#include <iostream>

#include "imgtoarr.hpp"

int main() {
	std::FILE* img = std::fopen("eye.png", "rb");
	if (!img) return -1;

	std::FILE* out = stdout;
	if (!out) { std::fclose(img); return -1; }
	
	const auto arr = util::imgtoarr(img);
	const auto str = util::arrtosource(arr);

	std::fprintf(out, str.c_str());

	std::fclose(img);
	std::fclose(out);
}