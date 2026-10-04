
undefined4 FUN_004e1df3(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  iVar1 = FUN_0042612b(&local_8,0,0xffffffff);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  (**(code **)(*(int *)**(undefined4 **)(local_8 + 8) + 0x10))();
  (**(code **)(*(int *)**(undefined4 **)(local_8 + 8) + 0x14))();
  uVar2 = FUN_00401f73();
  uVar2 = FUN_004e988f(uVar2);
  return uVar2;
}

