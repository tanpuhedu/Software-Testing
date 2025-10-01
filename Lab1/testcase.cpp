#include <iostream>
#include <cmath>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1;
    }
    
    if (a == 0 && b == 0) {
        return 0;
    }
    
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    
    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;
    
    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);
    
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    
    return count;
}

int main() {
    double x[4];
    int result;
    
    cout << "=== TEST CHƯƠNG TRÌNH GIẢI PHƯƠNG TRÌNH BẬC 4 TRÙNG PHƯƠNG ===\n";
    
    // Test 1: Vô số nghiệm (0, 0, 0)
    cout << "\nTest 1: a=0, b=0, c=0 (vô số nghiệm)\n";
    result = solveQuartic(0, 0, 0, x);
    cout << "Kết quả: " << result << " (mong đợi: -1)\n";
    cout << (result == -1 ? "✓ PASS" : "✗ FAIL") << endl;
    
    // Test 2: Vô nghiệm (0, 0, 5)
    cout << "\nTest 2: a=0, b=0, c=5 (vô nghiệm)\n";
    result = solveQuartic(0, 0, 5, x);
    cout << "Kết quả: " << result << " (mong đợi: 0)\n";
    cout << (result == 0 ? "✓ PASS" : "✗ FAIL") << endl;
    
    // Test 3: Phương trình bậc 2, có nghiệm (0, 2, -8)
    cout << "\nTest 3: a=0, b=2, c=-8 (2 nghiệm: ±2)\n";
    result = solveQuartic(0, 2, -8, x);
    cout << "Kết quả: " << result << " nghiệm (mong đợi: 2)\n";
    if (result == 2) {
        cout << "Nghiệm: " << x[0] << ", " << x[1] << endl;
        cout << "✓ PASS" << endl;
    } else {
        cout << "✗ FAIL" << endl;
    }
    
    // Test 4: Delta < 0, vô nghiệm (1, 2, 5)
    cout << "\nTest 4: a=1, b=2, c=5 (delta < 0, vô nghiệm)\n";
    result = solveQuartic(1, 2, 5, x);
    cout << "Kết quả: " << result << " (mong đợi: 0)\n";
    cout << (result == 0 ? "✓ PASS" : "✗ FAIL") << endl;
    
    // Test 5: Delta > 0, có nghiệm (1, 0, -4)
    cout << "\nTest 5: a=1, b=0, c=-4 (2 nghiệm: ±√2)\n";
    result = solveQuartic(1, 0, -4, x);
    cout << "Kết quả: " << result << " nghiệm (mong đợi: 4)\n";
    if (result > 0) {
        cout << "Nghiệm: ";
        for (int i = 0; i < result; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    cout << (result == 2 ? "✓ PASS" : "✗ FAIL") << endl;
    
    cout << "\n=== KẾT THÚC TEST ===\n";
    return 0;
}