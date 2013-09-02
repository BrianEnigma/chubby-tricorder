#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <gd.h>

#define DISPLAY_WIDTH  128
#define DISPLAY_HEIGHT 56

void createPrefix(const char *in, std::string *out)
{
    const char *tmp;
    if (!in || !out)
        return;
    out->clear();
    tmp = strrchr(in, '/');
    if (tmp)
        in = tmp + 1;
    for (; *in; in++)
    {
        if (isalnum(*in))
            out->push_back(toupper(*in));
        else if ('-' == *in)
            out->push_back('_');
        else if ('.' == *in)
            return;
    }
}

int process(const char *filename)
{
    unsigned char currentByte = 0;
    unsigned char bitCount = 0;
    unsigned int characterCount = 0;
    std::string prefix;
    gdImagePtr image;
    FILE *f = fopen(filename, "rb");
    if (!f)
        return 1;
    image = gdImageCreateFromPng(f);
    fclose(f);
    if (!image)
        return 1;
    createPrefix(filename, &prefix);
    printf("#define %s_WIDTH  %d\n", prefix.c_str(), gdImageSX(image));
    printf("#define %s_HEIGHT %d\n", prefix.c_str(), gdImageSY(image));
    printf("#define %s_X  %d\n", prefix.c_str(), DISPLAY_WIDTH / 2 - gdImageSX(image) / 2);
    printf("#define %s_Y %d\n", prefix.c_str(), DISPLAY_HEIGHT / 2 - gdImageSY(image) / 2);
    printf("static unsigned char PROGMEM %s[] = {\n", prefix.c_str());
    for (int y = 0; y < gdImageSY(image); y++)
    {
        for (int x = 0; x < gdImageSX(image); x++)
        {
            if (8 == bitCount)
            {
                if (characterCount > 0)
                    printf(",");
                printf("0x%02X", currentByte);
                characterCount++;
                if (characterCount % 16 == 0)
                    printf("\n");
                currentByte = 0;
                bitCount = 0;
            }
            // We're assuming it's black and white (or at least grayscale), 
            // so R/G/B should all be the same. Use the red to determine
            // proximity to white or black.
            unsigned int color = gdImageRed(image, gdImageGetPixel(image, x, y));
            currentByte <<= 1;
            bitCount++;
            if (color < 128)
                currentByte |= 0x01;
        }
        currentByte <<= (8 - bitCount);
        printf(",0x%02X", currentByte);
        currentByte = 0;
        bitCount = 0;
        characterCount++;
        if (characterCount % 16 == 0)
            printf("\n");
    }
    printf("};\n");
    return 0;
}

int main(int argc, char **argv)
{
    int rc;
    if (argc != 2)
    {
        printf("Put PNG image file to process on the command line\n");
        return 1;
    }
    rc = process(argv[1]);
    if (0 != rc)
        printf("ERROR\n");
    return rc;
}