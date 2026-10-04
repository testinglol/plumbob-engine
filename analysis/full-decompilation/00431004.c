
void FUN_00431004(int param_1,int param_2,int param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_2;
  while( true ) {
    iVar2 = iVar4 * 2;
    iVar5 = iVar2 + 2;
    if (param_3 <= iVar5) break;
    iVar1 = param_1 + iVar5 * 4;
    cVar3 = (*param_5)(iVar1,iVar1 + -4);
    if (cVar3 != '\0') {
      iVar5 = iVar2 + 1;
    }
    *(undefined4 *)(param_1 + iVar4 * 4) = *(undefined4 *)(param_1 + iVar5 * 4);
    iVar4 = iVar5;
  }
  if (iVar5 == param_3) {
    *(undefined4 *)(param_1 + iVar4 * 4) = *(undefined4 *)(param_1 + -4 + iVar5 * 4);
    iVar4 = iVar2 + 1;
  }
  FUN_00431066(param_1,iVar4,param_2,param_4,param_5);
  return;
}

