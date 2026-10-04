
void FUN_00479318(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -0x13) = 0;
  *(undefined1 *)(unaff_EBP + -0x12) = 0;
  uVar5 = *(uint *)(unaff_EBP + 8) & 3;
  *(uint *)(extraout_ECX + 0x84) = uVar5;
  uVar3 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0xf) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  cVar4 = (char)uVar3;
  *(char *)(unaff_EBP + -0x10) = cVar4 + -1;
  *(undefined1 *)(unaff_EBP + -0x16) = 0;
  *(char *)(unaff_EBP + -0x18) = cVar4 + -1;
  *(char *)(unaff_EBP + -0x17) = cVar4 + -1;
  *(undefined1 *)(unaff_EBP + 8) = 0;
  *(undefined1 *)(unaff_EBP + 10) = 0;
  *(char *)(unaff_EBP + 9) = cVar4 + -1;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00434ffd(uVar5);
  FUN_00434ffd(*(undefined4 *)(extraout_ECX + 0x84));
  FUN_00434ffd(*(undefined4 *)(extraout_ECX + 0x84));
  FUN_00434ffd(*(undefined4 *)(extraout_ECX + 0x84));
  iVar6 = (int)*(char *)(unaff_EBP + -0x10);
  iVar8 = (int)*(char *)(unaff_EBP + -0x14);
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  *(int *)(unaff_EBP + -0x20) = iVar6;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar8 <= iVar6) {
    piVar7 = (int *)(unaff_EBP + -0x1c);
  }
  iVar9 = (int)*(char *)(unaff_EBP + -0x18);
  piVar1 = (int *)(extraout_ECX + 0x70);
  *piVar1 = *piVar7;
  iVar2 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = iVar9;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar2 <= iVar9) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  iVar2 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = (int)*(char *)(unaff_EBP + 8);
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar2 <= *(char *)(unaff_EBP + 8)) {
    piVar7 = piVar1;
  }
  iVar2 = *piVar7;
  *(int *)(unaff_EBP + -0x20) = iVar6;
  *piVar1 = iVar2;
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar6 <= iVar8) {
    piVar7 = (int *)(unaff_EBP + -0x1c);
  }
  piVar1 = (int *)(extraout_ECX + 0x74);
  *piVar1 = *piVar7;
  iVar6 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = iVar9;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar9 <= iVar6) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  iVar6 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = (int)*(char *)(unaff_EBP + 8);
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (*(char *)(unaff_EBP + 8) <= iVar6) {
    piVar7 = piVar1;
  }
  iVar6 = (int)*(char *)(unaff_EBP + -0xf);
  iVar8 = (int)*(char *)(unaff_EBP + -0x13);
  *piVar1 = *piVar7;
  *(int *)(unaff_EBP + -0x20) = iVar6;
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar8 <= iVar6) {
    piVar7 = (int *)(unaff_EBP + -0x1c);
  }
  iVar9 = (int)*(char *)(unaff_EBP + -0x17);
  piVar1 = (int *)(extraout_ECX + 0x78);
  *piVar1 = *piVar7;
  iVar2 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = iVar9;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar2 <= iVar9) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  iVar2 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = (int)*(char *)(unaff_EBP + 9);
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar2 <= *(char *)(unaff_EBP + 9)) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  *(int *)(unaff_EBP + -0x20) = iVar6;
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar6 <= iVar8) {
    piVar7 = (int *)(unaff_EBP + -0x1c);
  }
  piVar1 = (int *)(extraout_ECX + 0x7c);
  *piVar1 = *piVar7;
  iVar6 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = iVar9;
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (iVar9 <= iVar6) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  iVar6 = *piVar1;
  *(int *)(unaff_EBP + -0x20) = (int)*(char *)(unaff_EBP + 9);
  piVar7 = (int *)(unaff_EBP + -0x20);
  if (*(char *)(unaff_EBP + 9) <= iVar6) {
    piVar7 = piVar1;
  }
  *piVar1 = *piVar7;
  if ((*(int *)(extraout_ECX + 0x54) != 0) && (*(char *)(unaff_EBP + 0xc) == '\0')) {
    FUN_0054066a(*(undefined4 *)(extraout_ECX + 0x84));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

