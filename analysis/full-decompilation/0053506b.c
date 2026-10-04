
void FUN_0053506b(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  if (*(int *)(unaff_EBP + 0x10) < iVar4) {
    do {
      iVar4 = (iVar4 + -1) / 2;
      iVar1 = iVar2 + iVar4 * 0x28;
      *(int *)(unaff_EBP + 0xc) = iVar1;
      cVar3 = (**(code **)(unaff_EBP + 0x3c))(iVar1,unaff_EBP + 0x14);
      if (cVar3 == '\0') break;
      FUN_00533dae(*(undefined4 *)(unaff_EBP + 0xc));
    } while (*(int *)(unaff_EBP + 0x10) < iVar4);
  }
  FUN_00533dae(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

