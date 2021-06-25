#pragma once
#include <io.h>
#include <string>
#include <cstdio>

using namespace System;
using namespace System::Collections::Generic;

namespace FileMaintain {
	public ref class FileOperator
	{
	public:
		FileOperator(String^ filepath, String^ filename);
		void CleanFiles();
		void CleanFiles(String^ filename);
		void CleanFiles(List<String^>^ files);
		List<String^>^ GetAllFiles();

	private:
		String^ FilePath;
		String^ FileName;
	};
}
