#include <iostream>
using namespace std;

// cấu trúc của một node trong danh sách liên kết đơn
class Node {
public:
	int data;
	Node *next;
};

// khởi tạo một node
Node* initNode(int new_data) {
	Node* new_node = new Node(); // khai báo một đối tượng node mới
	new_node->data = new_data; // gán giá trị cho Node->data
	new_node->next = NULL; // Node mới có Node->next = NULL
	return new_node;
}

void push(Node** head_ref, int new_data) {
	Node* new_node = initNode(new_data); // khởi tạo Node
	new_node->next = (*head_ref); // new_node là Node đầu nên new_node->next sẽ là head cũ
	(*head_ref) = new_node; // head mới bây giờ chính là new_node
}

// thêm node vào cuối
void append(Node** head_ref, int new_data) {
	Node* new_node = initNode(new_data); // do thêm node vào cuối nên ta chỉ cần khởi tạo new_node và mặc định Node->next = NULL (tức node cuối)

	// nếu list rỗng thì gán node mới làm phần tử đầu tiên cho list và return để thoát khỏi hàm append
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	// ngược lại nếu list không rỗng thì khai báo một con trỏ last có giá trị = địa chỉ của head (nhằm giữ nguyên head)
	// sau khi duyệt hết list thì lúc này node cuối cùng chính là last, sau đó ta chỉ cần cho last->next = new_node (new_node lúc này sẽ thành node cuối)
	Node* last = *head_ref;
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;
	return;
}

// đảo chiều danh sách liên kết đơn
void reverseLinkedList(Node** head_ref) {
	Node* curr = *head_ref;
	Node* prev = NULL;
	Node* next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head_ref = prev;
	return;
}

// tìm kiếm node và trả về kết quả có hoặc không (true or false)
bool search(Node* head, int key) {
	Node* curr = head;
	while (curr != NULL) {
		if (curr->data == key) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

// tìm kiếm node trong danh sách liên kết đơn và trả về node đó
Node *searchNode(Node *head, int n) {
	Node *cur = head;
	while (cur) {
		if (cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "No Node " << n << " in list.\n";
	return NULL;
}

// liệt kê danh sách liên kết đơn
void printList(Node *node) {
	if (node == NULL) {
		cout << "list is null";
		return;
	}
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
}

// so sánh hai danh sách liên kết đơn
bool compareTwoLinkedList(struct Node* head1, struct Node* head2) {
	bool result = true;
	while (head1 != NULL && head2 != NULL) {
		if (head1->data != head2->data) {
			result = false;
			break;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return result;
}

Node* copyLinkedList (Node* head) {
	if (head != NULL) {
		Node *cur = head;
		Node* headCopy = initNode(head->data);

		cur = cur->next;
		while (cur) {
			append(&headCopy, cur->data);
			cur = cur->next;
		}

		return headCopy;
	}
	return NULL;
}

// xoá danh sách liên kết đơn
void deleteList(Node** head_ref) {
	Node* curr = *head_ref;
	Node* temp = NULL;

	while (curr != NULL) {
		temp = curr->next;
		delete(curr);
		curr = temp;
	}

	*head_ref = NULL;
}

// xoá một node chứa key trong danh sách liên kết đơn
void deleteNode(Node** head_ref, int key) {
	Node* temp = *head_ref;
	Node* prev = NULL;

	// nếu danh sách rỗng thoát hàm và không làm gì cả
	if (*head_ref == NULL) {
		return;
	}

	// nếu node đầu là node chứa key cần xoá
	if (temp->data == key) {
		// gán node kế tiếp của node head làm head mới
		*head_ref = temp->next;
		delete temp;
		return;
	} else { // nếu node cần xoá không phải là node đầu mà có thể nằm trong các node còn lại
		// vòng lặp chạy đến khi tìm thấy key thì sẽ thoát khỏi vòng lặp
		while (temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}
		// nếu chạy hết vòng while bên trên mà không tìm được key thì tức là
		// không tìm thấy node chứa key trong list
		if (temp == NULL) {
			cout << "key not found" << endl;
			return;
		} else {
			// con trỏ trỏ đến next của con trỏ phía trước được gán bằng con trỏ hiện tại trỏ đến next;
			prev->next = temp->next;
			// xoá con trỏ hiện tại
			delete temp;
		}
	}
}

int main(int argc, char const *argv[]) {
	Node* head = NULL;

	int options = 0;

	do {
		int data;
		cout << "\t1. Them node vao dau\n";
		cout << "\t2. Them node vao cuoi\n";
		cout << "\t3. Liet ke danh sach lien ket\n";
		cout << "\t4. Dao chieu danh sach lien ket\n";
		cout << "\t5. Xoa mot node trong danh sach lien ket\n";
		cout << "\t6. Xoa mot danh sach lien ket\n";
		cout << "\t7. Tim kiem 1 node\n";
		cout << "\t0. Tro lai\n";
		cout << "nhap lua chon\n";
		cin >> options;
		switch (options) {
		case 1:
			cout << "nhap gia tri muon them (int): ";
			cin >> data;
			push(&head, data);
			break;
		case 2:
			cout << "nhap gia tri muon them (int): ";
			cin >> data;
			append(&head, data);
			break;
		case 3:
			printList(head);
			cout << endl;
			break;
		case 4:
			reverseLinkedList(&head);
			break;
		case 5:
			cout << "nhap gia tri muon xoa (int): ";
			cin >> data;
			deleteNode(&head, data);
			break;
		case 6:
			deleteList(&head);
			break;
		case 7:
			cout << "nhap gia tri muon tim (int): ";
			cin >> data;
			if (search(head, data)) {
				cout << "found\n";
			} else {
				cout << "not found\n";
			}
			break;
		default:
			break;
		}
	} while (options != 0);
}
