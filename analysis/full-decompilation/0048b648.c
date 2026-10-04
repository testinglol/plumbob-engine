
void FUN_0048b648(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00492d46(0);
  if (*(int *)(extraout_ECX + 0x5c) == 0) goto LAB_0048b72f;
  cVar1 = FUN_004972cb();
  if (cVar1 != '\0') {
    FUN_00495076();
    goto LAB_0048b72f;
  }
  if (*(char *)(*(int *)(extraout_ECX + 0x5c) + 0xe024) == '\0') {
    FUN_00494fb9();
    goto LAB_0048b72f;
  }
  if (*(int *)(extraout_ECX + 0x6c) == 1) {
LAB_0048b6ac:
    FUN_00492cca();
  }
  else {
    FUN_0057a7f7(s_UI_bld_dragtool_mouseup_006c5f38,0xfffffffc);
    if (*(int *)(extraout_ECX + 0x6c) == 1) goto LAB_0048b6ac;
  }
  uVar2 = FUN_00492b26();
  FUN_0040766a(0x91,uVar2);
  iVar3 = FUN_00492b26();
  if (iVar3 == 1) {
    iVar3 = FUN_00492b26();
    FUN_0040766a(0x91,iVar3 + 1);
  }
  FUN_00494488();
  FUN_0049341e(*(undefined4 *)(extraout_ECX + 0x5c));
  FUN_00485b4c();
  pvVar4 = operator_new(0xe068);
  *(void **)(unaff_EBP + -0x10) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00493f54(extraout_ECX);
  }
  *(int *)(extraout_ECX + 0x5c) = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  }
LAB_0048b72f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x70) = 1;
  return;
}

