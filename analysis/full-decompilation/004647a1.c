
void __thiscall FUN_004647a1(int *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  if ((DAT_006e5308 != 0) && (param_1[3] != 0)) {
    FUN_006357d8(DAT_006e5308,s_bit__d___d_at__d__d_006c4720,param_2,*param_3,param_1[2],param_1[8])
    ;
  }
  if (param_1[3] == 2) {
    if (7 < (int)param_2) {
      uVar1 = param_2 >> 3;
      param_2 = param_2 + uVar1 * -8;
      do {
        param_1[2] = param_1[2] + 1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
    if (0 < (int)param_2) {
      do {
        if (param_1[8] == 0) {
          param_1[2] = param_1[2] + 1;
          param_1[8] = 0x80;
        }
        param_2 = param_2 - 1;
        param_1[8] = param_1[8] / 2;
      } while (param_2 != 0);
    }
  }
  else if (param_1[3] == 1) {
    pbVar2 = (byte *)(*param_1 + -1 + param_1[2]);
    uVar1 = param_1[8];
    for (uVar3 = 1 << ((char)param_2 - 1U & 0x1f); uVar3 != 0; uVar3 = uVar3 >> 1) {
      if (uVar1 == 0) {
        pbVar2 = pbVar2 + 1;
        *pbVar2 = 0;
        uVar1 = 0x80;
      }
      if ((*param_3 & uVar3) != 0) {
        *pbVar2 = *pbVar2 | (byte)uVar1;
      }
      uVar1 = uVar1 >> 1;
    }
    param_1[8] = uVar1;
    param_1[2] = (int)(pbVar2 + (1 - *param_1));
  }
  else {
    pbVar2 = (byte *)(*param_1 + -1 + param_1[2]);
    uVar1 = param_1[8];
    *param_3 = 0;
    for (uVar3 = 1 << ((char)param_2 - 1U & 0x1f); uVar3 != 0; uVar3 = uVar3 >> 1) {
      if (uVar1 == 0) {
        pbVar2 = pbVar2 + 1;
        uVar1 = 0x80;
      }
      if ((*pbVar2 & (byte)uVar1) != 0) {
        *param_3 = *param_3 | uVar3;
      }
      uVar1 = uVar1 >> 1;
    }
    param_1[8] = uVar1;
    param_1[2] = (int)(pbVar2 + (1 - *param_1));
  }
  return;
}

