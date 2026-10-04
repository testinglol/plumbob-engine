
void FUN_00576c38(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != param_3) {
    **(int **)(param_3 + 4) = param_1;
    **(int **)(param_2 + 4) = param_3;
    **(int **)(param_1 + 4) = param_2;
    uVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_2 + 4) = uVar1;
  }
  return;
}

