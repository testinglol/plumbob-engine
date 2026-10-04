
undefined4 __thiscall
FUN_005dfdb4(int param_1,undefined2 *param_2,undefined1 param_3,undefined1 param_4,
            undefined1 param_5)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 5) {
    uVar2 = FUN_0049f1f4((uint)CONCAT21(CONCAT11(param_3,param_4),param_5));
  }
  else if (iVar1 == 6) {
    uVar2 = FUN_004a4531((uint)CONCAT21(CONCAT11(param_3,param_4),param_5));
  }
  else if (iVar1 == 7) {
    uVar2 = FUN_0049f21b((uint)CONCAT21(CONCAT11(param_3,param_4),param_5));
  }
  else {
    if (iVar1 != 8) {
      return 0;
    }
    uVar2 = FUN_004a4558((uint)CONCAT21(CONCAT11(param_3,param_4),param_5));
  }
  *param_2 = uVar2;
  return 1;
}

