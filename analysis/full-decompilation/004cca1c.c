
void FUN_004cca1c(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int local_3c;
  int local_38;
  
  FUN_00634c24();
  iVar6 = *(int *)(extraout_ECX + 0xd8);
  local_38 = 0x4cca44;
  iVar3 = FUN_004096c2();
  if (iVar6 != iVar3) {
    iVar6 = *(int *)(extraout_ECX + 0xd8);
    local_38 = 0x4cca54;
    iVar3 = FUN_004096c2();
    if (iVar6 != iVar3) goto LAB_004ccbf9;
  }
  local_38 = *(undefined4 *)(extraout_ECX + 0xdc);
  local_3c = 0x4cca6a;
  FUN_005a5dea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  local_38 = 0x4cca77;
  cVar2 = FUN_005a5e72();
  if ((cVar2 == '\0') && (*(int *)(extraout_ECX + 0x194) != 0)) {
    local_38 = unaff_EBP + -0x10;
    local_3c = 0x4cca8e;
    cVar2 = FUN_004cc7f7();
    if (cVar2 != '\0') {
      *(int **)(unaff_EBP + -0x14) = &local_3c;
      local_3c = 0;
      local_38 = 0;
      uVar4 = FUN_004096c2();
      FUN_005e4fb5(uVar4);
    }
  }
  local_38 = 0x4ccab6;
  cVar2 = FUN_005a5e72();
  if (cVar2 != '\0') {
    iVar6 = *(int *)(extraout_ECX + 0xf0);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if ((1 < iVar6) &&
       ((*(int *)(extraout_ECX + 0xe0) != 0 || (*(char *)(extraout_ECX + 0x169) != '\0')))) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    local_38 = 0x4ccaea;
    iVar5 = FUN_004096c2();
    iVar6 = *(int *)(iVar5 + 0x14);
    *(int *)(unaff_EBP + -0x34) = iVar6;
    iVar3 = *(int *)(extraout_ECX + 0xf0);
    iVar1 = *(int *)(iVar5 + 0x18);
    *(int *)(unaff_EBP + -0x30) = iVar1;
    iVar7 = *(int *)(iVar5 + 0x1c);
    *(int *)(unaff_EBP + -0x2c) = iVar7;
    iVar5 = *(int *)(iVar5 + 0x20);
    *(int *)(unaff_EBP + -0x28) = iVar5;
    if (1 < iVar3) {
      *(int *)(unaff_EBP + -0x2c) = iVar7 / 2;
    }
    *(int *)(unaff_EBP + -0x24) = iVar6;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x2c);
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar3 = *(int *)(unaff_EBP + -0x2c) - iVar6;
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar3;
      *(int *)(unaff_EBP + -0x34) = iVar6 + iVar3;
    }
    iVar7 = (((*(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80)) - iVar5) + iVar1) / 2;
    iVar6 = *(int *)(extraout_ECX + 0x1c);
    iVar3 = (((*(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c)) -
             *(int *)(unaff_EBP + -0x2c)) + *(int *)(unaff_EBP + -0x34)) / 2;
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar3;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar3;
    iVar3 = *(int *)(extraout_ECX + 0x20);
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar6;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar6;
    *(int *)(unaff_EBP + -0x20) = iVar1 + iVar7 + iVar3;
    *(int *)(unaff_EBP + -0x18) = iVar5 + iVar7 + iVar3;
    local_38 = 0x4ccb84;
    iVar6 = FUN_004096c2();
    if (*(int *)(iVar6 + 0x60) == 0) {
      local_38 = 0x10;
      local_3c = 0x4ccbbd;
      cVar2 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x20))();
      if (cVar2 != '\0') {
        local_38 = 0;
        iVar6 = **(int **)(extraout_ECX + 0x5c);
        local_3c = unaff_EBP + -0x24;
        uVar4 = FUN_004096c2(unaff_EBP + -0x34);
        (**(code **)(iVar6 + 0x9c))(uVar4);
        (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x24))(0x10);
      }
    }
    else {
      local_38 = 0x4ccb93;
      iVar6 = FUN_004096c2();
      local_3c = unaff_EBP + -0x34;
      local_38 = 0;
      FUN_004ba1dc(*(undefined4 *)(extraout_ECX + 0x5c),unaff_EBP + -0x24,
                   *(undefined4 *)(extraout_ECX + 0xdc),*(undefined4 *)(iVar6 + 0x60));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  local_38 = 0x4ccbf9;
  FUN_005a5e09();
LAB_004ccbf9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

