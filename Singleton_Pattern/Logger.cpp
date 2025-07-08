#include<iostream>
#include<string>
#include<mutex>


using namespace std;

class Logger {
    private:
        static Logger* instance;
        static mutex mtx;
        Logger(){} // Private Constructor

    public:
        static Logger* getInstance() {
            if(instance == nullptr){
                lock_guard<mutex> lock(mtx);
                if(instance == nullptr)
                    instance = new Logger();
            }
            return instance;
        }

        void log(const string& msg){
            cout<<"[LOG]: "<<msg<<endl;
        }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;

int main(){
    
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();

    logger1->log("This is First");
    logger2->log("This is Second");

    if(logger1 == logger2)
        cout<<"Same Logger"<<endl;
    else
        cout<<"Different Logger"<<endl;


    return 0;
}