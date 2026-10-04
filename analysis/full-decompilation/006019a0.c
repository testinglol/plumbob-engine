
undefined1 FUN_006019a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  undefined4 *puStack_18;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  puStack_18 = (undefined4 *)0x6019c6;
  (**(code **)(iVar1 + 4))();
  puVar2 = *(undefined4 **)(extraout_ECX + 4);
  uVar3 = 0;
  puStack_18 = (undefined4 *)*puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    if (puStack_18 == puVar2) {
LAB_006019f6:
      iVar1 = *(int *)(extraout_ECX + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      puStack_18 = (undefined4 *)0x601a01;
      (**(code **)(iVar1 + 8))();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar3;
    }
    if (puStack_18[2] == *(int *)(unaff_EBP + 8)) {
      *(undefined4 ***)(unaff_EBP + 8) = &puStack_18;
      FUN_00602846(unaff_EBP + 8);
      uVar3 = 1;
      goto LAB_006019f6;
    }
    puStack_18 = (undefined4 *)*puStack_18;
  } while( true );
}

