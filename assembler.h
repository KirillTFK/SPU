#pragma once

//-------------------------------------------Константы---------------------------------------------------------

const unsigned VERSION    = 1;
const char*    SIGNATURE  = "abobus228"; //Я не помню че дед хотел в сигнатуре, пока так напишу.
const unsigned MAX_CODE_SIZE = 1000;

//-------------------------------------------Функции-------------------------------------------------------------------
void Read_Command (struct text_param *commands, int *code, unsigned *command_counter);
void Print_Headline (FILE* const machine_code, unsigned code_size, unsigned command_counter);
void Print_Code (int *code, unsigned code_size, FILE* machine_code);

