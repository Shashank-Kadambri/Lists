#include <iostream>
#include <iomanip>
#include <limits>
#include "sll.h"

#define CLEAR_INPUT_BUFFER(c) \
    c.clear(); \
    c.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// template <class T>
// class SLLNode {
//     private:
//         // T data;
//         // SLLNode<T>* next;
//     public:
//         T data;
//         SLLNode<T>* next;

//         SLLNode(void) {
//             data = 0;
//             next = NULL;
//         }
//         SLLNode(T data) {
//             this -> data = data;
//             next = NULL;
//         }
//         ~SLLNode(void) {
//             delete next;
//         }
//         // T getData(void) {
//         //     return this -> data;
//         // }
// };

// template <class T>
// class SLList {
//     private:
//         SLLNode<T>* head;
//         SLLNode<T>* tail;
//     public:
//         SLList(void) {
//             head = tail = NULL;
//         }
//         ~SLList(void) {
//             delete head;
//             delete tail;
//         }
//         void addAtHead(T data) {
//             SLLNode<T>* temp = new SLLNode<T>;

//             if(head == NULL) {
//                 temp -> data = data;
//                 temp -> next = NULL;
//                 head = tail = temp;
//             } else {
//                 temp -> data = data;
//                 temp -> next = head;
//                 head = temp;
//             }
//             return;
//         }
//         void addAtTail(T data) {
//             SLLNode<T>* temp;

//             if(tail == NULL) {
//                 temp = new SLLNode<T>(data);
//                 head = tail = temp;
//             } else {
//                 temp = new SLLNode<T>(data);
//                 tail -> next = temp;
//                 tail = temp;
//             }
//             return;
//         }
//         void traverse(void) {
//             if(head == NULL) {
//                 std::cout << "\nNo node is present in the linked list.\n";
//                 return;
//             } else if(head == tail) {
//                 std::cout << head -> data;
//                 return;
//             } else {
//                 SLLNode<T>* temp = head;

//                 while(temp != NULL) {
//                     std::cout << temp -> data << "  ";
//                     temp = temp -> next;
//                 }
//             }
//             return;
//         }
//         void deleteFromHead(void) {
//             if(head == NULL) {
//                 return;
//             } else if(head == tail) {
//                 delete head;
//                 delete tail;
//                 head = NULL;
//                 return;
//             } else {
//                 SLLNode<T>* temp;
//                 temp = head;
//                 head = head -> next;
//                 delete temp;
//                 return;
//             }
//         }
//         void deleteFromTail(void) {
//             if(head == NULL) {
//                 return;
//             } else if(head == tail) {
//                 delete head;
//                 delete tail;
//                 head = NULL;
//                 return;
//             } else {
//                 SLLNode<T>* temp = head;

//                 while(temp -> next -> next != NULL) {
//                    temp = temp -> next;
//                 }
//                 delete tail;
//                 temp -> next = NULL;
//                 tail = temp;
//                 return;
//             }
//         }
//         int search(T data) {
//             int index = 0;

//             if(head == NULL) {
//                 return -2;
//             } else if(head == tail) {
//                 if(head -> data == data) {
//                     return index; 
//                 } else {
//                     return -1;
//                 }
//             } else {
//                 // if(tail -> next == NULL) {
//                 //     std::cout << "\nlasdnkl\n";
//                 // }
//                 // std::cout << "\nhi\n";
//                 SLLNode<T>* temp = head;
                
//                 while(temp != NULL) {
//                     if(temp -> data == data) {
//                         return index;
//                     } else {
//                         ++index;
//                         // std::cout << "yo\n";
//                         temp = temp -> next;
//                     }
//                 }
//                 // if(temp -> data == data) {
//                 //     return ++index;
//                 // }
//             }
//             return -1;
//         }
// };

int main(void) {
    int choice;
    SLList<int> sll;

    while(true) {
        std::cout << "\t\tSINGLY LINKED LIST DEMO PROGRAM\n\n\t\t"
                << "----------MENU----------\n\t\t"
                << "1. Add at head\n\t\t"
                << "2. Add at tail\n\t\t"
                << "3. Delete from head\n\t\t"
                << "4. Delete from tail\n\t\t"
                << "5. Traverse the list\n\t\t"
                << "6. Search the list\n\t\t"
                << "7. Exit the program\n\n"
                << "Enter your choice: ";
        while(!(std::cin >> choice) || !(choice >= 1 && choice <= 7)) {
            std::cout << "Please enter a valid choice: ";
            CLEAR_INPUT_BUFFER(std::cin);
        }
        CLEAR_INPUT_BUFFER(std::cin);
        
        switch(choice) {
            case 1 : {
                int data;

                std::cout << "Enter the data (any number): ";
                while(!(std::cin >> data)) {
                    std::cout << "Please enter a valid number: ";
                    CLEAR_INPUT_BUFFER(std::cin);
                }
                CLEAR_INPUT_BUFFER(std::cin);
                sll.addAtHead(data);
            }
            break;

            case 2 : {
                int data;

                std::cout << "Enter the data (any number): ";
                while(!(std::cin >> data)) {
                    std::cout << "Please enter a valid number: ";
                    CLEAR_INPUT_BUFFER(std::cin);
                }
                CLEAR_INPUT_BUFFER(std::cin);
                sll.addAtTail(data);
            }
            break;

            case 3 : {
                sll.deleteFromHead();
            }
            break;

            case 4 : {
                sll.deleteFromTail();
            }
            break;

            case 5 : {
                std::cout << "\nLinked List:\n";
                sll.traverse();
            }
            break;

            case 6 : {
                int data, index;

                std::cout << "Enter the data to be searched (any number) : ";
                while(!(std::cin >> data)) {
                    std::cout << "Please enter a valid number: ";
                    CLEAR_INPUT_BUFFER(std::cin);
                }
                CLEAR_INPUT_BUFFER(std::cin);
                index = sll.search(data);
                if(index == -1) {
                    std::cout << "\nValue not found.\n";
                } else if(index == -2) {
                    std::cout << "\nNo node present in the linked list.\n";
                } else {
                    std::cout << "\nValue found at node number: " << index + 1;
                }
            }
            break;

            case 7 : {
                char ch;

                std::cout << "\nSure to exit? (Y/N): ";
                std::cin >> ch;
                if(tolower(ch) == 'y') {
                    exit(0);
                } else {
                    std::cout << "\n\n\n\n" << std::endl;
                    std::cout << std::setw(80) << std::setfill('*') << std::endl;
                    std::cout << "\n\n";
                    continue;
                }
            }
            break;
        }
        std::cout << "\n\n\n\n" << std::endl;
        std::cout << std::setw(80) << std::setfill('*') << std::endl;
        std::cout << "\n\n";
    }
    return 0;
}