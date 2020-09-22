#include "printheader.h"

void printHeader(riffHeader *ptrRIFF, 
    fmtHeader *ptrFMT, 
    dataHeader *ptrDATA)
{
    printf("******** WAV HEADER PARSING! ********\n\n");

    printf("Chunk ID : %c%c%c%c\n",
        ptrRIFF->riff[0], ptrRIFF->riff[1], ptrRIFF->riff[2], ptrRIFF->riff[3]);
    printf("Overall size : %d\n", ptrRIFF->overall_size);
    printf("Format : %c%c%c%c\n\n", ptrRIFF->wave[0], ptrRIFF->wave[1], ptrRIFF->wave[2], ptrRIFF->wave[3]);

    printf("SubChunk_1 ID : %c%c%c%c\n",
        ptrFMT->fmt_chunk_marker[0], ptrFMT->fmt_chunk_marker[1], ptrFMT->fmt_chunk_marker[2], ptrFMT->fmt_chunk_marker[3]);
    printf("SubChunk 1 size : %d\n", ptrFMT->length_of_fmt);
    printf("Audio format : ( %d ) IEEE-754 \n", ptrFMT->format_type);
    printf("Channels number : %d\n", ptrFMT->channels);
    printf("Sample rate : %d\n", ptrFMT->sample_rate);
    printf("Byterate : %d\n", ptrFMT->byterate);
    printf("Block allign : %d\n", ptrFMT->block_align);
    printf("Bits per sample : %d\n", ptrFMT->bits_per_sample);
    printf("Axillary data : %d\n\n", ptrFMT->axillary_data);

    printf("SubChunk_2 ID : %c%c%c%c\n",
        ptrDATA->data_chunk_header[0], ptrDATA->data_chunk_header[1], ptrDATA->data_chunk_header[2], ptrDATA->data_chunk_header[3]);
    printf("Data size : %d\n\n", ptrDATA->data_size);

}