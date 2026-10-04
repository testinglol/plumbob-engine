
undefined4 FUN_005cb022(void)

{
  int *piVar1;
  byte bVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00636080();
  bVar2 = DAT_006fe7bc & 1;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  if (bVar2 == 0) {
    DAT_006fe7bc = DAT_006fe7bc | 1;
    FUN_005c784e();
    FUN_00635543(&LAB_005cb4c5);
  }
  if (DAT_006fe7a8 != (code *)0x0) {
    iVar5 = (*DAT_006fe7a8)(&PTR_LAB_006d2dc0,0);
    if ((iVar5 != 0) && (*(int *)(unaff_EBP + 8) != 0)) {
      iVar5 = FUN_004096c2();
      if (iVar5 == 1) {
        iVar5 = FUN_00401f73();
        if (iVar5 != 0) {
          _memset((void *)(unaff_EBP + -0x24bc),0,0x2424);
          *(int *)(unaff_EBP + -0x24bc) = iVar5;
          *(undefined4 *)(unaff_EBP + -0x24b8) = 0;
          *(undefined4 *)(unaff_EBP + -0x24b4) = *(undefined4 *)(iVar5 + 0x10);
          *(int *)(unaff_EBP + -0x24ac) = unaff_EBP + -0x2098;
          *(int *)(unaff_EBP + -0x24a8) = unaff_EBP + -0x2098;
          *(undefined4 *)(unaff_EBP + -0x24a4) = 0;
          *(undefined4 *)(unaff_EBP + -0x24a0) = 0;
          FUN_005b8f4a(0);
          pcVar3 = DAT_006fe7ac;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (pcVar3 != (code *)0x0) {
            iVar5 = (*pcVar3)(unaff_EBP + -0x10,unaff_EBP + -0x24bc,0,1);
            if (iVar5 != 0) {
              if (DAT_006fe7b0 != (code *)0x0) {
                iVar5 = (*DAT_006fe7b0)(*(undefined4 *)(unaff_EBP + -0x10),0);
                if (iVar5 != 0) {
                  *(undefined4 *)(unaff_EBP + 8) = 0;
                  iVar9 = *(int *)(unaff_EBP + 0xc);
                  *(undefined4 *)(unaff_EBP + -4) = 0;
                  cVar4 = FUN_005cb302(*(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x74),
                                       *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                                       iVar9,unaff_EBP + 8);
                  if (cVar4 != '\0') {
                    _memset((void *)(unaff_EBP + -0x98),0,0x7c);
                    *(undefined4 *)(unaff_EBP + -0x98) = 0x7c;
                    iVar7 = (**(code **)(**(int **)(unaff_EBP + 8) + 100))
                                      (*(int **)(unaff_EBP + 8),0,unaff_EBP + -0x98,0x21,0);
                    if (iVar7 == 0) {
                      if (iVar9 == 0) {
                        iVar9 = *(int *)(unaff_EBP + -0x14) + 200;
                      }
                      if (*(int *)(iVar9 + 0xc) == 0x20) {
                        uVar8 = *(uint *)(iVar9 + 4) & 0x40;
                        if ((((((uVar8 != 0) && (*(int *)(iVar9 + 0x1c) == -0x1000000)) &&
                              (*(int *)(iVar9 + 0x10) == 0xff0000)) &&
                             ((*(int *)(iVar9 + 0x14) == 0xff00 && (*(int *)(iVar9 + 0x18) == 0xff))
                             )) || ((((uVar8 != 0 &&
                                      ((*(int *)(iVar9 + 0x1c) == 0 &&
                                       (*(int *)(iVar9 + 0x10) == 0xff0000)))) &&
                                     (*(int *)(iVar9 + 0x14) == 0xff00)) &&
                                    (*(int *)(iVar9 + 0x18) == 0xff)))) &&
                           (DAT_006fe7b4 != (code *)0x0)) {
                          iVar9 = (*DAT_006fe7b4)(*(undefined4 *)(unaff_EBP + -0x10),iVar5,
                                                  *(undefined4 *)(unaff_EBP + -0x74),
                                                  *(undefined4 *)(unaff_EBP + -0x88));
                          if (iVar9 != 0) {
                            uVar6 = FUN_005cb46c(*(undefined4 *)(unaff_EBP + 0x10),
                                                 *(undefined4 *)(unaff_EBP + 8));
                            *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
                          }
                        }
                      }
                      else {
                        *(undefined4 *)(unaff_EBP + -0x18) = 0;
                        *(undefined4 *)(unaff_EBP + -0x14) = 0;
                        iVar9 = *(int *)(iVar5 + 0x14);
                        iVar7 = *(int *)(iVar5 + 0x10) * 4;
                        *(undefined1 *)(unaff_EBP + -4) = 1;
                        cVar4 = FUN_005c78d1(iVar9 * iVar7);
                        if ((cVar4 != '\0') && (DAT_006fe7b4 != (code *)0x0)) {
                          iVar9 = (*DAT_006fe7b4)(*(undefined4 *)(unaff_EBP + -0x10),iVar5,
                                                  *(undefined4 *)(unaff_EBP + -0x14),iVar7);
                          if (iVar9 != 0) {
                            cVar4 = FUN_005cb36e(*(undefined4 *)(unaff_EBP + -0x14),iVar7,
                                                 unaff_EBP + -0x98);
                            if (cVar4 != '\0') {
                              uVar6 = FUN_005cb46c(*(undefined4 *)(unaff_EBP + 0x10),
                                                   *(undefined4 *)(unaff_EBP + 8));
                              *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
                            }
                          }
                        }
                        *(undefined1 *)(unaff_EBP + -4) = 0;
                        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
                        *(undefined4 *)(unaff_EBP + -0x18) = 0;
                      }
                      (**(code **)(**(int **)(unaff_EBP + 8) + 0x80))(*(int **)(unaff_EBP + 8),0);
                    }
                  }
                  FUN_005a9340(iVar5);
                  piVar1 = *(int **)(unaff_EBP + 8);
                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                  if (piVar1 != (int *)0x0) {
                    (**(code **)(*piVar1 + 8))(piVar1);
                  }
                }
              }
              if (DAT_006fe7b8 != (code *)0x0) {
                (*DAT_006fe7b8)(*(undefined4 *)(unaff_EBP + -0x10));
              }
            }
          }
          uVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
          goto LAB_005cb2f2;
        }
      }
    }
  }
  uVar6 = 0xffffffff;
LAB_005cb2f2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

