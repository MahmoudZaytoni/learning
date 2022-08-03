#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;
#define sz(v) ((int)v.size())

///////////////////////////////////// Helper Methods ////////////////////////////
vector<string> ReadFileLines(const string& path) {
	vector<string> lines;

	fstream file_handler(path);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't Open the file \n\n";
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

void WriteFileLines(const string& path,const vector<string> &lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;

	fstream file_handler(path, status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't Open the file \n\n";
		return;
	}

	for (const auto &line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

vector<string> SplitString(const string &str,const string &dilemeter = "|") {
	string line = str;

	int pos = 0;
	vector<string> fields;
	while (pos = (int)line.find(dilemeter) != -1) {
		string field = line.substr(0,pos);
		fields.push_back(field);
		line.erase(0, pos + dilemeter.size());
	}
	fields.push_back(line);
	return fields;
}

int ToInt(string str) {
	istringstream iss(str);
	int num;
	iss >> num;

	return num;
}

int ReadInt(int low, int high) {
	cout << "\nEnter numer in range " << low << " - " << high << ": ";
	int value; cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "\nERROR: invalid number ...Try again\n";
	return ReadInt(low, high);
}

int ShowReadMenu(vector<string>& choices) {
	cout << "\nMenu:\n";

	for (int ch = 0; ch < choices.size(); ch++)
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";

	return ReadInt(1, choices.size());
}

class Question {
	int question_id;
	int parent_question_id;
	int from_user_id;
	int to_user_id;
	int is_anonymous_questions;
	string question_text;
	string answer_text;
public:

    Question() :
        question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonymous_questions(1) {	
    }

	Question(const string &line){
		vector<string> substrs = SplitString(line);
		assert(substrs.size() == 7);

		question_id = ToInt(substrs[0]);
		parent_question_id = ToInt(substrs[1]);
		from_user_id = ToInt(substrs[2]);
		 to_user_id = ToInt(substrs[3]);
		is_anonymous_questions = ToInt(substrs[4]);
		question_text = substrs[5];
		answer_text = substrs[6];
	}

    string ToString() const {
        ostringstream oss;
        oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << "," << is_anonymous_questions << "," << question_text << "," << answer_text;

        return oss.str();
    }

    void PrintToQuestion() const {
        
    }	

    void PrintFromQuestion const {
        
    }
};

class User {
	int user_id; 
	string name;
	string password;
	string email;
	bool allow_anonymous_quesion;
	vector<int> quesions_id_from_me;

	void askQuesion(){}

	void responseQuestion(){}

	void print_data(){}
	

};


class UserManager {

};


class QuestionManager {

};

class Askme {
    

public:
    void Run() {
        

        vector<string> menu;
        menu.push_back("Print Quetion To Me");
        menu.push_back("Print Quetion From Me");
        menu.push_back("Answer Question");
        menu.push_back("Delete Question");
        menu.push_back("Ask Question");
        menu.push_back("List System Users");
        menu.push_back("Feed");
        menu.push_back("Logout");
    }
};







int main()
{

	return 0;
}
