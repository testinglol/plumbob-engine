
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00527ffb(void)

{
  char *pcVar1;
  size_t sVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  bool bVar5;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_005e372a();
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x68] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x6c] = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  extraout_ECX[0x65] = 0xffffffff;
  extraout_ECX[0x66] = 0xffffffff;
  *extraout_ECX = &PTR_FUN_0066d574;
  extraout_ECX[0x6a] = 0;
  bVar5 = DAT_006f3ba8 == 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (bVar5) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      pcVar1 = (char *)FUN_0046fc7a();
      sVar2 = _strlen(pcVar1);
      pvVar3 = operator_new(sVar2 + 1);
      *(void **)(unaff_EBP + 0xc) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_0046fc7a();
        FUN_006358b0(*(undefined4 *)(unaff_EBP + 0xc),uVar4);
      }
      *(undefined4 *)((int)&DAT_006f3ba8 + *(int *)(unaff_EBP + -0x10)) =
           *(undefined4 *)(unaff_EBP + 0xc);
      FUN_005c11ce();
      pcVar1 = (char *)FUN_0046fc7a();
      sVar2 = _strlen(pcVar1);
      pvVar3 = operator_new(sVar2 + 1);
      *(void **)(unaff_EBP + 0xc) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        uVar4 = FUN_0046fc7a();
        FUN_006358b0(*(undefined4 *)(unaff_EBP + 0xc),uVar4);
      }
      *(undefined4 *)((int)&DAT_006f3bbc + *(int *)(unaff_EBP + -0x10)) =
           *(undefined4 *)(unaff_EBP + 0xc);
      FUN_005c11ce();
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
    } while (*(int *)(unaff_EBP + -0x10) < 0x14);
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    uVar4 = FUN_0046fc7a();
    FUN_005d4bbf(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar4 = FUN_0046fc7a();
    FUN_005d4bbf(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    uVar4 = FUN_0046fc7a();
    FUN_005d4bbf(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    uVar4 = FUN_0046fc7a();
    FUN_005d4bbf(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x6b] = *(undefined4 *)(unaff_EBP + 8);
  _DAT_006f3b98 = _DAT_006f3b98 + 1;
  return extraout_ECX;
}

