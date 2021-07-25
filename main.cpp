#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

class CityTemps { // establish class to store city data
    public:
        void SetName(string cityName);
        void SetFahrenheit(int FTemp);
        void SetCelsius (int CTemp);
        string GetName();
        int GetFahrenheit();
        int GetCelsius();

    private:
        string name;
        int fahrenheit;
        int celsius;
};

void CityTemps::SetName(string cityName)  {
    name = cityName;
}

void CityTemps::SetFahrenheit(int Ftemp) {
    fahrenheit = Ftemp;
}

void CityTemps::SetCelsius(int Ctemp) {
    celsius = Ctemp;
}

string CityTemps::GetName() {
    return name;
}

int CityTemps::GetFahrenheit() {
    return fahrenheit;
}

int CityTemps::GetCelsius() {
    return celsius;
}

void WriteFile(ostream& outStream, string writeName, int writeTemp) { // function to simplify writing to output
    outStream << writeName << " " << writeTemp << endl;
}

int main() {
   vector<CityTemps> cityList; // establish vector for city data
   CityTemps currCity; // temporary city object to house incoming data
   string currCityName;
   int currCityFtemp;
   int currCityCtemp;
   ifstream inFS;
   ofstream outFS;
   int i;

   inFS.open("FahrenheitTemperature.txt"); // open initial file

   if (!inFS.is_open()) { // error check for failed file opening
       cout << "Couldn't open FahrenheitTemperature.txt" << endl;
       return 1;
   }
   inFS >> currCityName; // store data
   inFS >> currCityFtemp;
   while(!inFS.fail()) {
       //cout << currCityName << " " << currCityFtemp << endl; //line to check the data during testing
       currCity.SetName(currCityName);
       currCity.SetFahrenheit(currCityFtemp);
       cityList.push_back(currCity);
       inFS >> currCityName;
       inFS >> currCityFtemp;
   }
   inFS.close(); // close out initial file

   for ( i =  0; i < cityList.size(); ++i) { //run temperature conversion and store to vector
       currCityCtemp = 0;
       currCityFtemp = cityList.at(i).GetFahrenheit();
       currCityCtemp = (currCityFtemp - 32) * (0.5555);
       cityList.at(i).SetCelsius(currCityCtemp);
       //cout << cityList.at(i).GetName() << " " << cityList.at(i).GetFahrenheit() << " " << cityList.at(i).GetCelsius() << endl; //line to check the data during testing
    }

    outFS.open("CelsiusTemperature.txt"); // open or create output destination
    if (!outFS.is_open()) { // error check file open
      cout << "Couldn't open CelsiusTemperature.txt" << endl;
      return 1;
   }

   for (i = 0; i < cityList.size(); ++i) { //write to output file
       currCityCtemp = cityList.at(i).GetCelsius();
       currCityName = cityList.at(i).GetName();
       WriteFile(outFS, currCityName, currCityCtemp);
   }
   outFS.close();//close out output file

}