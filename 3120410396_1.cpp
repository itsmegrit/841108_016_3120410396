#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int i = left, j = mid + 1;

	// khai báo mảng tạm (tempArr) chứa các giá trị của mảng truyền vào (arr) sau khi trộn
	int n = right - left + 1;
	int* tempArr = new int[n];
	int k = 0; //k là biến đếm của mảng tạm (arrTemp)

	// khi nửa mảng bên trái và nửa mảng bên phải vẫn còn phần tử chưa được trộn
	while ((i <= mid) && (j <= right)) {
		// nếu giá trị đang xét của mảng bên phải lơn hơn giá trị đang xét của mảng bên trái
		if (arr[i] < arr[j]) {
			// gán arr[i] vào cuối tempArr
			tempArr[k++] = arr[i++];
		}
		else {
			// gán arr[j] vào cuối tempArr
			tempArr[k++] = arr[j++];
		}
	}
	// khi nửa mảng bên trái vẫn còn phần tử chưa được trộn thì đổ toàn bộ những phần tử còn lại đó vào cuối tempArr
	while (i <= mid) {
		tempArr[k++] = arr[i++];
	}
	// khi nửa mảng bên phải vẫn còn phần tử chưa được trộn thì đổ toàn bộ những phần tử còn lại đó vào cuối tempArr
	while (j <= right) {
		tempArr[k++] = arr[j++];
	}
	// đổ tempArr vào lại arr
	i = left;
	for (k = 0; k < n; ++k) {
		arr[i++] = tempArr[k];
	}
	delete tempArr;
}

void mergeSort(int arr[], int left, int right) {
	// khi left = right tức là phần tử đầu tiên của mảng cũng là phần từ cuối của mảng
	// cũng có nghĩa là mảng đã được sắp xếp
	if (left == right) {
		return;
	}
	if (left < right) {
		// tìm ra vị trí nằm giữa mảng nhằm chia mảng ra làm hai phần (phần bên trái arr[mid] và phần bên phải arr[mid])
		int mid = (left + right) / 2;
		// gọi đệ quy sắp xếp phần bên trái arr[mid]
		mergeSort(arr, left, mid);
		// gọi đệ quy sắp xếp phần bên phải arr[mid]
		mergeSort(arr, mid + 1, right);
		// trộn phần bên trái và phần bên phải của mảng lại với nhau
		merge(arr, left, mid, right);
	}
}

void nhapMang(int arr[], int n) {
	puts("nhap cac phan tu cua mang (kieu int):");
	for (int i = 0; i < n; i++) {
		cout << "nhap phan tu thu " << "[" << i << "]: ";
		cin >> arr[i];
	}
}

void xuatMang(int arr[], int n) {
	puts("\ncac phan tu cua mang la:");
	for (int i = 0; i < n; i++) {
		printf("%10d", arr[i]);
	}
}

int main(int argc, char const *argv[]) {
	int arr[100];
	int n;
	puts("nhap so phan tu (khong lon hon 100):");
	cin >> n;
	nhapMang(arr, n);
	puts("\nmerge sort:");
	mergeSort(arr, 0, n - 1);
	xuatMang(arr, n);
	return 0;
}
