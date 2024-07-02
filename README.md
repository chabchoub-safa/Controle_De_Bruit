# ESP32 WiFi MQTT Noise Sensor


This project uses an ESP32 to measure the noise level using an analog sensor and then sends the data to an MQTT broker via WiFi.
The measured values are published on the "project/noise" topic of the MQTT broker "broker.emqx.io".
The code also configures the WiFi connection and handles MQTT communication to ensure continuous transmission of noise data.


 Ce projet utilise un ESP32 pour mesurer le niveau de bruit à l'aide d'un capteur analogique, puis envoie les données à un broker MQTT via WiFi.
 Les valeurs mesurées sont publiées sur le topic "projet/bruit" du broker MQTT "broker.emqx.io".
 Le code configure également la connexion WiFi et gère la communication MQTT pour assurer une transmission continue des données de bruit.
