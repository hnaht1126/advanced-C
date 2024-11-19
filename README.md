advanced-C

# Bài 1: Compiler - Macro

## 1. Compiler
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


## 2. Macro 
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





# Bài 2: STDARG - ASSERT

## 1. stdarg

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

## 2. assert

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


# Bài 3: Pointer

## 1. Pointer
Pointer là một biến chứa địa chỉ bộ nhớ của một biến khác

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/b01a0c93-6b2f-42a9-b52c-b22cf9c3f130)

Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch

## 2. Void Pointer
Con trỏ void trong C và C++ là  con trỏ có thể trỏ đến các đối tượng thuộc bất kỳ kiểu dữ liệu nào (không cần biết kiểu dữ liệu con trỏ trỏ tới). Con trỏ void được khai báo bằng kiểu `void *ptr.`
```c
// vd sử dụng con trỏ void

/* 
Trong ví dụ này, chúng ta có một con trỏ void ptr được gán địa chỉ của các biến có kiểu dữ liệu khác nhau (int, float và char). 
** cần ép kiểu thích hợp khi lấy giá trị mà con trỏ trỏ tới
 */
#include <stdio.h>

int main() {
    int num = 10;
    float pi = 3.14;
    char letter = 'A';

    // Declaring void pointer
    void *ptr;

    // Pointing void pointer to different types of data
    ptr = &num;
    printf("Value pointed by void pointer (integer): %d\n", *(int*)ptr);

    ptr = &pi;
    printf("Value pointed by void pointer (float): %.2f\n", *(float*)ptr);

    ptr = &letter;
    printf("Value pointed by void pointer (character): %c\n", *(char*)ptr);

    return 0;
}
```
## 3. [Function pointer](https://www.geeksforgeeks.org/function-pointer-in-c/?ref=lbp) 

Con trỏ hàm (function pointer) là một biến có kiểu dữ liệu là con trỏ, nhưng thay vì chỉ trỏ đến một vùng nhớ chứa dữ liệu, nó trỏ đến một hàm cụ thể trong bộ nhớ. Con trỏ hàm cho phép chúng ta truy cập và thực thi các hàm thông qua biến con trỏ đó.

Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

```c
/*
gán ptr tới các hàm add và subtract, chúng ta có thể gọi các hàm này thông qua ptr, cung cấp sự linh hoạt trong việc thay đổi hàm mà ptr trỏ tới mà không cần thay đổi mã nguồn.
  */
#include <stdio.h>

// Định nghĩa hai hàm cần được trỏ tới
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Khai báo một con trỏ hàm có kiểu trả về là int và nhận hai đối số kiểu int
    int (*ptr)(int, int);

    // Gán con trỏ hàm đến hàm add
    ptr = add;
    printf("Addition: %d\n", ptr(10, 5)); // Gọi hàm add thông qua con trỏ hàm

    // Gán con trỏ hàm đến hàm subtract
    ptr = subtract;
    printf("Subtraction: %d\n", ptr(10, 5)); // Gọi hàm subtract thông qua con trỏ hàm

    return 0;
}

```
**Ứng dụng :** Con trỏ hàm thường được sử dụng trong các tình huống như việc truyền hàm làm đối số cho một hàm khác (callbacks), xử lý sự kiện, hoặc khi cần chọn lựa hàm để gọi dựa trên điều kiện trong thời gian chạy.

```c
#include <stdio.h>
// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```

Con trỏ hàm trỏ tới những hàm input parameter (tham số) giốn nhau
sd ctro hàm để làm input  parameter cho hàm khác.

***tham số là biến trong khai báo hàm, đối số là giá trị cụ thể được truyền cho các biến này khi hàm được gọi.***

## 4. Pointer to Constant 

"Con trỏ tới hằng số" trong C và C++ dùng để chỉ `một con trỏ` trỏ tới một `giá trị không đổi`. Điều này có nghĩa là bản thân `con trỏ có thể thay đổi` (tức là nó có thể trỏ đến các vị trí bộ nhớ khác nhau), nhưng `giá trị được lưu trữ tại vị trí bộ nhớ mà nó trỏ tới không thể được sửa đổi thông qua con trỏ đó`.

(giá trị không đổi, con trỏ có thể trỏ tới chỗ khác )

```c
const int *ptr; // Pointer to a constant integer
```
Ứng dụng: bảo vệ dữ liệu không bị thay đổi

## 5. Constant Pointer:
là một con trỏ `không thể` được sử dụng để sửa đổi giá trị(địa chỉ) mà nó trỏ tới, nhưng nó `có thể` thay đổi giá trị ở vùng nhớ tại địa chỉ đó . 

(địa chỉ con trỏ trỏ tới ko đổi, có thể thay đổi giá trị ở vùng nhớ tại địa chỉ đó)

```c
int *const ptr = &x; // Constant pointer to an integer
```

Ứng dụng: Đảm bảo con trỏ, trỏ đến đúng địa chỉ (vd trỏ đến đúng hàm cần sd)

## 6. Pointer to Pointer

Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 

Con trỏ tới con trỏ cung cấp một cách tiếp cận linh hoạt đến bộ nhớ, cho phép thay đổi giá trị của con trỏ thứ hai để thay đổi địa chỉ mà nó trỏ tới.

Ứng dụng:  **Truyền con trỏ vào hàm**, **Sử dụng trong mảng 2 chiều**, **Sử dụng trong danh sách liên kết**.


# Bài 4: Memory layout


## 1. Memory layout

Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.



Việc tổ chức dữ liệu trong bộ nhớ của hệ thống máy tính. Nó xác định cách dữ liệu được lưu trữ, truy cập và quản lý trong hệ thống phân cấp bộ nhớ của hệ thống.

Bố cục bộ nhớ thường bao gồm việc sắp xếp các phân đoạn bộ nhớ khác nhau, chẳng hạn như:

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/7868dafa-ceee-4d9d-9313-a8d52b7ec365)



## 2. Code Segment (Text Segment)

Chứa mã thực thi của một chương trình.

chỉ đọc và thực thi, không có quyền ghi. 

Lưu hằng số, con trỏ kiểu char

Tất cả các biến lưu ở phần vùng Text đều không thể thay đổi giá trị mà chỉ được đọc

```c
#include <stdio.h>

const int a = 10;
char arr[] = "Hello";
char *arr1 = "Hello";

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

    arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}

```


## 3. Data Segment

Phân đoạn này chứa các `biến toàn cục` và `biến static` của chương trình. 

Nó có thể được chia tiếp thành

### Dữ liệu khởi tạo (biến khởi tạo - initialized variables)

- (khởi tạo giá trị !=0)

- đọc ghi, thay đổi giá trị của biến.

- All các biến thu hồi sau khi chương trình kết thúc. (windown- thoát khỏi hàm main, VĐK - ngắt nguồn)

```c
#include <stdio.h>

int a = 10;
double d = 20.5;

static int var = 5;

void test()
{
    static int local = 10;
}


int main(int argc, char const *argv[])
{  
    a = 15;
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);



    return 0;
}
```

### Dữ liệu chưa khởi tạo (biến chưa khởi tạo - uninitialized variables, còn được gọi là phân đoạn BSS).

- Giá trị khởi tạo = 0 / không gán giá trị.

- Đọc - ghi 

- All các biến thu hồi sau khi chương trình kết thúc. 

