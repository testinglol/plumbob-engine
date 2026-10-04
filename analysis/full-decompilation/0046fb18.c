
int __thiscall FUN_0046fb18(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  
  uVar3 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar6 != '\0');
  iVar4 = ~uVar3 - 1;
  iVar2 = (**(code **)*param_1)();
  iVar2 = iVar2 + (1 - iVar4);
  iVar7 = param_3 - iVar2;
  while( true ) {
    if (SBORROW4(param_3,iVar2) == iVar7 < 0) {
      return -1;
    }
    iVar7 = 0;
    if (iVar4 < 1) break;
    pcVar5 = (char *)(param_1[1] + param_3);
    while( true ) {
      cVar6 = *pcVar5;
      cVar1 = param_2[iVar7];
      if (('@' < cVar6) && (cVar6 < '[')) {
        cVar6 = cVar6 + ' ';
      }
      if (('@' < cVar1) && (cVar1 < '[')) {
        cVar1 = cVar1 + ' ';
      }
      if (cVar6 != cVar1) break;
      iVar7 = iVar7 + 1;
      pcVar5 = pcVar5 + 1;
      if (iVar4 <= iVar7) {
        return param_3;
      }
    }
    param_3 = param_3 + 1;
    iVar7 = param_3 - iVar2;
  }
  return param_3;
}

