#include "pbPlots.hpp"
#include "supportLib.hpp"

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
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    vector<double> x{-2, -1, 0, 1, 2, 3};
    vector<double> y{-2.6, 1.1, 2.2, 0.7, 1.1, -2.2};

    DrawScatterPlot(imageRef, 600, 400, &x, &y);

    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, "plot.png");
    DeleteImage(imageRef->image);

    vector<double> data;

    getData(data);
    printData(data);
    plotData(data);

    return 0;
}//main