```c
#include <stdio.h>


typedef struct 
{
    int x;
    int y;
} Point_Data;


int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {5,7};



void test()
{
    static int local = 0;
    static int local_2;
}

int main() {

    
    printf("a: %d\n", a);
    printf("global: %d\n", global);
   

    
    
    return 0;
}
```

## 4. Stack
được sử dụng để Cấp phát bộ nhớ động và quản lý lệnh gọi hàm. 

 lưu trữ các biến cục bộ, tham số hàm, địa chỉ trả về và thông tin liên quan đến lệnh gọi hàm khác. 
 
 Ngăn xếp thường phát triển xuống trong bộ nhớ.

 Đọc - ghi trong thời gian chương trình chạy 

 thu hồi khi thoát khỏi vùng nhớ

 ```c
#include <stdio.h>


void test()
{
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b)
{
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}



int main() {

    sum(3,5);
    /*
        0x01
        0x02
        0x03
    */
   test();
   /*
    int test = 0; // 0x01
   */


    
    return 0;
}
 ```

## 5. Heap

Heap là vùng bộ nhớ được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.

Nó được quản lý bởi người lập trình hoặc bởi các hàm cấp phát bộ nhớ như malloc() và free(), cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.

 Heap thường tăng lên trong bộ nhớ.

> Quyền truy cập: có quyền đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.


  - `malloc()`:  <stdlib.h>
        
    Tham số truyền vào: kích thước mong muốn ( byte) 

     Giá trị trả về: con trỏ void
```c
     void *malloc(size_t size);
```

`calloc()`:

   tương tự malloc, nhưng khởi tạo bộ nhớ được cấp phát = 0.

```c
void *calloc(size_t num_elements, size_t element_size);
```

num_elements: Số lượng phần tử để phân bổ bộ nhớ.
element_size: Kích thước của mỗi phần tử tính bằng byte.

*Tự tìm phân vùng đủ cho dữ liệu*

```c
#include <stdlib.h>

int main() {
    int *arr_malloc, *arr_calloc;
    size_t size = 5;

    // Sử dụng malloc
    arr_malloc = (int*)malloc(size * sizeof(int));

    // Sử dụng calloc
    arr_calloc = (int*)calloc(size, sizeof(int));

    // ...

    // Giải phóng bộ nhớ
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
```


```c
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{  
    int soluongkytu = 0;

    char* ten = (char*) malloc(sizeof(char) * soluongkytu);



    for (int i = 0; i < 3; i++)
    {
        printf("Nhap so luong ky tu trong ten: \n");
        scanf("%d", &soluongkytu);
        ten = realloc(ten, sizeof(char) * soluongkytu);
        printf("Nhap ten cua ban: \n");
        scanf("%s", ten);

        printf("Hello %s\n", ten);
    }
    

    

    return 0;
}
```
## 6. Stack và Heap
Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.

Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

`Stack`: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.

`Heap`: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

>### Lỗi tràn bộ nhớ
**Stack:** bởi vì bộ nhớ Stack cố định nên nếu chương trình sử dụng quá nhiều bộ nhớ **vượt quá khả năng lưu trữ của Stack** chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn `khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...`
```c

int foo(int x)
    printf("De quy khong gioi han\n")
        return foo(x);
}
```

**Heap:** Nếu bạn **liên tục cấp phát vùng nhớ mà không giải phóng** thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

```c
int *A = (int *)malloc(18446744073709551615);
```

# Bài 5: Extern - Static - Volatile - Register

## 1. Extern 
- tự tìm `biến` đã được khai báo

Khi sử dụng `Extern` khai báo biến, trình biên dịch hiểu rằng biến đã được khai báo ở một nơi khác và trình biên dịch sẽ tìm kiếm biến này ở các file khác trong quá trình liên kết.

    #include <abc>: dán nội dung file abc vào mã 

## 2. Static
## Static local variables 
- giữ giá trị biến ở những lần gọi tiếp

(biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm (giá trị của nó được bảo tồn giữa các lần gọi) và giữ phạm vi của biến chỉ trong hàm đó. 
```c
#include <stdio.h>

void exampleFunction() {
    static int count = 0; // Biến cục bộ tĩnh
    count++;
    printf("This function has been called %d times.\n", count);
}

int main() {
    exampleFunction(); // In ra "This function has been called 1 times."
    exampleFunction(); // In ra "This function has been called 2 times."
    exampleFunction(); // In ra "This function has been called 3 times."
    return 0;
}
```
 biến count được khai báo là một biến cục bộ tĩnh trong hàm exampleFunction(). Mỗi lần hàm được gọi, biến count tăng lên một và giá trị của nó được giữ qua các lần gọi tiếp theo của hàm.

 > tăng sau mỗi lần gọi biến

 ## Static global variables 
 - chỉ được sử dụng trong cùng một file mà nó được khai báo.

 **Ứng dụng:** dùng để thiết kế các file thư viện.

 Static global variables hay được gọi là "biến toàn cục tĩnh", là `biến mà chỉ có phạm vi trong file mà nó được khai báo`. Tức là, biến này **không thể truy cập từ các file khác thông qua việc sử dụng từ khóa extern**. Biến toàn cục tĩnh chỉ được sử dụng trong cùng một file mà nó được khai báo.
```c
// File: test.c
#include <stdio.h>

static int globalVar = 10;

void printGlobalVar() {
    printf("Global variable: %d\n", globalVar);
}

void modifyGlobalVar() {
    globalVar += 5;
}

int main() {
    printGlobalVar(); // In ra "Global variable: 10"
    modifyGlobalVar();
    printGlobalVar(); // In ra "Global variable: 15"
    return 0;
}
```
> biến globalVar không thể truy cập từ các file khác thông qua extern.

## Static trong class 
Trong một lớp, **biến tĩnh (static member)** là một biến mà nó `thuộc về lớp chứ không thuộc về mỗi đối tượng của lớp đó`.

Mọi đối tượng của lớp đều chia sẻ một bản sao duy nhất của biến tĩnh. Các biến tĩnh được ***cấp phát bộ nhớ khi chương trình bắt đầu chạy và tồn tại cho đến khi chương trình kết thúc.***

Tương tự, **phương thức tĩnh (static method)** là `một phương thức mà nó thuộc về lớp chứ không phải thuộc về các đối tượng của lớp đó`. Phương thức tĩnh có thể được gọi mà không cần tạo ra một đối tượng của lớp đó.

```c
#include <iostream>

class MyClass {
public:
    static int staticVariable;
    static void staticMethod() {
        std::cout << "This is a static method.\n";
    }
};

int MyClass::staticVariable = 0;

int main() {
    // Gọi phương thức tĩnh của lớp mà không cần tạo đối tượng
    MyClass::staticMethod();

    // Truy cập biến tĩnh qua một đối tượng
    MyClass obj1;

    obj1.staticVariable = 5;

    // Truy cập biến tĩnh qua một đối tượng khác
    MyClass obj2;

    std::cout << obj2.staticVariable << std::endl; // In ra 5

    return 0;
}
```
`staticVariable `là biến tĩnh và `staticMethod` là phương thức tĩnh của lớp `MyClass`. Cả hai đều thuộc về lớp ` MyClass `chứ không phải thuộc về mỗi đối tượng của lớp.

## 3. Volatile
 - Sử dụng khi biến có sự thay đổi giá trị -> đọc 1 lần khi compiler.

được sử dụng để đánh dấu một biến như là "volatile". ***Giá trị của biến có thể thay đổi bất kỳ lúc nào bởi các yếu tố mà không được kiểm soát bởi chương trình***, chẳng hạn như phần cứng hoặc các luồng khác.

Việc sử dụng volatile thông báo cho trình biên dịch không nên tối ưu hóa hoặc loại bỏ bất kỳ mã nào liên quan đến biến đó, bởi vì giá trị của nó có thể thay đổi không lường trước. 

**Ứng dụng** trong các trường hợp như truy cập các biến được chia sẻ giữa các luồng hoặc trong truy cập vào các biến được cập nhật bởi phần cứng.

```c
// đọc giá trị cảm biến 
#include <stdio.h>

int main() {
    volatile int sensorValue;

    while (1) {
        // Đọc giá trị từ cảm biến (giả sử)
        sensorValue = readSensor();

        // In giá trị cảm biến ra màn hình
        printf("Sensor Value: %d\n", sensorValue);
    }

    return 0;
}
```
việc sử dụng volatile đảm bảo rằng trình biên dịch sẽ luôn đọc lại giá trị mới nhất của biến sensorValue mỗi khi nó được truy cập.

## 4. Register

Trong ngôn ngữ lập trình C, từ khóa `register` được sử dụng để yêu cầu trình biên dịch cấp phát một biến cục bộ cho một thanh ghi máy tính. Giúp cải thiện hiệu suất truy cập vào biến đó bởi vì việc sử dụng thanh ghi có thể nhanh hơn so với việc truy cập bộ nhớ.

Tuy nhiên, trình biên dịch thường có thể tự động quyết định xem có sử dụng thanh ghi cho biến cục bộ hay không, và nó thường tốt hơn trong việc tối ưu hóa mã.

Một số lưu ý về từ khóa register:

1. Trình biên dịch có thể bỏ qua từ khóa register và xem nó như là một yêu cầu tùy chọn.
2. Không thể lấy địa chỉ của một biến được khai báo với từ khóa register, vì vậy chúng không thể được sử dụng trong các trường hợp như truyền con trỏ.
3. Việc sử dụng register có thể không có hiệu quả nếu trình biên dịch không thực sự chuyển biến vào thanh ghi.
```c
// cấp phát biến x cho thanh ghi
#include <stdio.h>

int main() {
    register int x = 10; // Yêu cầu cấp phát biến x cho một thanh ghi
    printf("x = %d\n", x);
    return 0;
}

```
# Bài 6: Goto - setjmp.h

## 1. Goto 
cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm (có thể làm mã khó đọc và khó bảo trì)

```c
/*chương trình sẽ nhảy tới nhãn end và in ra "The end." mà không cần thực thi các dòng code ở giữa*/

#include <stdio.h>

int main() {
    printf("Start.\n");
    goto end;

    printf("This will be skipped.\n");

    end: // lable
    printf("The end.\n");

    return 0;
}

```
## matrix led 
 điều khiển mảng led (and giá trị hàng và cột )
 ![image](https://github.com/hnaht1126/advanced-C/assets/152061415/a9558990-ad37-4bf2-8311-1b19dbd75980)

## 2. setjmp.h
setjmp.h là một thư viện trong ngôn ngữ lập trình C. Thư viện này chứa hai hàm chính là `setjmp` và `longjmp`.

xử lý các tình huống đặc biệt như xử lý ngoại lệ (exception handling)

ngoại lệ (exception) là một sự kiện không mong muốn xảy ra trong quá trình thực thi chương trình, làm ảnh hưởng đến luồng bình thường của chương trình. 
 1. **setjum:** sử dụng hàm để đặt một điểm trong chương trình. Nó ***lưu trữ trạng thái hiện tại của cá biến và các thông số của hàm*** gọi nó vào kiểu dữ liệu là `jmp_buf`.  Sau khi gọi setjmp, chương trình có thể tiếp tục thực hiện và thể quay lại điểm đã đánh dấu bằng cách sử dụng `longjmp`.

 2. **longjmp:** Hàm này được sử dụng để quay lại điểm đã đánh dấu trước đó bởi setjmp. Nó khôi phục trạng thái của các biến và thông số của hàm gọi đến trạng thái đã lưu trữ trong jmp_buf, cho phép chương trình nhảy đến điểm đó mà không cần hoàn thành các lệnh ở giữa.

# Bài 7: Bitmask

## 1. Bitmask
Quá trình sửa đổi và sử dụng các biểu diễn nhị phân của số hoặc dữ liệu 

### bitwise
* OR (|) - đặt bit thành 1 nếu một trong hai bit tương ứng trong toán hạng là 1. (1 cái 1 -> 1)
* AND (&) - đặt một bit thành 1 nếu cả hai bit tương ứng trong toán hạng là 1.  (nhân lại ra 1 -> 1)
* XOR (^) - đặt bit thành 1 nếu các bit tương ứng trong toán hạng khác nhau. (tổng lẻ -> 1)
* NOT (~) - đặt 0 thành 1 và 1 thành 0.
* shif-left (<<)  - dịch bit sang trái. (xóa trái thêm 0 phải )
* shif- right (>>) - dịch bit sang phải. (xóa phải thêm 0 trái)
### dùng để luu các biến chỉ cần 2 giá trị (0/1) -> giảm bộ nhớ 
 



# Bài 8: Struct - Union

## 1. Struct

`struct` là một cấu trúc dữ liệu được sử dụng để tổ chức các biến có liên quan lại với nhau trong một khối duy nhất. Một `struct` **cho phép bạn tự định nghĩa các kiểu dữ liệu phức tạp bằng cách kết hợp nhiều kiểu dữ liệu cơ bản lại với nhau.**

```c
typedef struct <tên_struct> {
    // các thành phần (fields) của struct
    <kiểu_dữ_liệu1> <tên_biến1>;
    <kiểu_dữ_liệu2> <tên_biến2>;
    //...
}<bí danh>; // sd typedef để đặt tên cho Struct
```

Kích thước dữ liệu cơ sở tạo bởi `stuct` được xác định bằng kích thước kiểu dữ liệu lớn nhất được khởi tạo trong `struct` đó.

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/47d85127-ff5f-424e-8e2b-1dbc04e942ac)

với struct trên mỗi lần quét dữ liệu sẽ tạo 4 byte dữ liệu.

Quét kích thước cơ sở -> kiểm tra kích thước -> sắp xếp dữ liệu vào ô nhớ.

Việc sắp xếp dữ liệu hợp lý giúp tôi ưu bộ nhớ, làm giảm số lượng các ô nhớ trống.

**Ứng dụng:** Tổ chức dữ liệu theo một cấu trúc nhất định để dễ dàng quản lý và thao tác với chúng.

Ứng dụng của struct trong:
json....... 
list.....

## 3. Union

`union` là một loại cấu trúc dữ liệu giống như `struct`, nhưng các thành phần của nó sử dụng cùng một vùng nhớ. Điều này có nghĩa là mỗi thành phần của `union chia sẻ cùng một địa chỉ bắt đầu`, do đó chỉ một thành phần của `union` có thể lưu trữ giá trị tại một thời điểm.

```c

union <tên_union> {
    // các thành phần (fields) của union
    <kiểu_dữ_liệu1> <tên_biến1>;
    <kiểu_dữ_liệu2> <tên_biến2>;
    //...
};
```
**Ứng dụng:** Đọc dữ liệu cảm biến (mỗi lần đọc 1 cảm biến rồi in dữ liệu ra -> tiết kiệm bộ nhớ )

## Ứng dụng kết hợp struct và union

# Bài 9: JSON

## 1. Khái niệm JSON

JSON được biểu diễn dưới dạng các cặp key-value (khóa-giá trị) và có thể nhóm thành các đối tượng (objects) và mảng (arrays), giúp tổ chức dữ liệu một cách cấu trúc và linh hoạt, để dễ đọc và viết cho con người.

## 2. Các kiểu định dạng

JSON (JavaScript Object Notation) hỗ trợ một số kiểu định dạng dữ liệu cơ bản, bao gồm:

- Chuỗi (String): `chuỗi ký tự Unicode được bao quanh bởi dấu ngoặc kép`. Ví dụ: "Hello, World!", "123", "true".

- Số (Number): JSON hỗ trợ cả `số nguyên và số thực`. Các số có thể được biểu diễn với hoặc không có dấu thập phân và/hoặc mũ. Ví dụ: 123, 3.14, -42, 1.5e10.

- Boolean: Được biểu diễn bởi từ khóa `true` hoặc `false`.

- Mảng (Array): Một danh sách các giá trị, được `bao quanh bởi dấu ngoặc vuông và các giá trị được phân tách bằng dấu phẩy`. Mỗi phần tử trong mảng `có thể là bất kỳ kiểu dữ liệu JSON nào`. Ví dụ: [1, 2, 3, "apple", true].

- Đối tượng (Object): `Một tập hợp các cặp key-value`, được `bao quanh bởi dấu ngoặc nhọn`. `Mỗi cặp key-value được phân tách bằng dấu phẩy`. Key là một chuỗi và phải được bao quanh bởi dấu ngoặc kép, sau đó là dấu hai chấm, và sau đó là giá trị. Ví dụ: {"name": "John", "age": 30, "isStudent": true}.

- Null: Được biểu diễn bởi từ khóa `null`, `đại diện cho một giá trị không tồn tại hoặc không xác định`.

 Các kiểu dữ liệu này có thể được kết hợp với nhau để tạo ra cấu trúc dữ liệu phức tạp hơn trong JSON.







# Bài 10: Linked List

## 1. Linked list 

Danh sách liên kết là một `cấu trúc dữ liệu` bao gồm một `chuỗi các phần tử`, mỗi phần tử thường được gọi là một nút **(node)**. `Mỗi nút chứa hai phần: dữ liệu và tham chiếu (hoặc liên kết) đến nút tiếp theo trong chuỗi`. Nút cuối cùng trong danh sách trỏ đến null, biểu thị sự kết thúc của danh sách.

* Danh sách liên kết đơn: mỗi nút chứa dữ liệu và tham chiếu đến nút tiếp theo trong chuỗi.

* Danh sách liên kết đôi:  mỗi nút chứa tham chiếu đến nút tiếp theo và tham chiếu đến nút trước đó trong chuỗi. 

* Danh sách liên kết vòng:  nút cuối cùng trỏ về nút đầu tiên.

## Ưu nhược điểm 
Ưu điểm: 

* Kích thước động: Danh sách liên kết có thể dễ dàng tăng và giảm kích thước.

* Chèn và xóa: Việc chèn và xóa nói chung diễn ra nhanh chóng và hiệu quả, đặc biệt đối với các danh sách liên kết đơn khi đã biết vị trí.

* Không lãng phí dung lượng: Danh sách liên kết chỉ sử dụng nhiều bộ nhớ cần thiết cho các phần tử chứa trong đó.

Nhược điểm:

* Thời gian truy cập: Việc truy cập các phần tử trong danh sách liên kết chậm hơn so với mảng hoặc cấu trúc dữ liệu khác cho phép truy cập ngẫu nhiên.

* Chi phí bộ nhớ: Mỗi nút trong danh sách liên kết yêu cầu bộ nhớ bổ sung để lưu trữ tham chiếu đến nút tiếp theo.

* Truy cập tuần tự: Không giống như mảng, việc truy cập các phần tử trong danh sách liên kết yêu cầu duyệt từ đầu danh sách.

# Bài 11: Stack - Queue

## 1. Stack

Stack (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 

**Các hoạt động liên quan đến ngăn xếp bao gồm:**

1. Push: Thêm một phần tử vào đầu ngăn xếp.

2. Pop: Loại bỏ phần tử trên cùng khỏi ngăn xếp.

3. Peek hoặc Top: Lấy giá trị phần tử ở trên cùng.

4. IsEmpty: Kiểm tra xem ngăn xếp có trống không.

5. Size: Xác định số lượng phần tử trong ngăn xếp.

Ngăn xếp được sử dụng rộng rãi trong các `thuật toán và ứng dụng như quản lý lệnh gọi hàm (ngăn xếp cuộc gọi trong ngôn ngữ lập trình), đánh giá biểu thức và thuật toán quay lui`.

## 2. Queue

Queue là một cấu trúc dữ liệu tuân theo nguyên tắc "First In, First Out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 

**Các hoạt động liên quan đến hàng đợi bao gồm:**

1. Enqueue: Thêm một phần tử vào cuối hàng đợi.

2. Dequeue: Loại bỏ một phần tử ở đầu hàng đợi.

3. Peek or Front: Giá trị phần tử đầu hàng đợi.

4. IsEmpty: Kiểm tra xem hàng đợi có trống không.

5. Size: Xác định số lượng phần tử trong hàng đợi.

Hàng đợi được sử dụng trong các tình huống trong đó các tác vụ được xử lý theo thứ tự nhận được, chẳng hạn như lập lịch công việc, thuật toán tìm kiếm theo chiều rộng và hàng đợi máy in.

# Bài 12: Binary search - File operations - Code standards

## 1. Binary search

Binary search là một thuật toán tìm kiếm hiệu quả được sử dụng để tìm kiếm một phần tử trong một mảng đã được sắp xếp theo thứ tự tăng dần (hoặc giảm dần). 
### Hoạt động của Binary search

Thuật toán này hoạt động bằng cách chia mảng thành các phần nhỏ hơn và so sánh phần tử cần tìm với phần tử ở giữa của mảng. Nếu phần tử cần tìm bằng với phần tử ở giữa, thuật toán kết thúc.Nếu phần tử cần tìm lớn hơn phần tử ở giữa, thuật toán tiếp tục tìm kiếm ở nửa phải của mảng, ngược lại, nếu nhỏ hơn, tiếp tục tìm kiếm ở nửa trái của mảng. Thuật toán lặp lại quá trình này cho đến khi tìm thấy phần tử hoặc mảng đã được thăm hết mà không tìm thấy phần tử.

Thuật toán binary search hoạt động nhanh chóng trên các mảng đã được sắp xếp và có độ phức tạp thời gian là O(log n), trong đó n là kích thước của mảng.

## 2. File operations

File operations là các hoạt động thao tác với tập tin trên hệ thống máy tính. Các hoạt động này bao gồm đọc từ tập tin, ghi vào tập tin, xóa tập tin, di chuyển hoặc đổi tên tập tin, và kiểm tra sự tồn tại của tập tin.

Các hoạt động tập tin có thể liên quan đến việc nhập xuất dữ liệu, lưu trữ cấu trúc dữ liệu, cài đặt các cơ chế lưu trữ dữ liệu như cơ sở dữ liệu, và nhiều ứng dụng khác. Điều này rất quan trọng trong việc xử lý thông tin trong môi trường máy tính.

### File CSV (Comma-Separated Values)

File CSV (Comma-Separated Values) là một loại định dạng tập tin dữ liệu được sử dụng để lưu trữ và truyền tải dữ liệu dưới dạng văn bản, trong đó mỗi dòng của tập tin biểu diễn một bản ghi dữ liệu và các trường dữ liệu trong mỗi bản ghi được phân tách bằng dấu phẩy (,).

Ví dụ về một tập tin CSV: 
``` 
Name, Age, City
John, 25, New York
Alice, 30, London
Bob, 28, Paris
```

Trong ví dụ này, mỗi hàng đại diện cho một bản ghi, trong đó trường dữ liệu được phân tách bằng dấu phẩy. Điều này cho phép dữ liệu được dễ dàng đọc và xử lý bởi các chương trình máy tính.



C++

# Bài 13 Class
## 1. Declaring Object
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 
    
có thể khai báo một lớp bằng từ khóa "class", theo sau là tên lớp, các biến và hàm thành viên của nó.

 ``` C++
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...

protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa

public:
        // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...

}; 
```

## 2. Constructor

Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.

(method: là một hàm được liên kết với một lớp hoặc một đối tượng. Nó định nghĩa hành vi của các đối tượng của lớp. Các method được sử dụng để thực hiện các hành động hoặc thao tác nhất định trên các thành viên dữ liệu của lớp.)

``` C++
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;

    HinhChuNhat(){
        chieuDai = 10;
        chieuRong = 9;
    }

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};

int main()
{
    HinhChuNhat hinh1; // Constructor HinhChuNhat


    std::cout << "Chieu dai: " << hinh1.chieuDai << '\n';


    return 0;
}

```

## 3. Destructor

Destructor trong C++ là một method sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.

```C++
    ~HinhChuNhat(){
    }
```

## 4. Static keyword

 Khi một property(biến trong C) trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này

Khi một method trong class được khai báo với từ khóa static:
   - Method này độc lập với bất kỳ đối tượng nào của lớp.
   - Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại.
   - Method này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: .
   - Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class.
   - Method có phạm vi bên trong class và không thể truy cập con trỏ đối tượng hiện tại.

## 5. Binary search

Binary search là một thuật toán tìm kiếm trong một mảng đã được sắp xếp. 

Hoạt động của Thuật toán:

-  chia mảng thành các phần bằng nhau và so sánh giá trị cần tìm với phần tử ở giữa của mảng.
- Dựa vào kết quả so sánh, loại bỏ một nửa mảng mà giá trị cần tìm không thể nằm trong đó,
- Tiếp tục lặp lại cho đến khi tìm thấy giá trị cần tìm hoặc không còn phần tử nào để kiểm tra.


# Bài 14 OPP
## 1. Encapsulation
Tính đóng gói ( Encapsulation) là ẩn đi các property “ mật” khỏi người dùng. Bằng cách khai báo các property ở quyền truy cập private ( tức là không thể truy cập trực tiếp tới các property này).  

    thuộc tính (property) thường được hiểu là một đặc điểm hoặc thông tin thuộc về một đối tượng.
    Ví dụ, nếu bạn đang làm việc với lớp "Person", các thuộc tính của mỗi đối tượng "Person" có thể bao gồm tên, tuổi, địa chỉ, giới tính, vv.

Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta cung cấp các method ở quyền truy cập public.

``` C++
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    // Getter cho name
    string getName() {
        return name;
    }

    // Setter cho name
    void setName(string name) {
        this->name = name;
    }

    // Getter cho age
    int getAge() {
        return age;
    }

    // Setter cho age
    void setAge(int age) {
        if (age >= 0) {
            this->age = age;
        } else {
            cout << "Invalid age!" << endl;
        }
    }
};

int main() {
    // Tạo một đối tượng Person
    Person person("Alice", 30);

    // Sử dụng các phương thức public để đọc và ghi dữ liệu
    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    person.setName("Bob");
    person.setAge(-5); // Test invalid age

    cout << "New name: " << person.getName() << endl;
    cout << "New age: " << person.getAge() << endl;

    return 0;
}

```
## 2. Inheritance
Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác

- class con (child class hoặc subclass), sử dụng (kế thừa) các thuộc tính và phương thức của class cha (parent class hoặc base class)


Tất cả những property và method có quyền truy cập là public và protected ở class cha sẽ được class con kế thừa.

Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.

Kiểu kế thừa:

    public: 
        - các thành viên public của lớp cha trở thành các thành viên public của lớp con
        - các thành viên protected của lớp cha trở thành các thành viên protected của lớp con

    protected:
        - Các thành viên public và protected của lớp cha trở thành các thành viên protected của lớp con.

    private:
        - Các thành viên public và protected của lớp cha trở thành các thành viên private của lớp con.
```c++
#include <iostream>
#include <string>

using namespace std;

// Lớp cha
class Animal {
protected: // protected để cho lớp con truy cập
    string name;

public:
    Animal(string name) : name(name) {}

    void speak() {
        cout << "Animal speaks" << endl;
    }

    void setName(string name) {
        this->name = name;
    }
};

// Lớp con kế thừa từ lớp cha
class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    // Override phương thức speak của lớp cha
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog dog("Buddy");
    dog.speak(); // Gọi phương thức speak của lớp con

    dog.setName("Max"); // Gọi phương thức setName của lớp cha

    return 0;
}

```

## 3. Polymorphism

Đa hình (Polymorphism) cho phép một object (đối tượng) có thể được xử lý dưới nhiều cách khác nhau. một method (phương thức) có thể được triển khai ở nhiều lớp khác nhau và thể hiện 1 hành động theo nhiều cách khác nhau. ( Function overriding - nạp chồng)

Function overloading cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/efc6bbe4-aa63-4560-b53c-1aaeabb84c81)

Có hai loại đa hình:

    1.  Đa hình cơ bản (Compile-time Polymorphism): 
    - xảy ra tại thời gian biên dịch.
    - ví dụ cơ bản là overload hàm (hàm đa nạng) trong C++. 
    - Trong overload hàm, có thể định nghĩa nhiều hàm có cùng tên nhưng có số lượng và kiểu dữ liệu tham số khác nhau.
    Compiler sẽ quyết định hàm nào sẽ được gọi dựa trên kiểu và số lượng tham số được truyền vào.

    2. Đa hình động (Runtime Polymorphism): 
    - xảy ra tại thời điểm chương trình đang chạy.
    - Trong C++, đa hình động thường được thực hiện thông qua việc sử dụng hàm ảo (virtual functions) và kế thừa.
    - Khi một phương thức được khai báo là virtual trong lớp cha và được ghi đè trong lớp con,
    việc quyết định phương thức nào sẽ được gọi được thực hiện tại thời điểm chạy dựa trên loại thực sự của đối tượng.
    -Điều này cho phép chúng ta gọi cùng một phương thức trên các đối tượng của các lớp con khác nhau và có hành vi khác nhau.

ví dụ về đa hình động trong C++ sử dụng hàm ảo (virtual functions):

``` C++
#include <iostream>
using namespace std;

// Lớp cơ sở (base class) lớp cha
class Animal {
public:
    // Phương thức ảo
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Lớp kế thừa (derived class) lớp con
class Dog : public Animal {
public:
    // Ghi đè phương thức ảo của lớp cha
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

// Lớp kế thừa khác (derived class) lớp con
class Cat : public Animal {
public:
    // Ghi đè phương thức ảo của lớp cha
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Gọi phương thức speak tùy thuộc vào loại đối tượng thực sự
    for (int i = 0; i < 2; i++) {
        animals[i]->speak();
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}
```

lớp Animal có một phương thức ảo speak(). Cả hai lớp con Dog và Cat đều ghi đè phương thức speak() của lớp cha Animal. Khi chúng ta gọi phương thức speak() trên một con trỏ của lớp Animal, hành vi được quyết định tại thời điểm chạy dựa trên loại thực sự của đối tượng được tạo ra.

## 4. Abstraction

Tính trừu tượng (Abstraction) cho phép ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.

tạo ra một lớp cơ sở (base class) hoặc một giao diện (interface) mà không cần cung cấp các chi tiết cụ thể về cách nó hoạt động bên trong. 

Lớp trừu tượng không thể được khởi tạo, nhưng nó có thể có các phương thức trừu tượng, các phương thức này chỉ được định nghĩa mà không cung cấp triển khai cụ thể. Các lớp con phải triển khai các phương thức trừu tượng này để có thể được khởi tạo.

ví dụ về trừu tượng trong C++:
``` C++
#include <iostream>
using namespace std;

// Lớp trừu tượng
class Shape {
public:
    // Phương thức trừu tượng tính diện tích
    virtual float area() = 0;

    // Phương thức trừu tượng tính chu vi
    virtual float perimeter() = 0;
};

// Lớp con kế thừa từ lớp trừu tượng Shape
class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float length, float width) : length(length), width(width) {}

    // Triển khai phương thức area cho hình chữ nhật
    float area() override {
        return length * width;
    }

    // Triển khai phương thức perimeter cho hình chữ nhật
    float perimeter() override {
        return 2 * (length + width);
    }
};

int main() {
    // Khởi tạo một đối tượng Rectangle
    Rectangle rect(5, 3);

    // In diện tích và chu vi của hình chữ nhật
    cout << "Area of rectangle: " << rect.area() << endl;
    cout << "Perimeter of rectangle: " << rect.perimeter() << endl;

    return 0;
}

```
Trong ví dụ này, lớp trừu tượng Shape có hai phương thức trừu tượng area() và perimeter(). Lớp con Rectangle triển khai các phương thức này để tính diện tích và chu vi của hình chữ nhật.

# Bài 15: Standard template library

Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.

Một số thành phần chính của STL:
- Container
- Iterator
- Algorithms
- Functor

## 1. Containers

Một container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể. STL (Standard Template Library) cung cấp một số container tiêu biểu giúp lưu trữ và quản lý dữ liệu. 

### 1.1 Vector

 Vector là một mảng động có thể mở rộng tự động khi cần.

- Các phần tử được lưu trữ dưới dạng một dãy liên tiếp trong bộ nhớ.
- **Truy cập ngẫu nhiên:** truy cập ngãu nhiên vào các phần tử thông qua chỉ số.
- **Hiệu suất chèn và xóa:** Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.


Một số method của vector:
- at(): Truy cập vào phần tử của vector
- size(): Trả về kích thước của vector
- resize(): Thay đổi kích thước của vector
- begin(): Địa chỉ của phần tử đầu tiên của vector
- push_back(): Thêm phần tử vào vị trí cuối của vector
- end(): Địa chỉ của phần tử cuối cùng của vector


### 1.2 List

Triển khai dưới dạng danh sách liên kết hai chiều

- **Truy cập tuần tự:** Truy cập các phần tử của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
- **Hiệu suất chèn và xóa:** Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm/xóa ở giữa danh sách.

Một số method của list:
- push_back():
- pop_back():
- insert(): Chèn một node vào list
- erase(): Xóa một node của list
- size(): Trả về kích thước của list


<table>
<thead>
<tr>
<th>Sử dụng vector khi </th>
<th>Sử dụng list khi </th>
</tr>
</thead>
<tbody>
<tr>
<td>Cần truy cập ngẫu nhiên đến các phần tử.</td>
<td> </td>
</tr>

<tr>
<td>Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách. </td>
<td>Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách. </td>
</tr>

<tr>
<td> </td>
<td>Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.</td>
</tr>

<tr>
<td>Dung lượng có thể biết trước hoặc thay đổi ít.</td>
<td>Dung lượng không quan trọng hoặc thay đổi thường xuyên.</td>
</tr>

</table>




Tùy thuộc vào yêu cầu cụ thể của vấn đề, bạn có thể chọn sử dụng std::vector hoặc std::list.


### 1.3 Map

cung cấp một cấu trúc dữ liệu ánh xạ key-value

- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map
        
### 1.4 Array

Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)

- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []

``` C++
#include <iostream>
#include <array>

using namespace std;


int main()
{
  
    array <int, 5> arr = {2,3,1,7,6};
    // array<int,0> arr;


    if (arr.empty())
    {
        cout << "Array is empty" << endl;
    }
    else
    {
        cout << "Array it not empty" << endl;
    }
    

    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Value: " << arr.at(i) << endl;
    }
    

    return 0;
}

```

## 2. Iterator

Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.

- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container

Chúng làm giảm độ phức tạp và thời gian thực hiện của chương trình.
 https://www.geeksforgeeks.org/iterators-c-stl/

 ## 3. Algorithm

 Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 

 
 vd thuật toán sắp xếp
  ```C++
  #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    vector <int> arr = {3,5,7,4,1};

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end());
    
    cout << "vector after sort ascending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "vector after sort descending: " << endl;

    for (auto const var : arr)
    {
        cout << "Vector: " << var << endl;
    }

    return 0;
}


 ```

 vd thuật toán tìm kiếm

 ```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};
    
    auto it = find(arr1.begin(), arr1.end(), 5);
    
    if (it != arr1.end())
    {
        cout << "Da tim thay" << endl;
        cout << *it;

        int position = it - arr1.begin(); // Calculate the position
        cout << "Vi tri cua phan tu: " << position << endl;
    }
    else
    {
        cout << "Khong tim thay" << endl;
    }
    
    return 0;
}


 ```

