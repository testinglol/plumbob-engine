
void FUN_004e5372(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2;
  while( true ) {
    iVar1 = iVar3 * 2;
    iVar2 = iVar1 + 2;
    if (param_3 <= iVar2) break;
    if (*(int *)(param_1 + iVar2 * 4) < *(int *)(param_1 + -4 + iVar2 * 4)) {
      iVar2 = iVar1 + 1;
    }
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + iVar2 * 4);
    iVar3 = iVar2;
  }
  if (iVar2 == param_3) {
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + -4 + iVar2 * 4);
    iVar3 = iVar1 + 1;
  }
  FUN_004e53ec(param_1,iVar3,param_2,param_4);
  return;
}

