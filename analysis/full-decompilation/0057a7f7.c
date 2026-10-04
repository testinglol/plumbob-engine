
undefined4 FUN_0057a7f7(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  short sVar5;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  cVar1 = *(char *)(extraout_ECX + 0x14);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  if (cVar1 == '\0') {
    uVar4 = 1;
  }
  else {
    if (DAT_006f6434 != '\0') {
      _strncmp(s_footstep_006cf3bc,*(char **)(unaff_EBP + 8),8);
    }
    iVar3 = _strncmp(s_footstep_006cf3bc,*(char **)(unaff_EBP + 8),8);
    sVar5 = (short)*(undefined4 *)(unaff_EBP + 0xc);
    if ((iVar3 == 0) && (0 < sVar5)) {
      *(int *)(extraout_ECX + 0x10) = (int)sVar5;
    }
    if (sVar5 == -2) {
      if (*(int *)(extraout_ECX + 0x10) == 0) {
        uVar4 = 0;
        goto LAB_0057a995;
      }
      sVar5 = *(short *)(extraout_ECX + 0x10);
    }
    FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d4d37();
    if (DAT_006c9f93 == '\0') {
      InterlockedIncrement(&DAT_006f29fc);
      (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xc) + 0x10) + 4))();
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar2 = FUN_0057348c(unaff_EBP + -0x20,(int)sVar5,0,0);
      *(undefined1 *)(unaff_EBP + 0xb) = uVar2;
      uVar4 = FUN_0057a965();
      return uVar4;
    }
    iVar3 = FUN_005d5f70();
    if (iVar3 == 0) {
      iVar3 = *(int *)(extraout_ECX + 0xc);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      (**(code **)(**(int **)(iVar3 + 0x10) + 4))();
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar2 = FUN_0057348c(unaff_EBP + -0x20,(int)sVar5,0,0);
      *(undefined1 *)(unaff_EBP + 0xb) = uVar2;
      uVar4 = FUN_0057a8de();
      return uVar4;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar4 = 1;
  }
LAB_0057a995:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

