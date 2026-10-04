
void __thiscall FUN_0060a718(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int local_2c;
  int local_28;
  char local_24;
  undefined4 local_c;
  int local_8;
  
  local_8 = param_3;
  iVar3 = 0;
  uVar2 = 0;
  local_c = (**(code **)(*param_1 + 0x58))();
  while ((param_4 != 0 && (FUN_0060980f(&local_2c,local_8,param_4), local_2c != 0))) {
    local_8 = local_8 + local_2c;
    param_4 = param_4 - local_2c;
    cVar1 = (**(code **)(*param_1 + 0x38))((int)local_24);
    uVar2 = (uint)(cVar1 == '\0');
    iVar3 = iVar3 + local_28 + uVar2;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = iVar3 - uVar2;
  param_2[3] = local_c;
  return;
}

