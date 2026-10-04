
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004214d4(int *param_1,int param_2)

{
  short *psVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  int local_c;
  float local_8;
  
  iVar4 = *param_1;
  local_8 = 0.0;
  if (iVar4 != iVar4 + param_1[1] * 0x14) {
    do {
      psVar1 = (short *)(param_2 + *(int *)(iVar4 + 0x10) * 6);
      sVar2 = *psVar1;
      if (sVar2 == 0) {
        fVar3 = (float)((int)psVar1[2] + (int)psVar1[1]);
      }
      else {
        local_c = (int)*(short *)(param_1[0x2f] + 0x58c + *(int *)(&DAT_00666a6c + sVar2 * 0xc) * 2)
        ;
        if (*(int *)(&DAT_00666a70 + sVar2 * 0xc) != 0) {
          local_c = 1000 - local_c;
        }
        fVar3 = (float)(int)psVar1[2] * (float)local_c * _DAT_00666a24 + (float)(int)psVar1[1];
      }
      fVar5 = (float10)FUN_004167d4(fVar3 * _DAT_00666b7c +
                                    *(float *)(param_1[0x30] + *(int *)(iVar4 + 0x10) * 4));
      iVar4 = iVar4 + 0x14;
      local_8 = (float)(fVar5 + (float10)local_8);
    } while (iVar4 != *param_1 + param_1[1] * 0x14);
  }
  return (float10)local_8 / (float10)param_1[1];
}

