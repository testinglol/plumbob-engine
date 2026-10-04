
void FUN_00436af7(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
            (unaff_EBP + -0x24,unaff_EBP + -0x20,unaff_EBP + -0x1c);
  uVar3 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                       *(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(*(int *)(extraout_ECX + 0x70) + 100) = uVar3;
  if (*(char *)(extraout_ECX + 0x6d) == '\0') {
    uVar3 = FUN_005d49d6();
    uVar4 = FUN_004096c2(uVar3);
    uVar3 = FUN_005d4916(uVar4,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00523771(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  cVar2 = FUN_005a5e72();
  if (cVar2 != '\0') {
    FUN_005de822(extraout_ECX + 0x58);
    uVar3 = 0;
    if (*(int *)(unaff_EBP + -0x2c) == *(int *)(unaff_EBP + -0x34)) {
      uVar4 = FUN_004096c2(0);
      FUN_00523b25(uVar4,uVar3);
    }
    else {
      iVar5 = unaff_EBP + -0x34;
      uVar4 = FUN_004096c2(iVar5);
      FUN_00523b65(uVar4,iVar5,uVar3);
    }
  }
  cVar2 = *(char *)(extraout_ECX + 0x69);
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = 2;
  if (cVar2 == '\0') {
    if (*(char *)(extraout_ECX + 0x6c) == '\0') {
      FUN_00523a25(2);
    }
    else {
      FUN_00523a33(2,0x1f);
    }
  }
  else {
    uVar3 = FUN_005d49d6();
    uVar4 = FUN_004096c2(uVar3);
    uVar3 = FUN_005d4916(uVar4,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0052386b(uVar3,2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  iVar5 = *(int *)(extraout_ECX + 0x50);
  *(int *)(unaff_EBP + -0x14) = iVar5;
  if ((iVar5 == 1) || (iVar5 == 2)) {
    uVar3 = FUN_005d49d6();
    uVar4 = FUN_004096c2(uVar3);
    uVar3 = FUN_005d4916(uVar4,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_0052386b(uVar3,3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 3;
    if (*(int *)(unaff_EBP + -0x14) == 2) {
      uVar3 = FUN_005d49d6();
      uVar4 = FUN_004096c2(uVar3);
      uVar3 = FUN_005d4916(uVar4,uVar3);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      FUN_0052386b(uVar3,4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -0x18) = 4;
    }
  }
  uVar3 = FUN_005d49d6();
  uVar4 = FUN_004096c2(uVar3);
  uVar3 = FUN_005d4916(uVar4,uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_00523be3(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (*(int *)(unaff_EBP + -0x14) == 3) {
    uVar3 = FUN_005d4956(s_Hello_world_006c29c0);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_00523937(uVar3,999);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if (((*(int *)(unaff_EBP + -0x14) != 4) && (*(int *)(unaff_EBP + -0x14) != 3)) &&
     (*(char *)(extraout_ECX + 0x6c) == '\0')) {
    FUN_00523ba5(*(undefined4 *)(unaff_EBP + -0x18),40000);
  }
  FUN_00523afc(2,0xd);
  FUN_00523afc(*(undefined4 *)(unaff_EBP + -0x18),0x1b);
  if (*(char *)(unaff_EBP + -0xd) != '\0') {
    FUN_00523afc(2,0x20);
  }
  if (*(char *)(extraout_ECX + 0x6d) != '\0') {
    (**(code **)(**(int **)(extraout_ECX + 0x70) + 0x5c))(1,200);
  }
  if (*(char *)(extraout_ECX + 0x6e) != '\0') {
    *(undefined4 *)(*(int *)(extraout_ECX + 0x70) + 0x140) = 0x3f99999a;
  }
  piVar1 = *(int **)(*(int *)(DAT_006f2a08 + 0x84) + 0x11ac);
  if ((piVar1 != (int *)0x0) && (*(char *)(extraout_ECX + 0x6c) != '\0')) {
    cVar2 = FUN_004ff877(unaff_EBP + -0x44);
    if (cVar2 == '\0') {
      *(int *)(unaff_EBP + -0x44) = piVar1[0x1f];
      *(int *)(unaff_EBP + -0x40) = piVar1[0x20];
      iVar5 = piVar1[0x22];
      *(int *)(unaff_EBP + -0x3c) = piVar1[0x21];
      *(int *)(unaff_EBP + -0x38) = iVar5;
    }
    FUN_00523724(1,unaff_EBP + -0x44);
    (**(code **)(**(int **)(extraout_ECX + 0x70) + 0x98))();
    (**(code **)(*piVar1 + 0x94))();
    FUN_00436e16();
    FUN_004ffa7e(*(undefined4 *)(extraout_ECX + 0x70));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

