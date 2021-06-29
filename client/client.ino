#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Wifi ağ adınızı ve Wifi Şifrenizi girin
const char* ssid = "OZASLAN";
const char* password = "ganime.91";

// Statik IP adresinizi, ağ geçidinizi ve alt ağ maskenizi girin
IPAddress local_IP(192, 168, 1, 101); //---- her client için ayrı ip tanımlanacak
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

const int button = 2; 

void setup() {
WiFi.mode (WIFI_OFF);//wifi ap mod kapatma
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(100);
}
Serial.println(WiFi.localIP());
Serial.begin(115200);

// Çıkış Birimlerini Tanımlama
pinMode (button,INPUT_PULLUP);

if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA YAPILANDIRILAMADI!");
}

// SSID ve şifre ile Wi-Fi ağına bağlanılıyor
Serial.print("Şu Ağa Bağlanılıyor: ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(100);
Serial.print(".");
}

// Yerel IP adresiniz yazdırılıyor ve web sunucusunu başlatılıyor
Serial.println("");
Serial.println("WiFi Bağlandi.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}

void loop(){
if (digitalRead(button) == LOW){
Serial.println("1 Numaralı Butona Basıldı");
HTTPClient http;  //Declare an object of class HTTPClient
http.begin("http://192.168.1.100/1/on");  //----sunucu ipsi ve hangi client se onun numarası yazılacak 
int httpCode = http.GET();
//  if (httpCode > 0) { //Check the returning code
// String payload = http.getString();   //Get the request response payload
// Serial.println(payload);             //Print the response payload
Serial.flush(); //Bu fonksiyon gönderilen seri veri iletiminin tamamlanmasını beklemek için kullanılır. Herhangi bir parametre almaz ve geriye değer döndürmez.
   }
}
