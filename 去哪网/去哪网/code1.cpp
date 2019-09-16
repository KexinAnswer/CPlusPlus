#include <iostream>
#include <string>

struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* BuildTree(std::string& vin, std::string& back) {
	char rootValue = back[back.size() - 1];
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = rootValue;
	root->left = root->right = NULL;
	if (vin.size() == 0 && back.size() == 0) {
		return root;
	}

	int left_len = 0;
	while (vin[left_len] != rootValue && left_len < vin.size()) {
		left_len++;
	}
	if (left_len == vin.size()) {
		return NULL;
	}
	std::string left_back;
	std::string right_back;
	std::string left_vin;
	std::string right_vin;

	for (int i = 0; i < left_len; ++i) {
		left_back += back[i];
	}
	for (int i = left_len; i < back.size() - 1; ++i) {
		right_back += back[i];
	}
	for (int i = 0; i < left_len; ++i) {
		left_vin += vin[i];
	}
	for (int i = left_len + 1; i < vin.size(); ++i) {
		right_vin += vin[i];
	}

	if (left_back.size() > 0 && left_vin.size() > 0) {
		root->left = BuildTree(left_vin, left_back);
	}

	if (right_back.size() > 0 && right_vin.size() > 0) {
		root->right = BuildTree(right_vin, right_back);
	}
	return root;

}

void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	std::cout << root->val;
	preOrder(root->left);
	preOrder(root->right);

}

#if 0
int main() {
	std::string vin;
	std::string back;
	while (std::cin >> vin >> back) {
		TreeNode* root = BuildTree(vin, back);
		preOrder(root);
		std::cout << std::endl;
	}

	return 0;
}
#endif