# Bài 16: Generic Programming
## 1. Template
    công cụ trong C++, đơn giản kiểu truyền dữ liệu dưới dạng tham số để sử dụng cho nhiều kiểu dữ liệu khác nhau cho cùng 1 mã.

- Write once, use for any data type
## Hoạt động của template
    Mẫu được mở rộng tại thời điểm biên dịch. Điều này giống như macro. Sự khác biệt là trình biên dịch thực hiện kiểm tra kiểu trước khi mở rộng mẫu. Ý tưởng rất đơn giản, mã nguồn chỉ chứa hàm/lớp, nhưng mã biên dịch có thể chứa nhiều bản sao của cùng một hàm/lớp.
-Like MACRO, proceesed by compiler. But better than macro as type checking is beformed


   ![image](https://github.com/user-attachments/assets/2e198602-fa34-4a76-bb7c-687f85fdb86f)



## 1. Function template: 
   Viết 1 hàm sử dụng cho nhiều kiểu dữ liệu khác nhau. Ví dụ về các mẫu hàm là sort(), max(), min(), printArray(). 

- Sort, linear search, binary seach
EX:
```c++
    // C++ Program to demonstrate
// Use of template
#include <iostream>
using namespace std;

// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T> 
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // int result = myMAx(3,7); cout << myMAx << endl;

    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;

    return 0;
}
```
# 2. Class templates 
Tương tự funtion templatres, áp dụng cho class. Cho phép viết một lớp chung sử dụng với nhiều kiểu dữ liệu khác nhau 
- LinkedList, BinaryTree, Stack, Queue, Array, v.v. 

``` c++
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyContainer {
private:
    T element;

public:
    MyContainer(T val) : element(val) {}

    T getValue() const {
        return element;
    }
};

int main()
{

    MyContainer<int> intContainer(42);
    MyContainer<double> doubleContainer(3.14);
    MyContainer<string> stringContainer("Trung");

    int intValue = intContainer.getValue();
    double doubleValue = doubleContainer.getValue();
    string stringValue = stringContainer.getValue();

    cout << "int value: " << intValue << endl;
    cout << "double value: " << doubleValue << endl;
    cout << "string value: " << stringValue << endl;

    return 0;
}

```
# 3. Advanced template techniques
 ## 1. Metaprogramming
 Mục đích: Tính toán giai thừa tại thời điểm biên dịch.
 ```c++
 #include <iostream>

 using namespace std;
 
template <unsigned int n>
struct Factorial {
 enum 
 { 
 value = n * Factorial<n - 1>::value 
 };
};
 
template <>
struct Factorial<0> {
 enum { value = 1 };
};

int main() {
 cout << "Factorial of 5 is " << Factorial<5>::value << endl;
 return 0;
}
 
 ```
## 2. Expression Templates
Thực hiện một phép cộng đơn giản giữa hai số nguyên
```c++
#include <iostream>

using namespace std;

template <typename A, typename B>
class AddExpr {
private:
    const A& a;
    const B& b;

public:
    AddExpr(const A& a, const B& b) : a(a), b(b) {}

    
    int eval() const {
        return a + b;
    }
};


template <typename A, typename B>
AddExpr<A, B> add(const A& a, const B& b) {
    return AddExpr<A, B>(a, b);
}

int main() {
    int x = 5,	y = 3;


    auto expr = add(x, y);


    cout << "Result: " << expr.eval() << endl; // Output: 8

    return 0;
}

```
## 3. Variadic Templates
Mục đích: Tạo một hàm có thể chấp nhận số lượng tham số đầu vào không xác định.
```c++
#include <iostream>

using namespace std;

void print1()
{
    cout << endl;
}

template<typename T, typename... Rest>
void print1(T first, Rest... rest) {
    cout << first << endl;
    print1(rest...);
}


template <typename... Args>
void print(Args... args) {
 (cout << ... << args) << '\n';
}

int main() {
 print(1, 2, 3, "hello", 4.5, "Trung", 55);
 return 0;
}
```

https://www.geeksforgeeks.org/templates-cpp/




# Bài 17 Smart Pointer - Lambda
## 1. Cấp phát động trong C++
new và delete là hai toán tử quan trọng trong C++ được sử dụng để cấp phát và giải phóng bộ nhớ động, tương ứng. Các toán tử này thường được sử dụng khi làm việc với đối tượng được cấp phát động, như là đối tượng được tạo trong vùng nhớ heap.
```c++
int *ptr = new int; // cấp phát bộ nhớ cho một biến kiểu int
int *arr = new int[5]; // cấp phát bộ nhớ cho một mảng kiểu int với 5 phần tử

delete ptr; // giải phóng bộ nhớ của biến động
delete[] arr; // giải phóng bộ nhớ của mảng động

```
### Khái niệm
Trong C++, smart pointers là một cơ chế quản lý bộ nhớ tự động 
giúp giảm thiểu rủi ro của lỗi liên quan đến quản lý bộ nhớ 
và giúp người lập trình tránh được việc quên giải phóng bộ nhớ 
đã được cấp phát.

```C++
#include <iostream>
using namespace std;
 
 // tạo class để sủ dụng SmartPtr
class SmartPtr {
private:
    int* ptr; 
public:
    SmartPtr(int* p = NULL) { ptr = p; }
 
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
    int getValue()
    {
        return *ptr;
    }
    // method lấy giá trị địa chỉ ptr
    void setValue(int value)
    {
        *ptr = value;
    }
};
 
int main()
{
    SmartPtr ptr(new int);
    // *ptr = 20;
    ptr.setValue(50);
    cout << "Value: " << ptr.getValue() << endl;
    // cout << "Value: " << *ptr << endl;
  
 
 
    return 0;
}

```
## 2. Unique Pointer
unique_ptr là một loại smart pointer trong C++, giúp quản lý bộ nhớ động và tự động giải phóng bộ nhớ khi không còn cần thiết. Nó được khai báo trong thư viện `<memory>` và được biểu diễn bởi lớp `std::unique_ptr`.

### Đặc điểm:  
1. Quyền sở hữu duy nhất:

- Một std::unique_ptr chỉ có thể sở hữu một tài nguyên (ví dụ, một con trỏ) tại một thời điểm.
- Không thể sao chép một std::unique_ptr sang một std::unique_ptr khác (copy semantics bị cấm). Điều này đảm bảo rằng chỉ có một thực thể duy nhất chịu trách nhiệm quản lý và giải phóng tài nguyên đó.
2. Di chuyển quyền sở hữu (Move Semantics):

- Quyền sở hữu của std::unique_ptr có thể được chuyển (moved) từ đối tượng này sang đối tượng khác bằng cách sử dụng `std::move`.
3. Tự động giải phóng tài nguyên:

- Khi một std::unique_ptr bị hủy (out of scope), nó tự động giải phóng tài nguyên mà nó sở hữu. Điều này giúp tránh lỗi rò rỉ bộ nhớ (memory leak).
4. Hiệu quả:

- std::unique_ptr nhẹ và hiệu quả vì nó không yêu cầu một bộ đếm tham chiếu (reference count) như std::shared_ptr.
### Cách sử dụng
```cpp
#include <iostream>
#include <memory> // Để sử dụng std::unique_ptr

int main() {
    // Tạo một unique_ptr quản lý một con trỏ
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    // Truy cập giá trị
    std::cout << "Giá trị: " << *ptr << std::endl;

    // Chuyển quyền sở hữu
    std::unique_ptr<int> new_ptr = std::move(ptr);

    if (!ptr) {
        std::cout << "ptr không còn sở hữu tài nguyên!" << std::endl;
    }

    std::cout << "new_ptr giá trị: " << *new_ptr << std::endl;

    // Khi new_ptr ra khỏi phạm vi, tài nguyên sẽ tự động được giải phóng.
    return 0;
}
```
### Ưu điểm: 

1. Đảm bảo an toàn bộ nhớ (memory safety).
2. Tránh lỗi double-delete hoặc rò rỉ bộ nhớ.
3. Hỗ trợ mạnh mẽ cho các ứng dụng cần quản lý tài nguyên động.

### Nhược điểm:
1. Không phù hợp nếu cần chia sẻ quyền sở hữu tài nguyên giữa nhiều đối tượng (trường hợp này nên dùng std::shared_ptr).

std::unique_ptr thường được sử dụng khi tài nguyên chỉ được sở hữu bởi `một đối tượng duy nhất`, như trong lập trình hướng đối tượng và các ứng dụng đa luồng.


## 3. Shared Pointer
Shared Pointer là một khái niệm trong lập trình C++ được cung cấp bởi lớp `std::shared_ptr` (thuộc thư viện `<memory>`). Nó cũng thuộc nhóm smart pointers, nhưng khác với `std::unique_ptr`, `std::shared_ptr` cho phép chia sẻ quyền sở hữu tài nguyên giữa nhiều con trỏ thông minh.

### Đặc điểm 
1. Chia sẻ quyền sở hữu( Shared Ownership):
    - Nhiều `shared_ptr` có thể cùng sở hữu một tài nguyên duy nhất.
    - Tài nguyên chỉ được giải phóng (hủy) khi tất cả các `shared_ptr` ngừng sử dụng tài nguyên đó (khi bộ đếm tham chiếu về 0).
2. Bộ đếm tham chiếu (Reference Count):
    - `shared_ptr` sử dụng một bộ đếm tham chiếu để theo dõi số lượng `shared_ptr` đang sở hữu cùng một tài nguyên.
    - Khi một `shared_ptr`  mới được sao chép từ `shared_ptr` hiện tại, bộ đếm tham chiếu tăng lên.
    - Khi một `shared_ptr` bị hủy hoặc được gán giá trị mới, bộ đếm tham chiếu giảm xuống.
3. Quản lý tài nguyên tự động:
    - Khi bộ đếm tham chiếu về 0, `shared_ptr` tự động giải phóng tài nguyên mà nó sở hữu.
4. Hiệu quả hơn `unique_ptr` trong trường hợp **chia sẻ tài nguyên**, nhưng có chi phí thêm để duy trì bộ nhớ tham chiếu.
### Cách sử dụng: 
 ``` cpp
#include <iostream>
#include <memory> // Để sử dụng std::shared_ptr

int main() {
    // Tạo shared_ptr quản lý một con trỏ
    std::shared_ptr<int> ptr1 = std::make_shared<int>(10);

    // Tạo shared_ptr khác chia sẻ quyền sở hữu với ptr1
    std::shared_ptr<int> ptr2 = ptr1;

    std::cout << "Giá trị: " << *ptr1 << std::endl;
    std::cout << "Bộ đếm tham chiếu: " << ptr1.use_count() << std::endl;

    {
        // Thêm một shared_ptr trong scope mới
        std::shared_ptr<int> ptr3 = ptr1;
        std::cout << "Bộ đếm tham chiếu trong scope: " << ptr1.use_count() << std::endl;
    }

    // Ra khỏi scope, bộ đếm tham chiếu giảm
    std::cout << "Bộ đếm tham chiếu sau scope: " << ptr1.use_count() << std::endl;

    return 0;
}

 ```
### Ưu điểm:
1. Quản lý tài nguyên chia sẻ một cách an toàn.
2. Tự động giải phóng tài nguyên khi không còn sử dụng, giảm nguy cơ rò rỉ bộ nhớ (memory leak).
3. Dễ dàng sử dụng trong các cấu trúc phức tạp như đồ thị (graph) hoặc cây (tree), nơi tài nguyên có thể được tham chiếu từ nhiều nơi.
### Nhược điểm:
1. Chi phí bộ đếm tham chiếu:
    - Quá trình tăng/giảm bộ đếm tham chiếu có thể gây ảnh hưởng hiệu năng trong một số trường hợp.
2. Vấn đề vòng lặp tham chiếu (Circular References):
    - Nếu hai `shared_ptr` tham chiếu lẫn nhau (vòng lặp tham chiếu), tài nguyên sẽ không bao giờ được giải phóng. Trường hợp này cần dùng `weak_ptr`.

## 4. Weak Pointer 
Weak Pointer là một loại smart pointer trong C++ được cung cấp bởi lớp `std::weak_ptr`, nằm trong thư viện `<memory>`. Nó thường được sử dụng cùng với `std::shared_ptr` để giải quyết vấn đề vòng lặp tham chiếu (circular references), một trong những nhược điểm lớn của `std::shared_ptr`.

### Đặc điểm 
1. Không sở hữu tài nguyên:
    - `weak_ptr` không trực tiếp sở hữu tài nguyên mà nó trỏ tới.
    - Nó hoạt động như một "quan sát viên" (observer) của tài nguyên được quản lý bởi `shared_ptr`
2. Không tăng bộ đếm tham chiếu:
    - Khi một `weak_ptr` trỏ đến tài nguyên được quản lý bởi `shared_ptr`, nó không làm tăng bộ đếm tham chiếu của `shared_ptr`.
3. Giải quyết vòng lặp tham chiếu:
    - `weak_ptr` được dùng để phá vỡ các vòng lặp tham chiếu, đảm bảo tài nguyên được giải phóng khi không còn ai sử dụng nó.
4. Kiểm tra hợp lệ:
    - Vì không sở hữu tài nguyên, `weak_ptr có thể trở nên không hợp lệ nếu tài nguyên mà nó quan sát đã bị giải phóng.
    - Dùng hàm `expired()` hoặc chuyển đổi thành `shared_ptr` bằng cách gọi `lock()` để kiểm tra và sử dụng tài nguyên.

### Cách sử dụng:
```cpp
#include <iostream>
#include <memory>

int main() {
    // Tạo shared_ptr quản lý tài nguyên
    std::shared_ptr<int> shared = std::make_shared<int>(100);

    // Tạo weak_ptr quan sát shared_ptr
    std::weak_ptr<int> weak = shared;

    // Kiểm tra trạng thái của weak_ptr
    if (auto sp = weak.lock()) { // Chuyển weak_ptr thành shared_ptr
        std::cout << "Tài nguyên còn tồn tại: " << *sp << std::endl;
    } else {
        std::cout << "Tài nguyên đã bị giải phóng." << std::endl;
    }

    // Giải phóng shared_ptr
    shared.reset();

    // Kiểm tra lại weak_ptr
    if (weak.expired()) {
        std::cout << "Tài nguyên không còn tồn tại." << std::endl;
    }

    return 0;
}
```
### Ví dụ vòng lặp tham chiếu:
Trong trường hợp hai `std::shared_ptr` tham chiếu lẫn nhau, tài nguyên sẽ không bao giờ được giải phóng. `std::weak_ptr` có thể được sử dụng để khắc phục điều này.

**Mô hình vòng lặp tham chiếu:**
```cpp
#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev; // Dùng weak_ptr để phá vỡ vòng lặp
    Node() { std::cout << "Node được tạo.\n"; }
    ~Node() { std::cout << "Node bị hủy.\n"; }
};

