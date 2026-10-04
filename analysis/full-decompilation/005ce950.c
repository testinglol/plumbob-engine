
undefined4 __thiscall FUN_005ce950(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((param_3 == 0) || (param_3 == *(int *)(param_1 + 0x90))) {
    FUN_00462f2f(param_2);
    *(undefined4 *)(param_1 + 0x1b0) = *(undefined4 *)(param_2 + 0x40);
    piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
    uVar2 = (**(code **)(*piVar1 + 100))(piVar1,3,param_1 + 0x170);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

