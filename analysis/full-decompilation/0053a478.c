
undefined4 FUN_0053a478(void)

{
  int iVar1;
  char cVar2;
  SHORT SVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) != 1) goto LAB_0053ad0f;
  iVar4 = *(int *)(unaff_EBP + 0xc);
  if (iVar4 == *(int *)(extraout_ECX + 0x10c)) {
    iVar4 = FUN_004cebac();
    if (iVar4 != 1) {
      FUN_0051eaec();
    }
    uVar9 = 1;
  }
  else {
    if (iVar4 != *(int *)(extraout_ECX + 0x110)) {
      if (iVar4 == *(int *)(extraout_ECX + 0x114)) {
        uVar9 = 8;
        goto LAB_0053a50e;
      }
      if (iVar4 == *(int *)(extraout_ECX + 0xd8)) {
        FUN_004cef47(1);
        goto LAB_0053ad0f;
      }
      if (iVar4 == *(int *)(extraout_ECX + 0xdc)) {
        FUN_004cef2b(1);
        goto LAB_0053ad0f;
      }
      if (iVar4 == *(int *)(extraout_ECX + 0xe0)) {
        FUN_004cef5b(1);
        goto LAB_0053ad0f;
      }
      if (iVar4 == *(int *)(extraout_ECX + 0xe4)) {
        FUN_004cef7c(1);
        goto LAB_0053ad0f;
      }
      if (iVar4 == *(int *)(extraout_ECX + 0xe8)) {
        uVar9 = 1;
      }
      else if (iVar4 == *(int *)(extraout_ECX + 0xec)) {
        uVar9 = 4;
      }
      else {
        if (iVar4 != *(int *)(extraout_ECX + 0xf0)) {
          if (iVar4 == *(int *)(extraout_ECX + 0xf4)) {
            SVar3 = GetKeyState(0x10);
            *(byte *)(unaff_EBP + 0xb) = (byte)((ushort)SVar3 >> 0xf);
            SVar3 = GetKeyState(0x11);
            if ((*(char *)(unaff_EBP + 0xb) != '\0') && (SVar3 < 0)) goto LAB_0053ad0f;
            iVar4 = FUN_00401f6f();
            if (iVar4 == 2) {
              FUN_004cfe14(*(int *)(extraout_ECX + 0x1a0) == 0,0);
              goto LAB_0053ad0f;
            }
            if (*(int *)(extraout_ECX + 0x1a0) == 1) {
              FUN_004cfe14(0,0);
            }
            uVar9 = 2;
          }
          else if (iVar4 == *(int *)(extraout_ECX + 0xf8)) {
            uVar9 = 1;
            if (*(int *)(extraout_ECX + 0x1a0) == 1) {
              FUN_004cfe14(0,0);
            }
            iVar4 = FUN_00401f6f();
            if (iVar4 == 1) {
              iVar4 = *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xa0);
              if (iVar4 == 0) {
                uVar10 = 1;
LAB_0053a695:
                FUN_004cf54e(uVar10);
              }
              else {
                if (iVar4 == 1) {
                  uVar10 = 0;
                  goto LAB_0053a695;
                }
                if (iVar4 == 2) {
                  uVar10 = 2;
                  goto LAB_0053a695;
                }
              }
              FUN_004cffbb();
            }
          }
          else if (iVar4 == *(int *)(extraout_ECX + 0xfc)) {
            if (*(int *)(extraout_ECX + 0x1a0) == 1) {
              FUN_004cfe14(0,0);
            }
            uVar9 = 0;
          }
          else if (iVar4 == *(int *)(extraout_ECX + 0x100)) {
            if (*(int *)(extraout_ECX + 0x1a0) == 1) {
              FUN_004cfe14(0,0);
            }
            uVar9 = 3;
          }
          else {
            if (iVar4 != *(int *)(extraout_ECX + 0x104)) {
              if (iVar4 == *(int *)(extraout_ECX + 0x118)) {
                cVar2 = FUN_00493b85();
                if (cVar2 == '\0') {
                  uVar9 = 0;
                  uVar10 = FUN_004cebb0(0);
                }
                else {
                  uVar9 = FUN_004cebb0();
                  uVar10 = 0;
                }
                FUN_0053b99f(uVar10,uVar9);
                cVar2 = FUN_00493b85();
                FUN_004cefe5('\x01' - (cVar2 != '\0'));
                goto LAB_0053ad0f;
              }
              if (iVar4 == *(int *)(extraout_ECX + 0x11c)) {
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  *(undefined1 *)(extraout_ECX + 0x1ec) = 0;
                }
                cVar2 = FUN_00493b85();
                if (cVar2 == '\0') {
                  uVar9 = FUN_004425e2();
                  uVar10 = FUN_004cebb0(uVar9);
                }
                else {
                  uVar9 = FUN_004425e2();
                  uVar10 = 0;
                }
                FUN_0053b99f(uVar10,uVar9);
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  FUN_004cefe5(0);
                }
                uVar9 = FUN_004425e2();
              }
              else if (iVar4 == *(int *)(extraout_ECX + 0x120)) {
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  *(undefined1 *)(extraout_ECX + 0x1ec) = 0;
                }
                cVar2 = FUN_00493b85();
                if (cVar2 == '\0') {
                  uVar9 = FUN_0046d380();
                  uVar10 = FUN_004cebb0(uVar9);
                }
                else {
                  uVar9 = FUN_0046d380();
                  uVar10 = 0;
                }
                FUN_0053b99f(uVar10,uVar9);
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  FUN_004cefe5(0);
                }
                uVar9 = FUN_0046d380();
              }
              else {
                if (iVar4 != *(int *)(extraout_ECX + 0x124)) {
                  if (((iVar4 == *(int *)(extraout_ECX + 0x108)) &&
                      (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0)) &&
                     (cVar2 = FUN_004074bc(), cVar2 == '\x01')) {
                    FUN_0057a7f7(s_UI_whoosh_006c7b60,0xfffffffc);
                    pvVar5 = operator_new(0x140);
                    *(void **)(unaff_EBP + 8) = pvVar5;
                    *(undefined4 *)(unaff_EBP + -4) = 0;
                    if (pvVar5 == (void *)0x0) {
                      piVar6 = (int *)0x0;
                    }
                    else {
                      piVar6 = (int *)FUN_0050201c();
                    }
                    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    if (piVar6 != (int *)0x0) {
                      cVar2 = (**(code **)(*piVar6 + 0xc))();
                      if (cVar2 != '\0') {
                        piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
                        iVar8 = (**(code **)(*piVar7 + 8))();
                        iVar4 = *(int *)(iVar8 + 0x7c);
                        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar8 + 0x80);
                        uVar9 = *(undefined4 *)(iVar8 + 0x84);
                        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0x88);
                        iVar8 = *(int *)(unaff_EBP + -0x18);
                        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -iVar8;
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -iVar8;
                        iVar8 = piVar6[0x20];
                        *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
                        iVar1 = piVar6[0x22];
                        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) - iVar4;
                        FUN_004cb21d((((piVar6[0x1f] - piVar6[0x21]) - *(int *)(unaff_EBP + -0x1c))
                                     + *(int *)(unaff_EBP + -0x14)) / 2,
                                     (((iVar8 - iVar1) - *(int *)(unaff_EBP + -0x18)) +
                                     *(int *)(unaff_EBP + -0x10)) / 2);
                        piVar6[0x12] = extraout_ECX;
                        FUN_004d3f37(1);
                        FUN_004f6c41(piVar6,1,0);
                        FUN_004d3f37(0);
                      }
                      FUN_005da4c7(piVar6);
                    }
                  }
                  else if ((iVar4 == *(int *)(extraout_ECX + 0x1d0)) &&
                          (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x50) == 0)) {
                    pvVar5 = operator_new(0x148);
                    *(void **)(unaff_EBP + 8) = pvVar5;
                    *(undefined4 *)(unaff_EBP + -4) = 1;
                    if (pvVar5 == (void *)0x0) {
                      piVar6 = (int *)0x0;
                    }
                    else {
                      piVar6 = (int *)FUN_00523434();
                    }
                    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    if (piVar6 != (int *)0x0) {
                      cVar2 = (**(code **)(*piVar6 + 0xc))();
                      if (cVar2 != '\0') {
                        FUN_0046fca5();
                        *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
                        *(undefined4 *)(unaff_EBP + -4) = 2;
                        uVar9 = FUN_0041532c(9,unaff_EBP + -0xac,0);
                        cVar2 = FUN_004fff98(0xa2,uVar9);
                        if (cVar2 != '\0') {
                          uVar9 = FUN_004705f2(1,0xffffffff);
                          FUN_005d4956(uVar9);
                          *(undefined1 *)(unaff_EBP + -4) = 3;
                          FUN_00523771(unaff_EBP + -0x40);
                          *(undefined1 *)(unaff_EBP + -4) = 2;
                          FUN_005b8770();
                          uVar9 = FUN_004705f2(2,0xffffffff);
                          FUN_005d4956(uVar9);
                          *(undefined1 *)(unaff_EBP + -4) = 4;
                          FUN_00523be3(unaff_EBP + -0x34);
                          *(undefined1 *)(unaff_EBP + -4) = 2;
                          FUN_005b8770();
                          uVar9 = FUN_004705f2(3,0xffffffff);
                          FUN_005d4956(uVar9);
                          *(undefined1 *)(unaff_EBP + -4) = 5;
                          FUN_0052386b(unaff_EBP + -0x28,0);
                          *(undefined1 *)(unaff_EBP + -4) = 2;
                          FUN_005b8770();
                          piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
                          iVar8 = (**(code **)(*piVar7 + 8))();
                          iVar4 = *(int *)(iVar8 + 0x7c);
                          *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar8 + 0x80);
                          uVar9 = *(undefined4 *)(iVar8 + 0x84);
                          *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0x88);
                          iVar8 = *(int *)(unaff_EBP + -0x18);
                          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -iVar8;
                          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -iVar8;
                          iVar8 = piVar6[0x20];
                          *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
                          iVar1 = piVar6[0x22];
                          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) - iVar4;
                          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                          FUN_004cb21d((((piVar6[0x1f] - piVar6[0x21]) - *(int *)(unaff_EBP + -0x1c)
                                        ) + *(int *)(unaff_EBP + -0x14)) / 2,
                                       (((iVar8 - iVar1) - *(int *)(unaff_EBP + -0x18)) +
                                       *(int *)(unaff_EBP + -0x10)) / 2);
                          piVar6[0x12] = extraout_ECX;
                          FUN_004d3f37(1);
                          FUN_004f6c41(piVar6,1,0);
                          FUN_004d3f37(0);
                        }
                        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                        FUN_00470467();
                      }
                      FUN_005da4c7(piVar6);
                    }
                  }
                  else {
                    if (iVar4 != *(int *)(extraout_ECX + 0x128)) goto LAB_0053ad0f;
                    pvVar5 = operator_new(0x188);
                    *(void **)(unaff_EBP + 8) = pvVar5;
                    *(undefined4 *)(unaff_EBP + -4) = 6;
                    if (pvVar5 == (void *)0x0) {
                      piVar6 = (int *)0x0;
                    }
                    else {
                      piVar6 = (int *)FUN_0050e9b6(DAT_006f2aa4);
                    }
                    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    if (piVar6 == (int *)0x0) goto LAB_0053ad0f;
                    (**(code **)(*piVar6 + 0xc))();
                    FUN_0050f14d(*(undefined4 *)(extraout_ECX + 0x1f0));
                    FUN_004d3f37(1);
                    FUN_004f6c41(piVar6,1,0);
                    FUN_004d3f37(0);
                    uVar9 = FUN_0050f139();
                    *(undefined4 *)(extraout_ECX + 0x1f0) = uVar9;
                    FUN_005da4c7(piVar6);
                  }
                  FUN_005e46f0(0);
                  goto LAB_0053ad0f;
                }
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  *(undefined1 *)(extraout_ECX + 0x1ec) = 0;
                }
                cVar2 = FUN_00493b85();
                if (cVar2 == '\0') {
                  uVar9 = FUN_0046d386();
                  uVar10 = FUN_004cebb0(uVar9);
                }
                else {
                  uVar9 = FUN_0046d386();
                  uVar10 = 0;
                }
                FUN_0053b99f(uVar10,uVar9);
                iVar4 = FUN_00401f6f();
                if (iVar4 == 2) {
                  FUN_004cefe5(0);
                }
                uVar9 = FUN_0046d386();
                uVar10 = FUN_004cebb0(uVar9);
                FUN_0053b99f(uVar10,uVar9);
                uVar9 = FUN_0046d386();
              }
              FUN_004cf024(uVar9);
              goto LAB_0053ad0f;
            }
            if (*(int *)(extraout_ECX + 0x1a0) == 1) {
              FUN_004cfe14(0,0);
            }
            uVar9 = 4;
          }
          FUN_004cebf8(uVar9,0);
          goto LAB_0053ad0f;
        }
        uVar9 = 2;
      }
LAB_0053a50e:
      FUN_004cf0ab(uVar9,1);
      goto LAB_0053ad0f;
    }
    iVar4 = FUN_004cebac();
    if (iVar4 != 2) {
      FUN_0051eaec();
    }
    uVar9 = 2;
  }
  FUN_004cefa3(uVar9,0);
LAB_0053ad0f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

