// For more information on PPM (P3) format, see https://paulbourke.net/dataformats/ppm/.
#include <stdio.h>
#include <stdlib.h>

// Struct to represent an image
struct image
{
    unsigned char ***data; // 3D matrix of unsigned char representing the image (height x width x 3 for RGB)
    int width;             // Width of the image
    int height;            // Height of the image
};

// Typedef the struct image to Image
typedef struct image Image;

/**
 * Loads an image from a (RGB+P3) PPM file.
 *
 * @param filename The path to the PPM file.
 * @param image    A pointer to the Image structure where the loaded image will be stored.
 */
void load_image_ppm(const char *filename, Image *image)
{
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error opening file for reading: %s\n", filename);
        return;
    }

    // Read the PPM header
    char magic_number[3];
    if (fscanf(file, "%2s", magic_number) != 1 || magic_number[0] != 'P' || magic_number[1] != '3')
    {
        printf("Invalid PPM file: %s\n", filename);
        fclose(file);
        return;
    }

    // Read the width and height of the image
    if (fscanf(file, "%d %d", &image->width, &image->height) != 2)
    {
        printf("Invalid PPM file: %s\n", filename);
        fclose(file);
        return;
    }

    // Read the maximum pixel value (it must be 255)
    int max_value;
    if (fscanf(file, "%d", &max_value) != 1 || max_value != 255)
    {
        printf("Invalid PPM file: %s\n", filename);
        fclose(file);
        return;
    }

    // Allocate memory for the image data
    image->data = (unsigned char ***)malloc(image->height * sizeof(unsigned char **));
    for (int i = 0; i < image->height; i++)
    {
        image->data[i] = (unsigned char **)malloc(image->width * sizeof(unsigned char *));
        for (int j = 0; j < image->width; j++)
        {
            image->data[i][j] = (unsigned char *)malloc(3 * sizeof(unsigned char));
        }
    }

    // Read the image data
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            int r, g, b;
            if (fscanf(file, "%d %d %d", &r, &g, &b) != 3)
            {
                printf("Invalid PPM file: %s\n", filename);
                fclose(file);
                return;
            }
            image->data[i][j][0] = (unsigned char)r;
            image->data[i][j][1] = (unsigned char)g;
            image->data[i][j][2] = (unsigned char)b;
        }
    }

    // Close the file
    fclose(file);
}

/**
 * Writes the given image to a (RGB+P3) PPM file.
 *
 * @param filename The name of the PPM file to write.
 * @param image The image to write.
 */

void write_image_to_ppm(const char *filename, const Image *image)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    // Write the PPM header
    fprintf(file, "P3\n");                                 // P3 is the magic number for PPM P3 format
    fprintf(file, "%d %d\n", image->width, image->height); // Write the width and height of the image
    fprintf(file, "255\n");                                // Write the maximum pixel value

    // Write the image data
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            fprintf(file, "%d %d %d", image->data[i][j][0], image->data[i][j][1], image->data[i][j][2]);
            if (j < image->width - 1)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "\n");
            }
        }
    }

    // Close the file
    fclose(file);
}

int main()
{
    // Declare an image structure
    Image image;

    // Load the image from the file "input.ppm"
    load_image_ppm("input.ppm", &image);

    // Write the image to the file "output.ppm"
    write_image_to_ppm("output.ppm", &image);

    return 0;
}