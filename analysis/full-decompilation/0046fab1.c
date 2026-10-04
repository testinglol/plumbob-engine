
int __thiscall FUN_0046fab1(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar2 = param_2;
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  iVar3 = (**(code **)*param_1)();
  iVar3 = iVar3 + (1 - iVar5);
  param_2 = (char *)param_3;
  param_3 = param_3 - iVar3;
  while( true ) {
    if (SBORROW4((int)param_2,iVar3) == param_3 < 0) {
      return -1;
    }
    iVar7 = 0;
    if (iVar5 < 1) break;
    pcVar6 = (char *)(param_1[1] + (int)param_2);
    while (*pcVar6 == pcVar2[iVar7]) {
      iVar7 = iVar7 + 1;
      pcVar6 = pcVar6 + 1;
      if (iVar5 <= iVar7) {
        return (int)param_2;
      }
    }
    param_2 = (char *)((int)param_2 + 1);
    param_3 = (int)param_2 - iVar3;
  }
  return (int)param_2;
}

