#include "read_fcn.h"

void open_existance(HANDLE *hRead, char *existance_path)
{
    *hRead = CreateFile(existance_path,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (*hRead == INVALID_HANDLE_VALUE)
    {
        printf("Error in opening initial WAV file\n");
    }
    else
    {
        printf("Sucess in opening of existance WAV file\n");
    } 
}

void create_new_file(HANDLE *hWrite, char *new_path)
{
    *hWrite = CreateFile(new_path,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        0,
        NULL);                 

    if (*hWrite == INVALID_HANDLE_VALUE)
    {
        printf("Error in opening new WAV file\n");
    }
    else
    {
        printf("Sucess creation of new WAV file\n");
    }
}

void read_wav_header(HANDLE* hRead, 
    waveFileHeader *ptrWAVHeader,
    uint32_t *ptrNumRead)
{
    BOOL rd_handl;

   /*   Read RIFF Chunk     */
    rd_handl = ReadFile(*hRead,
        ptrWAVHeader->riff,
        sizeof(ptrWAVHeader->riff),
        ptrNumRead,
        NULL);
    
    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Chunk ID writing fail\n");
    }

    /*   Read Overall Size     */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->overall_size),
        sizeof(ptrWAVHeader->overall_size),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Overall Size writing fail\n");
    }
   
    /*   Read Format     */
    rd_handl = ReadFile(*hRead,
        ptrWAVHeader->wave,
        sizeof(ptrWAVHeader->wave),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Format writing fail\n");
    }

    /*   Read FMT String     */
    rd_handl = ReadFile(*hRead,
        ptrWAVHeader->fmt_chunk_marker,
        sizeof(ptrWAVHeader->fmt_chunk_marker),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("FMT writing fail\n");
    }


    /*   FMT Length    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->length_of_fmt),
        sizeof(ptrWAVHeader->length_of_fmt),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("FMT Length writing fail\n");
    }


    /*   Format Type     */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->format_type),
        sizeof(ptrWAVHeader->format_type),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Format Type writing fail\n");
    }


    /*   Number of channels    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->channels),
        sizeof(ptrWAVHeader->channels),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Number of channels writing fail\n");
    }


    /*   Sample rate    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->sample_rate),
        sizeof(ptrWAVHeader->sample_rate),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Sample rate writing fail\n");
    }


    /*   Byte rate    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->byterate),
        sizeof(ptrWAVHeader->byterate),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Byte rate writing fail\n");
    }


    /*   Block allign    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->block_align),
        sizeof(ptrWAVHeader->block_align),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Block allign writing fail\n");
    }


    /*   Bits per sample    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->bits_per_sample),
        sizeof(ptrWAVHeader->bits_per_sample),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Bits per sample\n");
    }


    /*   Axillary data    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->axillary_data),
        sizeof(ptrWAVHeader->axillary_data),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Axillary data\n");
    }


    /*   Read DATA Chunk     */
    rd_handl = ReadFile(*hRead,
        ptrWAVHeader->data_chunk_header,
        sizeof(ptrWAVHeader->data_chunk_header),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("DATA Chunk writing fail\n");
    }


    /*   Data size    */
    rd_handl = ReadFile(*hRead,
        &(ptrWAVHeader->data_size),
        sizeof(ptrWAVHeader->data_size),
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Data size  writing fail\n");
    }
}

/*
* 
* 
*/
void write_wav_file_header(HANDLE* hWrite,
    waveFileHeader* ptrWAVHeader,
    uint32_t* ptrNumWrite)
{
    BOOL rd_handl;

    rd_handl = WriteFile(*hWrite,
        ptrWAVHeader->riff,
        sizeof(ptrWAVHeader->riff),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->overall_size),
        sizeof(ptrWAVHeader->overall_size),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        ptrWAVHeader->wave,
        sizeof(ptrWAVHeader->wave),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        ptrWAVHeader->fmt_chunk_marker,
        sizeof(ptrWAVHeader->fmt_chunk_marker),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->length_of_fmt),
        sizeof(ptrWAVHeader->length_of_fmt),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->format_type),
        sizeof(ptrWAVHeader->format_type),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->channels),
        sizeof(ptrWAVHeader->channels),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->sample_rate),
        sizeof(ptrWAVHeader->sample_rate),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->byterate),
        sizeof(ptrWAVHeader->byterate),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->block_align),
        sizeof(ptrWAVHeader->block_align),
        ptrNumWrite,
        NULL);;

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->bits_per_sample),
        sizeof(ptrWAVHeader->bits_per_sample),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->axillary_data),
        sizeof(ptrWAVHeader->axillary_data),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        ptrWAVHeader->data_chunk_header,
        sizeof(ptrWAVHeader->data_chunk_header),
        ptrNumWrite,
        NULL);

    rd_handl = WriteFile(*hWrite,
        &(ptrWAVHeader->data_size),
        sizeof(ptrWAVHeader->data_size),
        ptrNumWrite,
        NULL);
}

void read_buffer(HANDLE *hRead,
    uint8_t *buffer,
    uint32_t *bufSize,
    uint32_t *ptrNumRead)
{
    BOOL rd_handl;

    rd_handl = ReadFile(*hRead,
        buffer,
        *bufSize,
        ptrNumRead,
        NULL);

    if (rd_handl == INVALID_HANDLE_VALUE)
    {
        printf("Buffer read fail!\n");
    }

    for (int i = 0; i < 16; i++)
    {
        printf("%XX ", buffer[i]);
    }
    
    printf("\n");
}


void printHeader(waveFileHeader *ptrWAVHeader)
{
    printf("******** WAV HEADER PARSING! ********\n\n");

    printf("Chunk ID : %c%c%c%c\n", 
        ptrWAVHeader->riff[0], ptrWAVHeader->riff[1], ptrWAVHeader->riff[2], ptrWAVHeader->riff[3]);
    printf("Overall size : %d\n", ptrWAVHeader->overall_size);
    printf("Format : %c%c%c%c\n\n", ptrWAVHeader->wave[0], ptrWAVHeader->wave[1], ptrWAVHeader->wave[2], ptrWAVHeader->wave[3]);

    printf("SubChunk_1 ID : %c%c%c%c\n", 
        ptrWAVHeader->fmt_chunk_marker[0], ptrWAVHeader->fmt_chunk_marker[1], ptrWAVHeader->fmt_chunk_marker[2], ptrWAVHeader->fmt_chunk_marker[3]);
    printf("SubChunk 1 size : %d\n", ptrWAVHeader->length_of_fmt);
    printf("Audio format : ( %d ) IEEE-754 \n", ptrWAVHeader->format_type);
    printf("Channels number : %d\n", ptrWAVHeader->channels);
    printf("Sample rate : %d\n", ptrWAVHeader->sample_rate);
    printf("Byterate : %d\n", ptrWAVHeader->byterate);
    printf("Block allign : %d\n", ptrWAVHeader->block_align);
    printf("Bits per sample : %d\n", ptrWAVHeader->bits_per_sample);
    printf("Axillary data : %d\n\n", ptrWAVHeader->axillary_data);

    printf("SubChunk_2 ID : %c%c%c%c\n", 
        ptrWAVHeader->data_chunk_header[0], ptrWAVHeader->data_chunk_header[1], ptrWAVHeader->data_chunk_header[2], ptrWAVHeader->data_chunk_header[3]);
    printf("Data size : %d\n\n", ptrWAVHeader->data_size);
}
