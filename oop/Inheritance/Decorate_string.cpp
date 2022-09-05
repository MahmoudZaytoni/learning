#include<iostream>
#include<string>

using namespace std;

class DecorateString : public string {
    using string::string;
    using std::string::operator=;
public:
    void Decorate() {
        string str = *this;
        str = "<<[[" + str + "]]>>";
        this->assign(str);
    }

};

int main()
{
    DecorateString str = "I am learning CS";
    str.Decorate();
    cout << str;
    return 0;
}