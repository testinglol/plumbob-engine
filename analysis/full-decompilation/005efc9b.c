
undefined4 FUN_005efc9b(void)

{
  FARPROC pFVar1;
  int iVar2;
  HMODULE pHVar3;
  HRESULT HVar4;
  undefined4 uVar5;
  char *lpOutputString;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  HMODULE local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_18 = (int *)0x0;
  local_10 = (int *)0x0;
  local_24 = 0;
  local_1c = 0;
  local_c = LoadLibraryA(s_DDRAW_DLL_006d7b68);
  if (local_c != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(local_c,s_DirectDrawCreate_006d2d84);
    if (pFVar1 == (FARPROC)0x0) {
      FreeLibrary(local_c);
      lpOutputString = s_Couldn_t_LoadLibrary_DDraw_006d7b48;
    }
    else {
      iVar2 = (*pFVar1)(0,&local_8,0);
      if (iVar2 < 0) {
        FreeLibrary(local_c);
        lpOutputString = s_Couldn_t_create_DDraw_006d7b30;
      }
      else {
        iVar2 = (**(code **)*local_8)(local_8,&DAT_00677338,&local_18);
        if (iVar2 < 0) {
          (**(code **)(*local_8 + 8))(local_8);
          FreeLibrary(local_c);
          OutputDebugStringA(s_Couldn_t_QI_DDraw2_006d7b18);
          return 0x100;
        }
        (**(code **)(*local_18 + 8))(local_18);
        pHVar3 = LoadLibraryA(s_DINPUT_DLL_006d7b0c);
        if (pHVar3 == (HMODULE)0x0) {
          OutputDebugStringA(s_Couldn_t_LoadLibrary_DInput_006d7aec);
          (**(code **)(*local_8 + 8))(local_8);
          return 0x200;
        }
        pFVar1 = GetProcAddress(pHVar3,s_DirectInputCreateA_006d7ad8);
        if (pFVar1 == (FARPROC)0x0) {
          FreeLibrary(pHVar3);
          FreeLibrary(local_c);
          (**(code **)(*local_8 + 8))(local_8);
          OutputDebugStringA(s_Couldn_t_GetProcAddress_DInputCr_006d7ab0);
          return 0x200;
        }
        FreeLibrary(pHVar3);
        _memset(&local_90,0,0x6c);
        local_90 = 0x6c;
        local_28 = 0x200;
        local_8c = 1;
        iVar2 = (**(code **)(*local_8 + 0x50))(local_8,0,8);
        if (iVar2 < 0) {
          (**(code **)(*local_8 + 8))(local_8);
          FreeLibrary(local_c);
          lpOutputString = s_Couldn_t_Set_coop_level_006d7a94;
        }
        else {
          iVar2 = (**(code **)(*local_8 + 0x18))(local_8,&local_90,&local_10,0);
          if (-1 < iVar2) {
            iVar2 = (**(code **)*local_10)(local_10,&DAT_006772e8,&local_24);
            if (iVar2 < 0) {
              (**(code **)(*local_8 + 8))(local_8);
              uVar5 = 0x300;
            }
            else {
              iVar2 = (**(code **)*local_10)(local_10,&DAT_006772d8,&local_1c);
              if (iVar2 < 0) {
                (**(code **)(*local_8 + 8))(local_8);
                uVar5 = 0x500;
              }
              else {
                (**(code **)(*local_10 + 8))(local_10);
                (**(code **)(*local_8 + 8))(local_8);
                local_14 = (int *)0x0;
                CoInitialize((LPVOID)0x0);
                HVar4 = CoCreateInstance((IID *)&DAT_00677218,(LPUNKNOWN)0x0,1,(IID *)&DAT_00677208,
                                         &local_14);
                if (HVar4 < 0) {
                  OutputDebugStringA(s_Couldn_t_create_CLSID_DirectMusi_006d7a54);
                  uVar5 = 0x600;
                }
                else {
                  (**(code **)(*local_14 + 8))(local_14);
                  CoUninitialize();
                  pFVar1 = GetProcAddress(local_c,s_DirectDrawCreateEx_006d7a40);
                  if ((pFVar1 == (FARPROC)0x0) ||
                     (iVar2 = (*pFVar1)(0,&local_20,&DAT_00677318,0), iVar2 < 0)) {
                    uVar5 = 0x601;
                  }
                  else {
                    (**(code **)(*local_20 + 8))(local_20);
                    pHVar3 = LoadLibraryA(s_D3D8_DLL_006d7a34);
                    if (pHVar3 != (HMODULE)0x0) {
                      FreeLibrary(local_c);
                      FreeLibrary(pHVar3);
                      return 0x800;
                    }
                    uVar5 = 0x700;
                  }
                }
              }
            }
            FreeLibrary(local_c);
            return uVar5;
          }
          (**(code **)(*local_8 + 8))(local_8);
          FreeLibrary(local_c);
          lpOutputString = s_Couldn_t_CreateSurface_006d7a78;
        }
      }
    }
    OutputDebugStringA(lpOutputString);
  }
  return 0;
}

