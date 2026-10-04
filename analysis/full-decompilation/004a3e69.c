
void FUN_004a3e69(void)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x38) == 0) {
    iVar2 = *(int *)(extraout_ECX + 0x10) * 0x100 + -0x100;
    FUN_004c656a(iVar2);
    iVar2 = FUN_004c8f7a(iVar2);
    puVar3 = (ushort *)(*(int *)(*(int *)(iVar2 + 0xc) + 0xc) + *(int *)(iVar2 + 0xc));
    *(uint *)(extraout_ECX + 0x38) = (uint)*puVar3;
    *(uint *)(extraout_ECX + 0x3c) = (uint)puVar3[1];
  }
  *(undefined1 *)(unaff_EBP + -0x20) = **(undefined1 **)(unaff_EBP + 8);
  uVar1 = (*(undefined4 **)(unaff_EBP + 0xc))[1];
  *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004a4354(unaff_EBP + -0x14,unaff_EBP + -0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

