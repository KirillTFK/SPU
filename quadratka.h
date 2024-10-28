#pragma once
//----------------[Константы]----------------------------------

const int INF_ROOTS = 8;
const int NUM_OF_ROOTS = 2;
const int MAX_NAME_SIZE = 256;
const int MAX_ROW   = 6000;
const int VER_WIDTH = 10;   //TODO CONST,(Сделал)
const int COLUMNS   = 100;

const char message[10][200]={"Знак путкуации","Управляющий символ",
"Пробел", "Пробельный символ", "Десятичная цифра",
"Шестнадцатиричная цифра", "Маленькая", "Большая", "Буква" };
// сверху константа для dec_symb_typ
struct Coeffs
{
    double a, b, c;
};
/*
struct string
{
    int size;
    char *beginning;
};

struct text_param
{
    struct string *lines[MAX_ROW];//TODO: ПРЕКРАТИТЬ ХУЙНЮ
    int am_of_lines;
    int text_size;
    char *original;

};
*/
// struct text_param
// {
//     char **beginning_of_lines;//TODO: ПРЕКРАТИТЬ ХУЙНЮ
//     int am_of_lines;
//     int text_size;
//     char *original;
//
// };

struct string
{
    int size;
    char *beginning;
};

struct text_param
{
    struct string lines[MAX_ROW];//TODO: ПРЕКРАТИТЬ ХУЙНЮ
    unsigned am_of_lines;
    int text_size;
    char *original;

};

//----------------[FUNCTIONS WITHOUT ARGUMENTS]----------------
void clear_buf (void);
void greet (void);
void invit_select_mode (void);
int mode_select (void);
char restart (void);


//----------------[FUNCTIONS WITH ARGUMENTS]----------------
void                 check_num_of_arguments (int argc);
void                 assert_and_finite (double check);
void                 calculat_for_conv_to_another_num_sys (char** ptr, unsigned long long base,
                                                           unsigned long long div, unsigned long long xcopy);
void                 check_input (double* check_coeff);
void                 choose_file_mode   (char* file_name,FILE** file_pointer,const char mod);
int                  compare_with_zer0 (const double num, const char operation);
char*                conv_to_another_num_sys (char** ptr, unsigned long long x, unsigned div);
unsigned long long   convert_to_ten_sys (char* num, unsigned base, size_t size);
void                 dec_symb_typ (int);
int                  div_in_lines (struct text_param * info);
bool                 equal_zer0 (const double buf_num);
void                 find_out_file_name (char* file_name, FILE** file_pointer);
char                 find_out_symbol (unsigned long long symb );
void                 lin_mode ( struct Coeffs* input, int mode,
                                int nRoots, double* Roots);
int use_file_to_input (void);

void read_and_check_file_input (FILE* file_pointer,
                                struct Coeffs* adres_input,
                                int mode);
void read_coeffs ( struct Coeffs* adres_input,
                   int mode );
void read_in_array (char *arr, struct text_param *info);
void output_roots (int nRoots, double* Roots);
void square_mode (struct Coeffs* input, int mode,
                  int nRoots, double* Roots);
int quadratic_solver ( struct Coeffs* adres_input,
                       double* Roots);
void make_x1_the_biggest (double* Roots);


int lin_solver (const struct Coeffs* adres_input,
                double* Roots);

int  stupid_compare (const void* first_str, const void* second_str);
void selection_sort (struct string lines[], int size);
int  read_from_file   (FILE *source, char text_on_pc[][COLUMNS]);
void nullify (char *rubbish);
void copy (char* pathetic_parody, const char* unique_original, int Max_char_to_copy);
void remove_excess (char* arr,int size);

void check_open  (FILE **f_ptr, const char *name, const char *mode);  //TODO rename
struct text_param* create_space_for_text ();
int clear_text_from_cringe (const char *text);
void allocate_memory_for_text (struct text_param *Onegin,const char* const source);

int symb_typ (char); //определяет че за переменная(число, буква и т.д.)
void ZOV (FILE *text, char agitation[]);
void div_in_words (struct text_param *Onegin);
void clear_memory_for_text (struct text_param *Onegin);
void read_from_file (FILE* text, struct text_param* const Onegin);

//-----------------------------[Функции для квадратки]----------------------------

void choose_the_biggest (unsigned* a, unsigned* b, unsigned* c);

void sort (unsigned* mults, int j);
void factorize (unsigned* num);

int check_is_prime (unsigned n);
