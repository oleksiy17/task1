#ifndef TASK_1
#define TASK_1

#define BUFFER_DIV_COEFF 100        /* 1 / 10 ms*/
#include "stdint.h"


/*typedef struct{
	
    uint8_t    riff[4];                    // RIFF string
    uint8_t    overall_size[4];  	            // overall size of file in bytes
    uint8_t    wave[4];                    // WAVE string

    uint8_t    fmt_chunk_marker[4];        // fmt string with trailing null char
    uint8_t    length_of_fmt[4];              // length of the format data
    uint8_t    format_type[2];                // format type
    uint8_t    channels[2];                   // # of channels
    uint8_t    sample_rate[4];                // sampling rate 
    uint8_t    byterate[4];                   // SampleRate * NumChannels * BitsPerSample/8
    uint8_t    block_align[2];                // NumChannels * BitsPerSample/8
    uint8_t    bits_per_sample[2];            // bits per sample, 8- 8bits, 16- 16 bits
    uint8_t    axillary_data[2];              // NOT USED BUT NECESSARY

    uint8_t    data_chunk_header[4];           // DATA string or FLLR string
    uint8_t    data_size[4];                  // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read

} waveFileHeader;*/

typedef struct {
    uint8_t    riff[4];                    // RIFF string
    uint32_t   overall_size;  	            // overall size of file in bytes
    uint8_t    wave[4];                    // WAVE string
} riffHeader;

typedef struct {
    uint8_t    fmt_chunk_marker[4];        // fmt string with trailing null char
    uint32_t   length_of_fmt;              // length of the format data
    uint16_t   format_type;                // format type
    uint16_t   channels;                   // # of channels
    uint32_t   sample_rate;                // sampling rate 
    uint32_t   byterate;                   // SampleRate * NumChannels * BitsPerSample/8
    uint16_t   block_align;                // NumChannels * BitsPerSample/8
    uint16_t   bits_per_sample;            // bits per sample, 8- 8bits, 16- 16 bits
    uint16_t   axillary_data;              // NOT USED BUT NECESSARY
}fmtHeader;

typedef struct {
    uint8_t    data_chunk_header[4];           // DATA string or FLLR string
    uint32_t    data_size;                  // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
}dataHeader;


#endif
