#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int alert_id;
    char medication_name[50];
    float recorded_temp;
} SensorAlert;

typedef struct {
    SensorAlert *alerts;
    int top;
    int capacity;
} AlertStack;

void init(AlertStack *st)
{
    st->top = -1;
    st->capacity = 10;
    st->alerts = (SensorAlert*)malloc(st->capacity * sizeof(SensorAlert));
}

void pushAlert(AlertStack *st, SensorAlert alert)
{
    if (st->top == st->capacity - 1){
        printf("Stack is full");
        return;
    }
    st->alerts[++st->top] = alert;
}

SensorAlert popAlert(AlertStack *st)
{
    if (st->top == -1){
        printf("Stack is empty");
        return (SensorAlert){-1, "", 0.0f};
    }
    return st->alerts[st->top--];
}

void displayAlerts(AlertStack *st)
{
    if (st->top == -1){
        printf("Stack is empty");
        return;
    }
    for (int i = st->top; i >= 0; i--){
        printf("%d %s %f\n", st->alerts[i].alert_id, st->alerts[i].medication_name, st->alerts[i].recorded_temp);
    }
}

void recCritical(AlertStack *st)
{
    if (st->top == -1)
        return;
    else {
        SensorAlert alert = popAlert(st);
        recCritical(st);
        if (alert.recorded_temp > 8.0 || alert.recorded_temp < 2.0)
            pushAlert(st, alert);
    }
}

int main()
{
    
}