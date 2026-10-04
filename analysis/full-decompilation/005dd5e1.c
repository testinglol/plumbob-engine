
undefined2 __thiscall
FUN_005dd5e1(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x5c) == 0) {
    piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    uVar1 = (**(code **)(*piVar2 + 0x38))(param_2,param_3,param_4);
  }
  else {
    uVar1 = FUN_005dfe3b(param_2,param_3,param_4);
  }
  return uVar1;
}

