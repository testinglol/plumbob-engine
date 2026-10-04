
uint * __thiscall FUN_005c174f(uint *param_1,char *param_2)

{
  byte bVar1;
  size_t sVar2;
  byte bVar3;
  int iVar4;
  
  sVar2 = _strlen(param_2);
  if (4 < (int)sVar2) {
    sVar2 = 4;
  }
  iVar4 = 0;
  *param_1 = 0;
  if (0 < (int)sVar2) {
    bVar3 = 0x18;
    do {
      bVar1 = bVar3 & 0x1f;
      bVar3 = bVar3 - 8;
      *param_1 = *param_1 | (int)param_2[iVar4] << bVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)sVar2);
  }
  return param_1;
}

