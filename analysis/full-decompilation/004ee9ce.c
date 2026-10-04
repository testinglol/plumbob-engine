
void FUN_004ee9ce(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004f2baf(unaff_EBP + -0x18);
  puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
  *(undefined2 *)(puVar2 + 2) = 0;
  *(undefined1 *)puVar2[1] = 0;
  FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x18),0xffffffff);
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
  }
  iVar3 = (**(code **)*puVar2)();
  cVar1 = *(char *)(puVar2[1] + iVar3 + -1);
  if ((cVar1 != '/') && (cVar1 != '\\')) {
    FUN_0046fa24(0x2f);
  }
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    FUN_0046f847(*(undefined4 *)(unaff_EBP + 0xc),0xffffffff);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

