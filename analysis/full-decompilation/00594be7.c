
undefined4 FUN_00594be7(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  cVar1 = FUN_005b911f();
  if (cVar1 != '\0') {
    cVar1 = FUN_005b90c2(unaff_EBP + -0x118,0x100);
    if (cVar1 != '\0') {
      FUN_005b870f(unaff_EBP + -0x118);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      cVar1 = FUN_005b8f4a(4);
      if (cVar1 != '\0') {
        cVar1 = FUN_005b9095(unaff_EBP + 8);
        if (cVar1 != '\0') {
          if (*(int *)(extraout_ECX + 0x24) != 0) {
            FUN_005942ab();
          }
          *(undefined4 *)(extraout_ECX + 0x24) = 0;
          if (*(int *)(unaff_EBP + 8) != 0) {
            cVar1 = FUN_00594196(uVar2);
            if (cVar1 == '\0') goto LAB_00594c8e;
          }
          uVar2 = 1;
          goto LAB_00594c94;
        }
      }
    }
  }
LAB_00594c8e:
  uVar2 = 0;
LAB_00594c94:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

