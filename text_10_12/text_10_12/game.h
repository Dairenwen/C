#define _CRT_SECURE_NO_WARNINGS 1
#define HANG 9
#define LIE 9

#define HANGS HANG+2
#define LIES LIE+2

#define EASY_MODE 1

#include<stdio.h>
#include<time.h>

void playboard(char board[HANGS][LIES], int hangs, int lies, char set);

void displayboard(char board[HANG][LIE], int hang, int lie);

void designboard(char board[HANGS][LIES], int hangs, int lies);

void playerboard(char mine[HANGS][LIES], char show[HANGS][LIES], int hang, int lie);