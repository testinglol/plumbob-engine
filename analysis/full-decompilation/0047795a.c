
undefined4 * FUN_0047795a(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004075d4();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00667a88;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  puVar2 = extraout_ECX + 0xb;
  iVar5 = 2;
  do {
    puVar2[-2] = 0;
    *puVar2 = 0;
    puVar2[2] = 0;
    puVar2[4] = 0;
    puVar2[6] = 0;
    puVar2[8] = 0;
    puVar2[0xf] = 0;
    puVar2[0xb] = 0;
    puVar2 = puVar2 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  pvVar3 = operator_new(0x48);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005404a6();
  }
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x15] = uVar4;
  FUN_00477a73(uVar1);
  FUN_0053d4b1();
  FUN_0053bc14();
  FUN_0049f015();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x20) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x81) = 0;
  return extraout_ECX;
}

