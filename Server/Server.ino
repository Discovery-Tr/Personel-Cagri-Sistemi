#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

// Enter your wifi network name and Wifi Password

const char* ssid = "Wifi Name";
const char* password = "Wifi Pass";

// Set web server port number to 80
WiFiServer server(80);

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 100);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 255, 0);

String header;

String outputkullanici1 = "off";
String outputkullanici2 = "off";
String outputkullanici3 = "off";
String outputkullanici4 = "off";
String outputkullanici5 = "off";
String outputkullanici6 = "off";

const int kullanici1 = 3;
const int kullanici2 = 19;
const int kullanici3 = 18;
const int kullanici4 = 17;
const int kullanici5 = 4;
const int kullanici6 = 2;
const int resetButton = 15;
const int buzzer = 12; 


// şimdiki zamanı milis için tanımlama
unsigned long simdikizaman = millis();

// geçen zamana başlangıç verme
unsigned long eskizaman = 0; 

// Zaman aşımı süresini milisaniye cinsinden tanımlayama (örn: 2000ms = 2s)
const long zamanasimi = 2000;


void setup() {
etiket();

Serial.begin(115200);

pinMode(kullanici1, OUTPUT);
pinMode(kullanici2, OUTPUT);
pinMode(kullanici3,OUTPUT);
pinMode(kullanici4,OUTPUT);
pinMode(kullanici5,OUTPUT);
pinMode(kullanici6,OUTPUT);
pinMode(resetButton,INPUT_PULLUP);
pinMode(buzzer, OUTPUT);


digitalWrite(kullanici1, LOW);
digitalWrite(kullanici2, LOW);
digitalWrite(kullanici3, LOW);
digitalWrite(kullanici4, LOW);
digitalWrite(kullanici5, LOW);
digitalWrite(kullanici6, LOW);


if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

// Connect to Wi-Fi network with SSID and password

Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// Print local IP address and start web server
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();
}

void etiket()
{
lcd.begin();  
lcd.backlight();
lcd.setCursor(0,0);
  lcd.print("     OSB KOLEJi");
  lcd.setCursor(0,1);
  lcd.print("ELEKTRiK  ELEKTRONiK");
  lcd.setCursor(0,2);
  lcd.print("         VE");
  lcd.setCursor(0,3);
  lcd.print("  OTOMASYON BOLUMU  ");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Personel Cagri Sis.");
  
  lcd.setCursor(0,1);
  lcd.print("Oda1:");
  
  lcd.setCursor(0,2);
  lcd.print("Oda2:");
 
  lcd.setCursor(0,3);
  lcd.print("Oda3:");
  
  lcd.setCursor(11,1);
  lcd.print("Oda4:");
  
  lcd.setCursor(11,2);
  lcd.print("Oda5:");
    
  lcd.setCursor(11,3);
  lcd.print("Oda6:");
  
}



