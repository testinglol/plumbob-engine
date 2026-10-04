
bool FUN_005bf165(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 0x10))();
  if (cVar2 != '\0') {
    (**(code **)(*extraout_ECX + 0x14))();
  }
  if (DAT_006fe590 == (code *)0x0) {
    FUN_004dc9d9();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005c0622(extraout_ECX + 1,unaff_EBP + -0x2c,0xffffffff);
    iVar4 = DeleteFileA(*(LPCSTR *)(unaff_EBP + -0x28));
    if (iVar4 == 0) {
      FUN_005bfa81();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x2c) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    puVar3 = (undefined4 *)FUN_005be30b(unaff_EBP + -0x18,extraout_ECX + 1);
    uVar1 = *puVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar4 = (*DAT_006fe590)(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bdc4a();
    if (iVar4 == 0) {
      FUN_005bfa81();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4 != 0;
}

