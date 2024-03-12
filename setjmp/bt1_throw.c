#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char* error_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
//do while - thực thi 1 lần 
#define THROW(x, message) do { error_code = (message); longjmp(buf, (x)); } while (0)

double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Lỗi: phép chia cho 0!"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    if (b == 5){
        THROW(2, "Lỗi: không cho chia 5!");
    }
    THROW(3, "Lỗi: Những lỗi khác!");

    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 6;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } 
    CATCH(1) {
        printf("%s\n", error_code);
    }
    CATCH(2) {
        printf("%s\n", error_code);
    }
    CATCH(3) {
        printf("%s\n", error_code);
    }
    // Các xử lý khác của chương trình
    return 0;
}
