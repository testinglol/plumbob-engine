
void FUN_00602e69(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  undefined1 *puStack_18;
  int local_14;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00676a6c;
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  while (iVar2 != iVar1) {
    if (*(int *)(iVar2 + 0x14) != 0) {
      *(undefined4 *)(iVar2 + 0x14) = 0;
    }
    local_14 = 0x602ea6;
    FUN_0041674f();
    iVar1 = extraout_ECX[1];
    iVar2 = *(int *)(unaff_EBP + -0x10);
  }
  local_14 = extraout_ECX[1];
  puStack_18 = (undefined1 *)&local_14;
  *(int **)(unaff_EBP + -0x18) = &local_14;
  *(undefined1 ***)(unaff_EBP + -0x18) = &puStack_18;
  FUN_005e8037(&puStack_18);
  FUN_00603058();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  local_14 = 0x602ed7;
  FUN_0060307c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

