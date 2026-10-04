
void FUN_0040f0f4(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined *puVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_0055e4e2(unaff_EBP + -0x13);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0055e4e2(unaff_EBP + -0x12);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0047274f(&DAT_006c10b4);
  FUN_00472855(1);
  FUN_0047274f(&DAT_006c10ac);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar6 = &DAT_006c0f98;
  }
  else {
    if (iVar2 != 1) goto LAB_0040f1a3;
    puVar6 = &DAT_006c0f9c;
  }
  FUN_004727bd(puVar6,&DAT_006c0fa0);
  FUN_004727bd(puVar6,&DAT_006c0fa0);
LAB_0040f1a3:
  FUN_0047274f(&DAT_006c0a74);
  FUN_0047274f(&DAT_006c0a74);
  iVar2 = FUN_0040cd0e();
  if ((-1 < iVar2) && (iVar2 < 2)) {
    FUN_00472855(3);
    FUN_00472855(3);
  }
  FUN_0040d069(unaff_EBP + -0x7c);
  FUN_0040f445(&DAT_006f6b88);
  iVar2 = FUN_00409291();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x20) = iVar2;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
      iVar2 = FUN_004728e9(uVar3);
      if ((0 < iVar2) && (iVar4 = FUN_004728e9(uVar3), iVar4 < 1)) {
        FUN_0046f824(unaff_EBP + -0xbc,0,0x40);
        *(undefined ***)(unaff_EBP + -200) = &PTR_FUN_0066651c;
        FUN_0046f917(uVar3,iVar2);
        FUN_0055e4e2(unaff_EBP + -0x11);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_0047274f(*(undefined4 *)(unaff_EBP + -0xc4));
        iVar2 = FUN_0040cd0e();
        if ((-1 < iVar2) && (iVar2 < 2)) {
          FUN_0047274f(*(undefined4 *)(unaff_EBP + -0x78));
        }
        FUN_004089ca();
        iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
        if (0 < iVar2) {
          iVar4 = 0;
          *(int *)(unaff_EBP + -0x1c) = iVar2;
          do {
            FUN_004089ca();
            iVar2 = iVar4 + DAT_006e4860;
            iVar5 = FUN_004728e9(iVar2);
            if (0 < iVar5) {
              FUN_004030b4(unaff_EBP + -0x160);
              FUN_0046f917(iVar2,0xffffffff);
              uVar3 = FUN_00472f7f(*(undefined4 *)(unaff_EBP + -0x24),unaff_EBP + -0x114);
              FUN_0040f46e(uVar3);
            }
            iVar4 = iVar4 + 0x4c;
            piVar1 = (int *)(unaff_EBP + -0x1c);
            *piVar1 = *piVar1 + -1;
          } while (*piVar1 != 0);
        }
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00409919();
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x20));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00409919();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

