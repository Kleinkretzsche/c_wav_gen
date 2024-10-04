#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wav_header {
	// MASTER RIFF CHUNK
	char file_type_bloc_ID[4];
	uint32_t file_size;
	char file_format_ID[4];

	// CHUNK DESCRIBING DATA FORMAT
	char format_bloc_ID[4];
	uint32_t bloc_size;
	uint16_t audio_fmt;
	uint16_t num_channels;

	uint32_t frequence;
	uint32_t byte_per_sec;
	uint16_t byte_per_bloc;
	uint16_t bits_per_sample;

	// CHUNK CONTAINING SAMPLED DATA
	char data_bloc_ID[4];
	uint32_t data_size;
};

const uint32_t WAV_HEADER_SIZE = sizeof(struct wav_header);

struct wav_header wav_create_basic_info(uint32_t sample_rate, )
{
	struct wav_header wavh;

	strncpy(&wavh.file_type_bloc_ID, "RIFF", 4);
	strncpy(&wavh.file_format_ID   , "WAVE", 4);
	strncpy(&wavh.format_bloc_ID   , "fmt ", 4);
	strncpy(&wavh.data_bloc_ID     , "data", 4);

	wavh.file_size = WAV_HEADER_SIZE;
	wavh.bloc_size = 0x10;

	wavh.audio_fmt = 1;
	wavh.num_channels = 1;

	wavh.frequence = sample_rate;
}

int main(void)
{
	return 0;
}
