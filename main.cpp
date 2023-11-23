#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<double> getData(vector<double>& data)
{
    cout << "Beep, boop, getting data from huge cloud..." << endl;
    vector<double> cloud = {11.2, 25.2, 90.12, 99.22};
    
    data = cloud;
    return data;
}//getData

void printData(const vector<double> data)
{
    cout << "Count: " << data.size() << endl;
    cout << "Data: ";

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << "%, ";
    }
    cout << endl;
}//printData

void plotData(const vector<double> data){
    cout << "Cool graph:" << endl;
}//plotData

int main()
{
    vector<double> data;

    getData(data);
    printData(data);
    plotData(data);

    return 0;
}//main
