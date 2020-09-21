#ifndef READ_FCN
#define READ_FCN

#include "Windows.h"
#include "task1.h"
#include "stdio.h"

/*
*   Function for opening WAV file
* @params[in]  : *existance_path - pointer to string, in which path of file is placed
* @params[out] : *hRead - pointer to read file HANDLER
*/
void open_wav(HANDLE *hRead, 
    char *existance_path);

/*
*   Function for creating new WAV file
* @params[in]  : *new_path -  pointer to string, in which path new file is need to placed
* @params[out] : *hWrite - pointer to write file HANDLER
*/
void create_new_wav(HANDLE *hWrite, 
    char *new_path);

/*
*   Function for reading WAV HEADER by fields
* @param[in, out]   : *ptrWAVHeader pointer to WAV HEADER structure
* @param[in]        : *hRead - HANDLE of file, which is readed
* @param[in]        : *numRead - number of readed bytes
*/
void read_wav_header(HANDLE* hRead, 
    waveFileHeader *ptrWAVHeader,
    uint32_t *ptrNumRead);


/*
*   Function for printing WAV HEADER by fields
* @param[in]   : *ptrWAVHeader pointer to WAV HEADER structure
*/
void print_wav_header(waveFileHeader *ptrWAVHeader);

/*
*   Function which writes new file
*@param
*
*/

void write_wav_file_header(HANDLE *hWrite,
    waveFileHeader *ptrWAVHeader,
    uint32_t *ptrNumWrite);

/*
*
*
*/

void read_buffer(HANDLE *hRead,
    uint8_t *buffer,
    uint32_t *bufSize,
    uint32_t *ptrNumRead);

#endif // !READ_FCN