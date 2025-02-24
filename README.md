# AM Transceiver
The AM transmitter is system designed for short-range audio transmission using a tunable carrier signal. The system uses a DDS for generating the carrier, supports analog audio input via microphone or AUX.

# Overview
This project demonstrates a functional AM short-range transmitter, showcasing the principles of amplitude modulation. The transmitter allows users to transmit audio signals over a tunable frequency range (750kHz to 1.25MHz).
# Key Features
- DDS Carrier Generation: The carrier signal is generated using a Direct Digital Synthesizer (DDS), providing a tunable range from 750kHz to 1.25MHz.
- Audio Input: Supports audio input from either an analog microphone or a 3.5mm AUX jack. 
- Tunable Frequency: A dial is used to adjust the carrier frequency, allowing transmission across a range of frequencies. 
- Wire Antenna: Uses a wire antenna for effective short-range signal transmission.

# Components Used
- DDS Module: AD9850
- Analog Microphone: CMEJ-0605-36-L030
- 3.5mm AUX Jack: Any 3.5mm Aux is suitable
- Wire Antenna: Standard 6" through-hole wire
- Frequency Tuning Dial: 3386P-1-103T


# Libraries Used
- SPI.h
-- Built in Arduino SPI Library
