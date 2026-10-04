
undefined4 FUN_00596f69(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  cVar1 = FUN_005b90c2(unaff_EBP + -300,0x100);
  if (cVar1 != '\0') {
    FUN_005b870f(unaff_EBP + -300);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    cVar1 = FUN_005b90c2(unaff_EBP + -300,0x100);
    if (cVar1 != '\0') {
      FUN_005b870f(unaff_EBP + -300);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      cVar1 = FUN_005b9095(unaff_EBP + -0x10);
      if (cVar1 != '\0') {
        *(undefined4 *)(extraout_ECX + 0x2c) = *(undefined4 *)(unaff_EBP + -0x10);
        cVar1 = FUN_005b9095(unaff_EBP + -0x10);
        if (cVar1 != '\0') {
          *(undefined4 *)(extraout_ECX + 0x30) = *(undefined4 *)(unaff_EBP + -0x10);
          cVar1 = FUN_005b9095(unaff_EBP + 8);
          if (cVar1 != '\0') {
            *(undefined4 *)(extraout_ECX + 0x34) = *(undefined4 *)(unaff_EBP + 8);
            cVar1 = FUN_005b9095(unaff_EBP + 8);
            if (cVar1 != '\0') {
              *(undefined4 *)(extraout_ECX + 0x5c) = *(undefined4 *)(unaff_EBP + 8);
              cVar1 = FUN_005b9095(unaff_EBP + 8);
              if (cVar1 != '\0') {
                *(undefined4 *)(extraout_ECX + 100) = *(undefined4 *)(unaff_EBP + 8);
                *(undefined4 *)(extraout_ECX + 0x38) = 0;
                *(undefined4 *)(extraout_ECX + 0x44) = 0;
                *(undefined4 *)(extraout_ECX + 0x40) = 0;
                *(undefined4 *)(extraout_ECX + 0x3c) = 0;
                *(undefined4 *)(extraout_ECX + 0x54) = 0;
                *(undefined4 *)(extraout_ECX + 0x50) = 0;
                *(undefined4 *)(extraout_ECX + 0x4c) = 0;
                *(undefined4 *)(extraout_ECX + 0x48) = 0;
                cVar1 = FUN_005b9095(unaff_EBP + 8);
                if (cVar1 != '\0') {
                  *(undefined4 *)(unaff_EBP + -0x14) = 0;
                  if (0 < *(int *)(unaff_EBP + 8)) {
                    do {
                      iVar2 = FUN_005977ba();
                      cVar1 = FUN_00596834(uVar3);
                      if (cVar1 == '\0') {
                        if (iVar2 != 0) {
                          FUN_00596b92();
                          FUN_006321f0(iVar2);
                        }
                        goto LAB_0059710e;
                      }
                      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + 8));
                  }
                  uVar3 = 1;
                  goto LAB_005970eb;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0059710e:
  uVar3 = 0;
LAB_005970eb:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

