
int __thiscall FUN_0060b73f(int *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  uVar1 = param_2 + param_3;
  if (param_4 == 0) {
    local_c = 1;
  }
  else {
    for (; param_2 < uVar1; param_2 = param_2 + iVar2) {
      iVar2 = (**(code **)(*param_1 + 0x60))(param_2,param_3 - local_8,param_4);
      local_8 = local_8 + iVar2;
      local_c = local_c + 1;
    }
  }
  return local_c;
}

