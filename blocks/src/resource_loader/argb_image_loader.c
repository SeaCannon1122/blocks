#include "headers.h"
#include "external/stb_image.h"

void load_png(const char* file_name, struct argb_image* image) {
    int width, height, channels;
    unsigned char* img = stbi_load(file_name, &width, &height, &channels, 4);
    if (!img) {
        printf("Failed to load image %s\n", file_name);
        //exit(1);
        return;
    }

    image->width = width;
    image->height = height;
    image->data = (union pixel*)malloc(width * height * sizeof(union pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char* px = &img[(y * width + x) * 4];
            image->data[y * width + x].color.r = px[0];
            image->data[y * width + x].color.g = px[1];
            image->data[y * width + x].color.b = px[2];
            image->data[y * width + x].color.a = px[3];
        }
    }

    stbi_image_free(img);
}