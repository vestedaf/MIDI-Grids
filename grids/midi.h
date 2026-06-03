#ifndef GRIDS_MIDI_H_
#define GRIDS_MIDI_H_

#include "avrlib/base.h"
#include "grids/hardware_config.h"

#define MIDI_BUFFER_SIZE 64

namespace grids
{

  static constexpr uint8_t MIDI_CHANNEL = 9; // channel 10 (channel index 0-15)

  // General MIDI note numbers
  static uint8_t BD_NOTE = 0x24;        // Kick Drum (Electric Bass Drum)
  static uint8_t SD_NOTE = 0x26;        // Snare Drum (Acoustic Snare)
  static uint8_t HH_NOTE = 0x2a;        // Closed Hi-Hat
  static uint8_t BD_ACCENT_NOTE = 0x24; // Kick Drum (Electric Bass Drum)
  static uint8_t SD_ACCENT_NOTE = 0x26; // Snare Drum (Acoustic Snare)
  static uint8_t HH_ACCENT_NOTE = 0x2e; // Open Hi-Hat

  // Circular buffer implementation
  static volatile uint8_t output_buffer[MIDI_BUFFER_SIZE];
  static volatile uint8_t buffer_head = 0;
  static volatile uint8_t buffer_tail = 0;

  class MidiDevice
  {
  public:
    // Initialize UART for MIDI TX on PD1
    static inline void Init()
    {
      // Configure UART for MIDI output (31250 baud, 8N1)
      UBRR0 = 31; // 31250 baud at 16MHz: (16000000 / 16 / 31250) - 1 = 31
      UCSR0A = 0;
      UCSR0B = (1 << TXEN0); // Enable transmitter only
      UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data bits, 1 stop bit, no parity
    }

    // Send a single MIDI byte directly (non-blocking check)
    static inline void Send(uint8_t byte)
    {
      while (!(UCSR0A & (1 << UDRE0))); // Wait for transmit buffer to be ready
      UDR0 = byte;
    }

    // Buffer a single byte into the circular buffer
    static inline void Buffer(uint8_t byte)
    {
      uint8_t next_head = (buffer_head + 1) % MIDI_BUFFER_SIZE;
      if (next_head != buffer_tail)
      { // Ensure buffer is not full
        output_buffer[buffer_head] = byte;
        buffer_head = next_head;
      }
      // Else: Buffer overflow, notes will be dropped
    }

    // Send all buffered MIDI bytes using direct UART
    static inline void SendBuffer()
    {
      while (buffer_tail != buffer_head)
      {
        Send(output_buffer[buffer_tail]);
        buffer_tail = (buffer_tail + 1) % MIDI_BUFFER_SIZE;
      }
    }

    // Send a 3-byte MIDI message
    static inline void BufferMidiMessage(uint8_t a, uint8_t b, uint8_t c)
    {
      Buffer(a);
      Buffer(b);
      Buffer(c);
    }

    // Buffer a MIDI note
    static inline void BufferNote(uint8_t channel, uint8_t note, uint8_t velocity)
    {
      BufferMidiMessage(0x90 | channel, note, velocity);
    }

    // Buffer All Notes Off for a specific channel
    static inline void BufferAllNotesOff(uint8_t channel)
    {
      BufferMidiMessage(0x80 | channel, BD_NOTE, 0);
      BufferMidiMessage(0x80 | channel, SD_NOTE, 0);
      BufferMidiMessage(0x80 | channel, HH_NOTE, 0);
      BufferMidiMessage(0x80 | channel, BD_ACCENT_NOTE, 0);
      BufferMidiMessage(0x80 | channel, SD_ACCENT_NOTE, 0);
      BufferMidiMessage(0x80 | channel, HH_ACCENT_NOTE, 0);
    }

  };

} // namespace grids

#endif // GRIDS_MIDI_H_
