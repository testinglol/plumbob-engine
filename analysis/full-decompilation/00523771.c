
void FUN_00523771(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar2 = DAT_006f2aac;
  pvVar3 = operator_new(0x110);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005e9913();
  }
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x39] = iVar4;
  *(undefined4 *)(iVar4 + 8) = 0xffffffff;
  (**(code **)(*(int *)extraout_ECX[0x39] + 0x9c))(uVar1);
  (**(code **)(*(int *)(extraout_ECX[0x39] + 0xd4) + 0x18))(uVar2);
  (**(code **)(*(int *)(extraout_ECX[0x39] + 0xd4) + 0x1c))(0);
  (**(code **)(*(int *)(extraout_ECX[0x39] + 0xd4) + 0x14))(0);
  (**(code **)(*(int *)(extraout_ECX[0x39] + 0xd4) + 0xc))(2,0);
  (*(code *)**(undefined4 **)(extraout_ECX[0x39] + 0xd4))();
  (**(code **)(*(int *)(extraout_ECX[0x39] + 0xd4) + 0x20))(0,0);
  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