int main() {
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    // Tạo liên kết hai chiều giữa node1 và node2
    node1->next = node2;
    node2->prev = node1;

    // Khi node1 và node2 ra khỏi scope, tài nguyên được giải phóng
    return 0;
}
```
### Ưu điểm:
1. Giải quyết vòng lặp tham chiếu:
    - Đảm bảo các tài nguyên được giải phóng đúng cách.
2. Kiểm soát tài nguyên một cách linh hoạt:
    - Cho phép truy cập tài nguyên mà không sở hữu nó.
### Nhược điểm:
1. Không thể trực tiếp truy cập tài nguyên:
    - Phải chuyển đổi sang std::shared_ptr bằng cách sử dụng lock().

## So sánh unique_ptr, shared_ptr và weak_ptr

|Đặc điểm	|std::unique_ptr|	std::shared_ptr|	std::weak_ptr|

Sở hữu tài nguyên	Duy nhất	Chia sẻ	Không sở hữu
Bộ đếm tham chiếu	Không có	Có (tăng khi sao chép)	Không làm tăng bộ đếm
Vòng lặp tham chiếu	Không xảy ra	Có thể xảy ra	Dùng để giải quyết vấn đề này

| Đặc điểm  | unique_ptr | shared_ptr | weak_ptr|
| --------  | --------   | --------   | ------- |
| Sở hữu tài nguyên | Duy nhất   | Chia sẻ  | Không sở hữu|
| Bộ đếm tham chiếu   | Không có  | Có (tăng khi sao chép)  |Không làm tăng bộ đếm|
|Vòng lặp tham chiếu| Không xảy ra| Có thể xảy ra| Dùng để giải quyết vòng lặp tham chiếu|

