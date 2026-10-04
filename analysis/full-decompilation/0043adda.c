
int __thiscall FUN_0043adda(int param_1,int param_2)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int local_8;
  
  sVar1 = *(short *)(*(int *)(param_2 + 0x60) + 0x14);
  if (sVar1 == 0) {
    iVar3 = 0;
  }
  else {
    local_8 = 0;
    if (0 < (int)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) & 0xfffffffcU)) {
      do {
        iVar3 = FUN_0043ad1f((int)(short)local_8);
        cVar2 = FUN_005c17a6(param_2);
        if (((cVar2 != '\0') && (*(short *)(*(int *)(iVar3 + 0x60) + 0x14) == sVar1)) &&
           (*(short *)(*(int *)(iVar3 + 0x60) + 0x7e) != 0)) {
          return iVar3;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2);
    }
    iVar3 = FUN_0043ad41(param_2,0,0,0);
  }
  return iVar3;
}

