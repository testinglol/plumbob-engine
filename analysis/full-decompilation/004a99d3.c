
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a99d3(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  float fVar4;
  short sVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined2 extraout_var;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int *extraout_ECX;
  int iVar16;
  int iVar17;
  int unaff_EBP;
  int iVar18;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 0x10) == '\0') {
    iVar8 = (int)*(short *)(unaff_EBP + 0xe);
    iVar9 = extraout_ECX[10];
    *(int *)(unaff_EBP + -0x28) = iVar8;
    if ((iVar9 <= iVar8) && (iVar8 < extraout_ECX[0xc])) {
      iVar8 = (int)*(short *)(unaff_EBP + 0xc);
      iVar9 = extraout_ECX[0xb];
      *(int *)(unaff_EBP + -0x2c) = iVar8;
      if ((iVar9 <= iVar8) &&
         ((iVar8 < extraout_ECX[0xd] &&
          (piVar15 = *(int **)(*(int *)(*(int *)(extraout_ECX[0x1c] + 0x5c) + 0x48) + 4),
          piVar15 != (int *)0x0)))) {
        _memset((void *)(unaff_EBP + -0xd0),0,0x6c);
        iVar9 = *piVar15;
        *(undefined1 *)(unaff_EBP + 0x13) = 0;
        *(undefined4 *)(unaff_EBP + -0xd0) = 0x6c;
        iVar9 = (**(code **)(iVar9 + 100))(piVar15,0,unaff_EBP + -0xd0,1);
        if (iVar9 == 0) {
          *(undefined1 *)(unaff_EBP + 0x13) = 1;
          if (*(int *)(unaff_EBP + -0xac) != 0) {
            uVar2 = *(ushort *)
                     (*(int *)(unaff_EBP + -0xac) +
                     (((uint)(iVar8 * *(int *)(unaff_EBP + -0xc0)) >> 1) +
                     *(int *)(unaff_EBP + -0x28)) * 2);
            if (*(char *)(unaff_EBP + 0x13) != '\0') {
              (**(code **)(*piVar15 + 0x80))(piVar15);
            }
            if (uVar2 != 0xffff) {
              *(uint *)(unaff_EBP + 0x10) = (uint)uVar2;
              *(float *)(unaff_EBP + -0x54) = (float)*(int *)(unaff_EBP + -0x28);
              *(float *)(unaff_EBP + -0x50) = (float)*(int *)(unaff_EBP + -0x2c);
              *(float *)(unaff_EBP + -0x4c) = (float)*(int *)(unaff_EBP + 0x10);
              *(undefined4 *)(unaff_EBP + -0x48) = 0x3f800000;
              pfVar10 = (float *)FUN_005c37a0(unaff_EBP + -100,unaff_EBP + -0x54);
              fVar4 = 1.0 / pfVar10[3];
              *(float *)(unaff_EBP + -0x38) = fVar4 * *pfVar10;
              *(float *)(unaff_EBP + -0x34) = fVar4 * pfVar10[1];
              *(float *)(unaff_EBP + -0x30) = fVar4 * pfVar10[2];
              iVar9 = FUN_004b09c2();
              fVar4 = _DAT_00666578;
              if (iVar9 == 2) {
                iVar8 = *extraout_ECX;
                *(float *)(unaff_EBP + -0x44) = _DAT_00666578;
                *(float *)(unaff_EBP + -0x3c) = fVar4;
                *(undefined4 *)(unaff_EBP + -0x40) = 0;
                iVar8 = (**(code **)(iVar8 + 0x18))();
                *(int *)(unaff_EBP + 0x10) = -iVar8;
                *(float *)(unaff_EBP + 0x10) =
                     (float)*(int *)(unaff_EBP + 0x10) * DAT_00673438 * _DAT_00666578;
                uVar11 = FUN_005c38c0(unaff_EBP + -0x114,1);
                *(undefined4 *)(unaff_EBP + -4) = 0;
                puVar12 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x60,unaff_EBP + -0x44,uVar11);
                uVar11 = *puVar12;
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                *(undefined4 *)(unaff_EBP + -0x44) = uVar11;
                *(undefined4 *)(unaff_EBP + -0x40) = puVar12[1];
                *(undefined4 *)(unaff_EBP + -0x3c) = puVar12[2];
                FUN_005c4890();
                *(float *)(unaff_EBP + -0x38) =
                     *(float *)(unaff_EBP + -0x38) - *(float *)(unaff_EBP + -0x44);
                *(float *)(unaff_EBP + -0x34) =
                     *(float *)(unaff_EBP + -0x34) - *(float *)(unaff_EBP + -0x40);
                *(float *)(unaff_EBP + -0x30) =
                     *(float *)(unaff_EBP + -0x30) - *(float *)(unaff_EBP + -0x3c);
              }
              FUN_00454ff9(unaff_EBP + -0x14);
              if ((iVar9 == extraout_ECX[6]) && (cVar7 = FUN_00422665(), cVar7 == '\0')) {
                FUN_0047bd91(unaff_EBP + -0x10,unaff_EBP + -0x14,
                             *(undefined4 *)(DAT_006e54d8 + 0x84));
                piVar15 = *(int **)(unaff_EBP + 8);
                *piVar15 = *(int *)(unaff_EBP + -0x14);
                iVar9 = *(int *)(unaff_EBP + -0x10);
                goto LAB_004a9e4c;
              }
            }
          }
        }
      }
    }
  }
  iVar9 = extraout_ECX[6];
  uVar11 = *(undefined4 *)(unaff_EBP + 0xc);
  iVar8 = 0x4c - DAT_006f0088;
  *(undefined4 *)(unaff_EBP + -0x28) = uVar11;
  iVar8 = extraout_ECX[iVar8];
  FUN_004a976d(unaff_EBP + -0x20,uVar11);
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x20) << 4;
  iVar16 = DAT_006e54d8;
  iVar18 = *(int *)(unaff_EBP + -0x1c) << 4;
  iVar13 = *(int *)(DAT_006e54d8 + 0x70);
  *(int *)(unaff_EBP + -0x14) = iVar18;
  if (((((int)*(char *)(unaff_EBP + -0x20) < iVar13 + 1) ||
       (*(int *)(iVar16 + 0x74) + -1 < (int)*(char *)(unaff_EBP + -0x20))) ||
      ((int)*(char *)(unaff_EBP + -0x1c) < *(int *)(iVar16 + 0x78) + 1)) ||
     (*(int *)(iVar16 + 0x7c) + -1 < (int)*(char *)(unaff_EBP + -0x1c))) {
    piVar15 = *(int **)(unaff_EBP + 8);
    *piVar15 = iVar18;
  }
  else {
    *(undefined1 **)(unaff_EBP + 0x10) = &stack0xfffffee8;
    FUN_004796d9(unaff_EBP + -0x18);
    FUN_004a9e60(unaff_EBP + 0xc,*(undefined4 *)(unaff_EBP + -0x20),
                 *(undefined4 *)(unaff_EBP + -0x1c),1,DAT_006f0088);
    iVar13 = CONCAT22(extraout_var,(ushort)*(byte *)(unaff_EBP + -0x17));
    iVar16 = DAT_006f0088 + 1;
    *(int *)(unaff_EBP + 0x10) = iVar16;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
    uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
    if (*(short *)(unaff_EBP + -0x26) < *(short *)(unaff_EBP + 0xe)) {
      sVar5 = -(short)extraout_ECX[0x17];
      bVar1 = *(byte *)(unaff_EBP + -0x18);
    }
    else {
      sVar5 = (short)extraout_ECX[0x17];
      bVar1 = *(byte *)(unaff_EBP + -0x16);
    }
    iVar17 = (int)(short)((short)((iVar13 - CONCAT22((short)((uint)uVar3 >> 0x10),(ushort)bVar1)) +
                                  2 << ((byte)*(undefined4 *)(unaff_EBP + 0x10) & 0x1f)) +
                         (short)*(undefined4 *)(unaff_EBP + 0xc));
    *(int *)(unaff_EBP + 0x10) = (int)(short)(*(short *)(unaff_EBP + 0xe) + sVar5);
    *(int *)(unaff_EBP + -0x2c) = (int)*(short *)(unaff_EBP + 0xe);
    *(int *)(unaff_EBP + -0x24) = *(short *)(unaff_EBP + 0xc) - iVar17;
    *(int *)(unaff_EBP + -0x18) = iVar17;
    iVar18 = *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x24) = (int)*(short *)(unaff_EBP + 0xe) - *(int *)(unaff_EBP + 0x10);
    fVar4 = (float)iVar18 / (float)*(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x24) =
         (short)((short)((iVar13 - CONCAT22((short)((uint)iVar16 >> 0x10),
                                            (ushort)*(byte *)(unaff_EBP + -0x15))) + 4 <<
                        ((byte)uVar3 & 0x1f)) + (short)*(undefined4 *)(unaff_EBP + 0xc)) - iVar17;
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x1a) - *(int *)(unaff_EBP + 0x10);
    fVar6 = (float)*(int *)(unaff_EBP + -0x24) / (float)*(int *)(unaff_EBP + -0x1c);
    if (fVar6 == fVar4) {
      *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x26);
      *(float *)(unaff_EBP + -0x18) = (float)*(int *)(unaff_EBP + -0x1c);
    }
    else {
      *(int *)(unaff_EBP + -0x1c) = (int)(short)((short)iVar8 * ((short)iVar9 + -1) + (short)uVar11)
      ;
      iVar9 = *(int *)(unaff_EBP + -0x1c);
      *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(unaff_EBP + -0x26);
      *(float *)(unaff_EBP + -0x24) = (float)*(int *)(unaff_EBP + -0x1c);
      *(float *)(unaff_EBP + -0x18) =
           (*(float *)(unaff_EBP + -0x24) * fVar6 +
           (((float)*(int *)(unaff_EBP + -0x18) - (float)iVar9) -
           (float)*(int *)(unaff_EBP + 0x10) * fVar4)) / (fVar6 - fVar4);
    }
    if (*(short *)(unaff_EBP + -0x26) < *(short *)(unaff_EBP + 0xe)) {
      uVar14 = __ftol();
      *(uint *)(unaff_EBP + -0x14) =
           *(uint *)(unaff_EBP + -0x14) ^ (uVar14 ^ *(uint *)(unaff_EBP + -0x14)) & 0xf;
      uVar14 = __ftol();
    }
    else {
      *(float *)(unaff_EBP + 0xc) = (float)extraout_ECX[0x17];
      uVar14 = __ftol();
      *(uint *)(unaff_EBP + -0x14) =
           *(uint *)(unaff_EBP + -0x14) ^ (uVar14 ^ *(uint *)(unaff_EBP + -0x14)) & 0xf;
      uVar14 = __ftol();
    }
    *(uint *)(unaff_EBP + -0x10) =
         *(uint *)(unaff_EBP + -0x10) ^ (uVar14 ^ *(uint *)(unaff_EBP + -0x10)) & 0xf;
    piVar15 = *(int **)(unaff_EBP + 8);
    *piVar15 = *(int *)(unaff_EBP + -0x14);
  }
  iVar9 = *(int *)(unaff_EBP + -0x10);
LAB_004a9e4c:
  piVar15[1] = iVar9;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

