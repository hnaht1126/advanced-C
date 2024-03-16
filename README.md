advanced-C

# Bài 1: Compiler - Macro

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
/*
- Nếu DEBUG_MODE được định nghĩa là 1, câu lệnh printf("Debug mode is enabled.\n"); sẽ được biên dịch.
- Nếu DEBUG_MODE là 0, câu lệnh printf("Debug mode is disabled.\n"); sẽ được biên dịch.
- Nếu không có giá trị nào của DEBUG_MODE được định nghĩa, câu lệnh printf("Unknown debug mode.\n"); sẽ được biên dịch.
*/
```


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

# Bài 3: Pointer

## Pointer
Pointer là một biến chứa địa chỉ bộ nhớ của một biến khác

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/b01a0c93-6b2f-42a9-b52c-b22cf9c3f130)

Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch

## Void Pointer
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
## [Function pointer](https://www.geeksforgeeks.org/function-pointer-in-c/?ref=lbp) 

Con trỏ hàm (function pointer) là một biến có kiểu dữ liệu là con trỏ, nhưng thay vì chỉ trỏ đến một vùng nhớ chứa dữ liệu, nó trỏ đến một hàm cụ thể trong bộ nhớ. Con trỏ hàm cho phép chúng ta truy cập và thực thi các hàm thông qua biến con trỏ đó.

Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

```c
/*
gán ptr tới các hàm add và subtract, chúng ta có thể gọi các hàm này thông qua ptr,
cung cấp sự linh hoạt trong việc thay đổi hàm mà ptr trỏ tới mà không cần thay đổi mã nguồn.
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

## Pointer to Constant 

"Con trỏ tới hằng số" trong C và C++ dùng để chỉ `một con trỏ` trỏ tới một `giá trị không đổi`. Điều này có nghĩa là bản thân `con trỏ có thể thay đổi` (tức là nó có thể trỏ đến các vị trí bộ nhớ khác nhau), nhưng `giá trị được lưu trữ tại vị trí bộ nhớ mà nó trỏ tới không thể được sửa đổi thông qua con trỏ đó`.

(giá trị không đổi, con trỏ có thể trỏ tới chỗ khác )

```c
const int *ptr; // Pointer to a constant integer
```
Ứng dụng: bảo vệ dữ liệu không bị thay đổi

## Constant Pointer:
là một con trỏ `không thể` được sử dụng để sửa đổi giá trị(địa chỉ) mà nó trỏ tới, nhưng nó `có thể` được trỏ đến các vị trí khác. 

(địa chỉ con trỏ trỏ tới ko đổi, có thể thay đổi giá trị ở vùng nhớ tại địa chỉ đó)

```c
int *const ptr = &x; // Constant pointer to an integer
```

Ứng dụng: Đảm bảo con trỏ, trỏ đến đúng địa chỉ (vd trỏ đến đúng hàm cần sd)

## Pointer to Pointer

Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 

Con trỏ tới con trỏ cung cấp một cách tiếp cận linh hoạt đến bộ nhớ, cho phép thay đổi giá trị của con trỏ thứ hai để thay đổi địa chỉ mà nó trỏ tới.

Ứng dụng:  **Truyền con trỏ vào hàm**, **Sử dụng trong mảng 2 chiều**, **Sử dụng trong danh sách liên kết**.



# Bài 4: Memory layout


## Memory layout

Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.

## Memory layout

Việc tổ chức dữ liệu trong bộ nhớ của hệ thống máy tính. Nó xác định cách dữ liệu được lưu trữ, truy cập và quản lý trong hệ thống phân cấp bộ nhớ của hệ thống.

Bố cục bộ nhớ thường bao gồm việc sắp xếp các phân đoạn bộ nhớ khác nhau, chẳng hạn như:

![image](https://github.com/hnaht1126/advanced-C/assets/152061415/7868dafa-ceee-4d9d-9313-a8d52b7ec365)



## Code Segment (Text Segment)

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

## Data Segment

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

## Stack
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

 ## Heap

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
 ## Stack và Heap
Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.

Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

`Stack`: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.

`Heap`: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

>## Lỗi tràn bộ nhớ
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

## Extern 
- tự tìm biến đã được khai báo

Khi sử dụng `Extern` khai báo biến, trình biên dịch hiểu rằng biến đã được khai báo ở một nơi khác và trình biên dịch sẽ tìm kiếm biến này ở các file khác trong quá trình liên kết.

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

 ## Static global variables 
 - chỉ được sử dụng trong cùng một file mà nó được khai báo.

 **Ứng dụng:** dùng để thiết kế các file thư viện.

 Static global variables hay được gọi là "biến toàn cục tĩnh", là biến mà chỉ có phạm vi trong file mà nó được khai báo. Tức là, biến này **không thể truy cập từ các file khác thông qua việc sử dụng từ khóa extern**. Biến toàn cục tĩnh chỉ được sử dụng trong cùng một file mà nó được khai báo.
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
biến globalVar không thể truy cập từ các file khác thông qua extern.

## Static trong class 
Trong một lớp, **biến tĩnh (static member)** là một biến mà nó thuộc về lớp chứ không thuộc về mỗi đối tượng của lớp đó.

Mọi đối tượng của lớp đều chia sẻ một bản sao duy nhất của biến tĩnh. Các biến tĩnh được ***cấp phát bộ nhớ khi chương trình bắt đầu chạy và tồn tại cho đến khi chương trình kết thúc.***

Tương tự, **phương thức tĩnh (static method)** là một phương thức mà nó thuộc về lớp chứ không phải thuộc về các đối tượng của lớp đó. Phương thức tĩnh có thể được gọi mà không cần tạo ra một đối tượng của lớp đó.

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

## Volatile
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

## Register

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

# Bài 7: Bitmask

## Bitmask
Quá trình sửa đổi và sử dụng các biểu diễn nhị phân của số hoặc dữ liệu 

### bitwise
* OR (|) - đặt bit thành 1 nếu một trong hai bit tương ứng trong toán hạng là 1. (1 cái 1 -> 1)
* AND (&) - đặt một bit thành 1 nếu cả hai bit tương ứng trong toán hạng là 1.  (nhân lại ra 1 -> 1)
* XOR (^) - đặt bit thành 1 nếu các bit tương ứng trong toán hạng khác nhau. (tổng lẻ -> 1)
* NOT (~) - đặt 0 thành 1 và 1 thành 0.
* shif-left (<<)  - dịch bit sang trái. (xóa trái thêm 0 phải )
* shif- right (>>) - dịch bit sang phải. (xóa phải thêm 0 trái)
### dùng để luu các biến chỉ cần 2 giá trị (0/1) -> giảm bộ nhớ 
 




