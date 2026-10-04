
undefined4 FUN_00612680(int *param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = *(int *)(*param_1 + 0x18);
  param_2 = iVar1 * param_2;
  pbVar2 = (byte *)(((int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3) + param_1[2] * param_3 +
                   param_1[1]);
  if (iVar1 == 8) {
    pbVar2 = (byte *)(*param_1 + 0x28 + (uint)*pbVar2 * 4);
  }
  return *(undefined4 *)pbVar2;
}

