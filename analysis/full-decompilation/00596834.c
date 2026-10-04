
undefined4 FUN_00596834(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar2 = FUN_005b90c2(unaff_EBP + -0x11c,0x100);
  if (cVar2 != '\0') {
    FUN_005b870f(unaff_EBP + -0x11c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(unaff_EBP + -0x1c);
    uVar3 = FUN_00598764(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0xc) = uVar3;
    FUN_005b8770();
    cVar2 = FUN_005b9095(extraout_ECX + 0x14);
    if (cVar2 != '\0') {
      cVar2 = FUN_005b9095(extraout_ECX + 0x18);
      if (cVar2 != '\0') {
        cVar2 = FUN_005b9095(extraout_ECX + 0x1c);
        if (cVar2 != '\0') {
          cVar2 = FUN_005b9095(extraout_ECX + 0x20);
          if (cVar2 != '\0') {
            cVar2 = FUN_005b9095(extraout_ECX + 0x24);
            if (cVar2 != '\0') {
              cVar2 = FUN_005b9095(extraout_ECX + 0x28);
              if (cVar2 != '\0') {
                cVar2 = FUN_005b9095(unaff_EBP + -0x10);
                if (cVar2 != '\0') {
                  if (*(int *)(extraout_ECX + 0x2c) != 0) {
                    FUN_005942ab();
                  }
                  iVar1 = *(int *)(unaff_EBP + -0x10);
                  *(undefined4 *)(extraout_ECX + 0x2c) = 0;
                  if (iVar1 == 0) {
LAB_0059698b:
                    cVar2 = FUN_005b9095(unaff_EBP + -0x10);
                    if (cVar2 != '\0') {
                      if (*(int *)(extraout_ECX + 0x30) != 0) {
                        FUN_005946cf();
                      }
                      iVar1 = *(int *)(unaff_EBP + -0x10);
                      *(undefined4 *)(extraout_ECX + 0x30) = 0;
                      if (iVar1 != 0) {
                        piVar4 = operator_new(0x10);
                        if (piVar4 == (int *)0x0) {
                          piVar4 = (int *)0x0;
                        }
                        else {
                          *piVar4 = 0;
                          piVar4[1] = 0;
                          piVar4[2] = 0;
                          piVar4[3] = 0;
                        }
                        cVar2 = FUN_00594536(*(undefined4 *)(unaff_EBP + 8));
                        if (cVar2 == '\0') {
                          if (piVar4 != (int *)0x0) {
                            FUN_00594673();
                            goto LAB_005969e4;
                          }
                          goto LAB_005969eb;
                        }
                        if (*(int *)(extraout_ECX + 0x30) != 0) {
                          FUN_005946cf();
                        }
                        if (piVar4 != (int *)0x0) {
                          *piVar4 = *piVar4 + 1;
                        }
                        *(int **)(extraout_ECX + 0x30) = piVar4;
                      }
                      uVar3 = 1;
                      goto LAB_00596a06;
                    }
                  }
                  else {
                    piVar4 = operator_new(0x10);
                    if (piVar4 == (int *)0x0) {
                      piVar4 = (int *)0x0;
                    }
                    else {
                      *piVar4 = 0;
                      piVar4[1] = 0;
                      piVar4[2] = 0;
                      piVar4[3] = 0;
                    }
                    cVar2 = FUN_0059411c(*(undefined4 *)(unaff_EBP + 8));
                    if (cVar2 != '\0') {
                      if (*(int *)(extraout_ECX + 0x2c) != 0) {
                        FUN_005942ab();
                      }
                      if (piVar4 != (int *)0x0) {
                        *piVar4 = *piVar4 + 1;
                      }
                      *(int **)(extraout_ECX + 0x2c) = piVar4;
                      goto LAB_0059698b;
                    }
                    if (piVar4 == (int *)0x0) goto LAB_005969eb;
                    FUN_00594235();
LAB_005969e4:
                    FUN_006321f0(piVar4);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005969eb:
  uVar3 = 0;
LAB_00596a06:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

