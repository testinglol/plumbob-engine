
uint __thiscall FUN_0044058c(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (int)*param_2 + (int)param_2[1];
  iVar1 = (int)*param_1 + (int)param_1[1];
  if (iVar1 == iVar2) {
    iVar2 = (int)*param_2 - (int)param_2[1];
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),(int)*param_1 - (int)param_1[1] < iVar2);
  }
  else {
    uVar3 = (uint)(iVar1 < iVar2);
  }
  return uVar3;
}

