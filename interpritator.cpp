#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"
#include "constructor.h"
#include "destructor.h"
#include "stack_verify.h"
#include "stack_push_and_pop.h"
#include "interpritator.h"


const int command_size = 30;
FILE* f_out = stdout;



int main ()
{
    FILE* f_in;
    check_open(&f_in, "instructions", "r");

    struct Stack_t *stk = get_stack_pointer ();

    STACK_CONSTRUCTOR (stk, 15, f_out);

    Run (stk, f_in);

    fclose (f_in); // Деструктор будет.
}


void Add ( struct Stack_t *stk)
{
    double first = 0;
    double second = 0;

    first = stack_pop (stk);
    second = stack_pop (stk);

    stack_push (stk, first+second);
}


void In (struct Stack_t *stk)
{
    stack_elem_t elem = 0;

    printf ("Ожидаю ввод числа!\n");
    if(scanf ("%lf", &elem) == 0)
    {
        fprintf (f_out, "Не смог найти число, которое нужно положить в стек");
        return;
    }

    stack_push (stk, elem);
}

void Push (struct Stack_t *stk, FILE* f_in)
{
    stack_elem_t elem = 0;

    if(fscanf (f_in, "%lf", &elem) == 0)
    {
        fprintf (f_out, "Не смог найти число, которое нужно положить в стек");
        return;
    }

    stack_push (stk, elem);
}

void Mul (struct Stack_t *stk)
{
    stack_elem_t first = 0;
    stack_elem_t second = 0;

    first = stack_pop (stk);
    second = stack_pop (stk);

    stack_push (stk, first*second);
}

void Sub (struct Stack_t *stk)
{
    stack_elem_t minuend = 0;
    stack_elem_t subtrahend = 0;

    subtrahend = stack_pop (stk);
    minuend = stack_pop (stk);

    stack_push (stk, minuend - subtrahend);

}

void Div (struct Stack_t *stk)
{
    stack_elem_t dividend = 0;
    stack_elem_t divider = 0;

    divider = stack_pop (stk);
    dividend = stack_pop (stk);

    if (fabs(divider-0) < DEVIATION )
    {
        fprintf (f_out, "Нельзя делить на 0\n");
        return;
    }

    stack_push (stk, dividend/divider);

}

void Out (struct Stack_t *stk)
{
    #ifdef DOUBLE_STACK

    fprintf (f_out,"Последний элемент добавленный в стек:%lf\n", stack_pop (stk));

    #endif

    #ifdef INT_STACK

    fprintf (f_out,"Последний элемент добавленный в стек:%d\n", stack_pop (stk));

    #endif
}

void   Sqrt (struct Stack_t *stk)
{
    #ifndef DOUBLE_STACK

    printf ("Эта функция не работает с int'овым стеком\n");
    return;

    #endif

    stack_elem_t square = stack_pop (stk);

    stack_push (stk, sqrt(square));
}

void Sin (struct Stack_t *stk)
{
    #ifndef DOUBLE_STACK

    printf ("Эта функция не работает с int'овым стеком\n");
    return;

    #endif

    stack_elem_t angel = stack_pop (stk);

    stack_push (stk, sin(angel));

}

void Cos (struct Stack_t *stk)
{
    #ifndef DOUBLE_STACK

    printf ("Эта функция не работает с int'овым стеком\n");
    return;

    #endif

    stack_elem_t angel = stack_pop (stk);

    stack_push (stk, cos(angel));

}

void Hlf (struct Stack_t *stk)
{
    printf ("Завершаю программу. Удаляю стек\n");
    stack_dtor (stk);
}


void Run (struct Stack_t *stk, FILE* f_in)
{
    char current_command [command_size] = {};

    unsigned command_counter = 1;
    while (strcmp(current_command, "half") != 0)
    {
        fscanf (f_in, "%s", current_command);

        if (strcmp(current_command, "In") == 0)
        {
            In (stk);
            command_counter++;
        }

        else if (strcmp(current_command, "Add") == 0)
        {
            Add (stk);
            command_counter++;
        }

        else if (strcmp(current_command, "Push") == 0)
        {
            Push (stk, f_in);
            command_counter++;
        }

        else if (strcmp(current_command, "Mul") == 0)
        {
            Mul (stk);
            command_counter++;
        }


        else if (strcmp(current_command, "Sub") == 0)
        {
            Sub (stk);
            command_counter++;
        }


        else if (strcmp(current_command, "Div") == 0)
        {
            Div (stk);
            command_counter++;
        }


        else if (strcmp(current_command, "Out") == 0)
        {
            Out (stk);
            command_counter++;
        }


        else if (strcmp(current_command, "Sqrt") == 0)
        {
            Sqrt (stk);
            command_counter++;
        }

        else if (strcmp(current_command, "Sin") == 0)
        {
            Sin (stk);
            command_counter++;
        }

        else if (strcmp(current_command, "Cos") == 0)
        {
            Cos (stk);
            command_counter++;
        }

        else if (strcmp(current_command, "Hlf") == 0)
        {
            Hlf (stk);
            command_counter++;
            return;
        }

        else
        {
            printf ("Синтаксическая ошибка! не смог распознать комнаду номер:%u\n", command_counter);
            exit (EXIT_FAILURE);
        }
    }
}

