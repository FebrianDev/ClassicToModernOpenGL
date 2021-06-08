#include <glew.h>
#include <stb_image.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
class Texture
{
private:
	unsigned int ID;

	void setTexture();
	void load(const char* img);
public:
	Texture() = default;
	Texture(const char* img);

	void bind();
};