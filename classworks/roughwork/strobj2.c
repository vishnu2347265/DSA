#include <stdio.h>
struct Point {
int x;
int y;
};
int main() {
struct Point pointArray[2][2] = {
{{1, 2}, {3, 4}},
{{5, 6}, {7, 8}}
};
for (int i = 0; i < 2; i++) {
for (int j = 0; j < 2; j++) {
printf("(%d, %d) ", pointArray[i][j].x, pointArray[i][j].y);
}
printf("\n");
}
return 0;
}
