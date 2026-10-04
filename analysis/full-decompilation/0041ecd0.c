
void FUN_0041ecd0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  while ((param_3 < param_2 && (iVar1 = (param_2 + -1) / 2, *(int *)(param_1 + iVar1 * 8) < param_4)
         )) {
    *(undefined4 *)(param_1 + param_2 * 8) = *(undefined4 *)(param_1 + iVar1 * 8);
    *(undefined4 *)(param_1 + 4 + param_2 * 8) = *(undefined4 *)(param_1 + 4 + iVar1 * 8);
    param_2 = iVar1;
  }
  *(int *)(param_1 + param_2 * 8) = param_4;
  *(undefined4 *)(param_1 + 4 + param_2 * 8) = param_5;
  return;
}

