#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Book {
public:
    string title;
    string author;

    // 생성자
    Book(string Title, string Author) : title(Title), author(Author) {}
};

class BorrowManager {
private:
    unordered_map<string, int> stock;

public:
    // 책의 초기 재고를 설정하는 함수
    void initializeStock(Book book, int quantity = 3) {
        stock[book.title] = quantity; // 책 제목을 키로 하여 재고 수량 설정
    }

    // 책을 대여하는 함수
    void borrowBook(string title) {
        // 제목이 있는지 확인하고 재고가 있는 경우 대여 처리
        auto it = stock.find(title);
        if (it != stock.end()) { // 책 제목이 있는 경우
            if (it->second > 0) {
                it->second--; // 대여 시 재고 감소
                cout << title << " 대여되었습니다." << endl;
            }
            else {
                cout << "재고가 없습니다." << endl; // 재고가 없는 경우
            }
        }
        else {
            cout << "해당 책이 없습니다." << endl; // 책 제목이 없는 경우
        }
    }

    // 책을 반납하는 함수
    void returnBook(string title) {
        // 제목이 있는지 확인하고 반납 처리
        auto it = stock.find(title);
        if (it != stock.end()) { // 책 제목이 있는 경우
            it->second++; // 반납 시 재고 증가
            cout << title << " 반납되었습니다." << endl;
        }
        else {
            cout << "해당 책이 없습니다." << endl; // 책 제목이 없는 경우
        }
    }

    // 모든 책의 재고를 출력하는 함수
    void displayStock() {
        for (unordered_map<string, int>::iterator it = stock.begin(); it != stock.end(); ++it) {
            cout << "책 이름: " << it->first << ", 재고: " << it->second << endl;
        }
    }
};


class BookManager {
private:
    vector<Book> books;  // 책을 저장하는 벡터

protected:
    // 책 제목을 통해 책을 찾는 함수
    // 반복자를 사용해 벡터를 순회하며 책을 찾음
    // 외부에서는 접근할 수 없으며 내부에서만 사용됨
    Book* findBookByTitle(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                return &(*it); // 책을 찾으면 해당 책의 포인터 반환
            }
        }
        return nullptr; // 책을 찾지 못하면 nullptr 반환
    }

    // 책 저자를 통해 책을 찾는 함수
    // findBookByTitle과 유사하게 작동하나, 저자로 책을 찾음
    // 외부에서는 접근할 수 없으며 내부에서만 사용됨
    Book* findBookByAuthor(string author) {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->author == author) {
                return &(*it); // 책을 찾으면 해당 책의 포인터 반환
            }
        }
        return nullptr; // 책을 찾지 못하면 nullptr 반환
    }

public:
    // 책을 추가하는 함수
    // 책 제목과 저자를 입력받아 books 벡터에 책을 추가
    void addBook(string title, string author) {
        books.push_back(Book(title, author)); // 새 책을 books 벡터에 추가
    }

    // 모든 책을 출력하는 함수
    // books 벡터에 저장된 모든 책의 제목과 저자를 출력
    void displayAllBooks() {
        for (const Book& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    // 책 제목으로 책을 찾는 public 함수
    // findBookByTitle을 호출해 책을 찾고, 찾은 책의 포인터를 반환
    // 외부에서 책을 찾고자 할 때 사용하는 함수
    Book* getBookByTitle(string title) {
        return findBookByTitle(title); // 내부의 findBookByTitle 호출
    }

    // 책 저자명으로 책을 찾는 public 함수
    // findBookByAuthor를 호출해 책을 찾고, 찾은 책의 포인터를 반환
    Book* getBookByAuthor(string author) {
        return findBookByAuthor(author); // 내부의 findBookByAuthor 호출
    }
};