
void FUN_00418a30(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
    *puVar1 = *puVar2;
    FUN_004030b4(puVar2 + 1);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

