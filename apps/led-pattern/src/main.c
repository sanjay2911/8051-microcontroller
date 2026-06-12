#include "led_pattern.h"

void delay_ms(unsigned int ms);
void pattern_left_shift(void);
void pattern_right_shift(void);
void pattern_knight_rider(void);
void pattern_converge(void);
void pattern_diverge(void);
void pattern_alternate(void);
void pattern_binary_counter(void);
void pattern_fill_up(void);
void pattern_empty_down(void);
void pattern_blink_all(void);

void main(void)
{
    while (1)
    {
        pattern_left_shift();
        pattern_right_shift();
        pattern_knight_rider();
        pattern_converge();
        pattern_diverge();
        pattern_alternate();
        pattern_binary_counter();
        pattern_fill_up();
        pattern_empty_down();
        pattern_blink_all();
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++);
    }
}

void pattern_left_shift(void)
{
    unsigned char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 8; i++)
        {
            P0 = (1U << i);
            delay_ms(100U);
        }
    }
}

void pattern_right_shift(void)
{
    signed char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 7; i >= 0; i--)
        {
            P0 = (1U << i);
            delay_ms(100U);
        }
    }
}

void pattern_knight_rider(void)
{
    signed char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 8; i++)
        {
            P0 = (1U << i);
            delay_ms(80U);
        }

        for (i = 6; i > 0; i--)
        {
            P0 = (1U << i);
            delay_ms(80U);
        }
    }
}

void pattern_converge(void)
{
    unsigned char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 4; i++)
        {
            P0 = (0x80U >> i) | (0x01U << i);
            delay_ms(120U);
        }
    }
}

void pattern_diverge(void)
{
    signed char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 3; i >= 0; i--)
        {
            P0 = (0x80U >> i) | (0x01U << i);
            delay_ms(120U);
        }
    }
}

void pattern_alternate(void)
{
    unsigned char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 6; i++)
        {
            P0 = 0xAAU;
            delay_ms(150U);

            P0 = 0x55U;
            delay_ms(150U);
        }
    }
}

void pattern_binary_counter(void)
{
    unsigned int value;
    int iterations = 3;

    while (iterations--)
    {
        for (value = 0; value < 256U; value++)
        {
            P0 = (unsigned char)value;
            delay_ms(20U);
        }
    }
}

void pattern_fill_up(void)
{
    unsigned char value = 0U;
    unsigned char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 8; i++)
        {
            value |= (1U << i);
            P0 = value;
            delay_ms(120U);
        }
    }
}

void pattern_empty_down(void)
{
    unsigned char value = 0xFFU;
    signed char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 7; i >= 0; i--)
        {
            value &= ~(1U << i);
            P0 = value;
            delay_ms(120U);
        }
    }
}

void pattern_blink_all(void)
{
    unsigned char i;
    int iterations = 3;

    while (iterations--)
    {
        for (i = 0; i < 5; i++)
        {
            P0 = 0xFFU;
            delay_ms(150U);

            P0 = 0x00U;
            delay_ms(150U);
        }
    }
}