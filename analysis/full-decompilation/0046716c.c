
void __fastcall FUN_0046716c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x34);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      uVar2 = 1;
    }
    else if (iVar1 == 2) {
      uVar2 = 2;
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      uVar2 = 0;
    }
    FUN_00466d14(uVar2);
  }
  return;
}

