#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include "Directory.h"
#include "Directory.h" // intentional
#include "File.h"
#include "File.h" // intentional
#include "Flags.h"
#include "Flags.h" // intentional

int cout = 0; // won't compile if headers don't follow convention

void printLine() {
    std::cout << "--------------------------\n";
}

void printHeader(std::string label) {
    size_t padLeft = (26 - label.length()) / 2;

    printLine();
    std::cout << std::setw(padLeft) << " " << label << std::endl;
    printLine();
}

void printRInfo(int count, size_t bytes, std::string path) {
    std::cout << std::left << std::setw(2) << (count >= 0 ? std::to_string(count) : "")
              << std::right << std::setw(12) << std::to_string(bytes) + " bytes "
              << std::left << path << std::right << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; ++i)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    /*************************************************
     * Creating a directory structure
     **************************************************/
    printHeader("DIRECTORY STRUCTURE");

    seneca::Directory* root = new seneca::Directory("");
    seneca::File* scene_img = new seneca::File("scene.jpg", "This is an image of a beautiful landscape.");
    seneca::File* flag_img = new seneca::File("flag.jpg", "A Canadian flag.");
    seneca::File* flag_img_test = new seneca::File("flag.jpg", "A Canadian flag.");
    seneca::Directory* videos = new seneca::Directory("videos/");
    seneca::File* harry_potter = new seneca::File("harry-potter.webm", "Compilation of the best moments from all 8 Harry Potter movies.");

    *root += scene_img;
    *root += flag_img;
    *videos += harry_potter;
    *root += videos;

    try {
        *root += flag_img_test;
    } catch(...) {
        std::cout << "**EXPECTED EXCEPTION: flag.jpg image already exists in the root\n" << std::endl;
        delete flag_img_test;
    }

    std::cout << "Directory structure created successfully" << std::endl;

    ::printLine();

    /*************************************************
     * Directory & file information
     **************************************************/
    ::printHeader("RESOURCE INFO");
    ::printRInfo(root->count(), root->size(), root->path());
    ::printRInfo(scene_img->count(), scene_img->size(), scene_img->path());
    ::printRInfo(flag_img->count(), flag_img->size(), flag_img->path());
    ::printRInfo(videos->count(), videos->size(), videos->path());
    ::printRInfo(harry_potter->count(), harry_potter->size(), harry_potter->path());
    ::printLine();

    /*************************************************
     * Finding a file in a directory
     **************************************************/
    ::printHeader("FIND");

    std::vector<seneca::OpFlags> oflags;

    if(!root->find(".flag.jpg")) {
        std::cout << "**EXPECTED ERROR: File .flag.jpg not found in " << root->path() << "\n" << std::endl;
    }

    if(root->find("flag.jpg")) {
        std::cout << "Found " << flag_img->name() << " in " << root->path() << " with the ALL flag\n" << std::endl;
    }

    if (!root->find("harry-potter.webm")) {
        std::cout << "**EXPECTED ERROR: File harry-potter.webm not found in " << root->path() << " non-recursively\n" << std::endl;
    }

    oflags.push_back(seneca::OpFlags::RECURSIVE);
    if (root->find("harry-potter.webm", oflags)) {
        std::cout << "Found " << harry_potter->name() << " in " << root->path() << " recursively\n"
                  << std::endl;
    }

    ::printLine();

    delete root;

    return cout;
}
