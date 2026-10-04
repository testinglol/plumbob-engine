
int FUN_004c9f9a(void)

{
  undefined3 *puVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  int local_18;
  
  FUN_00634c24();
  puVar1 = *(undefined3 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)puVar1;
  *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)((int)puVar1 + 1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  local_18 = unaff_EBP + 8;
  *(undefined1 *)(unaff_EBP + 10) = 1;
  iVar2 = FUN_004a6ad9();
  iVar2 = iVar2 - DAT_006f0084;
  *(int **)(unaff_EBP + -0x14) = &local_18;
  iVar2 = *(int *)(*(int *)(extraout_ECX + (7 - *(int *)(unaff_EBP + 0xc)) * 4) + iVar2 * 4);
  local_18 = CONCAT13(local_18._3_1_,*puVar1);
  FUN_004796d9(unaff_EBP + -0x10);
  iVar2 = iVar2 + *(short *)(*(int *)(extraout_ECX + (0x15 - *(int *)(unaff_EBP + 0xc)) * 4) +
                            (uint)*(byte *)(unaff_EBP + -0xf) * 2);
  if (*(char *)(unaff_EBP + 0x10) == '\x01') {
    if (iVar2 < 0x10000) {
      if (iVar2 < 0) {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0xffff;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

