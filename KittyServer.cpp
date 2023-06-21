#include "KittyServer.h"

WiFiServer server(80);

KittyServer::KittyServer() {
  delay(10);
}

void KittyServer::setup() 
{
  // Set web server port number to 80
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("Connected.");
  server.begin();
}

void KittyServer::handleClient() 
{
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // HTML code
            client.println(R"HTML(
<!DOCTYPE html>
<html>
<head>
    <title>Kitt's Kitchen Kullanıcı Arayüzü</title>
    <style>
        body {
            background-color: #f4f4f4;
            font-family: Arial, sans-serif;
        }
        
        h2 {
            color: #333;
            text-align: center;
            padding-top: 20px;
        }
        
        form {
            max-width: 400px;
            margin: 0 auto;
            padding: 20px;
            background-color: #fff;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        
        label {
            display: block;
            font-weight: bold;
            margin-bottom: 10px;
            color: #666;
        }
        
        input[type="number"],
        input[type="text"] {
            width: 100%;
            padding: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
            margin-bottom: 10px;
        }
        
        input[type="button"] {
            background-color: #4caf50;
            color: #fff;
            border: none;
            padding: 10px 20px;
            font-size: 16px;
            border-radius: 4px;
            cursor: pointer;
        }
        
        input[type="button"]:hover {
            background-color: #45a049;
        }
        
        input[type="checkbox"] {
            margin-bottom: 10px;
        }
    </style>
    <script>
        function kaydet() {
            var saat1 = parseInt(document.getElementById("saat1").value);
            var dakika1 = parseInt(document.getElementById("dakika1").value);
            var saat2 = parseInt(document.getElementById("saat2").value);
            var dakika2 = parseInt(document.getElementById("dakika2").value);
            var miktar = parseInt(document.getElementById("miktar").value);
            var aksamKontrol = Boolean(document.getElementById("dakikaCheck1").value);
            var sabahKontrol = Boolean(document.getElementById("dakikaCheck2").value);
            
            var miktarSonuc = miktar;
            
            document.getElementById("sonuc").innerHTML = sonuc;
        }
        
        function dok() {
            var mamaDok = Boolean("true");
        }
    </script>
</head>
<body>
    <h2>Kitt's Kitchen</h2>
    <form>
        <label for="saat1">Akşam Mama Saati:</label>
        <label for="saat1">Saat:</label>
        <input type="number" id="saat1" name="saat1" min="12" max="23" required>
        <label for="dakika1">Dakika:</label>
        <input type="number" id="dakika1" name="dakika1" min="0" max="59" required>
        <input type="checkbox" id="dakikaCheck1" name="dakikaCheck1"><br><br>

        <label for="saat2">Sabah Mama Saati:</label>
        <label for="saat1">Saat:</label>
        <input type="number" id="saat2" name="saat2" min="0" max="12" required>
        <label for="dakika2">Dakika:</label>
        <input type="number" id="dakika2" name="dakika2" min="0" max="59" required>
        <input type="checkbox" id="dakikaCheck2" name="dakikaCheck2"><br><br>

        <label for="miktar">Miktar:</label>
        <input type="text" id="miktar" name="miktar" pattern="[0-9]+" required><br><br>

        <input type="button" value="Kaydet" onclick="kaydet()">
        <input type="button" value="Mama Dök" onclick="dok()">
    </form>
</body>
</html>
)HTML");

            client.println("</body></html>");
            client.println();
           break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
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
