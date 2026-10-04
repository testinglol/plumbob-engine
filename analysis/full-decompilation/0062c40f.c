
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062c40f(float *param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float *pfVar29;
  int iVar30;
  
  if (param_3 == 2) {
    iVar30 = 4;
    pfVar29 = param_2 + 7;
    do {
      pfVar29[1] = 0.0;
      *pfVar29 = 0.0;
      pfVar29[-1] = 0.0;
      pfVar29[-2] = 0.0;
      pfVar29[-3] = 0.0;
      pfVar29[-4] = 0.0;
      pfVar29[-5] = 0.0;
      pfVar29[-6] = 0.0;
      pfVar29[-7] = 0.0;
      fVar5 = _DAT_00687e34;
      fVar4 = _DAT_00687e30;
      fVar3 = _DAT_00666578;
      pfVar29 = pfVar29 + 9;
      iVar30 = iVar30 + -1;
    } while (iVar30 != 0);
    param_1 = param_1 + 9;
    iVar30 = 3;
    pfVar29 = param_2 + 7;
    do {
      param_1[6] = param_1[6] + param_1[3];
      param_1[3] = *param_1 + param_1[3];
      *param_1 = param_1[-3] + *param_1;
      param_1[-3] = param_1[-3] + param_1[-6];
      param_1[-6] = param_1[-6] + param_1[-9];
      param_1[6] = param_1[6] + *param_1;
      fVar2 = *param_1;
      *param_1 = fVar2 + param_1[-6];
      fVar6 = param_1[-3] * fVar5;
      fVar8 = param_1[3] * fVar3 + param_1[-9];
      fVar9 = fVar8 + fVar6;
      fVar8 = fVar8 - fVar6;
      fVar2 = (fVar2 + param_1[-6]) * fVar5;
      fVar7 = param_1[6] * fVar3 + param_1[-6];
      fVar6 = (fVar7 - fVar2) * _DAT_00687e2c;
      fVar10 = (param_1[-6] - param_1[6]) * _DAT_00687e28;
      fVar7 = (fVar7 + fVar2) * _DAT_00687e24;
      fVar11 = (fVar7 + fVar9) * _DAT_00687e20;
      fVar12 = (fVar10 + (param_1[-9] - param_1[3])) * _DAT_00687e1c;
      fVar2 = (fVar8 + fVar6) * _DAT_00687e18;
      pfVar1 = pfVar29 + 6;
      fVar6 = (fVar8 - fVar6) * _DAT_00687e14;
      fVar8 = ((param_1[-9] - param_1[3]) - fVar10) * _DAT_00687e10;
      fVar9 = (fVar9 - fVar7) * _DAT_00687e0c;
      fVar10 = fVar11 * _DAT_00687e08;
      fVar13 = fVar12 * _DAT_00687e04;
      fVar12 = fVar12 * _DAT_00687e00;
      fVar14 = fVar2 * _DAT_00687dfc;
      fVar2 = fVar2 * _DAT_00687df8;
      fVar15 = fVar8 * _DAT_00687df4;
      fVar16 = fVar9 * _DAT_00687df0;
      fVar8 = fVar8 * _DAT_00687e04;
      fVar7 = fVar6 * _DAT_00687dfc;
      pfVar29[-1] = fVar6 * _DAT_00687dec + pfVar29[-1];
      *pfVar29 = fVar15 + *pfVar29;
      pfVar29[1] = fVar16 + pfVar29[1];
      pfVar29[2] = fVar9 * fVar4 + pfVar29[2];
      pfVar29[3] = fVar8 + pfVar29[3];
      pfVar29[4] = fVar7 + pfVar29[4];
      pfVar29[5] = fVar14 + pfVar29[5];
      *pfVar1 = fVar13 + *pfVar1;
      pfVar29[7] = fVar11 * fVar4 + pfVar29[7];
      pfVar29[8] = fVar10 + pfVar29[8];
      pfVar29[9] = fVar12 + pfVar29[9];
      pfVar29[10] = fVar2 + pfVar29[10];
      param_1 = param_1 + 1;
      iVar30 = iVar30 + -1;
      pfVar29 = pfVar1;
    } while (iVar30 != 0);
    return;
  }
  param_1[0x11] = param_1[0x10] + param_1[0x11];
  param_1[0x10] = param_1[0x10] + param_1[0xf];
  param_1[0xf] = param_1[0xf] + param_1[0xe];
  param_1[0xe] = param_1[0xe] + param_1[0xd];
  param_1[0xd] = param_1[0xd] + param_1[0xc];
  param_1[0xc] = param_1[0xc] + param_1[0xb];
  param_1[0xb] = param_1[0xb] + param_1[10];
  param_1[10] = param_1[10] + param_1[9];
  param_1[9] = param_1[9] + param_1[8];
  param_1[8] = param_1[8] + param_1[7];
  param_1[7] = param_1[7] + param_1[6];
  param_1[6] = param_1[6] + param_1[5];
  param_1[5] = param_1[5] + param_1[4];
  param_1[4] = param_1[4] + param_1[3];
  param_1[3] = param_1[3] + param_1[2];
  param_1[2] = param_1[2] + param_1[1];
  fVar2 = *param_1 + param_1[1];
  param_1[1] = fVar2;
  param_1[0x11] = param_1[0x11] + param_1[0xf];
  param_1[0xf] = param_1[0xf] + param_1[0xd];
  param_1[0xd] = param_1[0xd] + param_1[0xb];
  param_1[0xb] = param_1[0xb] + param_1[9];
  param_1[9] = param_1[9] + param_1[7];
  param_1[7] = param_1[7] + param_1[5];
  param_1[5] = param_1[5] + param_1[3];
  fVar7 = fVar2 + param_1[3];
  param_1[3] = fVar7;
  fVar3 = *param_1 + *param_1;
  fVar4 = fVar3 + param_1[0xc];
  fVar17 = param_1[4] * _DAT_00687de8 + param_1[8] * _DAT_00687de4 + param_1[0x10] * _DAT_00687de0 +
           fVar4;
  fVar3 = ((((fVar3 + param_1[4]) - param_1[8]) - param_1[0xc]) - param_1[0xc]) - param_1[0x10];
  fVar16 = param_1[0x10] * _DAT_00687de4 +
           ((fVar4 - param_1[4] * _DAT_00687de0) - param_1[8] * _DAT_00687de8);
  fVar6 = (param_1[8] * _DAT_00687de0 + (fVar4 - param_1[4] * _DAT_00687de4)) -
          param_1[0x10] * _DAT_00687de8;
  fVar4 = (((*param_1 - param_1[4]) + param_1[8]) - param_1[0xc]) + param_1[0x10];
  fVar5 = param_1[6] * _DAT_006689b0;
  fVar19 = param_1[2] * _DAT_00687dd4 + param_1[10] * _DAT_00687dd8 + param_1[0xe] * _DAT_00687ddc +
           fVar5;
  fVar18 = ((param_1[2] - param_1[10]) - param_1[0xe]) * _DAT_006689b0;
  fVar21 = param_1[0xe] * _DAT_00687dd4 +
           ((param_1[2] * _DAT_00687dd8 - fVar5) - param_1[10] * _DAT_00687ddc);
  fVar20 = (param_1[10] * _DAT_00687dd4 + (param_1[2] * _DAT_00687ddc - fVar5)) -
           param_1[0xe] * _DAT_00687dd8;
  fVar8 = fVar2 + fVar2 + param_1[0xd];
  fVar15 = param_1[5] * _DAT_00687de8 + param_1[9] * _DAT_00687de4 + param_1[0x11] * _DAT_00687de0 +
           fVar8;
  fVar5 = ((((fVar2 + fVar2 + param_1[5]) - param_1[9]) - param_1[0xd]) - param_1[0xd]) -
          param_1[0x11];
  fVar14 = param_1[0x11] * _DAT_00687de4 +
           ((fVar8 - param_1[5] * _DAT_00687de0) - param_1[9] * _DAT_00687de8);
  fVar8 = (param_1[9] * _DAT_00687de0 + (fVar8 - param_1[5] * _DAT_00687de4)) -
          param_1[0x11] * _DAT_00687de8;
  fVar22 = ((((fVar2 - param_1[5]) + param_1[9]) - param_1[0xd]) + param_1[0x11]) * _DAT_00687e28;
  fVar2 = param_1[7] * _DAT_006689b0;
  fVar11 = param_1[0xb] * _DAT_00687dd8 + param_1[0xf] * _DAT_00687ddc + fVar7 * _DAT_00687dd4 +
           fVar2;
  fVar13 = ((fVar7 - param_1[0xb]) - param_1[0xf]) * _DAT_006689b0;
  fVar12 = param_1[0xf] * _DAT_00687dd4 +
           ((fVar7 * _DAT_00687dd8 - fVar2) - param_1[0xb] * _DAT_00687ddc);
  fVar7 = (param_1[0xb] * _DAT_00687dd4 + (fVar7 * _DAT_00687ddc - fVar2)) -
          param_1[0xf] * _DAT_00687dd8;
  fVar23 = fVar19 + fVar17;
  fVar2 = (fVar11 + fVar15) * _DAT_00687dd0;
  fVar24 = fVar2 + fVar23;
  fVar23 = fVar23 - fVar2;
  fVar25 = fVar18 + fVar3;
  fVar2 = (fVar13 + fVar5) * _DAT_00687e24;
  fVar26 = fVar2 + fVar25;
  fVar25 = fVar25 - fVar2;
  fVar27 = fVar21 + fVar16;
  fVar2 = (fVar12 + fVar14) * _DAT_00687dcc;
  fVar28 = fVar2 + fVar27;
  fVar27 = fVar27 - fVar2;
  fVar10 = fVar20 + fVar6;
  fVar2 = (fVar7 + fVar8) * _DAT_00687dc8;
  fVar9 = fVar2 + fVar10;
  fVar10 = fVar10 - fVar2;
  fVar2 = fVar22 + fVar4;
  fVar4 = fVar4 - fVar22;
  param_3 = param_3 * 0x90;
  fVar6 = fVar6 - fVar20;
  fVar7 = (fVar8 - fVar7) * _DAT_00687dc4;
  fVar8 = fVar7 + fVar6;
  fVar6 = fVar6 - fVar7;
  fVar16 = fVar16 - fVar21;
  fVar12 = (fVar14 - fVar12) * _DAT_00687dc0;
  fVar7 = fVar12 + fVar16;
  fVar16 = fVar16 - fVar12;
  fVar3 = fVar3 - fVar18;
  fVar12 = (fVar5 - fVar13) * _DAT_00687e2c;
  fVar5 = fVar12 + fVar3;
  fVar3 = fVar3 - fVar12;
  fVar17 = fVar17 - fVar19;
  fVar12 = (fVar15 - fVar11) * _DAT_00687dbc;
  fVar11 = fVar12 + fVar17;
  fVar17 = fVar17 - fVar12;
  *param_2 = -(fVar17 * *(float *)(&DAT_00687b34 + param_3));
  param_2[1] = -(fVar3 * *(float *)(&DAT_00687b38 + param_3));
  param_2[2] = -(fVar16 * *(float *)(&DAT_00687b3c + param_3));
  param_2[3] = -(fVar6 * *(float *)(&DAT_00687b40 + param_3));
  param_2[4] = -(fVar4 * *(float *)(&DAT_00687b44 + param_3));
  param_2[5] = -(fVar10 * *(float *)(&DAT_00687b48 + param_3));
  param_2[6] = -(fVar27 * *(float *)(&DAT_00687b4c + param_3));
  param_2[7] = -(fVar25 * *(float *)(&DAT_00687b50 + param_3));
  param_2[8] = -(fVar23 * *(float *)(&DAT_00687b54 + param_3));
  param_2[9] = fVar23 * *(float *)(&DAT_00687b58 + param_3);
  param_2[10] = fVar25 * *(float *)(&DAT_00687b5c + param_3);
  param_2[0xb] = fVar27 * *(float *)(&DAT_00687b60 + param_3);
  param_2[0xc] = fVar10 * *(float *)(&DAT_00687b64 + param_3);
  param_2[0xd] = fVar4 * *(float *)(&DAT_00687b68 + param_3);
  param_2[0xe] = fVar6 * *(float *)(&DAT_00687b6c + param_3);
  param_2[0xf] = fVar16 * *(float *)(&DAT_00687b70 + param_3);
  param_2[0x10] = fVar3 * *(float *)(&DAT_00687b74 + param_3);
  param_2[0x11] = fVar17 * *(float *)(&DAT_00687b78 + param_3);
  param_2[0x12] = fVar11 * *(float *)(&DAT_00687b7c + param_3);
  param_2[0x13] = fVar5 * *(float *)(&DAT_00687b80 + param_3);
  param_2[0x14] = fVar7 * *(float *)(&DAT_00687b84 + param_3);
  param_2[0x15] = fVar8 * *(float *)(&DAT_00687b88 + param_3);
  param_2[0x16] = fVar2 * *(float *)(&DAT_00687b8c + param_3);
  param_2[0x17] = fVar9 * *(float *)(&DAT_00687b90 + param_3);
  param_2[0x18] = fVar28 * *(float *)(&DAT_00687b94 + param_3);
  param_2[0x19] = fVar26 * *(float *)(&DAT_00687b98 + param_3);
  param_2[0x1a] = fVar24 * *(float *)(&DAT_00687b9c + param_3);
  param_2[0x1b] = fVar24 * *(float *)(&DAT_00687ba0 + param_3);
  param_2[0x1c] = fVar26 * *(float *)(&DAT_00687ba4 + param_3);
  param_2[0x1d] = fVar28 * *(float *)(&DAT_00687ba8 + param_3);
  param_2[0x1e] = fVar9 * *(float *)(&DAT_00687bac + param_3);
  param_2[0x1f] = fVar2 * *(float *)(&DAT_00687bb0 + param_3);
  param_2[0x20] = fVar8 * *(float *)(&DAT_00687bb4 + param_3);
  param_2[0x21] = fVar7 * *(float *)(&DAT_00687bb8 + param_3);
  param_2[0x22] = fVar5 * *(float *)(&DAT_00687bbc + param_3);
  param_2[0x23] = fVar11 * *(float *)(&DAT_00687bc0 + param_3);
  return;
}

