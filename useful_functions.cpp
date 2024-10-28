#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

#include "quadratka.h"
/*
void choose_the_biggest (unsigned* a, unsigned* b, unsigned* c)
{
    unsigned swap = 0;

    if (*c > *a)
    {
        swap = *a;
        *a = *c;
        *c = swap;
    }

    if (*b > *a)
    {
        swap = *a;
        *a = *b;
        *b = swap;
    }

    if (*c > *b)
    {
        swap = *b;
        *b = *c;
        *c = swap;
    }
}
*/
/*
void factirize (unsigned* num)
{
    double check_lim = 0;
    unsigned i = 0, j = 0;
    unsigned multf[], mults[SIZE];


    check_lim = sqrt((double)*num);

    for (int del = 1;del <= check_lim; del++)
    {
        if (*num % del == 0 && del != check_lim)
        {
            multf[i++] = del;
            mults[j++] = *num/del;
        }

        if (del == check_lim)
        multf[i++] = del;
        else
            continue;
    }

    sort (mults, j);

}
*/


int div_in_lines (struct text_param *Onegin) // Тут я надеюсь на ненулевую массив
{
    (Onegin->lines)[0].beginning = Onegin->original;//Говорю что нет пустых строк
    int lines_count = 1;
    for (int i = 0; i < Onegin->text_size; i++)
    {

        if (Onegin->original[i] == '\r')
        {
            Onegin->original[i] = '\0';
            continue;
        }


        if (Onegin->original[i] == '\n')
        {
            (Onegin->lines)[lines_count].beginning = (Onegin->original + (++i));
            lines_count++;
        }
    }
    return (lines_count-2);
}

void check_num_of_arguments (int argc)
{
    if (argc < 3)
        {
            printf ("Не обнаружины названия файлов ввода и вывода\n");
            exit (EXIT_FAILURE);
        }
}

int read_from_file (FILE *source, char text_on_pc[][COLUMNS])
{
    char buf[COLUMNS] = {};
    int i = 0;
    int ch = 0;
    int flag;
    for (; (ch = getc(source))!= EOF; i++)
    {
            ungetc (ch, source);
            fgets (buf, COLUMNS, source);
            flag = clear_text_from_cringe (buf);

            if (flag == 0)
            {
                continue;
            }
            copy (text_on_pc[i], buf, COLUMNS);
            nullify (buf);
            //fputs (text_on_pc[i], stdout);
    }
    //while (text_on_pc[i-1] )
    copy (text_on_pc[i], "END_OF_TEXT", COLUMNS);
    return (i - 1);
}

void nullify (char *dump)
{
    for (int i = 0; i < VER_WIDTH; i++ )
    {
        dump[i] = '\0';
    }
}

void    copy (char* pathetic_parody,
                  const char* unique_original, int Max_char_to_copy)
{
    int count = 0;
    int i = 0;
    int sh = 0;
    int ch = 0;
    int flag = 1;
    //TODO: make sizeof(type)
    for (; unique_original[count*8 + i*4 + sh*2 + ch]
             != '\0' && count*sizeof(long) + i*4 + sh*2+ ch < Max_char_to_copy  && flag != 0; )
    {
        flag = 0;
        if ((count+1)*sizeof(long) < Max_char_to_copy )
        {
            *(((long*)pathetic_parody) + count) = *(((long*)unique_original) + count);
            //printf ("Итерация номер %d\n", count);
            count++;
            flag = 1;
        }

        else
        {   if ((count)*sizeof(long) + 2*sh + ch + 4*i + sizeof(int) < Max_char_to_copy )
            {
                *(((int*)pathetic_parody) + (2*count )) = *(((int*)unique_original) + (2*count));
                //printf ("Зашел в инты\n");
                i++;
                flag = 1;
            }
            if (count*sizeof(long) + 4*i + sizeof(short) + 2*sh + ch < Max_char_to_copy)
            {
                *(((short*)pathetic_parody) + 4*count + 2*i) = *(((short*)unique_original) + 4*count + 2*i);
                //printf ("Зашел в шорты\n");
                sh++;
                flag = 1;
            }
            //printf("Иду дальше\n");
            if ((count)*sizeof(long) + 4*i + 2*sh + sizeof(char) < Max_char_to_copy )
            {
                *(((char*)pathetic_parody) + 8*count + 4*i + 2*sh) = *(((char*)unique_original) + 8*count + 4*i + 2*sh);
                //printf ("Зашел в чары\n");
                ch++;
                flag = 1;
            }

        }



    }
    pathetic_parody[Max_char_to_copy-1] = '\0';

    //printf ("%d\n", count);

    remove_excess (pathetic_parody, (count) *sizeof(long)+i*4+sh*2+ch);


    printf ("Жалкая пародия:        ");
    for (int i = 0; i < COLUMNS; i++)
    {
        printf ("%c", pathetic_parody[i]);
    }
    putchar ('\n');
    printf ("Неповторимый оригинал: ");
    for (int i = 0; i < COLUMNS; i++)
    {
        printf ("%c", unique_original[i]);
    }
    putchar ('\n');



}

void remove_excess(char *arr, int size)
{
    for (int i = size; i < COLUMNS; i++)
    {
        arr[i] = '\0';
    }
}

