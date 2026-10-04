
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062e67b(int param_1,float *param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  int local_18;
  int local_14;
  int local_10;
  int iStack_8;
  
  iVar9 = param_1 + param_3 * 0xa0;
  iVar7 = param_4 * 0x48;
  iVar8 = iVar9 + 0x34e4 + param_4 * 0x48;
  param_4 = 0;
  local_18 = 0;
  if ((*(int *)(iVar9 + 0x34f4 + iVar7) == 0) || (*(int *)(iVar8 + 0x14) != 2)) {
    uVar4 = (uint)*(byte *)(param_1 + 0x4a0f);
  }
  else {
    uVar4 = (uint)*(byte *)(param_1 + 0x4a0f);
    if (*(int *)(iVar8 + 0x18) == 0) {
      local_18 = (int)*(short *)(&DAT_0067d7a8 + uVar4 * 0x4a);
      local_10 = local_18 * 3;
      goto LAB_0062e6f2;
    }
  }
  local_10 = (int)*(short *)(&DAT_0067d77a + uVar4 * 0x4a);
LAB_0062e6f2:
  local_14 = 0;
  fVar10 = (float10)FUN_00636e69(_DAT_00668308,
                                 ((double)*(uint *)(iVar8 + 8) - _DAT_00687e38) * _DAT_00673440);
  iStack_8 = 0;
  psVar5 = (short *)(param_1 + 0x4a04 + param_3 * 2);
  if (0 < *psVar5) {
    pfVar6 = param_2;
    do {
      iVar7 = *(int *)((param_5 - (int)param_2) + (int)pfVar6);
      if (iVar7 == 0) {
        fVar11 = (float10)0;
      }
      else if (iVar7 < 1) {
        fVar11 = -(fVar10 * (float10)*(float *)(&DAT_0067d934 + iVar7 * -4));
      }
      else {
        fVar11 = fVar10 * (float10)*(float *)(&DAT_0067d934 + iVar7 * 4);
      }
      *pfVar6 = (float)fVar11;
      iStack_8 = iStack_8 + 1;
      pfVar6 = pfVar6 + 1;
    } while (iStack_8 < *psVar5);
  }
  iStack_8 = 0;
  pfVar6 = param_2;
  if (0 < *psVar5) {
    do {
      if (iStack_8 == local_10) {
        if ((*(int *)(iVar8 + 0x10) == 0) || (*(int *)(iVar8 + 0x14) != 2)) {
          uVar4 = (uint)*(byte *)(param_1 + 0x4a0f);
LAB_0062e85b:
          param_4 = param_4 + 1;
          local_10 = (int)*(short *)(&DAT_0067d77a + (uVar4 * 0x25 + param_4) * 2);
        }
        else {
          if (*(int *)(iVar8 + 0x18) == 0) {
            param_4 = param_4 + 1;
            iVar7 = ((uint)*(byte *)(param_1 + 0x4a0f) * 0x25 + param_4) * 2;
            local_10 = (int)*(short *)(&DAT_0067d7a8 + iVar7);
            local_14 = (int)*(short *)(&DAT_0067d7a6 + iVar7);
            local_18 = local_10 - local_14;
          }
          else {
            uVar4 = (uint)*(byte *)(param_1 + 0x4a0f);
            iVar7 = uVar4 * 0x4a;
            if (iStack_8 == *(short *)(&DAT_0067d788 + iVar7)) {
              sVar2 = *(short *)(&DAT_0067d7ae + iVar7);
              sVar3 = *(short *)(&DAT_0067d7ac + iVar7);
              param_4 = 3;
            }
            else {
              if (iStack_8 < *(short *)(&DAT_0067d788 + iVar7)) goto LAB_0062e85b;
              param_4 = param_4 + 1;
              iVar7 = (uVar4 * 0x25 + param_4) * 2;
              sVar2 = *(short *)(&DAT_0067d7a8 + iVar7);
              sVar3 = *(short *)(&DAT_0067d7a6 + iVar7);
            }
            local_10 = (int)sVar2;
            local_14 = (int)sVar3;
            local_18 = local_10 - local_14;
          }
          local_10 = local_10 * 3;
          local_14 = local_14 * 3;
        }
      }
      if (((*(int *)(iVar8 + 0x10) == 0) || (*(int *)(iVar8 + 0x14) != 2)) ||
         ((*(int *)(iVar8 + 0x18) != 0 && ((*(int *)(iVar8 + 0x18) == 0 || (iStack_8 < 0x24)))))) {
        iVar7 = *(int *)(param_1 + 0x3614 + (param_3 * 0x3e + param_4) * 4);
        if (*(int *)(iVar8 + 0x3c) != 0) {
          iVar7 = iVar7 + (char)(&UNK_0067d740)[param_4];
        }
        fVar1 = *(float *)(&DAT_00685934 +
                          (iVar7 << ((byte)*(undefined4 *)(iVar8 + 0x40) & 0x1f)) * 4);
      }
      else {
        iVar7 = (iStack_8 - local_14) / local_18;
        fVar1 = *(float *)(&DAT_00685934 +
                          ((*(int *)(param_1 +
                                    (param_3 * 0x3e + param_4 + (iVar7 + 0x10c) * 0xd) * 4) <<
                           ((byte)*(undefined4 *)(iVar8 + 0x40) & 0x1f)) +
                          *(int *)(iVar8 + 0x28 + iVar7 * 4) * 4) * 4);
      }
      iStack_8 = iStack_8 + 1;
      psVar5 = (short *)(param_1 + 0x4a04 + param_3 * 2);
      *pfVar6 = fVar1 * *pfVar6;
      pfVar6 = pfVar6 + 1;
    } while (iStack_8 < *psVar5);
  }
  iVar7 = (int)*psVar5;
  if (iVar7 < 0x240) {
    pfVar6 = param_2 + iVar7;
    for (iVar8 = 0x240 - iVar7; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar6 = 0.0;
      pfVar6 = pfVar6 + 1;
    }
  }
  return;
}

