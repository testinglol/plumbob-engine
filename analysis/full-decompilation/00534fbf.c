
void FUN_00534fbf(void)

{
  int iVar1;
  char cVar2;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_38 [32];
  undefined4 uStack_18;
  int iStack_14;
  int iStack_10;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 0xc) = iVar4;
  iVar3 = iVar4 * 2 + 2;
  if (iVar3 < *(int *)(unaff_EBP + 0x10)) {
    do {
      iStack_14 = iVar1 + iVar3 * 0x28;
      iStack_10 = iStack_14 + -0x28;
      uStack_18 = 0x534ff0;
      cVar2 = (**(code **)(unaff_EBP + 0x3c))();
      iVar4 = iVar3;
      if (cVar2 != '\0') {
        iVar4 = iVar3 + -1;
      }
      iStack_10 = iVar1 + iVar4 * 0x28;
      iStack_14 = 0x535009;
      FUN_00533dae();
      iVar3 = iVar4 * 2 + 2;
    } while (iVar3 < *(int *)(unaff_EBP + 0x10));
  }
  if (iVar3 == *(int *)(unaff_EBP + 0x10)) {
    iStack_10 = iVar1 + -0x28 + iVar3 * 0x28;
    iStack_14 = 0x53502c;
    FUN_00533dae();
    iVar4 = iVar3 + -1;
  }
  iStack_10 = *(undefined4 *)(unaff_EBP + 0x3c);
  *(undefined1 **)(unaff_EBP + 0x10) = auStack_38;
  FUN_00533d58(unaff_EBP + 0x14);
  FUN_0053506b(iVar1,iVar4,*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_10 = 0x53505c;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

