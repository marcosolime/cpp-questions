#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string title;
    int year;

    void print() {
        cout << title << " (" << year << ")" << endl;
    }
};

/*
- Manual new[] / delete[]
- easy to forget deletion -> memory leak
- fixed size
- exception unsafe
*/
/*
int main() {
    int n = 3;

    Book* books = new Book[n];

    books[0] = {"1984", 1949};
    books[1] = {"Dune", 1965};
    books[2] = {"The Hobbit", 1937};

    for (int i = 0; i< n; i++) {
        cout << books[i].title << " (" << books[i].year << ")" << endl;
    }

    delete[] books;
}
*/

int main(){

    //vector<Book> books;
    Book book = {"Fran", 1098};
    book.print();

    vector<Book> books;
    books.push_back(book);
    books.push_back({"Al", 394});
    books.push_back({"Jim", 044});

    for (auto book : books) {
        cout << book.title << " (" << book.year << ")" << endl;
    }
}