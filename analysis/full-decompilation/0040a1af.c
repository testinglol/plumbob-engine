
void FUN_0040a1af(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined *puVar6;
  undefined1 *puVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  FUN_0055e4e2(unaff_EBP + -0x11);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0047274f(&DAT_006c0fc0);
  FUN_00472855(3);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar6 = &DAT_006c0f98;
  }
  else {
    if (iVar2 != 1) goto LAB_0040a229;
    puVar6 = &DAT_006c0f9c;
  }
  FUN_004727bd(puVar6,&DAT_006c0fa0);
LAB_0040a229:
  iVar2 = FUN_0040cc3f();
  if (iVar2 == 1) {
    puVar7 = &DAT_006c0f94;
  }
  else {
    puVar7 = &DAT_006c0a74;
  }
  FUN_0047274f(puVar7);
  FUN_00472855(3);
  FUN_0040d069(unaff_EBP + -100);
  FUN_0040f445(&DAT_006f6b88);
  iVar2 = FUN_00409291();
  *(int *)(unaff_EBP + -0x20) = iVar2;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
      iVar2 = FUN_004728e9(uVar3);
      iVar5 = 0;
      if (0 < iVar2) {
        FUN_0046f824(unaff_EBP + -0xa4,0,0x40);
        *(undefined ***)(unaff_EBP + -0xb0) = &PTR_FUN_0066651c;
        FUN_0046f917(*(undefined4 *)(unaff_EBP + -0x18),iVar2);
        FUN_0055e4e2(unaff_EBP + -0x12);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005b8680();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0047274f(*(undefined4 *)(unaff_EBP + -0xac));
        FUN_0047274f(*(undefined4 *)(unaff_EBP + -0x60));
        FUN_004089ca();
        iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
        if (0 < iVar2) {
          *(int *)(unaff_EBP + -0x1c) = iVar2;
          do {
            FUN_004089ca();
            iVar2 = iVar5 + DAT_006e4860;
            iVar4 = FUN_004728e9(iVar2);
            if (0 < iVar4) {
              FUN_004030b4(unaff_EBP + -0x148);
              FUN_0046f917(iVar2,0xffffffff);
              uVar3 = FUN_00472f7f(*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0xfc);
              FUN_0040f46e(uVar3);
            }
            iVar5 = iVar5 + 0x4c;
            piVar1 = (int *)(unaff_EBP + -0x1c);
            *piVar1 = *piVar1 + -1;
          } while (*piVar1 != 0);
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00409919();
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

