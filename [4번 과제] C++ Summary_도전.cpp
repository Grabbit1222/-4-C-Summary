#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Book {
public:
    string title;
    string author;

    // ������
    Book(string Title, string Author) : title(Title), author(Author) {}
};

class BorrowManager {
private:
    unordered_map<string, int> stock;

public:
    // å�� �ʱ� ��� �����ϴ� �Լ�
    void initializeStock(Book book, int quantity = 3) {
        stock[book.title] = quantity; // å ������ Ű�� �Ͽ� ��� ���� ����
    }

    // å�� �뿩�ϴ� �Լ�
    void borrowBook(string title) {
        // ������ �ִ��� Ȯ���ϰ� ��� �ִ� ��� �뿩 ó��
        auto it = stock.find(title);
        if (it != stock.end()) { // å ������ �ִ� ���
            if (it->second > 0) {
                it->second--; // �뿩 �� ��� ����
                cout << title << " �뿩�Ǿ����ϴ�." << endl;
            }
            else {
                cout << "��� �����ϴ�." << endl; // ��� ���� ���
            }
        }
        else {
            cout << "�ش� å�� �����ϴ�." << endl; // å ������ ���� ���
        }
    }

    // å�� �ݳ��ϴ� �Լ�
    void returnBook(string title) {
        // ������ �ִ��� Ȯ���ϰ� �ݳ� ó��
        auto it = stock.find(title);
        if (it != stock.end()) { // å ������ �ִ� ���
            it->second++; // �ݳ� �� ��� ����
            cout << title << " �ݳ��Ǿ����ϴ�." << endl;
        }
        else {
            cout << "�ش� å�� �����ϴ�." << endl; // å ������ ���� ���
        }
    }

    // ��� å�� ��� ����ϴ� �Լ�
    void displayStock() {
        for (unordered_map<string, int>::iterator it = stock.begin(); it != stock.end(); ++it) {
            cout << "å �̸�: " << it->first << ", ���: " << it->second << endl;
        }
    }
};


class BookManager {
private:
    vector<Book> books;  // å�� �����ϴ� ����

protected:
    // å ������ ���� å�� ã�� �Լ�
    // �ݺ��ڸ� ����� ���͸� ��ȸ�ϸ� å�� ã��
    // �ܺο����� ������ �� ������ ���ο����� ����
    Book* findBookByTitle(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                return &(*it); // å�� ã���� �ش� å�� ������ ��ȯ
            }
        }
        return nullptr; // å�� ã�� ���ϸ� nullptr ��ȯ
    }

    // å ���ڸ� ���� å�� ã�� �Լ�
    // findBookByTitle�� �����ϰ� �۵��ϳ�, ���ڷ� å�� ã��
    // �ܺο����� ������ �� ������ ���ο����� ����
    Book* findBookByAuthor(string author) {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->author == author) {
                return &(*it); // å�� ã���� �ش� å�� ������ ��ȯ
            }
        }
        return nullptr; // å�� ã�� ���ϸ� nullptr ��ȯ
    }

public:
    // å�� �߰��ϴ� �Լ�
    // å ����� ���ڸ� �Է¹޾� books ���Ϳ� å�� �߰�
    void addBook(string title, string author) {
        books.push_back(Book(title, author)); // �� å�� books ���Ϳ� �߰�
    }

    // ��� å�� ����ϴ� �Լ�
    // books ���Ϳ� ����� ��� å�� ����� ���ڸ� ���
    void displayAllBooks() {
        for (const Book& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    // å �������� å�� ã�� public �Լ�
    // findBookByTitle�� ȣ���� å�� ã��, ã�� å�� �����͸� ��ȯ
    // �ܺο��� å�� ã���� �� �� ����ϴ� �Լ�
    Book* getBookByTitle(string title) {
        return findBookByTitle(title); // ������ findBookByTitle ȣ��
    }

    // å ���ڸ����� å�� ã�� public �Լ�
    // findBookByAuthor�� ȣ���� å�� ã��, ã�� å�� �����͸� ��ȯ
    Book* getBookByAuthor(string author) {
        return findBookByAuthor(author); // ������ findBookByAuthor ȣ��
    }
};