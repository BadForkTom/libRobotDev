/* libRobotDev
 * RobotDevBluetooth.h
 * Purpose: Abstracts all bluetooth functions
 * Created: 29/07/2014
 * Author(s): Jerry Luck
 * Status: UNTESTED
 */ 

#include "RobotDevUSART.h"

#ifndef ROBOTDEVBLUETOOTH_H_
#define ROBOTDEVBLUETOOTH_H_

void RDBluetoothInit(){
  RDUSARTInit();
}


void RDBluetoothSend(char* buffer, uint16_t length){
  RDUSARTSend(buffer, length);
}

char* RDBluetoothRecieve(){
  return RDUSARTRecieve();
}

void* RDBluetoothPacket(char header, char* buffer, uint16_t length){
  /* Dynamic Packet struct
   * char 	header
   * uint16_t 	data_len
   * char* 	data
   */
  //Allocate memory
  void* packet = (void*)malloc(sizeof(header)+length);
  //Copy data into malloc
  memcpy(packet, header, sizeof(header));			// header
  memcpy(packet+sizeof(header), length, sizeof(length));	// data_len
  memcpy(packet+sizeof(header)+sizeof(length), buffer, length);	// data

  return packet;
}

#endif /* ROBOTDEVBLUETOOTH_H_ */