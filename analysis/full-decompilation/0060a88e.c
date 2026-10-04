
int __thiscall FUN_0060a88e(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_8;
  
  uVar3 = param_2;
  local_8 = 0;
  param_2 = 0;
  uVar1 = uVar3 + param_3;
  for (; uVar3 < uVar1; uVar3 = uVar3 + iVar2) {
    iVar2 = (**(code **)(*param_1 + 0x60))(uVar3,param_3 - local_8,param_4);
    local_8 = local_8 + iVar2;
    param_2 = param_2 + 1;
  }
  return param_2;
}

