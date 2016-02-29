# openhab-rest-esp8266

Runs on esp8266.

Connects to wifi AP

Sends state changes to openhab's rest API

## Usage

```
const char* host = "10.1.1.85";
const int port = 8080;

Openhab client = Openhab(host, port);

```

To send a state change:

```
  String item_name = "Test_Thing"; // Item name is openhab
  String response = client.put(item_name, value);
  Serial.print(response);
```
