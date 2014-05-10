#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    int M,N;
    scanf("%d%d", &M, &N);
    map<int, int> count_map;
    int max_count = -1;
    int dominant_color = -1;
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < M; j ++)
        {
            int color;
            scanf("%d", &color);
            int count = count_map[color] += 1;
            if (count > max_count)
            {
                max_count = count;
                dominant_color = color;
            }
        }
    }
    printf("%d\n", dominant_color);
    return 0;
}
