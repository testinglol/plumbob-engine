
undefined4 * FUN_00582554(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar3 = (undefined4 *)FUN_00401742(0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *puVar3 = 0;
  puVar1 = puVar3 + 1;
  *(undefined4 **)(unaff_EBP + -0x18) = puVar1;
  *(undefined4 **)(unaff_EBP + -0x1c) = puVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = *(int *)(unaff_EBP + 8);
    FUN_005b86bd(iVar2);
    puVar3[4] = *(undefined4 *)(iVar2 + 0xc);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}

