#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Windows.h"
#include "getopt.h"

#include "task1.h"
#include "getopt.h"
#include "read_fcn.h"

int main(int argc, char** argv)
{
    
    HANDLE hRead;
    HANDLE hWrite;

    BOOL rd;

    DWORD ptrNumRead;
    DWORD ptrNumWrite;

    waveFileHeader wavHeader;
    waveFileHeader *ptrWavHeader = &wavHeader;
    char *in_add, *out_add;

    int i;
    int bufSize;
    int loop_cnt;
    int last_loop_cnt;

    const char *options = "i:o:";
    const struct option long_options[] = { {"in", required_argument, NULL, 'i'},
                                          {"out", required_argument, NULL, 'o'} };
    char opt;
    int longind;

    while ((opt = getopt_long(argc, argv, "i:o:", long_options, &longind)) != -1)
    {
        switch (opt)
        {
            case 'i':
            {
                in_add = optarg;
                printf("input argument = %s \n\n", optarg);
                break;
            }

            case 'o':
            {
                out_add = optarg;
                printf("output argument = %s \n\n", optarg);
                break;
            }

            default:
                break;
        }
    }

    open_existance(&hRead, in_add);         /*  This function opens file for read   */
    create_new_file(&hWrite, out_add);      /*  This function creates file for write */


    read_wav_header(&hRead, ptrWavHeader, &ptrNumRead);
    printHeader(ptrWavHeader);

    bufSize = (wavHeader.sample_rate / BUFFER_DIV_COEFF) * wavHeader.block_align;
    loop_cnt = wavHeader.data_size / bufSize;

    void* buffer = (uint8_t)malloc(bufSize);

   write_wav_file_header(&hWrite, ptrWavHeader, &ptrNumWrite);

    read_buffer(&hRead, buffer, &bufSize, &ptrNumRead);

   /*for(i = 0; i < loop_cnt; i++)

       ptrNumRead = 0;
    
    for (int i = 0; i < loop_cnt; i++)
    {
        rd = ReadFile(hRead,
                      buffer,
                      bufSize,
                      &ptrNumRead,
                      NULL);
        if (rd)
        {
          
        }
        else
        {
            printf("Readind file corrupted at %d iteration!\n", i);
        }

        rd = WriteFile(hWrite,
                       buffer,
                       bufSize,
                       &ptrNumWrite,
                       NULL);
        if (rd)
        {

        }
        else
        {
            printf("Writing file corrupted at %d iteration!\n", i);
        }

    }

    if (ptrNumWrite == ptrNumRead)
    {
        printf("Writing new file finished!\n");
    }
    else
    {
        printf("OOPS!\n");
    }
    

    return 0;
    */
}
