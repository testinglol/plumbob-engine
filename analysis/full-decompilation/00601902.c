
undefined4 FUN_00601902(void)

{
  int iVar1;
  int *piVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  undefined4 *puStack_24;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x1c) = (int *)(extraout_ECX + 8);
  puStack_24 = (undefined4 *)0x601929;
  (**(code **)(iVar1 + 4))();
  piVar2 = *(int **)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  puStack_24 = (undefined4 *)*piVar2;
  if (puStack_24 != piVar2) {
    do {
      piVar2 = *(int **)(unaff_EBP + 8);
      if ((((puStack_24[2] == *piVar2) && (puStack_24[3] == piVar2[1])) &&
          (puStack_24[4] == piVar2[2])) && (puStack_24[5] == piVar2[3])) {
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        puVar3 = (undefined4 *)*puStack_24;
        *(undefined4 ***)(unaff_EBP + -0x14) = &puStack_24;
        FUN_00602846(unaff_EBP + -0x18);
      }
      else {
        puVar3 = (undefined4 *)*puStack_24;
      }
      puStack_24 = puVar3;
    } while (puVar3 != *(undefined4 **)(extraout_ECX + 4));
  }
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puStack_24 = (undefined4 *)0x60198c;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

