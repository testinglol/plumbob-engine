
void FUN_005772fa(void)

{
  int iVar1;
  int *piVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 *puStack_28;
  int iStack_24;
  int iStack_20;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x18) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  iStack_20 = 0x577325;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x28) = 0;
  iStack_20 = unaff_EBP + 8;
  puStack_28 = (undefined1 *)&iStack_24;
  *(int **)(unaff_EBP + -0x10) = &iStack_24;
  FUN_00575825();
  *(undefined1 ***)(unaff_EBP + -0x10) = &puStack_28;
  FUN_00602902(&puStack_28);
  piVar2 = (int *)FUN_00602c63(unaff_EBP + -0x14);
  iStack_20 = *piVar2;
  *(int **)(unaff_EBP + -0x14) = &iStack_20;
  iStack_24 = unaff_EBP + -0x14;
  puStack_28 = (undefined1 *)0x577370;
  FUN_00580b0a();
  piVar2 = (int *)(extraout_ECX + 4);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    iStack_20 = 0x57737d;
    (**(code **)(**(int **)(extraout_ECX + 0xc) + 0x18))();
    iStack_20 = 0x577385;
    FUN_005ed911();
    *(undefined4 *)(extraout_ECX + 0xc) = 0;
    iStack_20 = 0x577391;
    FUN_005771b0();
    iStack_20 = *(int *)(extraout_ECX + 0x10);
    if (iStack_20 != 0) {
      iStack_24 = 0x57739e;
      FUN_006321f0();
    }
    *(undefined4 *)(extraout_ECX + 0x10) = 0;
  }
  iVar1 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_20 = 0x5773b1;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

