#include <iostream>
#include <fstream>
#include <ctime>

time_t now = time(0);
char* today = ctime(&now);


struct Logging {

		std::string level;
		std::string message;


		void log(std::string x, std::string m){
				std::fstream logfile {"logfile.log", std::ios_base::app};
				logfile << "Level: " << x << ", Message: " << m << " Time: " << today << "\n";
				std::cout << "action logged\n";
	};

};


void error(std::string l,std::string m){
		Logging logger;
		logger.log(l,m); 
};


//all items below here need to be removed for production
//
//BEGIN TESTING


void hello(){
		std::cout << "Hello World\n";
	//	Logging logger;
		//logger.log("warning","File Run successfully");
		error("Critical","File encountered a horrible error");
};

void end(){
		std::cout << "End of application\n";
		error("Warning","file ran again");
}

int main (){
		hello();
		end();


		return 0;

};
