
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006651ee(int param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  float *pfVar9;
  float *extraout_ECX;
  undefined8 *extraout_ECX_00;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  float in_XMM4_Da;
  float in_XMM4_Db;
  float in_XMM4_Dc;
  float in_XMM4_Dd;
  float in_XMM5_Da;
  float in_XMM5_Db;
  float in_XMM5_Dc;
  float in_XMM5_Dd;
  float in_XMM6_Da;
  float in_XMM6_Db;
  float in_XMM6_Dc;
  float in_XMM6_Dd;
  float in_XMM7_Da;
  float in_XMM7_Db;
  float in_XMM7_Dc;
  float in_XMM7_Dd;
  undefined8 uVar23;
  
  if (DAT_006f76f0 == 0) {
    if (DAT_006d21d4 != '\0') {
      uVar23 = FUN_00665033();
      puVar10 = (undefined8 *)((ulonglong)uVar23 >> 0x20);
      puVar7 = (undefined8 *)uVar23;
      do {
        uVar23 = *(undefined8 *)param_2;
        uVar11 = (ulonglong)(uint)param_2[2];
        uVar12 = PackedFloatingMUL(puVar10[4],uVar23);
        uVar13 = PackedFloatingMUL(puVar10[5],uVar11);
        uVar14 = PackedFloatingMUL(*puVar10,uVar23);
        uVar15 = PackedFloatingMUL(puVar10[1],uVar11);
        uVar16 = PackedFloatingMUL(puVar10[2],uVar23);
        uVar23 = PackedFloatingADD(uVar12,uVar13);
        uVar13 = PackedFloatingMUL(puVar10[3],uVar11);
        uVar12 = PackedFloatingADD(uVar14,uVar15);
        uVar23 = PackedFloatingAccumulate(uVar23,uVar23);
        uVar14 = PackedFloatingADD(uVar16,uVar13);
        uVar13 = PackedFloatingADD(uVar23,extraout_ECX_00[1]);
        uVar23 = PackedFloatingAccumulate(uVar12,uVar14);
        uVar12 = FloatingReciprocalAprox(uVar11,uVar13);
        uVar14 = PackedFloatingADD(uVar23,*extraout_ECX_00);
        uVar23 = PackedFloatingReciprocalIter1(uVar13,uVar12);
        param_2 = (float *)((int)param_2 + DAT_006d200c);
        uVar13 = PackedFloatingSUB(uVar13,(ulonglong)(uint)DAT_006d20e0);
        uVar14 = PackedFloatingMUL(uVar14,CONCAT44(DAT_006f7750._4_4_,(undefined4)DAT_006f7750));
        uVar12 = PackedFloatingReciprocalIter2(uVar23,uVar12);
        puVar8 = (undefined8 *)((int)puVar7 + DAT_006d2010);
        uVar23 = CONCAT44(DAT_006f7760._4_4_,(undefined4)DAT_006f7760);
        uVar13 = PackedFloatingMUL(uVar13,(ulonglong)(uint)DAT_006d20f0);
        *(int *)((int)puVar7 + 0xc) = (int)uVar12;
        uVar12 = PackedFloatingMUL(uVar14,uVar12);
        *(int *)(puVar7 + 1) = (int)uVar13;
        uVar23 = PackedFloatingADD(uVar12,uVar23);
        param_1 = param_1 + -1;
        *puVar7 = uVar23;
        puVar7 = puVar8;
      } while (param_1 != 0);
      FastExitMediaState();
      return;
    }
    if (DAT_006d21bc != '\0') {
      pfVar5 = (float *)FUN_0066510c();
      do {
        fVar20 = *param_2;
        fVar17 = param_2[1];
        fVar18 = param_2[2];
        auVar21._0_4_ = fVar17 * in_XMM5_Da + fVar18 * in_XMM6_Da;
        auVar21._4_4_ = fVar17 * in_XMM5_Db + fVar18 * in_XMM6_Db;
        auVar21._8_4_ = fVar17 * in_XMM5_Dc + fVar18 * in_XMM6_Dc;
        auVar21._12_4_ = fVar17 * in_XMM5_Dd + fVar18 * in_XMM6_Dd;
        fVar17 = fVar20 * in_XMM4_Da + in_XMM7_Da + auVar21._0_4_;
        fVar18 = fVar20 * in_XMM4_Db + in_XMM7_Db + auVar21._4_4_;
        fVar19 = fVar20 * in_XMM4_Dc + in_XMM7_Dc + auVar21._8_4_;
        param_2 = (float *)((int)param_2 + DAT_006d200c);
        pfVar9 = (float *)((int)pfVar5 + DAT_006d2010);
        auVar22._4_4_ = fVar18;
        auVar22._0_4_ = fVar17;
        auVar22._8_4_ = fVar19;
        auVar22._12_4_ = fVar20 * in_XMM4_Dd + in_XMM7_Dd + auVar21._12_4_;
        auVar22 = rcpss(auVar21,auVar22);
        fVar20 = auVar22._0_4_;
        fVar20 = (fVar20 + fVar20) - fVar17 * fVar20 * fVar20;
        fVar18 = DAT_006f7750._4_4_ * fVar18;
        fVar19 = _DAT_006f7758 * fVar19;
        pfVar5[2] = (fVar17 - DAT_006d20e0) * DAT_006d20f0;
        pfVar5[3] = fVar20;
        fVar17 = fVar18 * fVar20 + DAT_006f7760._4_4_;
        *pfVar5 = fVar19 * fVar20 + _DAT_006f7768;
        pfVar5[1] = fVar17;
        param_1 = param_1 + -1;
        pfVar5 = pfVar9;
      } while (param_1 != 0);
      return;
    }
  }
  uVar23 = FUN_00665000();
  pfVar9 = (float *)((ulonglong)uVar23 >> 0x20);
  pfVar5 = (float *)uVar23;
  do {
    fVar20 = *param_2;
    fVar17 = *param_2;
    pfVar1 = param_2 + 1;
    pfVar2 = param_2 + 1;
    pfVar3 = param_2 + 2;
    pfVar4 = param_2 + 2;
    fVar19 = param_2[2] * pfVar9[8] + param_2[1] * pfVar9[5] + *param_2 * pfVar9[2] +
             extraout_ECX[2];
    fVar18 = _DAT_006d20c0 / fVar19;
    param_2 = (float *)((int)param_2 + DAT_006d200c);
    pfVar6 = (float *)((int)pfVar5 + DAT_006d2010);
    fVar17 = (*pfVar4 * pfVar9[7] + *pfVar2 * pfVar9[4] + fVar17 * pfVar9[1] + extraout_ECX[1]) *
             DAT_006d20f8;
    fVar20 = (*pfVar3 * pfVar9[6] + *pfVar1 * pfVar9[3] + fVar20 * *pfVar9 + *extraout_ECX) *
             DAT_006d20f4;
    fVar19 = (fVar19 - DAT_006d20e0) * DAT_006d20f0;
    pfVar5[3] = fVar18;
    fVar17 = DAT_006d2100 - fVar17 * fVar18;
    fVar20 = fVar20 * fVar18 + DAT_006d20fc;
    pfVar5[2] = fVar19;
    pfVar5[1] = fVar17;
    *pfVar5 = fVar20;
    param_1 = param_1 + -1;
    pfVar5 = pfVar6;
  } while (param_1 != 0);
  return;
}

