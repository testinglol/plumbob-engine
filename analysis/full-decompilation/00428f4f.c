
int FUN_00428f4f(void)

{
  short *psVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  void *pvVar13;
  undefined4 extraout_ECX;
  int *piVar14;
  uint uVar15;
  int unaff_EBP;
  int *piVar16;
  undefined4 uVar17;
  short sVar18;
  undefined **ppuVar19;
  undefined *puVar20;
  
  FUN_00634c24();
  piVar10 = *(int **)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  **(undefined4 **)(unaff_EBP + 0xc) = 0;
  *piVar10 = 0;
  FUN_00418fea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar6 = FUN_004190d3(*(undefined4 *)(unaff_EBP + 8),1);
  if (iVar6 == 0) {
    uVar2 = *(undefined1 *)(DAT_006e486c + 100);
    *(undefined2 *)(unaff_EBP + -0x9e) = 0;
    *(undefined1 *)(unaff_EBP + -0xa0) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x9c) = 0;
    *(undefined4 *)(unaff_EBP + -0x98) = 0;
    *(undefined4 *)(unaff_EBP + -0x94) = 0;
    *(undefined4 *)(unaff_EBP + -0x90) = 0;
    iVar6 = FUN_0042fe40(unaff_EBP + -0xa0,unaff_EBP + -0x8c,0x45585069,0,0);
    if (iVar6 == 0) {
      FUN_004100cf(0,0xffffffff);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      cVar5 = FUN_00410398(unaff_EBP + -0x8c,(int)*(short *)(unaff_EBP + -0x9e));
      if (cVar5 == '\0') {
        iVar6 = -1;
      }
      else {
        FUN_004706f0();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_0047034e(unaff_EBP + -0x8c,1000,0x43545353,0,0xffffffff);
        iVar6 = FUN_00470d9f(1,0);
        if (iVar6 == 0) {
          uVar7 = FUN_00471509(1,0xffffffff);
          FUN_004108d0(uVar7);
        }
        FUN_0055e4e2(unaff_EBP + -0x39);
        *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x60;
        *(undefined4 *)(unaff_EBP + -0x20) = 0x4e425253;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        iVar6 = FUN_00430654(unaff_EBP + -0x24,unaff_EBP + -0x8c,0x4e425253,1,0);
        if (iVar6 == 0) {
          *(undefined4 *)(unaff_EBP + -0x38) = 0;
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x38;
          *(undefined4 *)(unaff_EBP + -0x20) = 0x46494e56;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_00430876(unaff_EBP + -0x24,unaff_EBP + -0x8c,0x46494e56,2,0);
          *(undefined1 *)(unaff_EBP + 0x13) = 0;
          FUN_0046cee2();
          uVar7 = s_IMISSUOH_006c1ef4._0_4_;
          *(undefined2 *)(unaff_EBP + -0x2c) = DAT_006c1ef0;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_004302bd(unaff_EBP + -0x6f4,uVar7);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          iVar6 = FUN_00464f5b(unaff_EBP + -0x54,unaff_EBP + -0x8c,
                               *(undefined4 *)(unaff_EBP + -0x2c),0);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_00465055();
          if (iVar6 == 0) {
            *(bool *)(unaff_EBP + 0x13) = *(short *)(unaff_EBP + -0x6b0) != 0;
          }
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_0046d08e();
          iVar6 = FUN_00425e34();
          piVar16 = *(int **)(unaff_EBP + 0xc);
          *(int *)(unaff_EBP + -0x14) = iVar6;
          *piVar16 = iVar6;
          piVar14 = *(int **)(*(int *)(unaff_EBP + -0x10) + 0x154);
          piVar4 = *(int **)(*(int *)(unaff_EBP + -0x10) + 0x158);
          *(int **)(unaff_EBP + -0x2c) = piVar4;
          if (piVar14 != piVar4) {
            do {
              if (*(int *)(*piVar14 + 0x10c) == *(int *)(unaff_EBP + -0x32c)) {
                iVar6 = *piVar14;
                goto LAB_0042919d;
              }
              piVar14 = piVar14 + 1;
            } while (piVar14 != *(int **)(unaff_EBP + -0x2c));
          }
          iVar6 = 0;
LAB_0042919d:
          if (iVar6 == 0) {
            *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10c) = *(int *)(unaff_EBP + -0x32c);
          }
          if (*piVar16 == 0) {
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0048c4c9();
            *(undefined1 *)(unaff_EBP + -4) = 2;
            iVar6 = -1;
          }
          else {
            FUN_0046f824(unaff_EBP + -0x7f4,0,0x100);
            *(undefined ***)(unaff_EBP + -0x800) = &PTR_FUN_00666524;
            FUN_004102d4(unaff_EBP + -0x800);
            FUN_004108c4(unaff_EBP + -0x800);
            *(undefined4 *)(*piVar16 + 0x118) = *(undefined4 *)(unaff_EBP + -800);
            *(undefined4 *)(*piVar16 + 0x11c) = *(undefined4 *)(unaff_EBP + -0x31c);
            *(undefined4 *)(*piVar16 + 0x140) = *(undefined4 *)(unaff_EBP + -0x2f8);
            *(undefined4 *)(unaff_EBP + -0x2f8) = 0;
            *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x328);
            iVar6 = FUN_00425ddf(*(undefined4 *)(unaff_EBP + -0x328));
            *piVar10 = iVar6;
            if (iVar6 == 0) {
LAB_0042927f:
              if (*(int *)(unaff_EBP + -0x18) != 0) {
                iVar6 = *(int *)(unaff_EBP + -0x10);
                for (piVar10 = *(int **)(iVar6 + 0x148); piVar10 != *(int **)(iVar6 + 0x14c);
                    piVar10 = piVar10 + 1) {
                  iVar8 = *piVar10;
                  if ((iVar8 != 0) && ((int)*(short *)(iVar8 + 0xfa) == *(int *)(unaff_EBP + -0x18))
                     ) {
                    FUN_00427017(iVar8);
                    iVar6 = *(int *)(unaff_EBP + -0x10);
                  }
                }
              }
            }
            else if (*(int *)(unaff_EBP + -0x18) != 0) {
              *(undefined4 *)(iVar6 + 0x110) = 0;
              uVar7 = FUN_00410304();
              *(undefined4 *)(*piVar10 + 0x118) = uVar7;
              *(undefined4 *)(*piVar10 + 0x11c) = 0;
              *(uint *)(*piVar10 + 0x138) = *(uint *)(*piVar10 + 0x138) & 0xfffffff7;
              goto LAB_0042927f;
            }
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            do {
              psVar1 = (short *)(unaff_EBP + -0x9c + *(int *)(unaff_EBP + -0x14) * 2);
              *(short **)(unaff_EBP + -0x20) = psVar1;
              sVar18 = *psVar1;
              *(uint *)(unaff_EBP + -0x2c) =
                   CONCAT22((short)((uint)*(int *)(unaff_EBP + -0x14) >> 0x10),sVar18);
              if (sVar18 == 0) break;
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0x134) = &PTR_FUN_0066643c;
              *(undefined1 *)(unaff_EBP + -4) = 7;
              FUN_0047034e(unaff_EBP + -0x8c,*(undefined4 *)(unaff_EBP + -0x2c),0x75436872,0,
                           0xffffffff);
              FUN_0046ffa4(1,1);
              ppuVar19 = &PTR_PTR_006c0fa4;
              uVar7 = FUN_004705f2(0xd,0xffffffff);
              iVar6 = FUN_006363c0(uVar7,ppuVar19);
              if (iVar6 == 0) {
                puVar20 = &DAT_006c0fa8;
                uVar7 = FUN_004705f2(0xd,0xffffffff);
                iVar6 = FUN_006363c0(uVar7,puVar20);
                if (iVar6 == 0) {
                  sVar18 = *psVar1;
                  uVar7 = 0;
                }
                else {
                  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) goto LAB_00429377;
                  sVar18 = *psVar1;
                  uVar7 = 2;
                }
LAB_004293a3:
                iVar6 = FUN_0042612b(unaff_EBP + -0x1c,uVar7,sVar18);
                if (iVar6 != 0) {
                  *(undefined1 *)(unaff_EBP + -4) = 4;
                  FUN_00470467();
                  *(undefined1 *)(unaff_EBP + -4) = 3;
                  FUN_0048c4c9();
                  *(undefined1 *)(unaff_EBP + -4) = 2;
                  FUN_0048c4c9();
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  FUN_004712d0();
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  FUN_00410173();
                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                  FUN_0041905d();
                  goto LAB_00429bdf;
                }
                uVar15 = *(uint *)(unaff_EBP + -0x14);
                *(undefined2 *)(unaff_EBP + -200 + uVar15 * 2) =
                     **(undefined2 **)(unaff_EBP + -0x1c);
                uVar7 = FUN_00401f73();
                FUN_004108dc(uVar7);
                if (uVar15 < (uint)(*(int *)(unaff_EBP + -0x34) - *(int *)(unaff_EBP + -0x38) >> 2))
                {
                  FUN_0042a970(CONCAT22((short)((uint)*(undefined2 **)(unaff_EBP + -0x1c) >> 0x10),
                                        **(undefined2 **)(unaff_EBP + -0x1c)),
                               *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + uVar15 * 4));
                }
                puVar11 = *(undefined4 **)(*(int *)(unaff_EBP + -0x1c) + 8);
                piVar10 = (int *)*puVar11;
                (**(code **)(*piVar10 + 0x10))();
                (**(code **)(*piVar10 + 0x14))();
                FUN_0046fca5();
                *(undefined ***)(unaff_EBP + -0x264) = &PTR_FUN_0066643c;
                iVar6 = 1;
                *(undefined1 *)(unaff_EBP + -4) = 8;
                iVar8 = FUN_0046fbe5(0xffffffff);
                if (0 < iVar8) {
                  do {
                    iVar8 = FUN_004706c3(iVar6,0);
                    if (iVar8 == 0) break;
                    FUN_004704a5(iVar6,iVar8,0);
                    iVar6 = iVar6 + 1;
                    iVar8 = FUN_0046fbe5(0xffffffff);
                  } while (iVar6 <= iVar8);
                }
                FUN_0047034e(piVar10,200,0x53545223,0,0);
                FUN_0046fd72();
                puVar9 = (undefined4 *)FUN_00457ea7();
                FUN_004706f0();
                sVar18 = **(short **)(unaff_EBP + -0x20);
                *(undefined1 *)(unaff_EBP + -4) = 9;
                FUN_0047034e(unaff_EBP + -0x8c,
                             CONCAT22((short)((uint)*(short **)(unaff_EBP + -0x20) >> 0x10),
                                      sVar18 + 2000),0x43545353,0,0xffffffff);
                iVar6 = FUN_00470d9f(1,0);
                if (iVar6 == 0) {
                  uVar7 = FUN_00471509(1,0xffffffff);
                  FUN_005b870f(uVar7);
                  *(undefined1 *)(unaff_EBP + -4) = 10;
                  FUN_005d499c(unaff_EBP + -0x54);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                  uVar7 = FUN_00471509(2,0xffffffff);
                  FUN_005b870f(uVar7);
                  *(undefined1 *)(unaff_EBP + -4) = 0xb;
                  FUN_005d499c(unaff_EBP + -0x48);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                  FUN_004063b5(piVar10,CONCAT22((short)((uint)puVar11[0x18] >> 0x10),
                                                *(undefined2 *)(puVar11[0x18] + 0x52)));
                }
                else {
                  FUN_005b8680();
                  *(undefined1 *)(unaff_EBP + -4) = 0xc;
                  FUN_005b8680();
                  *(undefined1 *)(unaff_EBP + -4) = 0xd;
                  FUN_0040622a(unaff_EBP + -0x8c,*(undefined4 *)(unaff_EBP + -0x2c),1);
                  FUN_005d499c(unaff_EBP + -0xb8);
                  FUN_005d499c(unaff_EBP + -0xac);
                  FUN_004063b5(piVar10,CONCAT22((short)((uint)puVar11[0x18] >> 0x10),
                                                *(undefined2 *)(puVar11[0x18] + 0x52)));
                  *(undefined1 *)(unaff_EBP + -4) = 0xe;
                  FUN_005b8770();
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                FUN_0046f824(unaff_EBP + -0x174,0,0x40);
                *(undefined ***)(unaff_EBP + -0x180) = &PTR_FUN_0066651c;
                FUN_00457f7a(unaff_EBP + -0x180);
                FUN_0046f847(&DAT_006c2814,0xffffffff);
                FUN_0046f847(*puVar9,0xffffffff);
                FUN_00457422(*(undefined4 *)(unaff_EBP + -0x17c));
                FUN_004580cc(1);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                FUN_004712d0();
                *(undefined1 *)(unaff_EBP + -4) = 7;
                FUN_00470467();
                *(undefined1 *)(unaff_EBP + -4) = 4;
                FUN_00470467();
                piVar16 = *(int **)(unaff_EBP + 0xc);
              }
              else {
                if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
                  sVar18 = *psVar1;
                  uVar7 = 1;
                  goto LAB_004293a3;
                }
LAB_00429377:
                FUN_00426068(*(undefined4 *)(unaff_EBP + -0x1c));
                *(undefined1 *)(unaff_EBP + -4) = 4;
                FUN_00470467();
              }
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            } while (*(int *)(unaff_EBP + -0x14) < 8);
            iVar6 = 0;
            *(undefined4 *)(unaff_EBP + -0x48) = 0;
            *(undefined4 *)(unaff_EBP + -0x44) = 0;
            *(undefined4 *)(unaff_EBP + -0x40) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            FUN_00415784(unaff_EBP + -0x8c);
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            do {
              sVar18 = *(short *)(unaff_EBP + -0x9c + *(int *)(unaff_EBP + -0x14));
              if (sVar18 == 0) break;
              if (0 < sVar18) {
                if (((uint)(int)sVar18 <=
                     (uint)(*(int *)(unaff_EBP + -0x5c) - *(int *)(unaff_EBP + -0x60) >> 2)) &&
                   (iVar8 = *(int *)(*(int *)(unaff_EBP + -0x60) + -4 + sVar18 * 4),
                   *(int *)(unaff_EBP + -0x1c) = iVar8, iVar8 != 0)) {
                  uVar15 = (uint)*(short *)(unaff_EBP + -200 + *(int *)(unaff_EBP + -0x14));
                  if (((int)uVar15 < 1) ||
                     (piVar10 = (int *)(*(int *)(unaff_EBP + -0x10) + 0x148),
                     (uint)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x14c) - *piVar10 >> 2) < uVar15)
                     ) {
                    iVar8 = 0;
                  }
                  else {
                    iVar8 = *(int *)(*piVar10 + -4 + uVar15 * 4);
                  }
                  if (iVar8 != 0) {
                    uVar7 = FUN_00401f73();
                    *(undefined4 *)(unaff_EBP + 0xc) = uVar7;
                    uVar7 = FUN_00401f73();
                    *(undefined1 *)(unaff_EBP + -0x4c) = 0;
                    *(undefined4 *)(unaff_EBP + -0x54) = uVar7;
                    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + 0xc);
                    FUN_0042ec91(unaff_EBP + -0x54);
                    *(undefined4 *)(unaff_EBP + 0xc) = 0;
                    do {
                      sVar18 = *(short *)(unaff_EBP + -0x9c + *(int *)(unaff_EBP + 0xc));
                      if (sVar18 == 0) break;
                      FUN_00429c3b(*(int *)(unaff_EBP + -0x1c) + 0xc,(int)sVar18,iVar8 + 0xc,
                                   (int)*(short *)(unaff_EBP + -200 + *(int *)(unaff_EBP + 0xc)));
                      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 2;
                    } while (*(int *)(unaff_EBP + 0xc) < 0x10);
                    uVar7 = *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 0x18);
                    *(undefined4 *)(unaff_EBP + 0xc) = uVar7;
                    *(undefined4 *)(iVar8 + 0x18) = uVar7;
                    puVar11 = (undefined4 *)FUN_0042385a(uVar7);
                    *(undefined4 **)(unaff_EBP + -0x20) = puVar11;
                    for (piVar10 = (int *)*puVar11; piVar10 != (int *)puVar11[1];
                        piVar10 = piVar10 + 2) {
                      if (piVar10[1] <= *(int *)(unaff_EBP + 0xc)) {
                        iVar12 = *piVar10 * 2 + 0x74;
                        *(undefined2 *)(iVar12 + iVar8) =
                             *(undefined2 *)(iVar12 + *(int *)(unaff_EBP + -0x1c));
                        puVar11 = *(undefined4 **)(unaff_EBP + -0x20);
                      }
                    }
                  }
                }
              }
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 2;
            } while (*(int *)(unaff_EBP + -0x14) < 0x10);
            iVar8 = *(int *)(unaff_EBP + -0x10);
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              iVar12 = FUN_004157ac(unaff_EBP + -0x8c);
              *(int *)(unaff_EBP + 0xc) = iVar12;
              if (iVar12 != 0) {
                *(undefined1 *)(unaff_EBP + -4) = 4;
                FUN_004d6053();
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_0048c4c9();
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_0048c4c9();
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_004712d0();
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_00410173();
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0041905d();
                iVar6 = *(int *)(unaff_EBP + 0xc);
                goto LAB_00429bdf;
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_004d6053();
            FUN_00427c21(*piVar16);
            FUN_0042528e();
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              iVar12 = FUN_00427368(*piVar16,*(undefined4 *)(unaff_EBP + -0x18));
              *(int *)(unaff_EBP + 0xc) = iVar12;
              if (iVar12 != 0) {
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_0048c4c9();
                iVar6 = *(int *)(unaff_EBP + 0xc);
                *(undefined1 *)(unaff_EBP + -4) = 2;
                goto LAB_00429ba8;
              }
              *(uint *)(*piVar16 + 0x138) = *(uint *)(*piVar16 + 0x138) & 0xfffffffb;
            }
            if ((*(byte *)(unaff_EBP + -0x300) & 1) != 0) {
              *(uint *)(*piVar16 + 0x138) = *(uint *)(*piVar16 + 0x138) | 1;
            }
            if (*(char *)(unaff_EBP + 0x13) == '\0') {
              if ((int)*(short *)(iVar8 + 300) == *(int *)(unaff_EBP + -0x18)) {
                *(undefined2 *)(iVar8 + 300) = 0;
                goto LAB_0042993c;
              }
            }
            else {
              uVar3 = *(undefined2 *)(unaff_EBP + -0x18);
              *(undefined2 *)(iVar8 + 0x12e) = 0;
              *(undefined2 *)(iVar8 + 300) = uVar3;
LAB_0042993c:
              if (*(char *)(unaff_EBP + 0x13) != '\0') {
                *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(DAT_006e486c + 0x28);
                iVar8 = FUN_0043ac6a();
                while (iVar8 = iVar8 + -1, -1 < iVar8) {
                  iVar12 = FUN_0043ad1f(iVar8);
                  if ((iVar12 != 0) && ((*(byte *)(*(int *)(iVar12 + 0x60) + 0xb6) >> 1 & 1) != 0))
                  {
                    uVar7 = FUN_0045741b();
                    iVar12 = FUN_0043e17b(uVar7);
                    if (iVar12 != 0) {
                      FUN_00456156();
                    }
                  }
                }
              }
            }
            FUN_004195ba();
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              FUN_0046f824(unaff_EBP + -0x53c,0,0x104);
              *(undefined ***)(unaff_EBP + -0x548) = &PTR_FUN_006664e8;
              FUN_0046f824(unaff_EBP + -0x64c,0,0x104);
              *(undefined ***)(unaff_EBP + -0x658) = &PTR_FUN_006664e8;
              FUN_00425691(*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x548);
              FUN_0046f8e4(unaff_EBP + -0x548);
              FUN_0046f847(&DAT_006c280c,0xffffffff);
              uVar7 = *(undefined4 *)(unaff_EBP + -0x654);
              uVar17 = *(undefined4 *)(unaff_EBP + -0x544);
              FUN_005b8e25(uVar17,uVar7);
              cVar5 = FUN_005b9849(uVar17,uVar7);
              if (cVar5 != '\0') {
                uVar7 = *(undefined4 *)(unaff_EBP + -0x544);
                uVar17 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
                FUN_005b8e25(uVar17,uVar7);
                cVar5 = FUN_005b9849(uVar17,uVar7);
                if (cVar5 != '\0') {
                  uVar7 = *(undefined4 *)(unaff_EBP + -0x654);
                  goto LAB_00429ac5;
                }
                uVar7 = *(undefined4 *)(unaff_EBP + -0x544);
                uVar17 = *(undefined4 *)(unaff_EBP + -0x654);
                FUN_005b8e25(uVar17,uVar7);
                FUN_005b9849(uVar17,uVar7);
              }
              *(undefined1 *)(unaff_EBP + -4) = 3;
              FUN_0048c4c9();
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_0048c4c9();
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_004712d0();
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_00410173();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              FUN_0041905d();
              iVar6 = -0x32;
              goto LAB_00429bdf;
            }
            uVar7 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
