
undefined4 __thiscall FUN_005bcc37(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(*param_3 + 0x1c))();
  uVar2 = (**(code **)(*param_3 + 0x14))(uVar1);
  FUN_005bd71d(param_2,uVar2,uVar1);
  return param_1;
}

