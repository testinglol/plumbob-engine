
uint FUN_004020d4(undefined4 param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  pbVar1 = (byte *)FUN_0040204f(param_1);
  if ((((pbVar1 != (byte *)0x0) && (-1 < (int)param_2)) &&
      (iVar2 = (int)*(short *)(pbVar1 + 2), (int)param_2 < iVar2)) && (uVar3 = 0, 0 < iVar2)) {
    pbVar1 = pbVar1 + 0xf;
    do {
      if ((uVar3 != param_2) && ((pbVar1[-1] == param_2 || (*pbVar1 == param_2)))) {
        return CONCAT31((int3)((uint)pbVar1 >> 8),1);
      }
      uVar3 = uVar3 + 1;
      pbVar1 = pbVar1 + 0xc;
    } while ((int)uVar3 < iVar2);
  }
  return (uint)pbVar1 & 0xffffff00;
}

