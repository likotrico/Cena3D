#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "screenshot.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int n_prt = 0;

void printScreen(const char *filename)
{
    /** @brief Alocação dos pixeis da captura de tela */
    unsigned char *pixels = (unsigned char *)malloc(3 * 640 * 640);

    // Lê o frame buffer
    glReadPixels(0, 0, 640, 640, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Inverte na vertical
    for (int y = 0; y < 640 / 2; y++)
        for (int x = 0; x < 640 * 3; x++)
        {
            int i = y * 640 * 3 + x;
            int j = (640 - y - 1) * 640 * 3 + x;

            unsigned char temp = pixels[i];
            pixels[i] = pixels[j];
            pixels[j] = temp;
        }

    char f[50];
    sprintf(f, "%s-%d.png", filename, n_prt);
    n_prt++;

    // Escreve no arquivo usando a biblioteca stb do usuário nothings no GitHub
    stbi_write_png(f, 640, 640, 3, pixels, 640 * 3);

    free(pixels);
}
