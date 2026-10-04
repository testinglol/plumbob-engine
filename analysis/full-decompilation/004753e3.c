
void __thiscall FUN_004753e3(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = param_1;
  FUN_0052ea87(param_1[2],param_1[3]);
  local_8 = (int *)*param_1;
  if (0 < param_2) {
    do {
      FUN_0047554d(&local_8);
      piVar1 = local_8;
      iVar2 = FUN_00475305();
      local_8 = (int *)(iVar2 + (int)piVar1);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

