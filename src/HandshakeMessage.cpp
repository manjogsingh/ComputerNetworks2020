#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

class Handshake
{
private: static const long int serialVersionUID = 8799977982265952720L;
private: static const std::string headerContent = "P2PFILESHARINGPROJ";
private: unsigned char header;
private: unsigned char zeroBits;
private: unsigned char peerID;

public: void HandShake(int peerId) {
	this->setHeader(new unsigned char[18]);
	int indexI = 0;
	while (indexI < getHeadercontent().length()) {
		this->getHeader()[indexI] = (unsigned char)(getHeadercontent().at(indexI));
		indexI++;
	}
	this->setPeerID(new unsigned char[4]);
	this->setPeerID(ByteBuffer.allocate(4).putInt(peerId).array());
	this->setZeroBits(new unsigned char[10]);
	int indexJ = 0;
	while (indexJ < 10) {
		this->getZeroBits()[indexJ] = unsigned char;
		indexJ++;
	}
}

public: unsigned char getHeader()
{
	return header;
}

public:
	void setHeader(unsigned char header)
	{
		this->header = header;
	}

public: unsigned char getZeroBits()
{
	return zeroBits;
}

public: unsigned char getPeerID()
{
	return peerID;
}
public: void setZeroBits(unsigned char zeroBits) {
	this->zeroBits = zeroBits;
}

public:
	void setPeerID(unsigned char peerID)
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
	return "HandShake [peerID=" + to_string(this->getPeerID()) + "]";
}
};

