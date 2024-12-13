#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>
#include <locale.h>
#include <string.h>

char32_t* init_world(short width, short height)
{
  char32_t* data = (char32_t*)malloc(width*height*sizeof(char32_t));
  if (data == NULL) {
    printf("allocation fail");
    return;
  }

  for (short i=0; i<height; i++)
  {
    for (short j=0; j<width; j++)
    {
      data[i*width + j] = U'░';
    }
  }
  return data;
}

void destroy_world(char32_t* data)
{
  if (data == NULL) {
    return;
  }
  free(data);
  data = NULL;
}

void draw_world(char32_t* data, int width, int height)
{
  for (short i=0; i<height; i++)
  {
    for (short j=0; j<width; j++)
    {
      printf("%lc", data[i*width + j]);
    }
    printf("\n");
  }
}

char32_t* generate_tree()
{
  short bmp_width = 10;
  short bmp_height = 10;

  char32_t* buffer = malloc(bmp_width*bmp_height*sizeof(char32_t));
  if (buffer == NULL) {
    printf("allocation fail");
    return NULL;
  } 

  for (short i=0; i<bmp_height; i++)
  {
    for (short j=0; j<bmp_width; j++)
    {
      buffer[i*bmp_width + j] = U'*';
    }
  }
  return buffer;
}

void destroy_tree(char32_t* data)
{
  if (data == NULL) {
    return;
  }
  free(data);
  data = NULL;
}

void ascii_bmp_cpy(char32_t* dst, char32_t* src, int dst_x, int dst_y, int src_width, int src_height, int dst_width)
{
  for (short i = 0; i < src_height; i++)
  {
    memcpy(&dst[(i + dst_y) * dst_width + dst_x], &src[i * src_width], src_width * sizeof(char32_t));
  }
}

int main() {
    printf("Program version: %s\n", VERSION);
    setlocale(LC_ALL, "");
    short world_width = 80;
    short world_height = 20;

    char32_t* world = init_world(world_width, world_height);

    char32_t* tree = generate_tree();
    ascii_bmp_cpy(world, tree, 10, 10, 10, 10, world_width);
    destroy_tree(tree);

    int tree_x = 4;
    int tree_thickness = 2;
    int tree_trunk_height = 3;
    int tree_crown_height = 3;
    int tree_crown_width = 6;

    draw_world(world, world_width, world_height);
    destroy_world(world);
    return 0;
}
