
int __thiscall FUN_0060a8d2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int local_18;
  int local_14;
  char local_10;
  
  iVar1 = param_3;
  uVar3 = 0;
  param_3 = 0;
  while ((iVar1 != 0 && (FUN_0060980f(&local_18,param_2,iVar1), local_18 != 0))) {
    iVar1 = iVar1 - local_18;
    param_2 = param_2 + local_18;
    cVar2 = (**(code **)(*param_1 + 0x38))((int)local_10);
    uVar3 = (uint)(cVar2 == '\0');
    if ((local_18 == 1) && (local_10 == '_')) {
      uVar3 = 0;
    }
    else {
      param_3 = param_3 + local_14 + uVar3;
    }
  }
  return param_3 - uVar3;
}

