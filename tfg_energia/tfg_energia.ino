
#define _DEBUG_
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <ThingerWifi.h>

//Datos del dispositivo
#define USERNAME "leviatansoul"
#define DEVICE_ID "tfg_energia"
#define DEVICE_CREDENTIAL "r0PiLq&IpRv$"

//CREDENCIALES DEL ROUTER
//#define SSID "*****_****"
//#define SSID_PASSWORD "**********"


ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL); //Conectar con Thinger

//Salidas y entradas
#define led  D0
#define boton  D2
#define lector  A0

int state = 0;
boolean activar;

int time1 = 0;
int time2 = 0;
int rtt = 0;
int t_cifrado = 0;

void setup() {
   // put your setup code here, to run once:
  Serial.begin(9600);


 thing.add_wifi(SSID, SSID_PASSWORD);
 
  pinMode(led, OUTPUT); //Led Verde
  pinMode(boton, INPUT); //Pulsador
  pinMode(lector, INPUT); //Pulsador


}

void loop() {
  // put your main code here, to run repeatedly:
   thing.handle();

   if(digitalRead(boton) == HIGH && state == 0){
       digitalWrite(led, HIGH);
       state = 1;
       
   

 
       
   }
   
  if(digitalRead(boton) == LOW){
          digitalWrite(led, LOW);
        state = 0;
      }
   
}



