
undefined4 FUN_00505151(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  undefined *puVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    iVar4 = FUN_005dd5e1(0x1f,0x7c,0x1f);
    extraout_ECX[0x19] = iVar4;
    cVar2 = FUN_005dbf32();
    if (cVar2 != '\0') {
      pvVar5 = operator_new(0x210);
      *(void **)(unaff_EBP + -0x18) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)FUN_0050806c(extraout_ECX[0x35]);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x10b] = (int)piVar6;
      if (piVar6 != (int *)0x0) {
        cVar2 = (**(code **)(*piVar6 + 0xc))();
        if (cVar2 != '\0') {
          iVar4 = extraout_ECX[0x21];
          *(undefined4 **)(unaff_EBP + -0x10) = &DAT_006cc3d4;
          piVar6 = extraout_ECX + 0x37;
          extraout_ECX[0x10c] = 0xc9;
          extraout_ECX[0x10d] = 0;
          extraout_ECX[0x10e] = iVar4 - extraout_ECX[0x1f];
          extraout_ECX[0x10f] = 100;
          do {
            FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x10),piVar6,4);
            pvVar5 = operator_new(0x194);
            *(void **)(unaff_EBP + -0x18) = pvVar5;
            *(undefined4 *)(unaff_EBP + -4) = 1;
            if (pvVar5 == (void *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = (int *)FUN_005e372a();
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            piVar6[2] = (int)piVar7;
            (**(code **)(*piVar7 + 0x19c))(*piVar6,4,1);
            if ((int *)*piVar6 != (int *)0x0) {
              (**(code **)(*(int *)*piVar6 + 0x68))(DAT_006f2a64);
            }
            *(undefined4 *)(piVar6[2] + 0xf4) = 0;
            *(undefined4 *)(piVar6[2] + 0xf8) = 0;
            (**(code **)(*extraout_ECX + 0x20))(piVar6[2]);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
            piVar6 = piVar6 + 1;
          } while (*(int *)(unaff_EBP + -0x10) < 0x6cc3dc);
          *(undefined4 *)(unaff_EBP + -0x14) = 0x3b;
          piVar6 = &DAT_006cc57c;
          do {
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            *(int **)(unaff_EBP + -0x18) = piVar6;
            do {
              if (*piVar6 != 0) {
                iVar4 = *(int *)(unaff_EBP + -0x14);
                iVar8 = *(int *)(unaff_EBP + -0x10);
                FUN_005a5631(*piVar6,extraout_ECX + iVar4 + iVar8,4);
                piVar6 = (int *)extraout_ECX[iVar4 + iVar8];
                if (piVar6 != (int *)0x0) {
                  (**(code **)(*piVar6 + 0x68))(DAT_006f2a64);
                }
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              piVar6 = (int *)(*(int *)(unaff_EBP + -0x18) + 4);
              *(int **)(unaff_EBP + -0x18) = piVar6;
            } while (*(int *)(unaff_EBP + -0x10) < 8);
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
          } while ((int)piVar6 < 0x6cc65c);
          pvVar5 = operator_new(0x194);
          *(void **)(unaff_EBP + -0x18) = pvVar5;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar5 == (void *)0x0) {
            piVar6 = (int *)0x0;
          }
          else {
            piVar6 = (int *)FUN_005e372a();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          extraout_ECX[0x73] = (int)piVar6;
          (**(code **)(*piVar6 + 0x19c))(extraout_ECX[0x3b],4,1);
          *(undefined4 *)(extraout_ECX[0x73] + 0xf4) = 0;
          *(undefined4 *)(extraout_ECX[0x73] + 0xf8) = 0;
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x73]);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x9c) = &PTR_FUN_0066643c;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          uVar3 = FUN_0041532c(9,unaff_EBP + -0x9c,0);
          cVar2 = FUN_004fff98(0x9a,uVar3);
          if (cVar2 != '\0') {
            FUN_00471655(unaff_EBP + -0x1c);
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_0046fc87(unaff_EBP + -0x24,0);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            uVar3 = FUN_0046fc7a();
            FUN_005d4956(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 6;
            FUN_005dd9c8(unaff_EBP + -0x30);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_0042004f();
            FUN_0046fc87(unaff_EBP + -0x24,0);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            uVar3 = FUN_0046fc7a();
            FUN_005d4956(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_005dd9c8(unaff_EBP + -0x30);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_0042004f();
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0042004f();
          }
          uVar3 = FUN_0041532c(9,unaff_EBP + -0x9c,0);
          cVar2 = FUN_004fff98(0xd2,uVar3);
          if (cVar2 != '\0') {
            FUN_00471655(unaff_EBP + -0x24);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            uVar3 = FUN_0046fc7a();
            FUN_005d4956(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_005dd9c8(unaff_EBP + -0x30);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_0042004f();
          }
          FUN_005a5631(0x62c,extraout_ECX + 0xfe,4);
          FUN_005a5631(0x62d,extraout_ECX + 0xff,4);
          FUN_005a5631(0x626,extraout_ECX + 0xfc,4);
          FUN_005a5631(0x627,extraout_ECX + 0xfd,4);
          (**(code **)(*(int *)extraout_ECX[0xfe] + 0x68))(DAT_006f2a64);
          (**(code **)(*(int *)extraout_ECX[0xff] + 0x68))(DAT_006f2a64);
          (**(code **)(*(int *)extraout_ECX[0xfc] + 0x68))(DAT_006f2a64);
          (**(code **)(*(int *)extraout_ECX[0xfd] + 0x68))(DAT_006f2a64);
          piVar6 = extraout_ECX + 0x7c;
          *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0xdc;
          iVar4 = 0;
          do {
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc3dc + iVar4),piVar6 + -8,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc3fc + iVar4),piVar6,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc4dc + iVar4),piVar6 + 0x30,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc53c + iVar4),piVar6 + 0x38,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc55c + iVar4),piVar6 + 0x40,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc4fc + iVar4),piVar6 + 0x48,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc51c + iVar4),piVar6 + 0x50,4);
            FUN_005a5631(*(undefined4 *)((int)&DAT_006cc41c + iVar4),piVar6 + 0x58,4);
            if (((iVar4 != 0x10) && (iVar4 != 0x14)) && (iVar4 != 0x18)) {
              FUN_005a5631(*(undefined4 *)((int)&DAT_006cc43c + iVar4),piVar6 + 8,4);
              FUN_005a5631(*(undefined4 *)((int)&DAT_006cc49c + iVar4),piVar6 + 0x10,4);
              FUN_005a5631(*(undefined4 *)((int)&DAT_006cc4bc + iVar4),piVar6 + 0x18,4);
              FUN_005a5631(*(undefined4 *)((int)&DAT_006cc45c + iVar4),piVar6 + 0x20,4);
              FUN_005a5631(*(undefined4 *)((int)&DAT_006cc47c + iVar4),piVar6 + 0x28,4);
            }
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x18);
            do {
              FUN_005a5631(*(int *)(unaff_EBP + -0x10) + *(int *)((int)&DAT_006cc41c + iVar4) * 10,
                           *(undefined4 *)(unaff_EBP + -0x14),4);
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            } while (*(int *)(unaff_EBP + -0x10) < 4);
            iVar4 = iVar4 + 4;
            piVar6 = piVar6 + 1;
            *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x14);
          } while (iVar4 < 0x20);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          piVar6 = extraout_ECX + 0xdc;
          piVar7 = extraout_ECX + 0xd4;
          do {
            pvVar5 = operator_new(0x194);
            *(void **)(unaff_EBP + -0x18) = pvVar5;
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            if (pvVar5 == (void *)0x0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_005e372a();
            }
            piVar7[0x2c] = iVar4;
            piVar1 = (int *)piVar7[-0x60];
            *(undefined1 *)(unaff_EBP + -4) = 3;
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
            }
            if ((int *)*piVar7 != (int *)0x0) {
              (**(code **)(*(int *)*piVar7 + 0x68))(DAT_006f2a64);
            }
            if (((*(int *)(unaff_EBP + -0x10) != 4) && (*(int *)(unaff_EBP + -0x10) != 5)) &&
               (*(int *)(unaff_EBP + -0x10) != 6)) {
              if ((int *)piVar7[-0x50] != (int *)0x0) {
                (**(code **)(*(int *)piVar7[-0x50] + 0x68))(DAT_006f2a64);
              }
              if ((int *)piVar7[-0x48] != (int *)0x0) {
                (**(code **)(*(int *)piVar7[-0x48] + 0x68))(DAT_006f2a64);
              }
              if ((int *)piVar7[-0x40] != (int *)0x0) {
                (**(code **)(*(int *)piVar7[-0x40] + 0x68))(DAT_006f2a64);
              }
              if ((int *)piVar7[-0x38] != (int *)0x0) {
                (**(code **)(*(int *)piVar7[-0x38] + 0x68))(DAT_006f2a64);
              }
              if ((int *)piVar7[-0x30] != (int *)0x0) {
                (**(code **)(*(int *)piVar7[-0x30] + 0x68))(DAT_006f2a64);
              }
            }
            *(undefined4 *)(unaff_EBP + -0x18) = 4;
            do {
              (**(code **)(*(int *)*piVar6 + 0x68))(DAT_006f2a64);
              piVar6 = piVar6 + 1;
              piVar1 = (int *)(unaff_EBP + -0x18);
              *piVar1 = *piVar1 + -1;
            } while (*piVar1 != 0);
            *(undefined4 *)(piVar7[0x2c] + 0xf4) = 1;
            *(undefined4 *)(piVar7[0x2c] + 0xf8) = 1;
            (**(code **)(*extraout_ECX + 0x20))(piVar7[0x2c]);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            piVar7 = piVar7 + 1;
          } while (*(int *)(unaff_EBP + -0x10) < 8);
          uVar3 = FUN_0041532c(9,unaff_EBP + -0x9c,0);
          cVar2 = FUN_004fff98(0x96,uVar3);
          if (cVar2 != '\0') {
            iVar4 = 0;
            puVar10 = &DAT_006f2fa0;
            do {
              iVar4 = iVar4 + 1;
              uVar3 = FUN_004705f2(iVar4,0xffffffff);
              FUN_005d4bbf(uVar3);
              puVar10 = puVar10 + 0xc;
            } while ((int)puVar10 < 0x6f3240);
          }
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          *(undefined **)(unaff_EBP + -0x14) = &DAT_006f2e18;
          do {
            uVar3 = FUN_0041532c(9,unaff_EBP + -0x9c,0);
            cVar2 = FUN_004fff98(*(int *)(unaff_EBP + -0x10) + 200,uVar3);
            if (cVar2 != '\0') {
              iVar4 = 0;
              do {
                iVar4 = iVar4 + 1;
                uVar3 = FUN_004705f2(iVar4,0xffffffff);
                FUN_005d4bbf(uVar3);
              } while (iVar4 < 4);
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x30;
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          } while (*(int *)(unaff_EBP + -0x14) < 0x6f2f98);
          uVar3 = FUN_0041532c(9,unaff_EBP + -0x9c,0);
          cVar2 = FUN_004fff98(0xd2,uVar3);
          if (cVar2 != '\0') {
            uVar3 = FUN_004705f2(2,0xffffffff);
            FUN_005d4bbf(uVar3);
            uVar3 = FUN_004705f2(3,0xffffffff);
            FUN_005d4bbf(uVar3);
            uVar3 = FUN_004705f2(4,0xffffffff);
            FUN_005d4bbf(uVar3);
            uVar3 = FUN_004705f2(5,0xffffffff);
            FUN_005d4bbf(uVar3);
          }
          FUN_005067d2(*(undefined4 *)(extraout_ECX[0x35] + 0xa0));
          iVar4 = FUN_004ce4a9();
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          iVar8 = *(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2;
          *(int *)(unaff_EBP + -0x18) = iVar8;
          if (0 < iVar8) {
            do {
              uVar3 = *(undefined4 *)(*(int *)(iVar4 + 4) + *(int *)(unaff_EBP + -0x14) * 4);
              cVar2 = FUN_004cba94();
              if (cVar2 == '\x01') {
                iVar8 = FUN_00507130(uVar3);
                iVar9 = FUN_005071bf(uVar3);
                (&DAT_006f2d98)[iVar8 * 8 + iVar9] = 1;
              }
              cVar2 = FUN_004cbc01();
              if (cVar2 == '\x01') {
                iVar8 = 0;
                do {
                  if (iVar8 == 0) {
                    cVar2 = FUN_004cbb5c(1);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d18)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 1) {
                    cVar2 = FUN_004cbb5c(2);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d20)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 2) {
                    cVar2 = FUN_004cbb5c(4);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d28)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 3) {
                    cVar2 = FUN_004cbb5c(8);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d30)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 7) {
                    cVar2 = FUN_004cbb5c(0x80);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d50)[iVar9] = 1;
                    }
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 8);
              }
              cVar2 = FUN_004cbc1c();
              if (cVar2 == '\x01') {
                iVar8 = 0;
                do {
                  if (iVar8 == 0) {
                    cVar2 = FUN_004cbb7d(1);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2cd8)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 1) {
                    cVar2 = FUN_004cbb7d(2);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2ce0)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 2) {
                    cVar2 = FUN_004cbb7d(4);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2ce8)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 3) {
                    cVar2 = FUN_004cbb7d(8);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2cf0)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 7) {
                    cVar2 = FUN_004cbb7d(0x80);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2d10)[iVar9] = 1;
                    }
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 8);
              }
              cVar2 = FUN_004cbc37();
              if (cVar2 == '\x01') {
                iVar8 = 0;
                do {
                  if (iVar8 == 0) {
                    cVar2 = FUN_004cbb9e(1);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c98)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 1) {
                    cVar2 = FUN_004cbb9e(2);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2ca0)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 2) {
                    cVar2 = FUN_004cbb9e(4);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2ca8)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 3) {
                    cVar2 = FUN_004cbb9e(8);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2cb0)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 7) {
                    cVar2 = FUN_004cbb9e(0x80);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2cd0)[iVar9] = 1;
                    }
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 8);
              }
              cVar2 = FUN_004cbc52();
              if (cVar2 == '\x01') {
                iVar8 = 0;
                do {
                  if (iVar8 == 0) {
                    cVar2 = FUN_004cbbbf(1);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c58)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 1) {
                    cVar2 = FUN_004cbbbf(2);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c60)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 2) {
                    cVar2 = FUN_004cbbbf(4);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c68)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 3) {
                    cVar2 = FUN_004cbbbf(8);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c70)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 7) {
                    cVar2 = FUN_004cbbbf(0x80);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c90)[iVar9] = 1;
                    }
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 8);
              }
              cVar2 = FUN_004cbc6d();
              if (cVar2 == '\x01') {
                iVar8 = 0;
                do {
                  if (iVar8 == 0) {
                    cVar2 = FUN_004cbbe0(1);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c18)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 1) {
                    cVar2 = FUN_004cbbe0(2);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c20)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 2) {
                    cVar2 = FUN_004cbbe0(4);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c28)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 3) {
                    cVar2 = FUN_004cbbe0(8);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c30)[iVar9] = 1;
                    }
                  }
                  else if (iVar8 == 7) {
                    cVar2 = FUN_004cbbe0(0x80);
                    if (cVar2 != '\0') {
                      iVar9 = FUN_005071bf(uVar3);
                      (&DAT_006f2c50)[iVar9] = 1;
                    }
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 8);
              }
              cVar2 = FUN_004cbb29();
              if (cVar2 != '\0') {
                cVar2 = FUN_004cbb41();
                if (cVar2 != '\0') {
                  iVar8 = FUN_005071bf(uVar3);
                  iVar9 = FUN_00507252(uVar3);
                  (&DAT_006f2d58)[iVar8 * 8 + iVar9] = 1;
                }
              }
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x18));
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00470467();
          uVar3 = 1;
          goto LAB_00505df8;
        }
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005dbf32();
  }
LAB_00505df8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

