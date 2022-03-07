#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include "EEPROM.h"
#include "WiFiMulti.h"
#include <LoRa.h>
#include <SPI.h>
#include <FastLED.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

WiFiMulti wifiMulti;

WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

#define DEBUG
#define TEST
// Criacao de credenciais constantes
String DEVICE_ID;
String SSID1;
String PWD1;
String SSID2;
String PWD2;
String ADM_COD;
String HOSTNAME_OTA;
String PREFIX_TOPIC;
String THINGNAME;

// Criacao de topicos
String TOPIC_SUB_UPDATE;
String TOPIC_PUB_STATUS;

// Receptor LoRa

/* Definicoes para comunicação com radio LoRa */
#define SCK_LORA           5
#define MISO_LORA          19
#define MOSI_LORA          27
#define RESET_PIN_LORA     14
#define SS_PIN_LORA        18
 
#define HIGH_GAIN_LORA     20  /* dBm */
#define BAND               915E6  /* 915MHz de frequencia */
 
/* Definicoes do OLED */
#define OLED_SDA_PIN    4
#define OLED_SCL_PIN    15
#define SCREEN_WIDTH    128 
#define SCREEN_HEIGHT   64  
#define OLED_ADDR       0x3C 
#define OLED_RESET      16
 
/* Offset de linhas no display OLED */
#define OLED_LINE1     0
#define OLED_LINE2     10
#define OLED_LINE3     20
#define OLED_LINE4     30
#define OLED_LINE5     40
#define OLED_LINE6     50
 
/* Definicoes gerais */
#define DEBUG_SERIAL_BAUDRATE    9600
 
/* Variaveis e objetos globais */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
/* Local prototypes */
void display_init(void);
bool init_comunicacao_lora(void);

char byte_recebido;
int packet_size = 0;
int lora_rssi = 0;
String informacao_recebida;
char * ptInformaraoRecebida = NULL;

String humidity;
String distance;
String packet;

//LEDS
#define NUM_LEDS 8

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 13
// #define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];