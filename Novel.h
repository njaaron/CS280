#include <iostream>

class Novel : public Story{
private:
    int num_words;
    const int lower_limit = 101;
public:
    Novel(std::string type = "Novel", int num_words = 0) : Story(type), num_words(num_words) {
        this->type = type;
        this->num_words = num_words;
    }
    void setNumWords(int updated_num_words) { num_words = updated_num_words; }
    int getNumWords() const { return num_words; }
    void setPages(int num_words_per_page) override {
        pages = num_words / num_words_per_page;
        if (pages < lower_limit) {
            int num_pages_to_add = lower_limit - pages;
            msg = "Pages must be added to the book to satisfy the requirements of a " + type + ": " + to_string(num_pages_to_add);
        } else {
            msg = "Book is accepted.";
        }
    }
    

};