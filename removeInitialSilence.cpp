#include <stdio.h>
#include <sndfile.h>
#include <stdlib.h>
#include <string.h>


#define READ_SAMPLES 8192
#define EPSILON ((double)0.01)


void removeSilence(const char *fname) {
    const char *prefix = "trimmed-";
    char *fname_new = (char *)malloc(strlen(fname) + strlen(prefix) + 1);
    sprintf(fname_new, "%s%s", prefix, fname);
    SF_INFO fileInfo;
    fileInfo.format = 0;

    SNDFILE *fr = sf_open(fname, SFM_READ, &fileInfo);
    SNDFILE *fw = sf_open(fname_new, SFM_WRITE, &fileInfo);

    free(fname_new);

    if (!fr || !fw) {
        sf_close(fr); sf_close(fw);
        printf("Error: couldn't open %s.\n", fname);
        throw;
    }

    double *buffer = (double*)malloc(sizeof(double) * fileInfo.channels * READ_SAMPLES);
    if (!buffer) {
        sf_close(fr); sf_close(fw);
        printf("Error: can't allocate enough memory.\n");
        throw;
    }

    sf_count_t framesRead = 0;
    bool soundStarted = false;
    int trimmedFrames = 0;

    while (true) {
        framesRead = sf_readf_double(fr, buffer, READ_SAMPLES);
        if (framesRead == 0)
            break;

        int i = 0;
        while (!soundStarted && i < framesRead/2) {
            if (buffer[2*i] > EPSILON || buffer[2*i+1] > EPSILON) {
                soundStarted = true;
                break;
            }
            i++;
        }
        trimmedFrames += i;

        if (soundStarted)
            sf_writef_double(fw, buffer + 2*i, framesRead - 2*i);
    }

    free(buffer);
    sf_close(fr); sf_close(fw);

    printf("%s: trimmed %i frames\n", fname, trimmedFrames);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s SOUNDFILE1 ... SOUNDFILEN\n\tRemoves initial silence from supplied sound files.\n\tFor each input file, a new one is created, called trimmed-OLDNAME.\n", argv[0]);
    } else {
        for (int i = 1; i < argc; i++) {
            removeSilence(argv[i]);
        }
    }
}
