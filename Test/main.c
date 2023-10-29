#include <stdio.h>

int solution(int N) {
    int maxGap = 0; //lưu trữ độ dài của khoảng cách nhị phân dài nhất được tìm thấy
    int currentGap = 0; //lưu trữ độ dài của khoảng cách nhị phân dài nhất hiện tại
    int count = 0; //cờ để cho biết đang đếm khoảng cách nhị phân

    // Bỏ qua các số 0 ở cuối
    while (N > 0 && (N & 1) == 0) {
        N >>= 1; // Dịch bit sang phải một vị trí và gán kết quả vào N
    }

    while (N > 0) {
        if ((N & 1) == 0) {
            if (count) {
                currentGap++;
            }
        } else {
            count = 1;
            if (currentGap > maxGap) {
                maxGap = currentGap;
            }
            currentGap = 0;
        }
        N >>= 1;
    }
    return maxGap;
}

int main() {
    int N;
    printf("Enter N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Value N is invalid!\n");
        return 1; // Thoát chương trình với mã lỗi
    }
    int longestGap = solution(N);
    printf("Longest binary gap: %d\n", longestGap);
    return 0;
}