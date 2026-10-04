
undefined4 __fastcall FUN_005c74c0(float *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  ushort uVar13;
  float fVar11;
  undefined4 uVar12;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined2 uVar14;
  
  uVar10 = (uint)param_3;
  fVar5 = param_1[1];
  fVar6 = param_1[2];
  fVar7 = param_1[3];
  fVar1 = *param_1;
  fVar8 = param_1[4];
  fVar9 = param_1[5];
  iVar17 = 0;
  fVar11 = fVar9;
  do {
    param_3 = *(float *)(iVar17 + (int)param_1);
    fVar2 = *(float *)(iVar17 + 0xc + (int)param_1);
    uVar16 = uVar10;
    iVar18 = param_2;
    if (1 < (int)uVar10) {
      uVar15 = uVar10 >> 1;
      fVar11 = (float)(uVar15 * 2);
      uVar16 = uVar10 + uVar15 * -2;
      do {
        fVar3 = *(float *)(iVar17 + iVar18);
        fVar4 = *(float *)(iVar17 + iVar18 + 0xc);
        iVar18 = iVar18 + 0x18;
        uVar13 = (ushort)((uint)fVar11 >> 0x10);
        if (fVar4 <= fVar3) {
          fVar11 = (float)((uint)CONCAT21(uVar13,fVar4 < param_3) << 8);
          if (fVar4 < param_3) {
            fVar11 = fVar4;
            param_3 = fVar4;
          }
          fVar11 = (float)((uint)fVar11 & 0xffff0000);
          if (fVar2 < fVar3) {
            fVar2 = fVar3;
          }
        }
        else {
          if (fVar3 < param_3) {
            param_3 = fVar3;
          }
          fVar11 = (float)((uint)uVar13 << 0x10);
          if (fVar2 < fVar4) {
            fVar2 = fVar4;
          }
        }
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    if (0 < (int)uVar16) {
      fVar3 = *(float *)(iVar17 + iVar18);
      if (fVar3 < param_3) {
        param_3 = fVar3;
      }
      fVar11 = (float)((uint)CONCAT21((short)((uint)fVar11 >> 0x10),fVar2 < fVar3) << 8);
      if (fVar2 < fVar3) {
        fVar2 = fVar3;
      }
    }
    *(float *)(iVar17 + (int)param_1) = param_3;
    *(float *)(iVar17 + 0xc + (int)param_1) = fVar2;
    iVar17 = iVar17 + 4;
  } while (iVar17 < 0xc);
  fVar2 = *param_1;
  uVar14 = (undefined2)((uint)fVar11 >> 0x10);
  uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe);
  if (fVar1 < fVar2 != 0 || (fVar1 == fVar2) != 0) {
    fVar1 = param_1[1];
    uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar5) << 8 | (ushort)(NAN(fVar1) || NAN(fVar5)) << 10
                             | (ushort)(fVar1 == fVar5) << 0xe);
    if (fVar1 < fVar5 == 0) {
      fVar1 = param_1[2];
      uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar6) << 8 |
                               (ushort)(NAN(fVar1) || NAN(fVar6)) << 10 |
                               (ushort)(fVar1 == fVar6) << 0xe);
      if (fVar1 < fVar6 == 0) {
        fVar1 = param_1[3];
        uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar7) << 8 |
                                 (ushort)(NAN(fVar1) || NAN(fVar7)) << 10 |
                                 (ushort)(fVar1 == fVar7) << 0xe);
        if (fVar1 < fVar7 != 0 || (fVar1 == fVar7) != 0) {
          fVar1 = param_1[4];
          uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar8) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(fVar8)) << 10 |
                                   (ushort)(fVar1 == fVar8) << 0xe);
          if (fVar1 < fVar8 != 0 || (fVar1 == fVar8) != 0) {
            fVar1 = param_1[5];
            uVar12 = CONCAT22(uVar14,(ushort)(fVar1 < fVar9) << 8 |
                                     (ushort)(NAN(fVar1) || NAN(fVar9)) << 10 |
                                     (ushort)(fVar1 == fVar9) << 0xe);
            if (fVar1 < fVar9 || (fVar1 == fVar9) != 0) {
              return uVar12;
            }
          }
        }
        return CONCAT31((int3)((uint)uVar12 >> 8),1);
      }
    }
  }
  return CONCAT31((int3)((uint)uVar12 >> 8),1);
}

