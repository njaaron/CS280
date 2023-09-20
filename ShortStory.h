using namespace std;
class ShortStory : public Story {
private:
    const int lower_limit = 5;
    const int upper_limit = 50;
    int num_words;
public:
    ShortStory(std::string type = "Short Story", int num_words = 0) : Story(type), num_words(num_words) {
            this->type = type;
        this->num_words = num_words;}
    void setNumWords(int updated_num_words) {
        num_words = updated_num_words;
    }
    int getNumWords() const {
        return num_words;
    }
    void setPages(int num_words_per_page) override {
        pages = num_words/num_words_per_page;
        if (pages < lower_limit) {
            int shortfall = lower_limit - pages;
            msg = "Pages must be added to the book to satisfy the requirements of a " + type + ": " + to_string(shortfall);
        } else if (pages > upper_limit) {
            int excess = pages - upper_limit;
            msg = "Pages must be cut from the book to satisfy the requirements of a " + type +": " + to_string(excess);
        } else {
            msg = "Book is accepted.";
        }
    }
};
