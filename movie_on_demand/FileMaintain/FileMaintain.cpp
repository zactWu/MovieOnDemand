#include "stdafx.h"

#include <msclr/marshal_cppstd.h>
#include "FileMaintain.h"

using namespace msclr::interop;

FileMaintain::FileOperator::FileOperator(String ^ filepath, String ^ filename)
{
	this->FileName = filename;
	if (filepath[filepath->Length-1] == '/')
		this->FilePath = filepath;
	else
		this->FilePath = filepath + "/";
	marshal_context^ context = gcnew marshal_context();
	std::string currentFilePath = context->marshal_as<std::string>(this->FileName);
	try {
		CreateDirectory(currentFilePath.c_str(), NULL);
	}
	catch (Exception^) {}
	finally{
		delete context;
	}
}

void FileMaintain::FileOperator::CleanFiles()
{
	marshal_context^ context = gcnew marshal_context();

	// 遍历当前目录下的文件
	std::string inPath = context->marshal_as<std::string>(this->FilePath) + "*";
	std::string currentFileName = context->marshal_as<std::string>(this->FileName);

	// 用于查找的句柄
	long handle;
	struct _finddata_t fileinfo;

	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return;
	do
	{
		std::string name = std::string(fileinfo.name);
		if (name.find(currentFileName) != std::string::npos)
		{
			std::string removeName = context->marshal_as<std::string>(this->FilePath) + std::string(fileinfo.name);
			remove(removeName.c_str());
		}

	} while (!_findnext(handle, &fileinfo));
	_findclose(handle);
	delete context;
}

void FileMaintain::FileOperator::CleanFiles(String ^ filename)
{
	marshal_context^ context = gcnew marshal_context();
	this->FileName = filename;

	// 遍历当前目录下的文件
	std::string inPath = context->marshal_as<std::string>(this->FilePath) + "*";
	std::string currentFileName = context->marshal_as<std::string>(this->FileName);

	// 用于查找的句柄
	long handle;
	struct _finddata_t fileinfo;

	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return;
	do
	{
		std::string name = std::string(fileinfo.name);
		if (name.find(currentFileName) != std::string::npos)
		{
			std::string removeName = context->marshal_as<std::string>(this->FilePath) + std::string(fileinfo.name);
			remove(removeName.c_str());
		}

	} while (!_findnext(handle, &fileinfo));
	_findclose(handle);
	delete context;
}

void FileMaintain::FileOperator::CleanFiles(List<String^>^ files)
{
	marshal_context^ context = gcnew marshal_context();
	// 遍历当前目录下的文件
	std::string inPath = context->marshal_as<std::string>(this->FilePath) + "*";
	for (int i = 0; i < files->Count; i++)
	{
		std::string removeName = context->marshal_as<std::string>(this->FilePath) + context->marshal_as<std::string>(files[i]);
		try
		{
			remove(removeName.c_str());
		}
		catch (Exception^) {}
	}
	delete context;
}

List<String ^> ^ FileMaintain::FileOperator::GetAllFiles()
{
	marshal_context^ context = gcnew marshal_context();
	// 遍历当前目录下的文件
	std::string inPath = context->marshal_as<std::string>(this->FilePath) + "*";

	List<String^>^ result = gcnew List<String^>();

	// 用于查找的句柄
	long handle;
	struct _finddata_t fileinfo;

	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return result;
	do
	{
		if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
			result->Add(marshal_as<String^>(fileinfo.name));
	} while (!_findnext(handle, &fileinfo));
	_findclose(handle);
	delete context;
	return result;
}
