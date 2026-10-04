
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ba98d(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  void *pvVar13;
  undefined4 *puVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 uStack_b0;
  
  FUN_00634c24();
  iVar16 = DAT_006e486c;
  if (((*(float *)(unaff_EBP + 8) < _DAT_00668830) || (*(float *)(unaff_EBP + 0xc) < _DAT_00668830))
     || ((piVar15 = *(int **)(unaff_EBP + 0x14), piVar15 != (int *)0x0 &&
         ((piVar15[2] <= *piVar15 || (piVar15[3] <= piVar15[1])))))) {
    uVar12 = 0;
    goto LAB_004bb622;
  }
  cVar9 = '\0';
  *(undefined1 *)(unaff_EBP + 0x17) = 0;
  *(undefined1 *)(unaff_EBP + -0x21) = 0;
  iVar16 = *(int *)(iVar16 + 0x34);
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined4 *)(unaff_EBP + -0x84) = 0;
  *(undefined4 *)(unaff_EBP + -0xa4) = 0;
  *(undefined4 *)(unaff_EBP + -0x68) = 0;
  *(undefined4 *)(unaff_EBP + -0x80) = 0;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  if (iVar16 == 1) {
    *(code **)(unaff_EBP + -100) = FUN_004bb631;
    *(code **)(unaff_EBP + -0x50) = FUN_004bb639;
LAB_004baa3a:
    iVar16 = *(int *)(unaff_EBP + 0x10);
    if ((*(byte *)(iVar16 + 0x28) & 2) != 0) {
      uVar12 = *(undefined4 *)(iVar16 + 0x24);
      *(undefined1 *)(unaff_EBP + 0x17) = 1;
      *(undefined4 *)(unaff_EBP + -0x54) = uVar12;
      uVar12 = (**(code **)(unaff_EBP + -100))();
      *(undefined4 *)(unaff_EBP + -0x80) = uVar12;
    }
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
    if (piVar15 == (int *)0x0) {
      iVar19 = *(int *)(iVar16 + 0x20);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar16 + 0x1c);
      *(int *)(unaff_EBP + -0x2c) = iVar19;
    }
    else {
      iVar19 = piVar15[3] - piVar15[1];
      *(int *)(unaff_EBP + -0x14) = piVar15[2] - *piVar15;
      *(int *)(unaff_EBP + -0x74) = *piVar15;
      iVar16 = piVar15[1];
      *(int *)(unaff_EBP + -0x2c) = iVar19;
      *(int *)(unaff_EBP + -0x70) = iVar16;
    }
    *(float *)(unaff_EBP + -0x30) = (float)*(int *)(unaff_EBP + -0x14);
    uStack_b0._4_4_ =
         SUB84((double)((float)*(int *)(unaff_EBP + -0x14) * *(float *)(unaff_EBP + 8)),0);
    uStack_b0._0_4_ = 0x4baa9a;
    FUN_00636ac8();
    uVar12 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x3c) = uVar12;
    *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + -0x2c);
    uStack_b0._4_4_ =
         SUB84((double)((float)*(int *)(unaff_EBP + -0x2c) * *(float *)(unaff_EBP + 0xc)),0);
    uStack_b0._0_4_ = 0x4baad0;
    FUN_00636ac8();
    uVar12 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x28) = uVar12;
    fVar1 = (float)*(int *)(unaff_EBP + -0x3c) / *(float *)(unaff_EBP + -0x30);
    *(float *)(unaff_EBP + -0x20) = fVar1;
    *(float *)(unaff_EBP + -0x48) = (float)*(int *)(unaff_EBP + -0x28) / *(float *)(unaff_EBP + 8);
    if ((fVar1 != _DAT_0066657c) && (*(float *)(unaff_EBP + -0x48) != _DAT_0066657c)) {
      uVar12 = 100;
      uStack_b0._4_4_ = 0x4bab2d;
      pvVar13 = operator_new(100);
      *(void **)(unaff_EBP + 8) = pvVar13;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar13 == (void *)0x0) {
        puVar14 = (undefined4 *)0x0;
      }
      else {
        puVar14 = (undefined4 *)FUN_005dfb13();
        uVar12 = extraout_ECX;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 **)(unaff_EBP + -0x6c) = puVar14;
      *(undefined4 **)(unaff_EBP + -0x68) = puVar14;
      if (puVar14 != (undefined4 *)0x0) {
        uVar2 = *puVar14;
        uStack_b0._4_4_ = 0;
        uStack_b0._0_4_ = 0;
        *(undefined4 **)(unaff_EBP + 8) = &uStack_b8;
        *(undefined4 *)(unaff_EBP + 8) = uVar2;
        uStack_b8 = uVar12;
        uStack_b4 = uVar12;
        FUN_00436a50(4);
        cVar9 = (**(code **)(*(int *)(unaff_EBP + 8) + 0xc))
                          (*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x28));
        if ((cVar9 != '\0') &&
           ((*(char *)(unaff_EBP + 0x18) == '\0' || (cVar9 = FUN_005df761(), cVar9 != '\0')))) {
          uVar12 = 100;
          uStack_b0._4_4_ = 0x4bab9f;
          pvVar13 = operator_new(100);
          *(void **)(unaff_EBP + 8) = pvVar13;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar13 == (void *)0x0) {
            piVar15 = (int *)0x0;
          }
          else {
            piVar15 = (int *)FUN_005dfb13();
            uVar12 = extraout_ECX_00;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(int **)(unaff_EBP + -0xa4) = piVar15;
          if (piVar15 != (int *)0x0) {
            iVar16 = *piVar15;
            uStack_b0._4_4_ = 0;
            uStack_b0._0_4_ = 0;
            *(undefined4 **)(unaff_EBP + 8) = &uStack_b8;
            uStack_b8 = uVar12;
            uStack_b4 = uVar12;
            FUN_00436a50(4);
            iVar17 = *(int *)(unaff_EBP + -0x3c);
            cVar9 = (**(code **)(iVar16 + 0xc))(iVar17,iVar19);
            if ((cVar9 != '\0') &&
               ((*(char *)(unaff_EBP + 0x18) == '\0' || (cVar9 = FUN_005df761(), cVar9 != '\0')))) {
              piVar18 = (int *)(unaff_EBP + -0x28);
              if (*(int *)(unaff_EBP + -0x28) <= iVar17) {
                piVar18 = (int *)(unaff_EBP + -0x3c);
              }
              uStack_b0._4_4_ = 0x4bac21;
              pvVar13 = operator_new(*piVar18 << 3);
              *(void **)(unaff_EBP + -0x4c) = pvVar13;
              if (pvVar13 != (void *)0x0) {
                fVar1 = 1.0;
                if (_DAT_00666748 <= *(float *)(unaff_EBP + -0x20)) {
                  *(undefined4 *)(unaff_EBP + -0x44) = 0x3f800000;
                }
                else {
                  fVar1 = 1.0 / *(float *)(unaff_EBP + -0x20);
                  *(float *)(unaff_EBP + 8) = fVar1;
                  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 8);
                }
                *(float *)(unaff_EBP + -0x10) = 1.0 / fVar1;
                iVar16 = __ftol();
                *(int *)(unaff_EBP + -0x2c) = iVar16;
                piVar18 = (int *)(unaff_EBP + -0x28);
                if (*(int *)(unaff_EBP + -0x28) <= iVar17) {
                  piVar18 = (int *)(unaff_EBP + -0x3c);
                }
                iVar19 = *piVar18;
                uVar12 = __ftol();
                *(undefined4 *)(unaff_EBP + 0xc) = uVar12;
                iVar17 = __ftol();
                *(int *)(unaff_EBP + 8) = iVar17;
                piVar18 = (int *)(unaff_EBP + 8);
                if (iVar17 <= *(int *)(unaff_EBP + 0xc)) {
                  piVar18 = (int *)(unaff_EBP + 0xc);
                }
                uStack_b0._4_4_ = 0x4bacd1;
                pvVar13 = operator_new(*piVar18 * iVar19 * 8);
                *(void **)(unaff_EBP + -0x84) = pvVar13;
                if (pvVar13 != (void *)0x0) {
                  *(undefined4 *)(unaff_EBP + 0xc) = 0;
                  *(void **)(unaff_EBP + -0x18) = pvVar13;
                  if (0 < *(int *)(unaff_EBP + -0x3c)) {
                    piVar18 = *(int **)(unaff_EBP + -0x4c);
                    *(int *)(unaff_EBP + -0x30) = iVar16 << 3;
                    do {
                      iVar19 = *(int *)(unaff_EBP + -0x18);
                      *piVar18 = 0;
                      *(undefined8 *)(unaff_EBP + -0x8c) = 0;
                      iVar16 = *(int *)(unaff_EBP + 0xc);
                      piVar18[1] = iVar19;
                      fVar1 = (float)iVar16 / *(float *)(unaff_EBP + -0x20);
                      *(int *)(unaff_EBP + -0x18) = iVar19 + *(int *)(unaff_EBP + -0x30);
                      *(float *)(unaff_EBP + -0x1c) = fVar1;
                      uStack_b0._4_4_ = SUB84((double)(fVar1 - *(float *)(unaff_EBP + -0x44)),0);
                      uStack_b0._0_4_ = 0x4bad29;
                      FUN_00636ac8();
                      iVar16 = __ftol();
                      uStack_b0._4_4_ =
                           SUB84((double)(*(float *)(unaff_EBP + -0x1c) +
                                         *(float *)(unaff_EBP + -0x44)),0);
                      uStack_b0._0_4_ = 0x4bad5b;
                      FUN_006369f9();
                      iVar19 = __ftol();
                      fVar1 = (float)*(double *)(unaff_EBP + -0x8c);
                      *(int *)(unaff_EBP + 8) = iVar16;
                      fVar8 = _DAT_00666748;
                      if (iVar16 <= iVar19) {
                        do {
                          fVar7 = (*(float *)(unaff_EBP + -0x1c) - (float)*(int *)(unaff_EBP + 8)) *
                                  *(float *)(unaff_EBP + -0x10);
                          if (fVar7 < _DAT_0066657c) {
                            fVar7 = -fVar7;
                          }
                          if (fVar8 <= fVar7) {
                            fVar7 = 0.0;
                          }
                          else {
                            fVar7 = ((fVar7 + fVar7) - _DAT_00666ccc) * fVar7 * fVar7 + fVar8;
                          }
                          fVar7 = fVar7 * *(float *)(unaff_EBP + -0x10);
                          iVar16 = *(int *)(unaff_EBP + 8);
                          fVar1 = fVar7 + fVar1;
                          while( true ) {
                            for (; iVar16 < 0; iVar16 = -iVar16) {
                            }
                            if (iVar16 < *(int *)(unaff_EBP + -0x14)) break;
                            iVar16 = (*(int *)(unaff_EBP + -0x14) * 2 - iVar16) + -2;
                          }
                          iVar17 = *piVar18;
                          *piVar18 = iVar17 + 1;
                          iVar3 = piVar18[1];
                          iVar17 = iVar17 * 8;
                          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                          iVar4 = *(int *)(unaff_EBP + 8);
                          *(int *)(iVar17 + iVar3) = iVar16;
                          *(float *)(iVar17 + 4 + piVar18[1]) = fVar7;
                        } while (iVar4 <= iVar19);
                        if ((float)_DAT_00668828 < fVar1) {
                          fVar1 = 1.0 / fVar1;
                        }
                      }
                      iVar16 = 0;
                      if (0 < *piVar18) {
                        do {
                          iVar19 = iVar16 * 8;
                          iVar17 = iVar16 * 8;
                          iVar16 = iVar16 + 1;
                          *(float *)(piVar18[1] + 4 + iVar17) =
                               *(float *)(piVar18[1] + 4 + iVar19) * fVar1;
                        } while (iVar16 < *piVar18);
                      }
                      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
                      piVar18 = piVar18 + 2;
                    } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + -0x3c));
                  }
                  uStack_b0._4_4_ = 0x4bae5a;
                  cVar9 = (**(code **)(*piVar15 + 0x20))();
                  if (cVar9 != '\0') {
                    uStack_b0._4_4_ = 0x4bae6c;
                    cVar9 = (**(code **)(**(int **)(unaff_EBP + 0x10) + 0x20))();
                    if (cVar9 != '\0') {
                      if (*(char *)(unaff_EBP + 0x18) != '\0') {
                        uStack_b0._4_4_ = 0x4bae84;
                        cVar9 = (**(code **)(*(int *)piVar15[0x18] + 0x20))();
                        if (cVar9 == '\0') goto LAB_004bb61c;
                      }
                      uVar12 = (**(code **)(*piVar15 + 0xcc))();
                      piVar18 = *(int **)(unaff_EBP + 0x10);
                      *(undefined4 *)(unaff_EBP + -0x20) = uVar12;
                      iVar16 = (**(code **)(*piVar18 + 0xcc))();
                      uVar20 = (**(code **)(*piVar18 + 0xd0))();
                      uVar21 = (**(code **)(*piVar15 + 0xd0))();
                      *(uint *)(unaff_EBP + -0x88) = uVar21 >> 1;
                      *(int *)(unaff_EBP + -0xa0) = piVar15[7];
                      *(int *)(unaff_EBP + -0x5c) = piVar15[8];
                      *(undefined4 *)(unaff_EBP + -0x30) = 0;
                      *(undefined4 *)(unaff_EBP + -0x18) = 0;
                      *(undefined4 *)(unaff_EBP + -0x58) = 0;
                      if (*(char *)(unaff_EBP + 0x18) != '\0') {
                        uVar12 = (**(code **)(*(int *)piVar15[0x18] + 0xcc))();
                        piVar18 = (int *)piVar15[0x18];
                        *(undefined4 *)(unaff_EBP + -0x18) = uVar12;
                        uVar12 = (**(code **)(*piVar18 + 0xd0))();
                        *(undefined4 *)(unaff_EBP + -0x58) = uVar12;
                      }
                      *(uint *)(unaff_EBP + -0x70) =
                           iVar16 + (*(int *)(unaff_EBP + -0x70) * (uVar20 >> 1) +
                                    *(int *)(unaff_EBP + -0x74)) * 2;
                      if (0 < *(int *)(unaff_EBP + -0x5c)) {
                        *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x5c);
                        do {
                          *(undefined4 *)(unaff_EBP + 0xc) = 0;
                          if (0 < *(int *)(unaff_EBP + -0xa0)) {
                            *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x20);
                            *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x4c);
                            do {
                              *(undefined4 *)(unaff_EBP + 8) = 0;
                              *(undefined4 *)(unaff_EBP + -0x34) = 0;
                              iVar16 = **(int **)(unaff_EBP + -0x14);
                              *(undefined4 *)(unaff_EBP + -0x38) = 0;
                              *(undefined4 *)(unaff_EBP + -0x40) = 0;
                              *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                              if (0 < iVar16) {
                                do {
                                  uVar21 = (**(code **)(unaff_EBP + -100))();
                                  if ((*(char *)(unaff_EBP + 0x17) == '\0') ||
                                     (uVar21 != *(uint *)(unaff_EBP + -0x80))) {
                                    *(undefined4 *)(unaff_EBP + -0x90) = 0;
                                    *(undefined4 *)(unaff_EBP + -0x98) = 0;
                                    fVar1 = *(float *)(*(int *)(*(int *)(unaff_EBP + -0x14) + 4) + 4
                                                      + *(int *)(unaff_EBP + 8) * 8);
                                    *(uint *)(unaff_EBP + -0x94) = uVar21 >> 0x10 & 0xff;
                                    *(uint *)(unaff_EBP + -0x9c) = uVar21 >> 8 & 0xff;
                                    *(undefined4 *)(unaff_EBP + -0x78) = 0;
                                    *(uint *)(unaff_EBP + -0x7c) = uVar21 & 0xff;
                                    *(float *)(unaff_EBP + -0x34) =
                                         (float)*(longlong *)(unaff_EBP + -0x94) * fVar1 +
                                         *(float *)(unaff_EBP + -0x34);
                                    *(float *)(unaff_EBP + -0x38) =
                                         (float)*(longlong *)(unaff_EBP + -0x9c) * fVar1 +
                                         *(float *)(unaff_EBP + -0x38);
                                    *(float *)(unaff_EBP + -0x40) =
                                         (float)*(longlong *)(unaff_EBP + -0x7c) * fVar1 +
                                         *(float *)(unaff_EBP + -0x40);
                                    *(float *)(unaff_EBP + -0x1c) =
                                         fVar1 + *(float *)(unaff_EBP + -0x1c);
                                  }
                                  *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                                } while (*(int *)(unaff_EBP + 8) < **(int **)(unaff_EBP + -0x14));
                              }
                              iVar16 = *(int *)(unaff_EBP + -0x18);
                              if (iVar16 == 0) {
                                if (_DAT_00668820 <= *(float *)(unaff_EBP + -0x1c)) {
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb0f2;
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb102;
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb109;
                                  uVar11 = (**(code **)(unaff_EBP + -0x50))();
                                }
                                else {
                                  uVar11 = *(undefined2 *)(unaff_EBP + -0x54);
                                }
                                **(undefined2 **)(unaff_EBP + -0x10) = uVar11;
                              }
                              else if (*(float *)(unaff_EBP + -0x1c) == _DAT_0066657c) {
                                **(undefined2 **)(unaff_EBP + -0x10) =
                                     *(undefined2 *)(unaff_EBP + -0x54);
                                *(undefined1 *)(iVar16 + *(int *)(unaff_EBP + 0xc)) = 0;
                              }
                              else {
                                __ftol();
                                uStack_b0._4_4_ = 0x4bb05d;
                                __ftol();
                                uStack_b0._4_4_ = 0x4bb06d;
                                __ftol();
                                uStack_b0._4_4_ = 0x4bb074;
                                uVar11 = (**(code **)(unaff_EBP + -0x50))();
                                fVar1 = *(float *)(unaff_EBP + -0x1c) * _DAT_00667668;
                                bVar6 = _DAT_0066657c <= fVar1;
                                **(undefined2 **)(unaff_EBP + -0x10) = uVar11;
                                if (bVar6) {
                                  if (fVar1 <= _DAT_00667668) {
                                    uVar10 = __ftol();
                                  }
                                  else {
                                    uVar10 = 0xff;
                                  }
                                }
                                else {
                                  uVar10 = 0;
                                }
                                *(undefined1 *)
                                 (*(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + 0xc)) = uVar10;
                              }
                              *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
                              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
                              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 2;
                            } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + -0xa0));
                          }
                          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + (uVar20 >> 1);
                          *(int *)(unaff_EBP + -0x20) =
                               *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x88) * 2;
                          *(int *)(unaff_EBP + -0x18) =
                               *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x58);
                          piVar18 = (int *)(unaff_EBP + -0x60);
                          *piVar18 = *piVar18 + -1;
                        } while (*piVar18 != 0);
                      }
                      uStack_b0._4_4_ = 0x4bb154;
                      (**(code **)(**(int **)(unaff_EBP + 0x10) + 0x24))();
                      fVar1 = 1.0;
                      if (_DAT_00666748 <= *(float *)(unaff_EBP + -0x48)) {
                        *(undefined4 *)(unaff_EBP + -0x44) = 0x3f800000;
                      }
                      else {
                        fVar1 = 1.0 / *(float *)(unaff_EBP + -0x48);
                        *(float *)(unaff_EBP + 0x10) = fVar1;
                        *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0x10);
                      }
                      *(undefined4 *)(unaff_EBP + 0xc) = 0;
                      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x84);
                      *(float *)(unaff_EBP + -0x10) = 1.0 / fVar1;
                      if (0 < *(int *)(unaff_EBP + -0x28)) {
                        piVar18 = *(int **)(unaff_EBP + -0x4c);
                        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x2c) << 3;
                        do {
                          iVar19 = *(int *)(unaff_EBP + -0x18);
                          *piVar18 = 0;
                          *(undefined8 *)(unaff_EBP + -0x7c) = 0;
                          iVar16 = *(int *)(unaff_EBP + 0xc);
                          piVar18[1] = iVar19;
                          fVar1 = (float)iVar16 / *(float *)(unaff_EBP + -0x48);
                          *(int *)(unaff_EBP + -0x18) = iVar19 + *(int *)(unaff_EBP + -0x30);
                          *(float *)(unaff_EBP + -0x1c) = fVar1;
                          uStack_b0 = (double)(fVar1 - *(float *)(unaff_EBP + -0x44));
                          uStack_b4 = 0x4bb1cd;
                          FUN_00636ac8();
                          uStack_b0._4_4_ = 0x4bb1ed;
                          iVar16 = __ftol();
                          uStack_b0 = (double)(*(float *)(unaff_EBP + -0x1c) +
                                              *(float *)(unaff_EBP + -0x44));
                          uStack_b4 = 0x4bb1ff;
                          FUN_006369f9();
                          uStack_b0._4_4_ = 0x4bb21f;
                          iVar19 = __ftol();
                          fVar1 = (float)*(double *)(unaff_EBP + -0x7c);
                          *(int *)(unaff_EBP + 8) = iVar16;
                          fVar8 = _DAT_00666748;
                          if (iVar16 <= iVar19) {
                            do {
                              fVar7 = (*(float *)(unaff_EBP + -0x1c) -
                                      (float)*(int *)(unaff_EBP + 8)) *
                                      *(float *)(unaff_EBP + -0x10);
                              if (fVar7 < _DAT_0066657c) {
                                fVar7 = -fVar7;
                              }
                              if (fVar8 <= fVar7) {
                                fVar7 = 0.0;
                              }
                              else {
                                fVar7 = ((fVar7 + fVar7) - _DAT_00666ccc) * fVar7 * fVar7 + fVar8;
                              }
                              fVar7 = fVar7 * *(float *)(unaff_EBP + -0x10);
                              iVar16 = *(int *)(unaff_EBP + 8);
                              fVar1 = fVar7 + fVar1;
                              while( true ) {
                                for (; iVar16 < 0; iVar16 = -iVar16) {
                                }
                                if (iVar16 < *(int *)(unaff_EBP + -0x5c)) break;
                                iVar16 = (*(int *)(unaff_EBP + -0x5c) * 2 - iVar16) + -2;
                              }
                              iVar17 = *piVar18;
                              *piVar18 = iVar17 + 1;
                              iVar3 = piVar18[1];
                              iVar17 = iVar17 * 8;
                              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                              iVar4 = *(int *)(unaff_EBP + 8);
                              *(int *)(iVar17 + iVar3) = iVar16;
                              *(float *)(iVar17 + 4 + piVar18[1]) = fVar7;
                            } while (iVar4 <= iVar19);
                            if ((float)_DAT_00668828 < fVar1) {
                              fVar1 = 1.0 / fVar1;
                            }
                          }
                          iVar16 = 0;
                          if (0 < *piVar18) {
                            do {
                              iVar19 = iVar16 * 8;
                              iVar17 = iVar16 * 8;
                              iVar16 = iVar16 + 1;
                              *(float *)(piVar18[1] + 4 + iVar17) =
                                   *(float *)(piVar18[1] + 4 + iVar19) * fVar1;
                            } while (iVar16 < *piVar18);
                          }
                          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
                          piVar18 = piVar18 + 2;
                        } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + -0x28));
                      }
                      piVar18 = *(int **)(unaff_EBP + -0x6c);
                      uStack_b0._4_4_ = 0x40;
                      uStack_b0._0_4_ = 0x4bb2fe;
                      cVar9 = (**(code **)(*piVar18 + 0x20))();
                      if (cVar9 != '\0') {
                        if (*(char *)(unaff_EBP + 0x18) != '\0') {
                          uStack_b0._4_4_ = 0x4bb316;
                          (**(code **)(*(int *)piVar18[0x18] + 0x20))();
                        }
                        uVar20 = (**(code **)(*piVar18 + 0xd0))();
                        *(uint *)(unaff_EBP + -0x70) = uVar20 >> 1;
                        uVar12 = (**(code **)(*piVar18 + 0xcc))();
                        *(undefined4 *)(unaff_EBP + -0x2c) = uVar12;
                        uVar12 = (**(code **)(*piVar15 + 0xcc))();
                        *(undefined4 *)(unaff_EBP + -0x14) = 0;
                        *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                        *(undefined4 *)(unaff_EBP + -0x20) = uVar12;
                        if (*(char *)(unaff_EBP + 0x18) != '\0') {
                          uVar12 = (**(code **)(*(int *)piVar18[0x18] + 0xcc))();
                          piVar5 = (int *)piVar18[0x18];
                          *(undefined4 *)(unaff_EBP + -0x14) = uVar12;
                          uVar12 = (**(code **)(*piVar5 + 0xd0))();
                          *(undefined4 *)(unaff_EBP + -0x5c) = uVar12;
                        }
                        if (0 < *(int *)(unaff_EBP + -0x3c)) {
                          *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x3c);
                          do {
                            if (0 < *(int *)(unaff_EBP + -0x28)) {
                              *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x28);
                              *(undefined4 *)(unaff_EBP + -0x18) =
                                   *(undefined4 *)(unaff_EBP + -0x14);
                              *(undefined4 *)(unaff_EBP + -0x10) =
                                   *(undefined4 *)(unaff_EBP + -0x2c);
                              *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x4c);
                              do {
                                *(undefined4 *)(unaff_EBP + 8) = 0;
                                *(undefined4 *)(unaff_EBP + -0x34) = 0;
                                iVar16 = **(int **)(unaff_EBP + 0xc);
                                *(undefined4 *)(unaff_EBP + -0x38) = 0;
                                *(undefined4 *)(unaff_EBP + -0x40) = 0;
                                *(undefined4 *)(unaff_EBP + 0x10) = 0;
                                if (0 < iVar16) {
                                  do {
                                    uVar20 = (**(code **)(unaff_EBP + -100))();
                                    if ((*(char *)(unaff_EBP + 0x17) == '\0') ||
                                       (uVar20 != *(uint *)(unaff_EBP + -0x80))) {
                                      *(undefined4 *)(unaff_EBP + -0x78) = 0;
                                      *(undefined4 *)(unaff_EBP + -0x98) = 0;
                                      fVar1 = *(float *)(*(int *)(*(int *)(unaff_EBP + 0xc) + 4) + 4
                                                        + *(int *)(unaff_EBP + 8) * 8);
                                      *(uint *)(unaff_EBP + -0x7c) = uVar20 >> 0x10 & 0xff;
                                      *(uint *)(unaff_EBP + -0x9c) = uVar20 >> 8 & 0xff;
                                      *(undefined4 *)(unaff_EBP + -0x90) = 0;
                                      *(uint *)(unaff_EBP + -0x94) = uVar20 & 0xff;
                                      *(float *)(unaff_EBP + -0x34) =
                                           (float)*(longlong *)(unaff_EBP + -0x7c) * fVar1 +
                                           *(float *)(unaff_EBP + -0x34);
                                      *(float *)(unaff_EBP + -0x38) =
                                           (float)*(longlong *)(unaff_EBP + -0x9c) * fVar1 +
                                           *(float *)(unaff_EBP + -0x38);
                                      *(float *)(unaff_EBP + -0x40) =
                                           (float)*(longlong *)(unaff_EBP + -0x94) * fVar1 +
                                           *(float *)(unaff_EBP + -0x40);
                                      *(float *)(unaff_EBP + 0x10) =
                                           fVar1 + *(float *)(unaff_EBP + 0x10);
                                    }
                                    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                                  } while (*(int *)(unaff_EBP + 8) < **(int **)(unaff_EBP + 0xc));
                                }
                                if (*(int *)(unaff_EBP + -0x14) == 0) {
                                  if (_DAT_00668820 <= *(float *)(unaff_EBP + 0x10)) {
                                    __ftol();
                                    uStack_b0._4_4_ = 0x4bb550;
                                    __ftol();
                                    uStack_b0._4_4_ = 0x4bb560;
                                    __ftol();
                                    uStack_b0._4_4_ = 0x4bb567;
                                    uVar11 = (**(code **)(unaff_EBP + -0x50))();
                                    **(undefined2 **)(unaff_EBP + -0x10) = uVar11;
                                    goto LAB_004bb56d;
                                  }
                                  **(undefined2 **)(unaff_EBP + -0x10) =
                                       *(undefined2 *)(unaff_EBP + -0x54);
                                }
                                else if (*(float *)(unaff_EBP + 0x10) == _DAT_0066657c) {
                                  **(undefined2 **)(unaff_EBP + -0x10) =
                                       *(undefined2 *)(unaff_EBP + -0x54);
                                  **(undefined1 **)(unaff_EBP + -0x18) = 0;
                                }
                                else {
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb4b9;
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb4c9;
                                  __ftol();
                                  uStack_b0._4_4_ = 0x4bb4d0;
                                  uVar11 = (**(code **)(unaff_EBP + -0x50))();
                                  fVar1 = *(float *)(unaff_EBP + 0x10) * _DAT_00667668;
                                  bVar6 = _DAT_0066657c <= fVar1;
                                  **(undefined2 **)(unaff_EBP + -0x10) = uVar11;
                                  if (bVar6) {
                                    if (fVar1 <= _DAT_00667668) {
                                      uVar10 = __ftol();
                                    }
                                    else {
                                      uVar10 = 0xff;
                                    }
                                  }
                                  else {
                                    uVar10 = 0;
                                  }
                                  **(undefined1 **)(unaff_EBP + -0x18) = uVar10;
LAB_004bb56d:
                                  piVar18 = *(int **)(unaff_EBP + -0x6c);
                                }
                                *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 8;
                                *(int *)(unaff_EBP + -0x10) =
                                     *(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + -0x70) * 2;
                                *(int *)(unaff_EBP + -0x18) =
                                     *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x5c);
                                piVar5 = (int *)(unaff_EBP + -0x60);
                                *piVar5 = *piVar5 + -1;
                              } while (*piVar5 != 0);
                            }
                            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 2;
                            *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 2;
                            if (*(int *)(unaff_EBP + -0x14) != 0) {
                              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                            }
                            piVar5 = (int *)(unaff_EBP + -0x58);
                            *piVar5 = *piVar5 + -1;
                          } while (*piVar5 != 0);
                        }
                        uStack_b0._4_4_ = 0x4bb5b0;
                        (**(code **)(*piVar15 + 0x24))();
                        if (*(char *)(unaff_EBP + 0x18) != '\0') {
                          uStack_b0._4_4_ = 0x40;
                          uStack_b0._0_4_ = 0x4bb5c1;
                          (**(code **)(*(int *)piVar15[0x18] + 0x24))();
                        }
                        uStack_b0._4_4_ = 0x40;
                        uStack_b0._0_4_ = 0x4bb5c9;
                        (**(code **)(*piVar18 + 0x24))();
                        if (*(char *)(unaff_EBP + 0x18) != '\0') {
                          uStack_b0._4_4_ = 0x4bb5da;
                          (**(code **)(*(int *)piVar18[0x18] + 0x24))();
                        }
                        cVar9 = *(char *)(unaff_EBP + -0x21);
                        goto LAB_004bb5dd;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_004bb61c:
    cVar9 = '\x01';
  }
  else if (iVar16 == 2) {
    *(code **)(unaff_EBP + -100) = FUN_004bb662;
    *(undefined1 **)(unaff_EBP + -0x50) = &LAB_004bb66a;
    goto LAB_004baa3a;
  }
LAB_004bb5dd:
  uStack_b0._4_4_ = 0x4bb5e5;
  FUN_006321f0();
  uStack_b0._4_4_ = *(undefined4 *)(unaff_EBP + -0x84);
  uStack_b0._0_4_ = 0x4bb5f0;
  FUN_006321f0();
  if (*(undefined4 **)(unaff_EBP + -0xa4) != (undefined4 *)0x0) {
    uStack_b0._4_4_ = 0x4bb602;
    (**(code **)**(undefined4 **)(unaff_EBP + -0xa4))();
  }
  if (cVar9 != '\0') {
    if (*(undefined4 **)(unaff_EBP + -0x68) != (undefined4 *)0x0) {
      uStack_b0._4_4_ = 0x4bb613;
      (**(code **)**(undefined4 **)(unaff_EBP + -0x68))();
    }
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
  }
  uVar12 = *(undefined4 *)(unaff_EBP + -0x68);
LAB_004bb622:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar12;
}

