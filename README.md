# Implementing-Publish-Subscribe-model-using-MQTT-protocol

<b>OBJECTIVE</b>-To publish the current values of intensity of light within an area using LDR sensor on MQTT Broker which mqtt client from anywhere at any point of time can subscribe to and use it for processing also at the same time we subscribe to another topic which give the status of led (value the user publishes at real time) and reflect that behavious of led(whether on or off) on our led connected to our Nodemcu.<br><br>
<b>DESCRIPTION</b>
•	Used HIVEMQ MQTT broker to carry out the Publish-Subscribe request.<br>
•	The values of LDR sensor is being published to the MQTT Broker under topic name "ldrval" which any mqtt client after establishing connection with mqtt server can subscribe to and process it in some way.<br>
• In addition to this We have also subscribed to topic name "ledstatus" which will give the value of ledstatus published by the user on websocket client in real time and this value of led whether on/off is reflected on the led connected to the Nodemcu.<br>
•	This all happens without any time lag and therefeore appears to be in real time.<br>
•	Also it offers an advantage that we can publish to and subscribe from the broker to different topics at same time.<br><br>
<b>ABOUT MQTT</b><br><br>
MQTT is a light-weight, open and scalable protocol for the Internet of Things. Near real time delivery of messages in an efficient, cost-effective way, even in unreliable networks, is where MQTT excels.MQTT is an open protocol, standardized by OASIS and ISO (ISO/IEC 20922:2016). It is widely adopted by many devices and companies worldwide for data exchange with constrained devices or products out in the field. MQTT keeps bandwidth at an absolute minimum and deals with unreliable networks without complex error handling and a huge implementation effort. It was made for keeping an steady line to your devices at a minimal cost supporting real push notifications and near real time communication.
