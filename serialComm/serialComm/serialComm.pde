//This processing file reads byte-values from the serial port.
//At the same time, the data from server port is send to the serial port.
//The serial port properties can be set by an external file which is under "data\setting.txt"
import processing.net.*;
import processing.serial.*;

// Define for setting file
String[] lines;
int a = 0;//index of comport
int b = 1;//index of board rate
int c = 2;//index of server port
int index = 0;
// Define your Serial port from the Arduino IDE, tools - serialport
String portname = "COM1";
Serial serialPort;
int BR = 9600;
String buf="";
int cr = 13;  // ASCII return   == 13 //
int lf = 10;  // ASCII linefeed == 10 //
// the Network stuff
int port = 9001;
Server myServer;
//for incoming serial data
String inString;
int charvalue;
//ASCII code for sending
byte eol = 0;
int NEWLINE = 10;
byte nullByte = 0;
 
void setup(){
  lines = loadStrings("setting.txt");
  if (index < lines.length) {
    String[] comport = split(lines[a], '=');
    portname = comport[1];
    print("COMPORT=");
    println(comport[1]);
    String[] br = split(lines[b], '=');
    BR = int(br[1]);
    print("BR=");
    println(br[1]);
    String[] serverPort = split(lines[c], '=');
    port = int(serverPort[1]);
    print("SERVER PORT=");
    println(serverPort[1]);
  }    

 size(20, 20);
  myServer = new Server(this, port);
  serialPort = new Serial(this, portname, BR);
  println("set up");
}
 
void draw() 
{
    frame.setLocation(-1000,-1000); 
    
    Client thisClient = myServer.available();   
    if (thisClient != null) {
      if (thisClient.available() > 0) 
      {
          //println("mesage from: " + thisClient.ip() + " : " + thisClient.readChar());
          //inputString = thisClient.readStringUntil(nullByte);
          //print("iString : ");
         // println(thisClient.readChar());
          serialPort.write(thisClient.readChar());
         // serialPort.write(thisClient.readStringUntil(nullByte));
        }
    }
}
//for incoming message
void serialEvent(Serial p) 
{  
  //println(serialPort.readString());
  inString = ( serialPort.readString());
  charvalue = inString.charAt(0);
  //if(charvalue != cr) //carriage return
  if(charvalue != lf) //line feed, for flash
  {
    buf += inString;
    
  }
  else
  {
      //println(buf);
      myServer.write(buf);
      //endTransmission();     
      buf = "";
  }
}
void endTransmission() {
  myServer.write(eol);   
}

