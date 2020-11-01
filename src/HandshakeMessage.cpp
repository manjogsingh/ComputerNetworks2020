#include <iostream>
#include <cstddef>
#include <string>

enum class byte : unsigned char {};

class Handshake
{
private: static const long int serialVersionUID = 8799977982265952720L;
private: static const std::string headerContent = "P2PFILESHARINGPROJ";
private: byte header;
private: byte zeroBits;
private: byte peerID;

public: void HandShake(int peerId) {
	this->setHeader(new byte[18]);
	int indexI = 0;
	while (indexI < getHeadercontent().length()) {
		this->getHeader()[indexI] = (byte)(getHeadercontent().at(indexI));
		indexI++;
	}
	this->setPeerID(new byte[4]);
	this->setPeerID(ByteBuffer.allocate(4).putInt(peerId).array());
	this->setZeroBits(new byte[10]);
	int indexJ = 0;
	while (indexJ < 10) {
		this->getZeroBits()[indexJ] = byte;
		indexJ++;
	}
}

public: byte getHeader()
{
	return header;
}

public:
	void setHeader(byte header)
	{
		this->header = header;
	}

public: byte getZeroBits()
{
	return zeroBits;
}

public: byte getPeerID()
{
	return peerID;
}
public: void setZeroBits(byte zeroBits) {
	this->zeroBits = zeroBits;
}

public:
	void setPeerID(byte peerID)
	{
		this->peerID = peerID;
	}

public: static long int getSerialversionuid() {
	return serialVersionUID;
}
public: static std::string getHeadercontent() {
	return headerContent;
}


public: std::string toString() override {
	return "HandShake [peerID=" + std::to_string(this->getPeerID()) + "]";
}
};