void read_in_array (char *arr, struct text_param *Onegin)
{
    for (int j = 0, i = 0; j <= Onegin->am_of_lines && i < Onegin->text_size; i++)
    {
        int count = 0;
        for (; Onegin->lines[j].beginning[count] != '\n'; count++, i++ )
        {
            arr[i] = Onegin->lines[j].beginning[count];
        }
        printf ("Сейчас в рид аррэй такая интеарция: %d и такая строка: %p  %d\n", j, Onegin->lines[j].beginning, i);
        arr[i] = Onegin->lines[j].beginning[count];
        j++;
    }
}

void selection_sort (char *beginning_of_lines[], int size)
{
    char *swap_buffer = NULL; //TODO swap_buffer(Сделал)

    for (; size > 0; size--)
    {
        char *the_biggest_str = NULL;//todo
        the_biggest_str = beginning_of_lines[0];
        for (int i = 0; i < size; i++)
        {

            if (stupid_compare (beginning_of_lines[i], the_biggest_str) > 0)
            {
                //printf ("Зашел в if\n");
                swap_buffer = beginning_of_lines[i];
                beginning_of_lines[i] = the_biggest_str;
                the_biggest_str = swap_buffer;
            }
            //printf ("challanger: %s, intermedia: %s, Onegin[%d]:%s\n", challanger,
                   //  intermediary, i, Onegin[i]);
        }
        if (stupid_compare (beginning_of_lines[size], the_biggest_str) > 0)
        {
            beginning_of_lines[0] = the_biggest_str;
            swap_buffer = NULL;
        }

        else
        {
            beginning_of_lines[0] = beginning_of_lines[size];
            beginning_of_lines[size] = the_biggest_str;
        }
    }


}



int clear_text_from_cringe(const char *text)
{
/*
    char reference[2] = {' ', ' '};
    if (*((short*)text) == *((short*)reference))
    {
        return (0);
    }
*/
    for (int i = 0; i < VER_WIDTH; i++)
    {

        if (isalpha(text[i]))
        {
            return (1);
        }

        if (text[i] == '\n' || text[i] == '\f')
        {
            return (0);
        }
    }
    return (0);
}




int stupid_compare (const void* first_str, const void* second_str) //
{
    int i = 0;
    int j = 0;
    for (; *((const char*)first_str + i) != '\n' && *((const char*)second_str + j) != '\n';)
    {
        if (!(isalpha( *((const char*)first_str + i)))) //очев
        {
            i++;
            continue;
        }

        if (!(isalpha( *((const char*)second_str + j))))
        {
            j++;
            continue;
        }

        if (tolower(*((const char*)first_str + i)) !=  tolower(*((const char*)second_str + j))) //очев
        {
            //printf ("Значение int i в stupid_compare: %d\n", i);
            return (tolower(*((const char*)first_str + i))- '\n') - (tolower(*((const char*)second_str + j)) - '\n'); // и тут очев
        }
        i++;
        j++;
    }
    if (*((const char*)first_str + i) == '\n')
    {
        if (*((const char*)second_str + j) == '\n')
        {
         return ( (tolower(*((const char*)first_str + i))) - (tolower(*((const char*)second_str + j))));
        }
        return ( (tolower(*((const char*)first_str + i) - '\n') - (tolower(*((const char*)second_str + j)))));
    }

    return ( (tolower(*((const char*)first_str + i)) - (tolower(*((const char*)second_str + j))-'\n')));


}


void allocate_memory_for_text (struct text_param *Onegin,const char* const source)
{

    struct stat Onegin_stat = {};
    stat (source, &Onegin_stat);

    Onegin->text_size = Onegin_stat.st_size;

    Onegin->original = (char*) calloc (Onegin->text_size + 1, sizeof(char));

    if (Onegin->original == 0)
        printf ("НЕ СМОГ ВЫДЕЛИТЬ ДОСТАТОЧНО ПАМЯТИ\n");

}


void div_in_words (struct text_param *Onegin) // Тут я надеюсь на ненулевую массив
{
    (Onegin->lines)[0].beginning = Onegin->original;//Говорю что нет пустых строк
    int word_number = 1;
    for (int i = 0; i < Onegin->text_size; i++)
    {

        if (Onegin->original[i] == '\r')
        {
            Onegin->original[i] = '\0';
            continue;
        }


        if (Onegin->original[i] == '\n' || Onegin->original[i] == ' ')
        {
            Onegin->original[i] = '\0';
            (Onegin->lines)[word_number].beginning = (Onegin->original + (++i));
            word_number++;
        }
    }
    Onegin->am_of_lines = word_number-1;
    printf ("%u\n", Onegin->am_of_lines);
}


void clear_memory_for_text (struct text_param *commands)
{
    free (commands->original);
    commands->text_size = 0;
    for (int i = 0; i < commands->am_of_lines;i++)
    {
        commands->lines[i].beginning = NULL;
        commands->lines[i].size = 0;
    }
    commands->am_of_lines = 0;
}

void read_from_file ( FILE*  text, struct text_param* const Onegin)
{
    Onegin->text_size = fread (Onegin->original,sizeof(char), Onegin->text_size, text);
    if (Onegin->text_size == 0)
    {
        printf ("НЕ СМОГ ПРОЧИТАТЬ ФАЙЛ\n");
    }


}
