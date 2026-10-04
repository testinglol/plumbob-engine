
undefined4 FUN_004e0bbc(LPCVOID param_1,LPSTR param_2,DWORD param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  LPCVOID pvVar3;
  SIZE_T SVar4;
  DWORD DVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  _MEMORY_BASIC_INFORMATION local_20;
  
  pvVar3 = param_1;
  SVar4 = VirtualQuery(param_1,&local_20,0x1c);
  if ((SVar4 != 0) &&
     (DVar5 = GetModuleFileNameA(local_20.AllocationBase,param_2,param_3), DVar5 != 0)) {
    iVar1 = ((HMODULE)((int)local_20.AllocationBase + 0x3c))->unused;
    param_1 = (LPCVOID)0x0;
    uVar9 = (int)pvVar3 - (int)local_20.AllocationBase;
    uVar8 = (uint)*(ushort *)
                   ((int)&((HMODULE)((int)local_20.AllocationBase + 4))->unused + iVar1 + 2);
    if (uVar8 != 0) {
      puVar6 = (uint *)((int)&((HMODULE)((int)local_20.AllocationBase + 0x20))->unused +
                       (uint)*(ushort *)
                              ((int)&((HMODULE)((int)local_20.AllocationBase + 0x14))->unused +
                              iVar1) + iVar1);
      do {
        uVar2 = puVar6[1];
        puVar7 = puVar6 + 2;
        if (puVar6[2] < *puVar6) {
          puVar7 = puVar6;
        }
        if ((uVar2 <= uVar9) && (uVar9 <= *puVar7 + uVar2)) {
          *param_4 = (int)param_1 + 1;
          *param_5 = uVar9 - uVar2;
          return 1;
        }
        param_1 = (LPCVOID)((int)param_1 + 1);
        puVar6 = puVar6 + 10;
      } while (param_1 < uVar8);
    }
  }
  return 0;
}

