#include "VideoList.h"
using namespace std;


VideoList::VideoList() : head(NULL), current(NULL) {} //intialize to null

VideoList::~VideoList() {
    if (!head) return; //empty linked list

    Node* temp = head; //temp node to itterate through linked list
    do {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != NULL);
}

void VideoList::addVideo(const std::string& videoPath) {
    Node* newNode = new Node(videoPath);

    if (!head) { //first insertion
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        current = head;
    }
    else {
        Node* tail = head->prev; //points to last node
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

string VideoList::prevVideo() {
    if (!current) {
        return NULL;
    }
    current = current->prev;
    return current->videoPath;
}

string VideoList::nextVideo() {
    if (!current) {
        return NULL;
    }
    current = current->next;
    return current->videoPath;
}

string VideoList::getCurrentVideo() const {
    return current ? current->videoPath : NULL;
}

bool VideoList::isEmpty() const {
    return head ? false : true;
}

void VideoList::printList() const {
    if (!head) {
        return;
    }

    Node* temp = head;
    do {
        cout << temp->videoPath << endl;
        temp = temp->next;
    } while (temp != head);
}

int VideoList::getSize() const {
    if (!head) {
        return 0; // List is empty
    }

    int size = 0;
    Node* temp = head;
    do {
        size++;
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again

    return size;
}

int VideoList::getCurrentNodeIndex() const {
    if (!current) {
        return -1; // Indicates the list is empty or current is not set
    }

    int index = 0;
    Node* temp = head;

    // Traverse the list and find the index of the current node
    do {
        if (temp == current) {
            return index;
        }
        index++;
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again

    return -1; // In case the current node is not found, which should not happen in normal conditions
}
