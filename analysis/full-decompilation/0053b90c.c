
void __thiscall FUN_0053b90c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    FUN_005e4320(0);
  }
  else {
    if (param_2 < 2) {
      return;
    }
    if (3 < param_2) {
      return;
    }
    if (*(char *)(param_1 + 0x1e0) != '\0') {
      FUN_005dae65(param_1);
      *(char *)(param_1 + 0x1e0) = '\0';
    }
    if (param_2 != 3) {
      FUN_005e46f0(0);
      FUN_005e4320(0);
      return;
    }
    iVar1 = FUN_004cebb0();
    iVar2 = FUN_0046d386();
    if (iVar1 == iVar2) {
      return;
    }
  }
  FUN_005e46f0(0);
  return;
}

