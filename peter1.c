// using gcc on Linux write a C program which opens up a usb midi device and sends a channel change request based on a supplied intege

// produces this:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <alsa/asoundlib.h>
#include <signal.h>


#define MIDI_CHANNEL_MSG_SIZE 3
#define MIDI_CHANNEL 0xB0 // MIDI Control Change message

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <device> <channel>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *device_name = argv[1];
    int channel = atoi(argv[2]);

    snd_rawmidi_t *midi_in;
    snd_rawmidi_t *midi_out;
    int err;

    // Open the MIDI device for output
    if ((err = snd_rawmidi_open(NULL, &midi_out, device_name, SND_RAWMIDI_NONBLOCK | SND_RAWMIDI_SYNC)) < 0) {
        fprintf(stderr, "Cannot open MIDI output device %s: %s\n", device_name, snd_strerror(err));
        return EXIT_FAILURE;
    }

    // Prepare MIDI message for channel change
    unsigned char msg[MIDI_CHANNEL_MSG_SIZE];
    msg[0] = MIDI_CHANNEL | (channel & 0x0F); // MIDI Control Change message
    msg[1] = 0; // Controller number (MSB)
    msg[2] = 0; // Controller value (LSB)

    // Send MIDI message
    if ((err = snd_rawmidi_write(midi_out, msg, MIDI_CHANNEL_MSG_SIZE)) != MIDI_CHANNEL_MSG_SIZE) {
        fprintf(stderr, "Error sending MIDI message: %s\n", snd_strerror(err));
        snd_rawmidi_close(midi_out);
        return EXIT_FAILURE;
    }

    // Close MIDI output device
    snd_rawmidi_close(midi_out);

    return EXIT_SUCCESS;
}

/*
To compile this program using gcc, you can use the following command:

gcc your_program.c -o midi_channel_changer -lasound

Replace your_program.c with the name of your source file containing the above code. This command compiles your program and links it with the ALSA library (libasound). After compiling, you can run the program providing the device name (e.g., /dev/snd/midiC1D0) and the MIDI channel number as arguments. For example:

bash

./midi_channel_changer /dev/snd/midiC1D0 1

This will send a MIDI channel change request to channel 1 on the specified MIDI device.
*/

