
undefined4 FUN_005b9849(void)

{
  char cVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  cVar1 = FUN_005b9bbe(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x10);
  if ((cVar1 == '\0') || (*(char *)(*(int *)(unaff_EBP + -0x10) + 0x10) == '\0')) {
    BVar2 = MoveFileA(*(LPCSTR *)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 0xc));
    if (BVar2 != 0) {
      FUN_005b8680();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005b8680();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b96fe(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x3c,unaff_EBP + -0x48);
      FUN_005b9348(unaff_EBP + -0x3c,unaff_EBP + -0x48);
      FUN_005b8680();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8680();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b96fe(*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x24,unaff_EBP + -0x30);
      FUN_005a509f(unaff_EBP + -0x18,unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        iVar5 = unaff_EBP + -0x30;
        FUN_005bab42(unaff_EBP + -0x24);
        puVar3 = (undefined4 *)FUN_005baa48(iVar5);
        *(undefined1 *)(puVar3 + 4) = 0;
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[3] = 0;
        *(undefined1 *)((int)puVar3 + 0x11) = 1;
        *(undefined1 *)((int)puVar3 + 0x12) = 0;
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar4 = 1;
      goto LAB_005b9966;
    }
  }
  uVar4 = 0;
LAB_005b9966:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

