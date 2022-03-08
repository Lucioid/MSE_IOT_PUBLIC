#include <LoRa.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int umidade;
float umid_percentual;

// Defina o Trig e o pino de eco:
#define trigPin 0
#define echoPin 23
#define humidpin 34
// Defina as variáveis:
long duration;
int distance;
int last_distance;

/* Definicoes para comunicação com radio LoRa */
#define SCK_LORA           5
#define MISO_LORA          19
#define MOSI_LORA          27
#define RESET_PIN_LORA     14
#define SS_PIN_LORA        18
 
#define HIGH_GAIN_LORA 20  /* dBm */
#define BAND 915E6  /* 915MHz de frequencia */
 

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
#define DEBUG_SERIAL_BAUDRATE 9600

/* Variaveis e objetos globais */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/* Variaveis globais */
String packet;
 
/* Local prototypes */
void display_init(void);
bool init_comunicacao_lora(void);
 
