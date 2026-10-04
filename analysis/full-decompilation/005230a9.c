
void FUN_005230a9(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = FUN_005f51ce();
  if (iVar2 != 0) {
    while (iVar2 = FUN_005f51ce(), iVar2 != 0) {
      iVar2 = FUN_005f51ce();
      FUN_005f53e2(iVar2 + -1);
    }
  }
  iVar2 = FUN_005231fb();
  *(int *)(unaff_EBP + -0x18) = iVar2;
  if (iVar2 != 0) {
    iVar2 = FUN_004102e1();
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(int *)(unaff_EBP + -0x14) = iVar2;
    if (0 < iVar2) {
      do {
        puVar3 = (undefined4 *)FUN_004102ab(*(undefined4 *)(unaff_EBP + -0x10));
        iVar2 = FUN_0043acf5(*puVar3);
        if ((iVar2 != 0) && (cVar1 = FUN_00523046(puVar3), cVar1 != '\0')) {
          FUN_0046f824(unaff_EBP + -0x130,0,0x100);
          *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_00666524;
          uVar4 = thunk_FUN_00457ea7();
          FUN_005b86bd(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (*(int *)(unaff_EBP + -0x20) != *(int *)(unaff_EBP + -0x24)) {
            uVar4 = FUN_004096c2();
            FUN_005d4956(uVar4);
            iVar2 = unaff_EBP + -0x30;
            *(undefined1 *)(unaff_EBP + -4) = 1;
            uVar4 = FUN_005f51ce(iVar2);
            FUN_005f51e0(uVar4,iVar2);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_005b8770();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

