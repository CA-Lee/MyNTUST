#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

void print_file(string name, fstream &f)
{
    cout << "print_file" << endl;
    cout << name << endl;
    string line;
    f.seekg(0);
    while (getline(f, line))
    {
        cout << line << endl;
    }
}

struct ons
{
    string nstate;
    string output;
};

void kiss2dot(fstream &kiss, fstream &dot)
{
    cout << "kiss2dot" << endl;
    kiss.seekg(0);
    string line, r;
    int ic, oc, tc, sc;
    map<string, map<string, ons>> definition; // definition[state][input] = [next_state][output]
    while (kiss >> line)
    {
        if (line[0] == '.')
        {
            // config
            if (line == ".start_kiss")
            {
                continue;
            }
            else if (line == ".p")
            {
                kiss >> line;
            }
            else if (line == ".end_kiss")
            {
                break;
            }
            else if (line == ".i")
            {
                kiss >> ic;
            }
            else if (line == ".o")
            {
                kiss >> oc;
            }
            else if (line == ".s")
            {
                kiss >> sc;
            }
            else if (line == ".r")
            {
                kiss >> r;
            }
        }
        else
        {
            // terms
            string iv, ov, s1, s2;
            iv = line;
            kiss >> s1 >> s2 >> ov;
            definition[s1][iv].nstate = s2;
            definition[s1][iv].output = ov;
        }
    }

    //write
    dot << "digraph G {" << endl;
    dot << "rankdir=LR;" << endl
        << "INIT [shape=point];" << endl;

    for (auto &state : definition)
    {
        dot << state.first << " [label=\"" << state.first << "\"];" << endl;
    }

    dot << "INIT -> " << r << ";" << endl;
    for (auto &state : definition)
    {
        for (auto &input : state.second)
        {
            dot << state.first << "->" << input.second.nstate << " [label=\"" << input.first << "/" << input.second.output << "\"];" << endl;
        }
    }

    dot << "}" << endl;
}

struct block : map<string, block *>
{
    bool not_equal = false;
};

string i2b(int i, int ic)
{
    cout << "i2b" << endl;
    string r = "";
    for (int n = 0; n < ic; n++)
    {
        r = to_string((i >> n) & 1) + r;
    }
    return r;
}

void print_table(map<string, map<string, block>> &state_table)
{
    cout << "  ";
    for (auto &s2 : (*state_table.begin()).second)
    {
        cout << s2.first << " ";
    }
    cout << endl;
    for (auto &s1 : state_table)
    {
        cout << s1.first << " ";
        for (auto &s2 : s1.second)
        {
            cout << s2.second.not_equal << " ";
            // for (auto &input : s2.second)
            // {
            //     cout << input.second << " ";
            // }
        }
        cout << endl;
    }
}

