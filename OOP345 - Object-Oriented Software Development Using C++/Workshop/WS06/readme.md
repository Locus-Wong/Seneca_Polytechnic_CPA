# Workshop 6: STL Containers

In this workshop, you store polymorphic objects in an STL container. 

You are going to create a mini UNIX-like filesystem that supports a few common commands.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- manage polymorphic objects using the vector container of the STL
- move a dynamically allocated object into a container
- code a range-based iteration on the objects in a container
- report and handle an exception



## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.



## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.




## Part 1 (0%)

The first portion of this workshop consists of modules:
- `w6` (supplied)
- `Flags` (supplied)
- `Resource` (supplied)
- `File`
- `Directory`

Enclose all your source code within the `seneca` namespace and include the necessary guards in each header file.

### `File` module

This module defines a class that holds information about a single file. A file is considered a resource of a filesystem.

***Private Data***

Design and code a class named `File`, that implements the `Resource` interface (supplied), and that should be able to store the following information (for each attribute, you can chose any type you think it's appropriate--you must be able to justify the decisions you have made):

- **m_contents**: stores the contents of a file

***Public Members***
- a custom constructor that receives two strings as parameters:
  - the name of the file
  - a text representation of the contents of a file (***optional***, with empty string as a default value).

- `void update_parent_path(const std::string&)`: sets the parent path to the parameter.
- `NodeType type() const`: a query that returns `Flags::FILE`.
- `std::string path() const`: a query that returns the full absolute path of the file (concatenates the absolute path location and the file name).
- `std::string name() const`: a query that returns the name of the file.
- `int count() const`: a query that returns `-1`.
- `size_t size() const`: a query that returns the size of the file in bytes. For simplicity, this is the number of characters in `m_contents` attribute.

**Add any other function that is required by your design, but make sure they are private members!**

### `Directory` module

This module defines a class that represents a directory in the filesystem (just like on your computer). A directory is considered a resource of a filesystem. A directory can hold many other directories and files.

***Private Data***

Design and code a class named `Directory`, that implements the `Resource` interface (supplied). A `Directory` object should be able to store the following information:
- **m_contents**: an object of type `std::vector` that holds pointers to `Resource` objects. Each element of the vector can either be a `Directory` or a `File`.

***Public Members***

- a custom constructor that receives the name of the directory as a string and uses it to initialize the `Directory` object. 

  ***Note:** assume all directory names end with a `/`.*

- `void update_parent_path(const std::string&)`: sets the parent path to the parameter. For each resource that this directory holds, this member should also set their absolute path locations to the full absolute path of this directory.

- `NodeType type() const`: a query that returns `Flags::DIR`.

- `std::string path() const`: a query that returns the full absolute path of the directory (a concatenation of the absolute path location and the directory name).

- `std::string name() const`: a query that returns the name of the directory.

- `int count() const`: a query that returns the number of resources that this directory holds.

- `size_t size() const`: a query that returns the size of the directory in bytes. The size of the directory is the sum of the individual sizes of each resource that this directory holds. This member returns `0u` if the directory is empty.

- `Directory& operator+=(Resource*)`: adds a resource to the directory and returns a reference to the current directory. This member should check for existing resources in the directory with the same name:

  - if a match is found, throw and exception and do nothing else;
  - if no match is found, add the resource and update the absolute path location of the added resource with the directory's full absolute path.

- `Resource* find(const std::string&, const std::vector<OpFlags>&)`: finds and returns the address of a resource in the directory whose name matches the given string or `nullptr` if a match is not found. This member also takes an ***optional*** vector of flags that determine how the find is performed (defaults to an empty collection).

  - if the `RECURSIVE` flag is in the second parameter, this member will also attempt to recursively find a match in each directory that is in the `m_contents` vector. ***HINT:** If an element in `m_contents` is a directory, use its `find()` member function to find a match*.

    ***NOTE:** If the current directory holds another directory named `src` which contains a file named `sample.txt` and we want to find `sample.txt`, this member will only return the `sample.txt` resource if the `RECURSIVE` flag is set, `nullptr` otherwise.*

- a destructor that deallocates memory for each resource that this directory holds.

- this class should not allow copy/move operations.

### `w6` Module (supplied)

The tester module for this portion has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.

### Sample Output

When the program is started with the command (the file `filesystem.txt` is provided):
```bash
ws
```
the output should look like the one from the `sample_output.txt` file.

### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```bash
~profname.proflastname/submit 345_w6_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***

## Part 2 (100%)

The second part of this workshop upgrades your solution to include one more module and update one existing module to complete the mini UNIX-like filesystem:
- `Filesystem`
- `Directory` (to be updated)

### `Filesystem` Module

The `Filesystem` module defines a class that represents a simple UNIX-like filesystem. The filesystem has a root directory and lets you move through the root directory which holds all of the filesystem's resources which you can run commands on.

***Private Data***

- **m_root**: a pointer to the root directory of the filesystem.
- **m_current**: a pointer to the current working directory in the filesystem from where operations are performed.

***Public Members***

- a custom constructor that receives the name of a file as its first argument, and an ***optional*** string containing the name of the root directory (defaults to an empty string). This member first creates a dynamically allocated `Directory` object to set as the root directory and the current working directory. Then loads the content of the file: each line in the file represents a resource in the filesystem that you must create using the appropriate class (`File` or `Directory`) and has one of the following formats:
  ```
  FILE_PATH | FILE_CONTENTS
  ```
  if the resource is a file, or
  ```
  DIRECTORY_PATH
  ```
  if the resource is a directory.
  - `FILE_PATH`, is a path to a file from the root directory, e.g. `images/file.png` or `file.png`.
  - `FILE_CONTENTS`, is a text representation of the contents of the file
  - `DIRECTORY_PATH`, is a path to a directory from the root directory, e.g. `documents/docs/`.

  For each line, the constructor **dynamically** creates a new `Directory` for each component of the path (separated by `/`) and links them together, with the first directory object being added to the root directory. You must not create duplicates of the directories.
  
  For example, for `images/pngs/file.png`, if `images` already exists on the root directory, do not create a new one (***HINT:** use the `find()` function for directories.*). Then create `pngs` and add it as a resource to `images` and finally create `file.png` and add it as a resource to `pngs`. You should also make sure to update the absolute location path of each resource as you create them.
  
  ***NOTE:** You must remove leading and trailing spaces from all paths and `FILE_CONTENTS`*
  
- this module does not allow copy operations. Make sure they are deleted.

- this module supports move operations.

- `Filesystem& operator+=(Resource*)`: adds a resource to the current directory.

- `Directory* change_directory(const std::string&)`: changes the current directory to the directory (located in the current directory) whose name matches argument.

  - the parameter is ***optional*** (defaults to an empty string).
  - if an empty string is passed, change the current directory to the root directory.
  - if no directory with the specified name exists (use`Directory::find()` to locate the directory), report an `std::invalid_argument` exception with the message `Cannot change directory! DIR_NAME not found!"`.

- `Directory* get_current_directory() const`: a query that returns the current directory.

- a destructor that deallocates memory for the root directory.

### `Directory` Module

Update the `Directory` module to support a few more commands and  displaying its contents.

***Public members***

- `void remove(const std::string&, const std::vector<OpFlags>&)`: deletes a resource from the directory whose name matches the first argument (removing it from its contents and deallocating memory for it).

  - If the matched resource is a directory, the `RECURSIVE` flag must be set, otherwise this member reports an `std::invalid_argument` exception with the message `NAME is a directory. Pass the recursive flag to delete directories."`.
  - If no matching resource is found, report an exception of type `std::string` with the message `NAME does not exist in DIRECTORY_NAME`.
  - The second argument is ***optional***, with a default value an empty collection.

- `void display(std::ostream&, const std::vector<FormatFlags>&) const`:

  - First inserts `Total size: XX bytes` and a newline into the output stream where `XX` is the size of the directory.

  - For each resource in the directory, first add `F` or `D` to the output stream based on the resource type, then add the resource information to the output stream in the following format:
  
    ```
    D | DIR_NAME |
    ```
    or
    ```
    F | FILE_NAME |
    ```
    where the name of the resource is left-aligned within a field width of `15` characters.

  - If the `LONG` flag is in the second parameter, insert into the output stream additional information about the resource:
  
    ```
    D | DIR_NAME | COUNT | XX bytes |
    ```
    or
    ```
    F | FILE_NAME |    | XX bytes |
    ```
    where `COUNT` (right-aligned field with width of `2`) is the number of resources in a directory, and `XX bytes` (right-aligned with a width of `10`) is the size of the resource in bytes.
  
  - The second argument is ***optional***, with a default value an empty collection.

### Sample Output

When the program is started with the command (the files are provided):
```bash
ws filesystem.txt
```
the output should look like the one from the `sample_output.txt` file.

### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- Why do you need to deallocate the dynamically allocated memory in your vector of resources?
- To call specific functions for a `Directory` objects stored in a `Resource*`, what special C++ operation did you have to do and why? 
- In this workshop you had to use `std::vector<seneca::Resource*>` to store a collection of filesystem resources as pointers. Could you have used `std::vector<seneca::Resource>` instead? **Justify your answer!**

To avoid deductions, refer to code in your solution as examples to support your explanations.

### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```bash
~profname.proflastname/submit 345_w6_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
