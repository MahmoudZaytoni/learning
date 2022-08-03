#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <string>
#include <sstream>
#include <ostream>
#include <cstring>
#include <map>
using namespace std;


vector<string> ReadFileLines(const string &path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}

void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (const auto &line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

vector<string> SplitString(const string &line, const string &dil = ",") {
    string record = line;
    vector<string> fields;

    int pos = 0;
    string substr;
    while ((pos = (int)record.find(dil)) != -1) {
        substr = record.substr(0,pos);
        fields.push_back(substr);
        record.erase(0,pos + dil.length());
    }
    fields.push_back(substr);
    return fields;
}

int toInt(const string &str) {
    istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

int ReadInt(int low, int high) {
	cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}

int ShowReadMenu(const vector<string> &choices) {
	cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}
//////////////////////////////////////////////////////////////

class Book {
    int book_id; 
    string author;
    string text;
public:
    Book() : book_id(-1) {
    }

    Book(const string &line) {
        vector<string> fields = SplitString(line, ",");
        assert(fields.size() == 3);
        book_id = toInt(fields[0]);
        author = fields[1];
        text = fields[2];
    }

    string ToString(const string &dil = ",") const {
        ostringstream oss;
        oss << book_id << dil << author << dil << text;

        return oss.str();
    }

    void SetAuthor(const string &author) {
        this->author = author;
    }

    const string& GetAuthor() const {
        return author;
    }

    void SetText(const string &text) {
        this->text = text;
    }

    const string& GetText() const {
        return text;
    }

    void SetPageNumber(int num) {
        book_id = num;
    }

    const int GetPageNumber() const {
        return book_id;
    }
};

class User {
private:
    int user_id;
    string user_name;
    string password;
    string email;
    vector<Book> books; 

public:
    User() : user_id(-1) {
    }

    User(const string &line) {
        vector<string> fields = SplitString(line, ",");
        assert(fields.size() == 4);
        user_id = toInt(fields[0]);
        user_name = fields[1];
        password = fields[2];
        email = fields[3];
    }

    string ToString(const string &dil = ",") const {
        ostringstream oss;
        oss << user_id << dil << user_name << dil << password << dil << email;

        return oss.str();
    }

    void ReadUser(const string &name, int id) {
        SetName(name);
        SetId(id);
        
        string s;
        cout << "Enter Password\n";
        cin >> s;
        SetPassword(s);

        cout << "Enter Email\n";
        cin >> s;
        SetEmail(s);
    }

    void SetName(const string &name) {
        user_name = name;
    }

    const string& GetName() const {
        return user_name; 
    }

    void SetId(const int id) {
       this->user_id = id;
    }

    int GetId() const {
        return user_id;
    }

    void SetPassword(const string& password) {
        this->password = password;
    }

    const string& GetPassword() const {
        return password;
    }

    void SetEmail(const string &email) {
        this->email = email;
    }

    const string& GetEmail() const {
        return email;
    }
};

class Admin {
    string name;
    string password;
    string email;
    int id;
};

class UsersManager {
    map<string,User> username_userobject_map;
    User current_user;
    int last_id;
public:
    UsersManager() {
        last_id = 0;
    }

    void LoadDatabase() {
        last_id = 0;
        username_userobject_map.clear();

        vector<string> records = ReadFileLines("user.txt");
        for (auto &record : records) {
            User user(record);
            last_id = max(last_id, user.GetId());
            username_userobject_map[user.GetName()] = user;
        }
    }

    void UpdateDataBase(const User &user) {
        string record = user.ToString();
        vector<string> records(1, record);
        WriteFileLines("user.txt", records);
    }

    void DoLogin() {
        LoadDatabase();

        string name, pass;
        while (true) {
            cout << "Enter user name and password: ";
            cin >> name >> pass;

            bool exist = username_userobject_map.count(name);

            if (!exist) {
                cout << "\nInvalid User name or password. Try Again\n\n";
                continue;
            }
            const User& user_exist = username_userobject_map[name];
            exist &= (pass == user_exist.GetPassword());

            if (!exist) {
                cout << "\nIvalid User name or password. Try Again\n\n";
                continue;
            }

            current_user = user_exist;
            break;
        }
    }

    void DoSignUp() {
        string user_name;
        while (true) {
            cout << "Enter user name. (No spaces)\n";
            cin >> user_name;

            if (username_userobject_map.count(user_name))
                cout << "Already used. Try Again\n";
            else
                break;
        }

        current_user.ReadUser(user_name, ++last_id);
        username_userobject_map[current_user.GetName()] = current_user;

        UpdateDataBase(current_user);
    }
};

class Page {
    int page_number;
    string header;
    string text;

public:
    Page() : page_number(-1) {}

    Page(const string &line) {
        vector<string> fields = SplitString(line, ",");
        assert(fields.size() == 3);
        page_number = toInt(fields[0]);
        header = fields[1];
        text = fields[2];
    }

    string ToString(const string &dil = ",") const {
        ostringstream oss;
        oss << header << dil << text << dil << page_number;

        return oss.str();
    }

    void SetHeader(const string &header) {
        this->header = header;
    }

    const string& GetHeader() const {
        return header;
    }

    void SetText(const string &text) {
        this->text = text;
    }

    const string& GetText() const {
        return text;
    }

    void SetPageNumber(int num) {
        page_number = num;
    }

    const int GetPageNumber() const {
        return page_number;
    }
};






int main()
{
    UsersManager u;
    u.DoLogin();
    return 0;
}
