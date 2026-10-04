
undefined4 FUN_00509b69(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  void *pvVar8;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 == '\0') {
    (**(code **)(*extraout_ECX + 0x90))();
    iVar6 = FUN_005dd5e1();
    extraout_ECX[0x19] = iVar6;
    cVar4 = FUN_005dbf32();
    if (cVar4 != '\0') {
      FUN_005a5631();
      piVar7 = (int *)extraout_ECX[0x41];
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0x70))();
        cVar4 = FUN_004cff80();
        if (cVar4 != '\0') {
          FUN_005a5631();
          piVar7 = (int *)(**(code **)(*(int *)extraout_ECX[0x41] + 0x94))();
          extraout_ECX[0x42] = (int)piVar7;
          if ((piVar7 != (int *)0x0) && (cVar4 = (**(code **)(*piVar7 + 0x20))(), cVar4 != '\0')) {
            iVar6 = extraout_ECX[0x43];
            iVar1 = *(int *)(iVar6 + 0x14);
            *(int *)(unaff_EBP + -0x20) = iVar1;
            iVar2 = *(int *)(iVar6 + 0x18);
            *(int *)(unaff_EBP + -0x1c) = iVar2;
            iVar3 = *(int *)(iVar6 + 0x1c);
            *(int *)(unaff_EBP + -0x18) = iVar3;
            iVar6 = *(int *)(iVar6 + 0x20);
            *(int *)(unaff_EBP + -0x1c) = iVar2 + 0x32;
            *(int *)(unaff_EBP + -0x28) = iVar3 + 0x118;
            *(int *)(unaff_EBP + -0x14) = iVar6;
            *(int *)(unaff_EBP + -0x2c) = iVar2;
            piVar7 = (int *)extraout_ECX[0x42];
            *(int *)(unaff_EBP + -0x30) = iVar1 + 0x118;
            *(int *)(unaff_EBP + -0x24) = iVar6 + -0x32;
            (**(code **)(*piVar7 + 0x9c))();
            (**(code **)(*(int *)extraout_ECX[0x42] + 0x24))();
          }
          pvVar8 = operator_new(100);
          *(void **)(unaff_EBP + -0x10) = pvVar8;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar8 == (void *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = (int *)FUN_005dfb13();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          if (piVar7 != (int *)0x0) {
            iVar6 = *piVar7;
            *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffb4;
            *(int *)(unaff_EBP + -0x10) = iVar6;
            FUN_00436a50(4);
            iVar6 = FUN_0050a296(0x32);
            cVar4 = (**(code **)(*(int *)(unaff_EBP + -0x10) + 0xc))(iVar6 + -500);
            if (cVar4 != '\0') {
              cVar4 = (**(code **)(*piVar7 + 0x20))();
              if (cVar4 != '\0') {
                (**(code **)(*piVar7 + 0x9c))();
                (**(code **)(*piVar7 + 0x24))(0x10);
              }
              cVar4 = FUN_005df761();
              if ((cVar4 != '\0') &&
                 (cVar4 = (**(code **)(*(int *)piVar7[0x18] + 0x20))(), cVar4 != '\0')) {
                (**(code **)(*(int *)piVar7[0x18] + 0x9c))();
                (**(code **)(*(int *)piVar7[0x18] + 0x24))(0x10);
              }
              (**(code **)(*piVar7 + 0x68))();
            }
          }
          if ((undefined4 *)extraout_ECX[0x43] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)extraout_ECX[0x43])();
          }
          extraout_ECX[0x43] = (int)piVar7;
        }
        FUN_004ce4a9();
        pvVar8 = operator_new(0x210);
        *(void **)(unaff_EBP + -0x10) = pvVar8;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar8 == (void *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)FUN_0053802e();
        }
        extraout_ECX[0x37] = (int)piVar7;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 0xc))();
          pvVar8 = operator_new(0x184);
          *(void **)(unaff_EBP + -0x10) = pvVar8;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar8 == (void *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = FUN_0050044b();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          extraout_ECX[0x3a] = iVar6;
          if (iVar6 != 0) {
            FUN_004cb1a2();
            FUN_004cb21d();
            cVar4 = (**(code **)(*(int *)extraout_ECX[0x3a] + 0xc))();
            if (cVar4 != '\0') {
              (**(code **)(*(int *)extraout_ECX[0x3a] + 0x98))();
              (**(code **)(*extraout_ECX + 0x20))();
              pvVar8 = operator_new(0x474);
              *(void **)(unaff_EBP + -0x10) = pvVar8;
              *(undefined4 *)(unaff_EBP + -4) = 3;
              if (pvVar8 == (void *)0x0) {
                iVar6 = 0;
              }
              else {
                FUN_004cff80();
                iVar6 = FUN_0051829c();
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              extraout_ECX[0x39] = iVar6;
              if (iVar6 != 0) {
                FUN_004cb1a2();
                FUN_004cb21d();
                cVar4 = (**(code **)(*(int *)extraout_ECX[0x39] + 0xc))();
                if (cVar4 != '\0') {
                  (**(code **)(*(int *)extraout_ECX[0x39] + 0x98))();
                  (**(code **)(*extraout_ECX + 0x20))();
                  pvVar8 = operator_new(0x480);
                  *(void **)(unaff_EBP + -0x10) = pvVar8;
                  *(undefined4 *)(unaff_EBP + -4) = 4;
                  if (pvVar8 == (void *)0x0) {
                    iVar6 = 0;
                  }
                  else {
                    iVar6 = FUN_00504da4();
                  }
                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                  extraout_ECX[0x38] = iVar6;
                  if (iVar6 != 0) {
                    FUN_004cb1a2();
                    FUN_004cb21d();
                    cVar4 = (**(code **)(*(int *)extraout_ECX[0x38] + 0xc))();
                    if (cVar4 != '\0') {
                      (**(code **)(*(int *)extraout_ECX[0x38] + 0x98))();
                      (**(code **)(*extraout_ECX + 0x20))();
                      pvVar8 = operator_new(0x1b4);
                      *(void **)(unaff_EBP + -0x10) = pvVar8;
                      *(undefined4 *)(unaff_EBP + -4) = 5;
                      if (pvVar8 == (void *)0x0) {
                        iVar6 = 0;
                      }
                      else {
                        iVar6 = FUN_00513e39();
                      }
                      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                      extraout_ECX[0x3b] = iVar6;
                      if (iVar6 != 0) {
                        FUN_004cb1a2();
                        FUN_004cb21d();
                        cVar4 = (**(code **)(*(int *)extraout_ECX[0x3b] + 0xc))();
                        if (cVar4 != '\0') {
                          (**(code **)(*(int *)extraout_ECX[0x3b] + 0x98))();
                          (**(code **)(*extraout_ECX + 0x20))();
                          pvVar8 = operator_new(0x128);
                          *(void **)(unaff_EBP + -0x10) = pvVar8;
                          *(undefined4 *)(unaff_EBP + -4) = 6;
                          if (pvVar8 == (void *)0x0) {
                            iVar6 = 0;
                          }
                          else {
                            iVar6 = FUN_005033ab(extraout_ECX[0x3f]);
                          }
                          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                          extraout_ECX[0x3d] = iVar6;
                          if (iVar6 != 0) {
                            FUN_004cb1a2((extraout_ECX[0x21] - extraout_ECX[0x1f]) - DAT_006f35f0);
                            FUN_004cb21d(DAT_006f35f0);
                            cVar4 = (**(code **)(*(int *)extraout_ECX[0x3d] + 0xc))();
                            if (cVar4 != '\0') {
                              (**(code **)(*(int *)extraout_ECX[0x3d] + 0x98))();
                              (**(code **)(*extraout_ECX + 0x20))();
                              pvVar8 = operator_new(0x350);
                              *(void **)(unaff_EBP + -0x10) = pvVar8;
                              *(undefined4 *)(unaff_EBP + -4) = 7;
                              if (pvVar8 == (void *)0x0) {
                                piVar7 = (int *)0x0;
                              }
                              else {
                                piVar7 = (int *)FUN_005330be();
                              }
                              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                              extraout_ECX[0x3e] = (int)piVar7;
                              if (piVar7 != (int *)0x0) {
                                (**(code **)(*piVar7 + 0x98))();
                                FUN_004cb1a2((extraout_ECX[0x21] - extraout_ECX[0x1f]) -
                                             DAT_006f35f0,100);
                                cVar4 = (**(code **)(*(int *)extraout_ECX[0x3e] + 0xc))();
                                if (cVar4 != '\0') {
                                  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3e]);
                                  FUN_004cb21d(DAT_006f35f0,DAT_006f35f4);
                                  pvVar8 = operator_new(0x118);
                                  *(void **)(unaff_EBP + -0x10) = pvVar8;
                                  *(undefined4 *)(unaff_EBP + -4) = 8;
                                  if (pvVar8 == (void *)0x0) {
                                    iVar6 = 0;
                                  }
                                  else {
                                    iVar6 = FUN_0050cad2(extraout_ECX,extraout_ECX[0x3f],
                                                         extraout_ECX[0x41]);
                                  }
                                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                                  extraout_ECX[0x3c] = iVar6;
                                  if (iVar6 != 0) {
                                    FUN_004cb1a2((extraout_ECX[0x21] - extraout_ECX[0x1f]) -
                                                 DAT_006f35f0,100);
                                    FUN_004cb21d(DAT_006f35f0,DAT_006f35f4);
                                    cVar4 = (**(code **)(*(int *)extraout_ECX[0x3c] + 0xc))();
                                    if (cVar4 != '\0') {
                                      (**(code **)(*(int *)extraout_ECX[0x3c] + 0x98))();
                                      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3c]);
                                      (**(code **)(*extraout_ECX + 0x98))();
                                      FUN_0050a9c0(extraout_ECX[0x3f]);
                                      uVar5 = FUN_005e74ca(0);
                                      FUN_005dde6d(uVar5);
                                      FUN_005a5631(0x7f4,extraout_ECX + 0x40,4);
                                      FUN_005ddfdc(1);
                                      uVar5 = 1;
                                      goto LAB_0050a287;
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
                }
              }
            }
          }
        }
      }
    }
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005dbf32();
  }
LAB_0050a287:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

