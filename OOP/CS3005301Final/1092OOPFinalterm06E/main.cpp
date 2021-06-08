#include <iostream>
#include "BasicJson.h"
using namespace std;

int main()
{
    BasicJson json;
    if(json.Parse("Test.json"))
    {
        cout<<json[0]["type"]<<endl;
        cout<<json[0]["x"]<<endl;
        cout<<json[1]["_id"]<<endl;
        json[1]["y"] = 20.0;
        cout<<json.TotalArea()<<endl;
        json.Delete("129123345");
        cout<<json.TotalArea()<<endl;
        json.Write("output.json");
    }
}
