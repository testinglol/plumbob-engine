
void __thiscall FUN_005632d6(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x168) == '\0') {
    FUN_005dde6d(0);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1d0);
    if ((iVar2 != 0) && (*(int *)(param_1 + 0x1d4) != 0)) {
      iVar1 = *(int *)(param_1 + 0x194);
      if (iVar1 != 0) {
        if ((iVar1 == 10) ||
           (param_2 <=
            (((*(int *)(*(int *)(param_1 + 0x198) + 0x1c) -
              *(int *)(*(int *)(param_1 + 0x198) + 0x14)) / 10) * iVar1 - *(int *)(param_1 + 0x7c))
            + *(int *)(param_1 + 0x1b8))) {
          FUN_005dde6d(*(int *)(param_1 + 0x1d4));
          *(undefined1 *)(param_1 + 0x1d8) = 0;
          goto LAB_0056335e;
        }
        iVar2 = *(int *)(param_1 + 0x1d0);
      }
      FUN_005dde6d(iVar2);
      *(undefined1 *)(param_1 + 0x1d8) = 1;
    }
  }
LAB_0056335e:
  FUN_005e452a(param_2,param_3,param_4);
  return;
}

