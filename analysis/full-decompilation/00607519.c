
undefined1 FUN_00607519(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  undefined4 *puStack_1c;
  int iStack_18;
  
  FUN_00634c24();
  iStack_18 = unaff_EBP + -0x10;
  puStack_1c = (undefined4 *)0x607537;
  (**(code **)(*(int *)(extraout_ECX + 0x28) + 0x38))();
  iVar1 = *(int *)(extraout_ECX + 0x44);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 0x44);
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  puStack_1c = (undefined4 *)0x60754c;
  (**(code **)(iVar1 + 4))();
  puVar2 = *(undefined4 **)(extraout_ECX + 4);
  uVar3 = 0;
  puStack_1c = (undefined4 *)*puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    if (puStack_1c == puVar2) {
LAB_0060757c:
      iVar1 = *(int *)(extraout_ECX + 0x44);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      puStack_1c = (undefined4 *)0x607587;
      (**(code **)(iVar1 + 8))();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar3;
    }
    if (puStack_1c[2] == *(int *)(unaff_EBP + 8)) {
      *(undefined4 ***)(unaff_EBP + 8) = &puStack_1c;
      FUN_0060786f(unaff_EBP + 8);
      uVar3 = 1;
      goto LAB_0060757c;
    }
    puStack_1c = (undefined4 *)*puStack_1c;
  } while( true );
}

