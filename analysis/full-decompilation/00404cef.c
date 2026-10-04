
undefined4 __thiscall FUN_00404cef(int *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  int *piVar11;
  
  iVar9 = param_2;
  bVar3 = true;
  if (param_2 != -1) {
    iVar5 = FUN_004ea79e(param_2);
    sVar10 = *(short *)(iVar5 + 0xa2);
    iVar5 = (int)sVar10;
    if ((iVar5 != 10) && (iVar5 < 0xb)) {
      iVar6 = FUN_004ea79e(param_2);
      sVar1 = *(short *)(iVar6 + 0xa0);
      iVar6 = FUN_004ea79e(param_2);
      sVar2 = *(short *)(iVar6 + 0xa4);
      iVar6 = *(int *)(*param_1 + iVar5 * 4);
      param_2 = 0;
      piVar11 = &DAT_00666538;
      do {
        iVar7 = FUN_00405165(iVar9,param_2);
        iVar8 = FUN_004ea79e(iVar9);
        iVar8 = (int)*(short *)(iVar8 + *piVar11 * 2) / 100;
        if (10 < iVar8) {
          iVar8 = 10;
        }
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        if (iVar8 < iVar7) {
          bVar3 = false;
          break;
        }
        param_2 = param_2 + 1;
        piVar11 = piVar11 + 1;
      } while ((int)piVar11 < 0x666550);
      cVar4 = FUN_00405333(iVar9);
      if (((cVar4 != '\0') && (bVar3)) && (iVar6 <= sVar1)) {
        sVar10 = sVar10 + 1;
        iVar6 = FUN_004ea79e(iVar9);
        *(short *)(iVar6 + 0xa2) = sVar10;
        if ((int)sVar2 < iVar5 + 1) {
          iVar9 = FUN_004ea79e(iVar9);
          *(short *)(iVar9 + 0xa4) = sVar10;
        }
        return 1;
      }
    }
  }
  return 0;
}

