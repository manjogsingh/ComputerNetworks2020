#include "sys/Socket.h""
#include "HandshakeMessage.h"
#include "PeerProcess.h" //use of object
#include "HavePayload.h"
#include "PiecePayload.h"
#include "RequestPayload.h"
#include <stdio.h>
#include <serial.h>
#include <fstream>
#include "Message.cpp"
#include <boost/stacktrace.hpp>
using namespace std;

class MessageReader {
	Socket socket;
	PeerProcess peerProc;
	bool isHandshakeDone = false;

public: MessageReader(Socket socket, PeerProcess peerProc) throw IOException{
	this->setSocket(socket);
	this->setPeerProc(peerProc);
}
public: void setSocket(Socket socket) {
	this->setSocket = socket;
}
public: Socket getSocket() {
	return socket;
}
public: PeerProcess getPeerProc() {
		  return peerProc;
	  }
public: void setPeerProc(PeerProcess peerProc) {
	this->getPeerProc = peerProc;
}
public: void setHandshakeDone(bool isHandshakeDone) {
	this->isHandshakeDone = isHandshakeDone;
}
//object is referecned from the peerprocess
public: Object readObject() throw IOException{
	istream inputStream (this->getSocket().getInputStream());
	  if (isHandshakeDone) {
		  for (; (!this->getPeerProc().isExit() && inputStream.gcount() < 4);) {
		  }
		  unsigned char * lengthBytes = new unsigned char[4];
		  istream.read(lengthBytes, 4);
		  int length = stringbuf; /////?????
		  for (; inputStream.gcount() < length;) {
		  }
		  unsigned char * typeBuffer = new unsigned char[1];
		  try {
			  istream.read(typeBuffer, 1);
		  }
		  catch (IOException e) {
			  e.boost::stacktrace::stacktrace();
			  throw e;
		  }
		  unsigned char type = typeBuffer[0];
		  unsigned char * payload = NULL;
		  if ((length > 1)) {
			  payload = new unsigned char[length - 1];
			  int receivedBytes = 0;
			  for (; receivedBytes < (length - 1) : ) {
				  try {
					  receivedBytes = receivedBytes + istream.read(payload, receivedBytes, length - 1);
				  }
				  catch (IOException e) {
					  e.boost::stacktrace::stacktrace();
					  throw e;
				  }
			  }
		  }
	  }
	  Message msg = NULL;
	  switch (int type) {
	  case 4:
		  HavePayload havePayLoad = new HavePayload(payload);
		  msg = new Message(length, type, havePayLoad, NULL);
		  break;
	  case 5:
		  BitfieldPayload bitFieldPayLoad = new BitfieldPayload(payload);
		  msg = new Message(length, type, bitFieldPayLoad, NULL);
		  break;
	  case 6:
		  RequestPayload requestPayLoad = new RequestPayload(payload);
		  msg = new Message(length, type, requestPayLoad, NULL);
		  break;
	  case 7:
		  PiecePayload piecePayLoad = new PiecePayload(payload);
		  msg = new Message(length, type, piecePayLoad, NULL);
		  break;
	  default:
		  msg = new Message(length, type, payload);
		  break;
	  }
	  return msg;	  
	  }
		else {
		unsigned char header[] = new byte[18];
		try {
			istream.read(header, 18);
		}
		catch (IOException e) {
			e.boost::stacktrace::stacktrace();
			throw e;
		}
		unsigned char zerobits[] = new byte[10];
		try {
			istream.read(zerobits, 10);
		}
		catch (IOException e) {
			e.boost::stacktrace::stacktrace();
			throw e;
		}
		unsigned char peerId[] = new byte[4];
		try {
			istream.read(peerId);
		}
		catch (IOException e) {
			e.boost::stacktrace::stacktrace();
			throw e;
		}
		this->setHandshakeDone(true);
		return new HandShake(stringbuf.wrap(peerId).getInt());
		}






	


};