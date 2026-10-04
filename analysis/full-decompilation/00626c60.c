
uint FUN_00626c60(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5,uint param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  iVar4 = *param_2;
  iVar5 = *(int *)(iVar4 + 0x18);
  param_4 = (*(int *)(param_3 + 0x450) - *(int *)(iVar4 + 0x450)) + param_4;
  param_5 = (*(int *)(param_3 + 0x454) - *(int *)(iVar4 + 0x454)) + param_5;
  *param_1 = 0;
  if ((((-1 < param_4) && (param_4 < *(int *)(iVar4 + 0x10))) && (-1 < param_5)) &&
     (param_5 < *(int *)(iVar4 + 0x14))) {
    param_4 = param_4 * iVar5;
    pbVar6 = (byte *)(param_2[2] * param_5 + ((int)(param_4 + (param_4 >> 0x1f & 7U)) >> 3) +
                     param_2[1]);
    if (iVar5 == 8) {
      bVar1 = *pbVar6;
      *param_1 = 1;
      return (uint)bVar1;
    }
    bVar1 = pbVar6[3];
    bVar2 = pbVar6[1];
    bVar3 = *pbVar6;
    *param_1 = 1;
    return CONCAT31(CONCAT21(CONCAT11(bVar1,pbVar6[2]),bVar2),bVar3);
  }
  return param_6;
}

