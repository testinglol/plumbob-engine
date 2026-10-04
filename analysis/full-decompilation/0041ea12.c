
void FUN_0041ea12(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar1 = *(undefined2 **)(unaff_EBP + 8);
  *(undefined2 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined2 *)0x0) {
    puVar2 = *(undefined2 **)(unaff_EBP + 0xc);
    *puVar1 = *puVar2;
    *(undefined1 *)(puVar1 + 1) = *(undefined1 *)(puVar2 + 1);
    FUN_0041ba73((int)puVar2 + 3);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

