#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Windows.h"
#include "getopt.h"

#include "task1.h"
#include "getopt.h"
#include "printheader.h"


int main(int argc, char** argv)
{
    FILE *existance;
    FILE *new_create; 

    size_t numRead;
    size_t numWrite;

    /*waveFileHeader wavHeader;
    waveFileHeader *ptrWavHeader = &wavHeader;*/

    riffHeader RIFF;
    riffHeader *ptrRIFF = &RIFF;

    fmtHeader FMT;
    fmtHeader *ptrFMT = &FMT;

    dataHeader DATA;
    dataHeader *ptrDATA = &DATA;

    char *in_add, *out_add;
    size_t bufSize, loop_cnt;

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

    
    if ((existance = fopen(in_add, "rb")) == NULL)
    {
        printf("ERROR in opening existance file!\n");
    }

    if ((new_create = fopen(out_add, "w+b")) == NULL)
    {
        printf("ERROR in opening new file!\n");
    }


    /* read header */
    
    numRead = fread(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), existance);
    if (numRead == sizeof(riffHeader))
    {
        printf("ALL RIFF HEADER READED : %d from %d!\n", numRead, sizeof(riffHeader));
    }

    numRead = fread(ptrFMT, sizeof(uint8_t), sizeof(fmtHeader), existance);
    if (numRead == sizeof(fmtHeader))
    {
        printf("ALL FMT HEADER READED : %d from %d!\n", numRead, sizeof(fmtHeader));
    }

    fseek(existance, -2, SEEK_CUR);     //костыль

    numRead = fread(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), existance);
    if (numRead == sizeof(dataHeader))
    {
        printf("ALL DATA HEADER READED : %d from %d!\n", numRead, sizeof(dataHeader));
    }

    printf("Length of fmt = %d\n", (FMT.length_of_fmt + 8));

    printHeader(ptrRIFF, ptrFMT, ptrDATA);

    bufSize = (FMT.sample_rate / BUFFER_DIV_COEFF) * FMT.block_align;
    printf("Buffer size = %d\n", bufSize);

    loop_cnt = DATA.data_size / bufSize;
    printf("Loops = %d\n", loop_cnt);

    numWrite = fwrite(ptrRIFF, sizeof(uint8_t), sizeof(riffHeader), new_create);
    numWrite = fwrite(ptrFMT, sizeof(uint8_t), (FMT.length_of_fmt + 8), new_create);
    numWrite = fwrite(ptrDATA, sizeof(uint8_t), sizeof(dataHeader), new_create);
 
    void *buffer = (uint8_t*)malloc(bufSize);
    
    for (int i = 0; i < loop_cnt; i++)
    {

        numRead = fread(buffer, sizeof(uint8_t), bufSize, existance);

        if (numRead != bufSize)
        {
            printf("Something wrong!\n");
        }
        numWrite = fwrite(buffer, sizeof(uint8_t), bufSize, new_create);
    }

   return 0;
}
 