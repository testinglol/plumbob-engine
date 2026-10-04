
undefined4 FUN_00645ca2(uint *param_1,HANDLE param_2,uint param_3)

{
  byte *pbVar1;
  BOOL BVar2;
  DWORD DVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  _SECURITY_ATTRIBUTES local_14;
  HANDLE local_8;
  
  local_14.lpSecurityDescriptor = (LPVOID)0x0;
  uVar7 = param_3 & 0x80;
  local_14.nLength = 0xc;
  local_14.bInheritHandle = (BOOL)(uVar7 == 0);
  BVar2 = CreatePipe(&param_2,&local_8,&local_14,(DWORD)param_2);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    FUN_0063d723(DVar3);
  }
  else {
    uVar4 = FUN_0064579f();
    *param_1 = uVar4;
    if (uVar4 == 0xffffffff) {
      puVar5 = (undefined4 *)FUN_0063d796();
      *puVar5 = 0x18;
    }
    else {
      *(undefined1 *)((&DAT_00704000)[(int)uVar4 >> 5] + 4 + (uVar4 & 0x1f) * 0x24) = 0x89;
      uVar4 = FUN_0064579f();
      param_1[1] = uVar4;
      if (uVar4 == 0xffffffff) {
        *(undefined1 *)((&DAT_00704000)[(int)*param_1 >> 5] + 4 + (*param_1 & 0x1f) * 0x24) = 0;
        puVar5 = (undefined4 *)FUN_0063d796();
        *puVar5 = 0x18;
      }
      else {
        *(undefined1 *)((&DAT_00704000)[(int)uVar4 >> 5] + 4 + (uVar4 & 0x1f) * 0x24) = 0x89;
        if (((param_3 & 0x8000) != 0) || (((param_3 & 0x4000) == 0 && (DAT_00703d60 == 0x8000)))) {
          pbVar1 = (byte *)((&DAT_00704000)[(int)*param_1 >> 5] + 4 + (*param_1 & 0x1f) * 0x24);
          *pbVar1 = *pbVar1 & 0x7f;
          pbVar1 = (byte *)((&DAT_00704000)[(int)param_1[1] >> 5] + 4 + (param_1[1] & 0x1f) * 0x24);
          *pbVar1 = *pbVar1 & 0x7f;
        }
        if (uVar7 != 0) {
          pbVar1 = (byte *)((&DAT_00704000)[(int)*param_1 >> 5] + 4 + (*param_1 & 0x1f) * 0x24);
          *pbVar1 = *pbVar1 | 0x10;
          pbVar1 = (byte *)((&DAT_00704000)[(int)param_1[1] >> 5] + 4 + (param_1[1] & 0x1f) * 0x24);
          *pbVar1 = *pbVar1 | 0x10;
        }
        FUN_006458c2(*param_1,param_2);
        FUN_006458c2(param_1[1],local_8);
        puVar5 = (undefined4 *)FUN_0063d796();
        *puVar5 = 0;
        FUN_00645a5e(param_1[1]);
      }
      FUN_00645a5e(*param_1);
    }
    piVar6 = (int *)FUN_0063d796();
    if (*piVar6 == 0) {
      return 0;
    }
    CloseHandle(param_2);
    CloseHandle(local_8);
    puVar5 = (undefined4 *)FUN_0063d79f();
    *puVar5 = 0;
  }
  return 0xffffffff;
}

