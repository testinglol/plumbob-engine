
int __thiscall FUN_0046f990(undefined4 *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_1[1];
  iVar1 = (**(code **)*param_1)();
  iVar6 = iVar1;
  if (param_3 < iVar1) {
    iVar6 = param_3;
  }
  iVar2 = 0;
  if (0 < iVar6) {
    iVar5 = iVar5 - (int)param_2;
    do {
      cVar3 = param_2[iVar5];
      cVar4 = *param_2;
      if (('@' < cVar3) && (cVar3 < '[')) {
        cVar3 = cVar3 + ' ';
      }
      if (('@' < cVar4) && (cVar4 < '[')) {
        cVar4 = cVar4 + ' ';
      }
      if ((int)cVar3 - (int)cVar4 != 0) {
        return (int)cVar3 - (int)cVar4;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 < iVar6);
  }
  return iVar1 - param_3;
}

