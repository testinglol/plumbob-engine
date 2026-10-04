
int FUN_00645a80(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  HANDLE hFile;
  BOOL BVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  int iVar7;
  undefined1 local_1008 [4064];
  undefined4 uStackY_28;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  
  FUN_00636080();
  iVar7 = 0;
  iVar1 = FUN_0063d4f4();
  if ((iVar1 == -1) || (iVar1 = FUN_0063d4f4(), iVar1 == -1)) {
    iVar7 = -1;
  }
  else {
    param_2 = param_2 - iVar1;
    if (param_2 < 1) {
      if (param_2 < 0) {
        uStackY_20 = 0x645b51;
        FUN_0063d4f4();
        uStackY_20 = param_1;
        uStackY_24 = 0x645b59;
        hFile = (HANDLE)FUN_006459bd();
        BVar4 = SetEndOfFile(hFile);
        iVar7 = (BVar4 != 0) - 1;
        if (iVar7 == -1) {
          puVar3 = (undefined4 *)FUN_0063d796();
          *puVar3 = 0xd;
          DVar5 = GetLastError();
          pDVar6 = (DWORD *)FUN_0063d79f();
          *pDVar6 = DVar5;
        }
      }
    }
    else {
      uStackY_20 = 0x645ae0;
      _memset(local_1008,0,0x1000);
      uStackY_20 = 0x8000;
      uStackY_24 = param_1;
      uStackY_28 = 0x645aed;
      FUN_0063d801();
      do {
        uStackY_20 = 0x645b0b;
        iVar1 = FUN_0063d0c6();
        if (iVar1 == -1) {
          piVar2 = (int *)FUN_0063d79f();
          if (*piVar2 == 5) {
            puVar3 = (undefined4 *)FUN_0063d796();
            *puVar3 = 0xd;
          }
          iVar7 = -1;
          break;
        }
        param_2 = param_2 - iVar1;
      } while (0 < param_2);
      FUN_0063d801();
    }
    uStackY_20 = 0x645b97;
    FUN_0063d4f4();
  }
  return iVar7;
}

