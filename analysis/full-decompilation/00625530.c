
void FUN_00625530(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00625580(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(*param_1 + 0x14),0x20);
  FUN_00625690(param_1,param_3,uVar1);
  uVar2 = FUN_00625ff0(uVar1);
  FUN_00626060(uVar1);
  FUN_006258b0(param_1,uVar2,param_2,param_3);
  FUN_00626060(uVar2);
  return;
}

