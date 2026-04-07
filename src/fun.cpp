#include "fun.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double fun(double x){
    return (2 + cos(x))*sin(2*x) - 1;
}

double funp(double x){
    return 4*cos(2*x) + 2* cos(2 * x) * cos(x) - sin(x) * sin(2 * x);
}
double funpp(double x){
    return -8*sin(2*x)-5*sin(2*x)*cos(x) - 4 * cos(2*x) * sin(x);
}

void save_plot(const char* filename, double* y_values, int count, int width, int height){
    double y_min = y_values[0];
    double y_max = y_values[0];
    for (int i = 1; i < count; i++){
        if (y_values[i] < y_min) y_min = y_values[i];
        if (y_values[i] > y_max) y_max = y_values[i];
    }
    double range = y_max - y_min;
    if (range == 0) range = 1;

    // Создаём изображение (24-bit BMP)
    int padding = (4 - (width * 3) % 4) % 4;
    int row_size = width * 3 + padding;
    int data_size = row_size * height;
    int file_size = 54 + data_size;

    unsigned char* pixels = (unsigned char*)calloc(data_size, 1);

    // Рисуем оси (середина изображения)
    int y_axis_x = width / 10;
    int x_axis_y = height / 2;

    // Рисуем линию графика
    for (int x = 0; x < width && x < count; x++){
        int idx = (int)((double)x * (count - 1) / (width - 1));
        double normalized = (y_values[idx] - y_min) / range;
        int y = (int)((1.0 - normalized) * (height - 1));

        // Рисуем точку (с небольшой толщиной)
        for (int dy = -1; dy <= 1; dy++){
            for (int dx = -1; dx <= 1; dx++){
                int px = x + dx;
                int py = y + dy;
                if (px >= 0 && px < width && py >= 0 && py < height){
                    int row = height - 1 - py;
                    int pos = row * row_size + px * 3;
                    pixels[pos] = 255;     // B
                    pixels[pos + 1] = 255; // G
                    pixels[pos + 2] = 255;  // R
                }
            }
        }
    }
    for (int x = 0; x < width; x++){
        int row = height - 1 - x_axis_y;
        int pos = row * row_size + x * 3;
        pixels[pos] = 200;
        pixels[pos + 1] = 200;
        pixels[pos + 2] = 200;
    }
    for (int y = 0; y < height; y++){
        int row = height - 1 - y;
        int pos = row * row_size + y_axis_x * 3;
        pixels[pos] = 200;
        pixels[pos + 1] = 200;
        pixels[pos + 2] = 200;
    }

    FILE* f = fopen(filename, "wb");
    if (!f){
        printf("Error: cannot open file %s\n", filename);
        free(pixels);
        return;
    }
    unsigned char bmp_header[14] = {
        'B', 'M',                    // Signature
        0, 0, 0, 0,                  // File size
        0, 0, 0, 0,                  // Reserved
        54, 0, 0, 0                  // Data offset
    };
    *(int*)&bmp_header[2] = file_size;

    unsigned char dib_header[40] = {
        40, 0, 0, 0,                 // Header size
        0, 0, 0, 0,                  // Width
        0, 0, 0, 0,                  // Height
        1, 0,                        // Color planes
        24, 0,                       // Bits per pixel
        0, 0, 0, 0,                  // Compression (none)
        0, 0, 0, 0,                  // Image size
        0, 0, 0, 0,                  // X pixels per meter
        0, 0, 0, 0,                  // Y pixels per meter
        0, 0, 0, 0,                  // Colors used
        0, 0, 0, 0                   // Important colors
    };
    *(int*)&dib_header[4] = width;
    *(int*)&dib_header[8] = height;
    *(int*)&dib_header[20] = data_size;

    fwrite(bmp_header, 1, 14, f);
    fwrite(dib_header, 1, 40, f);
    fwrite(pixels, 1, data_size, f);
    fclose(f);
    free(pixels);

    printf("Plot saved: %s (%dx%d, %d points)\n", filename, width, height, count);
}