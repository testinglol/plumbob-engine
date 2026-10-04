
void FUN_004ce19b(int param_1,int param_2,int param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2;
  while( true ) {
    iVar1 = iVar3 * 2;
    iVar4 = iVar1 + 2;
    if (param_3 <= iVar4) break;
    cVar2 = (*param_5)(*(undefined4 *)(param_1 + iVar4 * 4),
                       *(undefined4 *)(param_1 + -4 + iVar4 * 4));
    if (cVar2 != '\0') {
      iVar4 = iVar1 + 1;
    }
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + iVar4 * 4);
    iVar3 = iVar4;
  }
  if (iVar4 == param_3) {
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + -4 + iVar4 * 4);
    iVar3 = iVar1 + 1;
  }
  FUN_004ce1fc(param_1,iVar3,param_2,param_4,param_5);
  return;
}

