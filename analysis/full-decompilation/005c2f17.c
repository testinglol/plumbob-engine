
undefined1 FUN_005c2f17(void)

{
  int iVar1;
  undefined4 uVar2;
  HANDLE hFindFile;
  int *extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  FUN_005b8680();
  iVar4 = *extraout_ECX;
  iVar1 = extraout_ECX[1];
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar4 != iVar1) {
    do {
      uVar2 = FUN_005c2efd(unaff_EBP + -0x3c,iVar4);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar2 = FUN_00412a04(unaff_EBP + -0x30,uVar2,&DAT_006cf084);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b86bd(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d499c(unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      hFindFile = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x18),
                                 (LPWIN32_FIND_DATAA)(unaff_EBP + -0x17c));
      if (hFindFile == (HANDLE)0xffffffff) goto LAB_005c2fd2;
      FindClose(hFindFile);
      iVar4 = iVar4 + 0xc;
    } while (iVar4 != extraout_ECX[1]);
  }
  uVar3 = 1;
LAB_005c2fd2:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

