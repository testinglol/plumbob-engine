
undefined1 FUN_0060388c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  int iStack_1c;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  iVar2 = *(int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x14) = (int *)(extraout_ECX + 0xac);
  iStack_1c = 0x6038b9;
  (**(code **)(iVar2 + 4))();
  iStack_1c = unaff_EBP + 8;
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00601485(unaff_EBP + -0x10);
  iStack_1c = *(int *)(unaff_EBP + -0x10);
  if (iStack_1c != *(int *)(extraout_ECX + 0x78)) {
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      puVar1 = (undefined4 *)(iStack_1c + 0x14);
      iStack_1c = 0x6038e6;
      (**(code **)(*(int *)*puVar1 + 4))();
      iStack_1c = *(int *)(unaff_EBP + -0x10);
    }
    *(int **)(unaff_EBP + 0xc) = &iStack_1c;
    FUN_006043cb();
    uVar3 = 1;
  }
  iVar2 = *(int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_1c = 0x603905;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

