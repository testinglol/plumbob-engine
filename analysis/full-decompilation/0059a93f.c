
undefined4 FUN_0059a93f(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar1 = FUN_005b90c2(unaff_EBP + -0x140,0x100);
  if (cVar1 != '\0') {
    uVar2 = FUN_005b870f(unaff_EBP + -0x140);
    iVar3 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    cVar1 = FUN_005b90c2(unaff_EBP + -0x140,0x100);
    if (cVar1 != '\0') {
      uVar2 = FUN_005b870f(unaff_EBP + -0x140);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_00599e03();
      cVar1 = FUN_005b9095(unaff_EBP + -0x10);
      if (cVar1 != '\0') {
        FUN_0059af08(*(undefined4 *)(unaff_EBP + -0x10));
        if (0 < *(int *)(unaff_EBP + -0x10)) {
          do {
            cVar1 = FUN_005b90c2(unaff_EBP + -0x140,0x100);
            if (cVar1 == '\0') goto LAB_0059abff;
            FUN_005b870f(unaff_EBP + -0x140);
            *(undefined4 *)(unaff_EBP + -4) = 2;
            FUN_00599e11(unaff_EBP + -0x1c);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(unaff_EBP + -0x10));
        }
        cVar1 = FUN_005b9095(unaff_EBP + -0x10);
        if (cVar1 != '\0') {
          FUN_0059b2e8(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x1c);
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          if (0 < *(int *)(unaff_EBP + -0x10)) {
            do {
              cVar1 = FUN_005997fa(*(undefined4 *)(unaff_EBP + 8));
              if (cVar1 == '\0') goto LAB_0059abff;
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x10));
          }
          cVar1 = FUN_005b9095(unaff_EBP + -0x10);
          if (cVar1 != '\0') {
            *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffff;
            FUN_0059b324(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x28);
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            if (0 < *(int *)(unaff_EBP + -0x10)) {
              do {
                cVar1 = FUN_005998b7(*(undefined4 *)(unaff_EBP + 8));
                if (cVar1 == '\0') goto LAB_0059abff;
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
              } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x10));
            }
            cVar1 = FUN_005b9095(unaff_EBP + -0x10);
            if (cVar1 != '\0') {
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
              FUN_0059b37f(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x18);
              iVar3 = 0;
              if (0 < *(int *)(unaff_EBP + -0x10)) {
                do {
                  cVar1 = FUN_005996bf(*(undefined4 *)(unaff_EBP + 8));
                  if (cVar1 == '\0') goto LAB_0059abff;
                  iVar3 = iVar3 + 1;
                } while (iVar3 < *(int *)(unaff_EBP + -0x10));
              }
              cVar1 = FUN_005b9095(unaff_EBP + -0x10);
              if (cVar1 != '\0') {
                FUN_0059b3ce(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x18);
                iVar3 = 0;
                if (0 < *(int *)(unaff_EBP + -0x10)) {
                  do {
                    cVar1 = FUN_005996bf(*(undefined4 *)(unaff_EBP + 8));
                    if (cVar1 == '\0') goto LAB_0059abff;
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < *(int *)(unaff_EBP + -0x10));
                }
                cVar1 = FUN_005b9095(unaff_EBP + -0x10);
                if (cVar1 != '\0') {
                  FUN_0059b402(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x40);
                  *(undefined4 *)(unaff_EBP + -0x14) = 0;
                  if (0 < *(int *)(unaff_EBP + -0x10)) {
                    do {
                      cVar1 = FUN_00599783(*(undefined4 *)(unaff_EBP + 8));
                      if (cVar1 == '\0') goto LAB_0059abff;
                      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x10));
                  }
                  FUN_004d5f89(*(undefined4 *)(extraout_ECX + 0x1c),
                               *(undefined4 *)(extraout_ECX + 0x20));
                  FUN_0059a46a();
                  uVar2 = 1;
                  goto LAB_0059abee;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0059abff:
  uVar2 = 0;
LAB_0059abee:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

