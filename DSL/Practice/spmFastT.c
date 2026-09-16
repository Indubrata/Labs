#include <stdio.h>
typedef struct spm{
    int r,c,v;

} spm;
spm a[10];
void display(spm a[]){
    for(int i=0;i<=a[0].v;i++){
        printf("%d %d %d\n",a[i].r,a[i].c,a[i].v);
    }
    printf("\n");
    return;
}
spm T[10];
int total[10];
int ind[10];
void transpose(){
    T[0].r=a[0].c;
    T[0].c=a[0].r;
    T[0].v=a[0].v;
    for(int i=0;i<a[0].c;i++){
        total[i]=0;
    }
    for(int i=1;i<=a[0].v;i++){
        total[a[i].c]++;
    }
    ind[0]=1;
    for(int i=1;i<a[0].c;i++){
        ind[i]=ind[i-1]+total[i-1];
    }
    for(int i=1;i<=a[0].v;i++){
        int k= ind[a[i].c]++;
        T[k].r=a[i].c;
        T[k].c=a[i].r;
        T[k].v=a[i].v;
    }
    return;
}
int main(){
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &a[0].r, &a[0].c);
    int k=1;
    printf("Enter elements: ");
    for(int i=0;i<a[0].r;i++){
        for(int j=0;j<a[0].c;j++){
        int ele;
        scanf("%d",&ele);
        if (ele !=0){
            a[k].r= i;
            a[k].c=j;
            a[k].v=ele;
            k++;
        }
        }
    }
    a[0].v=k-1;
    display(a);
    transpose();
    display(T);
    return 0;
}