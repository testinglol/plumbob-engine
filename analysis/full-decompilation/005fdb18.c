
undefined1 FUN_005fdb18(void)

{
  char cVar1;
  int iVar2;
  int *extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar2 = *(int *)(unaff_EBP + 8);
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  if (iVar2 != extraout_ECX[4]) {
    cVar1 = (**(code **)(*extraout_ECX + 0x24))(iVar2);
    if (cVar1 == '\0') goto LAB_005fdb8a;
    extraout_ECX[4] = iVar2;
    (**(code **)(extraout_ECX[5] + 0x90))(iVar2);
    cVar1 = (**(code **)(*extraout_ECX + 0x2c))(unaff_EBP + -0x18,iVar2);
    if (cVar1 == '\0') goto LAB_005fdb8a;
    iVar2 = FUN_00637627(0,*(undefined4 *)(unaff_EBP + -0x18));
    if (iVar2 != 0) {
      FUN_0063c8e8(0xfffffffc);
    }
  }
  uVar3 = 1;
LAB_005fdb8a:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

