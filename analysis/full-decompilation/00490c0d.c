
void FUN_00490c0d(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  void *pvVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = FUN_00492b26();
  if (iVar4 < 2) {
    FUN_00492d46(0);
    DAT_006e57e0 = *(undefined4 *)(unaff_EBP + 8);
    DAT_006e57e4 = *(undefined4 *)(unaff_EBP + 0xc);
    DAT_006e57dc = 0xfffffff0;
    DAT_006e57d8 = 0xfffffff0;
    *(undefined4 *)(extraout_ECX + 0x3c) = 0xffffffff;
    *(undefined1 *)(extraout_ECX + 0x2c) = 0;
    if (*(int *)(extraout_ECX + 0x44) == 0) {
      pvVar5 = operator_new(0x802c);
      *(void **)(unaff_EBP + 0xc) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_004921d3(extraout_ECX);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 0x44) = iVar4;
      if (iVar4 != 0) {
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
      }
    }
    if (*(int *)(extraout_ECX + 0x44) != 0) {
      FUN_0049242a();
    }
  }
  else {
    iVar4 = *(int *)(unaff_EBP + 8);
    iVar2 = *(int *)(unaff_EBP + 0xc);
    *(undefined4 *)(extraout_ECX + 0x38) = 8;
    *(char *)(unaff_EBP + 0xd) = (char)(iVar4 >> 4);
    uVar3 = FUN_00492b26();
    uVar1 = *(undefined1 *)(unaff_EBP + 0xd);
    *(char *)(extraout_ECX + 0x34) = (char)(iVar2 >> 4);
    *(undefined1 *)(extraout_ECX + 0x35) = uVar1;
    *(undefined1 *)(extraout_ECX + 0x36) = uVar3;
    FUN_00492c37();
    FUN_00491b2b();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

