
undefined1 FUN_0060b933(void)

{
  char *_Str;
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  void *pvVar4;
  size_t sVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  int *piVar12;
  int extraout_ECX;
  int iVar13;
  char *extraout_ECX_00;
  undefined1 *puVar14;
  int iVar15;
  int *piVar16;
  int unaff_EBP;
  char *pcStack_80;
  char *pcStack_7c;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 8) == '\0') {
    *(undefined1 *)(extraout_ECX + 0x20) = 0;
    if (*(int *)(extraout_ECX + 0x2c) != 0) {
      FUN_005e3581();
      *(undefined4 *)(extraout_ECX + 0x2c) = 0;
    }
    if (*(int *)(extraout_ECX + 0x10) != 0) {
      FUN_006321f0();
      *(undefined4 *)(extraout_ECX + 0x10) = 0;
    }
    uVar3 = 1;
  }
  else {
    *(undefined1 *)(extraout_ECX + 0x20) = 0;
    _Str = (char *)**(undefined4 **)(extraout_ECX + 0x30);
    cVar2 = FUN_004b8157();
    if (cVar2 != '\0') {
      pvVar4 = operator_new(0x1c00);
      *(void **)(unaff_EBP + -0x34) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar4 == (void *)0x0) {
        uVar10 = 0;
      }
      else {
        *(void **)(unaff_EBP + 8) = pvVar4;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0x100;
        do {
          FUN_0060bea5();
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x1c;
          piVar9 = (int *)(unaff_EBP + -0x2c);
          *piVar9 = *piVar9 + -1;
        } while (*piVar9 != 0);
        uVar10 = *(undefined4 *)(unaff_EBP + -0x34);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined1 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(extraout_ECX + 0x10) = uVar10;
      *(undefined4 *)(extraout_ECX + 0x2c) = 0;
      sVar5 = _strlen(_Str);
      do {
        sVar5 = sVar5 - 1;
      } while (_Str[sVar5] != '.');
      *(size_t *)(unaff_EBP + 8) = sVar5;
      sVar5 = _strlen(_Str);
      if (*(int *)(unaff_EBP + 8) != sVar5 - 1) {
        pcStack_7c = (char *)0x60b9e2;
        _strncpy((char *)(unaff_EBP + -0x6c),_Str + *(int *)(unaff_EBP + 8) + 1,0x20);
        iVar6 = FUN_00583594();
        *(int *)(unaff_EBP + -0x34) = iVar6;
        if (iVar6 != 0) {
          iVar6 = FUN_0058316d();
          if (iVar6 != 0) {
            pcStack_7c = (char *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            *(undefined4 *)(unaff_EBP + -0x28) = 0;
            *(undefined4 *)(unaff_EBP + -0x24) = 0;
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            pcStack_80 = (char *)0x60ba25;
            iVar6 = FUN_00583089();
            if (iVar6 != 0) {
              *(undefined4 *)(unaff_EBP + -0x2c) = 0;
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
              if (0 < *(int *)(*(int *)(unaff_EBP + -0x14) + 8)) {
                do {
                  iVar6 = FUN_005830c1();
                  if (iVar6 != 0) {
                    pcStack_80 = (char *)(iVar6 + 0x45c);
                    *(float *)(unaff_EBP + -0x28) =
                         *(float *)(unaff_EBP + -0x28) - (float)*(int *)(iVar6 + 0x448);
                    pcStack_7c = s__x___c___d_006d9e00;
                    FUN_00634d24();
                    iVar13 = *(int *)(unaff_EBP + -0x30) * 0x1c;
                    iVar8 = *(int *)(iVar6 + 0x14);
                    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar6 + 0x10);
                    iVar15 = *(int *)(unaff_EBP + -0x18);
                    puVar7 = (undefined4 *)(*(int *)(extraout_ECX + 0x10) + iVar13);
                    *puVar7 = 0;
                    puVar7[1] = *(undefined4 *)(unaff_EBP + -0x18);
                    puVar7[2] = *(undefined4 *)(unaff_EBP + -0x38);
                    puVar7[3] = iVar8 + iVar15;
                    iVar8 = *(int *)(extraout_ECX + 0x10) + iVar13;
                    iVar15 = *(int *)(iVar8 + 0xc) - *(int *)(iVar8 + 4);
                    *(int *)(unaff_EBP + -0x38) = iVar15;
                    puVar7 = (undefined4 *)(unaff_EBP + -0x38);
                    if (iVar15 <= *(int *)(unaff_EBP + -0x1c)) {
                      puVar7 = (undefined4 *)(unaff_EBP + -0x1c);
                    }
                    iVar15 = *(int *)(iVar6 + 0x448);
                    *(undefined4 *)(unaff_EBP + -0x1c) = *puVar7;
                    iVar1 = *(int *)(iVar6 + 0x44c);
                    *(int *)(iVar8 + 0x10) = -iVar15;
                    *(int *)(iVar8 + 0x14) = -iVar1;
                    *(int *)(*(int *)(extraout_ECX + 0x10) + iVar13 + 0x18) =
                         *(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 0x448);
                    iVar6 = *(int *)(unaff_EBP + -0x2c);
                    if (iVar6 != 0) {
                      piVar9 = (int *)(*(int *)(extraout_ECX + 0x10) + iVar13);
                      if (*(int *)(iVar6 + 4) == piVar9[1]) {
                        iVar6 = *(int *)(iVar6 + 8);
                        *piVar9 = *piVar9 + iVar6;
                        piVar9[2] = piVar9[2] + iVar6;
                      }
                      piVar9 = (int *)(*(int *)(extraout_ECX + 0x10) + iVar13);
                      if (0x400 < piVar9[2]) {
                        iVar6 = *piVar9;
                        *piVar9 = *piVar9 + -iVar6;
                        piVar9[2] = piVar9[2] + -iVar6;
                        iVar6 = *(int *)(unaff_EBP + -0x1c);
                        piVar9[1] = piVar9[1] + iVar6;
                        piVar9[3] = piVar9[3] + iVar6;
                        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar6;
                      }
                    }
                    iVar13 = iVar13 + *(int *)(extraout_ECX + 0x10);
                    iVar6 = *(int *)(iVar13 + 8);
                    *(int *)(unaff_EBP + -0x38) = iVar6;
                    puVar7 = (undefined4 *)(unaff_EBP + -0x38);
                    if (iVar6 <= *(int *)(unaff_EBP + -0x24)) {
                      puVar7 = (undefined4 *)(unaff_EBP + -0x24);
                    }
                    *(undefined4 *)(unaff_EBP + -0x24) = *puVar7;
                    iVar6 = *(int *)(iVar13 + 0xc);
                    *(int *)(unaff_EBP + -0x38) = iVar6;
                    puVar7 = (undefined4 *)(unaff_EBP + -0x38);
                    if (iVar6 <= *(int *)(unaff_EBP + -0x20)) {
                      puVar7 = (undefined4 *)(unaff_EBP + -0x20);
                    }
                    *(undefined4 *)(unaff_EBP + -0x20) = *puVar7;
                    *(int *)(unaff_EBP + -0x2c) = iVar13;
                    FUN_005a9340();
                  }
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                } while (*(int *)(unaff_EBP + -0x10) < *(int *)(*(int *)(unaff_EBP + -0x14) + 8));
              }
              uVar10 = __ftol();
              *(undefined4 *)(extraout_ECX + 0x34) = uVar10;
              pvVar4 = operator_new(100);
              *(void **)(unaff_EBP + 8) = pvVar4;
              *(undefined4 *)(unaff_EBP + -4) = 1;
              if (pvVar4 == (void *)0x0) {
                iVar6 = 0;
              }
              else {
                iVar6 = FUN_005dfb13();
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              *(int *)(extraout_ECX + 0x2c) = iVar6;
              if (iVar6 != 0) {
                FUN_005e357a();
                iVar6 = **(int **)(extraout_ECX + 0x2c);
                *(char ***)(unaff_EBP + 8) = &pcStack_80;
                pcStack_80 = extraout_ECX_00;
                pcStack_7c = extraout_ECX_00;
                FUN_00436a50(3);
                cVar2 = (**(code **)(iVar6 + 0xc))
                                  (*(undefined4 *)(unaff_EBP + -0x24),
                                   *(undefined4 *)(unaff_EBP + -0x20));
                if ((cVar2 != '\0') &&
                   (cVar2 = (**(code **)(**(int **)(extraout_ECX + 0x2c) + 0x20))(), cVar2 != '\0'))
                {
                  uVar10 = (**(code **)(**(int **)(extraout_ECX + 0x2c) + 0xcc))();
                  piVar9 = *(int **)(extraout_ECX + 0x2c);
                  *(undefined4 *)(unaff_EBP + -0x3c) = uVar10;
                  uVar10 = (**(code **)(*piVar9 + 0xd0))();
                  *(undefined4 *)(unaff_EBP + -0x30) = uVar10;
                  *(undefined4 *)(unaff_EBP + -0x10) = 0x40;
                  *(undefined4 *)(unaff_EBP + -0x18) = 0x40;
                  pvVar4 = operator_new(0x1000);
                  *(void **)(unaff_EBP + -0x1c) = pvVar4;
                  *(undefined4 *)(unaff_EBP + -0x24) = 0;
                  if (0 < *(int *)(*(int *)(unaff_EBP + -0x14) + 8)) {
                    do {
                      iVar6 = FUN_005830c1();
                      if (iVar6 != 0) {
                        iVar8 = *(int *)(unaff_EBP + -0x10);
                        piVar9 = (int *)(iVar6 + 0x10);
                        *(undefined4 *)(iVar6 + 0x438) = 8;
                        if ((iVar8 < *piVar9) ||
                           (*(int *)(unaff_EBP + -0x18) < *(int *)(iVar6 + 0x14))) {
                          if (*piVar9 < *(int *)(unaff_EBP + -0x10)) {
                            piVar9 = (int *)(unaff_EBP + -0x10);
                          }
                          *(int *)(unaff_EBP + -0x10) = *piVar9;
                          piVar9 = (int *)(unaff_EBP + -0x18);
                          if (*(int *)(unaff_EBP + -0x18) <= *(int *)(iVar6 + 0x14)) {
                            piVar9 = (int *)(iVar6 + 0x14);
                          }
                          *(int *)(unaff_EBP + -0x18) = *piVar9;
                          FUN_006321f0();
                          pvVar4 = operator_new(*(int *)(unaff_EBP + -0x18) *
                                                *(int *)(unaff_EBP + -0x10));
                          *(void **)(unaff_EBP + -0x1c) = pvVar4;
                        }
                        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x1c);
                        if (*(int *)(unaff_EBP + -0x1c) != 0) {
                          pcStack_80 = (char *)(iVar6 + 0x45c);
                          pcStack_7c = s__x___c___d_006d9e00;
                          FUN_00634d24();
                          pcStack_7c = *(char **)(unaff_EBP + -0x14);
                          pcStack_80 = (char *)0x60bcee;
                          FUN_005830db();
                          *(undefined4 *)(unaff_EBP + -0x2c) = 0;
                          piVar9 = (int *)(*(int *)(unaff_EBP + -0x38) * 0x1c +
                                          *(int *)(extraout_ECX + 0x10));
                          puVar11 = (undefined1 *)
                                    (piVar9[1] * *(int *)(unaff_EBP + -0x30) + *piVar9 +
                                    *(int *)(unaff_EBP + -0x3c));
                          if (0 < *(int *)(iVar6 + 0x14)) {
                            do {
                              *(undefined4 *)(unaff_EBP + -0x28) = 0;
                              if (0 < *(int *)(iVar6 + 0x10)) {
                                iVar8 = *(int *)(unaff_EBP + -0x20) - (int)puVar11;
                                *(int *)(unaff_EBP + -0x40) = iVar8;
                                puVar14 = puVar11;
                                while( true ) {
                                  uVar3 = puVar14[iVar8];
                                  *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
                                  *puVar14 = uVar3;
                                  *(undefined1 **)(unaff_EBP + -0x44) = puVar14 + 1;
                                  if (*(int *)(iVar6 + 0x10) <= *(int *)(unaff_EBP + -0x28)) break;
                                  iVar8 = *(int *)(unaff_EBP + -0x40);
                                  puVar14 = *(undefined1 **)(unaff_EBP + -0x44);
                                }
                              }
                              *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
                              *(int *)(unaff_EBP + -0x20) =
                                   *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x10);
                              puVar11 = puVar11 + *(int *)(unaff_EBP + -0x30);
                            } while (*(int *)(unaff_EBP + -0x2c) < *(int *)(iVar6 + 0x14));
                          }
                        }
                        if (*(int *)(extraout_ECX + 0x38) == 0) {
                          *(int *)(extraout_ECX + 0x38) = iVar6;
                          *(undefined1 *)(extraout_ECX + 0x23) = 1;
                        }
                        else {
                          FUN_005a9340();
                        }
                      }
                      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
                    } while (*(int *)(unaff_EBP + -0x24) < *(int *)(*(int *)(unaff_EBP + -0x14) + 8)
                            );
                  }
                  FUN_006321f0();
                  (**(code **)(**(int **)(extraout_ECX + 0x2c) + 0x24))();
                  piVar9 = (int *)(extraout_ECX + 0x18);
                  iVar6 = 0;
                  *piVar9 = 0;
                  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
                  *(undefined4 *)(unaff_EBP + -0x30) = 0;
                  *(undefined4 *)(unaff_EBP + 8) = 0;
                  do {
                    if (((*(int *)(unaff_EBP + 8) != 0x1180) &&
                        (piVar12 = (int *)(*(int *)(extraout_ECX + 0x10) + *(int *)(unaff_EBP + 8)),
                        *piVar12 < piVar12[2])) && (piVar12[1] < piVar12[3])) {
                      iVar15 = (piVar12[3] - piVar12[1]) + piVar12[5];
                      iVar8 = *piVar9;
                      *(int *)(unaff_EBP + -0x44) = iVar15;
                      piVar16 = (int *)(unaff_EBP + -0x44);
                      if (iVar15 <= iVar8) {
                        piVar16 = piVar9;
                      }
                      *piVar9 = *piVar16;
                      iVar8 = piVar12[5];
                      *(int *)(unaff_EBP + -0x44) = iVar8;
                      piVar16 = (int *)(unaff_EBP + -0x44);
                      if (iVar6 <= iVar8) {
                        piVar16 = (int *)(unaff_EBP + -0x30);
                      }
                      iVar6 = *piVar16;
                      iVar8 = piVar12[2];
                      iVar15 = *piVar12;
                      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
                      *(int *)(unaff_EBP + -0x30) = iVar6;
                      *(int *)(unaff_EBP + -0x44) = iVar8 - iVar15;
                    }
                    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x1c;
                  } while (*(int *)(unaff_EBP + 8) < 0x1be5);
                  if (iVar6 < 0) {
                    *piVar9 = *piVar9 - iVar6;
                    iVar8 = 0;
                    do {
                      piVar9 = (int *)(*(int *)(extraout_ECX + 0x10) + 0x14 + iVar8);
                      *piVar9 = *piVar9 - iVar6;
                      iVar8 = iVar8 + 0x1c;
                    } while (iVar8 < 0x1be4);
                  }
                  uVar10 = __ftol();
                  *(undefined4 *)(*(int *)(extraout_ECX + 0x10) + 0x398) = uVar10;
                  iVar6 = *(int *)(extraout_ECX + 0x10);
                  *(undefined4 *)(iVar6 + 0x380) = 0;
                  *(undefined4 *)(iVar6 + 900) = 0;
                  *(undefined4 *)(iVar6 + 0x388) = 0;
                  *(undefined4 *)(iVar6 + 0x38c) = 0;
                  *(undefined1 *)(extraout_ECX + 0x20) = 1;
                }
              }
              FUN_005830fd();
            }
          }
          FUN_005835ac();
        }
      }
    }
    uVar3 = *(undefined1 *)(extraout_ECX + 0x20);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

