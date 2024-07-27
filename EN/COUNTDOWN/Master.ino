#include <WiFi.h>
#include <Wire.h>

const char* ssid = "FOXTEK";
const char* password = "12345678";
const int I2C_SLAVE_ADDR = 8; // Adresse I2C de l'Arduino Nano Every

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("AP démarré");
  Serial.println(WiFi.softAPIP());
  server.begin();

  Wire.begin(); // Initialiser l'I2C en tant que maître
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Nouveau client connecté");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Envoyer la réponse HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<!DOCTYPE html><html>");
            client.println("<head><style>");
            client.println("body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background-color: #121212; color: #fff; text-align: center; padding: 50px; font-size: 32px; }");
            client.println("h1 { color: #00ff99; font-size: 48px; }");
            client.println(".container { display: flex; flex-direction: column; align-items: center; }");
            client.println(".input-row { display: flex; justify-content: center; margin-bottom: 20px; }");
            client.println(".input-row div { margin: 0 10px; }");
            client.println("label { display: block; margin-bottom: 10px; font-size: 32px; }");
            client.println("input[type='text'] { padding: 20px; width: 150px; text-align: center; background-color: #333; color: #fff; border: 1px solid #00ff99; border-radius: 10px; font-size: 32px; }");
            client.println(".button-row { display: flex; justify-content: center; margin-top: 20px; }");
            client.println(".button-row form { margin: 0 10px; }");
            client.println("input[type='submit'] { padding: 20px 40px; background-color: #00ff99; color: black; border: none; border-radius: 10px; font-size: 32px; cursor: pointer; }");
            client.println("input[type='submit']:hover { background-color: #00cc79; }");
            client.println("</style></head>");
            client.println("<body><h1>FX486 Countdown Control</h1>");
            client.println("<div class='container'>");
            client.println("<form action='/set'>");
            client.println("<div class='input-row'>");
            client.println("<div><label for='hours'>Heures</label><input type='text' id='hours' name='hours' maxlength='2'></div>");
            client.println("<div><label for='minutes'>Minutes</label><input type='text' id='minutes' name='minutes' maxlength='2'></div>");
            client.println("<div><label for='seconds'>Secondes</label><input type='text' id='seconds' name='seconds' maxlength='2'></div>");
            client.println("<div><label for='milliseconds'>Millisecondes</label><input type='text' id='milliseconds' name='milliseconds' maxlength='3'></div>");
            client.println("</div>");
            client.println("<div class='button-row'>");
            client.println("<input type='submit' value='SET'>");
            client.println("</div>");
            client.println("</form>");
            client.println("<div class='button-row'>");
            client.println("<form action='/start'><input type='submit' value='START'></form>");
            client.println("<form action='/pause'><input type='submit' value='PAUSE'></form>");
            client.println("<form action='/resume'><input type='submit' value='RESUME'></form>");
            client.println("<form action='/reset'><input type='submit' value='RESET'></form>");
            client.println("</div></div>");
            client.println("</body></html>");
            client.println();
            Serial.println("Page HTML envoyée");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        if (currentLine.startsWith("GET /set?")) {
          int hours = getParameterValue(currentLine, "hours");
          int minutes = getParameterValue(currentLine, "minutes");
          int seconds = getParameterValue(currentLine, "seconds");
          int milliseconds = getParameterValue(currentLine, "milliseconds");

          Serial.print("Heures: ");
          Serial.println(hours);
          Serial.print("Minutes: ");
          Serial.println(minutes);
          Serial.print("Secondes: ");
          Serial.println(seconds);
          Serial.print("Millisecondes: ");
          Serial.println(milliseconds);

          uint8_t buffer[8];
          buffer[0] = hours;
          buffer[1] = minutes;
          buffer[2] = seconds;
          buffer[3] = milliseconds >> 8;
          buffer[4] = milliseconds & 0xFF;

          Wire.beginTransmission(I2C_SLAVE_ADDR);
          Wire.write(buffer, 5);
          Wire.write('S'); // Commande SET
          Wire.endTransmission();
          Serial.println("Données SET envoyées");
        }

        if (currentLine.startsWith("GET /start")) {
          Wire.beginTransmission(I2C_SLAVE_ADDR);
          Wire.write('T'); // Commande START
          Wire.endTransmission();
          Serial.println("Commande START envoyée");
        }

        if (currentLine.startsWith("GET /pause")) {
          Wire.beginTransmission(I2C_SLAVE_ADDR);
          Wire.write('P'); // Commande PAUSE
          Wire.endTransmission();
          Serial.println("Commande PAUSE envoyée");
        }

        if (currentLine.startsWith("GET /resume")) {
          Wire.beginTransmission(I2C_SLAVE_ADDR);
          Wire.write('U'); // Commande RESUME (utilisation de 'U' pour ne pas confondre avec 'R' de RESET)
          Wire.endTransmission();
          Serial.println("Commande RESUME envoyée");
        }

        if (currentLine.startsWith("GET /reset")) {
          Wire.beginTransmission(I2C_SLAVE_ADDR);
          Wire.write('R'); // Commande RESET
          Wire.endTransmission();
          Serial.println("Commande RESET envoyée");
        }
      }
    }
    client.stop();
    Serial.println("Client déconnecté");
  }
}

int getParameterValue(String line, String paramName) {
  int startIndex = line.indexOf(paramName + "=") + paramName.length() + 1;
  int endIndex = line.indexOf("&", startIndex);
  if (endIndex == -1) {
    endIndex = line.indexOf(" ", startIndex);
  }
  if (endIndex == -1) {
    endIndex = line.length();
  }
  return line.substring(startIndex, endIndex).toInt();
}
