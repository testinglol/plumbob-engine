
int FUN_004309fe(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  iVar3 = FUN_00401742(0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  puVar1 = (undefined1 *)(iVar3 + 0x10);
  *(undefined1 **)(unaff_EBP + -0x18) = puVar1;
  *(undefined1 **)(unaff_EBP + -0x1c) = puVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(unaff_EBP + 8);
    *puVar1 = *puVar2;
    FUN_005b86bd(puVar2 + 4);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar3;
}

