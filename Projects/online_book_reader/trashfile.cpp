
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
