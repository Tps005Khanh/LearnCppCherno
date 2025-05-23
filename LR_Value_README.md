# Tham chiếu trong C++: const int&, int&, int&&

Tài liệu tóm tắt các loại tham chiếu trong C++, với minh họa để hiểu rõ sự khác nhau giữa `const int&`, `int&`, và `int&&` trong overload hàm.

---

## 1. Các kiểu tham chiếu

| Kiểu tham số        | Nhận giá trị      | Cho phép sửa | Bind đến     |
|---------------------|-------------------|--------------|-------------|
| `const int&`        | rvalue, lvalue     | ❌ không     | Cả hai       |
| `int&`              | lvalue             | ✅ có thể    | lvalue        |
| `int&&`             | rvalue             | ✅ có thể    | rvalue        |

---

## 2. Ví dụ overload hàm

```cpp
#include <iostream>

void func(const int& x) {
    std::cout << "const int& called\n";
}

void func(int& x) {
    std::cout << "int& called\n";
}

void func(int&& x) {
    std::cout << "int&& called\n";
}

int main() {
    int a = 10;
    func(a);      // --> int& called

    func(20);     // --> int&& called

    const int ca = 30;
    func(ca);     // --> const int& called
}
```

---

## 3. Quy tắc overload khi truyền tham số

| Truyền giá trị     | Được chọn overload       |
|------------------|---------------------------|
| Lvalue           | `int&` > `const int&`     |
| Rvalue           | `int&&` > `const int&`    |
| Const lvalue     | `const int&`              |

---

## 4. Ghi nhớ:

- `const int&` cho phép bind cả rvalue và lvalue, nhưng không cho sửa.
- `int&` chỉ cho lvalue, cho sửa.
- `int&&` chỉ cho rvalue, cho sửa, phù hợp cho move semantics.

---

## 5. Đề xuất mở rộng:

- Tìm hiểu về `T&&` trong template (universal reference).
- Dùng `std::forward<T>(x)` để perfect forwarding.
