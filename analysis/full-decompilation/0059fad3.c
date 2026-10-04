
undefined4 FUN_0059fad3(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  cVar1 = FUN_005b9095(unaff_EBP + -0x14);
  if (cVar1 != '\0') {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (0 < *(int *)(unaff_EBP + -0x14)) {
      do {
        cVar1 = FUN_005b90c2(unaff_EBP + -0x918,0x400);
        if ((cVar1 == '\0') || (cVar1 = FUN_005b90c2(unaff_EBP + -0x518,0x400), cVar1 == '\0'))
        goto LAB_0059fee0;
        FUN_005b870f(unaff_EBP + -0x918);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar2 = FUN_005a1f21(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005a242b(unaff_EBP + -0x2c,uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_0059ee43();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        if (*(int *)(unaff_EBP + -0x2c) == 0) {
          FUN_006358c0(unaff_EBP + -0x518,&DAT_006d1d64);
          uVar2 = FUN_005b870f(unaff_EBP + -0x518);
          *(undefined4 *)(unaff_EBP + -4) = 2;
          uVar3 = FUN_005b870f(unaff_EBP + -0x918);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          uVar2 = FUN_005a200d(uVar3,*(undefined4 *)(unaff_EBP + 8),uVar2,
                               *(undefined4 *)(unaff_EBP + 0x10));
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005a1cbf(unaff_EBP + -100,uVar2);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_0059ee43();
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
    }
    cVar1 = FUN_005b9095(unaff_EBP + -0x14);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + -0x14)) {
        do {
          cVar1 = FUN_005b90c2(unaff_EBP + -0x918,0x400);
          if ((cVar1 == '\0') || (cVar1 = FUN_005b90c2(unaff_EBP + -0x518,0x400), cVar1 == '\0'))
          goto LAB_0059fee0;
          FUN_005b870f(unaff_EBP + -0x918);
          *(undefined4 *)(unaff_EBP + -4) = 5;
          uVar2 = FUN_005a20c2(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005a2464(unaff_EBP + -0x2c,uVar2);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_0059ee88();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          if (*(int *)(unaff_EBP + -0x2c) == 0) {
            FUN_006358c0(unaff_EBP + -0x518,&DAT_006d1d64);
            uVar2 = FUN_005b870f(unaff_EBP + -0x518);
            *(undefined4 *)(unaff_EBP + -4) = 7;
            uVar3 = FUN_005b870f(unaff_EBP + -0x918);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            uVar2 = FUN_005a21ae(uVar3,*(undefined4 *)(unaff_EBP + 8),uVar2,
                                 *(undefined4 *)(unaff_EBP + 0x10));
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005a1e39(unaff_EBP + -100,uVar2);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_0059ee88();
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005b8770();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
      }
      cVar1 = FUN_005b9095(unaff_EBP + -0x14);
      if (cVar1 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if (0 < *(int *)(unaff_EBP + -0x14)) {
          do {
            cVar1 = FUN_005b90c2(unaff_EBP + -0x918,0x400);
            if ((cVar1 == '\0') || (cVar1 = FUN_005b90c2(unaff_EBP + -0x518,0x400), cVar1 == '\0'))
            goto LAB_0059fee0;
            FUN_005b870f(unaff_EBP + -0x918);
            *(undefined4 *)(unaff_EBP + -4) = 10;
            uVar2 = FUN_005a2263(unaff_EBP + -0x24);
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            FUN_005a242b(unaff_EBP + -0x4c,uVar2);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_0059eecd();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
            if (*(int *)(unaff_EBP + -0x4c) == 0) {
              FUN_006358c0(unaff_EBP + -0x518,&DAT_006d1d64);
              uVar2 = FUN_005b870f(unaff_EBP + -0x518);
              *(undefined4 *)(unaff_EBP + -4) = 0xc;
              uVar3 = FUN_005b870f(unaff_EBP + -0x918);
              *(undefined1 *)(unaff_EBP + -4) = 0xd;
              uVar2 = FUN_005a234f(uVar3,*(undefined4 *)(unaff_EBP + 8),uVar2,
                                   *(undefined4 *)(unaff_EBP + 0x10));
              *(undefined1 *)(unaff_EBP + -4) = 0xe;
              FUN_005a1d7c(unaff_EBP + -0xb0,uVar2);
              *(undefined1 *)(unaff_EBP + -4) = 0xd;
              FUN_0059eecd();
              *(undefined1 *)(unaff_EBP + -4) = 0xc;
              FUN_005b8770();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              FUN_005b8770();
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
        }
        uVar2 = 0;
        goto LAB_0059fecf;
      }
    }
  }
LAB_0059fee0:
  uVar2 = 1;
LAB_0059fecf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