LAB_00429ac5:
            FUN_005b8e25(uVar7);
            FUN_005b9796(uVar7);
            FUN_00425316(*(undefined4 *)(DAT_006e486c + 0x44));
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              pvVar13 = operator_new(0x7c);
              *(void **)(unaff_EBP + 0xc) = pvVar13;
              *(undefined1 *)(unaff_EBP + -4) = 0x10;
              if (pvVar13 == (void *)0x0) {
                iVar8 = 0;
              }
              else {
                iVar8 = FUN_00429bf0();
              }
              *(undefined1 *)(unaff_EBP + -4) = 4;
              cVar5 = FUN_004e1f04(*(undefined4 *)(unaff_EBP + -0x18),iVar8,0);
              if ((((cVar5 != '\0') && (0x44 < *(int *)(iVar8 + 0x48))) &&
                  (*(int *)(iVar8 + 0x48) < 0x46)) && (iVar12 = *(int *)(iVar8 + 0x24), 0 < iVar12))
              {
                *(undefined4 *)(unaff_EBP + -0x28) = 0;
                *(undefined4 *)(unaff_EBP + -0x24) = 0;
                *(undefined4 *)(unaff_EBP + -0x20) = 0;
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
                FUN_004e1d96(iVar12,unaff_EBP + -0x28);
                uVar15 = 0;
                if (*(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2 != 0) {
                  do {
                    FUN_004e8d99(*(undefined4 *)(*(int *)(unaff_EBP + -0x28) + uVar15 * 4),0x1f,1);
                    uVar15 = uVar15 + 1;
                  } while (uVar15 < (uint)(*(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28)
                                          >> 2));
                }
                *(undefined1 *)(unaff_EBP + -4) = 4;
                FUN_0048c4c9();
              }
              if (iVar8 != 0) {
                FUN_004e1909();
                FUN_006321f0(iVar8);
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0048c4c9();
            *(undefined1 *)(unaff_EBP + -4) = 2;
          }
        }
        else {
          *(undefined1 *)(unaff_EBP + -4) = 2;
        }
LAB_00429ba8:
        FUN_0048c4c9();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_004712d0();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00410173();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041905d();
LAB_00429bdf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
}

