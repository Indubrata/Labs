#include <stdio.h>
#include <stdlib.h>


int n;
typedef struct {
    char gamer_tag[30];
    int matches_played;
    int total_wins;
    float win_ratio; 
} Player;

Player* read(Player *p)
{
    scanf("%d", &n);
    p = (Player*)malloc(n * sizeof(Player));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", p[i].gamer_tag, &p[i].matches_played, &p[i].total_wins);
        p[i].win_ratio = (float)p[i].total_wins / p[i].matches_played;
    }
    return p;
}

void recS_Sort(Player *p, int i)
{
    if (i == n - 1)
        return;
    Player *max = p + i;
    int k = i;
    for (int j = i + 1;j < n;j++)
        if (p[j].win_ratio > max->win_ratio)
        {
            max = p + j;
            k = j;
        }
    if (max->win_ratio != (p + i)->win_ratio)
    {
        Player temp = *(p + k);
        *(p + k) = *(p + i);
        *(p + i) = temp;
    }
    recS_Sort(p, i + 1);
}

int len(char *a)
{
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}

int cmp(char *a, char *b)
{
    if (len(a) == len(b))
        return 0;
    else 
        for(int i = 0; i < len(a);i++)
            if (a[i] != b[i])
                return a[i] - b[i];
    return 0;
}

void recS_SortNames(Player *p, int i)
{
    if (i == n - 1)
        return;
    Player *min = p + i;
    int k = i;
    for (int j = i + 1;j < n;j++)
        if (cmp(p[j].gamer_tag, min->gamer_tag) < 0)
        {
            min = p + j;
            k = j;
        }
    if (cmp(min->gamer_tag, (p + i)->gamer_tag) != 0)
    {
        Player temp = *(p + k);
        *(p + k) = *(p + i);
        *(p + i) = temp;
    }
    recS_Sort(p, i + 1);
}

int RecbinSearch(Player *p, char *tag, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (cmp(p[mid].gamer_tag, tag) == 0)
        return mid;
    else if (cmp(p[mid].gamer_tag, tag) < 0)
        return RecbinSearch(p, tag, mid + 1, high);
    else
        return RecbinSearch(p, tag, low, mid - 1);
}

void display(Player *p)
{
    for (int i = 0; i < n; i++)
        printf("%s %d %d %f\n", p[i].gamer_tag, p[i].matches_played, p[i].total_wins, p[i].win_ratio);
}

int main()
{
    Player *p;
    p = read(p);
    recS_Sort(p, 0);
    display(p);
    char tag[30];
    scanf("%s", tag);
    recS_SortNames(p, 0);
    int index = RecbinSearch(p, tag, 0, n - 1);
    if (index != -1)
        printf("%d %s %d %d %f\n", index, p[index].gamer_tag, p[index].matches_played, p[index].total_wins, p[index].win_ratio);
    else
        printf("Player not found\n");
    return 0;
}