
undefined4 __thiscall FUN_00596a17(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_2;
  cVar2 = FUN_005b911f();
  if (((cVar2 != '\0') && (cVar2 = FUN_005b8f4a(0x18), cVar2 != '\0')) &&
     (cVar2 = FUN_005b9095(&param_2), cVar2 != '\0')) {
    if (*(int *)(param_1 + 0x2c) != 0) {
      FUN_005942ab();
    }
    *(undefined4 *)(param_1 + 0x2c) = 0;
    if (((param_2 == 0) || (cVar2 = FUN_00594196(iVar1), cVar2 != '\0')) &&
       (cVar2 = FUN_005b9095(&param_2), cVar2 != '\0')) {
      if (*(int *)(param_1 + 0x30) != 0) {
        FUN_005946cf();
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
      if ((param_2 == 0) || (cVar2 = FUN_005945c7(iVar1,param_3), cVar2 != '\0')) {
        return 1;
      }
    }
  }
  return 0;
}

