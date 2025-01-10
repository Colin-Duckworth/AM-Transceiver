# AM Transceiver
An AM transmitter and receiver system designed for audio transmission using a tunable carrier signal. The system uses a DDS for generating the carrier, supports analog audio input via microphone or AUX, and features a complete receiver circuit with filtering, demodulation, amplification, and playback capabilities.

# Overview
This project demonstrates a functional AM transmitter and receiver, showcasing the principles of amplitude modulation and demodulation. The transmitter allows users to transmit audio signals over a tunable frequency range (500kHz to 2MHz). The receiver filters, demodulates, amplifies, and plays back the transmitted audio using basic analog circuitry.

# Key Features

**Transmitter**
- DDS Carrier Generation: The carrier signal is generated using a Direct Digital Synthesizer (DDS), providing a tunable range from 500kHz to 2MHz.
- Audio Input: Supports audio input from either an analog microphone or a 3.5mm AUX jack. 
- Tunable Frequency: A dial is used to adjust the carrier frequency, allowing transmission across a range of frequencies. 
- Wire Antenna: Uses a wire antenna for effective signal transmission.

**Receiver**
- RLC Series Filter: Filters the incoming AM signal to isolate the desired frequency. 
- Envelope Detector: Demodulates the AM signal to recover the transmitted audio.
- Op-Amp Amplification: Amplifies the demodulated audio signal for playback.
- Speaker Output: Plays back the received audio through a small speaker.


# Components Used
**Transmitter**
- DDS Module: [Specify model name]
- Analog Microphone: [Specify model name]
- 3.5mm AUX Jack: [Specify part details]
- Wire Antenna: [Specify details if applicable]
- Frequency Tuning Dial: [Specify part details]

**Receiver**
- RLC Series Filter: [Specify component values]
- Envelope Detector: [Specify diode and capacitor details]
- Op-Amp: [Specify model name]
- Speaker: [Specify model name or specifications]
- Wire Antenna: [Specify details if applicable]

# Libraries Used
- None (Pure analog design)

# Troubleshooting

Carrier Signal Issues
Symptom: No carrier signal observed or unstable frequency output.
Potential Fixes:
Verify connections to the DDS module and check the power supply voltage.
Ensure the frequency tuning dial is functioning correctly and properly connected to the DDS module.
Audio Distortion

Symptom: Distorted or unclear audio playback on the receiver side.
Potential Fixes:
Check the integrity of the envelope detector components (diode and capacitor).
Ensure the op-amp circuit is functioning correctly and verify component values.
Confirm the microphone or AUX jack input is not overdriving the transmitter.
Low Signal Range

Symptom: The transmitted signal cannot be received at a reasonable distance.
Potential Fixes:
Ensure the wire antenna is properly sized and positioned.
Verify the power output of the transmitter.
Check for interference in the transmission environment.
Receiver Sensitivity

Symptom: Weak or no signal detected by the receiver.
Potential Fixes:
Verify the RLC filter component values match the carrier frequency.
Ensure the wire antenna on the receiver is properly connected and aligned.
Inspect the amplification stage for proper operation.
