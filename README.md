# advanced-C
> ## Bài 1: Compiler - Macro
## Compiler
 Compiler: Chuyển đổi ngôn ngữ bậc cao sang mã máy

![alt](https://media.geeksforgeeks.org/wp-content/uploads/compilerP.jpg)
## Quá trình biên dịch gồm 4 giai đoạn

- Giai đoạn tiền xử lý (Pre-processor):

  Thực hiện định nghĩa macro (#define), chèn nội dung của các file header (#include), loại bỏ comment.
- Giai đoạn dịch NNBC sang Assembly (Compiler):

  Trình biên dịch (compiler) chuyển đổi mã nguồn viết bằng ngôn ngữ lập trình thành mã Assembly tương ứng.

- Giai đoạn dịch Assembly sang ngôn ngữ máy (Assembler):

  Mã Assembly được chuyển đổi thành mã máy tương ứng

- Giai đoạn liên kết (Linker)

  File đối tượng (object files) được tạo ra từ các quá trình biên dịch trước đó được kết hợp lại thành một file thực thi hoàn chỉnh.

  Linker cũng giải quyết các tham chiếu tới các hàm và biến nằm ở các file object khác nhau, tạo ra các liên kết (links) giữa chúng, đảm bảo các tên và tham chiếu đúng khi chương trình được thực thi.
![image](https://github.com/hnaht1126/advanced-C/assets/152061415/92dd1506-ce76-49b6-95ec-ece00275b46f)


- file .i  được tạo ra từ các file mã nguồn C/C++ thông qua trình biên dịch hoặc trình dịch mã nguồn - đã được viết dưới dạng mã nguồn gốc, cũng như có thể chứa các chỉ thị và định nghĩa cho trình biên dịch.

- file .s thường là các tệp mã nguồn dạng văn bản chứa mã nguồn đã được viết bằng một ngôn ngữ lập trình hợp ngữ như Assembly.

- flie .exe thường là các tệp chứa mã máy thực thi cho các ứng dụng chạy trên hệ điều hành Windows

## Macro
Chỉ những thông tin được xử lý ở quá trình tiền xử lý ( Preprocessor).

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

Ví dụ về sử dụng #define để định nghĩa hằng số:
```
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
Ví dụ về sử dụng #define để tạo ra macro:
```
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

```
#define MAX_SIZE 100
#undef MAX_SIZE
```
' #undef ' MAX_SIZE sẽ hủy bỏ định nghĩa của macro MAX_SIZE trước đó, khiến cho các lần sử dụng MAX_SIZE sau đó sẽ không còn hiệu lực.

#undef thường được thực hiện khi cần thay đổi hoặc ghi đè lên các định nghĩa macro trong mã nguồn.


## #if, #elif, và #else
#if: Directive này cho phép kiểm tra một điều kiện và biên dịch một phần của mã nguồn nếu điều kiện đó là đúng.

#elif: Là viết tắt của "else if" và được sử dụng để kiểm tra một điều kiện mới nếu điều kiện trước đó không đúng.

#else: Được sử dụng khi không có điều kiện nào trong #if hoặc #elif trước đó là đúng.

```
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







