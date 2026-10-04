
void __fastcall FUN_004574bb(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*(int *)*param_1 + 0x38))(0x4f424a44,(int)param_1[0x2d] >> 0x10,FUN_0042004f)
  ;
  if (iVar1 != 0) {
    FUN_00431808(iVar1);
    iVar2 = FUN_00420096(iVar1);
    if (iVar2 == 0xd8) {
      param_1[0x23] = 0;
      uVar3 = FUN_00420048(iVar1);
      FUN_005a92b0(uVar3,param_1[0x18],0xd8);
      FUN_0042004f(iVar1);
      (**(code **)(*(int *)*param_1 + 0x7c))(iVar1);
      FUN_00465a06(iVar1);
      (**(code **)(*(int *)*param_1 + 0x1c))();
      FUN_0040766a(0x82,*(undefined4 *)(param_1[0x18] + 0x1c));
    }
  }
  return;
}

