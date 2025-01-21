#include <SPI.h>

#define UPDATE_PIN 8 //rising edge UPDATE_PIN toggles frequency change in DDS
#define DATA_OUT_PIN 11  //MASTER OUT SLAVE IN (D OUT) 
#define DATA_IN_PIN  12  //MASTER IN SLAVE OUT (D IN) *NOT BEING USED
#define SPI_CLOCK_PIN  13  //SPI CLOCK PIN
#define CHIP_SELECT_PIN 10  //CHIP SELECT *NOT BEING USED
#define SPI_CLOCK_FREQUENCY 1000000  //SPI frequency

int dial_state = 0;
int raw_dial_value_int = 0;
float raw_dial_value_float = 0;
String str;

    //The AD9850 takes in 40 bits of serial information with the following format
    //bits 0-31 are for output frequency (LSB first)
    //bits 32-34 are for control
    //bits 35-39 are for output phase (LSB first)

//                    fbyte1 fbyte2 fbyte3 fbyte4 control 
byte config_data[5] = {0xFF,  0xFF,  0xFF,  0x00,  0x00}; // 40 bits of 0
//{0xFF,  0xFF,  0xFF,  0x01,  0x00}; // is 1MHz for refrence
//Keep in mind how it works is it takes the hex, changes it to binary, and then sends the LSB first


void toggle_update_pin(){
  delay(50);
  digitalWrite(8, HIGH); //rising edge on this pin updates frequency of AD9850
  delay(50);
  digitalWrite(8, LOW);
}


void config_AD9850(){ //Note the AD9850 doesn't use SPI protocol it uses serial input, using SPI library is just convinent
  pinMode(DATA_OUT_PIN, OUTPUT); // sets the data out pin as an output
  pinMode(UPDATE_PIN, OUTPUT); // sets the update pin as an output
  digitalWrite(8, LOW); //sets update pin to LOW
  SPI.begin(); //begins SPI communication
  SPI.beginTransaction(SPISettings(SPI_CLOCK_FREQUENCY, LSBFIRST, SPI_MODE0));
    for (int i = 0; i < 5; i++) {
    SPI.transfer(config_data[i]); // Send the byte over SPI
  }
  SPI.endTransaction();
  delay(1000);
  toggle_update_pin();
}

void update_AD9850_register(){
  SPI.begin(); //begins SPI communication
  SPI.beginTransaction(SPISettings(SPI_CLOCK_FREQUENCY, LSBFIRST, SPI_MODE0));
    for (int i = 0; i < 5; i++) {
    SPI.transfer(config_data[i]); // Send the byte over SPI
  }
  SPI.endTransaction();
}

void poll_dial(){
  raw_dial_value_int = analogRead(A0);
  raw_dial_value_float = raw_dial_value_int / 1024;

  if (raw_dial_value_int < 130){ //500kHz setting
    config_data[0] = 0xFF;
    config_data[1] = 0xFF;
    config_data[2] = 0xFF;
    config_data[3] = 0x00;
    config_data[4] = 0x00;
    if (dial_state != 1){
      update_AD9850_register();
    }
    dial_state = 1;
  }

  if ( raw_dial_value_int >= 130 && raw_dial_value_int < 288){ //750kHz setting
  config_data[0] = 0x00;
  config_data[1] = 0x00;
  config_data[2] = 0x80;
  config_data[3] = 0x01;
  config_data[4] = 0x00;
    if (dial_state != 2){
      update_AD9850_register();
    }
    dial_state = 2;
  }

  if (raw_dial_value_int >= 288 && raw_dial_value_int < 423){ //1MHz setting
    config_data[0] = 0xFF;
    config_data[1] = 0xFF;
    config_data[2] = 0xFF;
    config_data[3] = 0x01;
    config_data[4] = 0x00;
    if (dial_state != 3){
      update_AD9850_register();
    }
    dial_state = 3;
  }

  if (raw_dial_value_int >= 423){ //1.25 MHz setting
    config_data[0] = 0xFF;
    config_data[1] = 0xFF;
    config_data[2] = 0x80;
    config_data[3] = 0x02;
    config_data[4] = 0x00;
    if (dial_state != 4){
      update_AD9850_register();
    }
    dial_state = 4;
  }
}

void print_serial_stuff(){
  //prints dial value
  Serial.print(str + "dial state value " + dial_state + "\n ");
  Serial.print(str + "int input value " + raw_dial_value_int + "\n ");
  Serial.print(str + "float input value " + raw_dial_value_float + "\n ");
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT); //carrier frequency dial
  config_AD9850();
}

void loop() {
  delay(1000);
  poll_dial();
  toggle_update_pin();
  print_serial_stuff();
}