void Oda1(){
  for (int  i= 0; i < 3; i++)
  {
    digitalWrite(kullanici1, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(6,1);
    lcd.print("    ");
    delay (300);
    digitalWrite(kullanici1, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(6,1);
    lcd.print("XXX ");
    delay (300);
    digitalWrite(kullanici1, HIGH);
    }
  }

void Oda2(){
  for (int i=0; i<3; i++)
  {
    digitalWrite(kullanici2, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(6,2);
    lcd.print("    ");
    delay (300);
    digitalWrite(kullanici2, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(6,2);
    lcd.print("XXX ");
    delay (300);
    digitalWrite(kullanici2, HIGH);
    }
  }

void Oda3(){
  for (int i=0; i<3; i++)
  {
    digitalWrite(kullanici3, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(6,3);
    lcd.print("    ");
    delay (300);
    digitalWrite(kullanici3, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(6,3);
    lcd.print("XXX ");
    delay (300);
    digitalWrite(kullanici3, HIGH);
    }
  }

void Oda4(){
  for (int i=0; i<3; i++)
  {
    digitalWrite(kullanici4, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(17,1);
    lcd.print("   ");
    delay (300);
    digitalWrite(kullanici4, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(17,1);
    lcd.print("XXX");
    delay (300);
    digitalWrite(kullanici4, HIGH);
    }
  }

  
void Oda5(){
  for (int i=0; i<3; i++)
  {
    digitalWrite(kullanici5, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(17,2);
    lcd.print("   ");
    delay (300);
    digitalWrite(kullanici5, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(17,2);
    lcd.print("XXX");
    delay (300);
    digitalWrite(kullanici5, HIGH);
    }
  }

void Oda6(){
  for (int i=0; i<3; i++)
  {
    digitalWrite(kullanici6, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(17,3);
    lcd.print("   ");
    delay (300);
    digitalWrite(kullanici6, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(17,3);
    lcd.print("XXX");
    delay (300);
    digitalWrite(kullanici6, HIGH);
    }
  }
void loop(){

   unsigned long simdikizaman1 = millis();
   WiFiClient client = server.available();
  if (digitalRead(resetButton) == HIGH)
  {
    
    digitalWrite(kullanici1, LOW);
    digitalWrite(kullanici2, LOW);
    digitalWrite(kullanici3, LOW);
    digitalWrite(kullanici4, LOW);
    digitalWrite(kullanici5, LOW);
    digitalWrite(kullanici6, LOW);
    
    outputkullanici1 = "off";
    outputkullanici2 = "off";
    outputkullanici3 = "off";
    outputkullanici4 = "off";
    outputkullanici5 = "off";
    outputkullanici6 = "off";
    
    Serial.println("Ledler Sıfırlandı");
    etiket();
  }
  


if (client) { // If a new client connects,
Serial.println("New Client."); // print a message out in the serial port
String currentLine = ""; // make a String to hold incoming data from the client
simdikizaman = millis();
eskizaman = simdikizaman;
while (client.connected() && simdikizaman - eskizaman <= zamanasimi) { // loop while the client's connected
simdikizaman = millis(); 
if (client.available()) { // if there's bytes to read from the client,
char c = client.read(); // read a byte, then
Serial.write(c); // print it out the serial monitor
header += c;
if (c == '\n') { // if the byte is a newline character
// if the current line is blank, you got two newline characters in a row.
// that's the end of the client HTTP request, so send a response:
if (currentLine.length() == 0) {
// HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
// and a content-type so the client knows what's coming, then a blank line:
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

// turns the GPIOs on and off
if (header.indexOf("GET /1/on") >= 0) {
Serial.println("Kullanıcı1 LED is on");
outputkullanici1 = "on";


Oda1();
  

  
} else if (header.indexOf("GET /1/off") >= 0) {
Serial.println("Kullanıcı1 LED is off");
outputkullanici1 = "off";
digitalWrite(kullanici1, LOW);
//------------------------------------------------
} else if (header.indexOf("GET /2/on") >= 0) {
Serial.println("Kullanıcı2 LED is on");
outputkullanici2 = "on";

Oda2();
 

} else if (header.indexOf("GET /2/off") >= 0) {
Serial.println("Kullanıcı2 LED is off");
outputkullanici2 = "off";
digitalWrite(kullanici2, LOW);
//------------------------------------------------
} else if (header.indexOf("GET /3/on") >= 0) {
Serial.println("Kullanıcı3 LED is on");
outputkullanici3 = "on";


Oda3();
  
} else if (header.indexOf("GET /3/off") >= 0) {
Serial.println("Kullanıcı3 LED is off");
outputkullanici3 = "off";
digitalWrite(kullanici3, LOW);
//------------------------------------------------
} else if (header.indexOf("GET /4/on") >= 0) {
Serial.println("Kullanıcı4 LED is on");
outputkullanici4 = "on";


Oda4();

} else if (header.indexOf("GET /4/off") >= 0) {
Serial.println("Kullanıcı4 LED is off");
outputkullanici4 = "off";
digitalWrite(kullanici4, LOW);
//------------------------------------------------
} else if (header.indexOf("GET /5/on") >= 0) {
Serial.println("Kullanıcı5 LED is on");
outputkullanici5 = "on";

Oda5();

} else if (header.indexOf("GET /5/off") >= 0) {
Serial.println("Kullanıcı5 LED is off");
outputkullanici5 = "off";
digitalWrite(kullanici5, LOW);
//------------------------------------------------
} else if (header.indexOf("GET /6/on") >= 0) {
Serial.println("Kullanıcı6 LED is on");
outputkullanici6 = "on";

Oda6();

} else if (header.indexOf("GET /6/off") >= 0) {
Serial.println("Kullanıcı6 LED is off");
outputkullanici6 = "off";
digitalWrite(kullanici6, LOW);
}



// Display the HTML web page
client.println("<!DOCTYPE html><html lang='tr'><html>");
client.println("<head><meta charset='utf-8' http-equiv='refresh' content='3;URL=http://192.168.1.100/'>");
client.println("<link rel=\"icon\" href=\"data:,\">");

client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
client.println(".button { background-color: #BF0010; border: none; color: white; padding: 16px 40px; border-radius: 60%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".buttonOff { background-color: #77878A; border: none; color: white; padding: 16px 40px; border-radius: 70%;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");

client.println("<br><img src='https://kirmiziyuz.com/wp-content/uploads/2020/11/KirmiziYeniLogo.png' data-noaft='1' jsname='HiaYvf' jsaction='load:XAeZkd;' style='width: 304px; height: 90px; margin: 0px;'><br>");

// Web Page Heading
client.println("<body><h1>Personel Çağrı Sistemi</h1>");

client.println("<table width='100%' border='0' cellspacing='1' cellpadding='1'>");
client.println("  <tr>");
client.println("    <td>");

client.println("<p><h2>Oda 1</h2></p>");
if (outputkullanici1=="off") {
client.println("<p><a href=\"/1/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/1/off\"><button class=\"button button\">Bekle</button></a></p>");
} 

client.println(" </td>");
client.println("    <td>");

client.println("<p><h2>Oda 2</h2></p>");
if (outputkullanici2=="off") {
client.println("<p><a href=\"/2/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/2/off\"><button class=\"button button\">Bekle</button></a></p>");
} 
client.println("</body></html>");

client.println("</td>");
client.println("    <td>");

client.println("<p><h2>Oda 3</h2></p>");
if (outputkullanici3=="off") {
client.println("<p><a href=\"/3/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/3/off\"><button class=\"button button\">Bekle</button></a></p>");
} 
client.println("</body></html>");

client.println(" </td>");
client.println("  </tr>");
client.println("  <tr>");
client.println("    <td>");

client.println("<p><h2>Oda 4</h2></p>");
if (outputkullanici4=="off") {
client.println("<p><a href=\"/4/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/4/off\"><button class=\"button button\">Bekle</button></a></p>");
} 
client.println("</body></html>");

client.println("</td>");
client.println("    <td>");

client.println("<p><h2>Oda 5</h2></p>");
if (outputkullanici5=="off") {
client.println("<p><a href=\"/5/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/5/off\"><button class=\"button button\">Bekle</button></a></p>");
} 
client.println("</body></html>");

client.println("</td>");
client.println("    <td>");

client.println("<p><h2>Oda 6</h2></p>");
if (outputkullanici6=="off") {
client.println("<p><a href=\"/6/on\"><button class=\"button buttonOff\">Çağır</button></a></p>");
} else {
client.println("<p><a href=\"/6/off\"><button class=\"button button\">Bekle</button></a></p>");
} 
client.println("</body></html>");


client.println("</td>");
client.println("  </tr>");
client.println("</table>");





// The HTTP response ends with another blank line
client.println();
// Break out of the while loop
break;
} else { // if you got a newline, then clear currentLine
currentLine = "";
}
} else if (c != '\r') { // if you got anything else but a carriage return character,
currentLine += c; // add it to the end of the currentLine
}
}
}
// Clear the header variable
header = "";
// Close the connection
client.stop();
Serial.println("Client disconnected.");
Serial.println("");
}
}


  
