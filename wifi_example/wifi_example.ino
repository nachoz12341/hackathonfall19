/*
    HTTP over TLS (HTTPS) example sketch
    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.
    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1
    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SoftwareSerial.h>
SoftwareSerial UNOserial(0, 2); //rx tx

#ifndef STASSID
#define STASSID "JBHunt Mobile Router 5"
#define STAPSK  "jbhunthack"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "shrouded-oasis-00187.herokuapp.com";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char fingerprint[] PROGMEM = "083b717202436ecaed428693ba7edf81c4bc6230";

void setup() {
  pinMode(0, INPUT);
  pinMode(2, OUTPUT);
  
  Serial.begin(9600);
  UNOserial.begin(9600);
  /*Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);

  Serial.printf("Using fingerprint '%s'\n", fingerprint);
  client.setFingerprint(fingerprint);

  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/";
  Serial.print("requesting URL: ");
  Serial.println(url);

  //client.print(String("GET ") + url + " HTTP/1.1\r\n" +
  //             "Host: " + host + "\r\n" +
  //             "Connection: close\r\n\r\n");
  char PostData[] = "{\"data\": \"buttz\"}"; // your JSON payload
  client.println("POST " + url + " HTTP/1.1");
      client.println("content-type: application/json");
      client.print("content-length: ");
      client.println(strlen(PostData));
    client.print("Host: ");
    client.println(host);
    client.println("Connection: close");
    client.println();
    client.println(PostData);

  //Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');

  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
  Serial.println();*/
}

void loop() {
    if(UNOserial.available() )   
    { 
      Serial.write( UNOserial.read() );  
    }
  //delay(50);
}
