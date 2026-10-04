
undefined4 FUN_004deed2(void)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char *pcVar6;
  int *piVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  void *pvVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  byte *pbVar14;
  int iVar15;
  ushort *puVar16;
  undefined4 extraout_ECX;
  uint uVar17;
  ushort *puVar18;
  ushort *puVar19;
  int unaff_EBP;
  byte *pbVar20;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  
  FUN_00634c24();
  pcVar6 = *(char **)(unaff_EBP + 8);
  cVar9 = *pcVar6;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if ((cVar9 == 'B') && (pcVar6[1] == 'M')) {
    iVar15 = *(int *)(pcVar6 + 0x16);
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    if (iVar15 < 0) {
      *(int *)(unaff_EBP + -0x18) = -iVar15;
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x18) = iVar15;
    }
    if ((*(int *)(unaff_EBP + -0x18) != 0) && (*(int *)(pcVar6 + 0x12) != 0)) {
      uVar10 = *(uint *)(pcVar6 + 0x2e);
      if (uVar10 == 0) {
        uVar10 = 1 << ((char)*(undefined2 *)(pcVar6 + 0x1c) * (char)*(undefined2 *)(pcVar6 + 0x1a) &
                      0x1fU);
      }
      *(uint *)(unaff_EBP + -0x10) = uVar10;
      if (uVar10 < 0x101) {
        *(char **)(unaff_EBP + -0x14) = pcVar6 + 0x36;
      }
      uStack_238 = 100;
      pbVar20 = (byte *)(pcVar6 + *(int *)(pcVar6 + 10));
      uStack_22c = 0x4def5d;
      pvVar11 = operator_new(100);
      *(void **)(unaff_EBP + -0x24) = pvVar11;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar11 == (void *)0x0) {
        puVar12 = (undefined4 *)0x0;
      }
      else {
        puVar12 = (undefined4 *)FUN_005dfb13();
        uStack_238 = extraout_ECX;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 **)(unaff_EBP + -0x20) = puVar12;
      *(undefined4 **)(unaff_EBP + -0x24) = puVar12;
      if (puVar12 != (undefined4 *)0x0) {
        uVar13 = *puVar12;
        uStack_22c = 0;
        uStack_230 = 0;
        *(undefined4 **)(unaff_EBP + -0x1c) = &uStack_238;
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar13;
        uStack_234 = uStack_238;
        FUN_00436a50(4);
        piVar7 = *(int **)(unaff_EBP + -0x20);
        cVar9 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0xc))
                          (*(undefined4 *)(pcVar6 + 0x12),*(undefined4 *)(unaff_EBP + -0x18));
        if (cVar9 != '\0') {
          *(uint *)(unaff_EBP + -0x1c) = (piVar7[2] != 5) + 1;
          iVar15 = *(int *)(unaff_EBP + -0x14);
          if (iVar15 != 0) {
            iVar8 = *(int *)(unaff_EBP + -0x10);
            if (*(int *)(unaff_EBP + -0x1c) == 1) {
              if (iVar8 != 0) {
                pbVar14 = (byte *)(iVar15 + 1);
                *(int *)(unaff_EBP + -0x10) = unaff_EBP + -0x224;
                *(int *)(unaff_EBP + -0x14) = iVar8;
                do {
                  bVar3 = pbVar14[1];
                  bVar4 = *pbVar14;
                  bVar5 = pbVar14[-1];
                  puVar16 = *(ushort **)(unaff_EBP + -0x10);
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 2;
                  pbVar14 = pbVar14 + 4;
                  piVar1 = (int *)(unaff_EBP + -0x14);
                  *piVar1 = *piVar1 + -1;
                  iVar15 = *piVar1;
                  *puVar16 = ((bVar3 & 0xfff8) << 5 | bVar4 & 0xfff8) << 2 | (ushort)(bVar5 >> 3);
                } while (iVar15 != 0);
              }
            }
            else if (iVar8 != 0) {
              pbVar14 = (byte *)(iVar15 + 1);
              *(int *)(unaff_EBP + -0x10) = unaff_EBP + -0x224;
              *(int *)(unaff_EBP + -0x14) = iVar8;
              do {
                bVar3 = pbVar14[1];
                bVar4 = *pbVar14;
                bVar5 = pbVar14[-1];
                puVar16 = *(ushort **)(unaff_EBP + -0x10);
                *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 2;
                pbVar14 = pbVar14 + 4;
                piVar1 = (int *)(unaff_EBP + -0x14);
                *piVar1 = *piVar1 + -1;
                iVar15 = *piVar1;
                *puVar16 = ((ushort)(bVar3 & 0xf8) << 5 | bVar4 & 0xfffc) << 3 |
                           (ushort)(bVar5 >> 3);
              } while (iVar15 != 0);
            }
          }
          cVar9 = (**(code **)(*piVar7 + 0x20))(0x40);
          if (cVar9 == '\0') {
            (**(code **)*piVar7)(1);
            *(undefined4 *)(unaff_EBP + -0x24) = 0;
          }
          else {
            if (*(char *)(unaff_EBP + 0xb) == '\0') {
              uVar10 = (**(code **)(*piVar7 + 0xd0))();
              iVar15 = **(int **)(unaff_EBP + -0x20);
              uVar10 = -(uVar10 >> 1);
              *(uint *)(unaff_EBP + -0x10) = uVar10;
              iVar15 = (**(code **)(iVar15 + 0xcc))();
              puVar16 = (ushort *)(iVar15 + (*(int *)(unaff_EBP + -0x18) + -1) * uVar10 * -2);
            }
            else {
              uVar10 = (**(code **)(*piVar7 + 0xd0))();
              uVar10 = uVar10 >> 1;
              iVar15 = **(int **)(unaff_EBP + -0x20);
              *(uint *)(unaff_EBP + -0x10) = uVar10;
              puVar16 = (ushort *)(**(code **)(iVar15 + 0xcc))();
            }
            iVar15 = *(int *)(pcVar6 + 0x1e);
            puVar18 = puVar16 + uVar10 * *(int *)(unaff_EBP + -0x18);
            *(ushort **)(unaff_EBP + -0x14) = puVar18;
            puVar19 = puVar16;
            if (iVar15 == 1) {
              while( true ) {
                while( true ) {
                  while( true ) {
                    pbVar14 = pbVar20 + 2;
                    *(byte **)(unaff_EBP + -0x18) = pbVar20;
                    if (*pbVar20 == 0) break;
                    uVar17 = (uint)*pbVar20;
                    *(uint *)(unaff_EBP + -0x14) = uVar17;
                    iVar15 = 0;
                    if (uVar17 != 0) {
                      *(uint *)(unaff_EBP + 8) = uVar17;
                      *(ushort **)(unaff_EBP + -0x1c) = puVar19;
                      puVar18 = puVar19;
                      while( true ) {
                        *puVar18 = *(ushort *)(unaff_EBP + -0x224 + (uint)pbVar20[1] * 2);
                        puVar18 = puVar18 + 1;
                        piVar7 = (int *)(unaff_EBP + 8);
                        *piVar7 = *piVar7 + -1;
                        if (*piVar7 == 0) break;
                        pbVar20 = *(byte **)(unaff_EBP + -0x18);
                      }
                      iVar15 = *(int *)(unaff_EBP + -0x14);
                    }
                    puVar19 = puVar19 + iVar15;
                    pbVar20 = pbVar14;
                  }
                  bVar3 = pbVar20[1];
                  *(byte *)(unaff_EBP + 0xb) = bVar3;
                  if (bVar3 != 0) break;
                  puVar16 = puVar16 + uVar10;
                  puVar19 = puVar16;
                  pbVar20 = pbVar14;
                }
                if (bVar3 == 1) break;
                if (bVar3 == 2) {
                  puVar16 = puVar16 + pbVar20[3] * uVar10;
                  puVar19 = puVar19 + (uint)*pbVar14 + pbVar20[3] * uVar10;
                  pbVar20 = pbVar20 + 4;
                }
                else {
                  *(undefined4 *)(unaff_EBP + -0x10) = 0;
                  if (*(char *)(unaff_EBP + 0xb) != '\0') {
                    do {
                      *puVar19 = *(ushort *)(unaff_EBP + -0x224 + (uint)*pbVar14 * 2);
                      bVar3 = pbVar20[1];
                      pbVar20 = *(byte **)(unaff_EBP + -0x18);
                      puVar19 = puVar19 + 1;
                      pbVar14 = pbVar14 + 1;
                      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                    } while (*(int *)(unaff_EBP + -0x10) < (int)(uint)bVar3);
                  }
                  pbVar20 = pbVar14 + (pbVar20[1] & 1);
                }
              }
            }
            else if (*(short *)(pcVar6 + 0x1c) == 8) {
              if (puVar16 != puVar18) {
                do {
                  *(undefined4 *)(unaff_EBP + 8) = 0;
                  puVar18 = puVar16;
                  if (0 < *(int *)(pcVar6 + 0x12)) {
                    do {
                      bVar3 = *pbVar20;
                      pbVar20 = pbVar20 + 1;
                      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                      *puVar18 = *(ushort *)(unaff_EBP + -0x224 + (uint)bVar3 * 2);
                      puVar18 = puVar18 + 1;
                    } while (*(int *)(unaff_EBP + 8) < *(int *)(pcVar6 + 0x12));
                  }
                  puVar16 = puVar16 + uVar10;
                  pbVar20 = pbVar20 + ((*(int *)(pcVar6 + 0x12) + 3U & 0xfffffffc) -
                                      *(int *)(pcVar6 + 0x12));
                } while (puVar16 != *(ushort **)(unaff_EBP + -0x14));
              }
            }
            else if (puVar16 != puVar18) {
              do {
                if (*(int *)(unaff_EBP + -0x1c) == 1) {
                  *(undefined4 *)(unaff_EBP + 8) = 0;
                  puVar18 = puVar16;
                  if (0 < *(int *)(pcVar6 + 0x12)) {
                    do {
                      pbVar14 = pbVar20 + 2;
                      pbVar2 = pbVar20 + 1;
                      bVar3 = *pbVar20;
                      pbVar20 = pbVar20 + 3;
                      *puVar18 = ((*pbVar14 & 0xfff8) << 5 | *pbVar2 & 0xfff8) << 2 |
                                 (ushort)(bVar3 >> 3);
                      puVar18 = puVar18 + 1;
                      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                    } while (*(int *)(unaff_EBP + 8) < *(int *)(pcVar6 + 0x12));
LAB_004df293:
                    uVar10 = *(uint *)(unaff_EBP + -0x10);
                  }
                }
                else {
                  *(undefined4 *)(unaff_EBP + 8) = 0;
                  puVar18 = puVar16;
                  if (0 < *(int *)(pcVar6 + 0x12)) {
                    do {
                      pbVar14 = pbVar20 + 2;
                      pbVar2 = pbVar20 + 1;
                      bVar3 = *pbVar20;
                      pbVar20 = pbVar20 + 3;
                      *puVar18 = ((ushort)(*pbVar14 & 0xf8) << 5 | *pbVar2 & 0xfffc) << 3 |
                                 (ushort)(bVar3 >> 3);
                      puVar18 = puVar18 + 1;
                      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                    } while (*(int *)(unaff_EBP + 8) < *(int *)(pcVar6 + 0x12));
                    goto LAB_004df293;
                  }
                }
                puVar16 = puVar16 + uVar10;
                pbVar20 = pbVar20 + (*(uint *)(pcVar6 + 0x12) & 3);
              } while (puVar16 != *(ushort **)(unaff_EBP + -0x14));
            }
            (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x24))(0x40);
          }
          uVar13 = *(undefined4 *)(unaff_EBP + -0x24);
          goto LAB_004defb6;
        }
        (**(code **)*piVar7)(1);
      }
    }
  }
  uVar13 = 0;
LAB_004defb6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar13;
}

