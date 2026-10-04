
undefined4 FUN_004df2ca(void)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  void *pvVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  undefined4 extraout_ECX;
  int iVar14;
  int unaff_EBP;
  byte *pbVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int *piStack_30;
  uint uStack_2c;
  
  FUN_00634c24();
  pcVar2 = *(char **)(unaff_EBP + 8);
  if ((*pcVar2 == 'B') && (pcVar2[1] == 'M')) {
    iVar6 = *(int *)(pcVar2 + 0x16);
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    if (iVar6 < 0) {
      *(int *)(unaff_EBP + -0x18) = -iVar6;
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x18) = iVar6;
    }
    if ((*(int *)(unaff_EBP + -0x18) != 0) && (*(int *)(pcVar2 + 0x12) != 0)) {
      iVar6 = *(int *)(pcVar2 + 0x2e);
      if (iVar6 == 0) {
        iVar6 = 1 << ((char)*(undefined2 *)(pcVar2 + 0x1c) * (char)*(undefined2 *)(pcVar2 + 0x1a) &
                     0x1fU);
      }
      *(int *)(unaff_EBP + -0x1c) = iVar6;
      *(char **)(unaff_EBP + -0x10) = pcVar2 + *(int *)(pcVar2 + 10);
      uStack_2c = 0x4df33e;
      piVar7 = operator_new(0x14);
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7[1] = 0;
        piVar7[2] = 0;
        piVar7[3] = 0;
        piVar7[4] = 0;
        *piVar7 = (int)&PTR_FUN_006693b4;
      }
      if (piVar7 != (int *)0x0) {
        cVar5 = (**(code **)(*piVar7 + 4))();
        puVar8 = (undefined4 *)*piVar7;
        if (cVar5 != '\0') {
          uStack_2c = *(undefined4 *)(unaff_EBP + -0x1c);
          piStack_30 = (int *)0x4df38d;
          cVar5 = (*(code *)puVar8[8])();
          if (cVar5 == '\0') {
            puVar8 = (undefined4 *)*piVar7;
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            if (*(int *)(unaff_EBP + -0x1c) != 0) {
              pcVar17 = pcVar2 + 0x37;
              do {
                *(uint *)(unaff_EBP + -0x24) = (uint)CONCAT21(*(undefined2 *)pcVar17,pcVar17[-1]);
                uStack_2c = *(undefined4 *)(unaff_EBP + -0x14);
                piStack_30 = (int *)0x4df3c1;
                (**(code **)(*piVar7 + 0x18))();
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                pcVar17 = pcVar17 + 4;
              } while (*(uint *)(unaff_EBP + -0x14) < *(uint *)(unaff_EBP + -0x1c));
            }
            piVar11 = (int *)0x0;
            uStack_38 = 100;
            uStack_2c = 0x4df3d8;
            pvVar10 = operator_new(100);
            *(void **)(unaff_EBP + -0x20) = pvVar10;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            if (pvVar10 != (void *)0x0) {
              piVar11 = (int *)FUN_005dfb13();
              uStack_38 = extraout_ECX;
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(int **)(unaff_EBP + -0x20) = piVar11;
            if (piVar11 == (int *)0x0) goto LAB_004df372;
            iVar6 = *piVar11;
            uStack_2c = 0;
            *(undefined4 **)(unaff_EBP + -0x1c) = &uStack_38;
            *(int *)(unaff_EBP + -0x1c) = iVar6;
            uStack_34 = uStack_38;
            piStack_30 = piVar7;
            FUN_00436a50(3);
            cVar5 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0xc))
                              (*(undefined4 *)(pcVar2 + 0x12),*(undefined4 *)(unaff_EBP + -0x18));
            puVar8 = (undefined4 *)*piVar11;
            if (cVar5 != '\0') {
              uStack_2c = 0x4df437;
              cVar5 = (*(code *)puVar8[8])();
              if (cVar5 == '\0') {
                uStack_2c = 1;
                piStack_30 = (int *)0x4df56d;
                (**(code **)*piVar11)();
                *(undefined4 *)(unaff_EBP + -0x20) = 0;
              }
              else {
                if (*(char *)(unaff_EBP + 0xb) == '\0') {
                  uStack_2c = 0x4df44f;
                  iVar6 = (**(code **)(*piVar11 + 0xd0))();
                  *(int *)(unaff_EBP + -0x14) = -iVar6;
                  uStack_2c = 0x4df45e;
                  iVar6 = (**(code **)(*piVar11 + 0xcc))();
                  iVar6 = iVar6 - (*(int *)(unaff_EBP + -0x18) + -1) * *(int *)(unaff_EBP + -0x14);
                }
                else {
                  uStack_2c = 0x4df472;
                  uVar12 = (**(code **)(*piVar11 + 0xd0))();
                  *(uint *)(unaff_EBP + -0x14) = uVar12 >> 1;
                  uStack_2c = 0x4df481;
                  iVar6 = (**(code **)(*piVar11 + 0xcc))();
                }
                iVar13 = *(int *)(unaff_EBP + -0x14) * *(int *)(unaff_EBP + -0x18) + iVar6;
                if (*(int *)(pcVar2 + 0x1e) == 1) {
                  *(int *)(unaff_EBP + 8) = iVar6;
                  pbVar15 = *(byte **)(unaff_EBP + -0x10);
                  while( true ) {
                    while( true ) {
                      while( true ) {
                        pbVar16 = pbVar15 + 2;
                        if (*pbVar15 == 0) break;
                        piStack_30 = (int *)(uint)pbVar15[1];
                        uStack_2c = (uint)*pbVar15;
                        uStack_34 = *(undefined4 *)(unaff_EBP + 8);
                        *(uint *)(unaff_EBP + -0x1c) = uStack_2c;
                        uStack_38 = 0x4df516;
                        FUN_005a9250();
                        *(int *)(unaff_EBP + 8) =
                             *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + -0x1c);
                        pbVar15 = pbVar16;
                      }
                      bVar1 = pbVar15[1];
                      if (bVar1 != 0) break;
                      iVar6 = iVar6 + *(int *)(unaff_EBP + -0x14);
                      *(int *)(unaff_EBP + 8) = iVar6;
                      pbVar15 = pbVar16;
                    }
                    if (bVar1 == 1) break;
                    if (bVar1 == 2) {
                      iVar13 = (uint)pbVar15[3] * *(int *)(unaff_EBP + -0x14);
                      iVar6 = iVar6 + iVar13;
                      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + (uint)*pbVar16 + iVar13;
                      pbVar15 = pbVar15 + 4;
                    }
                    else {
                      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                      if (bVar1 != 0) {
                        do {
                          pbVar3 = *(byte **)(unaff_EBP + 8);
                          bVar1 = *pbVar16;
                          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
                          pbVar16 = pbVar16 + 1;
                          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                          *pbVar3 = bVar1;
                        } while (*(int *)(unaff_EBP + -0x1c) < (int)(uint)pbVar15[1]);
                      }
                      pbVar15 = pbVar16 + (pbVar15[1] & 1);
                    }
                  }
                }
                else if (*(short *)(pcVar2 + 0x1c) == 8) {
                  for (; iVar6 != iVar13; iVar6 = iVar6 + *(int *)(unaff_EBP + -0x14)) {
                    iVar14 = 0;
                    if (0 < *(int *)(pcVar2 + 0x12)) {
                      do {
                        puVar4 = *(undefined1 **)(unaff_EBP + -0x10);
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                        *(undefined1 *)(iVar14 + iVar6) = *puVar4;
                        iVar14 = iVar14 + 1;
                      } while (iVar14 < *(int *)(pcVar2 + 0x12));
                    }
                    *(int *)(unaff_EBP + -0x10) =
                         *(int *)(unaff_EBP + -0x10) +
                         ((*(int *)(pcVar2 + 0x12) + 3U & 0xfffffffc) - *(int *)(pcVar2 + 0x12));
                  }
                }
                uStack_2c = 0x40;
                piStack_30 = (int *)0x4df563;
                (**(code **)(*piVar11 + 0x24))();
              }
              uVar9 = *(undefined4 *)(unaff_EBP + -0x20);
              goto LAB_004df374;
            }
          }
        }
        uStack_2c = 0x4df372;
        (*(code *)*puVar8)();
      }
    }
  }
LAB_004df372:
  uVar9 = 0;
LAB_004df374:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

