
int __thiscall FUN_0043ad41(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  
  if ((-1 < param_3) && (-1 < param_4)) {
    sVar4 = FUN_00431909(param_3,param_4);
    sVar1 = *(short *)(*(int *)(param_2 + 0x60) + 0x14);
    if ((sVar1 != 0) &&
       (param_4 = 0, 0 < (int)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) & 0xfffffffcU)))
    {
      do {
        iVar5 = FUN_0043ad1f((int)(short)param_4);
        cVar3 = FUN_005c17a6(param_2);
        if ((((cVar3 != '\0') && (iVar2 = *(int *)(iVar5 + 0x60), *(short *)(iVar2 + 0x14) == sVar1)
             ) && (*(short *)(iVar2 + 0x16) == sVar4)) && (*(short *)(iVar2 + 0x70) == param_5)) {
          return iVar5;
        }
        param_4 = param_4 + 1;
      } while (param_4 < *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2);
    }
  }
  return 0;
}

