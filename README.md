# advanced-C
<details><summary>Bài 1: Compiler - Macro</summary>
<p>

> ##  Bài 1: Compiler - Macro
<details><summary>Compiler</summary>
<p>

## Compiler
 [Compiler](https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/?ref=lbp): Chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy
 

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/1e02ab50-ef02-476c-89ea-842803466a14)

## Quá trình biên dịch gồm 4 giai đoạn

- Giai đoạn tiền xử lý (Pre-processor):

  - Thực hiện định nghĩa macro (#define)
  - Chèn nội dung của các file header (#include)
  - Loại bỏ comment.

 Tiền xử lý được lưu trữ trong filename.i.
 ```
  gcc -E main.c -o main.i. 
 ```

- Giai đoạn dịch NNBC sang Assembly (Compiler):

  - Trình biên dịch (compiler) chuyển đổi mã nguồn viết bằng ngôn ngữ lập trình thành mã Assembly tương ứng.

Biên dịch file`.i ` sang filename.s và tạo file `.s` 
```
gcc -S main.i -o main.s
```

- Giai đoạn dịch Assembly sang ngôn ngữ máy (Assembler):

  -   Mã Assembly được chuyển đổi thành mã máy tương ứng

dịch tệp file`.s` sang file`.o` (Object) và tạo file `.o`
```
gcc -c main.s -o main.o
```

- Giai đoạn liên kết (Linker)

  - File đối tượng (object files)`.o` được tạo ra từ các quá trình biên dịch trước đó được kết hợp lại thành một file thực thi hoàn chỉnh `.exe`.
  - Linker cũng giải quyết các tham chiếu tới các hàm và biến nằm ở các file object khác nhau, tạo ra các liên kết (links) giữa chúng, đảm bảo các tên và tham chiếu đúng khi chương trình được thực thi.
  
```
gcc -c main.s -o main.o

main.o -o filename
```

  ![image](https://github.com/hnaht1126/advanced-C/assets/152061415/ea26bc52-30e8-444c-a0c2-c2e05901711a)

- file `.i`  được tạo ra từ các file mã nguồn C/C++ thông qua trình biên dịch đã được viết dưới dạng mã nguồn gốc, cũng như có thể chứa các chỉ thị và định nghĩa cho trình biên dịch.

- file `.s` thường là các tệp mã nguồn dạng văn bản chứa mã nguồn đã được viết bằng một ngôn ngữ lập trình hợp ngữ như Assembly.

- flie `.exe` thường là các tệp chứa mã máy thực thi cho các ứng dụng chạy trên hệ điều hành Windows
</p>
</details>



<details><summary>Macro</summary>
<p>

## Macro 
[Macro](https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/?ref=header_search) là những thông tin được xử lý ở quá trình tiền xử lý ( Preprocessor).


## #include : thêm nội dung của một file mã nguồn vào mã nguồn khác. 
#include thường được sử dụng để chèn các tệp header (tệp đầu mục) vào mã nguồn hiện tại.

Cho phép tái sử dụng mã nguồn, phân chia mã nguồn thành các tệp nhỏ hơn, và tạo ra các thư viện và module trong các dự án lớn.

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```
## #define : được sử dụng để tạo ra các hằng số, các macro, hoặc định nghĩa các hàm ngắn gọn

> Ví dụ về sử dụng #define để định nghĩa hằng số:
```c
#include <stdio.h>

#define PI 3.14159
#define MAX_SIZE 100

int main() {
    // Sử dụng hằng số Pi trong chương trình
    double radius = 5.0;
    double area = PI * radius * radius;

    printf("Radius: %.2f\n", radius);
    printf("Area of the circle: %.2f\n", area);

    return 0;
}

```
> Ví dụ về sử dụng #define để tạo ra macro:
```c
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main() {

    
    // Sử dụng macro để tính bình phương của num
    int result = SQUARE(5);

    printf("Result is: %d\n", result);

    return 0;
}

```
SQUARE là một macro, và mỗi khi chương trình biên dịch gặp SQUARE(a), nó sẽ được thay thế bằng biểu thức ((a) * (a)).

'#define' là một công cụ trong tiền xử lý của ngôn ngữ C và C++, cho phép định nghĩa các hằng số, macro, hoặc các hàm ngắn gọn giúp làm cho mã nguồn dễ đọc và dễ bảo trì hơn.

## '#undef ' được sử dụng để hủy định nghĩa của một macro trước đó đã được định nghĩa bằng #define

```c
#define MAX_SIZE 100
#undef MAX_SIZE
```

' #undef ' MAX_SIZE sẽ hủy bỏ định nghĩa của macro MAX_SIZE trước đó, khiến cho các lần sử dụng MAX_SIZE sau đó sẽ không còn hiệu lực.

#undef thường được thực hiện khi cần thay đổi hoặc ghi đè lên các định nghĩa macro trong mã nguồn.


## #if, #elif, và #else
 - #if: Directive này cho phép kiểm tra một điều kiện và biên dịch một phần của mã nguồn nếu điều kiện đó là đúng.

- #elif: Là viết tắt của "else if" và được sử dụng để kiểm tra một điều kiện mới nếu điều kiện trước đó không đúng.

- #else: Được sử dụng khi không có điều kiện nào trong #if hoặc #elif trước đó là đúng.

```c
#include <stdio.h>

#define DEBUG_MODE 1

int main() {
    #if DEBUG_MODE == 1
        printf("Debug mode is enabled.\n");
    #elif DEBUG_MODE == 0
        printf("Debug mode is disabled.\n");
    #else
        printf("Unknown debug mode.\n");
    #endif

    return 0;
}

```
- Nếu DEBUG_MODE được định nghĩa là 1, câu lệnh printf("Debug mode is enabled.\n"); sẽ được biên dịch.
- Nếu DEBUG_MODE là 0, câu lệnh printf("Debug mode is disabled.\n"); sẽ được biên dịch.
- Nếu không có giá trị nào của DEBUG_MODE được định nghĩa, câu lệnh printf("Unknown debug mode.\n"); sẽ được biên dịch.

## #ifdef và #ifndef
Là các directive (chỉ thị tiền xử lý) được sử dụng để kiểm tra xem một macro đã được định nghĩa trước đó chưa.

- #ifdef kiểm tra xem một macro đã được định nghĩa hay không. Nếu macro đã được định nghĩa, khối mã tiếp theo được thực thi.

- #ifndef kiểm tra xem một macro chưa được định nghĩa. Nếu macro chưa được định nghĩa, khối mã tiếp theo được thực thi.

## Toán tử trong Macro
>  vd toán tử '#'
```c
#include <stdio.h>
#define STRINGIZE(x) #x
#define DATA 40

int main() {
    // Sử dụng toán tử #    printf("The value is: %s\n", STRINGIZE(DATA));
    
    return 0;
  }
```

> toán tử '##'

nối 

> toán tử '/'
xuống hàng

### Variadic macro

Variadic Marco: Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau

> Ví dụ

   ``` c
  #include <stdio.h>

#define CASE_OPTION(number, function) case number: function(); break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \ //switch case
        __VA_ARGS__ \
        default: printf("Invalid option!\n"); \
    }
// #define PRINT_MENU(...) printf(__VA_ARGS__);

#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)

#define PRINT_MENU(...) \
        const char* items[] = {__VA_ARGS__}; \
        int n = sizeof(items) / sizeof(items[0]); \
        for (int i = 0; i < n; i++) { \
            PRINT_MENU_ITEM(i + 1, items[i]); \
        } \

void feature1() {
    printf("You chose feature 1.\n");
}

void feature2() {
    printf("You chose feature 2.\n");
}

void feature3() {
    printf("You chose feature 3.\n");
}

void feature4() {
    printf("You chose feature 4.\n");
}

int main() {
    // PRINT_MENU("1. Option 1\n2. Option 2\n3. Option 3\n4. Option 4\n5. Exit\n");

    PRINT_MENU("Option 1", "Option 2", "Option 3","Option4", "Exit");

    // Giả sử option được nhập từ người dùng
    int option;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1)
        CASE_OPTION(2, feature2)
        CASE_OPTION(3, feature3)
        CASE_OPTION(4, feature4)
    )

    return 0;
}


