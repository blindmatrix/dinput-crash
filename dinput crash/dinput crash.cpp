// This sample application will crash if a SteelSeries H Wireless headset is connected via USB.
// This will only work for dinput.dll version 10.0.17763.1
// It's also best to run this with Application Verifier.
// To install the fix change INSTALL_PATCH to 1
// There's no expected output, but if it fails the application will crash.

#define INSTALL_PATCH 0

#define DIRECTINPUT_VERSION 0x0500

#include <cstdint>
#include <windows.h> 
#include <dinput.h> 

void installFixup();

BOOL CALLBACK EnumCallback(const DIDEVICEINSTANCEW* pdidInstance, VOID* pContext)
{
	return DIENUM_CONTINUE;
}

int main()
{
	LPDIRECTINPUTW pDI = nullptr;
	HMODULE hDI;
	HRESULT(WINAPI *pDirectInputCreateW)(HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTW *ppDI, LPUNKNOWN punkOuter);

	hDI = LoadLibraryA("dinput.dll");

	installFixup();

	pDirectInputCreateW = (HRESULT(WINAPI *)(HINSTANCE, DWORD, LPDIRECTINPUTW *, LPUNKNOWN))GetProcAddress(hDI, "DirectInputCreateW");
	pDirectInputCreateW(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, &pDI, nullptr);

	pDI->EnumDevices(0, EnumCallback, nullptr, 1);
}

#if INSTALL_PATCH
#include <psapi.h>

#include <hidusage.h>
#include <Hidpi.h>

struct __declspec(align(4)) Something88
{
	DWORD type;
	DWORD RangeUsageWidth;
	WORD UsagePage;
	WORD RangeUsageMin;
	WORD RangeStringMin;
	WORD RangeStringMax;
	WORD RangeDesignatorMin;
	WORD RangeDesignatorMax;
	WORD RangeDataIndexMin;
	WORD w_16;
	DWORD BitMask;
	WORD BitSize;
	WORD LinkCollection;
	LONG LogicalMin;
	LONG LogicalMax;
	LONG PhysicalMin;
	LONG PhysicalMax;
	DWORD dw_30;
	DWORD Units;
	WORD UnitsExp;
	WORD ReportID;
	DWORD dw_3C;
	DWORD dw_40;
	DWORD IsAbsolute;
	DWORD dw_48_One;
	DWORD IsAlias;
	DWORD dw_50;
	DWORD dw_54;
};

struct __declspec(align(4)) Something16
{
	const GUID *dw_0;
	DWORD dw_4;
	DWORD dw_8;
	DWORD dw_C;
};

struct Something116
{
	DWORD dw_0;
	DWORD dw_4;
	DWORD dw_8;
	DWORD dw_C;
	DWORD dw_10;
	DWORD dw_14;
	DWORD dw_18;
	DWORD dw_1C;
	DWORD dw_20;
	DWORD dw_24;
	DWORD dw_28;
	DWORD dw_2C;
	DWORD dw_30;
	DWORD dw_34;
	DWORD dw_38;
	DWORD dw_3C;
	DWORD dw_40;
	DWORD dw_44;
	DWORD dw_48;
	DWORD dw_4C;
	DWORD dw_50;
	DWORD dw_54;
	DWORD dw_58;
	DWORD dw_5C;
	DWORD dw_60;
	DWORD dw_64;
	DWORD dw_68;
	DWORD dw_6C;
	DWORD dw_70;
};

struct Something12
{
	Something88* dw_0;
	Something116* dw_4;
	DWORD dw_8;
};

