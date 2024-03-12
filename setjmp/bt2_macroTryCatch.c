#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char* error_message;

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };


#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
//do while - thực thi 1 lần 
#define THROW(x, message)  error_message = (message); longjmp(buf, (x))


void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    // Bổ sung chương trình
    printf("Kết nối mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi network: Kết nôi mạng thất bại!.");
}

void calculateData() {
   // Bổ sung chương trình
   printf("Thực hiện phép toán... \n");
   THROW(CALCULATION_ERROR, "Lỗi tính toán: Dữ liệu không chính xác. ");
}



int main() {
 
 
 TRY {

        TRY{ 
            readFile();
        }CATCH(FILE_ERROR) {
            printf("%s\n", error_message);
        }

        TRY{
            networkOperation();
        }CATCH(NETWORK_ERROR) {
            printf("%s\n", error_message);
        }

        TRY{
            calculateData();
        } CATCH(CALCULATION_ERROR) {
            printf("%s\n", error_message);
        } 

    }
    printf("Kết thúc chương trình.\n");
    return 0;
}
