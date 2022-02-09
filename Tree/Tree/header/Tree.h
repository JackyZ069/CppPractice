#pragma once
#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<vector>
#include<fstream>
#include<string>


#define Status int
#define OK 1
#define ERROR 0


namespace binary_search_tree_{

	typedef struct info {
		int id=0;//suppose id is unique
		std::string name;
		int age=0;
		std::string addr;
	}info;

	typedef struct node {
		info data;
		node* left = nullptr;
		node* right = nullptr;
	}node;

//下面代码是二叉搜索树的实现，主要包括树的创建、插入、删除、查找、遍历、保存、载入。
class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree() ;

	typedef std::tuple<int, int, std::string, int, std::string>row;	// flag(-1: no node, 0: have a node), id, name, age, addr

	Status Init(const std::vector<info>& infos);//creat binary search tree
	bool Search(int id,info& data)const;
	Status Insert(const info& data);
	Status Delete(int id);//delete a node
	Status Traversal(int type);// 0: pre-order, 1: in-order, 2: post-order, 3: level
	int GetMaxDepth()const;//get tree max depth
	int GetMinDepth()const;//get tree min depth
	int GetNodesCount()const;//get tree node count
	bool IsBinarySearchTree()const;//weather or not is a binary search tree
	int GetMinValue(info& data)const;
	int GetMaxValue(info& data)const;
	Status SaveTree(const char* name)const;//tree write in txt file
	Status LoadTree(const char* name);

protected:

	void PreorderTraversal(const node* ptr) const;
	void InorderTraversal(const node* ptr) const;
	void PostorderTraversal(const node* ptr) const;
	void LevelTraversal(const node* ptr) const;
	void LevelTraversal(const node* ptr, int level) const;
	void DeleteTree(node* ptr);
	void Insert(node* ptr, const info& data);
	const node* Search(const node* ptr, int id) const;
	void IsBinarySearchTree(const node* ptr, bool is_bst) const;
	int Traversal(int type) const;
	int GetNodesCount(const node* ptr) const;
	int GetMaxDepth(const node* ptr) const;
	int GetMinDepth(const node* ptr) const;
	//bool IsBinaryBalanceTree(const node* ptr) const;
	node* Delete(node* ptr, int id); // return new root
	node* GetMinValue(node* ptr);
	void NodeToRow(const node* ptr, std::vector<row>& rows, int pos) const;
	void RowToNode(node* ptr, const std::vector<row>& rows, int n, int pos);

private:
	node* tree = nullptr;
	bool flag;
};

int test_binary_tree();
}

#endif // !TREE_H
 