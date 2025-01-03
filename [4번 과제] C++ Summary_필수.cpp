#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;

    // 생성자
    Book(string Title, string Author) : title(Title), author(Author) {}
};

class BookManage {
private:
    vector<Book> books;  // 책을 저장하는 벡터

public:
    // 책 추가
    void addBook(string title, string author) {
        books.push_back(Book(title, author));
    }

    // 모든 책 출력
    void displayAllBooks() {
        for (const Book& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    // 제목으로 책을 검색
    void searchByTitle(string Title) {
        // 제목 입력 검증
        if (Title.empty()) {
            cout << "제목을 입력해 주세요." << endl;
            return;
        }

        bool found = false;
        // 제목이 일치하는 책을 찾기
        for (const Book& book : books) {
            if (book.title == Title) {
                cout << Title << "의 저자는 " << book.author << "입니다." << endl;
                found = true;
                break;  // 책을 찾으면 즉시 종료
            }
        }

        // 책을 찾지 못한 경우
        if (!found) {
            cout << Title << " 제목의 책을 찾을 수 없습니다." << endl;
        }
    }

    // 저자명으로 책을 검색
    void searchByAuthor(string Author) {
        // 저자 입력 검증
        if (Author.empty()) {
            cout << "저자명을 입력해 주세요." << endl;
            return;
        }

        bool found = false;
        // 저자명이 일치하는 책을 찾기
        for (const Book& book : books) {
            if (book.author == Author) {
                cout << Author << "의 책은 " << book.title << "입니다." << endl;
                found = true;
                break;  // 책을 찾으면 즉시 종료
            }
        }

        // 책을 찾지 못한 경우
        if (!found) {
            cout << Author << "의 책을 찾을 수 없습니다." << endl;
        }
    }
};

int main() {
    BookManage manager;

    // 책 추가
    manager.addBook("C++ Programming", "Bjarne Stroustrup");
    manager.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    manager.addBook("Learn C++", "John Doe");

    // 모든 책 출력
    cout << "모든 책 목록:" << endl;
    manager.displayAllBooks();

    // 제목으로 검색
    cout << "\n제목으로 검색:" << endl;
    manager.searchByTitle("C++ Programming");

    // 작가로 검색
    cout << "\n저자로 검색:" << endl;
    manager.searchByAuthor("F. Scott Fitzgerald");

    // 잘못된 입력 처리 예시
    cout << "\n잘못된 제목 검색:" << endl;
    manager.searchByTitle("");  // 빈 제목 검색

    cout << "\n잘못된 작가 검색:" << endl;
    manager.searchByAuthor("");  // 빈 작가명 검색

    return 0;
}
