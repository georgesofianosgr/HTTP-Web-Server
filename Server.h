#ifndef _SERVER_H
#define _SERVER_H

#include <WinSock2.h>
#include <string>
#include <fstream>

#define AppVersion "1.0beta"
#define DEFAULT_PORT "80"
#define BUFFER_SIZE 1024*5 // 5KB
#define ACC_EXT_NUM 48
#define OS_TYPE_NUM 9

using std::string;

// ERROR HANDLING
extern std::ofstream logger;
extern void logError(string msg,int GetLastError=0);
extern string ToString(int data);


class Server
{
public:
	Server(void);

	// Main Functions
	void Init(); // Initialize Server
	void Start(); // Start server
	void Stop(); // Close Server
	void Communicate(); // Main Loop.
	void ErrorQuit(); // Quit And Display An Error Message


	// IPs Input/Output
	  void setServerIP(string ip);
	  void setClientIP(string ip);
	string getServerIP();
	string getClientIP();

	// Main CMD Display
	struct CommandLine{
		CommandLine();
		void Display();
		void Add(string msg);
		void Clear();
		// Content
		string _cmdMessage;
	}*CMD;


private:
	// Initialize
	void loadContentType();
	void loadOSTypes();
	void resetError();
	
	// Browser Request Manipulation
	void checkRequest();
	void getCommands(); 
	bool isDirectory();
	bool checkFileExists();
	bool checkFileExtension();
	void checkDataLenght();


	 // Pass Info To Variables
	 int getFileRequest();
	 int getUserAgent();
	 int getBrowserInfo();
	 int getOSInfo();
	 int getAcceptedContent();

	 // Header Creation
	 void createHeader();
	 void resetHeader();
	 string _header;
	 string _headerStatus;
	 string _headerType;
	 string _redirectLocation;
	 string _contentLenght;

	// Communication Functions
	 string getMessage(); // Receive Browser Requests
	    int sendFile();
	   void sendHeader(); // Send Header Info
	   void sendMessage(string msg); // Send Text Files
	   int  sendData(char*data); // Send Other Type Files In Binary
	   void closeConnection(); // Close Connections


	// Initialize
	     int _handleReturn;
	    WORD _socketVersion;
	 WSADATA _wsaData;
	  SOCKET _listeningSocket;
 	  SOCKET _connectionSocket;
	addrinfo _hints,*_result;
	     int _maxConnections;

		 
	// Communication Content
		 int _sendData;
		 int _bytesReceived;
		 int _bytesSend;


	//  Server Info
	string _serverIP;
	string _clientIP;
	string _port;
	string _acceptedExtension[ACC_EXT_NUM];
	string _contentType[ACC_EXT_NUM];
	string _OSType[OS_TYPE_NUM];

	// Browser Request Data
	string _browserData;
	string _fileName;
	string _filePath;
	string _fileExt;
	string _fileType;
	   int _fileSize;
	string _userAgentData;
	string _browserInfo;
	string _OSInfo;

};

#endif

