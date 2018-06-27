
//#include <SlaMas.h>
#include <SoftwareSerial.h>
#include <SimpleModbusSlaveSoftwareSerial.h>


long pinek=1111;


int masterr=0;
int aslave=1;




enum 
{     
  sa1,
  sa2,
  sa3,
  sa4,
  sa5,
  sa6,
  spoz1,
  spoz2,
  spoz3,
  spoz4,
  spoz5,
  spoz6,
  smodbusczas,
  sig,
  srz1,
  srz2,
  srz3,
  srz4,
  srz5,
  srz6,
  HOLDINGREGS_SIZE 
};

unsigned int holdingRegs[HOLDINGREGS_SIZE];





int modbusczas2;







#define TAG_INTERRUPT 0x04
#define TOUCH_INTERRUPT 0x02
#define MEM_WRITE  0x80      // Potrzebne do odczytu z EEPROM i zapisu na ft800
#define MEM_READ  0x00
#define ZERO                 0UL

uint8_t touchedTag=0;

unsigned long serialdata;
int inbyte;
int ala;


int d=0;
int m=0;
int yr=0;

int pTag=0;
int aTag=0;
int lastTag=0;
int bTag;
int zTag=0;

int smodbusczas2=250;
int spmodbusczas2=200;


int blok=0;
int blokd=0;

int slamas=22;

int nrFab=9;

//zmienne do przerwania
int soundISR=0;
int alarmISR=0;
int durationISR=0;
long durationbISR=0;
long adresISR=0;

int aalarm=0;
int alarm=0;
int kalarm; //kolor alarmu



int tagoption;


int data;
int day;
int month;
int year;


int czyadres=0;

int niski[]={
  0,400,400,400,400,400,400};
int wysoki[]={
  600,600,600,600,600,600,600};
int rodzaj[]={
  0,1,2,3,4,5,6};
int kanal=1;
int jakikanal=1;



int alarmy[]={
  0,1,1,1,1,1,1};
int palarmy[]={
  0,1,1,1,1,1,1};

int iloscgazow=6;



int test=0;
int testISR=0;
long wyciszenieISR=0;
int wyciszenie=0;
int wycglob=0;
int show=0;
long showISR=0;
int showblok[]={
  0,0,0,0,0,0,0};
int showblokISR=0;
long pamiecanalog[]={
  0,0,0,0,0,0,0};

int serialISR=0;
int odebrano=0;
long odebranoISR=0;
int odebranoA=0;

int vol=255;
int bloksound=0;

int odx4[]={
  0,0,245,0,245};
int ody4[]={
  0,0,0,115,115};
int odx6[]={
  0,0,163,326,0,163,326};
int ody6[]={
  0,0,0,0,115,115,115};


long odczytanalog[]={
  0,0,0,0,0,0};
long odczytanalogg[]={
  0,0,0,0,0,0}; 
int odczytanalog2[]={
  0,0,0,0,0,0,0,0};

int an=0;

int kolcyfrowe[]={
  0,70,71,72,38,19,20,21};//kolejnosc wejsc cyfrowych

int blokwyc=0;

int numerfabryczny=1;











//////////////////////////////////////////////////////////////////////////////////////


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Start");


//////////////////////////////////////////////////////////

//  pinMode(18, OUTPUT);

  pinMode(7, OUTPUT);


//  smodbus_configure(&Serial, 9600, SERIAL_8N2, 5, 7, HOLDINGREGS_SIZE, holdingRegs);
//  smodbus_update_comms(9600, SERIAL_8N2, 5);

  modbus_configure(9600, 5, 7, HOLDINGREGS_SIZE);



/////////////////////////////////////////////////////////


}





void loop() {

   modbus_update(holdingRegs);
    iloscgazow=holdingRegs[sig];
    delayMicroseconds(50);    
    alarmy[1]=holdingRegs[sa1];
    delayMicroseconds(50); 
    alarmy[2]=holdingRegs[sa2];
    delayMicroseconds(50); 
    alarmy[3]=holdingRegs[sa3];
    delayMicroseconds(50); 
    alarmy[4]=holdingRegs[sa4];
    delayMicroseconds(50); 
    alarmy[5]=holdingRegs[sa5];
    delayMicroseconds(50); 
    alarmy[6]=holdingRegs[sa6];
    delayMicroseconds(50); 
    odczytanalog2[1]=holdingRegs[spoz1];
    delayMicroseconds(50); 
    odczytanalog2[2]=holdingRegs[spoz2];
    delayMicroseconds(50); 
    odczytanalog2[3]=holdingRegs[spoz3];
    delayMicroseconds(50); 
    odczytanalog2[4]=holdingRegs[spoz4];
    delayMicroseconds(50); 
    odczytanalog2[5]=holdingRegs[spoz5];
    delayMicroseconds(50); 
    odczytanalog2[6]=holdingRegs[spoz6];
    delayMicroseconds(50); 
    rodzaj[1]=holdingRegs[srz1];
    delayMicroseconds(50); 
    rodzaj[2]=holdingRegs[srz2];
    delayMicroseconds(50); 
    rodzaj[3]=holdingRegs[srz3];
    delayMicroseconds(50); 
    rodzaj[4]=holdingRegs[srz4];
    delayMicroseconds(50); 
    rodzaj[5]=holdingRegs[srz5];
    delayMicroseconds(50); 
    rodzaj[6]=holdingRegs[srz6];
    delayMicroseconds(50); 
    spmodbusczas2=holdingRegs[smodbusczas];
    delayMicroseconds(50); 


Serial.println("Ilosc gazow:"); 
Serial.println(iloscgazow); 
Serial.println(alarmy[1]); 
Serial.println("Rodzaje gazow:"); 
Serial.println(rodzaj[1]); 
Serial.println(rodzaj[2]); 
Serial.println(rodzaj[3]); 
Serial.println(rodzaj[4]); 
Serial.println(rodzaj[5]); 
Serial.println(rodzaj[6]); 

delay(500);


if(iloscgazow==2){
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
}else {
    digitalWrite(LED_BUILTIN, HIGH);    // turn the LED off by making the voltage LOW
}

    


  

}
