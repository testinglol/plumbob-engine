
void FUN_005d8d21(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
    *puVar1 = *puVar2;
    FUN_005b86bd(puVar2 + 1);
    puVar1[4] = puVar2[4];
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

