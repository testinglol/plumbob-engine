
undefined4 FUN_00604140(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b86bd(unaff_EBP + -0x18);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = operator_new(0x10);
    *(undefined4 **)(unaff_EBP + -0x44) = puVar2;
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00604458(unaff_EBP + -0x44);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_006041f7();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

