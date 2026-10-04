
undefined4 FUN_00466319(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = FUN_005c22bb();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_005c1033();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_005c171f(*(undefined4 *)(unaff_EBP + 8));
  uVar2 = *(undefined4 *)(extraout_ECX + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c1940(unaff_EBP + -0x3c,uVar2,uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  if (0 < *(short *)(unaff_EBP + 0xc)) {
    sVar1 = *(short *)(unaff_EBP + 0xc);
    iVar4 = FUN_005c11a7();
    if (sVar1 <= iVar4) {
      FUN_005c1171(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (1 < *(short *)(unaff_EBP + 0xc)) {
        iVar4 = sVar1 + -1;
        do {
          FUN_005c11d4(unaff_EBP + -0x20,0);
          FUN_0042004f();
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      pvVar5 = operator_new(0x20);
      *(void **)(unaff_EBP + 0xc) = pvVar5;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (pvVar5 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_005c32ce();
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar4 = FUN_005c1d4c(uVar2,unaff_EBP + -0x18);
      if (iVar4 == 0) {
        uVar3 = 0;
      }
      else if (iVar4 == 5) {
        uVar3 = 0xffffff9e;
      }
      else if (iVar4 == 6) {
        uVar3 = 0xffffff38;
      }
      else {
        uVar3 = 0xffffffff;
      }
      uVar2 = FUN_00465fd2(uVar2,uVar3,*(undefined4 *)(unaff_EBP + 0x10));
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
      goto LAB_0046642f;
    }
  }
  FUN_004659fc(0xffffffff);
  uVar2 = 0;
LAB_0046642f:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c1070();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

