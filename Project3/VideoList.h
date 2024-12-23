#pragma once
#include <string>
#include <iostream>

class VideoList {
private:
    // Node structure for the linked list
    struct Node {
        std::string videoPath;
        Node* next;
        Node* prev;

        Node(const std::string& path) : videoPath(path), next(nullptr), prev(nullptr) {}
    };

    Node* head; // Points to the first node
    Node* current; // Points to the currently playing node

public:
    // Constructor
    VideoList();

    // Destructor
    ~VideoList();

    // Add a video path to the list
    void addVideo(const std::string& videoPath);

    // Move to the next video
    std::string nextVideo();

    // Move to the previous video
    std::string prevVideo();

    // Get the current video
    std::string getCurrentVideo() const;

    // Check if the list is empty
    bool isEmpty() const;

    // Print all video paths in the list
    void printList() const;

    int getSize() const;

    int getCurrentNodeIndex() const;
};