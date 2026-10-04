
undefined4 FUN_0046e3ed(void)

{
  short sVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar2 = *extraout_ECX;
  *(int *)(unaff_EBP + -0x20) = unaff_EBP + -0x18;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x534c4f54;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046e6d7(unaff_EBP + -0x20,0x534c4f54);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00464f5b(unaff_EBP + -0x2c,uVar2,*(undefined4 *)(unaff_EBP + 8),0);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00465055();
  if ((*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) / 0x48 != 0) {
    iVar5 = 0;
    uVar4 = 1;
    do {
      psVar3 = (short *)(*(int *)(unaff_EBP + -0x18) + iVar5);
      sVar1 = *psVar3;
      if (sVar1 == 0) {
        FUN_0046dfd7(psVar3);
        *(uint *)(unaff_EBP + -0x48) = uVar4;
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          FUN_00435b8c(unaff_EBP + -0x54);
        }
      }
      else if (sVar1 == 1) {
        FUN_0046e09f(psVar3);
        *(uint *)(unaff_EBP + -0x84) = uVar4;
        if (*(int *)(unaff_EBP + 0x14) != 0) {
          FUN_0045f795(unaff_EBP + -0x90);
        }
      }
      else if (sVar1 == 3) {
        FUN_0046dea8(psVar3);
        *(uint *)(unaff_EBP + -0xc0) = uVar4;
        if (*(int *)(unaff_EBP + 0x10) != 0) {
          FUN_0046e53d(unaff_EBP + -0xcc);
        }
      }
      iVar5 = iVar5 + 0x48;
      bVar6 = uVar4 < (uint)((*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) / 0x48);
      uVar4 = uVar4 + 1;
    } while (bVar6);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0050be4b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

