
undefined4 * FUN_0050f244(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  bool bVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX;
  FUN_005e372a();
  bVar4 = DAT_006f3874 == '\0';
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x65] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x68] = 0;
  *extraout_ECX = &PTR_FUN_0066bac8;
  if (bVar4) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xf8) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    cVar1 = FUN_004fff98(0x8c,&DAT_006c265c,unaff_EBP + -0xf8,0);
    if (cVar1 != '\0') {
      cVar1 = FUN_004fff98(0x8e,&DAT_006c265c,unaff_EBP + -0x8c,0);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00471655(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar3 = 0;
        do {
          FUN_005c11ce();
          uVar2 = FUN_0046fc7a();
          FUN_005d4bbf(uVar2);
          FUN_005c11ce();
          uVar2 = FUN_0046fc7a();
          FUN_005d4bbf(uVar2);
          iVar3 = iVar3 + 0xc;
        } while (iVar3 < 0xe4);
        DAT_006f3874 = '\x01';
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00470467();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_00470467();
        goto LAB_0050f3b6;
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00470467();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00470467();
  }
  else {
LAB_0050f3b6:
    extraout_ECX[0x67] = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