struct XHid
{
	void* vtable;
	DWORD dw_4;
	DWORD dw_8;
	DWORD dw_C;
	DWORD dw_10;
	DWORD dw_14;
	DWORD dw_18;
	DWORD dw_1C;
	DWORD dw_20;
	DWORD dw_24;
	DWORD dw_28;
	DWORD dw_2C;
	DWORD dw_30;
	DWORD dw_34;
	DWORD dw_38;
	DWORD dw_3C;
	DWORD dw_40;
	DWORD dw_44;
	DWORD dw_48;
	DWORD dw_4C;
	DWORD dw_50;
	DWORD dw_54;
	DWORD dw_58;
	DWORD dw_5C;
	DWORD dw_60;
	DWORD dw_64;
	DWORD dw_68;
	DWORD dw_6C;
	DWORD dw_70;
	DWORD dw_74;
	DWORD dw_78;
	DWORD dw_7C;
	DWORD dw_80;
	DWORD dw_84_dataOffset[4];
	Something12 *dw_AC_pObjects_pastDataItems16;
	DWORD dw_98;
	DWORD dw_9C;
	DWORD dw_A0;
	DWORD dw_A4;
	DWORD numDataItems;
	Something16 *dw_AC_pObjects16;
	DWORD dw_B0;
	DWORD dw_B4;
	DWORD dw_B8;
	PHIDP_PREPARSED_DATA p_PhidpPreparsedData;
	Something88 *pCaps88_maybe;
	Something116 *pCaps116_maybe;
	HIDP_CAPS hidpCaps;
	DWORD dw_108;
	DWORD dw_10C;
	DWORD dw_110;
	DWORD dw_114;
	DWORD dw_118;
	DWORD dw_11C;
	DWORD dw_120;
	DWORD dw_124;
	DWORD dw_128;
	DWORD dw_12C;
	DWORD dw_130;
	DWORD dw_134;
	DWORD dw_138;
	DWORD dw_13C;
	DWORD dw_140;
	DWORD dw_144;
	DWORD dw_148;
	DWORD dw_14C;
	DWORD dw_150;
	DWORD dw_154;
	DWORD dw_158;
	DWORD numCaps88;
	DWORD dw_160;
	HKEY dw_164_hKey_joystickOEM;
	WORD VendorID;
	WORD ProductID;
	DWORD dw_16C;
	DWORD dw_170;
	DWORD dw_174;
	WORD w_178[4];
	DWORD dw_180;
	DWORD dw_184;
	DWORD dw_188;
	DWORD dw_18C;
	DWORD dw_190;
	DWORD dw_194;
	DWORD dw_198;
	DWORD dw_19C;
	DWORD dw_1A0;
	DWORD dw_1A4;
	DWORD dw_1A8;
	DWORD dw_1AC;
	DWORD dw_1B0;
};

HRESULT(__fastcall *ReallocCbPpv)(size_t uBytes, void **ppObj);

HRESULT __fastcall AllocObjectMemory(XHid* self)
{
	self->numDataItems = self->hidpCaps.NumberFeatureDataIndices + self->hidpCaps.NumberLinkCollectionNodes + self->hidpCaps.NumberOutputDataIndices + self->hidpCaps.NumberInputDataIndices;

	if (self->numDataItems >= 0xFFFF)
		return DIERR_GENERIC;

	self->numCaps88 =
		self->hidpCaps.NumberLinkCollectionNodes +
		self->hidpCaps.NumberOutputValueCaps +
		self->hidpCaps.NumberFeatureButtonCaps +
		self->hidpCaps.NumberFeatureValueCaps +
		self->hidpCaps.NumberInputValueCaps +
		self->hidpCaps.NumberOutputButtonCaps +
		self->hidpCaps.NumberInputButtonCaps;

	HRESULT hr = ReallocCbPpv(
		sizeof(Something16) * self->numDataItems +
		sizeof(Something12) * self->numDataItems +
		sizeof(Something88) * self->numCaps88 +
		sizeof(Something116) * self->hidpCaps.NumberInputDataIndices, // <<-- this is the change
		(void**)&self->dw_AC_pObjects16);

	if (SUCCEEDED(hr))
	{
		self->dw_AC_pObjects_pastDataItems16 = (Something12*)(&self->dw_AC_pObjects16[self->numDataItems]);
		self->pCaps88_maybe = (Something88*)(&(self->dw_AC_pObjects_pastDataItems16[self->numDataItems]));
		self->pCaps116_maybe = (Something116*)(&self->pCaps88_maybe[self->numCaps88]);
	}

	return hr;
}

void installFixup()
{
	HMODULE hModule = GetModuleHandleW(L"dinput.dll");
	MODULEINFO modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(modinfo));

	ptrdiff_t base = (ptrdiff_t)modinfo.lpBaseOfDll;
	ptrdiff_t location = base + 0x00013B54 + 1;
	ptrdiff_t ref = location + 4;
	ptrdiff_t target = (ptrdiff_t)&AllocObjectMemory;
	ptrdiff_t offset = target - ref;

	DWORD dwOldProtection = 0;

	VirtualProtect((LPVOID)location, 5, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	memcpy((LPVOID)location, &offset, 4);
	VirtualProtect((LPVOID)location, 4, dwOldProtection, &dwOldProtection);

	ReallocCbPpv = (HRESULT(__fastcall *)(size_t, void **))(base + 0xB996);
}
#else
void installFixup()
{
}
#endif