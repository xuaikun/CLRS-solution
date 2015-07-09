/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.1-5
 * 名称:  Double-ended queue
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 双端队列
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int head;
    int tail;
} deque_t;

void init_deque(deque_t *deque)
{
    deque->head=-1;
    deque->tail=0;
}

int is_empty(deque_t *deque)
{
    return (deque->head==-1);
}

void push(deque_t *deque, int n)
{
    if (deque->head == deque->tail) {
        fprintf(stderr, "Deque overflow\n");
        exit(1);
    }
    
    deque->items[deque->tail]=n;
    
    if (deque->head == -1) {
        deque->head = deque->tail;
    }
    
    deque->tail = (deque->tail+1)%MAX_SIZE;
}

void unshift(deque_t *deque, int n)
{
    if (deque->head == deque->tail) {
        fprintf(stderr, "Deque overflow\n");
        exit(1);
    }
    
    if (deque->head == -1) {
        deque->head = deque->tail;
    }
    
    deque->head = (deque->head-1+MAX_SIZE)%MAX_SIZE;
    deque->items[deque->head]=n;
}

int pop(deque_t *deque)
{
    if (deque->head == -1) {
        fprintf(stderr, "Deque underflow\n");
        exit(1);
    }
    
    deque->tail = (deque->tail+MAX_SIZE-1)%MAX_SIZE;
    
    if (deque->tail == deque->head) {
        deque->head = -1;
    }
    
    return deque->items[deque->tail];
}

int shift(deque_t *deque)
{
    if (deque->head == -1) {
        fprintf(stderr, "Deque underflow\n");
        exit(1);
    }
    
    int result = deque->items[deque->head];
    
    deque->head = (deque->head+1)%MAX_SIZE;
    
    if (deque->head == deque->tail) {
        deque->head = -1;
    }
    
    return result;
}
