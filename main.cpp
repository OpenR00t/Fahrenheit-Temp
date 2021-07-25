#include <iostream>
#include <fstream>
using namespace std;

class CityTemps {
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

int main() {
   
   return 0;
}