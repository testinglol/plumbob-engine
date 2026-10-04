
undefined1 FUN_00603abd(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*(int *)(extraout_ECX + 0xac) + 4))();
  iVar1 = *(int *)(extraout_ECX + 0x78);
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != iVar1) {
    do {
      if (*(int *)(*(int *)(unaff_EBP + -0x10) + 0x14) == *(int *)(unaff_EBP + 8)) {
        uVar3 = 1;
        goto LAB_00603b08;
      }
      FUN_0041674f();
    } while (*(int *)(unaff_EBP + -0x10) != *(int *)(extraout_ECX + 0x78));
  }
  uVar3 = 0;
LAB_00603b08:
  iVar1 = *(int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