bool minimize_group(map<string, map<string, ons>> &definition, const map<string, string> &group)
{
    cout << "minimize_group" << endl;
    // build table
    map<string, map<string, block>> state_table;
    for (auto &s1 : definition)
    {
        for (auto &s2 : definition)
        {
            for (auto &input : group)
            {
                state_table[s1.first][s2.first][input.first] = &state_table[s1.second[input.first].nstate][s2.second[input.first].nstate];
            }
        }
    }
    print_table(state_table);
    for (auto &state : definition)
    {
        map<string, string> this_group;
        for (auto &input : state.second)
        {
            this_group[input.first] = input.second.output;
        }
        if (this_group != group)
        {
            for (auto &s2 : state_table[state.first])
            {
                s2.second.not_equal = true;
            }
            for (auto &s1 : state_table)
            {
                s1.second[state.first].not_equal = true;
            }
            state_table[state.first][state.first].not_equal = false;
        }
    }
    print_table(state_table);

    cout << "start deleting" << endl;
    bool changed = false;
    do
    {
        print_table(state_table);
        changed = false;
        for (auto &s1 : state_table)
        {
            for (auto &s2 : s1.second)
            {
                for (auto &input : s2.second)
                {
                    if (!s2.second.not_equal && input.second->not_equal)
                    {
                        cout << s1.first << " " << s2.first << " " << input.first << endl;
                        s2.second.not_equal = true;
                        changed = true;
                        break;
                    }
                }
            }
        }
    } while (changed);

    cout << "start minimize" << endl;
    bool minimized = false;
    do
    {
        print_table(state_table);
        changed = false;
        for (auto &s1 : state_table)
        {
            for (auto &s2 : s1.second)
            {
                if (!s2.second.not_equal && s1.first != s2.first)
                {
                    cout << s1.first << " " << s2.first << " " << endl;
                    definition.erase(s2.first);
                    minimized = true;
                    for (auto &state : definition)
                    {
                        for (auto &input : state.second)
                        {
                            if (input.second.nstate == s2.first)
                            {
                                input.second.nstate = s1.first;
                            }
                        }
                    }

                    for (auto &s22 : state_table[s2.first])
                    {
                        s22.second.not_equal = true;
                    }
                    for (auto &s21 : state_table)
                    {
                        s21.second[s2.first].not_equal = true;
                    }
                    state_table[s2.first][s2.first].not_equal = false;

                    changed = true;
                }
            }
        }

    } while (changed);
    return minimized;
}

void minimize(fstream &fin, fstream &fout)
{
    cout << "minimize" << endl;
    string line, r;
    int ic, oc, tc, sc;
    map<string, map<string, ons>> definition; // definition[state][input] = [next_state][output]
    while (fin >> line)
    {
        if (line[0] == '.')
        {
            // config
            if (line == ".start_kiss")
            {
                continue;
            }
            else if (line == ".p")
            {
                fin >> line;
            }
            else if (line == ".end_kiss")
            {
                break;
            }
            else if (line == ".i")
            {
                fin >> ic;
            }
            else if (line == ".o")
            {
                fin >> oc;
            }
            else if (line == ".s")
            {
                fin >> sc;
            }
            else if (line == ".r")
            {
                fin >> r;
            }
        }
        else
        {
            // terms
            string iv, ov, s1, s2;
            iv = line;
            fin >> s1 >> s2 >> ov;
            definition[s1][iv].nstate = s2;
            definition[s1][iv].output = ov;
        }
    }

    set<map<string, string>> groups;
    for (auto &state : definition)
    {
        map<string, string> group;
        for (auto &input : state.second)
        {
            group[input.first] = input.second.output;
        }
        groups.insert(group);
    }
    bool changed;
    do
    {
        changed = false;
        for (auto &group : groups)
        {
            changed = changed || minimize_group(definition, group);
        }
    } while (changed);

    // write
    fout << ".start_kiss" << endl
         << ".i " << ic << endl
         << ".o " << oc << endl
         << ".p " << definition.size() * (1 << ic) << endl
         << ".s " << definition.size() << endl
         << ".r " << r << endl;
    for (auto &state : definition)
    {
        for (auto &input : state.second)
        {
            fout << input.first << " " << state.first << " " << input.second.nstate << " " << input.second.output << endl;
        }
    }
    fout << ".end_kiss" << endl;
}

int main(int argc, char *argv[])
{
    cout << "main" << endl;
    fstream kiss_in{argv[1], ios_base::in | ios_base::out},
        dot_in{"in.dot", ios_base::in | ios_base::out | ios_base::trunc},
        kiss_out{argv[2], ios_base::in | ios_base::out | ios_base::trunc},
        dot_out{argv[3], ios_base::in | ios_base::out | ios_base::trunc};
    minimize(kiss_in, kiss_out);
    kiss2dot(kiss_in, dot_in);
    kiss2dot(kiss_out, dot_out);
    print_file("kiss_in", kiss_in);
    print_file("dot_in", dot_in);
    print_file("kiss_out", kiss_out);
    print_file("dot_out", dot_out);
}
