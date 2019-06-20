#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Worker{
private:
    char *name;
    int salary;
    void deleteWorker();
    void copyWorker(const Worker&);
public:
    Worker(const char*, const int);
    Worker(const Worker&);
    ~Worker();
    Worker& operator=(const Worker&);

    const char* getName()const {return name;}
    int getSalary()const{return salary;}
};

void Worker::deleteWorker(){
    delete[] name;
}

void Worker::copyWorker(const Worker& other){
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    salary = other.salary;
}

Worker::Worker(const char* _name="", const int _salary=0){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    salary = _salary;
}

Worker::Worker(const Worker& other){
    copyWorker(other);
}

Worker::~Worker(){
    deleteWorker();
}

Worker& Worker::operator=(const Worker& other){
    if(this!=&other){
        deleteWorker();
        copyWorker(other);
    }
    return *this;
}

class SalaryWorker: public Worker{
private:
    char* job;
    int hours;
public:
    SalaryWorker(const char*, const int, const char*,
                 const int);
    SalaryWorker(const SalaryWorker&);
    SalaryWorker& operator=(const SalaryWorker&);
    ~SalaryWorker();

    int getPaid()const;
    void print()const;
    void writeIn(const char*)const;
};

SalaryWorker::SalaryWorker(const char* _name="",
const int _salary=0,const char* _job="", const int _hours=0):
                   Worker(_name, _salary){
    job = new char[strlen(_job)+1];
    strcpy(job, _job);
    hours = _hours;
}

SalaryWorker::SalaryWorker(const SalaryWorker& other):
                        Worker(other){
    job = new char[strlen(other.job)+1];
    strcpy(job, other.job);
    hours = other.hours;
}

SalaryWorker& SalaryWorker::operator=(
                    const SalaryWorker& other){
    if(this!=&other){
        Worker::operator=(other);
        delete[] job;
        job = new char[strlen(other.job)+1];
        strcpy(job, other.job);
        hours = other.hours;
    }return *this;
}

SalaryWorker::~SalaryWorker(){
    delete[] job;
}

int SalaryWorker::getPaid() const{
    return 40*getSalary();
}

void SalaryWorker::print() const{
    cout<<"Worker: "<<getName()<<"\n"
        <<"Job: "<<job<<"\n"
        <<"Salary: "<<getSalary()<<"\n";
}

void SalaryWorker::writeIn(const char* filename) const{
    ofstream fout(filename, ios::app);
    fout<<getName()<<" "<<job<<endl;
    fout.close();
}

int main(){
    int n;
    cin>>n;
    SalaryWorker* sw = new SalaryWorker[n];
    char name[128], job[128];
    int hours, salary;
    for(int i=0; i<n; i++){
        cin>>name>>salary>>job>>hours;
        sw[i]=SalaryWorker(name, salary, job, hours);

    }

    const char* filename="workers";
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(sw[i].getPaid()>sw[j].getPaid())
                swap(sw[i], sw[j]);
        }
        sw[i].writeIn(filename);
    }
    delete[] sw;


    return 0;
}

















