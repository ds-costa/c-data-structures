# c-algorithms (Because c is cool)

A repository with some functions written in c language.

## ✔️ Requirements

Scripts written in linux environment (Ubuntu **18.x** and **20.x**) - Things you need to compile and use the libraries:

- gcc compiler
```bash
$> sudo apt install gcc 
```
- build-essential package
```bash
$> sudo apt install build-essential 
```
- make
```bash
$> sudo apt install make 
```

## ⌨️ Getting Started

- Write your script in the main.c file

```c
#include <stdio.h>
#include "src/array.h"

int main() {

    int arr[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    float arr2[] = {
        123,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };
    
    double arr3[] = {
        123.333,76, 0, 3, 10, 434, 22, -1, 4, 99, 1, 12408, -12
    };

    array_print_int(12, arr);
    array_print_float(12, arr2);
    array_print_double(12, arr3);

    return 0;
}
```

- Build with make
```bash
$> make
```
- Execute the compiled project.
```bash
$> ./bin/app  
```
- To delete the created binaries
```bash
$> make clean  
```

## 📁 Creating your own libs and functions
You can create your own libraries with simple steps:

- Create the .c and .h files of your lib in the src folder (in our example we will create foo.h and foo.c)
- Add the lib header in the main.c file
	- ```#include "src/foo.h" ```

## 📝 License

This project is licensed under the MIT GENERAL PUBLIC LICENSE - see the [LICENSE](LICENSE) file for more details.

**Open Source Software** Hell Yeah!!! ヽ(・∀・)ﾉ