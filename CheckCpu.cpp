// CheckCpu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

void _PrintSystemInfo(SYSTEM_INFO &sysInfo)
{
	printf("OemId: %u\n", sysInfo.dwOemId);
	printf("处理器架构 : %u\n", sysInfo.wProcessorArchitecture);
	printf("页面大小 : %u\n", sysInfo.dwPageSize);
	printf("应用程序最小地址 : %u\n", sysInfo.lpMinimumApplicationAddress);
	printf("应用程序最大地址 : %u\n", sysInfo.lpMaximumApplicationAddress);
	printf("处理器掩码 : %u\n", sysInfo.dwActiveProcessorMask);
	printf("处理器数量 : %u\n", sysInfo.dwNumberOfProcessors);
	printf("处理器类型 : %u\n", sysInfo.dwProcessorType);
	printf("虚拟内存分配粒度 : %u\n", sysInfo.dwAllocationGranularity);
	printf("处理器级别 : %u\n", sysInfo.wProcessorLevel);
	printf("处理器版本 : %u\n", sysInfo.wProcessorRevision);	 
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");

	SYSTEM_INFO sysInfo;

	GetSystemInfo(&sysInfo);

	_PrintSystemInfo(sysInfo);
	
	OSVERSIONINFOEX osvi;
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	
	BOOL bRet = GetVersionEx((LPOSVERSIONINFOW)&osvi);
	if (!bRet)
	{
		return -1;
	}else
	{
		printf("Version     : %u.%u\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
		printf("Build       : %u\n", osvi.dwBuildNumber);
		printf("Service Pack: %u.%u\n", osvi.wServicePackMajor, osvi.wServicePackMinor);
	}

	return 0;
}

