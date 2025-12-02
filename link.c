#include <stdio.h>

struct food
{
    int no;
    char name[50];
    int price_full;
    int price_half;
};
struct choice
{
    int id;
    int amount;
    char quant[50];
};
struct bill
{
    char name[50];
    int phone_no;
};
struct food starters[6] =
{
    {1, "honey chilly potato", 150, 0},
    {2, "french fries", 100, 0},
    {3, "paneer tikka", 160, 0},
    {4, "mushroom kabana", 160, 0},
    {5, "chicken tikka", 280, 0},
    {6, "garlic butter prawns", 280, 0}
};
struct food maincourse[20] =
{
    {1, "Tandoori Naan", 30, 0},
    {2, "butter Naan", 40, 0},
    {3, "garlic Naan", 40, 0},
    {4, "garlic butter Naan", 50, 0},
    {5, "rumali roti", 30, 0},
    {6, "stuffed naan", 50, 0},
    {7, "Tandoori roti", 25, 0},
    {8, "kadai paneer", 250, 125},
    {9, "butter paneer masala", 300, 150},
    {10, "paneer lababdar", 250, 125},
    {11, "mix veg", 200, 100},
    {12, "daal makhni", 200, 100},
    {13, "butter chicken", 350, 200},
    {14, "mutton korma", 500, 300},
    {15, "prawn coconut curry", 350, 200},
    {16, "egg curry", 250, 125},
    {17, "Veg thaali", 200, 0},
    {18, "veg thaali premium", 300, 0},
    {19, "non veg thali", 300, 0},
    {20, "non veg thali premium", 375, 0}
};
struct food drinks[6] =
{
    {1, "coca cola", 50, 0},
    {2, "red bull", 120, 0},
    {3, "pina colada", 150, 0},
    {4, "oreo shake", 150, 0},
    {5, "biscoff shake", 150, 0},
    {6, "bloody marry", 120, 0}
};
struct food continental[8] =
{
    {1, "margareta pizza", 250, 150},
    {2, "white sauce pasta", 175, 0},
    {3, "red sauce pasta", 175, 0},
    {4, "spaghetti red sauce", 200, 0},
    {5, "fried chicken", 200, 0},
    {6, "garlic bread", 150, 0},
    {7, "vegetable pizza", 300, 200},
    {8, "chicken salami pizza", 300, 200}
};
struct food asian[6] =
{
    {1, "veg hakka noodles", 150, 75},
    {2, "chicken hakka noodles", 180, 90},
    {3, "spring rolls", 70, 35},
    {4, "veg momos", 60, 30},
    {5, "chicken momos", 80, 40},
    {6, "munchow soup", 50, 0}
};
struct food sweetdish[6] =
{
    {1, "Gulab Jamun", 40, 0},
    {2, "Rasgulla", 40, 0},
    {3, "brownie with icecream", 120, 0},
    {4, "cheese cake", 120, 0},
    {5, "chocolate ice cream", 60, 0},
    {6, "gajar halwa", 80, 0}
};
