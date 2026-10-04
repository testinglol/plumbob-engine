
void FUN_005b8300(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (param_1 == 0) {
    puVar3 = &DAT_006d229c;
    do {
      puVar2 = puVar3 + 2;
      *puVar3 = (*puVar3 ^ (uint)(param_2 != 0)) & 1 ^ *puVar3;
      puVar3 = puVar2;
    } while ((int)puVar2 < 0x6d249c);
    return;
  }
  if (param_1 == 1) {
    puVar3 = &DAT_006d229c;
    do {
      uVar1 = *puVar3;
      if ((uVar1 & 2) != 0) {
        *puVar3 = (param_2 != 0 ^ uVar1) & 1 ^ uVar1;
      }
      puVar3 = puVar3 + 2;
    } while ((int)puVar3 < 0x6d249c);
    return;
  }
  (&DAT_006d229c)[param_1 * 2] =
       ((uint)(param_2 != 0) ^ (&DAT_006d229c)[param_1 * 2]) & 1 ^ (&DAT_006d229c)[param_1 * 2];
  return;
}

