#ifndef TASK_1
#define TASK_1

#define BUFFER_DIV_COEFF 100        /* 1 / 10 ms*/
#include "stdint.h"
#include "effect_control.h"
#include "effect_process.h"

typedef struct{
	
    uint8_t     riff[4];                    // RIFF string
    uint32_t    overall_size;  	            // overall size of file in bytes
    uint8_t     wave[4];                    // WAVE string

    uint8_t     fmt_chunk_marker[4];        // fmt string with trailing null char
    uint32_t    length_of_fmt;              // length of the format data
    uint16_t    format_type;                // format type
    uint16_t    channels;                   // # of channels
    uint32_t    sample_rate;                // sampling rate 
    uint32_t    byterate;                   // SampleRate * NumChannels * BitsPerSample/8
    uint16_t    block_align;                // NumChannels * BitsPerSample/8
    uint16_t    bits_per_sample;            // bits per sample, 8- 8bits, 16- 16 bits
    uint16_t    axillary_data;              // NOT USED BUT NECESSARY

    uint8_t     data_chunk_header[4];       // DATA string or FLLR string
    uint32_t    data_size;                  // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read

} waveFileHeader;

#endif
