/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab5;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

/**
 *
 * @author Jeremy
 */
public class Control {
    
    private static int PACKETSIZE = 100;
    private static int PORT = 9876;
    private static int BYTE_LENGTH = 64;
    
    private static InetAddress host;
    private static int receivePort;
    private static DatagramSocket socket;    
    
    public Control() {
        int choice = 0;
        try {
            socket = new DatagramSocket(PORT);
        }catch (Exception e){
            System.out.println(e);
        }
        
    }
    
    public String waitForRemoteGreeting(){
        String message = "";
        byte[] receiveData = new byte[BYTE_LENGTH];
        boolean waitingForGreeting = true;
        try{
            do{
                System.out.println("Listening for remote greeting: ");
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                
                do{
                    socket.receive(receivePacket);
                }while(receivePacket.getLength() == 0);
                message = new String (receivePacket.getData(), 0, receivePacket.getLength());
                
                if(message.equals("Hello server!")){
                    host = receivePacket.getAddress();
                    receivePort = receivePacket.getPort();
                    waitingForGreeting = false;
                    return new String("Received Greeting: " + message + "\n");
                }
            }while(waitingForGreeting);
        }catch(Exception e){
            System.out.println(e);
        }
        
        return null;
    }
    
    public String waitForMessage(){
        String message = "";
        byte[] receiveData = new byte[BYTE_LENGTH];
        
        try{
            System.out.println("Listening for message: ");
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            
            do{
                socket.receive(receivePacket);
            }while(receivePacket.getLength() == 0);
            
            message = new String (receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Received: " + message + "\n");
            
            host = receivePacket.getAddress();
            receivePort = receivePacket.getPort();
            
        }catch(Exception e){
            System.out.println(e);
        }
        
        return message + "\n";
    }
    
    public boolean sendMessage(String message){
        try{
            byte[] data = message.getBytes("UTF-8");
            System.out.println("Sending " + message + " to " + host.getAddress().toString() + " on port " + receivePort);
            DatagramPacket sendPacket = new DatagramPacket (data, data.length, host, receivePort);
            
            socket.send(sendPacket);
        }catch(Exception e){
            System.out.println(e);
            return false;
        }
        return true;
    }
}