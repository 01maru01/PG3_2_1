#include "MenberManager.h"

MenberManager* MenberManager::GetInstance()
{
	static MenberManager* instance = new MenberManager;
	return instance;
}

void MenberManager::DeleteInstance()
{
	delete MenberManager::GetInstance();
}

void MenberManager::Add(std::string name_, std::string className_)
{
	Menber menber_;
	//	IDセット
	menber_.SetId(id);
	id++;
	//	menberの内容設定
	menber_.SetInfo(name_, className_);
	//	Add
	menber.push_back(menber_);
}

void MenberManager::Delete(int id_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	要素の削除
			menber.erase(itr);
			
			printf("要素が削除されました\n");
			return;
		}
	}

	printf("要素の削除に失敗しました\n");
}

void MenberManager::Change(int id_, std::string name_, std::string className_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			//	要素の変更
			itr->SetInfo(name_, className_);

			printf("ID:%dの要素が変更されました\n", id_);
			return;
		}
	}

	printf("ID:%dの要素の変更に失敗しました\n", id_);
}

void MenberManager::Draw()
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		printf("ID:%d Name:%s Class:%s\n", itr->GetId(), itr->GetName().c_str(), itr->GetClassName().c_str());
	}

	printf("\n");
}

void MenberManager::Draw(int id_)
{
	for (auto itr = menber.begin(); itr != menber.end(); ++itr) {
		if (itr->GetId() == id_) {
			printf("Name:%s Class:%s\n", itr->GetName().c_str(), itr->GetClassName().c_str());
			return;
		}
	}
	printf("担当者なし\n");
}
