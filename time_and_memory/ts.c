#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "include/u_template.h"

int double_area(struct triangle_t tr);
struct triangle_t scanf_triangle();

int main()
{
  int res;
  struct triangle_t tri = scanf_triangle();
  res = double_area(tri);
  printf("%d", res);
  return 0;
}

struct triangle_t scanf_triangle()
{
  int i, res;
  struct triangle_t tri = {0};
  for (i = 0; i < 3; i++)
  {
    res = scanf("%d%d", &tri.pts[i].x, &tri.pts[i].y);
    if (res != 2)
    {
      printf("%s\n", "Wrong input");
      abort();
    }
  }
  return tri;
}

int double_area(struct triangle_t tr)
{
  int ans = tr.pts[0].x * (tr.pts[1].y - tr.pts[2].y) - tr.pts[0].y * (tr.pts[1].x - tr.pts[2].x) + tr.pts[1].x * tr.pts[2].y - tr.pts[1].y * tr.pts[2].x;
  return ans > 0 ? ans : -1 * ans;
}