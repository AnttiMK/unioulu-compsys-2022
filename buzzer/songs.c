#include "songs.h"

Song nokia() {
    Song nokia;
    nokia.tempo = 180;

    int melody[] = {NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4,
    NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4,
    NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
    NOTE_A4, 2, 0};

    int i;
    for(i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        nokia.melody[i] = melody[i];
    };

    return nokia;
};
