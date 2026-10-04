
void FUN_0048a5a5(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x30) != 0) {
    cVar1 = FUN_00484ba0();
    if (cVar1 == '\0') {
      FUN_00492b26();
      *(undefined1 **)(unaff_EBP + -0x14) = &stack0xffffffe8;
      iVar2 = FUN_00488924();
      if (iVar2 != 0) {
        FUN_0048a829(unaff_EBP + 8,unaff_EBP + -0x10);
        uVar3 = FUN_00492b26();
        *(char *)(unaff_EBP + 0x16) = (char)uVar3;
        *(char *)(unaff_EBP + 0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
        *(char *)(unaff_EBP + 0x15) = (char)(*(int *)(unaff_EBP + 8) >> 4);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_0048a909(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),uVar3,
                     *(undefined4 *)(unaff_EBP + -0x10));
        cVar1 = FUN_00493897(unaff_EBP + 0x14,*(undefined4 *)(extraout_ECX + 0x3c),
                             *(undefined4 *)(unaff_EBP + -0x10),0);
        if (cVar1 != '\0') {
          FUN_004939fc(unaff_EBP + 0x14,*(undefined4 *)(extraout_ECX + 0x3c),
                       *(undefined4 *)(unaff_EBP + -0x10));
          FUN_00492b26();
          FUN_00540a5b();
          FUN_00540ecf();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
    }
    iVar2 = *(int *)(extraout_ECX + 0x30);
    if ((*(int *)(iVar2 + 0x28) - *(int *)(iVar2 + 0x24)) / 0x34 != 0) {
      if ((((1 < (*(int *)(iVar2 + 0x28) - *(int *)(iVar2 + 0x24)) / 0x34) &&
           (iVar2 = *(int *)(extraout_ECX + 0x3c), iVar2 != 1)) && (iVar2 != 3)) && (iVar2 != 2)) {
        FUN_0057a7f7(s_UI_bld_dragtool_mouseup_006c5f38);
      }
      FUN_0049341e();
      FUN_00485b4c();
      pvVar4 = operator_new(0x44);
      *(void **)(unaff_EBP + -0x14) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004935b7();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 0x30) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
        FUN_00493b7b();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x5c) = 1;
  return;
}

