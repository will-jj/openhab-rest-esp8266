# openhab-rest-esp8266

Runs on esp8266.

Connects to wifi, sends state changes to openhab's rest API

## Usage

```
const char* host = "10.1.1.85";  //Use the IP. No DNS lookups
const int port = 8080;

Openhab client = Openhab(host, port);

```

To send a state change:

```
  String item_name = "Fridge_Temperature"; // Item name in openhab
  String state = "34.3";   //Strings only at this time.
  String response = client.put(item_name, state);
  Serial.print(response);
```

response will be either the http response from the server, or an error message if unable to connect.



## Licence
 
GPL V3
