
void FUN_0044a8e4(int param_1,int param_2,int param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int local_c;
  
  iVar2 = param_2;
  while (iVar1 = param_2 * 2, local_c = iVar1 + 2, local_c < param_3) {
    cVar3 = (*param_5)(*(undefined4 *)(param_1 + local_c * 4),
                       *(undefined4 *)(param_1 + -4 + local_c * 4));
    if (cVar3 != '\0') {
      local_c = iVar1 + 1;
    }
    *(undefined4 *)(param_1 + param_2 * 4) = *(undefined4 *)(param_1 + local_c * 4);
    param_2 = local_c;
  }
  if (local_c == param_3) {
    *(undefined4 *)(param_1 + param_2 * 4) = *(undefined4 *)(param_1 + -4 + local_c * 4);
    param_2 = iVar1 + 1;
  }
  FUN_0044a989(param_1,param_2,iVar2,param_4,param_5);
  return;
}