```





### Câu 1. Ưu điểm của Macro là gì?
Trả lời:

1. Tăng năng suất: Macro có thể tiết kiệm thời gian và giảm lỗi bằng cách tự động hóa các tác vụ lặp đi lặp lại.
2. Customization: Macro có thể được tùy chỉnh để phù hợp với nhu cầu cụ thể, cho phép linh hoạt hơn trong cách hoàn thành nhiệm vụ.
3. Tính nhất quán: Macro có thể giúp đảm bảo tính nhất quán trong các tác vụ bằng cách làm theo một tập hợp các hướng dẫn được xác định trước.
4. Hiệu quả: Macro có thể thực hiện các tác vụ nhanh hơn con người, cải thiện hiệu quả tổng thể.
5. Dễ sử dụng: Macro rất dễ tạo và sử dụng, đòi hỏi ít hoặc không cần kiến thức lập trình

### Câu 2. Nhược điểm của Macro là gì?
Trả lời:

1. Rủi ro bảo mật: Macro có thể là một rủi ro bảo mật nếu chúng không được bảo mật đúng cách hoặc nếu chúng được sử dụng để thực thi mã độc.
2. Chức năng hạn chế: Macro có thể không thể thực hiện các tác vụ phức tạp hơn, hạn chế tính hữu dụng của chúng.
3.Vấn đề tương thích: Macro có thể không tương thích với tất cả các ứng dụng phần mềm, hạn chế tính hữu dụng của chúng.
4.Bảo trì: Macro có thể yêu cầu bảo trì và cập nhật, điều này có thể tốn thời gian và tốn kém.
5. Phụ thuộc: Quá phụ thuộc vào macro có thể dẫn đến giảm kỹ năng giải quyết vấn đề và tư duy phản biện.


</p>
</details>

</p>
</details>


<details><summary>Bài 2: STDARG - ASSERT</summary>
<p>

> ## stdarg - assert

## stdarg

Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.

Các hàm như `printf` và `scanf` là ví dụ điển hình 

 - va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi

 - va_start: Khởi tạo biến để trỏ đến đối số biến đầu tiên.va_list

 - va_arg: Truy xuất giá trị của đối số tiếp theo trong danh sách, với kiểu của nó.

 - va_end: Dọn sạch biến sau khi tất cả các đối số đã được xử lý.va_list

### ví dụ minh họa cách sử dụng:`stdarg`
```c

#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; ++i) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    va_end(args);
    printf("\n");
}

int main() {
    print_ints(3, 1, 2, 3);
    print_ints(5, 10, 20, 30, 40, 50);
    return 0;
}

```
Trong ví dụ này, là một hàm chấp nhận một số lượng đối số nguyên thay đổi. Nó sử dụng macro để lặp lại các đối số được cung cấp và in chúng ra.print_ints()stdarg

## assert

`assert` là một macro trong ngôn ngữ lập trình C và C ++ được sử dụng cho mục đích gỡ lỗi. Nó đánh giá một biểu thức và nếu biểu thức đánh giá là false (không), nó sẽ gây ra lỗi xác nhận, thường *`tạm dừng thực thi chương trình và in thông báo lỗi.`*

### vd
```c
#include <stdio.h>
#include <assert.h>

int main() {
    int x = 5;
    assert(x == 10);
    printf("This line will not be reached if assertion fails.\n");
    return 0;
}

```
cmd
```
Assertion failed: (x == 10), file example.c, line 6.

```
`assert` thường bị vô hiệu hóa trong các bản dựng sản xuất vì chúng có thể ảnh hưởng đáng kể đến hiệu suất 

</p>
</details>


