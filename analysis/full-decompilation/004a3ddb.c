
void FUN_004a3ddb(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (0 < *(int *)(unaff_EBP + 0x10)) {
    *(undefined1 *)(unaff_EBP + 0xc) =
         (&DAT_006efc6c)[(uint)*(byte *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + 0x10) * 0x100];
  }
  FUN_004a43df(unaff_EBP + 0x10,unaff_EBP + 0xc);
  iVar1 = *(int *)(unaff_EBP + 0x10);
  if (iVar1 == *(int *)(extraout_ECX + 4)) {
    FUN_004a3eeb(unaff_EBP + -0x14,unaff_EBP + 0xc);
    FUN_004a3e69(unaff_EBP + 0xc,unaff_EBP + -0x14);
    puVar2 = *(undefined4 **)(unaff_EBP + 8);
    *puVar2 = *(undefined4 *)(unaff_EBP + -0x14);
    uVar3 = *(undefined4 *)(unaff_EBP + -0x10);
  }
  else {
    puVar2 = *(undefined4 **)(unaff_EBP + 8);
    *puVar2 = *(undefined4 *)(iVar1 + 0x14);
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
  }
  puVar2[1] = uVar3;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

