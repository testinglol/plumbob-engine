
void FUN_00488bd4(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = FUN_00484ba0(unaff_EBP + 8);
  if (((cVar1 == '\0') && (*(char *)(extraout_ECX + 0x3c) != '\0')) &&
     (*(int *)(extraout_ECX + 0x30) != 0)) {
    FUN_0048830b();
    *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  }
  iVar3 = *(int *)(extraout_ECX + 0x30);
  if ((*(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24)) / 0x3c != 0) {
    if (((1 < (*(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24)) / 0x3c) &&
        (iVar3 = *(int *)(extraout_ECX + 0x34), iVar3 != 1)) && ((iVar3 != 3 && (iVar3 != 2)))) {
      FUN_0057a7f7(s_UI_bld_dragtool_mouseup_006c5f38,0xfffffffc);
    }
    if ((*(int *)(extraout_ECX + 0x34) == 1) || (*(int *)(extraout_ECX + 0x34) == 3)) {
      FUN_00492cca();
    }
    DAT_006e5780 = '\x01';
    FUN_0049341e(*(undefined4 *)(extraout_ECX + 0x30));
    FUN_00485b4c();
    pvVar2 = operator_new(0x34);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00488780(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x30) = iVar3;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
    }
  }
  *(undefined1 *)(extraout_ECX + 0x3f) = 0;
  *(undefined1 *)(extraout_ECX + 0x3d) = 1;
  if (DAT_006e5780 != '\0') {
    uVar4 = FUN_00492b26();
    FUN_0040766a(0x91,uVar4);
    iVar3 = FUN_00492b26();
    if (iVar3 == 1) {
      iVar3 = FUN_00492b26();
      FUN_0040766a(0x91,iVar3 + 1);
    }
    DAT_006e5780 = '\0';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

