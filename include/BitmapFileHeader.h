#ifndef __BITMAPFILEHEADER_H__
#define __BITMAPFILEHEADER_H__

#include <cstdint>

; // Semicolon removes pragma error
#pragma pack(push, 2)

struct BitmapFileHeader
{
	char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

#pragma pack(pop)

#endif // __BITMAPFILEHEADER_H__
