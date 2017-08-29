// CheckCpu.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

void _PrintSystemInfo(SYSTEM_INFO &sysInfo)
{
	printf("OemId: %u\n", sysInfo.dwOemId);
	printf("�������ܹ� : %u\n", sysInfo.wProcessorArchitecture);
	printf("ҳ���С : %u\n", sysInfo.dwPageSize);
	printf("Ӧ�ó�����С��ַ : %u\n", sysInfo.lpMinimumApplicationAddress);
	printf("Ӧ�ó�������ַ : %u\n", sysInfo.lpMaximumApplicationAddress);
	printf("���������� : %u\n", sysInfo.dwActiveProcessorMask);
	printf("���������� : %u\n", sysInfo.dwNumberOfProcessors);
	printf("���������� : %u\n", sysInfo.dwProcessorType);
	printf("�����ڴ�������� : %u\n", sysInfo.dwAllocationGranularity);
	printf("���������� : %u\n", sysInfo.wProcessorLevel);
	printf("�������汾 : %u\n", sysInfo.wProcessorRevision);	 
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

