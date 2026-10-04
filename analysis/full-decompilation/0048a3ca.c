
void FUN_0048a3ca(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  if (*(char *)(extraout_ECX + 0x5c) != '\0') goto LAB_0048a594;
  cVar2 = FUN_00484ba0(unaff_EBP + 8);
  if (cVar2 != '\0') {
    FUN_0057a7f7(s_UI_error_006c5e80,0xfffffffc);
    goto LAB_0048a594;
  }
  iVar3 = FUN_0048a777();
  if (iVar3 != *(int *)(extraout_ECX + 0x3c)) {
    *(int *)(extraout_ECX + 0x3c) = iVar3;
    if (*(int *)(extraout_ECX + 0x30) != 0) {
      FUN_00493875();
    }
    FUN_0048a9df(*(undefined4 *)(extraout_ECX + 0x3c));
  }
  DAT_006e57d8 = *(undefined4 *)(unaff_EBP + 8);
  uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(extraout_ECX + 0x40) = DAT_006e57d8;
  *(undefined4 *)(extraout_ECX + 0x44) = uVar4;
  puVar1 = *(undefined4 **)(unaff_EBP + 0x14);
  puVar5 = puVar1;
  puVar6 = (undefined4 *)(extraout_ECX + 0x48);
  for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_006e57dc = *(undefined4 *)(unaff_EBP + 0xc);
  if (*(int *)(extraout_ECX + 0x30) == 0) goto LAB_0048a594;
  puVar1 = puVar1 + 3;
  FUN_0048a829(unaff_EBP + 8,unaff_EBP + -0x14,puVar1);
  uVar4 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  *(char *)(unaff_EBP + 0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + 0x15) = (char)(*(int *)(unaff_EBP + 8) >> 4);
  *(char *)(unaff_EBP + 0x16) = (char)uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0048a909(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),uVar4,
               *(undefined4 *)(unaff_EBP + -0x14),1);
  iVar3 = *(int *)(extraout_ECX + 0x3c);
  if ((iVar3 == 2) || (iVar3 == 3)) {
    cVar2 = FUN_0048aa53(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + -0x18),
                         *(undefined4 *)(unaff_EBP + -0x14),*puVar1,iVar3);
    if (cVar2 != '\0') {
      if (*(int *)(extraout_ECX + 0x3c) == 3) {
        FUN_00492cca();
      }
      uVar4 = FUN_00492b26();
      FUN_00540a5b(uVar4);
      FUN_00540ecf(uVar4);
      goto LAB_0048a578;
    }
    FUN_00493875();
    *(undefined1 *)(*(int *)(extraout_ECX + 0x30) + 0x40) = 1;
  }
  else {
    cVar2 = FUN_00493897(unaff_EBP + 0x14,iVar3,*(undefined4 *)(unaff_EBP + -0x14),0,
                         unaff_EBP + -0x18);
    if (cVar2 == '\0') {
      iVar3 = *(int *)(unaff_EBP + -0x18);
      if (iVar3 != 0) {
        *(int *)(extraout_ECX + 0x60) = iVar3;
        FUN_004864ed(iVar3,0xffffffff);
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
      }
      FUN_00493b85();
LAB_0048a578:
      if (*(char *)(unaff_EBP + -0xd) != '\0') goto LAB_0048a594;
    }
    else {
      FUN_004939fc(unaff_EBP + 0x14,*(undefined4 *)(extraout_ECX + 0x3c),
                   *(undefined4 *)(unaff_EBP + -0x14),0);
      if (*(int *)(extraout_ECX + 0x3c) == 1) {
        FUN_00492cca();
      }
      uVar4 = FUN_00492b26();
      FUN_00540a5b(uVar4);
      FUN_00540ecf(uVar4);
    }
  }
  if (*(int *)(extraout_ECX + 0x60) == 0) {
    uVar4 = FUN_00492d2c();
    FUN_004864ed(0x1a,uVar4);
  }
LAB_0048a594:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

