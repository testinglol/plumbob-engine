
void __thiscall FUN_00417b0b(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  FUN_0046f824(local_44,0,0x40);
  local_50[0] = &PTR_FUN_0066651c;
  (**(code **)(*param_1 + 0x48))(param_2,local_50);
  if (param_1[2] == 0) {
    iVar1 = *param_1;
    uVar2 = (**(code **)(iVar1 + 0x58))(param_2);
    (**(code **)(iVar1 + 0x84))(param_2,param_3,local_50,uVar2);
  }
  return;
}

