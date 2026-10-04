
undefined4 FUN_00597112(void)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  cVar1 = FUN_005b90c2(unaff_EBP + -0x124,0x100);
  if (cVar1 != '\0') {
    FUN_005b870f(unaff_EBP + -0x124);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    cVar1 = FUN_005b90c2(unaff_EBP + -0x124,0x100);
    if (cVar1 != '\0') {
      FUN_005b870f(unaff_EBP + -0x124);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      cVar1 = FUN_005b8f4a(0x14);
      if (cVar1 != '\0') {
        cVar1 = FUN_005b9095(unaff_EBP + 8);
        if (cVar1 != '\0') {
          iVar3 = 0;
          if (0 < *(int *)(unaff_EBP + 8)) {
            do {
              cVar1 = FUN_00596a17(uVar2,*(undefined4 *)(unaff_EBP + 0x10),
                                   *(undefined4 *)(unaff_EBP + 0x14));
              if (cVar1 == '\0') goto LAB_00597201;
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(int *)(unaff_EBP + 8));
          }
          uVar2 = 1;
          goto LAB_005971f0;
        }
      }
    }
  }
LAB_00597201:
  uVar2 = 0;
LAB_005971f0:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

