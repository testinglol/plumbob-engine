
void __thiscall FUN_005cf06d(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  *(int *)(param_1 + 0x14) = param_3;
  *(int *)(param_1 + 0x10) = param_2;
  SetRect((LPRECT)(param_1 + 0x68),*(int *)(param_1 + 8),*(int *)(param_1 + 0xc),
          param_2 + *(int *)(param_1 + 8),param_3 + *(int *)(param_1 + 0xc));
  FUN_005cf0bd();
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x14))(*(int **)(param_1 + 0xd8),param_1 + 4);
  *(int *)(param_1 + 0x5c) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return;
}

