
undefined4 FUN_005b936f(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x6c) = extraout_ECX;
  FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b9589(unaff_EBP + -0x1c);
  cVar1 = FUN_005b9bbe(*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0x20);
  if ((cVar1 == '\0') || (*(char *)(*(int *)(unaff_EBP + -0x20) + 0x10) == '\0')) {
    pvVar3 = operator_new(0x80);
    *(void **)(unaff_EBP + -0x44) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (*(int *)(unaff_EBP + -0x44) == 0) {
      *(undefined4 *)(unaff_EBP + -0x74) = 0;
    }
    else {
      uVar4 = FUN_005be7fe(*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x74) = uVar4;
    }
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x74);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x40);
    if (*(char *)(unaff_EBP + 0xc) == '\0') {
      uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1,2,1);
      *(undefined1 *)(unaff_EBP + -0x10) = uVar2;
    }
    else {
      uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(3,2,1);
      *(undefined1 *)(unaff_EBP + -0x10) = uVar2;
    }
    if (*(char *)(unaff_EBP + -0x10) == '\0') {
      *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x58);
      if (*(int *)(unaff_EBP + -0x54) == 0) {
        *(undefined4 *)(unaff_EBP + -0x7c) = 0;
      }
      else {
        uVar4 = (**(code **)(**(int **)(unaff_EBP + -0x54) + 0x80))(1);
        *(undefined4 *)(unaff_EBP + -0x7c) = uVar4;
      }
      *(undefined4 *)(unaff_EBP + -0x5c) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar4 = *(undefined4 *)(unaff_EBP + -0x5c);
    }
    else {
      pvVar3 = operator_new(0x24);
      *(void **)(unaff_EBP + -0x4c) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (*(int *)(unaff_EBP + -0x4c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x78) = 0;
      }
      else {
        uVar4 = *(undefined4 *)(unaff_EBP + -0x6c);
        uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
        uVar6 = 0;
        uVar5 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x1c))(0,uVar7,uVar4);
        uVar4 = FUN_005b8e2b(*(undefined4 *)(unaff_EBP + -0x24),0,uVar5,uVar6,uVar7,uVar4);
        *(undefined4 *)(unaff_EBP + -0x78) = uVar4;
      }
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x78);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x48);
      FUN_005d499c(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
    }
  }
  else if (*(char *)(unaff_EBP + 0xc) == '\0') {
    pvVar3 = operator_new(0x24);
    *(void **)(unaff_EBP + -0x38) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (*(int *)(unaff_EBP + -0x38) == 0) {
      *(undefined4 *)(unaff_EBP + -0x70) = 0;
    }
    else {
      uVar4 = FUN_005b8e2b(**(undefined4 **)(unaff_EBP + -0x20),
                           *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 4),
                           *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xc),1,0,
                           *(undefined4 *)(unaff_EBP + -0x6c));
      *(undefined4 *)(unaff_EBP + -0x70) = uVar4;
    }
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x70);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x34);
    FUN_005d499c(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar4 = *(undefined4 *)(unaff_EBP + -0x3c);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar4 = *(undefined4 *)(unaff_EBP + -0x30);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

