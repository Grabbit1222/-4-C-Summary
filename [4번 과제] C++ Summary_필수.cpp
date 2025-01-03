#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;

    // ������
    Book(string Title, string Author) : title(Title), author(Author) {}
};

class BookManage {
private:
    vector<Book> books;  // å�� �����ϴ� ����

public:
    // å �߰�
    void addBook(string title, string author) {
        books.push_back(Book(title, author));
    }

    // ��� å ���
    void displayAllBooks() {
        for (const Book& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    // �������� å�� �˻�
    void searchByTitle(string Title) {
        // ���� �Է� ����
        if (Title.empty()) {
            cout << "������ �Է��� �ּ���." << endl;
            return;
        }

        bool found = false;
        // ������ ��ġ�ϴ� å�� ã��
        for (const Book& book : books) {
            if (book.title == Title) {
                cout << Title << "�� ���ڴ� " << book.author << "�Դϴ�." << endl;
                found = true;
                break;  // å�� ã���� ��� ����
            }
        }

        // å�� ã�� ���� ���
        if (!found) {
            cout << Title << " ������ å�� ã�� �� �����ϴ�." << endl;
        }
    }

    // ���ڸ����� å�� �˻�
    void searchByAuthor(string Author) {
        // ���� �Է� ����
        if (Author.empty()) {
            cout << "���ڸ��� �Է��� �ּ���." << endl;
            return;
        }

        bool found = false;
        // ���ڸ��� ��ġ�ϴ� å�� ã��
        for (const Book& book : books) {
            if (book.author == Author) {
                cout << Author << "�� å�� " << book.title << "�Դϴ�." << endl;
                found = true;
                break;  // å�� ã���� ��� ����
            }
        }

        // å�� ã�� ���� ���
        if (!found) {
            cout << Author << "�� å�� ã�� �� �����ϴ�." << endl;
        }
    }
};

int main() {
    BookManage manager;

    // å �߰�
    manager.addBook("C++ Programming", "Bjarne Stroustrup");
    manager.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    manager.addBook("Learn C++", "John Doe");

    // ��� å ���
    cout << "��� å ���:" << endl;
    manager.displayAllBooks();

    // �������� �˻�
    cout << "\n�������� �˻�:" << endl;
    manager.searchByTitle("C++ Programming");

    // �۰��� �˻�
    cout << "\n���ڷ� �˻�:" << endl;
    manager.searchByAuthor("F. Scott Fitzgerald");

    // �߸��� �Է� ó�� ����
    cout << "\n�߸��� ���� �˻�:" << endl;
    manager.searchByTitle("");  // �� ���� �˻�

    cout << "\n�߸��� �۰� �˻�:" << endl;
    manager.searchByAuthor("");  // �� �۰��� �˻�

    return 0;
}
