
undefined1 FUN_00601c3c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*(int *)(extraout_ECX + 8) + 4))();
  puVar2 = (undefined4 *)**(undefined4 **)(extraout_ECX + 4);
  do {
    if (puVar2 == *(undefined4 **)(extraout_ECX + 4)) {
      uVar3 = 0;
LAB_00601c71:
      iVar1 = *(int *)(extraout_ECX + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      (**(code **)(iVar1 + 8))();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar3;
    }
    if (puVar2[2] == *(int *)(unaff_EBP + 8)) {
      uVar3 = 1;
      goto LAB_00601c71;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

