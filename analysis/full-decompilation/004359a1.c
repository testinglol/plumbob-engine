
undefined4 __fastcall FUN_004359a1(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_0043532b();
  if ((param_1 == iVar2) && (iVar2 = FUN_00457e1c(), iVar2 != 0)) {
    iVar1 = *(int *)(iVar2 + 4);
    iVar4 = 0;
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        if ((iVar3 < 0) || (iVar1 <= iVar3)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*(int *)(iVar2 + 0x10) + iVar3 * 4);
        }
        if ((*(int *)(iVar5 + 0x1c) < 100) && ((*(uint *)(iVar5 + 0x14) >> 7 & 1) == 0)) {
          iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
      if (iVar4 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

