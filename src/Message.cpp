#include <iostream>
#include <cstddef>
#include <string>
#include "Payload.cpp"
//need to include payload and messagetype class
enum class byte : unsigned char {};
enum class MessageType { CHOKE = 0, UNCHOKE = 1, INTERESTED = 2, NOT_INTERESTED = 3, HAVE = 4, BITFIELD = 5, REQUEST = 6, PIECE = 7 }
class Message {
	static const long int serialVersionUID = 8799977982265952720L;
	int length;
	byte type;
	byte[] payload;
	MessageType messageType;
	Payload msgPayload;

public: Message() {
	super();
}
public: Message(int lenght, byte type, byte[] payload) {
	this->setlength(length);
	this->setType(type);
	this->setPayload(payload);
	setMsgType(type);
}
public: int getLenght() {
		  return length;
	  }
public: void setlength(int lenght) {
	this->length = length;
}
public: byte getType() {
	return type;
}
public: void setType(byte type) {
	this->type = type;
}
public: byte[] getPayload() {
		  return payload;
	  }
public: void setPayload(byte[] payload) {
	this->payload = payload;
}
public: long setSerialversionuid() {
	return serialVersionUID;
}

public: void setMsgType(byte type) {

	switch (int type) {
	case 0:
		this->setMessageType(MessageType.CHOKE);
		break;
	case 1:
		this->setMessageType(MessageType.UNCHOKE);
		break;
	case 2:
		this->setMessageType(MessageType.INTERESTED);
		break;
	case 3:
		this->setMessageType(MessageType.NOT_INTERESTED);
		break;
	case 4:
		this->setMessageType(MessageType.HAVE);
		break;
	case 5:
		this->setMessageType(MessageType.BITFIELD);
		break;
	case 6:
		this->setMessageType(MessageType.REQUEST);
		break;
	case 7:
		this->setMessageType(MessageType.PIECE);
		break;
	}
}
public: MessageType getMessageType() {
		return messageType;
	}
public: void setMessageType(messageType) {
		  this->messageType = messageType;
	  }

public: Payload getMsgPayload() {
		  return msgPayload;
	  }

public: void setMsgPayload(Payload msgPayload) {
		  this->msgPayload = msgPayload;
	  }

public: String toString() override{
		  return "Message [length=" + this->getLength() + ", type=" + this->getMessageType() + "]";
	  }


};

