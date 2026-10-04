
undefined4 __thiscall FUN_00580229(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(int **)(param_1 + 0xbc) = param_2;
  uVar1 = (**(code **)(*param_2 + 0x98))();
  *(undefined4 *)(param_1 + 0xc0) = uVar1;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xbc) + 0x88))(0x1a);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0xc4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xe4);
    *(undefined4 *)(param_1 + 0xc4) = uVar1;
  }
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}

