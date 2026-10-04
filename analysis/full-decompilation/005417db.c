
int FUN_005417db(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = param_2 - param_1 >> 2;
  while (iVar2 = iVar4, 0 < iVar2) {
    iVar4 = iVar2 >> 1;
    iVar1 = param_1 + iVar4 * 4;
    cVar3 = (*param_4)(iVar1,param_3);
    if (cVar3 != '\0') {
      param_1 = iVar1 + 4;
      iVar4 = iVar2 + (-1 - iVar4);
    }
  }
  return param_1;
}

