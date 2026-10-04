
undefined4 __thiscall
FUN_005dfe3b(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar2 = 0;
  if (iVar1 == 5) {
    uVar2 = FUN_0049f1f4((uint)CONCAT21(CONCAT11(param_2,param_3),param_4));
  }
  else if (iVar1 == 6) {
    uVar2 = FUN_004a4531((uint)CONCAT21(CONCAT11(param_2,param_3),param_4));
  }
  else if (iVar1 == 7) {
    uVar2 = FUN_0049f21b((uint)CONCAT21(CONCAT11(param_2,param_3),param_4));
  }
  else if (iVar1 == 8) {
    uVar2 = FUN_004a4558((uint)CONCAT21(CONCAT11(param_2,param_3),param_4));
  }
  return uVar2;
}

