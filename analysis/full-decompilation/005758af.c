
int FUN_005758af(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iStack_24;
  int iStack_20;
  
  FUN_00634c24();
  iStack_24 = unaff_EBP + -0x10;
  iStack_20 = *(undefined4 *)(unaff_EBP + 8);
  FUN_00576160();
  if (*(int *)(unaff_EBP + -0x10) != *extraout_ECX) {
    iStack_20 = *(int *)(unaff_EBP + -0x10) + 0x10;
    iStack_24 = *(int *)(unaff_EBP + 8);
    cVar2 = FUN_00430155();
    if (cVar2 == '\0') goto LAB_00575928;
  }
  iStack_20 = *(undefined4 *)(unaff_EBP + 8);
  iStack_24 = 0x5758f1;
  FUN_005b86bd();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_20 = unaff_EBP + -0x24;
  *(int **)(unaff_EBP + 8) = &iStack_24;
  FUN_00602c56(unaff_EBP + -0x10);
  puVar3 = (undefined4 *)FUN_00575b49(unaff_EBP + -0x14);
  uVar1 = *puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  iStack_20 = 0x575928;
  FUN_005b8770();
LAB_00575928:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(int *)(unaff_EBP + -0x10) + 0x1c;
}

