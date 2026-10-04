
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00629120(int param_1,int param_2,char param_3)

{
  int *piVar1;
  double dVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  longlong lVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  double *pdVar14;
  float10 fVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  uint uStack_50;
  
  do {
    iVar11 = *(int *)(*(byte **)(param_1 + 0x21c) + 4);
    if ((iVar11 <= param_2) && ((iVar11 != param_2 || (param_2 == 0xe)))) {
      return;
    }
    bVar3 = **(byte **)(param_1 + 0x21c);
    if (bVar3 < 0x8c) {
      iVar11 = *(int *)(param_1 + 0x218);
      iVar4 = *(int *)(iVar11 + -8);
      iVar5 = *(int *)(iVar11 + -0x20);
      iVar10 = iVar11 + -0x30;
      *(int *)(param_1 + 0x218) = iVar10;
      if (iVar5 < iVar4) {
        *(int *)(iVar11 + -0x20) = iVar4;
      }
      if ((bVar3 == 0x2b) || (bVar3 == 0x8b)) {
        if (*(int *)(iVar11 + -0x28) == 0x7fff) {
          *(int *)(iVar11 + -0x28) = *(int *)(iVar11 + -0x10);
        }
        else if (*(int *)(iVar11 + -0x10) != 0x7fff) {
          uVar13 = *(undefined4 *)(iVar11 + -0xc);
          goto LAB_00629213;
        }
      }
      else if (bVar3 == 0x2d) {
        if (*(int *)(iVar11 + -0x28) == *(int *)(iVar11 + -0x10)) {
LAB_00629223:
          *(undefined4 *)(iVar10 + 8) = 0x7fff;
        }
        else if (*(int *)(iVar11 + -0x10) != 0x7fff) {
          FUN_0061cf50(param_1,*(undefined4 *)(iVar11 + -0xc),0xe);
          *(undefined4 *)(*(int *)(param_1 + 0x218) + 8) = 0x7fff;
        }
      }
      else if ((*(int *)(iVar11 + -0x28) != 0x7fff) || (*(int *)(iVar11 + -0x10) != 0x7fff)) {
        uVar13 = *(undefined4 *)(iVar11 + -0x24);
LAB_00629213:
        FUN_0061cf50(param_1,uVar13);
        iVar10 = *(int *)(param_1 + 0x218);
        goto LAB_00629223;
      }
    }
    else {
      iVar11 = *(int *)(param_1 + 0x218);
      iVar4 = *(int *)(iVar11 + -0x10);
      *(int *)(param_1 + 0x218) = iVar11 + -0x18;
      if (iVar4 != 0x7fff) {
        FUN_0061cf50(param_1,*(undefined4 *)(iVar11 + -0xc),0xe);
        *(undefined4 *)(*(int *)(param_1 + 0x218) + 8) = 0x7fff;
      }
    }
    switch(bVar3) {
    case 0x21:
    case 0x7c:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar16 = __ftol();
      uVar17 = __ftol();
      *pdVar14 = (double)(longlong)(uVar16 | uVar17);
      break;
    default:
      FUN_0061cf50(param_1,*(undefined4 *)(*(int *)(param_1 + 0x218) + 0xc),7);
      break;
    case 0x23:
    case 0x85:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(*pdVar14 != pdVar14[3]);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x25:
      pdVar14 = *(double **)(param_1 + 0x218);
      dVar2 = pdVar14[3];
      if (dVar2 != _DAT_006669e8) {
        fVar15 = (float10)FUN_006369f9();
        *pdVar14 = (double)((float10)*pdVar14 - fVar15 * (float10)ABS(dVar2));
      }
      break;
    case 0x26:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar16 = __ftol();
      uVar17 = __ftol();
      *pdVar14 = (double)(longlong)(uVar16 & uVar17);
      break;
    case 0x2a:
      pdVar14 = *(double **)(param_1 + 0x218);
      *pdVar14 = pdVar14[3] * *pdVar14;
      break;
    case 0x2b:
    case 0x8b:
      pdVar14 = *(double **)(param_1 + 0x218);
      *pdVar14 = pdVar14[3] + *pdVar14;
      break;
    case 0x2c:
      if ((*(int *)(param_1 + 0x102b4) != 0) && (param_3 == '\0')) {
        iVar11 = *(int *)(param_1 + 0x102b4) * 0x90 + -0x90 + *(int *)(param_1 + 0x102b8);
        iVar4 = *(int *)(iVar11 + 8);
        if (iVar4 < 0x10) {
          uVar13 = (*(undefined4 **)(param_1 + 0x218))[1];
          *(undefined4 *)(iVar11 + 0x10 + iVar4 * 8) = **(undefined4 **)(param_1 + 0x218);
          *(undefined4 *)(iVar11 + 0x14 + iVar4 * 8) = uVar13;
          *(int *)(iVar11 + 8) = *(int *)(iVar11 + 8) + 1;
        }
      }
      puVar7 = *(undefined4 **)(param_1 + 0x218);
      *puVar7 = puVar7[6];
      puVar7[1] = puVar7[7];
      break;
    case 0x2d:
      pdVar14 = *(double **)(param_1 + 0x218);
      *pdVar14 = *pdVar14 - pdVar14[3];
      break;
    case 0x2f:
      pdVar14 = *(double **)(param_1 + 0x218);
      if (pdVar14[3] != _DAT_006669e8) {
        *pdVar14 = *pdVar14 / pdVar14[3];
      }
      break;
    case 0x3a:
    case 0x8a:
      puVar6 = *(undefined8 **)(param_1 + 0x218);
      if (*(char *)((int)puVar6 + 0x14) == '\0') {
        *puVar6 = puVar6[3];
      }
      else {
        *puVar6 = *puVar6;
      }
      break;
    case 0x3c:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(*pdVar14 < pdVar14[3]);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x3d:
    case 0x84:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(*pdVar14 == pdVar14[3]);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x3e:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(pdVar14[3] < *pdVar14);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x3f:
    case 0x89:
      pdVar14 = *(double **)(param_1 + 0x218);
      if (*pdVar14 == _DAT_006669e8) {
        *(undefined1 *)((int)pdVar14 + 0x14) = 0;
        *(undefined4 *)pdVar14 = *(undefined4 *)(pdVar14 + 3);
        *(undefined4 *)((int)pdVar14 + 4) = *(undefined4 *)((int)pdVar14 + 0x1c);
      }
      else {
        *(undefined1 *)((int)pdVar14 + 0x14) = 1;
        *(undefined4 *)pdVar14 = *(undefined4 *)(pdVar14 + 3);
        *(undefined4 *)((int)pdVar14 + 4) = *(undefined4 *)((int)pdVar14 + 0x1c);
      }
      break;
    case 0x5e:
    case 0x7e:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar16 = __ftol();
      uVar17 = __ftol();
      *pdVar14 = (double)(longlong)(uVar16 ^ uVar17);
      break;
    case 0x80:
      pdVar14 = *(double **)(param_1 + 0x218);
      __ftol();
      __ftol();
      lVar8 = __allshl();
      *pdVar14 = (double)lVar8;
      break;
    case 0x81:
      pdVar14 = *(double **)(param_1 + 0x218);
      __ftol();
      __ftol();
      lVar8 = __allshr();
      *pdVar14 = (double)lVar8;
      break;
    case 0x82:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(*pdVar14 <= pdVar14[3]);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x83:
      pdVar14 = *(double **)(param_1 + 0x218);
      uStack_50 = (uint)(pdVar14[3] <= *pdVar14);
      *pdVar14 = (double)uStack_50;
      break;
    case 0x86:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 == _DAT_006669e8) || (uStack_50 = 1, pdVar14[3] == _DAT_006669e8)) {
        uStack_50 = 0;
      }
      *pdVar14 = (double)uStack_50;
      break;
    case 0x87:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 != _DAT_006669e8) || (uStack_50 = 0, pdVar14[3] != _DAT_006669e8)) {
        uStack_50 = 1;
      }
      *pdVar14 = (double)uStack_50;
      break;
    case 0x88:
      pdVar14 = *(double **)(param_1 + 0x218);
      if (((*pdVar14 == _DAT_006669e8) &&
          (uStack_50 = (uint)(pdVar14[3] != _DAT_006669e8), (float)uStack_50 == _DAT_0066657c)) ||
         ((*pdVar14 != _DAT_006669e8 && (pdVar14[3] != _DAT_006669e8)))) {
        *pdVar14 = 0.0;
      }
      else {
        *pdVar14 = 1.0;
      }
      break;
    case 0x8c:
      **(double **)(param_1 + 0x218) = -**(double **)(param_1 + 0x218);
      break;
    case 0x8d:
      **(double **)(param_1 + 0x218) = -**(double **)(param_1 + 0x218) - _DAT_00667280;
      break;
    case 0x8e:
      uStack_50 = (uint)(**(double **)(param_1 + 0x218) == _DAT_006669e8);
      **(double **)(param_1 + 0x218) = (double)uStack_50;
      break;
    case 0x8f:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar12 = __ftol();
      *pdVar14 = (double)(uVar12 >> 0x10);
      break;
    case 0x90:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar9 = __ftol();
      *pdVar14 = (double)uVar9;
      break;
    case 0x91:
      pdVar14 = *(double **)(param_1 + 0x218);
      __ftol();
      lVar8 = __allshl();
      *pdVar14 = (double)lVar8;
      break;
    case 0x92:
      pdVar14 = *(double **)(param_1 + 0x218);
      __ftol();
      lVar8 = __allshr();
      *pdVar14 = (double)lVar8;
      break;
    case 0x93:
      **(double **)(param_1 + 0x218) = ABS(**(double **)(param_1 + 0x218));
      break;
    case 0x94:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(*(ushort *)(PTR_DAT_006dac18 + iVar11 * 2) & 0x103);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x95:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 1);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x96:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 2);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x97:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 4);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x98:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 0x80);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x99:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(*(ushort *)(PTR_DAT_006dac18 + iVar11 * 2) & 0x107);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9a:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 8);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9b:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 0x10);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9c:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(PTR_DAT_006dac18[iVar11 * 2] & 0x20);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9d:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(*(ushort *)(PTR_DAT_006dac18 + iVar11 * 2) & 0x157);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9e:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        if (DAT_006dae24 < 2) {
          iVar11 = __ftol();
          *pdVar14 = (double)(*(ushort *)(PTR_DAT_006dac18 + iVar11 * 2) & 0x117);
        }
        else {
          __ftol();
          iVar11 = FUN_0063cdac();
          *pdVar14 = (double)iVar11;
        }
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0x9f:
      pdVar14 = *(double **)(param_1 + 0x218);
      if ((*pdVar14 < _DAT_006669e8) || (_DAT_00677c88 <= *pdVar14)) {
        uVar12 = __ftol();
        *pdVar14 = (double)(uVar12 < 0x80);
      }
      else {
        *pdVar14 = _DAT_006669e8;
      }
      break;
    case 0xa0:
      pdVar14 = *(double **)(param_1 + 0x218);
      iVar11 = __ftol();
      if ((iVar11 < 0x41) || (0x5a < iVar11)) {
LAB_0062989c:
        *pdVar14 = *pdVar14;
      }
      else {
        *pdVar14 = ((double)iVar11 + _DAT_00677c80) - _DAT_00677c78;
      }
      break;
    case 0xa1:
      pdVar14 = *(double **)(param_1 + 0x218);
      iVar11 = __ftol();
      if ((iVar11 < 0x61) || (0x7a < iVar11)) goto LAB_0062989c;
      *pdVar14 = ((double)iVar11 + _DAT_00677c78) - _DAT_00677c80;
      break;
    case 0xa2:
      pdVar14 = *(double **)(param_1 + 0x218);
      uVar12 = __ftol();
      *pdVar14 = (double)(uVar12 & 0x7f);
      break;
    case 0xb4:
      if (*(int *)(param_1 + 0x102b4) == 0) {
        FUN_0061cf50(param_1,*(undefined4 *)(*(int *)(param_1 + 0x218) + 0xc),7);
      }
      else {
        piVar1 = (int *)(*(int *)(param_1 + 0x102b4) * 0x90 + -0x90 + *(int *)(param_1 + 0x102b8));
        iVar11 = piVar1[2];
        if (iVar11 < 0x10) {
          iVar4 = (*(int **)(param_1 + 0x218))[1];
          piVar1[iVar11 * 2 + 4] = **(int **)(param_1 + 0x218);
          piVar1[iVar11 * 2 + 5] = iVar4;
          piVar1[2] = piVar1[2] + 1;
        }
        puVar7 = (undefined4 *)*piVar1;
        iVar11 = puVar7[1];
        if (iVar11 == 0) {
          fVar15 = (float10)(*(code *)*puVar7)(param_1);
LAB_00629f66:
          **(double **)(param_1 + 0x218) = (double)fVar15;
        }
        else {
          if (iVar11 == 1) {
            fVar15 = (float10)(*(code *)*puVar7)();
            goto LAB_00629f66;
          }
          if (iVar11 == 2) {
            fVar15 = (float10)(*(code *)*puVar7)(piVar1[4],piVar1[5],piVar1[6],piVar1[7],piVar1[8],
                                                 piVar1[9],piVar1[10],piVar1[0xb],piVar1[0xc],
                                                 piVar1[0xd],piVar1[0xe],piVar1[0xf],piVar1[0x10],
                                                 piVar1[0x11],piVar1[0x12],piVar1[0x13],piVar1[0x14]
                                                 ,piVar1[0x15],piVar1[0x16],piVar1[0x17],
                                                 piVar1[0x18],piVar1[0x19],piVar1[0x1a],piVar1[0x1b]
                                                 ,piVar1[0x1c],piVar1[0x1d],piVar1[0x1e],
                                                 piVar1[0x1f],piVar1[0x20],piVar1[0x21]);
            goto LAB_00629f66;
          }
        }
        *(int *)(param_1 + 0x102b4) = *(int *)(param_1 + 0x102b4) + -1;
      }
    }
    *(int *)(param_1 + 0x218) = *(int *)(param_1 + 0x218) + 0x18;
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + 8;
  } while( true );
}

