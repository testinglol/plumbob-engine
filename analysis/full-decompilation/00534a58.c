
int FUN_00534a58(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = (param_2 - param_1) / 0x28;
  while (iVar2 = iVar4, 0 < iVar2) {
    iVar4 = iVar2 >> 1;
    iVar1 = param_1 + iVar4 * 0x28;
    cVar3 = (*param_4)(iVar1,param_3);
    if (cVar3 != '\0') {
      param_1 = iVar1 + 0x28;
      iVar4 = iVar2 + (-1 - iVar4);
    }
  }
  return param_1;
}

