
void __fastcall FUN_005cac60(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_005cacc8(param_1 + 0x468);
  FUN_004a891e();
  FUN_005cacc8(param_1 + 0x498);
  FUN_004a891e();
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar2 = *(int *)(iVar2 + 0x20) - *(int *)(iVar2 + 0x1c) >> 2;
    if (0 < iVar2) {
      do {
        FUN_005ce696();
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
  }
  return;
}

