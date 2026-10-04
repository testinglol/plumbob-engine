
undefined1 FUN_00537a9c(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_005dbf32();
    uVar2 = 0;
    if (cVar1 != '\0') {
      pvVar3 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005e9913();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x35] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*(int *)(iVar4 + 0xd4) + 0x18))(extraout_ECX[0x38]);
        (**(code **)(*(int *)(extraout_ECX[0x35] + 0xd4) + 0x1c))(2);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x35]);
        (**(code **)(*(int *)(extraout_ECX[0x35] + 0xd4) + 0x14))(0);
        (**(code **)(*(int *)(extraout_ECX[0x35] + 0xd4) + 0x20))(0,0);
      }
      pvVar3 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005e9913();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x36] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*(int *)(iVar4 + 0xd4) + 0x18))(extraout_ECX[0x38]);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x36]);
        (**(code **)(*(int *)(extraout_ECX[0x36] + 0xd4) + 0x1c))(2);
        (**(code **)(*(int *)(extraout_ECX[0x36] + 0xd4) + 0x14))(0);
        (**(code **)(*(int *)(extraout_ECX[0x36] + 0xd4) + 0x20))(0,0);
      }
      pvVar3 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005e9913();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x37] = iVar4;
      if (iVar4 != 0) {
        (**(code **)(*(int *)(iVar4 + 0xd4) + 0x18))(extraout_ECX[0x38]);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x37]);
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x1c))(2);
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x14))(0);
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x20))(0,0);
      }
      uVar2 = 1;
    }
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

