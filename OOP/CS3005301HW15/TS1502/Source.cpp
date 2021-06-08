#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class UC {};
class IC {};

class datum {
public:
	string author;
	string title;
	int ed;
	datum(string a, string b, int c)
		:author(a), title(b), ed(c) {
	};
	friend bool operator<(const datum& a, const datum& b) {
		if (a.author > b.author)return false;
		if (a.author == b.author && a.title > b.title)return false;
		if (a.author == b.author && a.title == b.title)return a.ed < b.ed;
		return true;
	}
	friend bool operator==(const datum& a, const datum& b) {
		return !(a < b) && !(b < a);
	}
};


vector<string> get_arg(istream& is) {
	string s;

	if (!is.eof()) {
		is >> s;
		vector<string> r{ s };
		if (s[0] == '"' && *s.rbegin() != '"') {
			while (1)
			{
				if (!is.eof()) {
					is >> s;
					(*r.rbegin()) += " " + s;
					if (s.find('"') != -1)break;
				}
				else throw IC();

			}
		}
		for_each(r.begin(), r.end(), [](string& a)
			{a= (a[0] == '"' ? a.substr(1, a.size() - 2) : a); });
		vector<string> r1 = get_arg(is);
		r.insert(r.end(), r1.begin(), r1.end());
		return r;
	}
	else
	{
		return vector<string>();
	}
}

int main() {
	string cmd;
	set<datum> lib;
	while (getline(cin, cmd))
	{
		if (cmd.size() == 0)continue;
		string key;
		stringstream ss(cmd);
		ss >> key;
		try {
			if (key == "Insert") {
				vector<string> args = get_arg(ss);
				if (args.size() < 3)throw IC();
				if (find_if(lib.begin(), lib.end(),
					[&args](datum c) {
						return c.author == args[1] &&
							c.title == args[0] &&
							c.ed == stoi(args[2]); }) != lib.end()) {
					cout << "Datum already exist." << endl;
				}
				else {
					lib.insert(datum(args[1], args[0], stoi(args[2]))					);
					cout << "Insert " << args[1]<< "'s "
						<< args[0] << ", Edition: "
						<< args[2] << "." << endl;
				}
			}
			else if (key == "Delete") {
				if (!(ss >> key))throw UC();
				if (key == "Edition") {
					vector<string> args = get_arg(ss);
					if (args.size() < 3)throw IC();
					auto b = find_if(lib.begin(), lib.end(),
						[&args](datum c) {
							return c.author == args[1] &&
								c.title == args[0] &&
								c.ed == stoi(args[2]); });
					if (b == lib.end()) {

						cout << "Datum doesn't exist." << endl;
					}
					else {
						cout << "Delete " << (*b).author << "'s "
							<< (*b).title << ", Edition: " << (*b).ed << "." << endl;
						lib.erase(b);
					}
				}
				else if (key == "Book") {
					vector<string> args = get_arg(ss);
					if (args.size() < 2)throw IC();
					int c = lib.size();
					while (true)
					{

						auto b = find_if(lib.begin(), lib.end(),
							[&args](datum c) {
								return c.author == args[1] &&
									c.title == args[0]; });
						if (b == lib.end()) {
							break;
						}
						else {
							cout << "Delete " << (*b).author << "'s "
								<< (*b).title <<"." << endl;
							lib.erase(b);
						}
					}
					if (c == lib.size())cout << "Book doesn't exist." << endl;
				}
				else throw UC();

			}
			else if (key == "Find") {
				if (!(ss >> key))throw UC();
				if (key == "Book") {
					vector<string> args = get_arg(ss);
					if (args.size() < 2)throw IC();
					set<int> vs;

					for (auto& i : lib) {
						if (i.author == args[1] && i.title == args[0])vs.insert(i.ed);
					}

					if (vs.size()) {
						cout << "Title: " << args[0] << "\tAuthor: " << args[1] << "\tEdition: ";
						for (auto& i : vs) {
							if (i != *vs.begin())cout << ", " << i;
							else cout << i;
						}
						cout << endl;
					}
					else {
						cout << "Book doesn't exist." << endl;
					}

				}
				else if (key=="Author") {
					vector<string> args = get_arg(ss);
					if (args.size() < 1)throw IC();
					set<string> vs;
					
					for (auto& i : lib) {
						if (i.author == args[0])vs.insert(i.title);
					}

					if (vs.size()) {
						cout << args[0]<<"'s Books: ";
						for (auto& i :vs) {
							if (i!=*vs.begin())cout << ", " <<i;
							else cout << i;
						}
						cout << endl;
					}
					else {
						cout << "No book found." << endl;
					}
				}
			}
			else if (key == "Sort") {
			if (!(ss >> key))throw UC();
			if (key == "by") {
				if (!(ss >> key))throw UC();
				if (key == "Title") {
					vector<datum> v(lib.begin(), lib.end());
					sort(v.begin(), v.end(),
						[](const datum& a, const datum& b) {
							return a.title < b.title || (a.title == b.title && a.author < b.author); });
					cout  << "Title: " << v[0].title << "\tAuthor: " << v[0].author << "\tEdition: " << v[0].ed;

					for (auto i = v.begin()+1; i != v.end();i++) {
						if ((*i).author != (*(i - 1)).author || (*i).title != (*(i - 1)).title) {
							cout << endl<< "Title: " << (*i).title << "\tAuthor: " << (*i).author << "\tEdition: " << (*i).ed  ;
							
						}
						else {
							cout << ", " << (*i).ed;
						}
					}
					cout << endl;

				}
				else if (key == "Author") {
					vector<datum> v(lib.begin(), lib.end());
					sort(v.begin(), v.end(),
						[](const datum& a, const datum& b) {
							return a.author < b.author || (a.author == b.author	 && a.title < b.title); });
					cout  << "Title: " << v[0].title << "\tAuthor: " << v[0].author << "\tEdition: " << v[0].ed;

					for (auto i = v.begin() + 1; i != v.end(); i++) {
						if ((*i).author != (*(i - 1)).author || (*i).title != (*(i - 1)).title) {
							cout << endl << "Title: " << (*i).title << "\tAuthor: " << (*i).author << "\tEdition: " << (*i).ed;

						}
						else {
							cout << ", " << (*i).ed;
						}
					}
					cout << endl;
				}
			}
			}
			else {
				throw UC();
			}
		}
		catch (UC& e) {
			cout << "Unknown Command." << endl;
		}
		catch (IC& e) {
			cout << "Incomplete Command." << endl;
		}
	}
}