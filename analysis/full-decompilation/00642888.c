
undefined4 FUN_00642888(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (DAT_00704100 <= param_1) {
LAB_00642909:
    puVar4 = (undefined4 *)FUN_0063d796();
    *puVar4 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) goto LAB_00642909;
  FUN_006459ff(param_1);
  if ((*(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + iVar5) & 1) != 0) {
    hFile = (HANDLE)FUN_006459bd(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar6 = 0;
    if (DVar2 == 0) goto LAB_006428fe;
    pDVar3 = (DWORD *)FUN_0063d79f();
    *pDVar3 = DVar2;
  }
  puVar4 = (undefined4 *)FUN_0063d796();
  *puVar4 = 9;
  uVar6 = 0xffffffff;
LAB_006428fe:
  FUN_00645a5e(param_1);
  return uVar6;
}

