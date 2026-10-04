
void FUN_0053d15c(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  if ((*(byte *)(extraout_ECX + 8) & 0x44) != 0) {
    pvVar1 = operator_new(0x5c);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0053d7f2();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x18) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + 1;
      if ((*(byte *)(extraout_ECX + 8) & 4) == 0) {
        uVar3 = 5;
      }
      else {
        uVar3 = 1;
      }
      FUN_0053f876(extraout_ECX,uVar3);
      iVar2 = (int)*(char *)(extraout_ECX + 2);
      uVar3 = *(undefined4 *)(extraout_ECX + 0x18);
      FUN_00540a5b(uVar3,iVar2);
      FUN_00540b60(uVar3,iVar2);
    }
  }
  if ((*(byte *)(extraout_ECX + 8) & 0x88) != 0) {
    pvVar1 = operator_new(0x5c);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0053d7f2();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x1c) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x58) + 1;
      if ((*(byte *)(extraout_ECX + 8) & 8) == 0) {
        uVar3 = 6;
      }
      else {
        uVar3 = 3;
      }
      FUN_0053f876(extraout_ECX,uVar3);
      iVar2 = (int)*(char *)(extraout_ECX + 2);
      uVar3 = *(undefined4 *)(extraout_ECX + 0x1c);
      FUN_00540a5b(uVar3,iVar2);
      FUN_00540b60(uVar3,iVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

