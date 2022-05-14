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

#include <cstdio>
#include <iostream>

#include "imgtoarr.hpp"

int main() {
	std::FILE* img = std::fopen("eye.png", "rb");
	if (!img) return -1;

	std::FILE* out = std::fopen("arr.txt", "w");
	if (!out) { std::fclose(img); return -1; }
	
	const auto arr = util::imgtoarr(img);
	const auto str = util::arrtosource(arr);

	std::fprintf(out, str.c_str());

	std::fclose(img);
	std::fclose(out);
}