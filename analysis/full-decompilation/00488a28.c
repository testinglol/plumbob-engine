
void FUN_00488a28(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x3d) != '\0') goto LAB_00488bc3;
  uVar4 = FUN_00433116(unaff_EBP + 8,1);
  cVar2 = FUN_00434d5c(uVar4);
  if (cVar2 != '\0') goto LAB_00488bc3;
  puVar6 = *(undefined4 **)(unaff_EBP + 0x14);
  *(undefined4 *)(extraout_ECX + 0x40) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x44) = *(undefined4 *)(unaff_EBP + 0xc);
  puVar7 = (undefined4 *)(extraout_ECX + 0x48);
  for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar5 = FUN_00488da4();
  if (iVar5 != *(int *)(extraout_ECX + 0x34)) {
    *(int *)(extraout_ECX + 0x34) = iVar5;
    FUN_00489b92(iVar5);
    if (*(int *)(extraout_ECX + 0x30) != 0) {
      FUN_0048830b();
      *(undefined1 *)(extraout_ECX + 0x3e) = 0;
    }
  }
  uVar4 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  iVar5 = *(int *)(extraout_ECX + 0x34);
  if ((iVar5 == 0) || (iVar5 == 1)) {
    if (*(int *)(extraout_ECX + 0x30) != 0) {
      FUN_0048830b();
    }
    iVar5 = DAT_006e57e0;
    DAT_006e57d8 = *(undefined4 *)(unaff_EBP + 8);
    if (*(int *)(extraout_ECX + 0x34) == 0) {
      uVar4 = *(undefined4 *)(extraout_ECX + 0x38);
    }
    else {
      uVar4 = 0;
    }
    DAT_006e57dc = *(int *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + 0x14) = DAT_006e57d8;
    iVar1 = DAT_006e57e4;
    *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) >> 4;
    cVar2 = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    if ((cVar2 == (char)(iVar1 >> 4)) && (*(char *)(unaff_EBP + 0x14) == (char)(iVar5 >> 4))) {
      cVar2 = FUN_00488de7(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + -0x18),uVar4,0,0);
      goto LAB_00488b57;
    }
    *(char *)(unaff_EBP + -0x10) = cVar2;
    *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(unaff_EBP + 0x14);
    *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar3 = FUN_00492b26();
    iVar5 = DAT_006e57e4;
    *(undefined1 *)(unaff_EBP + -0x12) = uVar3;
    *(char *)(unaff_EBP + -0x14) = (char)(iVar5 >> 4);
    *(char *)(unaff_EBP + -0x13) = (char)(DAT_006e57e0 >> 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    cVar2 = FUN_00489bba(unaff_EBP + -0x14,unaff_EBP + -0x10,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    cVar2 = '\x01' - (cVar2 != '\0');
    *(char *)(unaff_EBP + 0x17) = cVar2;
    if (cVar2 == '\0') goto LAB_00488bc3;
  }
  else {
    if ((iVar5 != 2) && (iVar5 != 3)) goto LAB_00488bc3;
    DAT_006e57d8 = *(undefined4 *)(unaff_EBP + 8);
    DAT_006e57dc = *(int *)(unaff_EBP + 0xc);
    uVar4 = 0;
    if (*(int *)(extraout_ECX + 0x34) == 2) {
      uVar4 = *(undefined4 *)(extraout_ECX + 0x38);
    }
    cVar2 = FUN_0048955c(unaff_EBP + 8,uVar4,*(undefined4 *)(*(int *)(unaff_EBP + 0x14) + 0xc));
LAB_00488b57:
    if (cVar2 != '\0') goto LAB_00488bc3;
  }
  if (*(int *)(extraout_ECX + 0x30) != 0) {
    FUN_0048830b();
  }
LAB_00488bc3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

