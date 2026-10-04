
void FUN_00464567(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 *)(extraout_ECX + 0x12) = 1;
  if (*(int *)(extraout_ECX + 0xc) != 2) {
    puVar2 = operator_new(0x6c);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0046fca5();
      *puVar2 = &PTR_FUN_0066643c;
    }
    uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(extraout_ECX + 0x14) = puVar2;
    FUN_0047034e(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),uVar1,0,0xffffffff
                );
    if (*(int *)(extraout_ECX + 0xc) == 0) {
      FUN_0046ffa4(0,1);
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

