
bool FUN_004e1113(void)

{
  int *piVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  HANDLE hObject;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  bool bVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x268) = 0x224;
  *(char **)(unaff_EBP + -0x24) = s_kernel32_dll_006c98f0;
  puVar4 = (undefined4 *)(unaff_EBP + -0x264);
  for (iVar3 = 0x88; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(char **)(unaff_EBP + -0x20) = s_tlhelp32_dll_006c98e0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  puVar4 = (undefined4 *)(unaff_EBP + -0x24);
  do {
    hModule = LoadLibraryA((LPCSTR)*puVar4);
    if (hModule != (HMODULE)0x0) {
      pFVar2 = GetProcAddress(hModule,s_CreateToolhelp32Snapshot_006c98c4);
      *(FARPROC *)(unaff_EBP + -0x14) = pFVar2;
      pFVar2 = GetProcAddress(hModule,s_Module32First_006c98b4);
      *(FARPROC *)(unaff_EBP + -0x18) = pFVar2;
      pFVar2 = GetProcAddress(hModule,s_Module32Next_006c98a4);
      *(FARPROC *)(unaff_EBP + -0x1c) = pFVar2;
      if (((*(int *)(unaff_EBP + -0x14) != 0) && (*(int *)(unaff_EBP + -0x18) != 0)) &&
         (pFVar2 != (FARPROC)0x0)) break;
      FreeLibrary(hModule);
      hModule = (HMODULE)0x0;
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    puVar4 = puVar4 + 1;
  } while (*(uint *)(unaff_EBP + -0x10) < 2);
  if (hModule == (HMODULE)0x0) {
    FUN_004e0eba(s_Never_could_find_Tool_Help__006c9884);
    *(undefined4 *)(unaff_EBP + -4) = 2;
  }
  else {
    hObject = (HANDLE)(**(code **)(unaff_EBP + -0x14))(8,*(undefined4 *)(unaff_EBP + 0xc));
    if (hObject != (HANDLE)0xffffffff) {
      iVar3 = (**(code **)(unaff_EBP + -0x18))(hObject,unaff_EBP + -0x268);
      piVar1 = *(int **)(unaff_EBP + 8);
      while (iVar3 != 0) {
        FUN_004e0eba(s__08lXh__6lu___15_15s__s_006c9844,*(undefined4 *)(unaff_EBP + -0x254),
                     *(undefined4 *)(unaff_EBP + -0x250),unaff_EBP + -0x248,unaff_EBP + -0x148);
        FUN_005d4bbf(unaff_EBP + -0x148);
        FUN_005d4bbf(unaff_EBP + -0x248);
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x254);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x250);
        FUN_004e1564(unaff_EBP + -0x44);
        iVar3 = (**(code **)(unaff_EBP + -0x1c))(hObject,unaff_EBP + -0x268);
      }
      CloseHandle(hObject);
      FreeLibrary(hModule);
      bVar5 = (piVar1[1] - *piVar1 & 0xffffffe0U) != 0;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      goto LAB_004e12ba;
    }
    FUN_004e0eba(s_CreateToolhelp32Snapshot_failed__006c9860);
    *(undefined4 *)(unaff_EBP + -4) = 3;
  }
  bVar5 = false;
LAB_004e12ba:
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar5;
}

