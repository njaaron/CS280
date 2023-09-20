#include <string>
using namespace std;
class Story {
protected:
    string title;
    string author;
    int pages = 0;
    string type;
    string msg;
public:
    Story(std::string type) : type(type) {}
    virtual ~Story() {}
    void setTitle(std::string updatedTitle) { title = updatedTitle; }
    std::string getTitle() const { return title; }
    void setAuthor(std::string updatedAuthor) { author = updatedAuthor; }
    std::string getAuthor() const { return author; }
    virtual void setPages(int num_words_per_page) = 0;
    int getPages() const { return pages; }
    void setType(std::string updatedType) { type = updatedType; }
    std::string getType() const { return type; }
    void setMsg(std::string updatedMsg) { msg = updatedMsg; }
    std::string getMsg() const { return msg; }

};
