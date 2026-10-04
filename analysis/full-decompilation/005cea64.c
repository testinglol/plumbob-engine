
undefined4 __thiscall FUN_005cea64(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_00462f2f(param_2);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_2 + 0x40);
  piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
  uVar2 = (**(code **)(*piVar1 + 100))(piVar1,1,param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0x5c) = uVar2;
  return 0;
}

