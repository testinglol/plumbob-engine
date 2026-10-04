
void FUN_00410173(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x148);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_004ede0b();
  }
  if (*(undefined4 **)(extraout_ECX + 0x148) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0x148))(1);
  }
  if (*(int *)(extraout_ECX + 0x140) != 0) {
    FUN_00420028(*(int *)(extraout_ECX + 0x140));
    *(undefined4 *)(extraout_ECX + 0x140) = 0;
  }
  if (*(int *)(extraout_ECX + 0x144) != 0) {
    FUN_00410204(1);
    *(undefined4 *)(extraout_ECX + 0x144) = 0;
  }
  uVar2 = *(undefined4 *)(extraout_ECX + 300);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

