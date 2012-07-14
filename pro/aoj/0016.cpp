#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

#define PI M_PI
#define RAD (M_PI/180.0)

double g_x = 0.0;
double g_y = 0.0;
double g_direction = 0.0; // north

int main(int argc, char *argv[])
{
  int distance, angle;
  while (1) {
    scanf("%d,%d",&distance,&angle);
    // Stop Condition
    if (distance==0 && angle==0) break;
    
    g_x += (double)distance * sin(g_direction * RAD);
    g_y += (double)distance * cos(g_direction * RAD);
    g_direction += angle;
  }

  std::cout <<(int)g_x << std::endl;
  std::cout << (int)g_y << std::endl;
  return 0;
}
