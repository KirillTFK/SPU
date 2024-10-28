#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


#include "assembler.h"
#include "constructor.h"
#include "quadratka.h"
#include "interpritator.h"

int main (void)
{
    FILE* executable_file = NULL;
    struct text_param commands = {};

    check_open (&executable_file, "instructions","r");

    int code[MAX_CODE_SIZE] = {};

    allocate_memory_for_text (&commands, "instructions");

    read_from_file (executable_file, &commands);

    div_in_words (&commands);


    for (int i = 0 ; i < commands.am_of_lines; i++)
    {
        printf ("%s\n", commands.lines[i].beginning);
    }

    unsigned command_counter = 1;
    Read_Command (&commands, code, &command_counter);

    FILE* machine_code = NULL;
    check_open (&machine_code, "machine_code", "w");

    Print_Headline (machine_code, commands.am_of_lines, --command_counter);

    Print_Code (code, commands.am_of_lines, machine_code);

    fclose (machine_code);
    clear_memory_for_text (&commands);
}


void Read_Command (struct text_param *commands, int *code, unsigned *command_counter)
{

    for (int i = 0; i < commands->am_of_lines;)
    {

        if (strcmp(commands->lines[i].beginning, "In") == 0)
        {
            code[i++] = IN;
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Add") == 0)
        {
            code[i++] = ADD;
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Push") == 0)
        {
            code[i++] = PUSH;

            code[i++] = atoi (commands->lines[i].beginning);
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Mul") == 0)
        {
            code[i++] = MUL;
            (*command_counter)++;
        }


        else if (strcmp(commands->lines[i].beginning, "Sub") == 0)
        {
            code[i++] = SUB;
            (*command_counter)++;
        }


        else if (strcmp(commands->lines[i].beginning, "Div") == 0)
        {
            code[i++] = DIV;
            (*command_counter)++;
        }


        else if (strcmp(commands->lines[i].beginning, "Out") == 0)
        {
            code[i++] = OUT;
            (*command_counter)++;
        }


        else if (strcmp(commands->lines[i].beginning, "Sqrt") == 0)
        {
            code[(i)++] = SQRT;
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Sin") == 0)
        {
            code[i++] = SIN;
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Cos") == 0)
        {
            code[i++] = COS;
            (*command_counter)++;
        }

        else if (strcmp(commands->lines[i].beginning, "Hlf") == 0)
        {
            code[i++] = HLF;
            (*command_counter)++;
        }

        else
        {
            printf ("Синтаксическая ошибка! не смог распознать комнаду номер:%u\n", *command_counter);
            exit (EXIT_FAILURE);
        }
    }
}


void Print_Headline (FILE* const machine_code, unsigned code_size, unsigned command_counter)
{
    fprintf (machine_code, "sign:%s cmd:%u cmd_with_arg:%u\nversion:%u\n",SIGNATURE, command_counter,
    code_size-command_counter, VERSION);
}

void Print_Code (int *code, unsigned code_size, FILE* machine_code)
{
    for (int i = 0; i < code_size; i++)
    {
        fprintf (machine_code,"%d", code[i]);
    }
}

