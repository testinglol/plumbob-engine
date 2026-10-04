
bool FUN_004e1314(void)

{
  int *piVar1;
  undefined4 *puVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  void *pvVar4;
  undefined1 *puVar5;
  int iVar6;
  DWORD DVar7;
  int unaff_EBP;
  bool bVar8;
  char *pcVar9;
  
  FUN_00634c24();
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  hModule = LoadLibraryA(s_psapi_dll_006c99a4);
  *(HMODULE *)(unaff_EBP + -0x28) = hModule;
  if (hModule == (HMODULE)0x0) {
    *(undefined4 *)(unaff_EBP + -4) = 2;
  }
  else {
    piVar1 = *(int **)(unaff_EBP + 8);
    FUN_004e158c(*piVar1,piVar1[1]);
    pFVar3 = GetProcAddress(hModule,s_EnumProcessModules_006c9990);
    *(FARPROC *)(unaff_EBP + 8) = pFVar3;
    pFVar3 = GetProcAddress(hModule,s_GetModuleFileNameExA_006c9978);
    *(FARPROC *)(unaff_EBP + -0x20) = pFVar3;
    pFVar3 = GetProcAddress(hModule,s_GetModuleBaseNameA_006c9964);
    *(FARPROC *)(unaff_EBP + -0x24) = pFVar3;
    pFVar3 = GetProcAddress(hModule,s_GetModuleInformation_006c994c);
    *(FARPROC *)(unaff_EBP + -0x1c) = pFVar3;
    if ((((*(int *)(unaff_EBP + 8) != 0) && (*(int *)(unaff_EBP + -0x20) != 0)) &&
        (*(int *)(unaff_EBP + -0x24) != 0)) && (*(int *)(unaff_EBP + -0x1c) != 0)) {
      pvVar4 = operator_new(0x10000);
      *(void **)(unaff_EBP + -0x18) = pvVar4;
      puVar5 = operator_new(0x10000);
      iVar6 = (**(code **)(unaff_EBP + 8))
                        (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + -0x18),
                         0x10000,unaff_EBP + -0x10);
      if (iVar6 == 0) {
        DVar7 = GetLastError();
        pcVar9 = s_EPM_failed__GetLastError______lu_006c9928;
LAB_004e140c:
        FUN_004e0eba(pcVar9,DVar7);
      }
      else {
        if (0x10000 < *(uint *)(unaff_EBP + -0x10)) {
          DVar7 = 1;
          pcVar9 = s_More_than__lu_module_handles__Hu_006c9900;
          goto LAB_004e140c;
        }
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if ((*(uint *)(unaff_EBP + -0x10) & 0xfffffffc) != 0) {
          *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x18);
          do {
            (**(code **)(unaff_EBP + -0x1c))
                      (*(undefined4 *)(unaff_EBP + 0x10),**(undefined4 **)(unaff_EBP + 8),
                       unaff_EBP + -0x34,0xc);
            *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x34);
            *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x30);
            puVar2 = *(undefined4 **)(unaff_EBP + 8);
            *puVar5 = 0;
            (**(code **)(unaff_EBP + -0x20))
                      (*(undefined4 *)(unaff_EBP + 0x10),*puVar2,puVar5,0x10000);
            FUN_005d4bbf(puVar5);
            puVar2 = *(undefined4 **)(unaff_EBP + 8);
            *puVar5 = 0;
            (**(code **)(unaff_EBP + -0x24))
                      (*(undefined4 *)(unaff_EBP + 0x10),*puVar2,puVar5,0x10000);
            FUN_005d4bbf(puVar5);
            FUN_004e0eba(s__08lXh__6lu___15_15s__s_006c9844,*(undefined4 *)(unaff_EBP + -0x3c),
                         *(undefined4 *)(unaff_EBP + -0x38),*(undefined4 *)(unaff_EBP + -0x48),
                         *(undefined4 *)(unaff_EBP + -0x54));
            FUN_004e1564(unaff_EBP + -0x54);
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
          } while (*(uint *)(unaff_EBP + -0x14) < *(uint *)(unaff_EBP + -0x10) >> 2);
        }
      }
      FreeLibrary(*(HMODULE *)(unaff_EBP + -0x28));
      FUN_006321f0(puVar5);
      FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x18));
      bVar8 = (piVar1[1] - *piVar1 & 0xffffffe0U) != 0;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      goto LAB_004e14f9;
    }
    FreeLibrary(hModule);
    *(undefined4 *)(unaff_EBP + -4) = 3;
  }
  bVar8 = false;
LAB_004e14f9:
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar8;
}

