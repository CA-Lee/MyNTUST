#include <iostream>
#include <cstring>

using namespace std;

string decrypt(string input)
{

    bool debug = true;
    debug = false;

    string elements[input.size()];
    int e_i = 0;
    //split
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            elements[e_i++] = input[i];
        }
        else if (input[i] == '<')
        {
            elements[e_i++] = input[i];
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            int c = 0;
            while (!(input[i] == ']' && c == 1))
            {
                if (input[i] == '[')
                    c++;
                if (input[i] == ']')
                    c--;
                elements[e_i] += input[i++];
            }
            elements[e_i] += input[i];
            e_i++;
        }
    }

    if (debug)
    {
        for (int i = 0; i < e_i; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // swap
    for (int i = 0; i < e_i; i++)
    {
        if (elements[i] == "<")
        {
            string t = elements[i - 1];
            elements[i - 1] = elements[i + 1];
            elements[i + 1] = t;
            elements[i] = "";
        }
    }

    // extract
    for (int i = 0; i < e_i; i++)
    {
        if (elements[i][0] >= '0' && elements[i][0] <= '9')
        {
            int n = stoi(elements[i]);
            // cut head
            elements[i] = elements[i].substr(elements[i].find('['));
            // cut tail
            elements[i] = elements[i].substr(0, elements[i].size());
            elements[i] = decrypt(elements[i]);
            string b = elements[i];
            for (int j = 1; j < n; j++)
            {
                elements[i] += b;
            }
        }
    }

    string r;
    for (int i = 0; i < e_i; i++)
    {
        r += elements[i];
    }
    return r;
}

int main()
{
    string input;
    while (cin >> input)
    {
        cout << decrypt(input) << endl;
    }
}