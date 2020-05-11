using System;                                                       //library for basic things
using System.IO;
using System.IO.Ports;                                              //library for Serial Port
using System.Threading;                                             //library for thread

class SerialCommunicationComputerMCU      //class for serial communication between the computer and the MCU(microcontroller)
{
    
    static void Main(string[] args){
        /*VARIABLE FOR COMMUNICATION BETWEEN KOCIEMBA -> SERIALCOMMUNICATION -> PHYSICAL SERIAL PORT*/
        string strCOMNumber = "";               //string for port com communication (ex : COM17 or COM6)
            string strFrameFromKociemba = "";       //string for frame which we want send to the MCU
        /*PIPE BETWEEN KOCIEMBA AND SERIALCOMMUNICATION*/
        if (Console.IsInputRedirected){
            Console.SetIn(new StreamReader(Console.OpenStandardInput(8192)));
            while (Console.In.Peek() != -1){
                strFrameFromKociemba = Console.In.ReadLine();
            }
                strCOMNumber = args[0].ToString();
            }
            else{
                if (args.Length != 0){
                    strCOMNumber = args[0].ToString();
                    strFrameFromKociemba = args[1].ToString();
            }
            else
            {
                    Console.WriteLine("This program needs a parameter");
                }
        }

        /*CREATE A NEW OBJECT SERIAL*/
        SerialPort SerialPortComMCU = new SerialPort(strCOMNumber);

        /*CREATE A NEW HANDLER FOR RECEIVE DATA ONLY WHEN THERE ARE HERE*/
        

            /*SETUP THE SERIAL COMMUNICATION*/
            SerialPortComMCU.BaudRate = 115200;             //Speed communication at 115200 bauds
            SerialPortComMCU.Parity = Parity.None;          //Parity disable
            SerialPortComMCU.StopBits = StopBits.One;       //1 Stop bit 
            SerialPortComMCU.DataBits = 8;                  //data Send/Receive on 8 bits
            SerialPortComMCU.Handshake = Handshake.None;    //Handshake  disable
            SerialPortComMCU.RtsEnable = true;              //Rts Enable
  
            SerialPortComMCU.Open();                        //Open the serial port
            SerialPortComMCU.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);   //creation of the handler for receive data with the SerialPort
            SerialPortComMCU.WriteLine(strFrameFromKociemba);            //Send the frame on the serial port for solve the cube
            SerialPortComMCU.Close();                                    //Close the serial port
    }

            private static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e){      //handler for interrupt on receive data for Serial Communication
                SerialPort sp = (SerialPort)sender;
                string indata = sp.ReadExisting();
                Console.WriteLine(indata);
            }
}
