
void FUN_0048521a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar3 = DAT_006e57e4;
  iVar2 = DAT_006e57e0;
  iVar5 = DAT_006e57dc;
  iVar1 = DAT_006e57d8;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(char *)(unaff_EBP + -0x10) = (char)(iVar5 >> 4);
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(char *)(unaff_EBP + -0xf) = (char)(iVar1 >> 4);
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)(unaff_EBP + 8) != '\0') {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    iVar5 = iVar3;
  }
  pcVar4 = (char *)(extraout_ECX + 0x4c);
  *pcVar4 = (char)(iVar3 >> 4);
  *(char *)(extraout_ECX + 0x4d) = (char)(iVar2 >> 4);
  *(undefined1 *)(extraout_ECX + 0x4e) = 1;
  if (iVar5 < iVar3) {
    if (*(int *)(unaff_EBP + -0x1c) < iVar2) {
      *pcVar4 = *pcVar4 + '\x01';
      *(char *)(extraout_ECX + 0x4d) = *(char *)(extraout_ECX + 0x4d) + '\x01';
      goto LAB_004852aa;
    }
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    if (*(int *)(unaff_EBP + -0x1c) < iVar2) {
      *(char *)(extraout_ECX + 0x4d) = *(char *)(extraout_ECX + 0x4d) + '\x01';
      *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
      goto LAB_004852aa;
    }
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
  }
  *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + '\x01';
LAB_004852aa:
  iVar1 = *(int *)(unaff_EBP + -0x14);
  FUN_00490dec(*(undefined4 *)(iVar1 + 0x50),pcVar4);
  FUN_00490dec(*(undefined4 *)(iVar1 + 0x54),unaff_EBP + -0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

